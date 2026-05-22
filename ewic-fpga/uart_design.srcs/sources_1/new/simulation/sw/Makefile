CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: sdr_sim uart_bridge

sdr_sim: sdr_sim.c protocol.h
	$(CC) $(CFLAGS) -o $@ sdr_sim.c

uart_bridge: uart_bridge.c
	$(CC) $(CFLAGS) -o $@ uart_bridge.c

clean:
	rm -f sdr_sim uart_bridge

.PHONY: all clean