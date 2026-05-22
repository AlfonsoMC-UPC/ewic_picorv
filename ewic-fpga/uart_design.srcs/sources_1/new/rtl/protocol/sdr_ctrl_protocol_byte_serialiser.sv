// Serialises a protocol_t packet into an 8-bit byte stream.
//
// Frame format emitted:
//   byte 0       : opcode
//   byte 1       : payload length (0 = no payload)
//   bytes 2..N+1 : payload bytes, LSB-first

module sdr_ctrl_protocol_byte_serialiser
  import pkg_sdr_ctrl_protocol::*;
(
    input logic clk,
    input logic rst_n,
    // Packet input (from engine)
    input  logic      core_valid,
    output logic      core_ready,
    input  protocol_t core_data,
    // Byte stream output (to uart_top from_core)
    output logic       iter_valid,
    input  logic       iter_ready,
    output logic [7:0] iter_data
);

  localparam int unsigned IterElemSize = 8;

  typedef enum logic [1:0] {
    S_IDLE,
    S_OPCODE,
    S_LEN,
    S_PAYLOAD
  } state_t;

  state_t    state,    state_n;
  protocol_t pkt,      pkt_n;
  logic [7:0] byte_idx, byte_idx_n;
  logic [7:0] rem,      rem_n;

  logic iter_fire;
  assign iter_fire = iter_valid && iter_ready;

  always_comb begin
    state_n    = state;
    pkt_n      = pkt;
    byte_idx_n = byte_idx;
    rem_n      = rem;
    core_ready = 0;
    iter_valid = 0;
    iter_data  = '0;

    case (state)

      S_IDLE: begin
        if (core_valid) begin
          core_ready = 1;
          pkt_n      = core_data;
          state_n    = S_OPCODE;
        end
      end

      S_OPCODE: begin
        iter_valid = 1;
        iter_data  = 8'(pkt.opcode);
        if (iter_fire)
          state_n = S_LEN;
      end

      S_LEN: begin
        iter_valid = 1;
        iter_data  = pkt.len;
        if (iter_fire) begin
          byte_idx_n = 0;
          rem_n      = pkt.len;
          state_n    = (pkt.len == 0) ? S_IDLE : S_PAYLOAD;
        end
      end

      S_PAYLOAD: begin
        iter_valid = 1;
        iter_data  = pkt.payload[byte_idx * IterElemSize +: IterElemSize];
        if (iter_fire) begin
          byte_idx_n = byte_idx + 1;
          rem_n      = rem - 1;
          if (rem == 1)
            state_n = S_IDLE;
        end
      end

      default: $fatal(1, "Unreachable sdr_ctrl_protocol_serialiser state");

    endcase
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state    <= S_IDLE;
      pkt      <= '0;
      byte_idx <= '0;
      rem      <= '0;
    end else begin
      state    <= state_n;
      pkt      <= pkt_n;
      byte_idx <= byte_idx_n;
      rem      <= rem_n;
    end
  end

endmodule
