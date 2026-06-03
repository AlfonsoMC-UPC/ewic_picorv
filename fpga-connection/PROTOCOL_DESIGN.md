# FPGA–SDR Control Protocol — Pull/Credit Redesign

Status: **design, pre-implementation**
Scope: the link between the FPGA protocol engine (RTL) and the SDR (software,
`sdr_fsm.c`/`sdr_sim.c`). The hub token MAC (`sdr_hub.c`) is unchanged.

---

## 1. Motivation

The current protocol (`sdr_ctrl_protocol_engine.sv`, `sdr_fsm.c`) is **push-based**:
the FPGA streams `OP_DATA` whenever it has data, and the SDR throttles it with
`OP_PAUSE`/`OP_RESUME` against a 16-packet TX ring with high/low-water marks.

Problems with push + watermark backpressure:

- The SDR needs a multi-packet queue and watermark logic it cannot really afford
  (real SDR has very little memory).
- `OP_PAUSE`/`OP_RESUME` add round-trips and a window in which the buffer can
  still overflow (`sdr_fsm.c` has an explicit "TX queue overflow, dropping
  packet" path).
- Backpressure state is duplicated on both sides and is fragile across resets.

This redesign makes TX **pull/credit-based**: the SDR asks for data only when it
has room, so **TX-buffer overflow is impossible by construction** and the SDR
needs only a single fixed buffer. RX stays a fire-and-forget stream.

---

## 2. Roles and assumptions

- **SDR TX buffer is a single fixed-size slot**, `BUFFER_SIZE` bytes. It is
  either **EMPTY** or **OCCUPIED**. The SDR knows nothing about the data beyond
  what fits in this buffer.
- **The FPGA owns all message state.** It tracks the core's transaction, chunks
  it to `BUFFER_SIZE`, and decides what to send.
- **Token MAC.** Each time the SDR is granted a slot by the hub it drains its
  entire TX buffer over the air, then the buffer is EMPTY again.
- **Reliable FPGA↔SDR link.** Bytes are not lost or corrupted in transit. (This
  assumption is what lets the poll be one-shot and lets us omit CRC/resync. If
  the link becomes lossy, see §9.)
- **RX is lossy by nature.** The SDR has no memory to hold received samples; if
  the FPGA cannot accept an RX packet it is dropped. There is therefore **no RX
  backpressure** — but the implementation must drop at *frame* granularity, not
  stall (see §6).
- **UART is full-duplex**: FPGA→SDR (TX wire) and SDR→FPGA (RX wire) are
  physically independent directions and never contend.

---

## 3. Flow-control model (TX): one-buffer credit

```
SDR buffer EMPTY ──► SDR sends exactly ONE OP_POLL ──► FPGA holds a 1-buffer credit
        ▲                                                        │
        │                                                        ▼
   token drain ◄── SDR drains buffer over the air ◄── FPGA sends ONE chunk (≤ BUFFER_SIZE)
```

- A `POLL` is a **credit for exactly one buffer**. It carries no size — the credit
  is implicitly one `BUFFER_SIZE` slot.
- The SDR polls **once per drain edge** and then waits. It never spins or
  re-polls while waiting for the reply (the link is reliable, so the single poll
  cannot be lost).
- Therefore there is **at most one outstanding credit**: the FPGA tracks it as a
  single bit, not a counter.
- If the FPGA has no data when a `POLL` arrives, it **holds** the credit and
  sends the chunk the instant the core produces data.
- A message larger than `BUFFER_SIZE` is sent as **one chunk per token round**;
  the FPGA decrements an internal byte counter and acknowledges the core only
  after the final chunk.

### Throughput ceiling (by design)

One buffer is in flight at a time (stop-and-wait), so sustained TX bandwidth is
bounded by `BUFFER_SIZE / token_round_period`. If the core produces faster, it
blocks on the held write-ack. This is the intended backpressure path.

---

## 4. Opcodes

| Opcode      | Value | Direction  | Meaning                                              |
|-------------|-------|------------|------------------------------------------------------|
| `OP_READY`  | 0x02  | FPGA → SDR | One-shot at boot: engine is up, you may begin polling |
| `OP_POLL`   | 0x01  | SDR → FPGA | TX buffer empty; one-buffer credit (`len = 0`)        |
| `OP_DATA`   | 0x10  | FPGA → SDR | One TX chunk, `len` ≤ `BUFFER_SIZE`                    |
| `OP_DATA`   | 0x10  | SDR → FPGA | RX sample chunk (hub broadcast), fire-and-forget      |
| `OP_REQ_SLOT` | 0x08 | SDR → Hub | TX buffer non-empty, request slot (unchanged)        |
| `OP_GRANT`  | 0x09  | Hub → SDR  | Slot granted, drain buffer (unchanged)               |
| `OP_DONE`   | 0x0A  | SDR → Hub  | Buffer drained, slot released (unchanged)            |

**Removed:** `OP_PAUSE` (0x20) and `OP_RESUME` (0x21). Pull flow control makes
push backpressure unnecessary.

**Direction change:** `OP_POLL` was FPGA→SDR (old boot probe) and is now
SDR→FPGA (credit). The old FPGA-initiated boot poll is replaced by the one-shot
`OP_READY` (see §7).

---

## 5. Wire format

Unchanged frame shape:

```
byte 0        : opcode
byte 1        : len           (payload length in bytes; 0 for control)
bytes 2..N+1  : payload        (N = len, LSB-first)
```

> **`len` width vs `BUFFER_SIZE`.** `len` is 8-bit, so it can only express
> `BUFFER_SIZE ≤ 255`. The old design's `TX_HIGH_WATER` was 384.
> **Decision: keep `BUFFER_SIZE ≤ 255` and the 1-byte `len`.** If a larger
> buffer is ever required, widen `len` to 16-bit in the serialiser, decoder,
> `pkg_sdr_ctrl_protocol.sv`, and `protocol.h` together.

---

## 6. Architecture

There is **one** SDR→FPGA wire carrying both `OP_POLL` (TX control) and
`OP_DATA` (RX samples). So the byte **decoder is shared**, and its output is
**demuxed by opcode**. TX and RX are otherwise independent engines.

```
                          req (DATA chunks + READY)         ┌────────────┐  TX wire
  core_sdr_if ─ TX ENGINE ─────────────────────────────────►│ serialiser │────►
   wr_*, wr_done   ▲  ▲                                       └────────────┘
                   │  └── poll_credit ──┐
                   │              ┌─────┴──────┐   ┌──────────┐  RX wire
   rd_* (fire- ◄───┘   DATA       │  opcode    │◄──│ decoder  │◄────
    and-forget) ◄──── RX ENGINE ◄─│  demux     │   └──────────┘
                                  └────────────┘
                                   POLL → TX engine
                                   DATA → RX engine
```

- **TX engine** — stateful: credit bit, byte counter, chunking, core write-ack.
  Owns the serialiser exclusively (TX chunks *and* the boot `OP_READY`).
- **RX engine** — thin forwarder: walks each `OP_DATA` payload to the core,
  fire-and-forget. Holds no protocol state.
- **Decoder** — shared; one instance on the RX wire.
- **Opcode demux** — routes decoded packets: `OP_POLL` → TX engine credit pulse,
  `OP_DATA` → RX engine. The credit pulse is the *only* coupling between the two
  engines.

Rationale for splitting (vs. today's single `S_ACTIVE` FSM): TX and RX have
independent lifecycles. Combining them re-creates the coupling this redesign
removes. The shared decoder is forced by the single physical wire, not a design
choice.

---

## 7. Boot / handshake

```
FPGA reset ──► resend OP_READY every READY_PERIOD until first OP_POLL ──► TX_WAIT
SDR start  ──► wait for OP_READY ──► (buffer empty) send OP_POLL ──► poll loop
```

`OP_READY` is the FPGA liveness signal: the SDR will not poll into an
uninitialised FPGA UART (which, lacking RX backpressure, would silently drop the
poll). It is **retransmitted every `READY_PERIOD` cycles until the first poll
arrives**, so boot tolerates either power-up order / a late-connecting SDR
(implemented in `sdr_ctrl_protocol_engine.sv`, state `TX_BOOT`). The first poll
both ends the boot loop and supplies the first one-buffer credit.

A one-shot `READY` is not enough on this sim's link: `UARTSIM` drops bytes
transmitted before the SDR's socket connects (uartsim.cpp), and the socket can
connect *between* the two bytes of a frame. The byte stream has no delimiter, so
a receiver that joins mid-frame can never realign on its own. Two mechanisms
together make boot robust:

1. **Periodic `READY`** (above) — guarantees a fresh, whole frame eventually
   reaches the connected SDR.
2. **SDR resync** — `recv_pkt` skips bytes until it reads a recognised opcode.
   During boot the FPGA emits only zero-payload `READY` frames, so this realigns
   within a byte or two; once aligned the (reliable) link stays aligned.

---

## 8. Core ↔ engine contract (model A: total-length up front)

### 8.1 TX channel (`core_sdr_if`)

```
core → engine:
    wr_valid                 // a message is presented
    wr_total_len [15:0]      // whole message size in bytes (may exceed BUFFER_SIZE)
    wr_data      [31:0]      // streamed payload words
engine → core:
    wr_ready                 // pulses per word, ONLY while a chunk is serialised
    wr_done                  // 1-cycle strobe when the whole message is out OTA
```

- The core holds `wr_total_len` stable for the duration of the message and
  streams `wr_data` words.
- `wr_ready` is asserted **only** while the engine is actively serialising a
  chunk (i.e. just after a `POLL`). Between chunks it is low — that low is the
  "hold the ack": the core cannot advance until the next poll pulls more bytes.
- `wr_done` strobes once when the final chunk has been serialised; the core may
  then present the next message.
- The engine needs **no deep staging FIFO**: because `wr_total_len` is known up
  front, the chunk `len` (`min(bytes_left, BUFFER_SIZE)`) is known before the
  payload is emitted. The only staging is the one `BUFFER_SIZE`-wide chunk
  assembly register (`chunk_buf`, == the serialiser's packet payload field) that
  the engine fills word-by-word in state `TX_COLLECT` before handing the whole
  chunk to the serialiser. This relies on the core keeping the engine fed during
  a chunk — trivially true for a picorv32-over-MMIO source versus a 115200-baud
  UART.
- Word/byte alignment: `wr_data` is 32-bit (4 bytes). If `wr_total_len` is not a
  multiple of 4, the final word is partial; carry the remainder count the same
  way `wr_len` does today.

### 8.2 RX channel (`core_sdr_if`)

```
engine → core:
    rd_valid                 // 1 cycle per emitted word
    rd_data  [31:0]
    rd_len   [LEN]           // valid bytes in this word (4, or remainder on last)
    rd_last                  // optional: marks the final word of a packet
core → engine:
    rd_ready                 // advisory only; RX never stalls on it
```

`rd_last` lets the receiving core group words into packets without any
reassembly metadata on the wire (chunks are independent OTA units — see §10).

---

## 9. TX engine FSM

```
BOOT        : send OP_READY once → IDLE

IDLE        : on OP_POLL (from demux)         : have_credit ← 1
              on new message latched          : bytes_left  ← wr_total_len
              if (have_credit && msg_pending) : → SEND_CHUNK

SEND_CHUNK  : chunk_len = min(bytes_left, BUFFER_SIZE)
              emit  OP_DATA | chunk_len | <chunk_len bytes pulled from core>
                    (wr_ready pulses word-by-word at serialiser/UART pace)
              bytes_left  -= chunk_len
              have_credit ← 0
              if bytes_left == 0 : strobe wr_done, drop message → IDLE
              else               :                              → IDLE  (await next POLL)
```

State is minimal: one `have_credit` bit, one `bytes_left` counter, one
`msg_pending`/`bytes_left` latch.

---

## 10. RX engine FSM

```
RX_IDLE : accept packet from decoder immediately   ← decoder NEVER stalls
          (only OP_DATA reaches here; demux drops/handles others)
          if packet has payload → RX_EMIT

RX_EMIT : walk payload in 4-byte words
          each word: rd_valid = 1 for one cycle
                     rd_len   = 4 (or remainder on the last word)
                     rd_last  = 1 on the final word
          advance regardless of rd_ready          ← fire-and-forget
          when all len bytes emitted → RX_IDLE
```

This single design choice fixes both latent bugs in the current code:

1. **No framer desync.** The RX engine always drains the decoder, so the decoder
   never parks in `S_FINISHED` waiting on a slow `rd_ready`. On a real UART a
   stall there backs up the RX FIFO and desyncs the framer permanently.
2. **No payload truncation.** It walks the full payload to the core instead of
   forwarding only the first 4 of up to `BUFFER_SIZE` bytes (the current
   `engine.sv` `rd_data = payload[31:0]` bug).

Because the core clock ≫ UART byte rate, the RX engine finishes dribbling a
packet's few words long before the next packet's bytes arrive, so dropping is
rare and, when it happens, is clean (whole-frame) — matching the lossy RX
assumption.

---

## 11. Worked example — 200-byte message, `BUFFER_SIZE = 64`

```
boot   FPGA → READY
       SDR (buffer empty) → POLL                       have_credit = 1
       core presents wr_total_len = 200                bytes_left  = 200

T1     credit + msg → DATA len=64  ──► SDR buf OCCUPIED  bytes_left=136, credit=0
       token: SDR drains 64 B OTA, DONE → POLL          have_credit = 1
T2                    DATA len=64                        bytes_left=72
       token → DONE → POLL
T3                    DATA len=64                        bytes_left=8
       token → DONE → POLL
T4                    DATA len=8    ◄── short final chunk, no padding
                                        bytes_left=0 → wr_done strobe ✓
```

The final `len=8` frame is the point of putting the size in the header: the
buffer-sized chunks and the short tail share one frame format, with no
fixed-length padding wasted on the wire. One chunk per token round; the core
sees a single `wr_done` after the fourth round.

---

## 12. SDR-side changes (`sdr_fsm.c` / `sdr_fsm.h`)

Collapse the multi-packet TX ring into a single binary buffer:

- **Remove:** `tx_queue[TX_QUEUE_DEPTH]`, head/tail/len, `tx_bytes_used`,
  `paused`, `TX_HIGH_WATER`, `TX_LOW_WATER`, and all `OP_PAUSE`/`OP_RESUME`
  handling.
- **States:** `PENDING` (await `OP_READY`) → `ACTIVE`.
- **On `OP_READY`** (from FPGA): enter `ACTIVE`; buffer is EMPTY → send `OP_POLL`.
- **On `OP_DATA`** (from FPGA): buffer becomes OCCUPIED; send `OP_REQ_SLOT` to
  the hub.
- **On `OP_GRANT`** (from hub): drain the one buffer to the hub, send `OP_DONE`,
  buffer EMPTY → send `OP_POLL` (pre-fill: poll right after draining so the
  buffer refills before the next token).
- **On hub broadcast `OP_DATA`:** forward straight to the FPGA (RX), unchanged.

---

## 13. Files touched (implementation checklist)

RTL (`fpga-connection/rtl/protocol/`):

- `pkg_sdr_ctrl_protocol.sv` — opcodes (`POLL` dir, drop `PAUSE`/`RESUME`),
  `BUFFER_SIZE`.
- `core_sdr_if.sv` — TX channel `wr_total_len` + `wr_done`; RX channel
  `rd_last`.
- `sdr_ctrl_protocol_engine.sv` — split into **TX engine** + **RX engine** +
  **opcode demux**; new FSMs (§9, §10).
- serialiser / decoder — unchanged frame shape; only touched if `len` is widened.

Software (`fpga-connection/sw/`):

- `protocol.h` — match opcode table; `MAX_PAYLOAD_BYTES` = `BUFFER_SIZE`.
- `sdr_fsm.c` / `sdr_fsm.h` — single binary buffer, poll loop (§12).
- `sdr_hub.c` — unchanged.

Sim core stub:

- `test_core.sv` — present `wr_total_len` and consume `wr_done`; exercise a
  message larger than `BUFFER_SIZE` to cover multi-round chunking.

---

## 14. Open items / future work

- **Lossy link.** If the reliable-link assumption is dropped, add a frame sync
  delimiter, a per-frame CRC, and a transfer/epoch ID so the stateful
  `bytes_left` counter survives a desync or SDR restart. Not needed under the
  current assumption. (The SDR's opcode-resync in §7 covers only the one-time
  mid-frame join at boot, not in-stream byte loss.)
- **`OP_READY` removal.** Could be dropped if power-up ordering (FPGA before SDR)
  is guaranteed on real hardware. Kept for now.
- **RX flow control.** Intentionally absent (lossy RX). Revisit only if dropped
  RX packets prove unacceptable at the application layer.
- **Real core integration.** `test_core.sv` is a stub; the model-A interface is
  designed to map onto the picorv32 `sdr_mmio` path (length register + streamed
  words / DMA).
