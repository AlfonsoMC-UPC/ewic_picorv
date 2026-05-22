# PicoRV32 startup: set stack, clear BSS, call main.
# Reset vector is address 0x00000000.

    .section .text.start
    .global  _start

_start:
    # Stack pointer
    la   sp, _stack_top

    # Clear BSS (required because BRAM init file only covers .text/.data)
    la   a0, __bss_start
    la   a1, __bss_end
    bge  a0, a1, 2f
1:
    sw   zero, 0(a0)
    addi a0, a0, 4
    blt  a0, a1, 1b
2:
    call main

_hang:
    j    _hang
