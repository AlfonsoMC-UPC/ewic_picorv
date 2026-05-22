#!/usr/bin/env bash
# patch_bitstream.sh — rebuild firmware and patch it into the existing bitstream.
#
# Does NOT require re-synthesis or re-implementation.
# The routed checkpoint (top_routed.dcp) must exist from a previous full run.
#
# Usage:
#   ./patch_bitstream.sh

set -euo pipefail

VIVADO=/tools/Xilinx/Vivado/2023.2/bin/vivado
ROOT="$(cd "$(dirname "$0")" && pwd)"
DCP="$ROOT/ewic-fpga/uart_design.runs/impl_1/top_routed.dcp"
OUT="$ROOT/ewic-fpga/uart_design.runs/impl_1/top_patched.bit"

# ── Step 1: build and install firmware ───────────────────────────────────────
echo ">>> Building firmware..."
make -C "$ROOT/firmware" install
echo "    firmware.hex installed."

# ── Step 2: sanity check ─────────────────────────────────────────────────────
if [ ! -f "$DCP" ]; then
    echo "ERROR: routed checkpoint not found: $DCP"
    echo "Run synthesis + implementation in Vivado first."
    exit 1
fi

# ── Step 3: patch BRAM init and write bitstream ───────────────────────────────
echo ""
echo ">>> Patching BRAM and writing bitstream (this takes ~2 min)..."
"$VIVADO" -mode batch -source "$ROOT/patch_bram.tcl" \
    -log  "$ROOT/patch_bram.log" \
    -journal "$ROOT/patch_bram.jou" \
    2>&1 | grep -E "^>>>|Patching|words|Writing|Done|ERROR|WARNING" || true

# ── Done ──────────────────────────────────────────────────────────────────────
if [ -f "$OUT" ]; then
    echo ""
    echo ">>> Patched bitstream ready:"
    echo "    $OUT"
    echo ""
    echo "Program both FPGAs with this file in Vivado Hardware Manager."
else
    echo "ERROR: output bitstream was not created. Check patch_bram.log for details."
    exit 1
fi
