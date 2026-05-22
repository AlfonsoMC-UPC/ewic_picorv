#!/usr/bin/env python3
"""
Convert a raw binary (from objcopy -O binary) to a $readmemh-compatible
32-bit word hex file.  RISC-V is little-endian, so each group of 4 bytes
is read as a little-endian 32-bit integer.

Usage:  python3 mem_init.py firmware.bin firmware.hex
"""
import sys

with open(sys.argv[1], 'rb') as f:
    data = f.read()

# Pad to 4-byte boundary
pad = (-len(data)) % 4
data += b'\x00' * pad

with open(sys.argv[2], 'w') as f:
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i+4], 'little')
        f.write(f'{word:08x}\n')
