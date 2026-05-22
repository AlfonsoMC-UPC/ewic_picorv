// Dual-port synchronous BRAM, 32-bit words, byte write enables.
// 1-cycle read latency (synchronous read — Vivado infers block RAM).
// Initialized from a hex file; empty string = no init (all zeros).
module bram_mem #(
    parameter int    WORDS     = 16384,   // 64 KB / 4
    parameter INIT_FILE = ""
) (
    input  logic        clk,
    input  logic        en,
    input  logic [$clog2(WORDS)-1:0] addr,
    input  logic [3:0]  wstrb,
    input  logic [31:0] wdata,
    output logic [31:0] rdata
);
    (* ram_style = "block" *)
    logic [31:0] mem [0:WORDS-1];

    initial begin
        if (INIT_FILE != "") $readmemh(INIT_FILE, mem);
    end

    always_ff @(posedge clk) begin
        if (en) begin
            if (wstrb[0]) mem[addr][ 7: 0] <= wdata[ 7: 0];
            if (wstrb[1]) mem[addr][15: 8] <= wdata[15: 8];
            if (wstrb[2]) mem[addr][23:16] <= wdata[23:16];
            if (wstrb[3]) mem[addr][31:24] <= wdata[31:24];
            rdata <= mem[addr];
        end
    end
endmodule
`default_nettype wire
