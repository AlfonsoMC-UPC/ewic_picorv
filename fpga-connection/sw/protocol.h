#pragma once
#include <stdint.h>
#include <string.h>

// Must match pkg_sdr_ctrl_protocol.sv (BUFFER_SIZE).
#define BUFFER_SIZE       64
#define MAX_PAYLOAD_BYTES BUFFER_SIZE

typedef enum __attribute__((packed)) {
  OP_POLL     = 0x01,  // FPGA → SDR : sent at boot ("are you ready?")
  OP_READY    = 0x02,  // SDR  → FPGA: one-buffer credit ("ready, send one chunk")

  // Hub-SDR sub-protocol (invisible to FPGA)
  OP_REQ_SLOT = 0x08,  // SDR  → Hub : TX buffer non-empty, request slot
  OP_GRANT    = 0x09,  // Hub  → SDR : slot granted, drain buffer
  OP_DONE     = 0x0A,  // SDR  → Hub : buffer drained, slot released

  OP_DATA     = 0x10,  // bidirectional: sample payload (len > 0)
} opcode_t;

// Wire frame: [ opcode (1B) | len (1B) | dst (1B) | payload (len B) ]
typedef struct {
  opcode_t opcode;
  uint8_t  len;          // payload length in bytes
  uint8_t  dst;          // destination SDR ID (OP_DATA only; 0 for control)
  uint8_t  payload[MAX_PAYLOAD_BYTES];
} packet_t;

static inline packet_t make_ctrl(opcode_t op) {
  packet_t p;
  memset(&p, 0, sizeof(p));
  p.opcode = op;
  p.len    = 0;
  p.dst    = 0;
  return p;
}

static inline const char *opcode_name(opcode_t op) {
  switch (op) {
  case OP_POLL:     return "POLL";
  case OP_READY:    return "READY";
  case OP_REQ_SLOT: return "REQ_SLOT";
  case OP_GRANT:    return "GRANT";
  case OP_DONE:     return "DONE";
  case OP_DATA:     return "DATA";
  }
  return "?";
}
