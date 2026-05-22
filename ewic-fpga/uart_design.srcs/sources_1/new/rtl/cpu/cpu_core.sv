// PicoRV32 CPU core with BRAM and memory-mapped SDR interface.
//
// Memory map
// ----------
//   0x00000000 – 0x0000FFFF  BRAM  (64 KB, instruction + data + stack)
//   0x10000000 – 0x1000000F  SDR MMIO  (see sdr_mmio.sv)
//
// The BRAM is initialised from MEM_INIT_FILE at elaboration time via
// $readmemh.  Build firmware/ first; the generated firmware.hex must be
// accessible at that path when Vivado runs synthesis.
//
// All memory transactions complete in 1 cycle (synchronous BRAM + registered
// MMIO registers), so PicoRV32 never stalls beyond the natural 1-cycle
// pipeline fill.

module cpu_core #(
    // Path to the 32-bit word hex file produced by firmware/Makefile.
    // Relative paths are resolved from the Vivado project directory.
    // Vivado resolves $readmemh paths relative to the source file.
    // Run "make install" in firmware/ to copy firmware.hex here.
    parameter MEM_INIT_FILE = "firmware.hex"
) (
    input  logic clk,
    input  logic rst_n,

    // SDR protocol engine interface (same as test_core)
    output logic        core_wr_valid,
    input  logic        core_wr_ready,
    output logic [31:0] core_wr_data,
    output logic [7:0]  core_wr_len,

    input  logic        core_rd_valid,
    output logic        core_rd_ready,
    input  logic [31:0] core_rd_data,
    input  logic [7:0]  core_rd_len
);

    // -----------------------------------------------------------------------
    // PicoRV32 native memory bus
    // -----------------------------------------------------------------------
    logic        mem_valid, mem_instr, mem_ready;
    logic [31:0] mem_addr, mem_wdata, mem_rdata;
    logic [3:0]  mem_wstrb;

    // -----------------------------------------------------------------------
    // Address decode (combinatorial)
    // -----------------------------------------------------------------------
    logic bram_sel, mmio_sel;
    assign bram_sel = mem_valid && (mem_addr[31:16] == 16'h0000);
    assign mmio_sel = mem_valid && (mem_addr[31: 4] == 28'h100_0000);

    // -----------------------------------------------------------------------
    // mem_ready: assert exactly one cycle after a valid, decoded access.
    // PicoRV32 holds mem_valid + addr stable until mem_ready fires.
    // -----------------------------------------------------------------------
    logic mem_ready_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) mem_ready_r <= 1'b0;
        else        mem_ready_r <= (bram_sel || mmio_sel) && !mem_ready_r;
    end
    assign mem_ready = mem_ready_r;

    // -----------------------------------------------------------------------
    // BRAM (64 KB)
    // -----------------------------------------------------------------------
    logic [31:0] bram_rdata;

    (* keep_hierarchy = "yes" *) bram_mem #(
        .WORDS    (16384),
        .INIT_FILE(MEM_INIT_FILE)
    ) u_bram (
        .clk  (clk),
        .en   (bram_sel),
        .addr (mem_addr[15:2]),
        .wstrb(mem_wstrb),
        .wdata(mem_wdata),
        .rdata(bram_rdata)
    );

    // -----------------------------------------------------------------------
    // SDR MMIO
    // -----------------------------------------------------------------------
    logic [31:0] mmio_rdata;

    sdr_mmio u_mmio (
        .clk          (clk),
        .rst_n        (rst_n),
        .en           (mmio_sel),
        .addr_w       (mem_addr[3:2]),
        .wstrb        (mem_wstrb),
        .wdata        (mem_wdata),
        .rdata        (mmio_rdata),
        .core_wr_valid(core_wr_valid),
        .core_wr_ready(core_wr_ready),
        .core_wr_data (core_wr_data),
        .core_wr_len  (core_wr_len),
        .core_rd_valid(core_rd_valid),
        .core_rd_ready(core_rd_ready),
        .core_rd_data (core_rd_data),
        .core_rd_len  (core_rd_len)
    );

    // -----------------------------------------------------------------------
    // Read-data mux
    // When mem_ready fires (cycle N+1), mem_valid and mem_addr are still
    // stable, so this combinatorial select is safe.
    // -----------------------------------------------------------------------
    assign mem_rdata = (mem_addr[31:16] == 16'h0000) ? bram_rdata : mmio_rdata;

    // -----------------------------------------------------------------------
    // PicoRV32 instance (RV32I, minimal feature set to save LUTs)
    // -----------------------------------------------------------------------
    picorv32 #(
        .ENABLE_COUNTERS    (0),
        .ENABLE_REGS_16_31  (1),
        .ENABLE_REGS_DUALPORT(1),
        .TWO_STAGE_SHIFT    (0),
        .BARREL_SHIFTER     (1),
        .TWO_CYCLE_COMPARE  (0),
        .TWO_CYCLE_ALU      (0),
        .COMPRESSED_ISA     (0),
        .CATCH_MISALIGN     (0),
        .CATCH_ILLINSN      (0),
        .ENABLE_PCPI        (0),
        .ENABLE_MUL         (0),
        .ENABLE_FAST_MUL    (0),
        .ENABLE_DIV         (0),
        .ENABLE_IRQ         (0),
        .ENABLE_IRQ_QREGS   (0),
        .PROGADDR_RESET     (32'h0000_0000),
        .PROGADDR_IRQ       (32'h0000_0010)
    ) u_cpu (
        .clk      (clk),
        .resetn   (rst_n),
        .mem_valid(mem_valid),
        .mem_instr(mem_instr),
        .mem_ready(mem_ready),
        .mem_addr (mem_addr),
        .mem_wdata(mem_wdata),
        .mem_wstrb(mem_wstrb),
        .mem_rdata(mem_rdata),
        // Look-ahead interface — unused
        .mem_la_read (),
        .mem_la_write(),
        .mem_la_addr (),
        .mem_la_wdata(),
        .mem_la_wstrb(),
        // PCPI — unused
        .pcpi_valid(      ),
        .pcpi_insn (      ),
        .pcpi_rs1  (      ),
        .pcpi_rs2  (      ),
        .pcpi_wr   (1'b0  ),
        .pcpi_rd   (32'b0 ),
        .pcpi_wait (1'b0  ),
        .pcpi_ready(1'b0  ),
        // IRQ — unused
        .irq(32'b0),
        .eoi(      )
    );

endmodule
`default_nettype wire
