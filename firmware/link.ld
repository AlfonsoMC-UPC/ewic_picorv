OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY {
    bram (rwx) : ORIGIN = 0x00000000, LENGTH = 64K
}

SECTIONS {
    . = 0x00000000;

    .text : {
        *(.text.start)   /* startup must be first (reset vector at 0x0) */
        *(.text*)
        *(.rodata*)
    } > bram

    .data : {
        *(.data*)
    } > bram

    .bss : {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    } > bram

    _stack_top = ORIGIN(bram) + LENGTH(bram) - 4;
}
