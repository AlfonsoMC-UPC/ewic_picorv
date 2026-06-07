// Memory-mapped SDR interface for PicoRV32.
//
// Address map (byte addresses, 4-byte aligned):
//   +0x00  SDR_TX_DATA  (WO) – write a 32-bit word; two writes complete a message
//   +0x04  SDR_TX_READY (RO) – 1 when TX can accept a new word
//   +0x08  SDR_RX_DATA  (RO) – most-recent received word (reading also clears RX_VALID)
//   +0x0C  SDR_RX_VALID (RO) – 1 when unread data is waiting in SDR_RX_DATA
//
// TX protocol: the firmware sends messages in 2-word pairs (header + data).
//   Word 0 (hdr): bits[31:24] = destination FPGA/SDR ID.
//   Word 1 (dat): payload data.
// The module buffers both words, extracts the destination from word 0, then
// presents an 8-byte message to the protocol engine with the correct dst.
//
// SDR_TX_READY is 1 whenever the buffer can accept another word (not FULL).
// The CPU should poll SDR_TX_READY between each of the two writes.

module sdr_mmio (
    input  logic        clk,
    input  logic        rst_n,

    // PicoRV32 bus (active only when this region is selected)
    input  logic        en,          // 1 when CPU targets this region
    input  logic [1:0]  addr_w,      // word offset: mem_addr[3:2]
    input  logic [3:0]  wstrb,
    input  logic [31:0] wdata,
    output logic [31:0] rdata,

    // SDR protocol engine (new pull/credit interface)
    output logic        core_wr_valid,
    input  logic        core_wr_ready,
    output logic [31:0] core_wr_data,
    output logic [15:0] core_wr_total_len,
    output logic [7:0]  core_wr_dst,
    input  logic        core_wr_done,

    input  logic        core_rd_valid,
    output logic        core_rd_ready,
    input  logic [31:0] core_rd_data,
    input  logic [7:0]  core_rd_len,  // unused; always DATA_BYTES
    input  logic        core_rd_last  // unused; fire-and-forget
);

    // --- TX 2-word buffer ---
    typedef enum logic [1:0] { ST_EMPTY, ST_HALF, ST_FULL } buf_state_t;

    buf_state_t buf_state;
    logic [31:0] tx_word0, tx_word1;
    logic [7:0]  tx_dst;    // destination extracted from word0[31:24]
    logic        word_sel;  // 0 → present word0, 1 → present word1

    wire tx_ready = (buf_state != ST_FULL);

    assign core_wr_valid     = (buf_state == ST_FULL);
    assign core_wr_data      = word_sel ? tx_word1 : tx_word0;
    assign core_wr_total_len = 16'd8;   // always 2 words
    assign core_wr_dst       = tx_dst;

    // --- RX ---
    logic        rx_valid;
    logic [31:0] rx_data_r;

    assign core_rd_ready = !rx_valid;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            buf_state <= ST_EMPTY;
            tx_word0  <= '0;
            tx_word1  <= '0;
            tx_dst    <= '0;
            word_sel  <= 1'b0;
            rx_valid  <= 1'b0;
            rx_data_r <= '0;
            rdata     <= '0;
        end else begin

            // --- TX: advance word_sel on each engine pull ---
            if (core_wr_valid && core_wr_ready)
                word_sel <= ~word_sel;

            // --- TX: buffer released after engine completes the message ---
            if (core_wr_done) begin
                buf_state <= ST_EMPTY;
                word_sel  <= 1'b0;
            end

            // --- RX: capture incoming word ---
            if (core_rd_valid && core_rd_ready) begin
                rx_data_r <= core_rd_data;
                rx_valid  <= 1'b1;
            end

            rdata <= '0;

            if (en) begin
                case (addr_w)
                    2'b00: begin  // SDR_TX_DATA (write)
                        if (wstrb != 4'b0 && tx_ready && !core_wr_done) begin
                            case (buf_state)
                                ST_EMPTY: begin
                                    tx_word0  <= wdata;
                                    tx_dst    <= wdata[31:24];
                                    buf_state <= ST_HALF;
                                end
                                ST_HALF: begin
                                    tx_word1  <= wdata;
                                    word_sel  <= 1'b0;
                                    buf_state <= ST_FULL;
                                end
                                default: ;
                            endcase
                        end
                    end
                    2'b01: begin  // SDR_TX_READY (read)
                        rdata <= {31'b0, tx_ready};
                    end
                    2'b10: begin  // SDR_RX_DATA (read clears valid)
                        rdata    <= rx_data_r;
                        rx_valid <= 1'b0;
                    end
                    2'b11: begin  // SDR_RX_VALID (read)
                        rdata <= {31'b0, rx_valid};
                    end
                endcase
            end
        end
    end
endmodule
`default_nettype wire
