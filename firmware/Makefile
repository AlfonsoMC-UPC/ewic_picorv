PREFIX  = riscv64-unknown-elf-
CC      = $(PREFIX)gcc
OBJCOPY = $(PREFIX)objcopy

ARCH    = -march=rv32i -mabi=ilp32
CFLAGS  = $(ARCH) -O2 -nostdlib -ffreestanding -Wall -Wextra
LDFLAGS = $(ARCH) -T link.ld -nostdlib

.PHONY: all clean

all: firmware.hex

firmware.elf: startup.S firmware.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

firmware.bin: firmware.elf
	$(OBJCOPY) -O binary $< $@

# Convert to 32-bit word hex for $readmemh
firmware.hex: firmware.bin
	python3 mem_init.py $< $@

RTL_CPU = ../ewic-fpga/uart_design.srcs/sources_1/new/rtl/cpu

# Copy the hex file where bram_mem.sv can find it at synthesis time
install: firmware.hex
	cp firmware.hex $(RTL_CPU)/firmware.hex

clean:
	rm -f firmware.elf firmware.bin firmware.hex
