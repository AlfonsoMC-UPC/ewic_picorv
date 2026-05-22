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

// Opens the serial port at the given baud rate, returns fd
static int open_serial(const char *dev, int baud) {
    int fd = open(dev, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) { perror("open serial"); exit(1); }

    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) { perror("tcgetattr"); exit(1); }

    // Raw mode — no processing, no echo
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

    tty.c_cc[VMIN]  = 0;   // non-blocking reads
    tty.c_cc[VTIME] = 1;   // 100ms timeout

    if (tcsetattr(fd, TCSANOW, &tty) < 0) { perror("tcsetattr"); exit(1); }
    tcflush(fd, TCIOFLUSH);
    return fd;
}

// Echo test: send pattern, verify the FPGA sends it back verbatim.
// Walking bits catch bit-position errors; 0xAA/0x55 catch framing; 0x00/0xFF
// catch stuck lines; the remaining bytes catch byte-ordering problems.
static int run_echo_test(int ser_fd) {
    static const uint8_t TX[] = {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
        0xAA, 0x55, 0xFF, 0x00, 0x12, 0x34, 0x56, 0x78,
    };
    const size_t N = sizeof(TX);
    uint8_t rx[sizeof(TX)];

    tcflush(ser_fd, TCIOFLUSH);

    // Send
    ssize_t w = write(ser_fd, TX, N);
    if (w != (ssize_t)N) { perror("write"); return 1; }
    printf("[test] sent    %zu bytes:", N);
    for (size_t i = 0; i < N; i++) printf(" %02x", TX[i]);
    printf("\n");

    // Read back with 2-second deadline
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
        printf("[test] FAIL\n");
        if (got != N)
            printf("[test]   size:  expected %zu, got %zu\n", N, got);
        printf("[test]   sent:");
        for (size_t i = 0; i < N;   i++) printf(" %02x", TX[i]);
        printf("\n[test]   recv:");
        for (size_t i = 0; i < got; i++) printf(" %02x", rx[i]);
        printf("\n[test]   diff:");
        for (size_t i = 0; i < N; i++) {
            if (i >= got)          printf(" ??");
            else if (TX[i] != rx[i]) printf(" ^^");
            else                   printf(" --");
        }
        printf("\n");
        return 1;
    }
    printf("[test] PASS\n");
    return 0;
}

int main(int argc, char **argv) {
    // Echo-test mode: uart_bridge --test <serial_dev> [baud] [count]
    if (argc >= 3 && strcmp(argv[1], "--test") == 0) {
        const char *dev   = argv[2];
        int         baud  = (argc >= 4) ? atoi(argv[3]) : 115200;
        int         count = (argc >= 5) ? atoi(argv[4]) : 1;
        int ser_fd = open_serial(dev, baud);
        printf("[test] serial %s @ %d baud, %d run(s)\n", dev, baud, count);
        int passed = 0;
        for (int i = 0; i < count; i++) {
            printf("[test] --- run %d/%d ---\n", i + 1, count);
            if (run_echo_test(ser_fd) == 0)
                passed++;
        }
        printf("[test] result: %d/%d passed\n", passed, count);
        close(ser_fd);
        return (passed == count) ? 0 : 1;
    }

    // Bridge mode: uart_bridge <tcp_port> <serial_dev> [baud]
    if (argc < 3) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s <tcp_port> <serial_dev> [baud]          — TCP↔serial bridge\n", argv[0]);
        fprintf(stderr, "  %s --test    <serial_dev> [baud] [count]   — UART echo test\n", argv[0]);
        return 1;
    }

    int         tcp_port   = atoi(argv[1]);
    const char *serial_dev = argv[2];
    int         baud       = (argc >= 4) ? atoi(argv[3]) : 115200;

    // --- Open serial port ---
    int ser_fd = open_serial(serial_dev, baud);
    printf("[bridge] serial %s @ %d baud opened\n", serial_dev, baud);

    // --- TCP server: wait for sdr_sim to connect ---
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = {
        .sin_family      = AF_INET,
        .sin_port        = htons((uint16_t)tcp_port),
        .sin_addr.s_addr = INADDR_ANY,
    };
    if (bind(srv, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind"); exit(1);
    }
    listen(srv, 1);
    printf("[bridge] waiting for sdr_sim on TCP port %d...\n", tcp_port);

    socklen_t alen = sizeof(addr);
    int cli = accept(srv, (struct sockaddr *)&addr, &alen);
    if (cli < 0) { perror("accept"); exit(1); }
    printf("[bridge] sdr_sim connected\n");
    close(srv);  // only one client
    tcflush(ser_fd, TCIOFLUSH);  // discard startup garbage before relaying

    // --- Relay loop ---
    uint8_t buf[256];
    for (;;) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(cli, &rfds);
        FD_SET(ser_fd, &rfds);
        int maxfd = (cli > ser_fd ? cli : ser_fd) + 1;

        struct timeval tv = {1, 0};
        int n = select(maxfd, &rfds, NULL, NULL, &tv);
        if (n < 0) { perror("select"); break; }

        // TCP → serial
        if (FD_ISSET(cli, &rfds)) {
            ssize_t r = read(cli, buf, sizeof(buf));
            if (r <= 0) { printf("[bridge] TCP client disconnected\n"); break; }
            printf("[bridge] TCP→serial %zd bytes:", r);
            for (ssize_t i = 0; i < r; i++) printf(" %02x", buf[i]);
            printf("\n");
            write(ser_fd, buf, (size_t)r);
        }

        // serial → TCP
        if (FD_ISSET(ser_fd, &rfds)) {
            ssize_t r = read(ser_fd, buf, sizeof(buf));
            if (r > 0) {
                printf("[bridge] serial→TCP %zd bytes:", r);
                for (ssize_t i = 0; i < r; i++) printf(" %02x", buf[i]);
                printf("\n");
                ssize_t ww = write(cli, buf, (size_t)r);
                if (ww < r) { perror("tcp write"); break; }
            }
        }
    }

    close(cli);
    close(ser_fd);
    return 0;
}
