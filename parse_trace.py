#!/usr/bin/env python3
"""
parse_trace.py — extract FPGA 0 execution trace from hub.log.

Usage: python3 parse_trace.py [hub.log]

Log message format (SDR DATA words captured by hub):
  word 0 (header): MSG_HDR(ADDR(0xFF, type), src_addr)
                   = ((0xFF00 | type) << 16) | src_addr
  word 1 (data):   value

Log types:
  0x01-0x03  partial sum from Core 1/2/3
  0x10       local total  (FPGA 0 sum of all 3 partials)
  0x11       remote total (received from FPGA 1)
  0x12       global sum   (local + remote)

Expected values per iteration:
  Core 1 partial : 15   (1+2+3+4+5)
  Core 2 partial : 40   (6+7+8+9+10)
  Core 3 partial : 81   (11+12+13+14+15+16)
  Local total    : 136
  Remote total   : 136
  Global sum     : 272
"""

import sys
import re


def parse(path):
    # Match DATA log lines; capture the hex data word
    data_re = re.compile(r'\[HUB\].*DATA.*data=(0x[0-9a-fA-F]+)', re.IGNORECASE)

    with open(path) as f:
        lines = f.readlines()

    words = []
    for line in lines:
        m = data_re.search(line)
        if m:
            words.append(int(m.group(1), 16))

    iteration = 0
    partials = {}
    i = 0
    while i < len(words) - 1:
        hdr = words[i]
        val = words[i + 1]
        i += 2

        # Filter: top byte of dst must be 0xFF
        if (hdr >> 24) != 0xFF:
            continue

        log_type = (hdr >> 16) & 0xFF

        if 0x01 <= log_type <= 0x03:
            partials[log_type] = val

        elif log_type == 0x10:
            iteration += 1
            print(f"\n=== Iteration {iteration} ===")
            for core in sorted(partials):
                expected = {1: 15, 2: 40, 3: 81}.get(core, '?')
                flag = '' if partials[core] == expected else f'  *** expected {expected}'
                print(f"  Core {core} partial : {partials[core]}{flag}")
            partials = {}
            expected_local = 136
            flag = '' if val == expected_local else f'  *** expected {expected_local}'
            print(f"  Local total       : {val}{flag}")

        elif log_type == 0x11:
            expected_remote = 136
            flag = '' if val == expected_remote else f'  *** expected {expected_remote}'
            print(f"  Remote total      : {val}{flag}")

        elif log_type == 0x12:
            expected_global = 272
            flag = '' if val == expected_global else f'  *** expected {expected_global}'
            print(f"  Global sum        : {val}{flag}")

    print(f"\nTotal iterations parsed: {iteration}")


if __name__ == '__main__':
    log_path = sys.argv[1] if len(sys.argv) > 1 else 'hub.log'
    parse(log_path)
