// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_sdr_ctrl_protocol_if.h"

std::string VL_TO_STRING(const Vtop_sdr_ctrl_protocol_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sdr_ctrl_protocol_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
