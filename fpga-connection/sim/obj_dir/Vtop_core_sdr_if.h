// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CORE_SDR_IF_H_
#define VERILATED_VTOP_CORE_SDR_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_core_sdr_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ wr_valid;
    CData/*0:0*/ wr_ready;
    CData/*0:0*/ rd_valid;
    CData/*7:0*/ rd_len;
    IData/*31:0*/ wr_data;
    IData/*31:0*/ rd_data;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_core_sdr_if(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_core_sdr_if();
    VL_UNCOPYABLE(Vtop_core_sdr_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_core_sdr_if* obj);

#endif  // guard
