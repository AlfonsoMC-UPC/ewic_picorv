#!/usr/bin/env python3
"""
Launch an N-FPGA-SDR cluster with real FPGA hardware (Alveo U280).

Starts one sdr_hub, N uart_bridge processes (one per FPGA serial port),
and N sdr_sim instances.  Each uart_bridge opens the FPGA's USB-UART port
and exposes it as a TCP server; each sdr_sim then connects to that server
using the same "sim" mode it uses against Verilator.

Prerequisites
-------------
Build tools if not already built:
  cd fpga-connection/sw && make          # builds sdr_hub, sdr_sim
  cd ewic-fpga/.../simulation/sw && make # builds uart_bridge  (if not present)

Then synthesize and program the FPGA with the updated ewic-fpga Vivado project.

Usage examples
--------------
    python run_fpga.py /dev/ttyUSB0                    # one FPGA
    python run_fpga.py /dev/ttyUSB0 /dev/ttyUSB1      # two FPGAs
    python run_fpga.py --baud 115200 /dev/ttyUSB0     # explicit baud rate
    python run_fpga.py --log-dir /tmp/run1 /dev/ttyUSB0
"""

import argparse
import pathlib
import signal
import subprocess
import sys
import time

BASE         = pathlib.Path(__file__).parent.resolve()
FPGA_CONN    = BASE / "fpga-connection"
EWIC_FPGA    = BASE / "ewic-fpga"

SDR_SIM      = FPGA_CONN / "sw" / "sdr_sim"
SDR_HUB      = FPGA_CONN / "sw" / "sdr_hub"
UART_BRIDGE  = (EWIC_FPGA / "uart_design.srcs" / "sources_1" / "new"
                / "simulation" / "sw" / "uart_bridge")


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
        "--build", action="store_true",
        help="Run make in fpga-connection/sw/ before launching",
    )
    return ap.parse_args()


def build():
    print("Building fpga-connection/sw/...")
    subprocess.run(["make", "-C", str(FPGA_CONN / "sw")], check=True)


def check_binaries(serial_ports):
    missing = [b for b in (SDR_SIM, SDR_HUB, UART_BRIDGE) if not b.exists()]
    if missing:
        sys.exit(
            "Missing binaries:\n"
            + "\n".join(f"  {b}" for b in missing)
            + "\nRun with --build or build manually."
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

    check_binaries(args.serial_ports)

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
        )
        procs.append((p, log_path))
        print(f"  pid={p.pid:<6}  {' '.join(str(c) for c in cmd)}")
        print(f"  {'':6}   -> {log_path}")

    def stop_all(sig=None, _frame=None):
        print("\nStopping all processes...", flush=True)
        for p, _ in procs:
            try:
                p.terminate()
            except OSError:
                pass
        time.sleep(0.5)
        for p, _ in procs:
            if p.poll() is None:
                p.kill()
        for f in logs:
            f.close()
        sys.exit(0)

    signal.signal(signal.SIGINT,  stop_all)
    signal.signal(signal.SIGTERM, stop_all)

    print(f"\n=== hub (port {args.hub_port}, {n} SDRs) ===")
    launch([SDR_HUB, args.hub_port, n], "hub.log")
    time.sleep(0.2)

    print(f"\n=== {n} UART bridge(s) ===")
    for i, dev in enumerate(args.serial_ports):
        port = args.bridge_base_port + i
        launch([UART_BRIDGE, port, dev, args.baud], f"bridge{i + 1}.log")
    # Give bridges time to open the serial ports before sdr_sim connects.
    time.sleep(1.0)

    print(f"\n=== {n} SDR simulator(s) ===")
    for i in range(n):
        port = args.bridge_base_port + i
        launch([SDR_SIM, "sim", port, args.hub_port], f"sdr{i + 1}.log")

    print(f"\nAll running. Logs in {args.log_dir.resolve()}/")
    print("Ctrl+C to stop.\n")

    # Monitor: report unexpected exits and stop everything if any process dies.
    while True:
        time.sleep(1)
        for p, log_path in list(procs):
            rc = p.poll()
            if rc is not None:
                print(f"  pid={p.pid} ({log_path.name}) exited with code {rc}",
                      flush=True)
                procs.remove((p, log_path))
        if not procs:
            print("All processes have exited.")
            for f in logs:
                f.close()
            sys.exit(0)


if __name__ == "__main__":
    main()
