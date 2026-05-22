// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_core_sdr_if.h"

void Vtop_core_sdr_if___ctor_var_reset(Vtop_core_sdr_if* vlSelf);

Vtop_core_sdr_if::Vtop_core_sdr_if(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_core_sdr_if___ctor_var_reset(this);
}

void Vtop_core_sdr_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_core_sdr_if::~Vtop_core_sdr_if() {
}
