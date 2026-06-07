// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, ((IData)(vlSelf->top__DOT__u_serialiser__DOT__iter_fire) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__0)));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSelf->top__DOT__u_engine__DOT__rsp_is_data) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__0)));
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__0 
        = vlSelf->top__DOT__u_serialiser__DOT__iter_fire;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__0 
        = vlSelf->top__DOT__u_engine__DOT__rsp_is_data;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

extern const VlWide<17>/*543:0*/ Vtop__ConstPool__CONST_h3a65fc40_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data = 0;
    IData/*31:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data = 0;
    CData/*3:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb = 0;
    // Body
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill 
        = ((0x3f0U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill)) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill));
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid = 0U;
    vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n 
        = (1U & (~ (IData)(vlSelf->i_reset)));
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_arready 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_waddr_plus_one 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_waddr_plus_one 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)));
    vlSelf->top__DOT__u_engine__DOT__tx_left = ((IData)(vlSelf->top__DOT__u_engine__DOT__in_msg)
                                                 ? (IData)(vlSelf->top__DOT__u_engine__DOT__bytes_left)
                                                 : 0xc8U);
    vlSymsp->TOP__top__DOT__sdr_core_if.wr_data = (
                                                   (vlSelf->top__DOT__u_test_core__DOT__fpga_id 
                                                    << 0x18U) 
                                                   | (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2 
        = ((IData)(vlSelf->i_reset) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)) 
                 | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
    vlSelf->__VdfgTmp_h61863ee6__0 = ((2U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                             >> 2U)) 
                                      | (1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow))));
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_data = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2 
        = ((IData)(vlSelf->i_reset) | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break) 
                                       | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) 
           & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow)) 
              | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill 
        = ((0x3f0U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill)) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill));
    vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid = 
        ((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state)) 
         & (0x32U > (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx)));
    vlSelf->top__DOT__u_engine__DOT__rx_rem = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__u_engine__DOT__rx_len) 
                                                  - (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx)));
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup;
    vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout 
        = ((0xffff0000U & vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout) 
           | ((0xff00U & (((2U & (IData)(__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb))
                            ? (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data 
                               >> 8U) : (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data 
                                         >> 8U)) << 8U)) 
              | (0xffU & ((1U & (IData)(__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb))
                           ? __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data
                           : __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data))));
    vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout 
        = ((0xffffU & vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout) 
           | ((((8U & (IData)(__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb))
                 ? (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data 
                    >> 0x18U) : (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data 
                                 >> 0x18U)) << 0x18U) 
              | (0xff0000U & (((4U & (IData)(__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb))
                                ? (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data 
                                   >> 0x10U) : (__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data 
                                                >> 0x10U)) 
                              << 0x10U))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup 
        = vlSelf->__Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)) 
                 & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow))));
    vlSymsp->TOP__top__DOT__protocol_tx.data[0U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[0U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[1U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[1U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[2U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[2U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[3U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[3U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[4U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[4U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[5U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[5U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[6U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[6U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[7U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[7U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[8U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[8U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[9U] = 
        Vtop__ConstPool__CONST_h3a65fc40_0[9U];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xaU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xaU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xbU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xbU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xcU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xcU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xdU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xdU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xeU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xeU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0xfU] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0xfU];
    vlSymsp->TOP__top__DOT__protocol_tx.data[0x10U] 
        = Vtop__ConstPool__CONST_h3a65fc40_0[0x10U];
    vlSymsp->TOP__top__DOT__protocol_tx.valid = 0U;
    if ((0U == (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))) {
        vlSymsp->TOP__top__DOT__protocol_tx.data[0U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[1U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[1U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[2U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[2U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[3U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[3U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[4U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[4U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[5U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[5U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[6U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[6U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[7U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[7U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[8U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[8U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[9U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[9U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xaU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xaU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xbU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xbU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xcU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xcU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xdU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xdU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xeU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xeU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xfU] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0xfU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0x10U] 
            = Vtop__ConstPool__CONST_h3a65fc40_0[0x10U];
        vlSymsp->TOP__top__DOT__protocol_tx.valid = 
            (0U == (IData)(vlSelf->top__DOT__u_engine__DOT__ready_cnt));
    } else if ((3U == (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))) {
        vlSymsp->TOP__top__DOT__protocol_tx.data[0U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[1U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[1U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[2U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[2U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[3U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[3U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[4U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[4U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[5U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[5U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[6U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[6U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[7U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[7U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[8U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[8U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[9U] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[9U];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xaU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xaU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xbU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xbU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xcU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xcU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xdU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xdU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xeU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xeU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0xfU] 
            = vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xfU];
        vlSymsp->TOP__top__DOT__protocol_tx.data[0x10U] 
            = (0x100000U | (((IData)(vlSelf->top__DOT__u_engine__DOT__chunk_len) 
                             << 8U) | (IData)(vlSelf->top__DOT__u_engine__DOT__cur_dst)));
        vlSymsp->TOP__top__DOT__protocol_tx.valid = 1U;
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status 
        = (0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill) 
                       << 2U) | ((2U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                        >> 2U)) | (1U 
                                                   & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow))))));
    vlSelf->top__DOT__u_engine__DOT__tx_msg_active 
        = ((IData)(vlSelf->top__DOT__u_engine__DOT__in_msg) 
           | (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid));
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_len = 0U;
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_last = 0U;
    if (vlSelf->top__DOT__u_engine__DOT__rx_state) {
        vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid = 1U;
        vlSymsp->TOP__top__DOT__sdr_core_if.rd_data 
            = (((0U == (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx), 3U)))
                 ? 0U : (vlSelf->top__DOT__u_engine__DOT__rx_payload[
                         (((IData)(0x1fU) + (0x1ffU 
                                             & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx), 3U))) 
                          >> 5U)] << ((IData)(0x20U) 
                                      - (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx), 3U))))) 
               | (vlSelf->top__DOT__u_engine__DOT__rx_payload[
                  (0xfU & (VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx), 3U) 
                           >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx), 3U))));
        vlSymsp->TOP__top__DOT__sdr_core_if.rd_len 
            = ((4U <= (IData)(vlSelf->top__DOT__u_engine__DOT__rx_rem))
                ? 4U : (IData)(vlSelf->top__DOT__u_engine__DOT__rx_rem));
        vlSymsp->TOP__top__DOT__sdr_core_if.rd_last 
            = (4U >= (IData)(vlSelf->top__DOT__u_engine__DOT__rx_rem));
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write) 
           & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)) 
              | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6)));
}

extern const VlWide<17>/*543:0*/ Vtop__ConstPool__CONST_h902eb634_0;

VL_ATTR_COLD void Vtop___024root___stl_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_comb__TOP__0\n"); );
    // Body
    vlSymsp->TOP__top__DOT__protocol_rx.ready = 1U;
    if (vlSelf->top__DOT__u_engine__DOT__rsp_is_data) {
        vlSymsp->TOP__top__DOT__protocol_rx.ready = 
            (1U & (~ (IData)(vlSelf->top__DOT__u_engine__DOT__rx_state)));
    }
    vlSelf->top__DOT__u_decoder__DOT__state_n = vlSelf->top__DOT__u_decoder__DOT__state;
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[1U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[1U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[2U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[2U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[3U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[3U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[4U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[4U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[5U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[5U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[6U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[6U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[7U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[7U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[8U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[8U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[9U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[9U];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xaU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xaU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xbU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xbU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xcU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xcU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xdU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xdU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xeU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xeU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xfU] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xfU];
    vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U] 
        = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U];
    vlSelf->top__DOT__u_decoder__DOT__rem_n = vlSelf->top__DOT__u_decoder__DOT__rem;
    vlSelf->top__DOT__u_decoder__DOT__byte_idx_n = vlSelf->top__DOT__u_decoder__DOT__byte_idx;
    vlSymsp->TOP__top__DOT__uart_rx_stream.ready = 0U;
    vlSymsp->TOP__top__DOT__protocol_rx.valid = 0U;
    if ((4U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_decoder.sv:91: Assertion failed in %Ntop.u_decoder: Unreachable sdr_ctrl_protocol_decoder state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_decoder.sv", 91, "");
        } else if (VL_UNLIKELY((1U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_decoder.sv:91: Assertion failed in %Ntop.u_decoder: Unreachable sdr_ctrl_protocol_decoder state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_decoder.sv", 91, "");
        } else {
            vlSymsp->TOP__top__DOT__protocol_rx.valid = 1U;
            if (vlSymsp->TOP__top__DOT__protocol_rx.ready) {
                vlSelf->top__DOT__u_decoder__DOT__state_n = 0U;
            }
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state))) {
            if (vlSymsp->TOP__top__DOT__uart_rx_stream.valid) {
                vlSymsp->TOP__top__DOT__uart_rx_stream.ready = 1U;
                VL_ASSIGNSEL_WI(536,8,(0x1ffU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_decoder__DOT__byte_idx), 3U)), vlSelf->top__DOT__u_decoder__DOT__prot_buf_n, vlSymsp->TOP__top__DOT__uart_rx_stream.data);
                vlSelf->top__DOT__u_decoder__DOT__byte_idx_n 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_decoder__DOT__byte_idx)));
                vlSelf->top__DOT__u_decoder__DOT__rem_n 
                    = (0xffU & ((IData)(vlSelf->top__DOT__u_decoder__DOT__rem) 
                                - (IData)(1U)));
                if ((1U == (IData)(vlSelf->top__DOT__u_decoder__DOT__rem))) {
                    vlSelf->top__DOT__u_decoder__DOT__state_n = 4U;
                }
            }
        } else if (vlSymsp->TOP__top__DOT__uart_rx_stream.valid) {
            vlSymsp->TOP__top__DOT__uart_rx_stream.ready = 1U;
            vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U] 
                = ((0xffff00U & vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U]) 
                   | (0xffffffU & (IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.data)));
            vlSelf->top__DOT__u_decoder__DOT__state_n 
                = ((0U == (IData)(vlSelf->top__DOT__u_decoder__DOT__rem))
                    ? 4U : 3U);
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__u_decoder__DOT__state))) {
        if (vlSymsp->TOP__top__DOT__uart_rx_stream.valid) {
            vlSymsp->TOP__top__DOT__uart_rx_stream.ready = 1U;
            vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U] 
                = ((0xff00ffU & vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U]) 
                   | (0xffffffU & ((IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.data) 
                                   << 8U)));
            vlSelf->top__DOT__u_decoder__DOT__rem_n 
                = vlSymsp->TOP__top__DOT__uart_rx_stream.data;
            vlSelf->top__DOT__u_decoder__DOT__state_n = 2U;
        }
    } else if (vlSymsp->TOP__top__DOT__uart_rx_stream.valid) {
        vlSymsp->TOP__top__DOT__uart_rx_stream.ready = 1U;
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0U] 
            = Vtop__ConstPool__CONST_h902eb634_0[0U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[1U] 
            = Vtop__ConstPool__CONST_h902eb634_0[1U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[2U] 
            = Vtop__ConstPool__CONST_h902eb634_0[2U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[3U] 
            = Vtop__ConstPool__CONST_h902eb634_0[3U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[4U] 
            = Vtop__ConstPool__CONST_h902eb634_0[4U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[5U] 
            = Vtop__ConstPool__CONST_h902eb634_0[5U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[6U] 
            = Vtop__ConstPool__CONST_h902eb634_0[6U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[7U] 
            = Vtop__ConstPool__CONST_h902eb634_0[7U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[8U] 
            = Vtop__ConstPool__CONST_h902eb634_0[8U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[9U] 
            = Vtop__ConstPool__CONST_h902eb634_0[9U];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xaU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xaU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xbU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xbU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xcU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xcU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xdU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xdU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xeU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xeU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0xfU] 
            = Vtop__ConstPool__CONST_h902eb634_0[0xfU];
        vlSelf->top__DOT__u_decoder__DOT__prot_buf_n[0x10U] 
            = (((IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.data) 
                << 0x10U) | Vtop__ConstPool__CONST_h902eb634_0[0x10U]);
        vlSelf->top__DOT__u_decoder__DOT__byte_idx_n = 0U;
        vlSelf->top__DOT__u_decoder__DOT__state_n = 1U;
    }
    vlSelf->top__DOT__u_engine__DOT__rsp_is_ready = 
        ((IData)(vlSymsp->TOP__top__DOT__protocol_rx.valid) 
         & (0x20000U == (0xff0000U & vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U])));
    vlSelf->top__DOT__u_engine__DOT__rsp_is_data = 
        ((IData)(vlSymsp->TOP__top__DOT__protocol_rx.valid) 
         & (0x100000U == (0xff0000U & vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U])));
}
