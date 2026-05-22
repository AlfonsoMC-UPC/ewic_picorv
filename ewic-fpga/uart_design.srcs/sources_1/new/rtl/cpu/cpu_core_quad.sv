// Quad PicoRV32 core with private BRAMs, Core-0-exclusive SDR MMIO,
// and a star mailbox (Core 0 is the router hub).
//
// Memory map (all cores see the same address space):
//   0x00000000 – 0x0000FFFF  Private BRAM  (64 KB, one per core)
//   0x10000000 – 0x1000000F  SDR MMIO       (Core 0 only)
//   0x20000000 – 0x2000004F  Local MMIO     (128-byte window)
//
// Local MMIO — registers common to all cores (offsets from LOCAL_BASE):
//   +0x00  MBOX_TX_DATA  (WO) – enqueue word toward Core 0  [non-zero cores]
//   +0x04  MBOX_TX_READY (RO) – 1 when TX slot is free      [non-zero cores]
//   +0x08  MBOX_RX_DATA  (RO, clears VALID) – word from Core 0 [non-zero cores]
//   +0x0C  MBOX_RX_VALID (RO)
//   +0x10  CORE_ID       (RO) – 0..3
//   +0x14  FPGA_ID       (RO) – set via FPGA_ID parameter
//
// Local MMIO — Core 0 extended registers (Core 0 → Core N mailboxes):
//   +0x20  C1_TX_DATA / +0x24 C1_TX_READY / +0x28 C1_RX_DATA / +0x2C C1_RX_VALID
//   +0x30  C2_TX_DATA / +0x34 C2_TX_READY / +0x38 C2_RX_DATA / +0x3C C2_RX_VALID
//   +0x40  C3_TX_DATA / +0x44 C3_TX_READY / +0x48 C3_RX_DATA / +0x4C C3_RX_VALID

module cpu_core_quad #(
    parameter MEM_INIT_FILE = "firmware.hex",
    parameter [7:0] FPGA_ID = 8'd0
) (
    input  logic clk,
    input  logic rst_n,

    output logic        core_wr_valid,
    input  logic        core_wr_ready,
    output logic [31:0] core_wr_data,
    output logic [7:0]  core_wr_len,

    input  logic        core_rd_valid,
    output logic        core_rd_ready,
    input  logic [31:0] core_rd_data,
    input  logic [7:0]  core_rd_len
);

    // -------------------------------------------------------------------------
    // PicoRV32 native memory buses (one set per core)
    // -------------------------------------------------------------------------
    logic        mem_valid0, mem_instr0, mem_ready0;
    logic [31:0] mem_addr0, mem_wdata0, mem_rdata0;
    logic [3:0]  mem_wstrb0;

    logic        mem_valid1, mem_instr1, mem_ready1;
    logic [31:0] mem_addr1, mem_wdata1, mem_rdata1;
    logic [3:0]  mem_wstrb1;

    logic        mem_valid2, mem_instr2, mem_ready2;
    logic [31:0] mem_addr2, mem_wdata2, mem_rdata2;
    logic [3:0]  mem_wstrb2;

    logic        mem_valid3, mem_instr3, mem_ready3;
    logic [31:0] mem_addr3, mem_wdata3, mem_rdata3;
    logic [3:0]  mem_wstrb3;

    // -------------------------------------------------------------------------
    // Address decode
    //   BRAM:  addr[31:16] == 0x0000
    //   SDR:   addr[31:4]  == 28'h100_0000  (0x10000000, Core 0 only)
    //   Local: addr[31:7]  == 25'h040_0000  (0x20000000, 128-byte window)
    // -------------------------------------------------------------------------
    logic bram_sel0, sdr_sel0, local_sel0;
    assign bram_sel0  = mem_valid0 && (mem_addr0[31:16] == 16'h0000);
    assign sdr_sel0   = mem_valid0 && (mem_addr0[31: 4] == 28'h100_0000);
    assign local_sel0 = mem_valid0 && (mem_addr0[31: 7] == 25'h040_0000);

    logic bram_sel1, local_sel1;
    assign bram_sel1  = mem_valid1 && (mem_addr1[31:16] == 16'h0000);
    assign local_sel1 = mem_valid1 && (mem_addr1[31: 7] == 25'h040_0000);

    logic bram_sel2, local_sel2;
    assign bram_sel2  = mem_valid2 && (mem_addr2[31:16] == 16'h0000);
    assign local_sel2 = mem_valid2 && (mem_addr2[31: 7] == 25'h040_0000);

    logic bram_sel3, local_sel3;
    assign bram_sel3  = mem_valid3 && (mem_addr3[31:16] == 16'h0000);
    assign local_sel3 = mem_valid3 && (mem_addr3[31: 7] == 25'h040_0000);

    // -------------------------------------------------------------------------
    // mem_ready — fires exactly one cycle after a decoded access
    // Core 0: BRAM | SDR | Local.  Cores 1-3: BRAM | Local only.
    // -------------------------------------------------------------------------
    logic mem_ready0_r, mem_ready1_r, mem_ready2_r, mem_ready3_r;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mem_ready0_r <= 1'b0; mem_ready1_r <= 1'b0;
            mem_ready2_r <= 1'b0; mem_ready3_r <= 1'b0;
        end else begin
            mem_ready0_r <= (bram_sel0 || sdr_sel0 || local_sel0) && !mem_ready0_r;
            mem_ready1_r <= (bram_sel1 ||              local_sel1) && !mem_ready1_r;
            mem_ready2_r <= (bram_sel2 ||              local_sel2) && !mem_ready2_r;
            mem_ready3_r <= (bram_sel3 ||              local_sel3) && !mem_ready3_r;
        end
    end
    assign mem_ready0 = mem_ready0_r;
    assign mem_ready1 = mem_ready1_r;
    assign mem_ready2 = mem_ready2_r;
    assign mem_ready3 = mem_ready3_r;

    // -------------------------------------------------------------------------
    // Private BRAMs (one 64 KB block per core)
    // -------------------------------------------------------------------------
    logic [31:0] bram_rdata0, bram_rdata1, bram_rdata2, bram_rdata3;

    (* keep_hierarchy = "yes" *) bram_mem #(
        .WORDS(16384), .INIT_FILE(MEM_INIT_FILE)
    ) u_bram0 (
        .clk(clk), .en(bram_sel0),
        .addr(mem_addr0[15:2]), .wstrb(mem_wstrb0),
        .wdata(mem_wdata0),     .rdata(bram_rdata0)
    );
    (* keep_hierarchy = "yes" *) bram_mem #(
        .WORDS(16384), .INIT_FILE(MEM_INIT_FILE)
    ) u_bram1 (
        .clk(clk), .en(bram_sel1),
        .addr(mem_addr1[15:2]), .wstrb(mem_wstrb1),
        .wdata(mem_wdata1),     .rdata(bram_rdata1)
    );
    (* keep_hierarchy = "yes" *) bram_mem #(
        .WORDS(16384), .INIT_FILE(MEM_INIT_FILE)
    ) u_bram2 (
        .clk(clk), .en(bram_sel2),
        .addr(mem_addr2[15:2]), .wstrb(mem_wstrb2),
        .wdata(mem_wdata2),     .rdata(bram_rdata2)
    );
    (* keep_hierarchy = "yes" *) bram_mem #(
        .WORDS(16384), .INIT_FILE(MEM_INIT_FILE)
    ) u_bram3 (
        .clk(clk), .en(bram_sel3),
        .addr(mem_addr3[15:2]), .wstrb(mem_wstrb3),
        .wdata(mem_wdata3),     .rdata(bram_rdata3)
    );

    // -------------------------------------------------------------------------
    // SDR MMIO — Core 0 exclusive (no arbitration required)
    // -------------------------------------------------------------------------
    logic [31:0] sdr_rdata;

    sdr_mmio u_mmio (
        .clk          (clk),
        .rst_n        (rst_n),
        .en           (sdr_sel0),
        .addr_w       (mem_addr0[3:2]),
        .wstrb        (mem_wstrb0),
        .wdata        (mem_wdata0),
        .rdata        (sdr_rdata),
        .core_wr_valid(core_wr_valid),
        .core_wr_ready(core_wr_ready),
        .core_wr_data (core_wr_data),
        .core_wr_len  (core_wr_len),
        .core_rd_valid(core_rd_valid),
        .core_rd_ready(core_rd_ready),
        .core_rd_data (core_rd_data),
        .core_rd_len  (core_rd_len)
    );

    // -------------------------------------------------------------------------
    // Star mailbox buffers
    //   buf_to_N   : Core 0 → Core N  (set by Core 0, cleared by Core N read)
    //   buf_from_N : Core N → Core 0  (set by Core N, cleared by Core 0 read)
    //
    // Local MMIO word offsets accessed (mem_addr[6:2]):
    //   Core N (N>0) TX:  offset 0  (MBOX_TX_DATA)  → buf_from_N
    //   Core N (N>0) RX:  offset 2  (MBOX_RX_DATA)  ← buf_to_N
    //   Core 0 → Core 1:  offset 8  (C1_TX_DATA)    → buf_to_1
    //   Core 0 ← Core 1:  offset 10 (C1_RX_DATA)   ← buf_from_1
    //   Core 0 → Core 2:  offset 12 (C2_TX_DATA)    → buf_to_2
    //   Core 0 ← Core 2:  offset 14 (C2_RX_DATA)   ← buf_from_2
    //   Core 0 → Core 3:  offset 16 (C3_TX_DATA)    → buf_to_3
    //   Core 0 ← Core 3:  offset 18 (C3_RX_DATA)   ← buf_from_3
    // -------------------------------------------------------------------------
    logic [31:0] buf_to_1, buf_to_2, buf_to_3;
    logic        buf_to_1_v, buf_to_2_v, buf_to_3_v;
    logic [31:0] buf_from_1, buf_from_2, buf_from_3;
    logic        buf_from_1_v, buf_from_2_v, buf_from_3_v;

    // buf_to_1 : Core 0 sets (offset 8), Core 1 clears (offset 2)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_to_1 <= '0; buf_to_1_v <= 1'b0; end
        else begin
            if (local_sel0 && mem_wstrb0 != 4'b0 && mem_addr0[6:2] == 5'd8 && !buf_to_1_v)
                begin buf_to_1 <= mem_wdata0; buf_to_1_v <= 1'b1; end
            else if (local_sel1 && mem_addr1[6:2] == 5'd2)
                buf_to_1_v <= 1'b0;
        end
    end

    // buf_from_1 : Core 1 sets (offset 0), Core 0 clears (offset 10)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_from_1 <= '0; buf_from_1_v <= 1'b0; end
        else begin
            if (local_sel1 && mem_wstrb1 != 4'b0 && mem_addr1[6:2] == 5'd0 && !buf_from_1_v)
                begin buf_from_1 <= mem_wdata1; buf_from_1_v <= 1'b1; end
            else if (local_sel0 && mem_addr0[6:2] == 5'd10)
                buf_from_1_v <= 1'b0;
        end
    end

    // buf_to_2 : Core 0 sets (offset 12), Core 2 clears (offset 2)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_to_2 <= '0; buf_to_2_v <= 1'b0; end
        else begin
            if (local_sel0 && mem_wstrb0 != 4'b0 && mem_addr0[6:2] == 5'd12 && !buf_to_2_v)
                begin buf_to_2 <= mem_wdata0; buf_to_2_v <= 1'b1; end
            else if (local_sel2 && mem_addr2[6:2] == 5'd2)
                buf_to_2_v <= 1'b0;
        end
    end

    // buf_from_2 : Core 2 sets (offset 0), Core 0 clears (offset 14)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_from_2 <= '0; buf_from_2_v <= 1'b0; end
        else begin
            if (local_sel2 && mem_wstrb2 != 4'b0 && mem_addr2[6:2] == 5'd0 && !buf_from_2_v)
                begin buf_from_2 <= mem_wdata2; buf_from_2_v <= 1'b1; end
            else if (local_sel0 && mem_addr0[6:2] == 5'd14)
                buf_from_2_v <= 1'b0;
        end
    end

    // buf_to_3 : Core 0 sets (offset 16), Core 3 clears (offset 2)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_to_3 <= '0; buf_to_3_v <= 1'b0; end
        else begin
            if (local_sel0 && mem_wstrb0 != 4'b0 && mem_addr0[6:2] == 5'd16 && !buf_to_3_v)
                begin buf_to_3 <= mem_wdata0; buf_to_3_v <= 1'b1; end
            else if (local_sel3 && mem_addr3[6:2] == 5'd2)
                buf_to_3_v <= 1'b0;
        end
    end

    // buf_from_3 : Core 3 sets (offset 0), Core 0 clears (offset 18)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin buf_from_3 <= '0; buf_from_3_v <= 1'b0; end
        else begin
            if (local_sel3 && mem_wstrb3 != 4'b0 && mem_addr3[6:2] == 5'd0 && !buf_from_3_v)
                begin buf_from_3 <= mem_wdata3; buf_from_3_v <= 1'b1; end
            else if (local_sel0 && mem_addr0[6:2] == 5'd18)
                buf_from_3_v <= 1'b0;
        end
    end

    // -------------------------------------------------------------------------
    // Local MMIO read-data (registered, 1-cycle latency matching BRAM)
    // -------------------------------------------------------------------------

    // Core 0: CORE_ID/FPGA_ID + extended per-peer registers
    logic [31:0] local_rdata0;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) local_rdata0 <= '0;
        else begin
            local_rdata0 <= '0;
            if (local_sel0) begin
                case (mem_addr0[6:2])
                    5'd4:  local_rdata0 <= 32'd0;             // CORE_ID = 0
                    5'd5:  local_rdata0 <= {24'b0, FPGA_ID};  // FPGA_ID
                    // Core 1 channel
                    5'd9:  local_rdata0 <= {31'b0, !buf_to_1_v};
                    5'd10: local_rdata0 <= buf_from_1;
                    5'd11: local_rdata0 <= {31'b0, buf_from_1_v};
                    // Core 2 channel
                    5'd13: local_rdata0 <= {31'b0, !buf_to_2_v};
                    5'd14: local_rdata0 <= buf_from_2;
                    5'd15: local_rdata0 <= {31'b0, buf_from_2_v};
                    // Core 3 channel
                    5'd17: local_rdata0 <= {31'b0, !buf_to_3_v};
                    5'd18: local_rdata0 <= buf_from_3;
                    5'd19: local_rdata0 <= {31'b0, buf_from_3_v};
                    default:;
                endcase
            end
        end
    end

    // Core 1: peer mailbox toward Core 0
    logic [31:0] local_rdata1;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) local_rdata1 <= '0;
        else begin
            local_rdata1 <= '0;
            if (local_sel1) begin
                case (mem_addr1[6:2])
                    5'd1: local_rdata1 <= {31'b0, !buf_from_1_v};  // MBOX_TX_READY
                    5'd2: local_rdata1 <= buf_to_1;                 // MBOX_RX_DATA
                    5'd3: local_rdata1 <= {31'b0, buf_to_1_v};     // MBOX_RX_VALID
                    5'd4: local_rdata1 <= 32'd1;                    // CORE_ID = 1
                    5'd5: local_rdata1 <= {24'b0, FPGA_ID};
                    default:;
                endcase
            end
        end
    end

    // Core 2: peer mailbox toward Core 0
    logic [31:0] local_rdata2;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) local_rdata2 <= '0;
        else begin
            local_rdata2 <= '0;
            if (local_sel2) begin
                case (mem_addr2[6:2])
                    5'd1: local_rdata2 <= {31'b0, !buf_from_2_v};  // MBOX_TX_READY
                    5'd2: local_rdata2 <= buf_to_2;                 // MBOX_RX_DATA
                    5'd3: local_rdata2 <= {31'b0, buf_to_2_v};     // MBOX_RX_VALID
                    5'd4: local_rdata2 <= 32'd2;                    // CORE_ID = 2
                    5'd5: local_rdata2 <= {24'b0, FPGA_ID};
                    default:;
                endcase
            end
        end
    end

    // Core 3: peer mailbox toward Core 0
    logic [31:0] local_rdata3;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) local_rdata3 <= '0;
        else begin
            local_rdata3 <= '0;
            if (local_sel3) begin
                case (mem_addr3[6:2])
                    5'd1: local_rdata3 <= {31'b0, !buf_from_3_v};  // MBOX_TX_READY
                    5'd2: local_rdata3 <= buf_to_3;                 // MBOX_RX_DATA
                    5'd3: local_rdata3 <= {31'b0, buf_to_3_v};     // MBOX_RX_VALID
                    5'd4: local_rdata3 <= 32'd3;                    // CORE_ID = 3
                    5'd5: local_rdata3 <= {24'b0, FPGA_ID};
                    default:;
                endcase
            end
        end
    end

    // -------------------------------------------------------------------------
    // Read-data mux (PicoRV32 holds mem_addr stable until mem_ready)
    // -------------------------------------------------------------------------
    assign mem_rdata0 = (mem_addr0[31:16] == 16'h0000)    ? bram_rdata0 :
                        (mem_addr0[31: 4] == 28'h100_0000) ? sdr_rdata   :
                                                              local_rdata0;
    assign mem_rdata1 = (mem_addr1[31:16] == 16'h0000) ? bram_rdata1 : local_rdata1;
    assign mem_rdata2 = (mem_addr2[31:16] == 16'h0000) ? bram_rdata2 : local_rdata2;
    assign mem_rdata3 = (mem_addr3[31:16] == 16'h0000) ? bram_rdata3 : local_rdata3;

    // -------------------------------------------------------------------------
    // PicoRV32 instances (shared parameter block)
    // -------------------------------------------------------------------------
    localparam PV32_PARAMS = 0;  // dummy — parameters listed inline below

    picorv32 #(
        .ENABLE_COUNTERS(0), .ENABLE_REGS_16_31(1), .ENABLE_REGS_DUALPORT(1),
        .TWO_STAGE_SHIFT(0), .BARREL_SHIFTER(1),    .TWO_CYCLE_COMPARE(0),
        .TWO_CYCLE_ALU(0),   .COMPRESSED_ISA(0),    .CATCH_MISALIGN(0),
        .CATCH_ILLINSN(0),   .ENABLE_PCPI(0),        .ENABLE_MUL(0),
        .ENABLE_FAST_MUL(0), .ENABLE_DIV(0),         .ENABLE_IRQ(0),
        .ENABLE_IRQ_QREGS(0),
        .PROGADDR_RESET(32'h0000_0000), .PROGADDR_IRQ(32'h0000_0010)
    ) u_cpu0 (
        .clk(clk), .resetn(rst_n),
        .mem_valid(mem_valid0), .mem_instr(mem_instr0), .mem_ready(mem_ready0),
        .mem_addr(mem_addr0), .mem_wdata(mem_wdata0), .mem_wstrb(mem_wstrb0),
        .mem_rdata(mem_rdata0),
        .mem_la_read(), .mem_la_write(), .mem_la_addr(), .mem_la_wdata(), .mem_la_wstrb(),
        .pcpi_valid(), .pcpi_insn(), .pcpi_rs1(), .pcpi_rs2(),
        .pcpi_wr(1'b0), .pcpi_rd(32'b0), .pcpi_wait(1'b0), .pcpi_ready(1'b0),
        .irq(32'b0), .eoi()
    );

    picorv32 #(
        .ENABLE_COUNTERS(0), .ENABLE_REGS_16_31(1), .ENABLE_REGS_DUALPORT(1),
        .TWO_STAGE_SHIFT(0), .BARREL_SHIFTER(1),    .TWO_CYCLE_COMPARE(0),
        .TWO_CYCLE_ALU(0),   .COMPRESSED_ISA(0),    .CATCH_MISALIGN(0),
        .CATCH_ILLINSN(0),   .ENABLE_PCPI(0),        .ENABLE_MUL(0),
        .ENABLE_FAST_MUL(0), .ENABLE_DIV(0),         .ENABLE_IRQ(0),
        .ENABLE_IRQ_QREGS(0),
        .PROGADDR_RESET(32'h0000_0000), .PROGADDR_IRQ(32'h0000_0010)
    ) u_cpu1 (
        .clk(clk), .resetn(rst_n),
        .mem_valid(mem_valid1), .mem_instr(mem_instr1), .mem_ready(mem_ready1),
        .mem_addr(mem_addr1), .mem_wdata(mem_wdata1), .mem_wstrb(mem_wstrb1),
        .mem_rdata(mem_rdata1),
        .mem_la_read(), .mem_la_write(), .mem_la_addr(), .mem_la_wdata(), .mem_la_wstrb(),
        .pcpi_valid(), .pcpi_insn(), .pcpi_rs1(), .pcpi_rs2(),
        .pcpi_wr(1'b0), .pcpi_rd(32'b0), .pcpi_wait(1'b0), .pcpi_ready(1'b0),
        .irq(32'b0), .eoi()
    );

    picorv32 #(
        .ENABLE_COUNTERS(0), .ENABLE_REGS_16_31(1), .ENABLE_REGS_DUALPORT(1),
        .TWO_STAGE_SHIFT(0), .BARREL_SHIFTER(1),    .TWO_CYCLE_COMPARE(0),
        .TWO_CYCLE_ALU(0),   .COMPRESSED_ISA(0),    .CATCH_MISALIGN(0),
        .CATCH_ILLINSN(0),   .ENABLE_PCPI(0),        .ENABLE_MUL(0),
        .ENABLE_FAST_MUL(0), .ENABLE_DIV(0),         .ENABLE_IRQ(0),
        .ENABLE_IRQ_QREGS(0),
        .PROGADDR_RESET(32'h0000_0000), .PROGADDR_IRQ(32'h0000_0010)
    ) u_cpu2 (
        .clk(clk), .resetn(rst_n),
        .mem_valid(mem_valid2), .mem_instr(mem_instr2), .mem_ready(mem_ready2),
        .mem_addr(mem_addr2), .mem_wdata(mem_wdata2), .mem_wstrb(mem_wstrb2),
        .mem_rdata(mem_rdata2),
        .mem_la_read(), .mem_la_write(), .mem_la_addr(), .mem_la_wdata(), .mem_la_wstrb(),
        .pcpi_valid(), .pcpi_insn(), .pcpi_rs1(), .pcpi_rs2(),
        .pcpi_wr(1'b0), .pcpi_rd(32'b0), .pcpi_wait(1'b0), .pcpi_ready(1'b0),
        .irq(32'b0), .eoi()
    );

    picorv32 #(
        .ENABLE_COUNTERS(0), .ENABLE_REGS_16_31(1), .ENABLE_REGS_DUALPORT(1),
        .TWO_STAGE_SHIFT(0), .BARREL_SHIFTER(1),    .TWO_CYCLE_COMPARE(0),
        .TWO_CYCLE_ALU(0),   .COMPRESSED_ISA(0),    .CATCH_MISALIGN(0),
        .CATCH_ILLINSN(0),   .ENABLE_PCPI(0),        .ENABLE_MUL(0),
        .ENABLE_FAST_MUL(0), .ENABLE_DIV(0),         .ENABLE_IRQ(0),
        .ENABLE_IRQ_QREGS(0),
        .PROGADDR_RESET(32'h0000_0000), .PROGADDR_IRQ(32'h0000_0010)
    ) u_cpu3 (
        .clk(clk), .resetn(rst_n),
        .mem_valid(mem_valid3), .mem_instr(mem_instr3), .mem_ready(mem_ready3),
        .mem_addr(mem_addr3), .mem_wdata(mem_wdata3), .mem_wstrb(mem_wstrb3),
        .mem_rdata(mem_rdata3),
        .mem_la_read(), .mem_la_write(), .mem_la_addr(), .mem_la_wdata(), .mem_la_wstrb(),
        .pcpi_valid(), .pcpi_insn(), .pcpi_rs1(), .pcpi_rs2(),
        .pcpi_wr(1'b0), .pcpi_rd(32'b0), .pcpi_wait(1'b0), .pcpi_ready(1'b0),
        .irq(32'b0), .eoi()
    );

endmodule
`default_nettype wire
