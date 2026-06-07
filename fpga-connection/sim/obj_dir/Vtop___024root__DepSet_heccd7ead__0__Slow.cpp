// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__0 
        = vlSelf->top__DOT__u_serialiser__DOT__iter_fire;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__0 
        = vlSelf->top__DOT__u_engine__DOT__rsp_is_data;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__1 
        = vlSelf->top__DOT__u_serialiser__DOT__iter_fire;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__1 
        = vlSelf->top__DOT__u_engine__DOT__rsp_is_data;
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = vlSelf->i_clk;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT____Vcellinp__u_serialiser__rst_n__0 
        = vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup = 0x364U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup = 0x364U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state = 0xeU;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill = 0xfU;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state = 0xfU;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup = 0x364U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data = 0xffU;
    vlSelf->o_uart_tx = 1U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter = 5U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state = 0U;
    vlSelf->top__DOT__u_test_core__DOT__fpga_id = 0U;
    __Vtemp_1[0U] = 0x643d2564U;
    __Vtemp_1[1U] = 0x67615f69U;
    __Vtemp_1[2U] = 0x6670U;
    (void)VL_VALUEPLUSARGS_INI(32, VL_CVT_PACK_STR_NW(3, __Vtemp_1), 
                               vlSelf->top__DOT__u_test_core__DOT__fpga_id);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../rtl/top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] top.u_serialiser.iter_fire)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] top.u_engine.rsp_is_data)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_comb__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___act_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] top.u_serialiser.iter_fire)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] top.u_engine.rsp_is_data)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge i_clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge i_clk or negedge top.__Vcellinp__u_serialiser__rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] top.u_serialiser.iter_fire)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] top.u_engine.rsp_is_data)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge i_clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge i_clk or negedge top.__Vcellinp__u_serialiser__rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->i_reset = VL_RAND_RESET_I(1);
    vlSelf->i_uart_rx = VL_RAND_RESET_I(1);
    vlSelf->o_uart_tx = VL_RAND_RESET_I(1);
    vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__u_uart_top__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup = VL_RAND_RESET_I(31);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0 = 0;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup = VL_RAND_RESET_I(30);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter = VL_RAND_RESET_I(24);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter = VL_RAND_RESET_I(28);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_waddr_plus_one = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_waddr_plus_one = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup = VL_RAND_RESET_I(31);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter = VL_RAND_RESET_I(28);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_serialiser__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__u_serialiser__DOT__state_n = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(536, vlSelf->top__DOT__u_serialiser__DOT__pkt);
    VL_RAND_RESET_W(536, vlSelf->top__DOT__u_serialiser__DOT__pkt_n);
    vlSelf->top__DOT__u_serialiser__DOT__byte_idx = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_serialiser__DOT__rem = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_serialiser__DOT__rem_n = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_serialiser__DOT__iter_fire = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_decoder__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__u_decoder__DOT__state_n = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(536, vlSelf->top__DOT__u_decoder__DOT__prot_buf);
    VL_RAND_RESET_W(536, vlSelf->top__DOT__u_decoder__DOT__prot_buf_n);
    vlSelf->top__DOT__u_decoder__DOT__rem = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_decoder__DOT__rem_n = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_decoder__DOT__byte_idx = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_decoder__DOT__byte_idx_n = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_engine__DOT__rsp_is_ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__rsp_is_data = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__tx_state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__u_engine__DOT__have_credit = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__in_msg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__bytes_left = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__u_engine__DOT__chunk_len = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_engine__DOT__byte_idx = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(512, vlSelf->top__DOT__u_engine__DOT__chunk_buf);
    vlSelf->top__DOT__u_engine__DOT__cur_dst = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_engine__DOT__ready_cnt = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__u_engine__DOT__req_fire = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__tx_msg_active = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__u_engine__DOT__tx_left = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__u_engine__DOT__rx_state = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, vlSelf->top__DOT__u_engine__DOT__rx_payload);
    vlSelf->top__DOT__u_engine__DOT__rx_len = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_engine__DOT__rx_idx = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_engine__DOT__rx_rem = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__u_test_core__DOT__fpga_id = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__u_test_core__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__u_test_core__DOT__settle_cnt = VL_RAND_RESET_I(17);
    vlSelf->top__DOT__u_test_core__DOT__gap_cnt = VL_RAND_RESET_I(20);
    vlSelf->top__DOT__u_test_core__DOT__word_idx = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__u_test_core__DOT__msg_num = VL_RAND_RESET_I(32);
    vlSelf->__VdfgTmp_h61863ee6__0 = 0;
    vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__0 = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT____Vcellinp__u_serialiser__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
