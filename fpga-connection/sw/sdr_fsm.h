#pragma once
#include <stdbool.h>
#include "protocol.h"

#define TX_QUEUE_DEPTH  16    // max packets in TX queue
#define TX_HIGH_WATER   384   // bytes: send PAUSE above this
#define TX_LOW_WATER    128   // bytes: send RESUME below this

typedef enum {
    SDR_PENDING,  // awaiting POLL/READY boot handshake
    SDR_ACTIVE,   // fully operational; TX buffer drains independently
} sdr_state_t;

typedef struct {
    int (*send_to_fpga)(void *ctx, const packet_t *pkt);
    int (*send_to_hub)(void *ctx, const packet_t *pkt);
} sdr_fsm_ops_t;

typedef struct {
    sdr_state_t   state;
    // TX packet queue: FPGA→SDR DATA held until hub grants a slot
    packet_t      tx_queue[TX_QUEUE_DEPTH];
    int           tx_q_head, tx_q_tail, tx_q_len;
    int           tx_bytes_used;   // total payload bytes currently queued
    bool          paused;          // FPGA is flow-controlled (PAUSE sent)
    bool          slot_requested;  // REQ_SLOT sent, waiting for GRANT
    sdr_fsm_ops_t ops;
    void         *ops_ctx;
    const char   *label;
} sdr_fsm_t;

void sdr_fsm_init(sdr_fsm_t *fsm, const sdr_fsm_ops_t *ops, void *ops_ctx,
                  const char *label);

int sdr_fsm_handle_fpga_pkt(sdr_fsm_t *fsm, const packet_t *pkt);
int sdr_fsm_handle_hub_pkt(sdr_fsm_t *fsm, const packet_t *pkt);
