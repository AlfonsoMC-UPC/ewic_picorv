// Memory-mapped SDR interface for PicoRV32.
//
// Address map (byte addresses, 4-byte aligned):
//   +0x00  SDR_TX_DATA  (WO) – write a 32-bit word; initiates one OP_DATA packet
//   +0x04  SDR_TX_READY (RO) – 1 when TX can accept a new packet
//   +0x08  SDR_RX_DATA  (RO) – most-recent received word (reading also clears RX_VALID)
//   +0x0C  SDR_RX_VALID (RO) – 1 when unread data is waiting in SDR_RX_DATA
//
// All reads take 1 cycle (rdata is registered), matching bram_mem latency.

module sdr_mmio (
    input  logic        clk,
    input  logic        rst_n,

    // PicoRV32 bus (active only when this region is selected)
    input  logic        en,          // 1 when CPU targets this region
    input  logic [1:0]  addr_w,      // word offset: mem_addr[3:2]
    input  logic [3:0]  wstrb,
    input  logic [31:0] wdata,
    output logic [31:0] rdata,

    // SDR protocol engine
    output logic        core_wr_valid,
    input  logic        core_wr_ready,
    output logic [31:0] core_wr_data,
    output logic [7:0]  core_wr_len,

    input  logic        core_rd_valid,
    output logic        core_rd_ready,
    input  logic [31:0] core_rd_data,
    input  logic [7:0]  core_rd_len  // unused, always 4
);

    // --- TX ---
    logic        tx_pending;
    logic [31:0] tx_data_r;

    assign core_wr_valid = tx_pending;
    assign core_wr_data  = tx_data_r;
    assign core_wr_len   = 8'd4;

    // --- RX ---
    logic        rx_valid;
    logic [31:0] rx_data_r;

    // Accept a new RX packet only when the buffer is empty
    assign core_rd_ready = !rx_valid;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tx_pending <= 1'b0;
            tx_data_r  <= '0;
            rx_valid   <= 1'b0;
            rx_data_r  <= '0;
            rdata      <= '0;
        end else begin
            // TX handshake: clear once the engine accepts
            if (tx_pending && core_wr_ready)
                tx_pending <= 1'b0;

            // RX latch: capture incoming packet
            if (core_rd_valid && core_rd_ready) begin
                rx_data_r <= core_rd_data;
                rx_valid  <= 1'b1;
            end

            // Default rdata (will be overridden on read)
            rdata <= '0;

            if (en) begin
                case (addr_w)
                    2'b00: begin  // SDR_TX_DATA (write-only)
                        if (wstrb != 4'b0 && !tx_pending) begin
                            tx_data_r  <= wdata;
                            tx_pending <= 1'b1;
                        end
                    end
                    2'b01: begin  // SDR_TX_READY (read-only)
                        rdata <= {31'b0, !tx_pending};
                    end
                    2'b10: begin  // SDR_RX_DATA (read clears valid)
                        rdata    <= rx_data_r;
                        rx_valid <= 1'b0;
                    end
                    2'b11: begin  // SDR_RX_VALID (read-only)
                        rdata <= {31'b0, rx_valid};
                    end
                endcase
            end
        end
    end
endmodule
`default_nettype wire
