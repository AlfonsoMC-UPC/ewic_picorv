// hackrf_bridge — transparent frame relay between an FPGA's UART and a real
// HackRF One acting as the SDR. Replaces uart_bridge + sdr_sim + sdr_hub on the
// real-hardware path: the HackRF firmware runs the SDR FSM + MAC + RF, so the
// host only needs to shuttle protocol frames between the two links.
//
//      FPGA --UART--> hackrf_bridge --USB bulk OUT(0x02)--> HackRF
//      FPGA <--UART-- hackrf_bridge <--USB bulk IN (0x81)-- HackRF
//
// Frame on the wire (must match the FPGA serialiser / SDR firmware):
//      [ opcode(1B) | len(1B) | dst(1B) | payload(len B) ]      HDR_LEN = 3
// One frame == one USB bulk transfer. NOTE: the current HackRF firmware still
// uses a 2-byte header [opcode|len|payload]; set HDR_LEN=2 to match it until the
// firmware is updated to carry the dst byte.
//
// Build:  needs libusb-1.0  (sudo apt install libusb-1.0-0-dev)
//         gcc -Wall -O2 -o hackrf_bridge hackrf_bridge.c -lusb-1.0 -lpthread
//
// Usage:  hackrf_bridge <serial_dev> [hackrf_index] [baud]
//   e.g.  hackrf_bridge /dev/serial/by-id/usb-Xilinx_...-if02-port0 0 115200

#define _DEFAULT_SOURCE        // expose cfmakeraw() from <termios.h>
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <pthread.h>
#include <libusb-1.0/libusb.h>

#define VENDOR_ID   0x1d50
#define PRODUCT_ID  0x6089
#define IFACE       0
#define EP_BULK_OUT 0x02
#define EP_BULK_IN  0x81
#define USB_TIMEOUT 1000          // ms; bounded so the relay can re-check `running`

#define HDR_LEN     3             // [opcode|len|dst]; set to 2 for legacy firmware
#define MAX_PAYLOAD 64
#define MAX_FRAME   (HDR_LEN + MAX_PAYLOAD)

static volatile sig_atomic_t running = 1;

static void on_signal(int sig) { (void) sig; running = 0; }

// ---------------------------------------------------------------------------
// Serial
// ---------------------------------------------------------------------------
static int open_serial(const char *dev, int baud) {
    int fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd < 0) { perror("open serial"); return -1; }

    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) { perror("tcgetattr"); close(fd); return -1; }
    cfmakeraw(&tty);

    speed_t speed;
    switch (baud) {
        case 9600:   speed = B9600;   break;
        case 19200:  speed = B19200;  break;
        case 38400:  speed = B38400;  break;
        case 57600:  speed = B57600;  break;
        case 115200: speed = B115200; break;
        default: fprintf(stderr, "Unsupported baud %d\n", baud); close(fd); return -1;
    }
    cfsetispeed(&tty, speed);
    cfsetospeed(&tty, speed);

    // Block up to 1s per read so the relay thread can re-check `running`.
    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = 10;          // 1.0 s

    if (tcsetattr(fd, TCSANOW, &tty) < 0) { perror("tcsetattr"); close(fd); return -1; }
    tcflush(fd, TCIOFLUSH);
    return fd;
}

// Read exactly n bytes from the serial port (assembling across reads). Returns
// 0 on success, -1 on error/shutdown.
static int serial_read_n(int fd, uint8_t *buf, int n) {
    int got = 0;
    while (got < n) {
        ssize_t r = read(fd, buf + got, (size_t)(n - got));
        if (r > 0) {
            got += (int) r;
        } else if (r == 0) {
            if (!running) return -1;   // VTIME timeout: just re-check and wait
        } else {
            if (errno == EINTR) { if (!running) return -1; continue; }
            perror("serial read");
            return -1;
        }
    }
    return 0;
}

static int serial_write_all(int fd, const uint8_t *buf, int n) {
    int put = 0;
    while (put < n) {
        ssize_t w = write(fd, buf + put, (size_t)(n - put));
        if (w > 0) { put += (int) w; }
        else if (w < 0 && errno == EINTR) { continue; }
        else { perror("serial write"); return -1; }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// HackRF (libusb)
// ---------------------------------------------------------------------------
static int open_hackrf(libusb_context **ctx_out, libusb_device_handle **dev_out,
                       int wanted_index) {
    libusb_context *ctx = NULL;
    libusb_device **list = NULL;
    libusb_device_handle *dev = NULL;

    if (libusb_init(&ctx) != 0) { fprintf(stderr, "libusb_init failed\n"); return -1; }

    ssize_t count = libusb_get_device_list(ctx, &list);
    int found = 0;
    for (ssize_t i = 0; i < count; i++) {
        struct libusb_device_descriptor desc;
        if (libusb_get_device_descriptor(list[i], &desc) != 0) continue;
        if (desc.idVendor == VENDOR_ID && desc.idProduct == PRODUCT_ID) {
            if (found == wanted_index) {
                if (libusb_open(list[i], &dev) == 0) break;
            }
            found++;
        }
    }
    libusb_free_device_list(list, 1);

    if (!dev) {
        fprintf(stderr, "HackRF index %d not found (saw %d device(s))\n",
                wanted_index, found);
        libusb_exit(ctx);
        return -1;
    }
    if (libusb_kernel_driver_active(dev, IFACE) == 1)
        libusb_detach_kernel_driver(dev, IFACE);
    if (libusb_claim_interface(dev, IFACE) != 0) {
        fprintf(stderr, "claim_interface failed\n");
        libusb_close(dev); libusb_exit(ctx);
        return -1;
    }
    *ctx_out = ctx;
    *dev_out = dev;
    return 0;
}

// ---------------------------------------------------------------------------
// Relay threads
// ---------------------------------------------------------------------------
typedef struct {
    int                   ser_fd;
    libusb_device_handle *usb;
} relay_t;

// FPGA UART -> HackRF USB.  Read one full frame, forward as one bulk transfer.
static void *uart_to_usb(void *arg) {
    relay_t *r = (relay_t *) arg;
    uint8_t frame[MAX_FRAME];

    while (running) {
        if (serial_read_n(r->ser_fd, frame, HDR_LEN) != 0) break;
        int len = frame[1];
        if (len > MAX_PAYLOAD) {
            fprintf(stderr, "[bridge] bad len %d, flushing\n", len);
            tcflush(r->ser_fd, TCIFLUSH);
            continue;
        }
        if (len > 0 && serial_read_n(r->ser_fd, frame + HDR_LEN, len) != 0) break;

        int total = HDR_LEN + len, tx = 0;
        int rc = libusb_bulk_transfer(r->usb, EP_BULK_OUT, frame, total, &tx, USB_TIMEOUT);
        if (rc != 0 || tx != total) {
            fprintf(stderr, "[bridge] USB OUT failed rc=%d (%s) tx=%d/%d\n",
                    rc, libusb_error_name(rc), tx, total);
            break;
        }
        printf("[bridge] UART->USB op=0x%02x len=%d dst=%d\n",
               frame[0], frame[1], HDR_LEN >= 3 ? frame[2] : 0);
    }
    running = 0;
    return NULL;
}

// HackRF USB -> FPGA UART.  Read one bulk frame, forward its bytes to the UART.
static void *usb_to_uart(void *arg) {
    relay_t *r = (relay_t *) arg;
    uint8_t frame[256];

    while (running) {
        int rx = 0;
        int rc = libusb_bulk_transfer(r->usb, EP_BULK_IN, frame, sizeof(frame),
                                      &rx, USB_TIMEOUT);
        if (rc == LIBUSB_ERROR_TIMEOUT) continue;   // no data this window
        if (rc != 0) {
            fprintf(stderr, "[bridge] USB IN failed rc=%d (%s)\n",
                    rc, libusb_error_name(rc));
            break;
        }
        if (rx <= 0) continue;
        if (serial_write_all(r->ser_fd, frame, rx) != 0) break;
        printf("[bridge] USB->UART op=0x%02x len=%d (%d bytes)\n",
               frame[0], rx >= 2 ? frame[1] : 0, rx);
    }
    running = 0;
    return NULL;
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IOLBF, 0);   // line-buffered: logs survive a kill

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <serial_dev> [hackrf_index] [baud]\n", argv[0]);
        return 1;
    }
    const char *serial_dev = argv[1];
    int hackrf_index = (argc >= 3) ? atoi(argv[2]) : 0;
    int baud         = (argc >= 4) ? atoi(argv[3]) : 115200;

    signal(SIGINT,  on_signal);
    signal(SIGTERM, on_signal);

    int ser_fd = open_serial(serial_dev, baud);
    if (ser_fd < 0) return 1;
    printf("[bridge] serial %s @ %d baud opened\n", serial_dev, baud);

    libusb_context *ctx = NULL;
    libusb_device_handle *usb = NULL;
    if (open_hackrf(&ctx, &usb, hackrf_index) != 0) { close(ser_fd); return 1; }
    printf("[bridge] HackRF #%d opened (VID:PID %04x:%04x), HDR_LEN=%d\n",
           hackrf_index, VENDOR_ID, PRODUCT_ID, HDR_LEN);

    tcflush(ser_fd, TCIOFLUSH);   // discard boot garbage before relaying

    relay_t r = { .ser_fd = ser_fd, .usb = usb };
    pthread_t t_out, t_in;
    pthread_create(&t_out, NULL, uart_to_usb, &r);
    pthread_create(&t_in,  NULL, usb_to_uart, &r);
    printf("[bridge] relaying (Ctrl-C to stop)\n");

    pthread_join(t_out, NULL);
    pthread_join(t_in,  NULL);

    printf("[bridge] shutting down\n");
    libusb_release_interface(usb, IFACE);
    libusb_close(usb);
    libusb_exit(ctx);
    close(ser_fd);
    return 0;
}
