#!/usr/bin/env python3
"""
Analyze performance metrics from SDR simulator logs.
"""
import re
import sys
from pathlib import Path
from collections import defaultdict

def parse_sdr_logs(log_dir="logs"):
    """Parse sdr1.log and sdr2.log for message timing."""
    metrics = {}

    for sdr_num in [1, 2]:
        log_file = Path(log_dir) / f"sdr{sdr_num}.log"
        if not log_file.exists():
            print(f"Warning: {log_file} not found")
            continue

        messages = []
        with open(log_file) as f:
            for line in f:
                # Pattern: [SDR@port] [time] [direction] OPCODE len=X dst=Y (msg#N)
                match = re.search(r'\[(\d+\.\d+)ms\].*msg#(\d+)', line)
                if match:
                    time_ms = float(match.group(1))
                    msg_num = int(match.group(2))
                    messages.append((time_ms, msg_num, line.strip()))

        if messages:
            start_time = messages[0][0]
            end_time = messages[-1][0]
            total_time = end_time - start_time
            total_msgs = len(messages)
            msg_rate = total_msgs / (total_time / 1000.0) if total_time > 0 else 0

            metrics[f"SDR{sdr_num}"] = {
                "start_ms": start_time,
                "end_ms": end_time,
                "duration_ms": total_time,
                "message_count": total_msgs,
                "msg_rate": msg_rate,
                "first_msg": messages[0][2],
                "last_msg": messages[-1][2],
            }

    return metrics

def parse_hub_log(log_file="logs/hub.log"):
    """Parse hub.log for cycle information."""
    if not Path(log_file).exists():
        print(f"Warning: {log_file} not found")
        return {}

    grants = 0
    data_msgs = 0
    allreduce_cycles = 0

    with open(log_file) as f:
        for line in f:
            if "granted slot" in line:
                grants += 1
            elif "DATA" in line and "len=8" in line:
                data_msgs += 1
                # Track Phase 5 (broadcast): 3 broadcasts per cycle
                if "data=0x" in line:
                    # This is a data message, count for cycle estimation
                    pass

    return {
        "total_grants": grants,
        "total_data_messages": data_msgs,
        "estimated_cycles": data_msgs // 10 if data_msgs > 0 else 0,  # 10 msgs per cycle approx
    }

def main():
    print("=== SDR Simulator Performance Characterization ===\n")

    sdr_metrics = parse_sdr_logs()
    hub_metrics = parse_hub_log()

    # Print SDR metrics
    print("SDR Performance:")
    print("-" * 60)
    for sdr_name, metrics in sorted(sdr_metrics.items()):
        print(f"\n{sdr_name}:")
        print(f"  Duration:        {metrics['duration_ms']:.2f} ms")
        print(f"  Message count:   {metrics['message_count']}")
        print(f"  Message rate:    {metrics['msg_rate']:.2f} msg/sec")
        print(f"  First message:   {metrics['start_ms']:.2f} ms")
        print(f"  Last message:    {metrics['end_ms']:.2f} ms")

    # Print hub metrics
    print(f"\n\nHub Performance:")
    print("-" * 60)
    for key, value in sorted(hub_metrics.items()):
        print(f"  {key}: {value}")

    # Calculate AllReduce cycle time if we have both SDRs
    if len(sdr_metrics) >= 2:
        sdr1 = sdr_metrics.get("SDR1", {})
        sdr2 = sdr_metrics.get("SDR2", {})
        if sdr1 and sdr2:
            total_duration = max(sdr1.get("end_ms", 0), sdr2.get("end_ms", 0))
            total_msgs = sdr1.get("message_count", 0) + sdr2.get("message_count", 0)
            estimated_cycles = hub_metrics.get("estimated_cycles", 0)

            print(f"\n\nSystem Summary:")
            print("-" * 60)
            print(f"  Total runtime:   {total_duration:.2f} ms")
            print(f"  Total messages:  {total_msgs}")
            print(f"  Overall rate:    {(total_msgs / (total_duration / 1000.0)):.2f} msg/sec")
            if estimated_cycles > 0:
                print(f"  Est. cycles:     {estimated_cycles}")
                print(f"  Time per cycle:  {(total_duration / estimated_cycles):.2f} ms")

if __name__ == "__main__":
    main()
