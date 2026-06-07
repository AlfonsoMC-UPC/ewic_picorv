// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_SDR_CTRL_PROTOCOL_IF_H_
#define VERILATED_VTOP_SDR_CTRL_PROTOCOL_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_sdr_ctrl_protocol_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ valid;
    CData/*0:0*/ ready;
    VlWide<17>/*535:0*/ data;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_sdr_ctrl_protocol_if(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_sdr_ctrl_protocol_if();
    VL_UNCOPYABLE(Vtop_sdr_ctrl_protocol_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_sdr_ctrl_protocol_if* obj);

#endif  // guard
