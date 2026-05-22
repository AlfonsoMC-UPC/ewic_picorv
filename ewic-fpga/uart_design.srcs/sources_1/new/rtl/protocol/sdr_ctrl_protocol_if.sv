interface sdr_ctrl_protocol_if
  import pkg_sdr_ctrl_protocol::*;
#(
    parameter int unsigned PAYLOAD_WORD_SIZE = 2
) ();

  logic valid;
  logic ready;
  pkg_sdr_ctrl_protocol::protocol_t data;

endinterface
