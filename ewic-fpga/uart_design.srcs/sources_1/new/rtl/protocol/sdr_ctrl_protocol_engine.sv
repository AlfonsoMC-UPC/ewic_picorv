`timescale 1ns / 1ps

// Protocol engine — FPGA side. Pull/credit design (flat port version).
//
//   TX engine  Sends OP_POLL repeatedly at boot until OP_READY arrives.
//              Each OP_READY grants a one-buffer credit. With credit and a
//              pending message it assembles one chunk of up to BUFFER_SIZE
//              bytes, pulls core words via core_wr_ready pulses, hands the
//              chunk to the serialiser, then strobes core_wr_done when the
//              final chunk of the message has been sent.
//
//   RX engine  Fire-and-forget. Latches each OP_DATA packet and walks the
//              payload to the core one word per cycle.

module sdr_ctrl_protocol_engine
  import pkg_sdr_ctrl_protocol::*;
#(
    parameter int unsigned POLL_PERIOD = 50_000
) (
    input logic clk,
    input logic rst_n,
    // Core interface (flat)
    input  logic        core_wr_valid,
    output logic        core_wr_ready,
    input  logic [31:0] core_wr_data,
    input  logic [15:0] core_wr_total_len,
    input  logic [7:0]  core_wr_dst,
    output logic        core_wr_done,
    output logic        core_rd_valid,
    input  logic        core_rd_ready,
    output logic [31:0] core_rd_data,
    output logic [7:0]  core_rd_len,
    output logic        core_rd_last,
    // req: FPGA → SDR (to serialiser)
    output logic      req_valid,
    input  logic      req_ready,
    output protocol_t req_data,
    // rsp: SDR → FPGA (from decoder)
    input  logic      rsp_valid,
    output logic      rsp_ready,
    input  protocol_t rsp_data
);

  localparam int unsigned DATA_WIDTH = 32;
  localparam int unsigned DATA_BYTES = DATA_WIDTH / 8;      // 4
  localparam int unsigned PAY_BITS   = MAX_PAYLOAD_BYTES*8;

  // ---------------------------------------------------------------------------
  // Inbound opcode demux
  // ---------------------------------------------------------------------------
  logic rsp_is_ready, rsp_is_data;
  assign rsp_is_ready = rsp_valid && (rsp_data.opcode == OP_READY);
  assign rsp_is_data  = rsp_valid && (rsp_data.opcode == OP_DATA);

  function automatic protocol_t ctrl_pkt(input opcode_t op);
    ctrl_pkt.opcode  = op;
    ctrl_pkt.len     = 8'h00;
    ctrl_pkt.dst     = 8'h00;
    ctrl_pkt.payload = '0;
  endfunction

  // =====================================================================
  // TX engine
  // =====================================================================
  typedef enum logic [1:0] {
    TX_BOOT,
    TX_WAIT,
    TX_COLLECT,
    TX_SEND
  } tx_state_t;

  tx_state_t           tx_state;
  logic                have_credit;
  logic                in_msg;
  logic [15:0]         bytes_left;
  logic [7:0]          chunk_len;
  logic [7:0]          byte_idx;
  logic [PAY_BITS-1:0] chunk_buf;
  logic [7:0]          cur_dst;
  logic [$clog2(POLL_PERIOD)-1:0] poll_cnt;

  logic req_fire;
  assign req_fire = req_valid && req_ready;

  logic        tx_msg_active;
  logic [15:0] tx_left;
  assign tx_msg_active = in_msg || core_wr_valid;
  assign tx_left       = in_msg ? bytes_left : core_wr_total_len;

  assign core_wr_ready = (tx_state == TX_COLLECT);

  always_comb begin
    req_valid = 1'b0;
    req_data  = ctrl_pkt(OP_POLL);
    case (tx_state)
      TX_BOOT: begin
        req_valid = (poll_cnt == 0);
        req_data  = ctrl_pkt(OP_POLL);
      end
      TX_SEND: begin
        req_valid        = 1'b1;
        req_data.opcode  = OP_DATA;
        req_data.len     = chunk_len;
        req_data.dst     = cur_dst;
        req_data.payload = chunk_buf;
      end
      default: ;
    endcase
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      tx_state     <= TX_BOOT;
      have_credit  <= 1'b0;
      in_msg       <= 1'b0;
      bytes_left   <= '0;
      chunk_len    <= '0;
      byte_idx     <= '0;
      chunk_buf    <= '0;
      cur_dst      <= '0;
      poll_cnt     <= '0;
      core_wr_done <= 1'b0;
    end else begin
      core_wr_done <= 1'b0;

      if (rsp_is_ready) have_credit <= 1'b1;

      // Latch a new message only on a genuinely fresh buffer-fill. Guard with
      // !core_wr_done: when a message completes, core_wr_done strobes for one
      // cycle while the single-slot mmio still shows core_wr_valid=1 with the
      // just-sent (stale) data. Without this guard the engine would phantom-
      // latch in_msg/cur_dst from that stale word, corrupting the next
      // message's destination.
      if (!in_msg && core_wr_valid && !core_wr_done) begin
        in_msg     <= 1'b1;
        bytes_left <= core_wr_total_len;
        cur_dst    <= core_wr_dst;
      end

      case (tx_state)
        TX_BOOT:
          if (have_credit || rsp_is_ready) begin
            tx_state <= TX_WAIT;
          end else if (req_fire) begin
            poll_cnt <= ($clog2(POLL_PERIOD))'(POLL_PERIOD - 1);
          end else if (poll_cnt != 0) begin
            poll_cnt <= poll_cnt - 1;
          end

        TX_WAIT:
          if (have_credit && tx_msg_active && (tx_left != 0)) begin
            chunk_len <= (tx_left > 16'(MAX_PAYLOAD_BYTES))
                           ? 8'(MAX_PAYLOAD_BYTES) : 8'(tx_left);
            byte_idx  <= '0;
            tx_state  <= TX_COLLECT;
          end

        TX_COLLECT:
          if (core_wr_valid) begin
            chunk_buf[byte_idx*8 +: 32] <= core_wr_data;
            byte_idx <= byte_idx + 8'(DATA_BYTES);
            if (byte_idx + 8'(DATA_BYTES) >= chunk_len)
              tx_state <= TX_SEND;
          end

        TX_SEND:
          if (req_fire) begin
            have_credit <= 1'b0;
            bytes_left  <= bytes_left - 16'(chunk_len);
            if (bytes_left == 16'(chunk_len)) begin
              in_msg       <= 1'b0;
              core_wr_done <= 1'b1;
            end
            tx_state <= TX_WAIT;
          end

        default: tx_state <= TX_BOOT;
      endcase
    end
  end

  // =====================================================================
  // RX engine (fire-and-forget)
  // =====================================================================
  typedef enum logic {
    RX_IDLE,
    RX_EMIT
  } rx_state_t;

  rx_state_t           rx_state;
  logic [PAY_BITS-1:0] rx_payload;
  logic [7:0]          rx_len;
  logic [7:0]          rx_idx;

  // Always accept incoming packets so the byte decoder never stalls in
  // S_FINISHED with iter_ready=0. OP_DATA arriving during RX_EMIT is
  // consumed here but silently dropped — the RX_IDLE case guard below
  // ensures it doesn't overwrite an in-progress delivery. Without this,
  // the UART RX FIFO (16 bytes) overflows within two stale RF cycles and
  // the framing decoder becomes permanently misaligned, losing all credits.
  assign rsp_ready = 1'b1;

  logic [7:0] rx_rem;
  assign rx_rem = rx_len - rx_idx;

  always_comb begin
    core_rd_valid = 1'b0;
    core_rd_data  = '0;
    core_rd_len   = '0;
    core_rd_last  = 1'b0;
    if (rx_state == RX_EMIT) begin
      core_rd_valid = 1'b1;
      core_rd_data  = rx_payload[rx_idx*8 +: 32];
      core_rd_len   = (rx_rem >= 8'(DATA_BYTES)) ? 8'(DATA_BYTES) : rx_rem;
      core_rd_last  = (rx_rem <= 8'(DATA_BYTES));
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      rx_state   <= RX_IDLE;
      rx_payload <= '0;
      rx_len     <= '0;
      rx_idx     <= '0;
    end else begin
      case (rx_state)
        RX_IDLE:
          if (rsp_is_data && (rsp_data.len != 0)) begin
            rx_payload <= rsp_data.payload;
            rx_len     <= rsp_data.len;
            rx_idx     <= '0;
            rx_state   <= RX_EMIT;
          end

        RX_EMIT: begin
          // Wait for sdr_mmio to accept the word (core_rd_ready = !rx_valid).
          // Without this, back-to-back words of a multi-word packet would be
          // emitted before the CPU clears the single-slot RX buffer.
          if (core_rd_ready) begin
            rx_idx <= rx_idx + 8'(DATA_BYTES);
            if (rx_rem <= 8'(DATA_BYTES))
              rx_state <= RX_IDLE;
          end
        end

        default: rx_state <= RX_IDLE;
      endcase
    end
  end

endmodule
