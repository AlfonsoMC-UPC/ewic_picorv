// GTY link: wraps aurora_64b66b_0_support + gty_mmio.
//
// Provides a CPU-bus-facing memory-mapped interface and the physical
// QSFP1 lane 1 differential pins for Aurora 64B/66B at 10.3125 Gbps.
//
// The AXI4-Lite port of aurora_64b66b_0_support is tied off (not used).

`timescale 1 ns / 10 ps
`default_nettype none

module gty_link (
    // Free-running 100 MHz clock for Aurora initialisation (from SYS_CLK0 IBUFDS)
    input  wire        init_clk,
    // Active-high power-on reset (w_sys_rst from top)
    input  wire        sys_rst,

    // GTY reference clock (156.25 MHz, MGT_SI570_CLOCK1)
    input  wire        gt_refclk1_p,
    input  wire        gt_refclk1_n,

    // QSFP1 lane 1 serial I/O
    input  wire        rxp,
    input  wire        rxn,
    output wire        txp,
    output wire        txn,

    // CPU clock domain (50 MHz) — Core 0 bus
    input  wire         clk,
    input  wire         rst_n,
    input  wire         en,
    input  wire  [2:0]  addr_w,       // mem_addr[4:2]
    input  wire  [3:0]  wstrb,
    input  wire  [31:0] wdata,
    output wire  [31:0] rdata
);

    // Aurora internal signals
    wire        aurora_clk;        // ~161 MHz user clock out of Aurora
    wire        sync_clk_unused;
    wire        channel_up;
    wire        lane_up;
    wire        hard_err_unused;
    wire        soft_err_unused;
    wire        gt_pll_lock;        // QPLL locked
    wire        sys_reset_out;      // Aurora system reset (active high)
    wire        link_reset_out;     // Aurora link reset (active high)
    wire        bufg_gt_clr_unused;
    wire        tx_out_clk_unused;
    wire        mmcm_not_locked;    // user-clock MMCM NOT locked

    // AXI-Stream between gty_mmio and Aurora (aurora_clk domain, [63:0] wires)
    wire [63:0] tx_tdata;
    wire        tx_tvalid;
    wire        tx_tready;
    wire [63:0] rx_tdata;
    wire        rx_tvalid;

    // -------------------------------------------------------------------------
    // GTY MMIO — CDC bridge between cpu_clk and aurora_clk
    // -------------------------------------------------------------------------
    gty_mmio u_gty_mmio (
        .clk              (clk),
        .rst_n            (rst_n),
        .en               (en),
        .addr_w           (addr_w),
        .wstrb            (wstrb),
        .wdata            (wdata),
        .rdata            (rdata),
        .aurora_clk       (aurora_clk),
        .channel_up       (channel_up),
        .lane_up          (lane_up),
        .gt_pll_lock      (gt_pll_lock),
        .mmcm_not_locked  (mmcm_not_locked),
        .sys_reset_out    (sys_reset_out),
        .link_reset_out   (link_reset_out),
        .aurora_tx_tdata  (tx_tdata),
        .aurora_tx_tvalid (tx_tvalid),
        .aurora_tx_tready (tx_tready),
        .aurora_rx_tdata  (rx_tdata),
        .aurora_rx_tvalid (rx_tvalid)
    );

    // -------------------------------------------------------------------------
    // Aurora 64B/66B support: QPLL, clocking, reset, Aurora core
    // The [0:63] AXI-Stream ports connect to [63:0] wires — both FPGAs use
    // the same convention so the bit ordering cancels on the link.
    // -------------------------------------------------------------------------
    aurora_64b66b_0_support u_aurora (
        // AXI-Stream TX
        .s_axi_tx_tdata  (tx_tdata),
        .s_axi_tx_tvalid (tx_tvalid),
        .s_axi_tx_tready (tx_tready),
        // AXI-Stream RX
        .m_axi_rx_tdata  (rx_tdata),
        .m_axi_rx_tvalid (rx_tvalid),
        // Serial I/O
        .rxp(rxp), .rxn(rxn),
        .txp(txp), .txn(txn),
        // GT reference clock (IBUFDS_GTE4 is inside support)
        .gt_refclk1_p(gt_refclk1_p),
        .gt_refclk1_n(gt_refclk1_n),
        // Status
        .hard_err       (hard_err_unused),
        .soft_err       (soft_err_unused),
        .channel_up     (channel_up),
        .lane_up        (lane_up),
        // Clock outputs
        .user_clk_out   (aurora_clk),
        .sync_clk_out   (sync_clk_unused),
        // Control
        .reset_pb       (sys_rst),    // active-high power-on reset
        .gt_rxcdrovrden_in(1'b0),
        .power_down     (1'b0),
        .loopback       (3'b000),     // normal operation (cable link)
        .pma_init       (1'b0),
        // Init clock
        .init_clk       (init_clk),
        // AXI4-Lite (tied off — not used)
        .s_axi_awaddr   (32'b0), .s_axi_awvalid(1'b0),
        .s_axi_wdata    (32'b0), .s_axi_wstrb  (4'b0), .s_axi_wvalid(1'b0),
        .s_axi_bready   (1'b1),
        .s_axi_araddr   (32'b0), .s_axi_arvalid(1'b0),
        .s_axi_rready   (1'b1),
        // Misc outputs
        .link_reset_out    (link_reset_out),
        .gt_pll_lock       (gt_pll_lock),
        .sys_reset_out     (sys_reset_out),
        .bufg_gt_clr_out   (bufg_gt_clr_unused),
        .mmcm_not_locked_out(mmcm_not_locked),
        .tx_out_clk        (tx_out_clk_unused)
    );

endmodule
`default_nettype wire
