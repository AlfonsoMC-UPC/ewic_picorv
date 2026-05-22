`timescale 1ns / 1ps

// Protocol engine — FPGA side.
//
//   S_UNINIT  Sends OP_POLL every POLL_PERIOD cycles until OP_READY arrives.
//   S_ACTIVE  Fully operational. Both directions run concurrently:
//               TX: core_wr_valid && !paused → send OP_DATA to SDR.
//               RX: OP_DATA from SDR → forward to core.
//               Backpressure: OP_PAUSE sets paused; OP_RESUME clears it.

module sdr_ctrl_protocol_engine
  import pkg_sdr_ctrl_protocol::*;
#(
    parameter int unsigned POLL_PERIOD = 1000
) (
    input logic clk,
    input logic rst_n,
    // core_sdr interface (flat ports, matches test_core and top.sv)
    input  logic        core_wr_valid,
    output logic        core_wr_ready,
    input  logic [31:0] core_wr_data,
    input  logic [7:0]  core_wr_len,
    output logic        core_rd_valid,
    input  logic        core_rd_ready,
    output logic [31:0] core_rd_data,
    output logic [7:0]  core_rd_len,
    // req: FPGA → SDR
    output logic      req_valid,
    input  logic      req_ready,
    output protocol_t req_data,
    // rsp: SDR → FPGA
    input  logic      rsp_valid,
    output logic      rsp_ready,
    input  protocol_t rsp_data
);

  if (MAX_PAYLOAD_BYTES > 255) begin : gen_payload_size_check
    $error("MAX_PAYLOAD_BYTES=%0d exceeds 8-bit len field", MAX_PAYLOAD_BYTES);
  end

  typedef enum logic {
    S_UNINIT,
    S_ACTIVE
  } state_t;

  state_t state, state_n;
  logic   paused_r, paused_n;

  logic [$clog2(POLL_PERIOD)-1:0] poll_cnt, poll_cnt_n;

  logic    rsp_fire, req_fire, core_wr_fire;
  opcode_t rsp_op;
  assign rsp_fire     = rsp_valid  && rsp_ready;
  assign rsp_op       = rsp_data.opcode;
  assign req_fire     = req_valid  && req_ready;
  assign core_wr_fire = core_wr_valid && core_wr_ready;

  function automatic protocol_t ctrl_pkt(input opcode_t op);
    ctrl_pkt.opcode  = op;
    ctrl_pkt.len     = 8'h00;
    ctrl_pkt.payload = '0;
  endfunction

  always_comb begin
    state_n       = state;
    paused_n      = paused_r;
    poll_cnt_n    = poll_cnt;
    req_valid     = 0;
    req_data      = ctrl_pkt(OP_POLL);
    rsp_ready     = 0;
    core_wr_ready = 0;
    core_rd_valid = 0;
    core_rd_data  = '0;
    core_rd_len   = '0;

    case (state)

      // -----------------------------------------------------------------------
      S_UNINIT: begin
        rsp_ready = 1;
        if (rsp_fire && rsp_op == OP_READY) begin
          state_n = S_ACTIVE;
        end else if (poll_cnt == 0) begin
          req_valid  = 1;
          req_data   = ctrl_pkt(OP_POLL);
          poll_cnt_n = ($clog2(POLL_PERIOD))'(POLL_PERIOD - 1);
        end else begin
          poll_cnt_n = poll_cnt - 1;
        end
      end

      // -----------------------------------------------------------------------
      S_ACTIVE: begin
        rsp_ready = 1;

        // RX path: forward DATA from SDR to core
        if (rsp_fire && rsp_op == OP_DATA) begin
          core_rd_valid = 1;
          core_rd_data  = rsp_data.payload[$bits(core_rd_data)-1:0];
          core_rd_len   = rsp_data.len;
        end

        // Backpressure from SDR TX buffer
        if (rsp_fire && rsp_op == OP_PAUSE)  paused_n = 1;
        if (rsp_fire && rsp_op == OP_RESUME) paused_n = 0;

        // TX path: push core data to SDR when not paused
        if (core_wr_valid && !paused_r) begin
          assert (core_wr_len <= 8'(MAX_PAYLOAD_BYTES))
            else $fatal(1, "core_wr_len=%0d exceeds MAX_PAYLOAD_BYTES=%0d",
                        core_wr_len, MAX_PAYLOAD_BYTES);
          req_valid        = 1;
          req_data.opcode  = OP_DATA;
          req_data.len     = core_wr_len;
          req_data.payload = {{($bits(req_data.payload)-$bits(core_wr_data)){1'b0}},
                               core_wr_data};
          if (req_fire) core_wr_ready = 1;
        end
      end

      default: $fatal(1, "Unreachable sdr_ctrl_protocol_engine state");

    endcase
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state    <= S_UNINIT;
      poll_cnt <= '0;
      paused_r <= '0;
    end else begin
      state    <= state_n;
      poll_cnt <= poll_cnt_n;
      paused_r <= paused_n;
    end
  end

endmodule
