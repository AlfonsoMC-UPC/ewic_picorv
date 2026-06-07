`timescale 1ns / 1ps
`default_nettype none

module top #(
    parameter [7:0] FPGA_ID = 8'd1  // set per-board in Vivado synthesis settings
) (
    input wire USER_SI570_CLOCK_P,
    input wire USER_SI570_CLOCK_N,
    input wire USB_UART_TX,  // TX from FTDI => RX for FPGA
    output wire USB_UART_RX, // RX to FTDI  => TX from FPGA

    // Free-running 100 MHz system clock (for Aurora init)
    input wire SYS_CLK0_P,
    input wire SYS_CLK0_N,

    // GTY reference clock for QSFP1 (156.25 MHz QSFP1_CLOCK = MGTREFCLK1_135)
    input wire QSFP1_CLOCK_P,
    input wire QSFP1_CLOCK_N,

    // QSFP1 oscillator control (Bank 75, LVCMOS18)
    output wire QSFP1_OEB,  // drive 0 to enable clock output
    output wire QSFP1_FS,   // drive 1 for 156.25 MHz (0 = 161.132 MHz)

    // QSFP1 lane 1 GTY serial I/O
    input  wire QSFP1_RX1_P,
    input  wire QSFP1_RX1_N,
    output wire QSFP1_TX1_P,
    output wire QSFP1_TX1_N
);

  wire w_clk_50MHz;

  // -----------------------------------------------------------------------
  // SYS_CLK0: 100 MHz free-running clock for Aurora init_clk
  // -----------------------------------------------------------------------
  wire w_init_clk_ibuf;
  wire w_init_clk;
  IBUFDS #(.DIFF_TERM("FALSE"), .IBUF_LOW_PWR("FALSE")) ibufds_sysclk0 (
      .I(SYS_CLK0_P), .IB(SYS_CLK0_N), .O(w_init_clk_ibuf)
  );
  BUFG bufg_init_clk (.I(w_init_clk_ibuf), .O(w_init_clk));

  // QSFP1 oscillator control: enable output (OEB=0), select 156.25 MHz (FS=1)
  assign QSFP1_OEB = 1'b0;
  assign QSFP1_FS  = 1'b1;

  // GTY bus signals (Core 0 → gty_link)
  wire        w_gty_en;
  wire [2:0]  w_gty_addr_w;
  wire [3:0]  w_gty_wstrb;
  wire [31:0] w_gty_wdata;
  wire [31:0] w_gty_rdata;

  // UART signals
  wire [7:0] w_uart_rx_data;
  wire       w_uart_rx_dv;
  reg        r_uart_tx_dv   = 1'b0;
  reg  [7:0] r_uart_tx_data = 8'd0;
  wire       w_tx_busy;

  // Power-On Reset — 20-bit counter @ 50 MHz = ~20 ms, covering PLL lock time.
  // Vivado FIFOs require an active-high reset to initialize properly.
  reg  [19:0] r_rst_cnt = 20'hFFFFF;
  wire        w_sys_rst = (r_rst_cnt != 0);
  wire        rst_n     = ~w_sys_rst;

  always @(posedge w_clk_50MHz) begin
    if (r_rst_cnt != 0) r_rst_cnt <= r_rst_cnt - 1'b1;
  end

  // PLL / clock wizard
  clk_wiz_0 pll_50MHz_inst (
      .clk_in1_p(USER_SI570_CLOCK_P),
      .clk_in1_n(USER_SI570_CLOCK_N),
      .clk_out1 (w_clk_50MHz)
  );

  // UART receiver
  uart_rx #(
      .G_CLK_FREQ(50000000),
      .G_BAUDRATE (115200)
  ) uart_receiver (
      .i_clk         (w_clk_50MHz),
      .i_uart_rx     (USB_UART_TX),
      .o_uart_rx_data(w_uart_rx_data),
      .o_uart_rx_dv  (w_uart_rx_dv)
  );

  // UART transmitter
  uart_tx #(
      .G_CLK_FREQ(50000000),
      .G_BAUDRATE (115200)
  ) uart_transmitter (
      .i_clk      (w_clk_50MHz),
      .i_tx_dv    (r_uart_tx_dv),
      .i_tx_data  (r_uart_tx_data),
      .o_tx_serial(USB_UART_RX),
      .o_tx_busy  (w_tx_busy)
  );

  // -----------------------------------------------------------------------
  // RX FIFO  —  UART RX (producer) → protocol stack (consumer)
  // -----------------------------------------------------------------------
  wire [7:0] w_rx_fifo_dout;
  wire       w_rx_fifo_full;
  wire       w_rx_fifo_empty;
  wire       w_rx_wr_rst_busy;
  wire       w_rx_rd_rst_busy;
  reg        r_rx_fifo_rd_en = 1'b0;

  uart_fifo rx_fifo (
      .clk        (w_clk_50MHz),
      .srst       (w_sys_rst),
      .din        (w_uart_rx_data),
      .wr_en      (w_uart_rx_dv & ~w_rx_wr_rst_busy),
      .rd_en      (r_rx_fifo_rd_en),
      .dout       (w_rx_fifo_dout),
      .full       (w_rx_fifo_full),
      .empty      (w_rx_fifo_empty),
      .wr_rst_busy(w_rx_wr_rst_busy),
      .rd_rst_busy(w_rx_rd_rst_busy)
  );

  // -----------------------------------------------------------------------
  // TX FIFO  —  protocol stack (producer) → UART TX (consumer)
  //
  // TX bridge is purely combinatorial: the serialiser's ready/valid
  // handshake drives the FIFO write port directly, no intermediate regs.
  // uart_tx_ready is fed back to the serialiser so it stalls when full.
  // -----------------------------------------------------------------------
  wire [7:0] w_tx_fifo_dout;
  wire       w_tx_fifo_full;
  wire       w_tx_fifo_empty;
  wire       w_tx_wr_rst_busy;
  wire       w_tx_rd_rst_busy;
  reg        r_tx_fifo_rd_en = 1'b0;

  wire       uart_tx_valid;
  wire [7:0] uart_tx_data;
  wire       uart_tx_ready = rst_n & ~w_tx_fifo_full & ~w_tx_wr_rst_busy;

  uart_fifo tx_fifo (
      .clk        (w_clk_50MHz),
      .srst       (w_sys_rst),
      .din        (uart_tx_data),
      .wr_en      (uart_tx_valid & uart_tx_ready),
      .rd_en      (r_tx_fifo_rd_en),
      .dout       (w_tx_fifo_dout),
      .full       (w_tx_fifo_full),
      .empty      (w_tx_fifo_empty),
      .wr_rst_busy(w_tx_wr_rst_busy),
      .rd_rst_busy(w_tx_rd_rst_busy)
  );

  // -----------------------------------------------------------------------
  // RX bridge  —  RX FIFO → protocol decoder (ready/valid stream)
  //
  // The FIFO has 1-cycle read latency, so we use a 3-state FSM to pop a
  // byte and hold it until the decoder asserts ready.
  // -----------------------------------------------------------------------
  wire       uart_rx_valid;
  wire [7:0] uart_rx_data;
  wire       uart_rx_ready;

  localparam [1:0] RXB_IDLE  = 2'd0,
                   RXB_WAIT  = 2'd1,   // rd_en pulsed, waiting for dout
                   RXB_VALID = 2'd2;   // dout stable, presenting to decoder
  reg [1:0] r_rxb_state = RXB_IDLE;

  assign uart_rx_valid = (r_rxb_state == RXB_VALID);
  assign uart_rx_data  = w_rx_fifo_dout;  // stable while in RXB_VALID

  always @(posedge w_clk_50MHz) begin
    if (w_sys_rst) begin
      r_rxb_state     <= RXB_IDLE;
      r_rx_fifo_rd_en <= 1'b0;
    end else begin
      r_rx_fifo_rd_en <= 1'b0;  // default: pulse

      case (r_rxb_state)
        RXB_IDLE: begin
          if (!w_rx_fifo_empty && !w_rx_rd_rst_busy) begin
            r_rx_fifo_rd_en <= 1'b1;
            r_rxb_state     <= RXB_WAIT;
          end
        end

        RXB_WAIT: begin
          r_rxb_state <= RXB_VALID;  // one-cycle bubble for FIFO latency
        end

        RXB_VALID: begin
          if (uart_rx_ready) begin  // decoder accepted the byte
            if (!w_rx_fifo_empty && !w_rx_rd_rst_busy) begin
              r_rx_fifo_rd_en <= 1'b1;  // pipeline: immediately start next pop
              r_rxb_state     <= RXB_WAIT;
            end else begin
              r_rxb_state <= RXB_IDLE;
            end
          end
        end

        default: r_rxb_state <= RXB_IDLE;
      endcase
    end
  end

  // -----------------------------------------------------------------------
  // Protocol stack
  // -----------------------------------------------------------------------

  // engine → serialiser → (TX bridge) → TX FIFO
  wire         proto_tx_valid;
  wire         proto_tx_ready;
  wire [527:0] proto_tx_data;

  // RX FIFO → (RX bridge) → decoder → engine
  wire         proto_rx_valid;
  wire         proto_rx_ready;
  wire [527:0] proto_rx_data;

  // engine ↔ test_core
  wire        core_wr_valid;
  wire        core_wr_ready;
  wire [31:0] core_wr_data;
  wire [7:0]  core_wr_len;
  wire        core_rd_valid;
  wire        core_rd_ready;
  wire [31:0] core_rd_data;
  wire [7:0]  core_rd_len;

  sdr_ctrl_protocol_byte_serialiser u_serialiser (
      .clk       (w_clk_50MHz),
      .rst_n     (rst_n),
      .core_valid(proto_tx_valid),
      .core_ready(proto_tx_ready),
      .core_data (proto_tx_data),
      .iter_valid(uart_tx_valid),
      .iter_ready(uart_tx_ready),
      .iter_data (uart_tx_data)
  );

  sdr_ctrl_protocol_byte_decoder u_decoder (
      .clk       (w_clk_50MHz),
      .core_valid(proto_rx_valid),
      .core_ready(proto_rx_ready),
      .core_data (proto_rx_data),
      .iter_valid(uart_rx_valid),
      .iter_ready(uart_rx_ready),
      .iter_data (uart_rx_data)
  );

  sdr_ctrl_protocol_engine u_engine (
      .clk          (w_clk_50MHz),
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

  cpu_core_quad #(
      .FPGA_ID(FPGA_ID)
  ) u_cpu_core (
      .clk          (w_clk_50MHz),
      .rst_n        (rst_n),
      .core_wr_valid(core_wr_valid),
      .core_wr_ready(core_wr_ready),
      .core_wr_data (core_wr_data),
      .core_wr_len  (core_wr_len),
      .core_rd_valid(core_rd_valid),
      .core_rd_ready(core_rd_ready),
      .core_rd_data (core_rd_data),
      .core_rd_len  (core_rd_len),
      // GTY MMIO bus
      .gty_en       (w_gty_en),
      .gty_addr_w   (w_gty_addr_w),
      .gty_wstrb    (w_gty_wstrb),
      .gty_wdata    (w_gty_wdata),
      .gty_rdata    (w_gty_rdata)
  );

  // -----------------------------------------------------------------------
  // GTY link: Aurora 64B/66B + MMIO bridge (QSFP1 lane 1)
  // -----------------------------------------------------------------------
  gty_link u_gty_link (
      .init_clk     (w_init_clk),
      .sys_rst      (w_sys_rst),
      .gt_refclk1_p (QSFP1_CLOCK_P),
      .gt_refclk1_n (QSFP1_CLOCK_N),
      .rxp          (QSFP1_RX1_P),
      .rxn          (QSFP1_RX1_N),
      .txp          (QSFP1_TX1_P),
      .txn          (QSFP1_TX1_N),
      .clk          (w_clk_50MHz),
      .rst_n        (rst_n),
      .en           (w_gty_en),
      .addr_w       (w_gty_addr_w),
      .wstrb        (w_gty_wstrb),
      .wdata        (w_gty_wdata),
      .rdata        (w_gty_rdata)
  );

  // -----------------------------------------------------------------------
  // TX Consumer FSM  —  TX FIFO → UART TX
  // -----------------------------------------------------------------------
  localparam [1:0] TX_IDLE = 2'd0,
                   TX_POP  = 2'd1,
                   TX_SEND = 2'd2;
  reg [1:0] r_tx_state = TX_IDLE;

  always @(posedge w_clk_50MHz) begin
    if (w_sys_rst) begin
      r_tx_state      <= TX_IDLE;
      r_tx_fifo_rd_en <= 1'b0;
      r_uart_tx_dv    <= 1'b0;
    end else begin
      r_tx_fifo_rd_en <= 1'b0;  // default: pulse
      r_uart_tx_dv    <= 1'b0;

      case (r_tx_state)
        TX_IDLE: begin
          // r_uart_tx_dv guard: w_tx_busy is registered so it reads 0 on
          // the same cycle the UART TX receives its rising edge trigger;
          // r_uart_tx_dv is still 1 that cycle, blocking a premature pop.
          if (!w_tx_fifo_empty && !w_tx_busy && !w_tx_rd_rst_busy && !r_uart_tx_dv) begin
            r_tx_fifo_rd_en <= 1'b1;
            r_tx_state      <= TX_POP;
          end
        end

        TX_POP: begin
          r_tx_state <= TX_SEND;  // one-cycle bubble for FIFO latency
        end

        TX_SEND: begin
          r_uart_tx_data <= w_tx_fifo_dout;
          r_uart_tx_dv   <= 1'b1;
          r_tx_state     <= TX_IDLE;
        end

        default: r_tx_state <= TX_IDLE;
      endcase
    end
  end

endmodule
