// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_sdr_ctrl_protocol_if.h"

VL_ATTR_COLD void Vtop_sdr_ctrl_protocol_if___ctor_var_reset(Vtop_sdr_ctrl_protocol_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sdr_ctrl_protocol_if___ctor_var_reset\n"); );
    // Body
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->ready = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(528, vlSelf->data);
}
