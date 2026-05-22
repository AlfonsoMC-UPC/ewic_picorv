# patch_bram.tcl — patch BRAM init data in the routed checkpoint and write a new bitstream.
#
# Run (from repo root, after running "make install" in firmware/):
#   vivado -mode batch -source patch_bram.tcl                          # uses impl_1 defaults
#   vivado -mode batch -source patch_bram.tcl -tclargs <dcp> <out.bit> # explicit paths
#
# BRAM cell naming convention (discovered by probing the routed DCP):
#   mem_reg_R_bram_B
#     R = byte lane  : 0→bits[7:0]  1→bits[15:8]  2→bits[23:16]  3→bits[31:24]
#     B = depth group: each RAMB36E2 holds 4096 words; B selects words [B*4096:(B+1)*4096-1]
#
# RAMB36E2 is configured in 9-bit mode (8 data + 1 parity).
# INIT_XX (XX = 00..7F): 128 × 256-bit values covering 32 addresses each (32 × 8 = 256 bits).
# String is MSB-first: rightmost 2 hex chars = byte at local address XX*32+0.

proc parse_hex {path} {
    set words {}
    set f [open $path r]
    while {[gets $f line] >= 0} {
        set line [string trim $line]
        if {$line ne ""} {
            lappend words [expr "0x$line"]
        }
    }
    close $f
    return $words
}

# Build a 64-char INIT_XX hex string for one RAMB36E2.
#   words      : full firmware word list
#   lane       : byte lane (0-3)
#   depth_group: depth block (0-3), covers global words [dg*4096 : dg*4096+4095]
#   init_idx   : INIT index (0-127), covers local addresses [ii*32 : ii*32+31]
proc build_init {words lane depth_group init_idx} {
    set s ""
    set base [expr {$depth_group * 4096 + $init_idx * 32}]
    for {set i 31} {$i >= 0} {incr i -1} {
        set gidx [expr {$base + $i}]
        if {$gidx < [llength $words]} {
            set byte [expr {([lindex $words $gidx] >> ($lane * 8)) & 0xFF}]
        } else {
            set byte 0
        }
        append s [format "%02x" $byte]
    }
    return $s
}

proc patch_bram_instance {inst words} {
    set zeros [string repeat "0" 64]
    for {set lane 0} {$lane < 4} {incr lane} {
        for {set dgrp 0} {$dgrp < 4} {incr dgrp} {
            set cname "${inst}/mem_reg_${lane}_bram_${dgrp}"
            set cell [get_cells $cname]
            if {[llength $cell] == 0} {
                puts "WARNING: cell not found: $cname"
                continue
            }
            puts "    $cname (bits [expr {$lane*8+7}]:[expr {$lane*8}]  words [expr {$dgrp*4096}]-[expr {$dgrp*4096+4095}])"
            for {set xx 0} {$xx < 128} {incr xx} {
                set_property [format "INIT_%02X" $xx] \
                              [build_init $words $lane $dgrp $xx] $cell
            }
            for {set p 0} {$p < 16} {incr p} {
                set_property [format "INITP_%02X" $p] $zeros $cell
            }
        }
    }
}

# ── paths ────────────────────────────────────────────────────────────────────
set root [file normalize [file dirname [info script]]]
set hex  [file join $root ewic-fpga uart_design.srcs sources_1 new rtl cpu firmware.hex]

if {[llength $argv] >= 2} {
    set dcp [file normalize [lindex $argv 0]]
    set out [file normalize [lindex $argv 1]]
} else {
    set dcp [file join $root ewic-fpga uart_design.runs impl_1 top_routed.dcp]
    set out [file join $root ewic-fpga uart_design.runs impl_1 top_patched.bit]
}

foreach f [list $dcp $hex] {
    if {![file exists $f]} { puts "ERROR: not found: $f" ; exit 1 }
}

# ── load ─────────────────────────────────────────────────────────────────────
puts "\nOpening checkpoint..."
open_checkpoint $dcp

set words [parse_hex $hex]
puts "Firmware: [llength $words] words ([expr {[llength $words]*4}] bytes)"

# ── patch ────────────────────────────────────────────────────────────────────
foreach inst {u_cpu_core/u_bram0 u_cpu_core/u_bram1 u_cpu_core/u_bram2 u_cpu_core/u_bram3} {
    puts "\nPatching $inst ..."
    patch_bram_instance $inst $words
}

# ── write ────────────────────────────────────────────────────────────────────
puts "\nWriting patched bitstream: $out"
write_bitstream -force $out

close_design
puts "\nDone. Program this FPGA with:\n  $out"
exit
