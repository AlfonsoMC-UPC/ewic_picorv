`default_nettype none

module uart_top #(
    parameter integer G_CLK_FREQ = 100_000_000,
    parameter integer G_BAUDRATE = 115200
)(
    input  wire i_clk,
    input  wire i_reset,
    input  wire i_uart_rx,
    output wire o_uart_tx,
    // from_core: serialiser → TX (uart_top consumes)
    input  wire logic       from_core_valid,
    input  wire logic [7:0] from_core_data,
    output logic            from_core_ready,
    // to_core: RX → decoder (uart_top produces)
    output logic            to_core_valid,
    output logic [7:0]      to_core_data,
    input  wire logic       to_core_ready
);

    reg        r_tx_dv      = 1'b0;
    reg [7:0]  r_tx_data    = 8'h00;
    reg        r_tx_pending = 1'b0;   // latched from byte accept until uart_tx sees it
    wire       w_tx_busy;

    assign from_core_ready = ~(r_tx_pending | w_tx_busy) & ~i_reset;

    always @(posedge i_clk) begin
        r_tx_dv <= 1'b0;
        if (i_reset) begin
            r_tx_pending <= 1'b0;
        end else begin
            // once uart_tx is driving the frame, we no longer need the latch
            if (r_tx_pending && w_tx_busy)
                r_tx_pending <= 1'b0;
            if (from_core_valid && from_core_ready) begin
                r_tx_data    <= from_core_data[7:0];
                r_tx_dv      <= 1'b1;
                r_tx_pending <= 1'b1;
            end
        end
    end

    uart_tx #(
        .G_CLK_FREQ(G_CLK_FREQ),
        .G_BAUDRATE(G_BAUDRATE)
    ) u_tx (
        .i_clk      (i_clk),
        .i_tx_dv    (r_tx_dv),
        .i_tx_data  (r_tx_data),
        .o_tx_serial(o_uart_tx),
        .o_tx_busy  (w_tx_busy)
    );


    // ------------------------------------------------------------------ RX --
    wire [7:0] w_rx_data;
    wire       w_rx_dv;

    uart_rx #(
        .G_CLK_FREQ(G_CLK_FREQ),
        .G_BAUDRATE(G_BAUDRATE)
    ) u_rx (
        .i_clk         (i_clk),
        .i_reset       (i_reset),       // <-- now connected
        .i_uart_rx     (i_uart_rx),
        .o_uart_rx_data(w_rx_data),
        .o_uart_rx_dv  (w_rx_dv)
    );

    reg [7:0] r_rx_buf   = 8'h00;
    reg       r_rx_valid = 1'b0;

    assign to_core_valid = r_rx_valid;
    assign to_core_data  = r_rx_buf;

    always @(posedge i_clk) begin
        if (i_reset) begin
            r_rx_valid <= 1'b0;
            r_rx_buf   <= 8'h00;
        end else begin
            if (r_rx_valid && to_core_ready)
                r_rx_valid <= 1'b0;
            if (w_rx_dv && (!r_rx_valid || to_core_ready)) begin
                r_rx_buf   <= w_rx_data;
                r_rx_valid <= 1'b1;
            end
        end
    end

endmodule