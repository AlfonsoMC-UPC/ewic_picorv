`timescale 1ns / 1ps

module uart_tx #(
    parameter integer G_CLK_FREQ = 50000000,
    parameter integer G_BAUDRATE = 115200
) (
    input  wire       i_clk,
    input  wire       i_tx_dv,      // High when we want to start sending
    input  wire [7:0] i_tx_data,    // Data to send
    output reg        o_tx_serial = 1'b1,  // idle-high; init prevents break on PLL startup
    output reg        o_tx_busy
);

  // FSM states
  localparam [1:0] IDLE = 2'd0, START_BIT = 2'd1, DATA_BITS = 2'd2, STOP_BIT = 2'd3;

  reg [1:0] r_state = IDLE;

  localparam integer R_CLOCKS_PER_BIT = G_CLK_FREQ / G_BAUDRATE;

  reg           r_prev_tx_dv = 1'b0;
  reg     [7:0] r_data;
  integer       r_clk_count = 0;
  reg     [2:0] r_tx_data_index = 3'd0;

  assign o_tx_busy = (r_state != IDLE);

  // Clock counter
  always @(posedge i_clk) begin
    if (r_state != IDLE) begin
      if (r_clk_count < R_CLOCKS_PER_BIT - 1) r_clk_count <= r_clk_count + 1;
      else r_clk_count <= 0;
    end
  end

  // FSM
  always @(posedge i_clk) begin
    case (r_state)
      IDLE: begin
        o_tx_serial  <= 1'b1;
        r_prev_tx_dv <= i_tx_dv;

        // Rising edge detect on i_tx_dv
        if ((i_tx_dv == 1'b1) && (r_prev_tx_dv == 1'b0)) begin
          r_data  <= i_tx_data;
          r_state <= START_BIT;
        end
      end

      START_BIT: begin
        o_tx_serial <= 1'b0;  // Start bit low
        if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          r_state <= DATA_BITS;
        end
      end

      DATA_BITS: begin
        o_tx_serial <= r_data[r_tx_data_index];
        if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          if (r_tx_data_index == 3'd7) begin
            r_tx_data_index <= 3'd0;
            r_state         <= STOP_BIT;
          end else begin
            r_tx_data_index <= r_tx_data_index + 1'b1;
          end
        end
      end

      STOP_BIT: begin
        o_tx_serial <= 1'b1;  // Stop bit high
        if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          r_state <= IDLE;
        end
      end
    endcase
  end

endmodule
