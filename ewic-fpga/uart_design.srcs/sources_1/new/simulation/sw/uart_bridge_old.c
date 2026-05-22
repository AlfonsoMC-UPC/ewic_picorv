#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
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

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <tcp_port> <serial_dev> [baud]\n", argv[0]);
        fprintf(stderr, "  e.g: %s 12345 /dev/ttyUSB2 115200\n", argv[0]);
        return 1;
    }

    int         tcp_port  = atoi(argv[1]);
    const char *serial_dev = argv[2];
    int         baud      = (argc >= 4) ? atoi(argv[3]) : 115200;

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
                // also print TCP→serial side the same way
                ssize_t w = write(cli, buf, (size_t)r);
                if (w < r) { perror("tcp write"); break; }
            }
        }
    }

    close(cli);
    close(ser_fd);
    return 0;
}