// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_core_sdr_if.h"

VL_ATTR_COLD void Vtop_core_sdr_if___ctor_var_reset(Vtop_core_sdr_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_core_sdr_if___ctor_var_reset\n"); );
    // Body
    vlSelf->wr_valid = VL_RAND_RESET_I(1);
    vlSelf->wr_data = VL_RAND_RESET_I(32);
    vlSelf->wr_done = VL_RAND_RESET_I(1);
    vlSelf->rd_valid = VL_RAND_RESET_I(1);
    vlSelf->rd_data = VL_RAND_RESET_I(32);
    vlSelf->rd_len = VL_RAND_RESET_I(8);
    vlSelf->rd_last = VL_RAND_RESET_I(1);
}
