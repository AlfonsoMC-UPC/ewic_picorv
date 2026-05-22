`default_nettype none

module test_core #(
    parameter integer SETTLE_CYCLES = 5_000_000,
    parameter integer TX_BURSTS     = 8,
    parameter integer GAP_CYCLES    = 10_000_000,
    parameter integer FPGA_ID       = 8'hAB
)(
    input wire logic clk,
    input wire logic rst_n,
    // core_sdr write channel (test_core is master)
    output logic             core_wr_valid,
    input  wire logic        core_wr_ready,
    output logic [31:0]      core_wr_data,
    output logic [7:0]       core_wr_len,
    // core_sdr read channel
    input  wire logic        core_rd_valid,
    output logic             core_rd_ready,
    input  wire logic [31:0] core_rd_data,
    input  wire logic [7:0]  core_rd_len
);
    typedef enum logic [1:0] { S_SETTLE, S_TX, S_GAP } state_t;

    state_t state;
    localparam int SC_W = $clog2(SETTLE_CYCLES + 1);
    localparam int GC_W = $clog2(GAP_CYCLES    + 1);
    localparam int BC_W = $clog2(TX_BURSTS     + 1);

    logic [SC_W-1:0] settle_cnt;
    logic [GC_W-1:0] gap_cnt;
    logic [BC_W-1:0] burst_cnt;

    assign core_rd_ready  = 1'b1;
    assign core_wr_valid  = (state == S_TX);
    assign core_wr_data   = {FPGA_ID[7:0], 8'h00, 8'h00, 8'(burst_cnt)};
    assign core_wr_len    = 8'd4;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state      <= S_SETTLE;
            settle_cnt <= '0;
            gap_cnt    <= '0;
            burst_cnt  <= '0;
        end else begin
            case (state)
                S_SETTLE:
                    if (settle_cnt == SC_W'(SETTLE_CYCLES))
                        state <= S_TX;
                    else
                        settle_cnt <= settle_cnt + 1;

                S_TX:
                    if (core_wr_valid && core_wr_ready) begin
                        if (burst_cnt == BC_W'(TX_BURSTS - 1)) begin
                            burst_cnt <= '0;
                            gap_cnt   <= '0;
                            state     <= S_GAP;
                        end else begin
                            burst_cnt <= burst_cnt + 1;
                        end
                    end

                S_GAP:
                    if (gap_cnt == GC_W'(GAP_CYCLES))
                        state <= S_TX;
                    else
                        gap_cnt <= gap_cnt + 1;
            endcase
        end
    end

endmodule
