// Memory-mapped GTY/Aurora interface for PicoRV32 Core 0.
//
// Address map (word offsets, mem_addr[4:2]):
//   0  GTY_TX_HDR   (WO) — header word; latch before triggering TX
//   1  GTY_TX_DAT   (WO) — data word; writing triggers one 64-bit Aurora beat
//   2  GTY_TX_READY (RO) — 1 when TX is idle and can accept next message
//   3  GTY_STATUS   (RO) — {30'b0, lane_up, channel_up}
//   4  GTY_RX_HDR   (RO) — received header word
//   5  GTY_RX_DAT   (RO) — received data word; reading also clears RX_VALID
//   6  GTY_RX_VALID (RO) — 1 when an unread message is waiting
//   7  (reserved)
//
// Protocol:
//   TX: write header to offset 0, data to offset 1 (triggers send).
//       Wait until GTY_TX_READY == 1 before next message.
//   RX: poll GTY_RX_VALID; when 1, read offset 4 (header) then offset 5 (data).
//       Reading offset 5 clears the valid flag.
//
// Clock domains:
//   clk        — CPU clock (50 MHz)
//   aurora_clk — Aurora user_clk (~161 MHz)
//
// CDC: two-FF synchronisers on all handshake signals. Data registers are held
// stable across the clock-domain boundary by the handshake protocol (acceptable
// for polling firmware; use an async FIFO for a hardened design).

`timescale 1ns / 1ps
`default_nettype none

module gty_mmio (
    // CPU clock domain (50 MHz)
    input  wire         clk,
    input  wire         rst_n,
    input  wire         en,
    input  wire  [2:0]  addr_w,      // word offset: mem_addr[4:2]
    input  wire  [3:0]  wstrb,
    input  wire  [31:0] wdata,
    output reg   [31:0] rdata,

    // Aurora clock domain (~161 MHz)
    input  wire         aurora_clk,

    // Status (slow-changing; safe to 2-FF sync)
    input  wire         channel_up,
    input  wire         lane_up,
    input  wire         gt_pll_lock,      // QPLL locked
    input  wire         mmcm_not_locked,  // user-clock MMCM NOT locked
    input  wire         sys_reset_out,    // Aurora system reset (active high)
    input  wire         link_reset_out,   // Aurora link reset (active high)

    // Aurora AXI-Stream TX (aurora_clk domain)
    output wire  [63:0] aurora_tx_tdata,
    output wire         aurora_tx_tvalid,
    input  wire         aurora_tx_tready,

    // Aurora AXI-Stream RX (aurora_clk domain)
    input  wire  [63:0] aurora_rx_tdata,
    input  wire         aurora_rx_tvalid
);

    // =========================================================================
    // TX: clk → aurora_clk via req/ack level handshake
    // =========================================================================

    reg [31:0] tx_hdr_c, tx_dat_c;
    reg        tx_req_c;   // level: set when message pending, cleared on ack

    // 2-FF sync of tx_req_c into aurora_clk domain
    (* ASYNC_REG = "TRUE" *) reg tx_req_a0, tx_req_a;
    reg tx_req_a_prev;
    always @(posedge aurora_clk) begin
        tx_req_a0     <= tx_req_c;
        tx_req_a      <= tx_req_a0;
        tx_req_a_prev <= tx_req_a;
    end
    wire tx_req_rise = tx_req_a & ~tx_req_a_prev;

    // Drive AXI-Stream: hold tvalid until tready accepted
    reg tx_inflight_a;
    reg tx_ack_a;          // one-cycle pulse back to clk domain

    always @(posedge aurora_clk) begin
        tx_ack_a <= 1'b0;
        if (tx_req_rise && !tx_inflight_a)
            tx_inflight_a <= 1'b1;
        if (tx_inflight_a && aurora_tx_tready) begin
            tx_inflight_a <= 1'b0;
            tx_ack_a      <= 1'b1;
        end
    end

    // tx_tdata[63:32]=header, tx_tdata[31:0]=data
    assign aurora_tx_tdata  = tx_inflight_a ? {tx_hdr_c, tx_dat_c} : 64'b0;
    assign aurora_tx_tvalid = tx_inflight_a;

    // 2-FF sync of tx_ack_a back into clk domain
    (* ASYNC_REG = "TRUE" *) reg tx_ack_c0, tx_ack_c;
    always @(posedge clk) begin
        tx_ack_c0 <= tx_ack_a;
        tx_ack_c  <= tx_ack_c0;
    end

    // =========================================================================
    // RX: aurora_clk → clk via req/ack level handshake
    // =========================================================================

    // Capture incoming beat; hold until CPU acknowledges.
    // rx_latch_a ensures rx_data_a is stable for >= 1 aurora_clk before valid.
    reg [63:0] rx_data_a;
    reg        rx_latch_a;
    reg        rx_valid_a;

    // 2-FF sync of rx_ack_c into aurora_clk (clears rx_valid_a)
    reg        rx_ack_c;
    (* ASYNC_REG = "TRUE" *) reg rx_ack_a0, rx_ack_a;
    always @(posedge aurora_clk) begin
        rx_ack_a0 <= rx_ack_c;
        rx_ack_a  <= rx_ack_a0;
    end

    always @(posedge aurora_clk) begin
        rx_latch_a <= 1'b0;
        if (aurora_rx_tvalid && !rx_valid_a && !rx_latch_a) begin
            rx_data_a  <= aurora_rx_tdata;
            rx_latch_a <= 1'b1;
        end
        if (rx_latch_a) rx_valid_a <= 1'b1;
        if (rx_ack_a)   rx_valid_a <= 1'b0;
    end

    // 2-FF sync of rx_valid_a into clk
    (* ASYNC_REG = "TRUE" *) reg rx_valid_c0, rx_valid_c;
    reg rx_valid_c_prev;
    always @(posedge clk) begin
        rx_valid_c0     <= rx_valid_a;
        rx_valid_c      <= rx_valid_c0;
        rx_valid_c_prev <= rx_valid_c;
    end

    // CPU-side RX registers: latched when rx_valid_c rises.
    // At that point rx_data_a has been stable for >= 1 aurora_clk + 2 cpu_clk
    // cycles (~52 ns), so sampling from cpu_clk is safe.
    reg [31:0] rx_hdr_c, rx_dat_c;
    reg        rx_holding;   // CPU-side: unread message available

    // =========================================================================
    // Status sync
    // =========================================================================
    (* ASYNC_REG = "TRUE" *) reg ch_up_s0, ch_up_s, ln_up_s0, ln_up_s;
    (* ASYNC_REG = "TRUE" *) reg pll_s0, pll_s, mmcm_nl_s0, mmcm_nl_s;
    (* ASYNC_REG = "TRUE" *) reg sysrst_s0, sysrst_s, lnkrst_s0, lnkrst_s;
    always @(posedge clk) begin
        ch_up_s0   <= channel_up;       ch_up_s   <= ch_up_s0;
        ln_up_s0   <= lane_up;          ln_up_s   <= ln_up_s0;
        pll_s0     <= gt_pll_lock;      pll_s     <= pll_s0;
        mmcm_nl_s0 <= mmcm_not_locked;  mmcm_nl_s <= mmcm_nl_s0;
        sysrst_s0  <= sys_reset_out;    sysrst_s  <= sysrst_s0;
        lnkrst_s0  <= link_reset_out;   lnkrst_s  <= lnkrst_s0;
    end

    // =========================================================================
    // CPU register file (clk domain)
    // =========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tx_hdr_c   <= 32'b0;
            tx_dat_c   <= 32'b0;
            tx_req_c   <= 1'b0;
            rx_hdr_c   <= 32'b0;
            rx_dat_c   <= 32'b0;
            rx_holding <= 1'b0;
            rx_ack_c   <= 1'b0;
            rdata      <= 32'b0;
        end else begin
            rx_ack_c <= 1'b0;   // default: no ack pulse this cycle

            // TX: deassert req when Aurora has accepted the beat
            if (tx_ack_c) tx_req_c <= 1'b0;

            // RX: capture data into clk domain when valid sync fires
            if (rx_valid_c && !rx_valid_c_prev) begin
                rx_hdr_c   <= rx_data_a[63:32];
                rx_dat_c   <= rx_data_a[31: 0];
                rx_holding <= 1'b1;
            end

            rdata <= 32'b0;
            if (en) begin
                case (addr_w)
                    3'd0: if (wstrb != 4'b0 && !tx_req_c)         // GTY_TX_HDR
                              tx_hdr_c <= wdata;
                    3'd1: if (wstrb != 4'b0 && !tx_req_c) begin   // GTY_TX_DAT -> trigger TX
                              tx_dat_c <= wdata;
                              tx_req_c <= 1'b1;
                          end
                    3'd2: rdata <= {31'b0, !tx_req_c};             // GTY_TX_READY
                    // GTY_STATUS: diagnostic bits
                    //   [0] channel_up     [1] lane_up        [2] gt_pll_lock
                    //   [3] user_clk_active [4] sys_reset_out [5] link_reset_out
                    // Note: mmcm_nl_s = gtwiz_userclk_tx_active_out — HIGH when user_clk IS active
                    3'd3: rdata <= {26'b0, lnkrst_s, sysrst_s,
                                    mmcm_nl_s, pll_s, ln_up_s, ch_up_s};
                    3'd4: rdata <= rx_hdr_c;                       // GTY_RX_HDR
                    3'd5: begin                                     // GTY_RX_DAT (read clears valid)
                              rdata      <= rx_dat_c;
                              rx_holding <= 1'b0;
                              rx_ack_c   <= 1'b1;
                          end
                    3'd6: rdata <= {31'b0, rx_holding};            // GTY_RX_VALID
                    default:;
                endcase
            end
        end
    end

endmodule
`default_nettype wire
