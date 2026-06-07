// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_core_sdr_if.h"
#include "Vtop_iter_if.h"
#include "Vtop_sdr_ctrl_protocol_if.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top__DOT__protocol_rx{this, Verilated::catName(namep, "top.protocol_rx")}
    , TOP__top__DOT__protocol_tx{this, Verilated::catName(namep, "top.protocol_tx")}
    , TOP__top__DOT__sdr_core_if{this, Verilated::catName(namep, "top.sdr_core_if")}
    , TOP__top__DOT__uart_rx_stream{this, Verilated::catName(namep, "top.uart_rx_stream")}
    , TOP__top__DOT__uart_tx_stream{this, Verilated::catName(namep, "top.uart_tx_stream")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top__DOT__protocol_rx = &TOP__top__DOT__protocol_rx;
    TOP.__PVT__top__DOT__protocol_tx = &TOP__top__DOT__protocol_tx;
    TOP.__PVT__top__DOT__sdr_core_if = &TOP__top__DOT__sdr_core_if;
    TOP.__PVT__top__DOT__uart_rx_stream = &TOP__top__DOT__uart_rx_stream;
    TOP.__PVT__top__DOT__uart_tx_stream = &TOP__top__DOT__uart_tx_stream;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top__DOT__protocol_rx.__Vconfigure(true);
    TOP__top__DOT__protocol_tx.__Vconfigure(false);
    TOP__top__DOT__sdr_core_if.__Vconfigure(true);
    TOP__top__DOT__uart_rx_stream.__Vconfigure(true);
    TOP__top__DOT__uart_tx_stream.__Vconfigure(false);
    // Setup scopes
    __Vscope_top__u_decoder.configure(this, name(), "top.u_decoder", "u_decoder", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__u_serialiser.configure(this, name(), "top.u_serialiser", "u_serialiser", -9, VerilatedScope::SCOPE_OTHER);
}
