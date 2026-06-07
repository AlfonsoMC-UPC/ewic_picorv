CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g

all: sdr_sim sdr_hub

SIM_OBJS = sdr_sim.o sdr_fsm.o
HUB_OBJS = sdr_hub.o

sdr_sim: $(SIM_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SIM_OBJS)

sdr_hub: $(HUB_OBJS)
	$(CC) $(CFLAGS) -o $@ $(HUB_OBJS)

sdr_sim.o: sdr_sim.c protocol.h sdr_fsm.h
sdr_fsm.o: sdr_fsm.c sdr_fsm.h protocol.h
sdr_hub.o: sdr_hub.c protocol.h

# Real-SDR path: transparent UART<->HackRF(USB) frame relay.
# Requires libusb-1.0:  sudo apt install libusb-1.0-0-dev
# Not built by `all` so the default build works without libusb installed.
hackrf_bridge: hackrf_bridge.c
	$(CC) $(CFLAGS) -O2 -o $@ $< $(shell pkg-config --cflags --libs libusb-1.0) -lpthread

clean:
	rm -f sdr_sim sdr_hub hackrf_bridge $(SIM_OBJS) $(HUB_OBJS)

.PHONY: all clean
