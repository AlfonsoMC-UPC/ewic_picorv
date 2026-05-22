// Deserialises an 8-bit byte stream into protocol_t packets.
//
// Frame format (on wire, in order):
//   byte 0       : opcode
//   byte 1       : payload length (0 = no payload)
//   bytes 2..N+1 : payload (N = len), LSB-first

module sdr_ctrl_protocol_byte_decoder
  import pkg_sdr_ctrl_protocol::*;
(
    input logic clk,
    // Parsed packet output (to engine)
    output logic      core_valid,
    input  logic      core_ready,
    output protocol_t core_data,
    // Incoming byte stream (from uart_top to_core)
    input  logic       iter_valid,
    output logic       iter_ready,
    input  logic [7:0] iter_data
);

  typedef enum logic [1:0] {
    S_OPCODE,
    S_LEN,
    S_PAYLOAD,
    S_FINISHED
  } state_t;

  state_t      state,     state_n;
  protocol_t   prot_buf,  prot_buf_n;
  logic [7:0]  rem,       rem_n;
  logic [7:0]  byte_idx,  byte_idx_n;

  always_comb begin
    state_n    = state;
    prot_buf_n = prot_buf;
    rem_n      = rem;
    byte_idx_n = byte_idx;
    iter_ready = 0;
    core_valid = 0;
    core_data  = prot_buf;

    case (state)
      S_OPCODE: begin
        if (iter_valid) begin
          iter_ready          = 1;
          prot_buf_n.opcode   = opcode_t'(iter_data);
          prot_buf_n.len      = '0;
          prot_buf_n.payload  = '0;
          byte_idx_n          = 0;
          state_n             = S_LEN;
        end
      end

      S_LEN: begin
        if (iter_valid) begin
          iter_ready      = 1;
          prot_buf_n.len  = iter_data;
          rem_n           = iter_data;
          state_n         = (iter_data == 0) ? S_FINISHED : S_PAYLOAD;
        end
      end

      S_PAYLOAD: begin
        if (iter_valid) begin
          iter_ready = 1;
          prot_buf_n.payload[byte_idx * 8 +: 8] = iter_data;
          byte_idx_n = byte_idx + 1;
          rem_n      = rem - 1;
          if (rem == 1)
            state_n = S_FINISHED;
        end
      end

      S_FINISHED: begin
        core_valid = 1;
        if (core_ready)
          state_n = S_OPCODE;
      end

      default: $fatal(1, "Unreachable sdr_ctrl_protocol_decoder state");
    endcase
  end

  always_ff @(posedge clk) begin
    state    <= state_n;
    prot_buf <= prot_buf_n;
    rem      <= rem_n;
    byte_idx <= byte_idx_n;
  end

endmodule
