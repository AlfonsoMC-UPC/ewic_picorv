// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_sdr_ctrl_protocol_if.h"

void Vtop_sdr_ctrl_protocol_if___ctor_var_reset(Vtop_sdr_ctrl_protocol_if* vlSelf);

Vtop_sdr_ctrl_protocol_if::Vtop_sdr_ctrl_protocol_if(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_sdr_ctrl_protocol_if___ctor_var_reset(this);
}

void Vtop_sdr_ctrl_protocol_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_sdr_ctrl_protocol_if::~Vtop_sdr_ctrl_protocol_if() {
}
