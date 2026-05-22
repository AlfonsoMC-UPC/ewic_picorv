#define _POSIX_C_SOURCE 200809L
#include "sdr_fsm.h"
#include <stdio.h>
#include <string.h>

static const char *state_name(sdr_state_t s) {
    switch (s) {
    case SDR_PENDING: return "PENDING";
    case SDR_ACTIVE:  return "ACTIVE";
    }
    return "?";
}

void sdr_fsm_init(sdr_fsm_t *fsm, const sdr_fsm_ops_t *ops, void *ops_ctx,
                  const char *label) {
    fsm->state          = SDR_PENDING;
    fsm->tx_q_head      = 0;
    fsm->tx_q_tail      = 0;
    fsm->tx_q_len       = 0;
    fsm->tx_bytes_used  = 0;
    fsm->paused         = false;
    fsm->slot_requested = false;
    fsm->ops            = *ops;
    fsm->ops_ctx        = ops_ctx;
    fsm->label          = label;
}

static void log_transition(const sdr_fsm_t *fsm, sdr_state_t prev) {
    if (fsm->state != prev)
        printf("%s %s -> %s\n", fsm->label, state_name(prev),
               state_name(fsm->state));
}

int sdr_fsm_handle_fpga_pkt(sdr_fsm_t *fsm, const packet_t *pkt) {
    sdr_state_t prev = fsm->state;

    switch (fsm->state) {

    case SDR_PENDING:
        if (pkt->opcode == OP_POLL) {
            packet_t rsp = make_ctrl(OP_READY);
            if (fsm->ops.send_to_fpga(fsm->ops_ctx, &rsp) < 0) return -1;
            fsm->state = SDR_ACTIVE;
        } else if (pkt->opcode == OP_DATA) {
            /* FPGA already in S_ACTIVE (SW restarted without reprogramming).
             * Skip the POLL/READY handshake and rejoin at ACTIVE. */
            printf("%s FPGA already ACTIVE on reconnect, skipping handshake\n",
                   fsm->label);
            fsm->state = SDR_ACTIVE;
            log_transition(fsm, prev);
            return sdr_fsm_handle_fpga_pkt(fsm, pkt);  /* reprocess as ACTIVE */
        }
        break;

    case SDR_ACTIVE:
        if (pkt->opcode == OP_POLL) {
            // FPGA rebooted — respond and flush any stale buffer state
            packet_t rsp = make_ctrl(OP_READY);
            if (fsm->ops.send_to_fpga(fsm->ops_ctx, &rsp) < 0) return -1;
            fsm->tx_q_head      = 0;
            fsm->tx_q_tail      = 0;
            fsm->tx_q_len       = 0;
            fsm->tx_bytes_used  = 0;
            fsm->paused         = false;
            fsm->slot_requested = false;

        } else if (pkt->opcode == OP_DATA) {
            if (fsm->tx_q_len >= TX_QUEUE_DEPTH) {
                // Queue full — drop packet (should not happen if PAUSE works)
                printf("%s TX queue overflow, dropping packet\n", fsm->label);
                break;
            }

            bool was_empty = (fsm->tx_q_len == 0);

            fsm->tx_queue[fsm->tx_q_tail] = *pkt;
            fsm->tx_q_tail = (fsm->tx_q_tail + 1) % TX_QUEUE_DEPTH;
            fsm->tx_q_len++;
            fsm->tx_bytes_used += pkt->len;

            printf("%s TX buf: %d bytes (%d pkts)\n",
                   fsm->label, fsm->tx_bytes_used, fsm->tx_q_len);

            // Request a hub slot when the first packet arrives
            if (was_empty && !fsm->slot_requested) {
                packet_t req = make_ctrl(OP_REQ_SLOT);
                if (fsm->ops.send_to_hub(fsm->ops_ctx, &req) < 0) return -1;
                fsm->slot_requested = true;
            }

            // Back-pressure FPGA when buffer is nearly full.
            // Check both byte count (for large packets) and packet count
            // (for small packets that never reach the byte threshold).
            if (!fsm->paused &&
                (fsm->tx_bytes_used >= TX_HIGH_WATER ||
                 fsm->tx_q_len >= TX_QUEUE_DEPTH - 2)) {
                packet_t pause = make_ctrl(OP_PAUSE);
                if (fsm->ops.send_to_fpga(fsm->ops_ctx, &pause) < 0) return -1;
                fsm->paused = true;
            }
        }
        break;
    }

    log_transition(fsm, prev);
    return 0;
}

int sdr_fsm_handle_hub_pkt(sdr_fsm_t *fsm, const packet_t *pkt) {
    if (fsm->state != SDR_ACTIVE)
        return 0;

    switch (pkt->opcode) {

    case OP_GRANT:
        // Drain the entire TX buffer to hub, then release the slot
        fsm->slot_requested = false;
        while (fsm->tx_q_len > 0) {
            const packet_t *p = &fsm->tx_queue[fsm->tx_q_head];
            if (fsm->ops.send_to_hub(fsm->ops_ctx, p) < 0) return -1;
            fsm->tx_q_head = (fsm->tx_q_head + 1) % TX_QUEUE_DEPTH;
            fsm->tx_q_len--;
        }
        fsm->tx_bytes_used = 0;

        {
            packet_t done = make_ctrl(OP_DONE);
            if (fsm->ops.send_to_hub(fsm->ops_ctx, &done) < 0) return -1;
        }

        // Lift FPGA back-pressure if it was paused
        if (fsm->paused) {
            packet_t resume = make_ctrl(OP_RESUME);
            if (fsm->ops.send_to_fpga(fsm->ops_ctx, &resume) < 0) return -1;
            fsm->paused = false;
        }
        break;

    case OP_DATA:
        // Hub broadcast from another SDR — forward straight to FPGA
        if (fsm->ops.send_to_fpga(fsm->ops_ctx, pkt) < 0) return -1;
        break;

    default:
        break;
    }

    return 0;
}
