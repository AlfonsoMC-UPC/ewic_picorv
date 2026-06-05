#include <stdint.h>
#include <stddef.h>

/* ── GTY MMIO (inter-FPGA via Aurora/QSFP1, Core 0 only) ────────────────── */
#define GTY_BASE     0x30000000U
#define GTY_TX_HDR   (*(volatile uint32_t *)(GTY_BASE + 0x00))
#define GTY_TX_DAT   (*(volatile uint32_t *)(GTY_BASE + 0x04))
#define GTY_TX_READY (*(volatile uint32_t *)(GTY_BASE + 0x08))
#define GTY_STATUS   (*(volatile uint32_t *)(GTY_BASE + 0x0C))
#define GTY_RX_HDR   (*(volatile uint32_t *)(GTY_BASE + 0x10))
#define GTY_RX_DAT   (*(volatile uint32_t *)(GTY_BASE + 0x14))
#define GTY_RX_VALID (*(volatile uint32_t *)(GTY_BASE + 0x18))

/* ── SDR MMIO (inter-FPGA, Core 0 only) ─────────────────────────────────── */
#define SDR_BASE     0x10000000U
#define SDR_TX_DATA  (*(volatile uint32_t *)(SDR_BASE + 0x00))
#define SDR_TX_READY (*(volatile uint32_t *)(SDR_BASE + 0x04))
#define SDR_RX_DATA  (*(volatile uint32_t *)(SDR_BASE + 0x08))
#define SDR_RX_VALID (*(volatile uint32_t *)(SDR_BASE + 0x0C))

/* ── Local MMIO — registers visible to all cores ────────────────────────── */
#define LOCAL_BASE    0x20000000U
#define MBOX_TX_DATA  (*(volatile uint32_t *)(LOCAL_BASE + 0x00))
#define MBOX_TX_READY (*(volatile uint32_t *)(LOCAL_BASE + 0x04))
#define MBOX_RX_DATA  (*(volatile uint32_t *)(LOCAL_BASE + 0x08))
#define MBOX_RX_VALID (*(volatile uint32_t *)(LOCAL_BASE + 0x0C))
#define CORE_ID       (*(volatile uint32_t *)(LOCAL_BASE + 0x10))
#define FPGA_ID_REG   (*(volatile uint32_t *)(LOCAL_BASE + 0x14))

/* ── Local MMIO — Core 0 extended registers (one bank per peer core) ─────── */
#define C1_TX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x20))
#define C1_TX_READY   (*(volatile uint32_t *)(LOCAL_BASE + 0x24))
#define C1_RX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x28))
#define C1_RX_VALID   (*(volatile uint32_t *)(LOCAL_BASE + 0x2C))
#define C2_TX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x30))
#define C2_TX_READY   (*(volatile uint32_t *)(LOCAL_BASE + 0x34))
#define C2_RX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x38))
#define C2_RX_VALID   (*(volatile uint32_t *)(LOCAL_BASE + 0x3C))
#define C3_TX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x40))
#define C3_TX_READY   (*(volatile uint32_t *)(LOCAL_BASE + 0x44))
#define C3_RX_DATA    (*(volatile uint32_t *)(LOCAL_BASE + 0x48))
#define C3_RX_VALID   (*(volatile uint32_t *)(LOCAL_BASE + 0x4C))

/* ── Addressing ──────────────────────────────────────────────────────────────
 *
 * addr_t = [15:8] fpga_id | [7:0] core_id
 *
 * Every message = 2 consecutive 32-bit word transfers:
 *   word 0  header : bits[31:16]=dst_addr  bits[15:0]=src_addr
 *   word 1  data   : application payload
 *
 * Routing topology:
 *   Core 0 is the router for its FPGA.  It is the only core that accesses
 *   the SDR link.  Cores 1-3 always send via their mailbox to Core 0, which
 *   then either delivers locally (another local core) or forwards over SDR.
 *
 * Reserved FPGA_ID 0xFF: log messages from FPGA 0 Core 0.
 *   type 0x01-0x03 = partial sum from Core 1/2/3
 *   type 0x10      = local total
 *   type 0x11      = remote total
 *   type 0x12      = global sum
 *   All FPGAs silently drop 0xFF-addressed messages in c0_route.
 */
typedef uint16_t addr_t;
#define ADDR(fpga, core)  ((addr_t)(((uint16_t)(fpga) << 8) | (uint8_t)(core)))
#define ADDR_FPGA(a)      (((a) >> 8) & 0xFF)
#define ADDR_CORE(a)      ((a) & 0xFF)

#define MSG_HDR(dst, src) (((uint32_t)(dst) << 16) | (uint32_t)(src))
#define MSG_DST(hdr)      ((addr_t)((hdr) >> 16))
#define MSG_SRC(hdr)      ((addr_t)((hdr) & 0xFFFF))

#define LOG_FPGA       0xFFU
#define LOG_LOCAL      0x10U
#define LOG_REMOTE     0x11U
#define LOG_GLOBAL     0x12U
#define LOG_GTY_STATUS 0x20U  /* GTY_STATUS register value at startup */

/* ── Startup globals ─────────────────────────────────────────────────────── */
static uint8_t my_fpga_id;
static uint8_t my_core_id;
static addr_t  my_addr;

/* ── Low-level transport ─────────────────────────────────────────────────── */
static void     sdr_send_word(uint32_t v)  { while (!SDR_TX_READY); SDR_TX_DATA = v; }
static void     mbox_send_word(uint32_t v) { while (!MBOX_TX_READY); MBOX_TX_DATA = v; }
static uint32_t mbox_recv_word(void)        { while (!MBOX_RX_VALID); return MBOX_RX_DATA; }

static void gty_send_msg(uint32_t hdr, uint32_t dat) {
    while (!GTY_TX_READY);
    GTY_TX_HDR = hdr;
    GTY_TX_DAT = dat;
}

static void delay(int n) { for (volatile int i = 0; i < n; i++); }

/* ── Core 0 only: send a 2-word message to a local peer core ────────────── */
static void c0_mbox_send(uint8_t core, uint32_t hdr, uint32_t dat)
{
    switch (core) {
    case 1:
        while (!C1_TX_READY) {} C1_TX_DATA = hdr;
        while (!C1_TX_READY) {} C1_TX_DATA = dat;
        break;
    case 2:
        while (!C2_TX_READY) {} C2_TX_DATA = hdr;
        while (!C2_TX_READY) {} C2_TX_DATA = dat;
        break;
    case 3:
        while (!C3_TX_READY) {} C3_TX_DATA = hdr;
        while (!C3_TX_READY) {} C3_TX_DATA = dat;
        break;
    default: break;
    }
}

/* ── Core 0 only: route a message not addressed to self ─────────────────── */
static void c0_route(uint32_t hdr, uint32_t dat)
{
    addr_t dst = MSG_DST(hdr);
    if (ADDR_FPGA(dst) == LOG_FPGA) return;   /* silently drop log/reserved messages */
    if (ADDR_FPGA(dst) == my_fpga_id)
        c0_mbox_send(ADDR_CORE(dst), hdr, dat);
    else
        gty_send_msg(hdr, dat);
}

/* ── Core 0 only: log a value over SDR (FPGA 0 master only) ─────────────── */
static void log_word(uint8_t type, uint32_t value)
{
    sdr_send_word(MSG_HDR(ADDR(LOG_FPGA, type), my_addr));
    sdr_send_word(value);
}

/* ── net_send ────────────────────────────────────────────────────────────────
 *
 * Core 0: routes directly (SDR if remote, peer mailbox if local).
 * Cores 1-3: push into mailbox toward Core 0, which routes on their behalf.
 */
static void net_send(addr_t dst, uint32_t data)
{
    uint32_t hdr = MSG_HDR(dst, my_addr);
    if (my_core_id == 0) {
        if (ADDR_FPGA(dst) == my_fpga_id)
            c0_mbox_send(ADDR_CORE(dst), hdr, data);
        else
            gty_send_msg(hdr, data);
    } else {
        mbox_send_word(hdr);
        mbox_send_word(data);
    }
}

/* ── net_recv ────────────────────────────────────────────────────────────────
 *
 * Core 0: polls all three peer mailbox RX channels and the GTY wire.  Routes any
 *         message not addressed to itself and keeps looping until one arrives
 *         for Core 0.
 * Cores 1-3: block on their single mailbox channel from Core 0.
 *
 * src_out may be NULL.
 */
static uint32_t net_recv(addr_t *src_out)
{
    if (my_core_id != 0) {
        uint32_t hdr = mbox_recv_word();
        uint32_t dat = mbox_recv_word();
        if (src_out) *src_out = MSG_SRC(hdr);
        return dat;
    }

    /* Core 0 routing loop */
    while (1) {
        uint32_t hdr, dat;

        if (C1_RX_VALID) {
            hdr = C1_RX_DATA; while (!C1_RX_VALID); dat = C1_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
        if (C2_RX_VALID) {
            hdr = C2_RX_DATA; while (!C2_RX_VALID); dat = C2_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
        if (C3_RX_VALID) {
            hdr = C3_RX_DATA; while (!C3_RX_VALID); dat = C3_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
        if (GTY_RX_VALID) {
            hdr = GTY_RX_HDR; dat = GTY_RX_DAT;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
    }
}

/* ── local_recv (Core 0 only) ───────────────────────────────────────────────
 *
 * Like net_recv but polls ONLY C1/C2/C3 mailboxes — never SDR.
 * Used during the local partial-sum collection phase to prevent a race where
 * an early SDR message from the remote FPGA is mistaken for a local partial.
 */
static uint32_t local_recv(addr_t *src_out)
{
    while (1) {
        uint32_t hdr, dat;

        if (C1_RX_VALID) {
            hdr = C1_RX_DATA; while (!C1_RX_VALID); dat = C1_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
        if (C2_RX_VALID) {
            hdr = C2_RX_DATA; while (!C2_RX_VALID); dat = C2_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
        if (C3_RX_VALID) {
            hdr = C3_RX_DATA; while (!C3_RX_VALID); dat = C3_RX_DATA;
            if (MSG_DST(hdr) == my_addr) { if (src_out) *src_out = MSG_SRC(hdr); return dat; }
            c0_route(hdr, dat);
        }
    }
}

/* ── Distributed parallel reduction demo ────────────────────────────────────
 *
 * Dataset is split across the 3 compute cores of each FPGA:
 *   Core 1: data[0..4]   = 1+2+3+4+5         =  15
 *   Core 2: data[5..9]   = 6+7+8+9+10        =  40
 *   Core 3: data[10..15] = 11+12+13+14+15+16 =  81
 *   Local total           = 136  (0x88)
 *   Global total (2 FPGAs)= 272  (0x110)
 *
 * Core 0 orchestrates: collects the 3 local partials via local_recv (mailbox
 * only, preventing SDR race), exchanges the local total with the remote
 * FPGA's Core 0 over SDR, and distributes the global result back to all 3
 * compute cores.  FPGA 0's Core 0 also emits log messages over SDR so the
 * hub can reconstruct the execution trace.
 */
#define N 16
static const uint32_t dataset[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

void main(void)
{
    my_fpga_id = (uint8_t)FPGA_ID_REG;
    my_core_id = (uint8_t)CORE_ID;
    my_addr    = ADDR(my_fpga_id, my_core_id);

    addr_t local_core0  = ADDR(my_fpga_id, 0);
    addr_t local_core1  = ADDR(my_fpga_id, 1);
    addr_t local_core2  = ADDR(my_fpga_id, 2);
    addr_t local_core3  = ADDR(my_fpga_id, 3);
    addr_t remote_core0 = ADDR(my_fpga_id, 0);       /* loopback: send to self */

    if (my_core_id == 0) {
        /*
         * Core 0 — router and reduce coordinator.
         *
         * Phase 1: Collect partial sums from Cores 1, 2, 3 via local_recv
         *          (mailbox-only — avoids SDR race condition).
         * Phase 2: Log per-core partials and local total (FPGA 0 master only).
         * Phase 3: Exchange local total with remote FPGA over SDR.
         * Phase 4: Log remote total and global sum (FPGA 0 master only).
         * Phase 5: Broadcast global result back to Cores 1, 2, 3.
         */
        int first_iter = 1;
        while (1) {
            /* Phase 1 */
            addr_t src1, src2, src3;
            uint32_t p1 = local_recv(&src1);
            uint32_t p2 = local_recv(&src2);
            uint32_t p3 = local_recv(&src3);
            uint32_t local_total = p1 + p2 + p3;

            /* Phase 2 */
            if (my_fpga_id == 0) {
                log_word(ADDR_CORE(src1), p1);
                log_word(ADDR_CORE(src2), p2);
                log_word(ADDR_CORE(src3), p3);
                log_word(LOG_LOCAL, local_total);
            }

            /* Phase 3 */
            while (!GTY_STATUS);               /* wait for Aurora lane_up / channel_up */
            if (my_fpga_id == 0 && first_iter) {
                log_word(LOG_GTY_STATUS, GTY_STATUS);
                first_iter = 0;
            }
            net_send(remote_core0, local_total);
            uint32_t remote_total = net_recv(NULL);
            uint32_t global_sum   = local_total + remote_total;

            /* Phase 4 */
            if (my_fpga_id == 0) {
                log_word(LOG_REMOTE, remote_total);
                log_word(LOG_GLOBAL, global_sum);
            }

            /* Phase 5 */
            net_send(local_core1, global_sum);
            net_send(local_core2, global_sum);
            net_send(local_core3, global_sum);
        }

    } else {
        /*
         * Cores 1, 2, 3 — compute cores.
         *
         * Each core sums its own slice of the dataset (private BRAM, no SDR
         * traffic), hands the partial sum to Core 0, waits for the global
         * result, then throttles before the next round.
         */
        int start, end;
        switch (my_core_id) {
        case 1: start =  0; end =  5; break;
        case 2: start =  5; end = 10; break;
        default: start = 10; end = 16; break;  /* Core 3 */
        }

        while (1) {
            uint32_t partial = 0;
            for (int i = start; i < end; i++)
                partial += dataset[i];

            net_send(local_core0, partial);

            uint32_t global_sum = net_recv(NULL);
            (void)global_sum;

            delay(10000);
        }
    }
}
