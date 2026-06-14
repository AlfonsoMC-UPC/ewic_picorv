#!/usr/bin/env python3
"""
Analyze performance metrics from SDR and wire simulator logs.

Works for both SDR-only and hybrid (SDR + wire) runs.
"""
import re
import sys
from pathlib import Path


# ── log parser ────────────────────────────────────────────────────────────────

def parse_log(path):
    """
    Parse a sdr_sim log file into a list of event dicts.

    Each dict has: time_ms, direction ('hub rx'/'fpga tx'/...), opcode,
    len, dst, msg_num (or None), val (second 32-bit word if len>=8, else None).
    """
    events = []
    path = Path(path)
    if not path.exists():
        return events

    cur = None
    with open(path) as f:
        for line in f:
            # Main timestamped event line
            m = re.search(
                r'\[(\d+\.\d+)ms\]\s+\[([^\]]+)\]\s+(\w+)\s+len=(\d+)\s+dst=(\d+)'
                r'(?:\s+\(msg#(\d+)\))?',
                line)
            if m:
                cur = {
                    'time_ms':   float(m.group(1)),
                    'direction': m.group(2),
                    'opcode':    m.group(3),
                    'len':       int(m.group(4)),
                    'dst':       int(m.group(5)),
                    'msg_num':   int(m.group(6)) if m.group(6) else None,
                    'val':       None,
                }
                events.append(cur)
                continue

            # Payload annotation line (immediately follows a DATA event)
            if cur and cur['opcode'] == 'DATA':
                m = re.search(r'val=(\d+)/', line)
                if m:
                    cur['val'] = int(m.group(1))

    return events


# ── per-channel stats ─────────────────────────────────────────────────────────

def channel_stats(events, name):
    stamped = [e for e in events if e['msg_num'] is not None]
    data    = [e for e in events if e['opcode'] == 'DATA']
    real    = [e for e in data   if e['dst'] != 255]   # real inter-FPGA
    logs    = [e for e in data   if e['dst'] == 255]   # diagnostic logs

    times = [e['time_ms'] for e in stamped]
    duration = (max(times) - min(times)) if len(times) >= 2 else 0.0

    return {
        'name':           name,
        'start_ms':       min(times) if times else 0.0,
        'end_ms':         max(times) if times else 0.0,
        'duration_ms':    duration,
        'total_msgs':     len(stamped),
        'data_real':      real,
        'data_log_count': len(logs),
    }


# ── wire end-to-end latency ───────────────────────────────────────────────────

def wire_latency(wire1_events, wire2_events):
    """
    Compute end-to-end wire latency by matching DATA packets across logs.

    wire2 [hub tx] → wire1 [hub rx]  : FPGA1→FPGA0 direction
    wire1 [hub tx] → wire2 [hub rx]  : FPGA0→FPGA1 direction

    Packets are matched by their payload value (val field).
    Returns a list of (direction_label, latency_ms) tuples.
    """
    results = []

    def match(send_events, recv_events, dst, label):
        sends = {e['val']: e['time_ms']
                 for e in send_events
                 if e['opcode'] == 'DATA' and e['direction'] == 'hub tx'
                 and e['dst'] == dst and e['val'] is not None}
        recvs = {e['val']: e['time_ms']
                 for e in recv_events
                 if e['opcode'] == 'DATA' and e['direction'] == 'hub rx'
                 and e['dst'] == dst and e['val'] is not None}
        for val, t_send in sends.items():
            if val in recvs:
                results.append((label, val, recvs[val] - t_send))

    match(wire2_events, wire1_events, dst=0, label='FPGA1→FPGA0')
    match(wire1_events, wire2_events, dst=1, label='FPGA0→FPGA1')
    return results


# ── SDR simulated latency ─────────────────────────────────────────────────────

def sdr_sim_latency(events):
    """
    Measure the simulated RF delay from GRANT→DATA in the SDR sim log.
    Returns list of latency_ms values (one per DATA sent to hub).
    """
    latencies = []
    last_grant = None
    for e in events:
        if e['opcode'] == 'GRANT' and e['direction'] == 'hub rx':
            last_grant = e['time_ms']
        elif (e['opcode'] == 'DATA' and e['direction'] == 'hub tx'
              and last_grant is not None):
            latencies.append(e['time_ms'] - last_grant)
            last_grant = None
    return latencies


# ── main ──────────────────────────────────────────────────────────────────────

def main():
    log_dir = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("logs")

    sdr1 = parse_log(log_dir / "sdr1.log")
    sdr2 = parse_log(log_dir / "sdr2.log")
    wire1 = parse_log(log_dir / "wire1.log")
    wire2 = parse_log(log_dir / "wire2.log")
    hybrid = bool(wire1 or wire2)

    print(f"=== Performance Analysis {'(hybrid: SDR + wire)' if hybrid else '(SDR only)'} ===\n")
    print(f"Log directory: {log_dir.resolve()}\n")

    # ── SDR channels ──────────────────────────────────────────────────────────
    print("SDR Channel")
    print("-" * 60)
    for events, name in [(sdr1, "SDR1 (FPGA0)"), (sdr2, "SDR2 (FPGA1)")]:
        if not events:
            continue
        s = channel_stats(events, name)
        real_vals = [e['val'] for e in s['data_real'] if e['val'] is not None]
        print(f"\n  {name}:")
        print(f"    Duration:          {s['duration_ms']:.1f} ms")
        print(f"    Real DATA packets: {len(s['data_real'])}"
              + (f"  (values: {real_vals})" if real_vals else ""))
        print(f"    Log  DATA packets: {s['data_log_count']}  (dst=255, dropped by hub)")

        rf_lats = sdr_sim_latency(events)
        if rf_lats:
            print(f"    Sim RF delay:      {rf_lats[0]:.1f} ms per hop"
                  f"  ({len(rf_lats)} samples, avg {sum(rf_lats)/len(rf_lats):.1f} ms)")

    # ── wire channels ─────────────────────────────────────────────────────────
    if hybrid:
        print(f"\n\nWire Channel")
        print("-" * 60)
        for events, name in [(wire1, "Wire1 (FPGA0 side)"), (wire2, "Wire2 (FPGA1 side)")]:
            if not events:
                continue
            s = channel_stats(events, name)
            real_vals = sorted({e['val'] for e in s['data_real'] if e['val'] is not None})
            print(f"\n  {name}:")
            print(f"    Duration:          {s['duration_ms']:.1f} ms")
            print(f"    Real DATA packets: {len(s['data_real'])}"
                  + (f"  (values: {real_vals})" if real_vals else ""))

        lats = wire_latency(wire1, wire2)
        if lats:
            print(f"\n  End-to-end wire latency (USB-UART overhead):")
            for direction, val, lat_ms in sorted(lats, key=lambda x: x[2]):
                print(f"    {direction:<16}  val={val:<8}  {lat_ms:.1f} ms")
            all_ms = [x[2] for x in lats]
            print(f"    Average: {sum(all_ms)/len(all_ms):.1f} ms  "
                  f"min={min(all_ms):.1f}  max={max(all_ms):.1f}")

    # ── system summary ────────────────────────────────────────────────────────
    print(f"\n\nSystem Summary")
    print("-" * 60)

    all_events = sdr1 + sdr2 + wire1 + wire2
    stamped = [e for e in all_events if e['msg_num'] is not None]
    if stamped:
        t_start = min(e['time_ms'] for e in stamped)
        t_end   = max(e['time_ms'] for e in stamped)
        print(f"  Wall-clock span:   {t_end - t_start:.1f} ms  ({t_start:.1f}–{t_end:.1f} ms)")

    # Bytes transferred per channel
    sdr_bytes  = sum(e['len'] for e in sdr1 + sdr2
                     if e['opcode'] == 'DATA' and e['dst'] != 255)
    wire_bytes = sum(e['len'] for e in wire1 + wire2
                     if e['opcode'] == 'DATA')
    print(f"  SDR payload bytes: {sdr_bytes}  (inter-FPGA only)")
    if hybrid:
        print(f"  Wire payload bytes:{wire_bytes}")
        total = sdr_bytes + wire_bytes
        if total:
            print(f"  Wire share:        {100*wire_bytes/total:.0f}%  "
                  f"SDR share: {100*sdr_bytes/total:.0f}%")

    # Simulated SDR RF delay vs wire overhead
    if hybrid:
        rf_lats = sdr_sim_latency(sdr1) + sdr_sim_latency(sdr2)
        wire_lats = [x[2] for x in wire_latency(wire1, wire2)]
        if rf_lats and wire_lats:
            print(f"\n  Latency comparison (one-way):")
            print(f"    Wire channel:  {sum(wire_lats)/len(wire_lats):.1f} ms  (USB-UART)")
            print(f"    SDR channel:   {sum(rf_lats)/len(rf_lats):.1f} ms  (simulated RF delay)")


if __name__ == "__main__":
    main()
