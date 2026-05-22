`timescale 1ns / 1ps

module uart_rx #(
    parameter integer G_CLK_FREQ = 156250000,
    parameter integer G_BAUDRATE = 115200
) (
    input  wire       i_clk,
    input  wire       i_uart_rx,
    output reg  [7:0] o_uart_rx_data,
    output reg        o_uart_rx_dv
);

  // FSM states
  localparam [1:0] IDLE = 2'd0, START_BIT = 2'd1, DATA_BITS = 2'd2, STOP_BIT = 2'd3;

  reg [1:0] r_state = IDLE;

  // Timing parameters
  localparam integer R_CLOCKS_PER_BIT = G_CLK_FREQ / G_BAUDRATE;
  localparam integer R_MIDDLE_BIT_COUNT = R_CLOCKS_PER_BIT / 2;

  integer r_clk_count = 0;
  reg [2:0] r_rx_data_index = 3'd0;

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
        o_uart_rx_dv <= 1'b0;
        if (i_uart_rx == 1'b0) begin
          r_state <= START_BIT;
        end
      end

      START_BIT: begin
        // Error: line not low in middle of start bit
        if ((r_clk_count == R_MIDDLE_BIT_COUNT) && (i_uart_rx == 1'b1)) begin
          r_state <= IDLE;
        end else if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          r_state <= DATA_BITS;
        end
      end

      DATA_BITS: begin
        o_uart_rx_dv <= 1'b0;
        if (r_clk_count == R_MIDDLE_BIT_COUNT) begin
          o_uart_rx_data[r_rx_data_index] <= i_uart_rx;
        end else if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          if (r_rx_data_index == 3'd7) begin
            r_rx_data_index <= 3'd0;
            r_state <= STOP_BIT;
          end else begin
            r_rx_data_index <= r_rx_data_index + 1'b1;
          end
        end
      end

      STOP_BIT: begin
        // Error: line not high in middle of stop bit
        if ((r_clk_count == R_MIDDLE_BIT_COUNT) && (i_uart_rx == 1'b0)) begin
          r_state      <= IDLE;
          o_uart_rx_dv <= 1'b0;
        end else if (r_clk_count == R_CLOCKS_PER_BIT - 1) begin
          r_state      <= IDLE;
          o_uart_rx_dv <= 1'b1;
        end
      end
    endcase
  end

endmodule
