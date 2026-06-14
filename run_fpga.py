#!/usr/bin/env python3
"""
Launch an N-FPGA-SDR cluster with real FPGA hardware (Alveo U280).

Simulated-SDR mode (default)
-----------------------------
Starts one sdr_hub, N uart_bridge processes (one per FPGA serial port),
and N sdr_sim instances.  Each uart_bridge opens the FPGA's USB-UART port
and exposes it as a TCP server; each sdr_sim then connects to that server.

Real-SDR mode (--hackrf)
-------------------------
Starts N hackrf_bridge processes — one per FPGA+HackRF pair.  Each bridge
relays frames directly between the FPGA's UART and a real HackRF One over
USB bulk.  No hub or sdr_sim is needed; the HackRF firmware handles the
SDR FSM, MAC, and RF.  HackRF index i is paired with the i-th FPGA port.

Prerequisites
-------------
Sim mode:
  cd fpga-connection/sw && make          # builds sdr_hub, sdr_sim
  cd ewic-fpga/.../simulation/sw && make # builds uart_bridge

HackRF mode:
  sudo apt install libusb-1.0-0-dev
  cd fpga-connection/sw && make hackrf_bridge

Then synthesize and program the FPGA with the updated ewic-fpga Vivado project.

Usage examples
--------------
    python run_fpga.py /dev/ttyUSB0                         # one FPGA, sim SDR
    python run_fpga.py /dev/ttyUSB0 /dev/ttyUSB1           # two FPGAs, sim SDRs
    python run_fpga.py --hackrf /dev/ttyUSB0               # one FPGA, real HackRF #0
    python run_fpga.py --hackrf /dev/ttyUSB0 /dev/ttyUSB1 # two FPGAs, HackRF #0 and #1
    python run_fpga.py --baud 115200 /dev/ttyUSB0
    python run_fpga.py --log-dir /tmp/run1 /dev/ttyUSB0
"""

import argparse
import os
import pathlib
import signal
import subprocess
import sys
import time

BASE         = pathlib.Path(__file__).parent.resolve()
FPGA_CONN    = BASE / "fpga-connection"
EWIC_FPGA    = BASE / "ewic-fpga"

SDR_SIM       = FPGA_CONN / "sw" / "sdr_sim"
SDR_HUB       = FPGA_CONN / "sw" / "sdr_hub"
UART_BRIDGE   = (EWIC_FPGA / "uart_design.srcs" / "sources_1" / "new"
                 / "simulation" / "sw" / "uart_bridge")
HACKRF_BRIDGE = FPGA_CONN / "sw" / "hackrf_bridge"


def parse_args():
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "serial_ports", nargs="+", metavar="SERIAL_PORT",
        help="Serial device for each FPGA (e.g. /dev/ttyUSB0). "
             "Order determines FPGA index.",
    )
    ap.add_argument(
        "--baud", type=int, default=115200, metavar="BAUD",
        help="UART baud rate (default: 115200)",
    )
    ap.add_argument(
        "--hub-port", type=int, default=14000, metavar="PORT",
        help="Hub TCP port (default: 14000)",
    )
    ap.add_argument(
        "--bridge-base-port", type=int, default=12345, metavar="PORT",
        help="First uart_bridge TCP port; each FPGA gets base+i (default: 12345)",
    )
    ap.add_argument(
        "--log-dir", type=pathlib.Path, default=pathlib.Path("logs"), metavar="DIR",
        help="Directory for log files (default: logs/)",
    )
    ap.add_argument(
        "--hackrf", action="store_true",
        help="Real-SDR mode: use hackrf_bridge instead of uart_bridge+sdr_sim+sdr_hub. "
             "HackRF index i is paired with the i-th serial port.",
    )
    ap.add_argument(
        "--wire", action="store_true",
        help="Enable hybrid wire channel alongside SDR simulation (zero RF delay). "
             "Requires a bitstream compiled with WIRE=1 firmware.",
    )
    ap.add_argument(
        "--wire-hub-port", type=int, default=14001, metavar="PORT",
        help="Wire hub TCP port (default: 14001)",
    )
    ap.add_argument(
        "--build", action="store_true",
        help="Run make in fpga-connection/sw/ before launching",
    )
    return ap.parse_args()


def build():
    print("Building fpga-connection/sw/...")
    subprocess.run(["make", "-C", str(FPGA_CONN / "sw")], check=True)


def check_binaries(serial_ports, hackrf_mode, wire_mode=False):
    if hackrf_mode:
        required = [HACKRF_BRIDGE]
        hint = "Run:  cd fpga-connection/sw && make hackrf_bridge\n" \
               "(requires: sudo apt install libusb-1.0-0-dev)"
    else:
        required = [SDR_SIM, SDR_HUB, UART_BRIDGE]
        hint = "Run with --build or build manually."
    _ = wire_mode  # wire mode reuses SDR_SIM (with latency=0) and SDR_HUB

    missing = [b for b in required if not b.exists()]
    if missing:
        sys.exit(
            "Missing binaries:\n"
            + "\n".join(f"  {b}" for b in missing)
            + "\n" + hint
        )
    for dev in serial_ports:
        p = pathlib.Path(dev)
        if not p.exists():
            sys.exit(f"Serial device not found: {dev}")
        if not p.is_char_device():
            print(f"Warning: {dev} exists but is not a character device", flush=True)


def main():
    args = parse_args()
    n = len(args.serial_ports)

    if args.build:
        build()

    check_binaries(args.serial_ports, args.hackrf, getattr(args, 'wire', False))

    args.log_dir.mkdir(parents=True, exist_ok=True)

    procs = []
    logs  = []

    def launch(cmd, log_name):
        log_path = args.log_dir / log_name
        f = log_path.open("w")
        logs.append(f)
        p = subprocess.Popen(
            [str(c) for c in cmd],
            stdout=f,
            stderr=subprocess.STDOUT,
            # Own session/process group: terminal signals (Ctrl-C) reach only
            # this launcher, which then tears the children down explicitly. This
            # prevents a child (e.g. uart_bridge) from being orphaned and left
            # holding a serial port if shutdown is interrupted.
            start_new_session=True,
        )
        procs.append((p, log_path))
        print(f"  pid={p.pid:<6}  {' '.join(str(c) for c in cmd)}")
        print(f"  {'':6}   -> {log_path}")

    def stop_all():
        # Called from the main loop's finally clause (normal context), never
        # from inside a signal handler — so print()/buffered I/O is safe here.
        # Terminate each child's whole process group so nothing is left behind.
        print("\nStopping all processes...", flush=True)
        for p, _ in procs:
            try:
                os.killpg(os.getpgid(p.pid), signal.SIGTERM)
            except (OSError, ProcessLookupError):
                pass
        deadline = time.time() + 1.0
        for p, _ in procs:
            try:
                p.wait(timeout=max(0.0, deadline - time.time()))
            except (subprocess.TimeoutExpired, OSError):
                pass
        for p, _ in procs:
            if p.poll() is None:
                try:
                    os.killpg(os.getpgid(p.pid), signal.SIGKILL)
                except (OSError, ProcessLookupError):
                    pass
        for f in logs:
            try:
                f.close()
            except OSError:
                pass

    # Translate SIGTERM into a normal exception so all teardown happens in the
    # main loop's finally clause. Printing inside a signal handler can reenter
    # the stdout buffer lock and crash mid-cleanup (orphaning children).
    # SIGINT already raises KeyboardInterrupt by default.
    def _raise_interrupt(_sig, _frame):
        raise KeyboardInterrupt

    signal.signal(signal.SIGTERM, _raise_interrupt)

    if args.hackrf:
        print(f"\n=== {n} HackRF bridge(s) ===")
        for i, dev in enumerate(args.serial_ports):
            launch([HACKRF_BRIDGE, dev, i, args.baud], f"bridge{i + 1}.log")
    else:
        print(f"\n=== hub (port {args.hub_port}, {n} SDRs) ===")
        launch([SDR_HUB, args.hub_port, n], "hub.log")
        if args.wire:
            print(f"\n=== wire hub (port {args.wire_hub_port}, {n} SDRs) ===")
            launch([SDR_HUB, args.wire_hub_port, n], "wire_hub.log")
        time.sleep(0.2)

        # Wire bridge base port is offset by 100 from the SDR bridge base port.
        wire_bridge_base = args.bridge_base_port + 100

        print(f"\n=== {n} UART bridge(s) ===")
        for i, dev in enumerate(args.serial_ports):
            sdr_port = args.bridge_base_port + i
            if args.wire:
                wire_port = wire_bridge_base + i
                launch([UART_BRIDGE, sdr_port, wire_port, dev, args.baud],
                       f"bridge{i + 1}.log")
            else:
                launch([UART_BRIDGE, sdr_port, dev, args.baud], f"bridge{i + 1}.log")
        # Give bridges time to open the serial ports before sdr_sim connects.
        time.sleep(1.0)

        print(f"\n=== {n} SDR simulator(s) ===")
        for i in range(n):
            port = args.bridge_base_port + i
            launch([SDR_SIM, "sim", port, args.hub_port], f"sdr{i + 1}.log")

        if args.wire:
            print(f"\n=== {n} wire simulator(s) (latency=0) ===")
            for i in range(n):
                wire_port = wire_bridge_base + i
                launch([SDR_SIM, "sim", wire_port, args.wire_hub_port, 0],
                       f"wire{i + 1}.log")

    print(f"\nAll running. Logs in {args.log_dir.resolve()}/")
    print("Ctrl+C to stop.\n")

    # Monitor: report unexpected exits and stop everything if any process dies.
    # All teardown runs in the finally clause so it happens exactly once, in
    # normal (non-signal) context, whether we exit via Ctrl-C, SIGTERM, or a
    # child dying.
    try:
        while procs:
            time.sleep(1)
            for p, log_path in list(procs):
                rc = p.poll()
                if rc is not None:
                    print(f"  pid={p.pid} ({log_path.name}) exited with code {rc}",
                          flush=True)
                    procs.remove((p, log_path))
        print("All processes have exited.")
    except KeyboardInterrupt:
        pass
    finally:
        stop_all()


if __name__ == "__main__":
    main()
