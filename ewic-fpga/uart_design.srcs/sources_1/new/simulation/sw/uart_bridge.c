#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#define MAX_PAYLOAD 64

// ── serial port ──────────────────────────────────────────────────────────────

static int open_serial(const char *dev, int baud) {
    int fd = open(dev, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) { perror("open serial"); exit(1); }

    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) { perror("tcgetattr"); exit(1); }

    cfmakeraw(&tty);

    speed_t speed;
    switch (baud) {
        case 9600:   speed = B9600;   break;
        case 19200:  speed = B19200;  break;
        case 38400:  speed = B38400;  break;
        case 57600:  speed = B57600;  break;
        case 115200: speed = B115200; break;
        default:
            fprintf(stderr, "Unsupported baud rate %d\n", baud);
            exit(1);
    }
    cfsetispeed(&tty, speed);
    cfsetospeed(&tty, speed);

    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = 1;

    if (tcsetattr(fd, TCSANOW, &tty) < 0) { perror("tcsetattr"); exit(1); }
    tcflush(fd, TCIOFLUSH);
    return fd;
}

// ── echo test (unchanged) ────────────────────────────────────────────────────

static int run_echo_test(int ser_fd) {
    static const uint8_t TX[] = {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
        0xAA, 0x55, 0xFF, 0x00, 0x12, 0x34, 0x56, 0x78,
    };
    const size_t N = sizeof(TX);
    uint8_t rx[sizeof(TX)];

    tcflush(ser_fd, TCIOFLUSH);

    ssize_t w = write(ser_fd, TX, N);
    if (w != (ssize_t)N) { perror("write"); return 1; }
    printf("[test] sent    %zu bytes:", N);
    for (size_t i = 0; i < N; i++) printf(" %02x", TX[i]);
    printf("\n");

    size_t got = 0;
    struct timespec deadline;
    clock_gettime(CLOCK_MONOTONIC, &deadline);
    deadline.tv_sec += 2;

    while (got < N) {
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        long ms_left = (deadline.tv_sec  - now.tv_sec)  * 1000
                     + (deadline.tv_nsec - now.tv_nsec) / 1000000;
        if (ms_left <= 0) break;

        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(ser_fd, &rfds);
        struct timeval tv = { ms_left / 1000, (ms_left % 1000) * 1000 };
        if (select(ser_fd + 1, &rfds, NULL, NULL, &tv) <= 0) break;

        ssize_t r = read(ser_fd, rx + got, N - got);
        if (r > 0) got += (size_t)r;
    }

    printf("[test] received %zu bytes:", got);
    for (size_t i = 0; i < got; i++) printf(" %02x", rx[i]);
    printf("\n");

    int pass = (got == N) && (memcmp(TX, rx, N) == 0);
    if (!pass) {
        printf("[test] FAIL — expected:");
        for (size_t i = 0; i < N; i++) printf(" %02x", TX[i]);
        printf("\n[test]         got:     ");
        for (size_t i = 0; i < got; i++) printf(" %02x", rx[i]);
        printf("\n");
        return 1;
    }
    printf("[test] PASS\n");
    return 0;
}

// ── packet parser ─────────────────────────────────────────────────────────────
// Parses the wire format: [opcode(1) | len(1) | dst(1) | payload(len)]
// Call pkt_feed() one byte at a time; returns 1 when a complete packet is ready.

typedef struct {
    int     state;   // 0=opcode 1=len 2=dst 3=payload
    uint8_t opcode, len, dst;
    uint8_t payload[MAX_PAYLOAD];
    int     idx;
} pkt_t;

static int pkt_feed(pkt_t *p, uint8_t b) {
    switch (p->state) {
    case 0:
        if (b == 0x00) return 0;  // 0x00 is never a valid opcode; skip to re-sync
        p->opcode = b; p->state = 1; break;
    case 1: p->len    = b; p->idx   = 0; p->state = 2; break;
    case 2: p->dst    = b; p->state = (p->len == 0) ? 0 : 3;
            if (p->len == 0) return 1;
            break;
    case 3:
        if (p->idx < MAX_PAYLOAD) p->payload[p->idx] = b;
        p->idx++;
        if (p->idx >= (int)p->len) { p->state = 0; return 1; }
        break;
    }
    return 0;
}

static void write_pkt(int fd, const pkt_t *p, uint8_t opcode) {
    uint8_t hdr[3] = { opcode, p->len, p->dst };
    if (write(fd, hdr, 3) < 0) return;
    if (p->len > 0) { if (write(fd, p->payload, p->len) < 0) return; }
}

// ── TCP helpers ───────────────────────────────────────────────────────────────

static int tcp_listen(int port) {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    struct sockaddr_in addr = {
        .sin_family      = AF_INET,
        .sin_port        = htons((uint16_t)port),
        .sin_addr.s_addr = INADDR_ANY,
    };
    if (bind(srv, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind"); exit(1);
    }
    listen(srv, 1);
    return srv;
}

// ── bridge mode ───────────────────────────────────────────────────────────────
//
// Dual-channel mode:   uart_bridge <sdr_port> <wire_port> <serial_dev> [baud]
// Single-channel mode: uart_bridge <sdr_port> <serial_dev> [baud]
//
// Detection: if argv[2] starts with '/' it is the serial device (single-channel).
//
// Dual-channel opcode routing:
//   serial → sdr_tcp : packets whose opcode has bit 6 = 0 (normal SDR opcodes)
//   serial → wire_tcp: packets whose opcode has bit 6 = 1 (wire opcodes 0x41/0x42/0x50)
//                      bit 6 is stripped before forwarding to wire_tcp
//   sdr_tcp → serial : raw byte relay (opcodes already correct)
//   wire_tcp → serial: packets are parsed; bit 6 is set in the opcode before forwarding

static void run_bridge(int ser_fd, int sdr_fd, int wire_fd) {
    pkt_t ser_parser  = {0};  // for serial → sdr/wire demux
    pkt_t wire_parser = {0};  // for wire_tcp → serial (opcode translation)

    printf("[bridge] relay started%s\n", wire_fd >= 0 ? " (dual-channel)" : "");

    for (;;) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(ser_fd, &rfds);
        FD_SET(sdr_fd, &rfds);
        if (wire_fd >= 0) FD_SET(wire_fd, &rfds);
        int maxfd = ser_fd;
        if (sdr_fd  > maxfd) maxfd = sdr_fd;
        if (wire_fd > maxfd) maxfd = wire_fd;

        struct timeval tv = {1, 0};
        int n = select(maxfd + 1, &rfds, NULL, NULL, &tv);
        if (n < 0) { perror("select"); break; }

        // serial → sdr_tcp / wire_tcp
        if (FD_ISSET(ser_fd, &rfds)) {
            uint8_t buf[256];
            ssize_t r = read(ser_fd, buf, sizeof(buf));
            for (ssize_t i = 0; i < r; i++) {
                if (pkt_feed(&ser_parser, buf[i])) {
                    if (ser_parser.opcode & 0x40) {
                        // wire packet
                        if (wire_fd >= 0)
                            write_pkt(wire_fd, &ser_parser,
                                      ser_parser.opcode & (uint8_t)~0x40u);
                        // else: no wire channel — drop silently
                    } else {
                        // SDR packet: forward to sdr_tcp unchanged
                        write_pkt(sdr_fd, &ser_parser, ser_parser.opcode);
                    }
                }
            }
        }

        // sdr_tcp → serial (raw relay: SDR opcodes are already correct)
        if (FD_ISSET(sdr_fd, &rfds)) {
            uint8_t buf[256];
            ssize_t r = read(sdr_fd, buf, sizeof(buf));
            if (r <= 0) { printf("[bridge] SDR TCP client disconnected\n"); break; }
            printf("[bridge] sdr→serial %zd bytes:", r);
            for (ssize_t i = 0; i < r; i++) printf(" %02x", buf[i]);
            printf("\n");
            if (write(ser_fd, buf, (size_t)r) < 0) break;
        }

        // wire_tcp → serial (parse packets, set bit 6 in opcode)
        if (wire_fd >= 0 && FD_ISSET(wire_fd, &rfds)) {
            uint8_t buf[256];
            ssize_t r = read(wire_fd, buf, sizeof(buf));
            if (r <= 0) { printf("[bridge] wire TCP client disconnected\n"); break; }
            for (ssize_t i = 0; i < r; i++) {
                if (pkt_feed(&wire_parser, buf[i])) {
                    write_pkt(ser_fd, &wire_parser,
                              wire_parser.opcode | 0x40u);
                }
            }
        }
    }
}

// ── main ─────────────────────────────────────────────────────────────────────

int main(int argc, char **argv) {
    // Echo-test mode
    if (argc >= 3 && strcmp(argv[1], "--test") == 0) {
        const char *dev   = argv[2];
        int         baud  = (argc >= 4) ? atoi(argv[3]) : 115200;
        int         count = (argc >= 5) ? atoi(argv[4]) : 1;
        int ser_fd = open_serial(dev, baud);
        printf("[test] serial %s @ %d baud, %d run(s)\n", dev, baud, count);
        int passed = 0;
        for (int i = 0; i < count; i++) {
            printf("[test] --- run %d/%d ---\n", i + 1, count);
            if (run_echo_test(ser_fd) == 0) passed++;
        }
        printf("[test] result: %d/%d passed\n", passed, count);
        close(ser_fd);
        return (passed == count) ? 0 : 1;
    }

    // Bridge mode: detect single vs dual channel by inspecting argv[2]
    if (argc < 3) {
        fprintf(stderr,
            "Usage:\n"
            "  %s <sdr_port> <serial_dev> [baud]             — single channel\n"
            "  %s <sdr_port> <wire_port> <serial_dev> [baud] — dual channel\n"
            "  %s --test <serial_dev> [baud] [count]         — echo test\n",
            argv[0], argv[0], argv[0]);
        return 1;
    }

    int         sdr_port   = atoi(argv[1]);
    int         wire_port  = 0;
    const char *serial_dev = NULL;
    int         baud       = 115200;

    // argv[2] starts with '/' → serial device (single-channel)
    if (argv[2][0] == '/') {
        serial_dev = argv[2];
        if (argc >= 4) baud = atoi(argv[3]);
    } else {
        // dual-channel: argv[2] is wire_port, argv[3] is serial_dev
        if (argc < 4) {
            fprintf(stderr, "uart_bridge: expected <serial_dev> after wire port\n");
            return 1;
        }
        wire_port  = atoi(argv[2]);
        serial_dev = argv[3];
        if (argc >= 5) baud = atoi(argv[4]);
    }

    int ser_fd = open_serial(serial_dev, baud);
    printf("[bridge] serial %s @ %d baud opened\n", serial_dev, baud);

    // Set up TCP server(s) before accepting so both listen sockets are ready
    // before any sim process tries to connect.
    int sdr_srv  = tcp_listen(sdr_port);
    int wire_srv = (wire_port > 0) ? tcp_listen(wire_port) : -1;

    printf("[bridge] waiting for sdr_sim on port %d%s\n",
           sdr_port, wire_srv >= 0 ? " and wire_sim on next port" : "");

    // Accept both clients (in any order) using select().
    int sdr_fd  = -1;
    int wire_fd = -1;

    while (sdr_fd < 0 || (wire_srv >= 0 && wire_fd < 0)) {
        fd_set rfds;
        FD_ZERO(&rfds);
        if (sdr_fd  < 0) FD_SET(sdr_srv,  &rfds);
        if (wire_srv >= 0 && wire_fd < 0) FD_SET(wire_srv, &rfds);
        int maxfd = (sdr_srv > wire_srv ? sdr_srv : wire_srv);
        select(maxfd + 1, &rfds, NULL, NULL, NULL);

        if (sdr_fd < 0 && FD_ISSET(sdr_srv, &rfds)) {
            sdr_fd = accept(sdr_srv, NULL, NULL);
            printf("[bridge] sdr_sim connected\n");
        }
        if (wire_srv >= 0 && wire_fd < 0 && FD_ISSET(wire_srv, &rfds)) {
            wire_fd = accept(wire_srv, NULL, NULL);
            printf("[bridge] wire_sim connected\n");
        }
    }

    close(sdr_srv);
    if (wire_srv >= 0) close(wire_srv);

    tcflush(ser_fd, TCIOFLUSH);
    run_bridge(ser_fd, sdr_fd, wire_fd);

    close(sdr_fd);
    if (wire_fd >= 0) close(wire_fd);
    close(ser_fd);
    return 0;
}
