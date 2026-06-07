// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->top__DOT__u_serialiser__DOT__iter_fire) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__1)));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->top__DOT__u_engine__DOT__rsp_is_data) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__1)));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->i_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i_clk__0))));
    vlSelf->__VactTriggered.set(3U, (((IData)(vlSelf->i_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i_clk__0))) 
                                     | ((~ (IData)(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__top__DOT____Vcellinp__u_serialiser__rst_n__0))));
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__1 
        = vlSelf->top__DOT__u_serialiser__DOT__iter_fire;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__1 
        = vlSelf->top__DOT__u_engine__DOT__rsp_is_data;
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = vlSelf->i_clk;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT____Vcellinp__u_serialiser__rst_n__0 
        = vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlWide<17>/*543:0*/ Vtop__ConstPool__CONST_h902eb634_0;

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
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
    vlSelf->top__DOT__u_engine__DOT__rsp_is_data = 
        ((IData)(vlSymsp->TOP__top__DOT__protocol_rx.valid) 
         & (0x100000U == (0xff0000U & vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U])));
    vlSelf->top__DOT__u_engine__DOT__rsp_is_ready = 
        ((IData)(vlSymsp->TOP__top__DOT__protocol_rx.valid) 
         & (0x20000U == (0xff0000U & vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U])));
}

VL_INLINE_OPT void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__u_serialiser__DOT__state_n = vlSelf->top__DOT__u_serialiser__DOT__state;
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[1U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[1U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[2U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[2U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[3U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[3U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[4U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[4U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[5U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[5U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[6U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[6U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[7U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[7U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[8U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[8U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[9U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[9U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xaU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xaU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xbU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xbU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xcU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xcU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xdU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xdU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xeU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xeU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xfU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xfU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0x10U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U];
    vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n 
        = vlSelf->top__DOT__u_serialiser__DOT__byte_idx;
    vlSelf->top__DOT__u_serialiser__DOT__rem_n = vlSelf->top__DOT__u_serialiser__DOT__rem;
    vlSymsp->TOP__top__DOT__protocol_tx.ready = 0U;
    vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 0U;
    vlSymsp->TOP__top__DOT__uart_tx_stream.data = 0U;
    if ((4U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_serialiser.sv:96: Assertion failed in %Ntop.u_serialiser: Unreachable sdr_ctrl_protocol_serialiser state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_serialiser.sv", 96, "");
        } else if (VL_UNLIKELY((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_serialiser.sv:96: Assertion failed in %Ntop.u_serialiser: Unreachable sdr_ctrl_protocol_serialiser state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_serialiser.sv", 96, "");
        } else {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U)))
                              ? 0U : (vlSelf->top__DOT__u_serialiser__DOT__pkt[
                                      (((IData)(7U) 
                                        + (0x1ffU & 
                                           VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U))) 
                                       >> 5U)] << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U))))) 
                            | (vlSelf->top__DOT__u_serialiser__DOT__pkt[
                               (0xfU & (VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U) 
                                        >> 5U))] >> 
                               (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U)))));
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx)));
                vlSelf->top__DOT__u_serialiser__DOT__rem_n 
                    = (0xffU & ((IData)(vlSelf->top__DOT__u_serialiser__DOT__rem) 
                                - (IData)(1U)));
                if ((1U == (IData)(vlSelf->top__DOT__u_serialiser__DOT__rem))) {
                    vlSelf->top__DOT__u_serialiser__DOT__state_n = 0U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U]);
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__state_n 
                    = ((0U == (IData)(vlSelf->top__DOT__u_serialiser__DOT__rem))
                        ? 0U : 4U);
            }
        } else {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                            >> 8U));
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n = 0U;
                vlSelf->top__DOT__u_serialiser__DOT__rem_n 
                    = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                                >> 8U));
                vlSelf->top__DOT__u_serialiser__DOT__state_n = 3U;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
        vlSymsp->TOP__top__DOT__uart_tx_stream.data 
            = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                        >> 0x10U));
        if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
            vlSelf->top__DOT__u_serialiser__DOT__state_n = 2U;
        }
    } else if (vlSymsp->TOP__top__DOT__protocol_tx.valid) {
        vlSymsp->TOP__top__DOT__protocol_tx.ready = 1U;
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[1U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[1U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[2U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[2U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[3U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[3U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[4U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[4U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[5U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[5U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[6U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[6U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[7U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[7U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[8U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[8U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[9U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[9U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xaU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xaU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xbU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xbU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xcU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xcU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xdU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xdU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xeU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xeU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xfU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xfU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0x10U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0x10U];
        vlSelf->top__DOT__u_serialiser__DOT__state_n = 1U;
    }
    vlSelf->top__DOT__u_engine__DOT__req_fire = ((IData)(vlSymsp->TOP__top__DOT__protocol_tx.valid) 
                                                 & (IData)(vlSymsp->TOP__top__DOT__protocol_tx.ready));
    vlSelf->top__DOT__u_serialiser__DOT__iter_fire 
        = ((IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.valid) 
           & (IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__prior_data = 0;
    IData/*31:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__new_data = 0;
    CData/*3:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb;
    __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__wstrb = 0;
    CData/*1:0*/ __Vdly__top__DOT__u_uart_top__DOT__tx_state;
    __Vdly__top__DOT__u_uart_top__DOT__tx_state = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready = 0;
    CData/*2:0*/ __Vdly__top__DOT__u_uart_top__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__state = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready = 0;
    CData/*4:0*/ __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count;
    __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count = 0;
    IData/*31:0*/ __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum;
    __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum = 0;
    CData/*4:0*/ __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx;
    __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = 0;
    IData/*27:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr = 0;
    IData/*23:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0;
    __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0;
    __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0;
    __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0;
    __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0;
    __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0;
    __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill = 0;
    CData/*3:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity = 0;
    IData/*27:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter = 0;
    CData/*0:0*/ __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 0;
    CData/*0:0*/ TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready;
    TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready = 0;
    CData/*0:0*/ TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid;
    TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid = 0;
    // Body
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready;
    __Vdly__top__DOT__u_uart_top__DOT__tx_state = vlSelf->top__DOT__u_uart_top__DOT__tx_state;
    TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready 
        = vlSymsp->TOP__top__DOT__uart_tx_stream.ready;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr;
    __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready;
    __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr;
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr;
    __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx 
        = vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx;
    __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum 
        = vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum;
    __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count 
        = vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr;
    __Vdly__top__DOT__u_uart_top__DOT__state = vlSelf->top__DOT__u_uart_top__DOT__state;
    __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid 
        = vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid;
    TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid 
        = vlSymsp->TOP__top__DOT__uart_rx_stream.valid;
    if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
         & (8U != (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)))) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg 
            = (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart) 
                << 7U) | (0x7fU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg) 
                                   >> 1U)));
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write) {
        __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data;
        __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 = 1U;
        __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr;
    }
    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready 
        = ((IData)(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n) 
           & (((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready)) 
               & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid) 
                  & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid))) 
              & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid)) 
                 | (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready))));
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write) {
        __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data;
        __Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 = 1U;
        __Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr;
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy) {
        if ((0x2000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
                = (1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                         >> 0x18U));
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter) {
            if ((8U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))) {
                if ((0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))) {
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
                        = (1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                 >> 0x18U));
                }
            } else {
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
                    = (1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity) 
                             ^ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data)));
            }
        } else if ((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
                = (1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                         >> 0x18U));
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data 
                = (0x7fU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data) 
                            >> 1U));
        }
    } else {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
            = (1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                     >> 0x18U));
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data 
            = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc)
                ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write)
                : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data));
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
            = (0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                             << 4U));
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state = 0xeU;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 1U;
    } else {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter 
            = (1U == vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter);
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter) {
            if ((0xeU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))) {
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter = 0U;
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 1U;
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state = 0xfU;
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy 
                    = (1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts)));
            } else if ((0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))) {
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter = 0U;
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 1U;
                if ((1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)) 
                           & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy))))) {
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
                        = (0xfffffffU & ((0xffffffU 
                                          & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup) 
                                         - (IData)(1U)));
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter = 0U;
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 1U;
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state 
                        = ((0x20000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup)
                            ? ((0x10000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup)
                                ? 3U : 2U) : ((0x10000000U 
                                               & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup)
                                               ? 1U
                                               : 0U));
                } else {
                    __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy 
                        = (1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts)));
                }
            } else {
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
                    = (0xfffffffU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state)
                                      ? ((0xffffffU 
                                          & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup) 
                                         - (IData)(2U))
                                      : ((0xffffffU 
                                          & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup) 
                                         - (IData)(1U))));
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state 
                    = (0xfU & ((8U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))
                                ? ((8U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))
                                    ? 9U : ((9U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))
                                             ? ((0x8000000U 
                                                 & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)
                                                 ? 0xaU
                                                 : 0xfU)
                                             : 0xfU))
                                : ((7U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))
                                    ? ((0x4000000U 
                                        & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)
                                        ? 8U : 9U) : 
                                   ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state)))));
                __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 1U;
            }
        } else {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
                = (0xfffffffU & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
                                 - (IData)(1U)));
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy = 1U;
        }
    }
    if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset) 
         | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break))) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr = 0U;
    } else if ((((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
                 & (8U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
                & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb) 
                   >> 1U))) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr 
            = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr) 
               & (~ (vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                     >> 0xaU)));
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr 
            = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr) 
               & (~ (vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                     >> 9U)));
    } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr 
            = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr) 
               | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr));
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr 
            = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr) 
               | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr));
    }
    vlSelf->top__DOT__u_decoder__DOT__byte_idx = vlSelf->top__DOT__u_decoder__DOT__byte_idx_n;
    vlSelf->top__DOT__u_decoder__DOT__rem = vlSelf->top__DOT__u_decoder__DOT__rem_n;
    vlSelf->top__DOT__u_decoder__DOT__state = vlSelf->top__DOT__u_decoder__DOT__state_n;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n 
        = ((~ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
               >> 0x1eU)) & (0xdU < (0xfU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status) 
                                             >> 2U))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset 
        = (1U & (((~ (IData)(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n)) 
                  | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
                     & (0U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr))))) 
                 | ((((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
                      & (0xcU == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
                     & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb) 
                        >> 1U)) & (vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                                   >> 0xcU))));
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill = 0xfU;
    } else if ((1U == (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write) 
                        << 1U) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read)))) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill 
            = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill)));
    } else if ((2U == (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write) 
                        << 1U) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read)))) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill 
            = (0xfU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                       - (IData)(1U)));
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill;
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill 
            = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow = 0U;
    } else {
        if ((1U == (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write) 
                     << 1U) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill 
                = (0xfU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                           - (IData)(1U)));
        } else if ((2U == (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write) 
                            << 1U) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill)));
        }
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill 
            = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill;
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow) 
                   & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb));
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow) 
                   | ((0xfU & ((IData)(2U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr))) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr)));
        } else if (((0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr))) 
                    == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow = 1U;
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr;
    if (vlSelf->i_reset) {
        __Vdly__top__DOT__u_uart_top__DOT__state = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready = 0U;
        TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid = 0U;
        vlSymsp->TOP__top__DOT__uart_rx_stream.data = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx = 0U;
    } else if ((4U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__state))) {
        __Vdly__top__DOT__u_uart_top__DOT__state = 0U;
    } else if ((2U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__state))) {
            if ((1U & ((~ (IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.valid)) 
                       | (IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.ready)))) {
                vlSymsp->TOP__top__DOT__uart_rx_stream.data 
                    = (0xffU & (vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum 
                                >> (0x1fU & VL_SHIFTL_III(5,32,32, (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx), 3U))));
                TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid = 1U;
                if ((((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx)) 
                     < (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count))) {
                    __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx)));
                } else {
                    __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count = 0U;
                    __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum = 0U;
                    __Vdly__top__DOT__u_uart_top__DOT__state = 0U;
                }
            }
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid) {
            __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready = 0U;
            if ((0x100U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data)) {
                __Vdly__top__DOT__u_uart_top__DOT__state = 0U;
            } else {
                __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum 
                    = (((~ ((IData)(0xffU) << (0x1fU 
                                               & VL_SHIFTL_III(5,32,32, (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count), 3U)))) 
                        & __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum) 
                       | (0xffffffffULL & ((0xffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data) 
                                           << (0x1fU 
                                               & VL_SHIFTL_III(5,32,32, (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count), 3U)))));
                __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count)));
                if ((((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count)) 
                     >= (IData)(vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed))) {
                    __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx = 0U;
                    __Vdly__top__DOT__u_uart_top__DOT__state = 3U;
                } else {
                    __Vdly__top__DOT__u_uart_top__DOT__state = 0U;
                }
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__state))) {
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready) {
            __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid = 0U;
            __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready = 1U;
            __Vdly__top__DOT__u_uart_top__DOT__state = 2U;
        }
    } else {
        if (((IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.valid) 
             & (IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.ready))) {
            TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid = 0U;
        }
        if ((1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)) 
                   & (~ (IData)(vlSymsp->TOP__top__DOT__uart_rx_stream.valid))))) {
            __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid = 1U;
            __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr = 8U;
            __Vdly__top__DOT__u_uart_top__DOT__state = 1U;
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__state = __Vdly__top__DOT__u_uart_top__DOT__state;
    vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count 
        = __Vdly__top__DOT__u_uart_top__DOT__rx_byte_count;
    vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum 
        = __Vdly__top__DOT__u_uart_top__DOT__rx_data_accum;
    vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx 
        = __Vdly__top__DOT__u_uart_top__DOT__rx_output_idx;
    vlSymsp->TOP__top__DOT__uart_rx_stream.valid = TOP__top__DOT__uart_rx_stream__DOT____Vdly__valid;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill 
        = ((0x3f0U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill)) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill));
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo
            [vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next];
    }
    if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write) 
         & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow) 
            | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read) 
               & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next) 
                  == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data;
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow = 1U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next = 1U;
    } else {
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow) 
                   & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write));
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow) 
                   | ((0xfU & ((IData)(2U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr))) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr)));
        } else if (((0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr))) 
                    == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow = 1U;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow = 0U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow) 
                   | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)));
        }
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write) 
             & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow) 
                | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read) 
                   & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc = 1U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc = 0U;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr 
                = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_waddr_plus_one;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr)));
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next 
                = (0xfU & ((IData)(2U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr)));
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state 
        = ((0x8000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)
            ? (0xaU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state))
            : (9U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n)) 
                 | (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                    >> 0x1eU)));
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter = 0x363U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state = 0xeU;
    } else {
        if ((0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity = 0U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity) 
                   ^ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart));
        }
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
             & ((9U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)) 
                | (0xaU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr 
                = (1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr) 
                         | (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart))));
        } else if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
                    | (0xdU <= (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr = 0U;
        }
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter 
            = (0xffffffU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter)
                             ? (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                - (IData)(1U)) : ((0xeU 
                                                   == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                                   ? 
                                                  (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                   - (IData)(1U))
                                                   : 
                                                  ((0xdU 
                                                    == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                                    ? 
                                                   (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                    - (IData)(1U))
                                                    : 
                                                   ((0xfU 
                                                     == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                                     ? 
                                                    (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                     - (IData)(1U))
                                                     : 
                                                    (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter 
                                                     - (IData)(1U)))))));
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart) 
             != (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter = 0U;
        } else if ((vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
                    < (0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                     << 4U)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
                = (0xfffffffU & ((IData)(1U) + vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter));
        }
        if ((0xeU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch)
                    ? 0xfU : 0xeU);
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state = 0xdU;
        } else if ((0xdU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)
                    ? 0xfU : 0xdU);
        } else if ((0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
                = (((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)) 
                    & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time))
                    ? ((0x20000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                        ? ((0x10000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                            ? 3U : 2U) : ((0x10000000U 
                                           & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                                           ? 1U : 0U))
                    : 0xfU);
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
                = (0xfU & ((7U > (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                            ? ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                            : ((7U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                ? ((0x4000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                                    ? 8U : 9U) : ((8U 
                                                   == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                                   ? 9U
                                                   : 
                                                  ((9U 
                                                    == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)
                                                     ? 
                                                    ((0x8000000U 
                                                      & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                                                      ? 0xaU
                                                      : 0xfU)
                                                     : 0xeU)
                                                    : 
                                                   ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)
                                                     ? 0xfU
                                                     : 0xeU))))));
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2)) 
           & ((vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
               >= (0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                 << 4U))) & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2)) 
           & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)) 
              & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
                 >= (0xffffffU & ((0x7fffffU & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                >> 1U)) 
                                  - (IData)(1U))))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset 
        = (1U & (((~ (IData)(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n)) 
                  | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
                      & (0U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
                     & (0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb)))) 
                 | ((((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
                      & (8U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
                     & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb) 
                        >> 1U)) & (vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                                   >> 0xcU))));
    if ((1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid)) 
               | (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready)))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data 
            = ((2U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr))
                ? ((1U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr))
                    ? (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                        << 0xdU) | ((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                                      & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write)) 
                                     << 0xcU) | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart) 
                                                  << 0xbU) 
                                                 | (((IData)(vlSelf->o_uart_tx) 
                                                     << 0xaU) 
                                                    | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) 
                                                        << 9U) 
                                                       | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0) 
                                                           << 8U) 
                                                          | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0)
                                                              ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data)
                                                              : 0U)))))))
                    : ((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                         & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb)) 
                        << 0xcU) | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break) 
                                     << 0xbU) | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow) 
                                                        << 8U) 
                                                       | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                                                           ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                                                           : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data))))))))
                : ((1U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr))
                    ? (0x40000000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                                        << 0x10U) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status))))
                    : vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup));
    }
    if (vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n) {
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = 1U;
        } else if ((1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid)) 
                          | (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready)))) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = 0U;
        }
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid) 
             & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arready))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready = 0U;
        } else if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid) 
                    & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready = 1U;
        }
    } else {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready = 1U;
    }
    if (__Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[__Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo__v0;
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr = 0U;
    } else if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
                & (8U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr 
            = (1U & ((0x2000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                      ? ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart) 
                         ^ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                            >> 0x18U)) : ((0x1000000U 
                                           & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                                           ? ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity) 
                                              != (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart))
                                           : ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity) 
                                              == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart)))));
    } else if ((0xdU <= (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr = 0U;
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity;
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid 
        = __Vdly__top__DOT__u_uart_top__DOT__s_axi_arvalid;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill 
        = ((0x3f0U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill)) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n;
    if ((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup;
    }
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_arready 
        = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready;
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr 
            = (3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr) 
                     >> 2U));
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo
            [vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next];
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data 
        = (0xffU & vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata);
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write 
        = (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
            & (0xcU == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2)) 
           & ((vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
               >= (0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                 << 4U))) & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart))));
    if ((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) 
               | ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)) 
                  & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)))))) {
        vlSelf->o_uart_tx = 0U;
    } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter) {
        vlSelf->o_uart_tx = (1U & ((0U == (8U & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state)))
                                    ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data)
                                    : ((8U != (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state)) 
                                       || (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity))));
    }
    if (vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n) {
        if ((((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
              & (0xcU == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr)))) 
             & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb) 
                >> 1U))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break 
                = (1U & (vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                         >> 9U));
        }
    } else {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break = 0U;
    }
    if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) 
         & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow) 
            | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read) 
               & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next) 
                  == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write 
            = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data;
    }
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2) {
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow = 1U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next = 1U;
    } else {
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow = 0U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow 
                = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow) 
                   | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)));
        }
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) 
             & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow) 
                | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read) 
                   & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next) 
                      == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc = 1U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc = 0U;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr 
                = vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_waddr_plus_one;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read) {
            __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr)));
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next 
                = (0xfU & ((IData)(2U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr)));
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr;
    if (vlSelf->i_reset) {
        vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed = 1U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid = 0U;
    } else if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid = 1U;
    } else if (vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid = 0U;
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread;
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready 
        = __Vdly__top__DOT__u_uart_top__DOT__s_axi_rready;
    if (__Vdlyvset__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[__Vdlyvdim0__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo__v0;
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_waddr_plus_one 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n = 0U;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready) 
           & (8U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart 
        = ((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2))) 
           && (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)) 
                 & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status 
        = (0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill) 
                       << 2U) | ((2U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                        >> 2U)) | (1U 
                                                   & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow))))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb 
        = (((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2)) 
            & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr)) 
           & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
              | (0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))));
    if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup = 0x364U;
    } else {
        if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
             & (9U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data 
                = ((0x20000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                    ? ((0x10000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                        ? (0x1fU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg) 
                                    >> 3U)) : (0x3fU 
                                               & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg) 
                                                  >> 2U)))
                    : ((0x10000000U & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)
                        ? (0x7fU & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg) 
                                    >> 1U)) : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg)));
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr = 1U;
        } else if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter) 
                    | (0xfU == (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr = 0U;
        }
        if ((0xeU <= (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state))) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                = (0x3fffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup);
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr 
        = __Vdly__top__DOT__u_uart_top__DOT__s_axi_araddr;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2 
        = ((IData)(vlSelf->i_reset) | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break) 
                                       | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read 
        = ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)) 
           & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart 
        = ((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2))) 
           && (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) 
           | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_waddr_plus_one 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb) 
           & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow)) 
              | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read)));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart 
        = ((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2))) 
           && (IData)(vlSelf->i_uart_rx));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter 
        = ((0xfU != (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state)) 
           & (1U == vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter));
    if (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) 
         & (0U == (0xcU & (IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr))))) {
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
            = (0x7fffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup);
    }
    if (vlSelf->i_reset) {
        __Vdly__top__DOT__u_uart_top__DOT__tx_state = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb = 0U;
        __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready = 0U;
        TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready = 0U;
        vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid = 0U;
    } else {
        if ((0U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__tx_state))) {
            TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready 
                = (1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)));
            if (((IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.valid) 
                 & (IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.ready))) {
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid = 1U;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr = 0xcU;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid = 1U;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata 
                    = vlSymsp->TOP__top__DOT__uart_tx_stream.data;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb = 1U;
                __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready = 1U;
                TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready = 0U;
                __Vdly__top__DOT__u_uart_top__DOT__tx_state = 1U;
            }
        } else if ((1U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__tx_state))) {
            if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) {
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid = 0U;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid = 0U;
                vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb = 0U;
                __Vdly__top__DOT__u_uart_top__DOT__tx_state = 2U;
            }
        } else if ((2U == (IData)(vlSelf->top__DOT__u_uart_top__DOT__tx_state))) {
            if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid) {
                __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready = 0U;
                __Vdly__top__DOT__u_uart_top__DOT__tx_state = 0U;
            }
        } else {
            __Vdly__top__DOT__u_uart_top__DOT__tx_state = 0U;
        }
        if (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid = 1U;
        } else if (vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready) {
            vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid = 0U;
        }
    }
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2 
        = ((IData)(vlSelf->i_reset) | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state;
    vlSelf->top__DOT__u_uart_top__DOT__tx_state = __Vdly__top__DOT__u_uart_top__DOT__tx_state;
    vlSymsp->TOP__top__DOT__uart_tx_stream.ready = TOP__top__DOT__uart_tx_stream__DOT____Vdly__ready;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow;
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
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)) 
                 | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy)));
    vlSelf->__VdfgTmp_h61863ee6__0 = ((2U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                             >> 2U)) 
                                      | (1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow))));
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write 
        = ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write) 
           & ((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)) 
              | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6)));
    vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready 
        = __Vdly__top__DOT__u_uart_top__DOT__s_axi_bready;
    vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready 
        = __Vdly__top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready;
}

extern const VlWide<17>/*543:0*/ Vtop__ConstPool__CONST_h3a6afc40_0;
extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h93e1b771_0;
extern const VlWide<17>/*543:0*/ Vtop__ConstPool__CONST_h3a65fc40_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__top__DOT__u_engine__DOT__have_credit;
    __Vdly__top__DOT__u_engine__DOT__have_credit = 0;
    SData/*15:0*/ __Vdly__top__DOT__u_engine__DOT__bytes_left;
    __Vdly__top__DOT__u_engine__DOT__bytes_left = 0;
    CData/*1:0*/ __Vdly__top__DOT__u_engine__DOT__tx_state;
    __Vdly__top__DOT__u_engine__DOT__tx_state = 0;
    CData/*7:0*/ __Vdly__top__DOT__u_engine__DOT__byte_idx;
    __Vdly__top__DOT__u_engine__DOT__byte_idx = 0;
    SData/*15:0*/ __Vdly__top__DOT__u_engine__DOT__ready_cnt;
    __Vdly__top__DOT__u_engine__DOT__ready_cnt = 0;
    SData/*15:0*/ __Vdly__top__DOT__u_test_core__DOT__word_idx;
    __Vdly__top__DOT__u_test_core__DOT__word_idx = 0;
    CData/*1:0*/ __Vdly__top__DOT__u_test_core__DOT__state;
    __Vdly__top__DOT__u_test_core__DOT__state = 0;
    IData/*31:0*/ __Vdly__top__DOT__u_test_core__DOT__msg_num;
    __Vdly__top__DOT__u_test_core__DOT__msg_num = 0;
    CData/*0:0*/ TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done;
    TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done = 0;
    // Body
    __Vdly__top__DOT__u_test_core__DOT__msg_num = vlSelf->top__DOT__u_test_core__DOT__msg_num;
    __Vdly__top__DOT__u_test_core__DOT__state = vlSelf->top__DOT__u_test_core__DOT__state;
    __Vdly__top__DOT__u_test_core__DOT__word_idx = vlSelf->top__DOT__u_test_core__DOT__word_idx;
    __Vdly__top__DOT__u_engine__DOT__byte_idx = vlSelf->top__DOT__u_engine__DOT__byte_idx;
    __Vdly__top__DOT__u_engine__DOT__have_credit = vlSelf->top__DOT__u_engine__DOT__have_credit;
    TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done 
        = vlSymsp->TOP__top__DOT__sdr_core_if.wr_done;
    __Vdly__top__DOT__u_engine__DOT__bytes_left = vlSelf->top__DOT__u_engine__DOT__bytes_left;
    __Vdly__top__DOT__u_engine__DOT__ready_cnt = vlSelf->top__DOT__u_engine__DOT__ready_cnt;
    __Vdly__top__DOT__u_engine__DOT__tx_state = vlSelf->top__DOT__u_engine__DOT__tx_state;
    if (vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n) {
        if ((2U & (IData)(vlSelf->top__DOT__u_test_core__DOT__state))) {
            if ((1U & (IData)(vlSelf->top__DOT__u_test_core__DOT__state))) {
                if ((0x927c0U == vlSelf->top__DOT__u_test_core__DOT__gap_cnt)) {
                    __Vdly__top__DOT__u_test_core__DOT__word_idx = 0U;
                    __Vdly__top__DOT__u_test_core__DOT__state = 1U;
                } else {
                    vlSelf->top__DOT__u_test_core__DOT__gap_cnt 
                        = (0xfffffU & ((IData)(1U) 
                                       + vlSelf->top__DOT__u_test_core__DOT__gap_cnt));
                }
            } else if (VL_UNLIKELY(vlSymsp->TOP__top__DOT__sdr_core_if.wr_done)) {
                VL_WRITEF("[FPGA%0#] TX msg#%0# done (200 bytes)\n",
                          32,vlSelf->top__DOT__u_test_core__DOT__fpga_id,
                          32,vlSelf->top__DOT__u_test_core__DOT__msg_num);
                __Vdly__top__DOT__u_test_core__DOT__msg_num 
                    = ((IData)(1U) + vlSelf->top__DOT__u_test_core__DOT__msg_num);
                vlSelf->top__DOT__u_test_core__DOT__gap_cnt = 0U;
                __Vdly__top__DOT__u_test_core__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__u_test_core__DOT__state))) {
            if (VL_UNLIKELY(((IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid) 
                             & (2U == (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))))) {
                VL_WRITEF("[FPGA%0#] TX msg#%0# word %0#/50  data=0x%08x\n",
                          32,vlSelf->top__DOT__u_test_core__DOT__fpga_id,
                          32,vlSelf->top__DOT__u_test_core__DOT__msg_num,
                          16,(IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx),
                          32,vlSymsp->TOP__top__DOT__sdr_core_if.wr_data);
                if ((0x31U == (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx))) {
                    __Vdly__top__DOT__u_test_core__DOT__state = 2U;
                }
                __Vdly__top__DOT__u_test_core__DOT__word_idx 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx)));
            }
        } else if ((0x186a0U == vlSelf->top__DOT__u_test_core__DOT__settle_cnt)) {
            __Vdly__top__DOT__u_test_core__DOT__word_idx = 0U;
            __Vdly__top__DOT__u_test_core__DOT__state = 1U;
        } else {
            vlSelf->top__DOT__u_test_core__DOT__settle_cnt 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__u_test_core__DOT__settle_cnt));
        }
        if (VL_UNLIKELY(vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid)) {
            VL_WRITEF("[FPGA%0#] RX msg#%0#      data=0x%08x (len=%0# B%s)\n",
                      32,vlSelf->top__DOT__u_test_core__DOT__fpga_id,
                      32,vlSelf->top__DOT__u_test_core__DOT__msg_num,
                      32,vlSymsp->TOP__top__DOT__sdr_core_if.rd_data,
                      8,(IData)(vlSymsp->TOP__top__DOT__sdr_core_if.rd_len),
                      48,((IData)(vlSymsp->TOP__top__DOT__sdr_core_if.rd_last)
                           ? 0x2c206c617374ULL : 0ULL));
        }
    } else {
        __Vdly__top__DOT__u_test_core__DOT__state = 0U;
        vlSelf->top__DOT__u_test_core__DOT__settle_cnt = 0U;
        vlSelf->top__DOT__u_test_core__DOT__gap_cnt = 0U;
        __Vdly__top__DOT__u_test_core__DOT__word_idx = 0U;
        __Vdly__top__DOT__u_test_core__DOT__msg_num = 0U;
    }
    if (vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n) {
        vlSelf->top__DOT__u_serialiser__DOT__rem = vlSelf->top__DOT__u_serialiser__DOT__rem_n;
        vlSelf->top__DOT__u_serialiser__DOT__byte_idx 
            = vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n;
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[1U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[1U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[2U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[2U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[3U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[3U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[4U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[4U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[5U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[5U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[6U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[6U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[7U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[7U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[8U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[8U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[9U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[9U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xaU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xaU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xbU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xbU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xcU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xcU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xdU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xdU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xeU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xeU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xfU] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xfU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
            = vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0x10U];
        vlSelf->top__DOT__u_serialiser__DOT__state 
            = vlSelf->top__DOT__u_serialiser__DOT__state_n;
        if (vlSelf->top__DOT__u_engine__DOT__rx_state) {
            if (vlSelf->top__DOT__u_engine__DOT__rx_state) {
                vlSelf->top__DOT__u_engine__DOT__rx_idx 
                    = (0xffU & ((IData)(4U) + (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx)));
                if ((4U >= (IData)(vlSelf->top__DOT__u_engine__DOT__rx_rem))) {
                    vlSelf->top__DOT__u_engine__DOT__rx_state = 0U;
                }
            } else {
                vlSelf->top__DOT__u_engine__DOT__rx_state = 0U;
            }
        } else if (((IData)(vlSelf->top__DOT__u_engine__DOT__rsp_is_data) 
                    & (0U != (0xffU & (vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U] 
                                       >> 8U))))) {
            vlSelf->top__DOT__u_engine__DOT__rx_idx = 0U;
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[1U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[1U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[2U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[2U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[3U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[3U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[4U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[4U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[5U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[5U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[6U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[6U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[7U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[7U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[8U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[8U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[9U] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[9U];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xaU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xaU];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xbU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xbU];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xcU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xcU];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xdU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xdU];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xeU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xeU];
            vlSelf->top__DOT__u_engine__DOT__rx_payload[0xfU] 
                = vlSelf->top__DOT__u_decoder__DOT__prot_buf[0xfU];
            vlSelf->top__DOT__u_engine__DOT__rx_len 
                = (0xffU & (vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U] 
                            >> 8U));
            vlSelf->top__DOT__u_engine__DOT__rx_state = 1U;
        }
        TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done = 0U;
        if (vlSelf->top__DOT__u_engine__DOT__rsp_is_ready) {
            __Vdly__top__DOT__u_engine__DOT__have_credit = 1U;
        }
        if ((((~ (IData)(vlSelf->top__DOT__u_engine__DOT__in_msg)) 
              & (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid)) 
             & (~ (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_done)))) {
            vlSelf->top__DOT__u_engine__DOT__in_msg = 1U;
            __Vdly__top__DOT__u_engine__DOT__bytes_left = 0xc8U;
            vlSelf->top__DOT__u_engine__DOT__cur_dst 
                = (0xffU & (1U ^ vlSelf->top__DOT__u_test_core__DOT__fpga_id));
        }
        if ((2U & (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))) {
            if ((1U & (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))) {
                if (vlSelf->top__DOT__u_engine__DOT__req_fire) {
                    __Vdly__top__DOT__u_engine__DOT__bytes_left 
                        = (0xffffU & ((IData)(vlSelf->top__DOT__u_engine__DOT__bytes_left) 
                                      - (IData)(vlSelf->top__DOT__u_engine__DOT__chunk_len)));
                    __Vdly__top__DOT__u_engine__DOT__have_credit = 0U;
                    if (((IData)(vlSelf->top__DOT__u_engine__DOT__bytes_left) 
                         == (IData)(vlSelf->top__DOT__u_engine__DOT__chunk_len))) {
                        vlSelf->top__DOT__u_engine__DOT__in_msg = 0U;
                        TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done = 1U;
                    }
                    __Vdly__top__DOT__u_engine__DOT__tx_state = 1U;
                }
            } else if (vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid) {
                VL_ASSIGNSEL_WI(512,32,(0x1ffU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_engine__DOT__byte_idx), 3U)), vlSelf->top__DOT__u_engine__DOT__chunk_buf, vlSymsp->TOP__top__DOT__sdr_core_if.wr_data);
                __Vdly__top__DOT__u_engine__DOT__byte_idx 
                    = (0xffU & ((IData)(4U) + (IData)(vlSelf->top__DOT__u_engine__DOT__byte_idx)));
                if (((0xffU & ((IData)(4U) + (IData)(vlSelf->top__DOT__u_engine__DOT__byte_idx))) 
                     >= (IData)(vlSelf->top__DOT__u_engine__DOT__chunk_len))) {
                    __Vdly__top__DOT__u_engine__DOT__tx_state = 3U;
                }
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))) {
            if ((((IData)(vlSelf->top__DOT__u_engine__DOT__have_credit) 
                  & (IData)(vlSelf->top__DOT__u_engine__DOT__tx_msg_active)) 
                 & (0U != (IData)(vlSelf->top__DOT__u_engine__DOT__tx_left)))) {
                vlSelf->top__DOT__u_engine__DOT__chunk_len 
                    = ((0x40U < (IData)(vlSelf->top__DOT__u_engine__DOT__tx_left))
                        ? 0x40U : (0xffU & (IData)(vlSelf->top__DOT__u_engine__DOT__tx_left)));
                __Vdly__top__DOT__u_engine__DOT__byte_idx = 0U;
                __Vdly__top__DOT__u_engine__DOT__tx_state = 2U;
            }
        } else if (((IData)(vlSelf->top__DOT__u_engine__DOT__have_credit) 
                    | (IData)(vlSelf->top__DOT__u_engine__DOT__rsp_is_ready))) {
            __Vdly__top__DOT__u_engine__DOT__tx_state = 1U;
        } else if (vlSelf->top__DOT__u_engine__DOT__req_fire) {
            __Vdly__top__DOT__u_engine__DOT__ready_cnt = 0xc34fU;
        } else if ((0U != (IData)(vlSelf->top__DOT__u_engine__DOT__ready_cnt))) {
            __Vdly__top__DOT__u_engine__DOT__ready_cnt 
                = (0xffffU & ((IData)(vlSelf->top__DOT__u_engine__DOT__ready_cnt) 
                              - (IData)(1U)));
        }
    } else {
        vlSelf->top__DOT__u_serialiser__DOT__rem = 0U;
        vlSelf->top__DOT__u_serialiser__DOT__byte_idx = 0U;
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[1U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[1U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[2U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[2U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[3U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[3U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[4U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[4U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[5U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[5U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[6U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[6U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[7U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[7U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[8U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[8U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[9U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[9U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xaU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xaU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xbU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xbU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xcU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xcU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xdU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xdU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xeU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xeU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0xfU] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0xfU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
            = Vtop__ConstPool__CONST_h3a6afc40_0[0x10U];
        vlSelf->top__DOT__u_serialiser__DOT__state = 0U;
        vlSelf->top__DOT__u_engine__DOT__rx_idx = 0U;
        vlSelf->top__DOT__u_engine__DOT__rx_state = 0U;
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[1U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[1U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[2U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[2U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[3U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[3U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[4U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[4U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[5U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[5U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[6U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[6U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[7U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[7U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[8U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[8U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[9U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[9U];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xaU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xbU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xcU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xdU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xeU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelf->top__DOT__u_engine__DOT__rx_payload[0xfU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelf->top__DOT__u_engine__DOT__rx_len = 0U;
        __Vdly__top__DOT__u_engine__DOT__have_credit = 0U;
        __Vdly__top__DOT__u_engine__DOT__bytes_left = 0U;
        TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done = 0U;
        __Vdly__top__DOT__u_engine__DOT__tx_state = 0U;
        vlSelf->top__DOT__u_engine__DOT__in_msg = 0U;
        vlSelf->top__DOT__u_engine__DOT__chunk_len = 0U;
        __Vdly__top__DOT__u_engine__DOT__byte_idx = 0U;
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[1U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[1U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[2U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[2U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[3U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[3U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[4U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[4U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[5U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[5U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[6U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[6U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[7U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[7U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[8U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[8U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[9U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[9U];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xaU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xbU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xcU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xdU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xeU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelf->top__DOT__u_engine__DOT__chunk_buf[0xfU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelf->top__DOT__u_engine__DOT__cur_dst = 0U;
        __Vdly__top__DOT__u_engine__DOT__ready_cnt = 0U;
    }
    vlSelf->top__DOT__u_test_core__DOT__msg_num = __Vdly__top__DOT__u_test_core__DOT__msg_num;
    vlSelf->top__DOT__u_test_core__DOT__state = __Vdly__top__DOT__u_test_core__DOT__state;
    vlSelf->top__DOT__u_test_core__DOT__word_idx = __Vdly__top__DOT__u_test_core__DOT__word_idx;
    vlSelf->top__DOT__u_engine__DOT__have_credit = __Vdly__top__DOT__u_engine__DOT__have_credit;
    vlSymsp->TOP__top__DOT__sdr_core_if.wr_done = TOP__top__DOT__sdr_core_if__DOT____Vdly__wr_done;
    vlSelf->top__DOT__u_engine__DOT__byte_idx = __Vdly__top__DOT__u_engine__DOT__byte_idx;
    vlSelf->top__DOT__u_engine__DOT__bytes_left = __Vdly__top__DOT__u_engine__DOT__bytes_left;
    vlSelf->top__DOT__u_engine__DOT__ready_cnt = __Vdly__top__DOT__u_engine__DOT__ready_cnt;
    vlSelf->top__DOT__u_engine__DOT__tx_state = __Vdly__top__DOT__u_engine__DOT__tx_state;
    vlSymsp->TOP__top__DOT__sdr_core_if.wr_data = (
                                                   (vlSelf->top__DOT__u_test_core__DOT__fpga_id 
                                                    << 0x18U) 
                                                   | (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx));
    vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid = 
        ((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state)) 
         & (0x32U > (IData)(vlSelf->top__DOT__u_test_core__DOT__word_idx)));
    vlSelf->top__DOT__u_engine__DOT__rx_rem = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__u_engine__DOT__rx_len) 
                                                  - (IData)(vlSelf->top__DOT__u_engine__DOT__rx_idx)));
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid = 0U;
    vlSymsp->TOP__top__DOT__sdr_core_if.rd_data = 0U;
    vlSelf->top__DOT__u_engine__DOT__tx_left = ((IData)(vlSelf->top__DOT__u_engine__DOT__in_msg)
                                                 ? (IData)(vlSelf->top__DOT__u_engine__DOT__bytes_left)
                                                 : 0xc8U);
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
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSymsp->TOP__top__DOT__protocol_rx.ready = 1U;
    if (vlSelf->top__DOT__u_engine__DOT__rsp_is_data) {
        vlSymsp->TOP__top__DOT__protocol_rx.ready = 
            (1U & (~ (IData)(vlSelf->top__DOT__u_engine__DOT__rx_state)));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__u_serialiser__DOT__state_n = vlSelf->top__DOT__u_serialiser__DOT__state;
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[1U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[1U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[2U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[2U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[3U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[3U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[4U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[4U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[5U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[5U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[6U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[6U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[7U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[7U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[8U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[8U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[9U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[9U];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xaU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xaU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xbU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xbU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xcU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xcU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xdU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xdU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xeU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xeU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xfU] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0xfU];
    vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0x10U] 
        = vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U];
    vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n 
        = vlSelf->top__DOT__u_serialiser__DOT__byte_idx;
    vlSelf->top__DOT__u_serialiser__DOT__rem_n = vlSelf->top__DOT__u_serialiser__DOT__rem;
    vlSymsp->TOP__top__DOT__protocol_tx.ready = 0U;
    vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 0U;
    vlSymsp->TOP__top__DOT__uart_tx_stream.data = 0U;
    if ((4U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_serialiser.sv:96: Assertion failed in %Ntop.u_serialiser: Unreachable sdr_ctrl_protocol_serialiser state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_serialiser.sv", 96, "");
        } else if (VL_UNLIKELY((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state)))) {
            VL_WRITEF("[%0t] %%Fatal: sdr_ctrl_protocol_byte_serialiser.sv:96: Assertion failed in %Ntop.u_serialiser: Unreachable sdr_ctrl_protocol_serialiser state\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("../rtl/../rtl/protocol/sdr_ctrl_protocol_byte_serialiser.sv", 96, "");
        } else {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & (((0U == (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U)))
                              ? 0U : (vlSelf->top__DOT__u_serialiser__DOT__pkt[
                                      (((IData)(7U) 
                                        + (0x1ffU & 
                                           VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U))) 
                                       >> 5U)] << ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U))))) 
                            | (vlSelf->top__DOT__u_serialiser__DOT__pkt[
                               (0xfU & (VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U) 
                                        >> 5U))] >> 
                               (0x1fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx), 3U)))));
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_serialiser__DOT__byte_idx)));
                vlSelf->top__DOT__u_serialiser__DOT__rem_n 
                    = (0xffU & ((IData)(vlSelf->top__DOT__u_serialiser__DOT__rem) 
                                - (IData)(1U)));
                if ((1U == (IData)(vlSelf->top__DOT__u_serialiser__DOT__rem))) {
                    vlSelf->top__DOT__u_serialiser__DOT__state_n = 0U;
                }
            }
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        if ((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U]);
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__state_n 
                    = ((0U == (IData)(vlSelf->top__DOT__u_serialiser__DOT__rem))
                        ? 0U : 4U);
            }
        } else {
            vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
            vlSymsp->TOP__top__DOT__uart_tx_stream.data 
                = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                            >> 8U));
            if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
                vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n = 0U;
                vlSelf->top__DOT__u_serialiser__DOT__rem_n 
                    = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                                >> 8U));
                vlSelf->top__DOT__u_serialiser__DOT__state_n = 3U;
            }
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__u_serialiser__DOT__state))) {
        vlSymsp->TOP__top__DOT__uart_tx_stream.valid = 1U;
        vlSymsp->TOP__top__DOT__uart_tx_stream.data 
            = (0xffU & (vlSelf->top__DOT__u_serialiser__DOT__pkt[0x10U] 
                        >> 0x10U));
        if (vlSelf->top__DOT__u_serialiser__DOT__iter_fire) {
            vlSelf->top__DOT__u_serialiser__DOT__state_n = 2U;
        }
    } else if (vlSymsp->TOP__top__DOT__protocol_tx.valid) {
        vlSymsp->TOP__top__DOT__protocol_tx.ready = 1U;
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[1U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[1U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[2U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[2U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[3U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[3U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[4U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[4U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[5U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[5U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[6U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[6U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[7U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[7U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[8U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[8U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[9U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[9U];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xaU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xaU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xbU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xbU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xcU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xcU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xdU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xdU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xeU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xeU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0xfU] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0xfU];
        vlSelf->top__DOT__u_serialiser__DOT__pkt_n[0x10U] 
            = vlSymsp->TOP__top__DOT__protocol_tx.data[0x10U];
        vlSelf->top__DOT__u_serialiser__DOT__state_n = 1U;
    }
    vlSelf->top__DOT__u_engine__DOT__req_fire = ((IData)(vlSymsp->TOP__top__DOT__protocol_tx.valid) 
                                                 & (IData)(vlSymsp->TOP__top__DOT__protocol_tx.ready));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    // Body
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

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__u_serialiser__DOT__iter_fire 
        = ((IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.valid) 
           & (IData)(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
}
