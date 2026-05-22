`timescale 1ns / 1ps
`default_nettype none

module top (
    input  wire USER_SI570_CLOCK_P,
    input  wire USER_SI570_CLOCK_N,
    input  wire USB_UART_RX,   // FTDI → FPGA (our RX)
    output wire USB_UART_TX    // FPGA → FTDI (our TX)
);

    wire w_clk;

    clk_wiz_0 pll_inst (
        .clk_in1_p(USER_SI570_CLOCK_P),
        .clk_in1_n(USER_SI570_CLOCK_N),
        .clk_out1 (w_clk)
    );

   // Make sure rst_n is actually low long enough on startup
// 256 cycles at 100MHz is only 2.56 µs - may not be enough
// Increase to at least 1000 cycles to be safe:
    reg [19:0] rst_cnt = 20'hFFFFF;
    always @(posedge w_clk)
        if (rst_cnt != 0) rst_cnt <= rst_cnt - 1;
    wire rst_n  = (rst_cnt == 0);
    wire i_reset = ~rst_n;
    // ------------------------------------------------------------------ wires --
    // uart_tx_stream: serialiser → uart_top TX
    wire       uart_tx_valid;
    wire [7:0] uart_tx_data;
    wire       uart_tx_ready;

    // uart_rx_stream: uart_top RX → decoder
    wire       uart_rx_valid;
    wire [7:0] uart_rx_data;
    wire       uart_rx_ready;

    // protocol_tx: engine → serialiser  (protocol_t = 528 bits)
    wire            proto_tx_valid;
    wire            proto_tx_ready;
    wire [527:0]    proto_tx_data;

    // protocol_rx: decoder → engine
    wire            proto_rx_valid;
    wire            proto_rx_ready;
    wire [527:0]    proto_rx_data;

    // core: test_core ↔ engine
    wire        core_wr_valid;
    wire        core_wr_ready;
    wire [31:0] core_wr_data;
    wire [7:0]  core_wr_len;
    wire        core_rd_valid;
    wire        core_rd_ready;
    wire [31:0] core_rd_data;
    wire [7:0]  core_rd_len;

    // ---------------------------------------------------------- instances --

    uart_top #(
        .G_CLK_FREQ(50_000_000),
        .G_BAUDRATE(115200)
    ) u_uart_top (
        .i_clk          (w_clk),
        .i_reset        (i_reset),
        .i_uart_rx      (USB_UART_RX),
        .o_uart_tx      (USB_UART_TX),
        .from_core_valid(uart_tx_valid),
        .from_core_data (uart_tx_data),
        .from_core_ready(uart_tx_ready),
        .to_core_valid  (uart_rx_valid),
        .to_core_data   (uart_rx_data),
        .to_core_ready  (uart_rx_ready)
    );

    sdr_ctrl_protocol_byte_serialiser u_serialiser (
        .clk       (w_clk),
        .rst_n     (rst_n),
        .core_valid(proto_tx_valid),
        .core_ready(proto_tx_ready),
        .core_data (proto_tx_data),
        .iter_valid(uart_tx_valid),
        .iter_ready(uart_tx_ready),
        .iter_data (uart_tx_data)
    );

    sdr_ctrl_protocol_byte_decoder u_decoder (
        .clk       (w_clk),
        .core_valid(proto_rx_valid),
        .core_ready(proto_rx_ready),
        .core_data (proto_rx_data),
        .iter_valid(uart_rx_valid),
        .iter_ready(uart_rx_ready),
        .iter_data (uart_rx_data)
    );

    sdr_ctrl_protocol_engine u_engine (
        .clk          (w_clk),
        .rst_n        (rst_n),
        .core_wr_valid(core_wr_valid),
        .core_wr_ready(core_wr_ready),
        .core_wr_data (core_wr_data),
        .core_wr_len  (core_wr_len),
        .core_rd_valid(core_rd_valid),
        .core_rd_ready(core_rd_ready),
        .core_rd_data (core_rd_data),
        .core_rd_len  (core_rd_len),
        .req_valid    (proto_tx_valid),
        .req_ready    (proto_tx_ready),
        .req_data     (proto_tx_data),
        .rsp_valid    (proto_rx_valid),
        .rsp_ready    (proto_rx_ready),
        .rsp_data     (proto_rx_data)
    );

    test_core u_test_core (
        .clk          (w_clk),
        .rst_n        (rst_n),
        .core_wr_valid(core_wr_valid),
        .core_wr_ready(core_wr_ready),
        .core_wr_data (core_wr_data),
        .core_wr_len  (core_wr_len),
        .core_rd_valid(core_rd_valid),
        .core_rd_ready(core_rd_ready),
        .core_rd_data (core_rd_data),
        .core_rd_len  (core_rd_len)
    );

endmodule
