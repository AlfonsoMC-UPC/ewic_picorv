// hackrf_bridge — protocol adapter between FPGA UART and HackRF USB.
//
// FPGA side (UART, 3-byte frames):
//   [ opcode(1B) | len(1B) | dst(1B) | payload(len B) ]
//   FPGA→bridge : OP_POLL  [01 00 00]          (boot probe)
//   FPGA→bridge : OP_DATA  [10 len dst pay...]  (TX data, after credit)
//   bridge→FPGA : OP_READY [02 00 00]           (one-buffer credit)
//   bridge→FPGA : OP_DATA  [10 len 00 pay...]   (received RF payload)
//
// HackRF side (USB bulk, 2-byte frames):
//   [ opcode(1B) | len(1B) | payload(len B) ]
//   bridge→HackRF : OP_POLL    [01 00]         (boot only)
//   HackRF→bridge : OP_READY   [02 00]         (boot ack)
//   HackRF→bridge : OP_REQ_SLOT[08 00]         (wants TX data)
//   bridge→HackRF : OP_DATA    [10 len pay...] (TX payload, no dst)
//   HackRF→bridge : OP_DATA    [10 len pay...] (received RF payload)
//
// Protocol translation:
//   Boot   : bridge→HackRF [01 00], wait [02 00]; then respond to each
//            FPGA OP_POLL with [02 00 00] (credit #1).
//   TX     : FPGA OP_DATA → 1-slot TX queue (max_payload=64B).
//            HackRF OP_REQ_SLOT → pop queue → send [10 len pay...] to HackRF
//            → send [02 00 00] to FPGA (re-credit).
//            If queue empty at REQ_SLOT time, send empty [10 00] and re-credit.
//   RX     : HackRF OP_DATA → prepend dst=0 → [10 len 00 pay...] to FPGA.
//   Reboot : FPGA OP_POLL while active → re-credit (FPGA rebooted).
//
// Build:  make hackrf_bridge   (see Makefile)
// Usage:  hackrf_bridge <serial_dev> [hackrf_index] [baud]

#define _DEFAULT_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <pthread.h>
#include <time.h>
#include <libusb-1.0/libusb.h>

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------
#define VENDOR_ID   0x1d50
#define PRODUCT_ID  0x6089
#define IFACE       0
#define EP_OUT      0x02
#define EP_IN       0x81
#define USB_TO_MS   1000          // USB bulk timeout (ms)

#define HDR_FPGA    3             // [opcode|len|dst]
#define HDR_HRF     2             // [opcode|len]
#define MAX_PAYLOAD 64
#define MAX_F_FPGA  (HDR_FPGA + MAX_PAYLOAD)
#define MAX_F_HRF   (HDR_HRF  + MAX_PAYLOAD)

#define OP_POLL     0x01
#define OP_READY    0x02
#define OP_REQ_SLOT 0x08
#define OP_DATA     0x10

// ---------------------------------------------------------------------------
// Shared state
// ---------------------------------------------------------------------------
static volatile sig_atomic_t running = 1;
static void on_signal(int s) { (void)s; running = 0; }

// UART write mutex (fpga_thread and hackrf_thread both write to FPGA UART)
static pthread_mutex_t uart_wr_lock = PTHREAD_MUTEX_INITIALIZER;

// 1-slot TX queue: FPGA OP_DATA waiting for HackRF REQ_SLOT
typedef struct {
    uint8_t payload[MAX_PAYLOAD];
    int     len;
    bool    valid;
} txslot_t;

static txslot_t        txq;
static pthread_mutex_t txq_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  txq_cond = PTHREAD_COND_INITIALIZER;

// Credit tracking (fpga_thread writes, hackrf_thread also writes via signal)
static bool credit_issued = false;   // protected by txq_lock

// Last successfully transmitted payload — used as fallback when txq is empty
// at OP_REQ_SLOT time so we never send an empty RF frame (len=0 is silently
// dropped by the FPGA protocol engine, causing net_recv to stall forever).
// Initialised to a one-word zero payload so that even the very first fallback
// (before any FPGA OP_DATA has arrived) sends something non-empty.
static uint8_t saved_payload[MAX_PAYLOAD] = {0};  // protected by txq_lock
static int     saved_plen = 4;                    // bootstrap: one zero word

// ---------------------------------------------------------------------------
// Serial helpers
// ---------------------------------------------------------------------------
static int open_serial(const char *dev, int baud) {
    int fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd < 0) { perror("open serial"); return -1; }
    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) { perror("tcgetattr"); close(fd); return -1; }
    cfmakeraw(&tty);
    speed_t sp;
    switch (baud) {
        case 9600:   sp = B9600;   break;
        case 19200:  sp = B19200;  break;
        case 38400:  sp = B38400;  break;
        case 57600:  sp = B57600;  break;
        case 115200: sp = B115200; break;
        default: fprintf(stderr, "Unsupported baud %d\n", baud); close(fd); return -1;
    }
    cfsetispeed(&tty, sp);
    cfsetospeed(&tty, sp);
    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = 10;   // 1 s timeout so thread can re-check `running`
    if (tcsetattr(fd, TCSANOW, &tty) < 0) { perror("tcsetattr"); close(fd); return -1; }
    tcflush(fd, TCIOFLUSH);
    return fd;
}

static int serial_read_n(int fd, uint8_t *buf, int n) {
    int got = 0;
    while (got < n && running) {
        ssize_t r = read(fd, buf + got, (size_t)(n - got));
        if (r > 0) { got += (int)r; }
        else if (r == 0) { /* VTIME timeout */ }
        else if (errno == EINTR) { continue; }
        else { perror("serial read"); return -1; }
    }
    return (got == n) ? 0 : -1;
}

// Locked UART write — safe to call from any thread.
static int uart_write(int fd, const uint8_t *buf, int n) {
    pthread_mutex_lock(&uart_wr_lock);
    int put = 0;
    while (put < n) {
        ssize_t w = write(fd, buf + put, (size_t)(n - put));
        if (w > 0) { put += (int)w; }
        else if (w < 0 && errno == EINTR) { continue; }
        else { perror("serial write"); pthread_mutex_unlock(&uart_wr_lock); return -1; }
    }
    pthread_mutex_unlock(&uart_wr_lock);
    return 0;
}

static int send_ready_to_fpga(int fd) {
    uint8_t rdy[3] = { OP_READY, 0x00, 0x00 };
    printf("[bridge] → FPGA  OP_READY\n");
    return uart_write(fd, rdy, 3);
}

// ---------------------------------------------------------------------------
// HackRF (libusb)
// ---------------------------------------------------------------------------
static int open_hackrf(libusb_context **ctx_out, libusb_device_handle **dev_out,
                       int idx) {
    libusb_context *ctx = NULL;
    libusb_device **list = NULL;
    libusb_device_handle *dev = NULL;
    if (libusb_init(&ctx) != 0) { fprintf(stderr, "libusb_init failed\n"); return -1; }
    ssize_t cnt = libusb_get_device_list(ctx, &list);
    int found = 0;
    for (ssize_t i = 0; i < cnt; i++) {
        struct libusb_device_descriptor desc;
        if (libusb_get_device_descriptor(list[i], &desc)) continue;
        if (desc.idVendor == VENDOR_ID && desc.idProduct == PRODUCT_ID) {
            if (found == idx) {
                if (libusb_open(list[i], &dev) == 0) break;
            }
            found++;
        }
    }
    libusb_free_device_list(list, 1);
    if (!dev) {
        fprintf(stderr, "HackRF index %d not found (saw %d device(s))\n", idx, found);
        libusb_exit(ctx);
        return -1;
    }
    if (libusb_kernel_driver_active(dev, IFACE) == 1)
        libusb_detach_kernel_driver(dev, IFACE);
    if (libusb_claim_interface(dev, IFACE)) {
        fprintf(stderr, "claim_interface failed\n");
        libusb_close(dev); libusb_exit(ctx); return -1;
    }
    *ctx_out = ctx;
    *dev_out = dev;
    return 0;
}

static int usb_write(libusb_device_handle *usb, const uint8_t *buf, int n) {
    int tx = 0;
    int rc = libusb_bulk_transfer(usb, EP_OUT, (uint8_t *)buf, n, &tx, USB_TO_MS);
    if (rc != 0 || tx != n) {
        fprintf(stderr, "[bridge] USB OUT failed rc=%d (%s) tx=%d/%d\n",
                rc, libusb_error_name(rc), tx, n);
        return -1;
    }
    return 0;
}

static int usb_read(libusb_device_handle *usb, uint8_t *buf, int n, int *got) {
    *got = 0;
    int rc = libusb_bulk_transfer(usb, EP_IN, buf, n, got, USB_TO_MS);
    if (rc == LIBUSB_ERROR_TIMEOUT) return 0;   // no data this window
    if (rc != 0) {
        fprintf(stderr, "[bridge] USB IN failed rc=%d (%s)\n",
                rc, libusb_error_name(rc));
        return -1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Relay context
// ---------------------------------------------------------------------------
typedef struct {
    int                   ser_fd;
    libusb_device_handle *usb;
} relay_t;

// ---------------------------------------------------------------------------
// FPGA thread: UART → TX queue + synthetic OP_READY
// ---------------------------------------------------------------------------
static void *fpga_thread(void *arg) {
    relay_t *r = (relay_t *)arg;
    uint8_t hdr[HDR_FPGA];
    uint8_t payload[MAX_PAYLOAD];

    while (running) {
        if (serial_read_n(r->ser_fd, hdr, HDR_FPGA) != 0) break;

        uint8_t op  = hdr[0];
        uint8_t len = hdr[1];
        // uint8_t dst = hdr[2];  (not used on this path)

        if (len > MAX_PAYLOAD) {
            fprintf(stderr, "[bridge] FPGA bad len=%d, flushing\n", len);
            tcflush(r->ser_fd, TCIFLUSH);
            continue;
        }
        if (len > 0 && serial_read_n(r->ser_fd, payload, len) != 0) break;

        if (op == OP_POLL) {
            // FPGA is at boot or rebooted.  Issue a credit.
            pthread_mutex_lock(&txq_lock);
            bool already = credit_issued;
            if (!already) credit_issued = true;
            pthread_mutex_unlock(&txq_lock);

            if (!already) {
                printf("[bridge] FPGA  OP_POLL → issuing credit\n");
                if (send_ready_to_fpga(r->ser_fd) != 0) break;
            } else {
                printf("[bridge] FPGA  OP_POLL (credit already outstanding, drop)\n");
            }

        } else if (op == OP_DATA) {
            printf("[bridge] FPGA  OP_DATA len=%d\n", len);
            pthread_mutex_lock(&txq_lock);
            // Overwrite stale slot (FPGA produced faster than HackRF consumed).
            if (txq.valid)
                printf("[bridge] TX queue overwrite (HackRF slow)\n");
            memcpy(txq.payload, payload, len);
            txq.len   = len;
            txq.valid = true;
            // Keep a copy as fallback for the next timeout (see OP_REQ_SLOT).
            memcpy(saved_payload, payload, len);
            saved_plen = len;
            credit_issued = false;  // credit consumed
            pthread_cond_signal(&txq_cond);
            pthread_mutex_unlock(&txq_lock);

        } else {
            printf("[bridge] FPGA  drop op=0x%02x len=%d\n", op, len);
        }
    }
    running = 0;
    return NULL;
}

// ---------------------------------------------------------------------------
// HackRF thread: USB IN loop, REQ_SLOT→OP_DATA, OP_DATA→FPGA
// ---------------------------------------------------------------------------
static void *hackrf_thread(void *arg) {
    relay_t *r = (relay_t *)arg;

    // ---- Boot handshake ----
    printf("[bridge] HackRF boot: sending OP_POLL [01 00]\n");
    uint8_t poll[2] = { OP_POLL, 0x00 };
    if (usb_write(r->usb, poll, 2) != 0) { running = 0; return NULL; }

    // Wait for OP_READY [02 00]
    bool booted = false;
    while (running && !booted) {
        uint8_t buf[16];
        int got = 0;
        if (usb_read(r->usb, buf, sizeof(buf), &got) != 0) { running = 0; return NULL; }
        if (got >= 2 && buf[0] == OP_READY) {
            printf("[bridge] HackRF boot: received OP_READY\n");
            booted = true;
        }
    }

    // ---- Main loop ----
    uint8_t frame[MAX_F_HRF + 8];   // a bit of slack for HackRF internals
    while (running) {
        int got = 0;
        if (usb_read(r->usb, frame, sizeof(frame), &got) != 0) break;
        if (got < HDR_HRF) continue;

        uint8_t op  = frame[0];
        uint8_t len = frame[1];

        if (op == OP_REQ_SLOT) {
            // HackRF wants TX data.  Pop from queue (wait up to 50 ms).
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            ts.tv_nsec += 50000000L;   // 50 ms
            if (ts.tv_nsec >= 1000000000L) {
                ts.tv_sec++;
                ts.tv_nsec -= 1000000000L;
            }

            pthread_mutex_lock(&txq_lock);
            while (!txq.valid && running) {
                int rc = pthread_cond_timedwait(&txq_cond, &txq_lock, &ts);
                if (rc == ETIMEDOUT) break;
            }
            uint8_t pay[MAX_PAYLOAD];
            int plen = 0;
            if (txq.valid) {
                plen = txq.len;
                memcpy(pay, txq.payload, plen);
                txq.valid = false;
            } else {
                // Fallback: use the last known payload (or the zero bootstrap)
                // instead of an empty frame.  An empty OP_DATA (len=0) is
                // silently dropped by the FPGA protocol engine (RX guard:
                // len != 0), which causes net_recv(NULL) to stall forever and
                // deadlocks the ring.
                plen = saved_plen;
                memcpy(pay, saved_payload, plen);
                printf("[bridge] HackRF OP_REQ_SLOT: txq empty, resending saved payload len=%d\n", plen);
            }
            pthread_mutex_unlock(&txq_lock);

            // Send OP_DATA to HackRF (2-byte header, no dst).
            uint8_t out[MAX_F_HRF];
            out[0] = OP_DATA;
            out[1] = (uint8_t)plen;
            if (plen > 0) memcpy(out + HDR_HRF, pay, plen);
            printf("[bridge] HackRF OP_REQ_SLOT → OP_DATA len=%d\n", plen);
            if (usb_write(r->usb, out, HDR_HRF + plen) != 0) break;

            // Re-credit FPGA so it can fill the slot for the next RF cycle.
            pthread_mutex_lock(&txq_lock);
            credit_issued = true;
            pthread_mutex_unlock(&txq_lock);
            if (send_ready_to_fpga(r->ser_fd) != 0) break;

        } else if (op == OP_DATA) {
            // RF data received for us — translate 2B→3B header and forward.
            if (len > MAX_PAYLOAD) len = MAX_PAYLOAD;
            uint8_t fwd[MAX_F_FPGA];
            fwd[0] = OP_DATA;
            fwd[1] = len;
            fwd[2] = 0x00;   // dst=0: FPGA0 is always our peer
            if (len > 0) {
                int payload_in_frame = got - HDR_HRF;
                int copy_len = (payload_in_frame < len) ? payload_in_frame : len;
                memcpy(fwd + HDR_FPGA, frame + HDR_HRF, copy_len);
            }
            printf("[bridge] HackRF OP_DATA len=%d → FPGA\n", len);
            if (uart_write(r->ser_fd, fwd, HDR_FPGA + len) != 0) break;

        } else if (op == OP_READY) {
            // Extra OP_READY from HackRF (e.g. second boot pulse) — ignore.
            printf("[bridge] HackRF OP_READY (ignored)\n");

        } else {
            printf("[bridge] HackRF drop op=0x%02x len=%d\n", op, len);
        }
    }
    running = 0;
    return NULL;
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IOLBF, 0);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <serial_dev> [hackrf_index] [baud]\n", argv[0]);
        return 1;
    }
    const char *serial_dev  = argv[1];
    int hackrf_index = (argc >= 3) ? atoi(argv[2]) : 0;
    int baud         = (argc >= 4) ? atoi(argv[3]) : 115200;

    signal(SIGINT,  on_signal);
    signal(SIGTERM, on_signal);

    int ser_fd = open_serial(serial_dev, baud);
    if (ser_fd < 0) return 1;
    printf("[bridge] serial %s @ %d baud\n", serial_dev, baud);

    libusb_context *ctx = NULL;
    libusb_device_handle *usb = NULL;
    if (open_hackrf(&ctx, &usb, hackrf_index) != 0) { close(ser_fd); return 1; }
    printf("[bridge] HackRF #%d opened\n", hackrf_index);

    tcflush(ser_fd, TCIOFLUSH);

    relay_t r = { .ser_fd = ser_fd, .usb = usb };
    pthread_t t_fpga, t_hrf;
    pthread_create(&t_fpga, NULL, fpga_thread, &r);
    pthread_create(&t_hrf,  NULL, hackrf_thread, &r);
    printf("[bridge] running (Ctrl-C to stop)\n");

    pthread_join(t_fpga, NULL);
    pthread_join(t_hrf,  NULL);

    printf("[bridge] shutting down\n");
    libusb_release_interface(usb, IFACE);
    libusb_close(usb);
    libusb_exit(ctx);
    close(ser_fd);
    return 0;
}
