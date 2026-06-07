// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__u_test_core__DOT__fpga_id),32);
        bufp->chgCData(oldp+1,((0xffU & (1U ^ vlSelf->top__DOT__u_test_core__DOT__fpga_id))),8);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__u_decoder__DOT__state_n),3);
        bufp->chgWData(oldp+3,(vlSelf->top__DOT__u_decoder__DOT__prot_buf_n),536);
        bufp->chgCData(oldp+20,(vlSelf->top__DOT__u_decoder__DOT__rem_n),8);
        bufp->chgCData(oldp+21,(vlSelf->top__DOT__u_decoder__DOT__byte_idx_n),8);
        bufp->chgBit(oldp+22,(vlSelf->top__DOT__u_engine__DOT__rsp_is_ready));
        bufp->chgBit(oldp+23,(vlSelf->top__DOT__u_engine__DOT__rsp_is_data));
        bufp->chgBit(oldp+24,(vlSymsp->TOP__top__DOT__uart_rx_stream.ready));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__top__DOT__protocol_rx.valid));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+26,(vlSelf->top__DOT__u_engine__DOT__req_fire));
        bufp->chgCData(oldp+27,(vlSelf->top__DOT__u_serialiser__DOT__state_n),3);
        bufp->chgWData(oldp+28,(vlSelf->top__DOT__u_serialiser__DOT__pkt_n),536);
        bufp->chgCData(oldp+45,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n),8);
        bufp->chgCData(oldp+46,(vlSelf->top__DOT__u_serialiser__DOT__rem_n),8);
        bufp->chgBit(oldp+47,(vlSymsp->TOP__top__DOT__uart_tx_stream.valid));
        bufp->chgCData(oldp+48,(vlSymsp->TOP__top__DOT__uart_tx_stream.data),8);
        bufp->chgBit(oldp+49,(vlSymsp->TOP__top__DOT__protocol_tx.ready));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+50,(vlSelf->top__DOT__u_decoder__DOT__state),3);
        bufp->chgCData(oldp+51,(vlSelf->top__DOT__u_decoder__DOT__rem),8);
        bufp->chgCData(oldp+52,(vlSelf->top__DOT__u_decoder__DOT__byte_idx),8);
        bufp->chgBit(oldp+53,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid));
        bufp->chgBit(oldp+54,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready));
        bufp->chgCData(oldp+55,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr),4);
        bufp->chgBit(oldp+56,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata),32);
        bufp->chgCData(oldp+58,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb),4);
        bufp->chgBit(oldp+59,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid));
        bufp->chgBit(oldp+60,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready));
        bufp->chgBit(oldp+61,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid));
        bufp->chgBit(oldp+62,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
        bufp->chgCData(oldp+63,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr),4);
        bufp->chgBit(oldp+64,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid));
        bufp->chgBit(oldp+65,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready));
        bufp->chgIData(oldp+66,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data),32);
        bufp->chgBit(oldp+67,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)))));
        bufp->chgBit(oldp+68,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)))));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                     >> 3U))));
        bufp->chgBit(oldp+70,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                     >> 3U))));
        bufp->chgCData(oldp+71,(vlSelf->top__DOT__u_uart_top__DOT__tx_state),2);
        bufp->chgCData(oldp+72,(vlSelf->top__DOT__u_uart_top__DOT__state),3);
        bufp->chgIData(oldp+73,(vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum),32);
        bufp->chgCData(oldp+74,(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count),5);
        bufp->chgCData(oldp+75,(vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed),5);
        bufp->chgCData(oldp+76,(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx),5);
        bufp->chgBit(oldp+77,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n));
        bufp->chgCData(oldp+78,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr) 
                                       >> 2U))),2);
        bufp->chgBit(oldp+79,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready));
        bufp->chgCData(oldp+80,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr) 
                                       >> 2U))),2);
        bufp->chgBit(oldp+81,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy));
        bufp->chgIData(oldp+82,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup),31);
        bufp->chgBit(oldp+83,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb));
        bufp->chgBit(oldp+84,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break));
        bufp->chgBit(oldp+85,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr));
        bufp->chgBit(oldp+86,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr));
        bufp->chgBit(oldp+87,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart));
        bufp->chgCData(oldp+88,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data),8);
        bufp->chgBit(oldp+89,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
        bufp->chgBit(oldp+90,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                               & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb))));
        bufp->chgCData(oldp+91,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                                  ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                                  : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data))),8);
        bufp->chgSData(oldp+92,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status),16);
        bufp->chgBit(oldp+93,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
        bufp->chgBit(oldp+94,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr));
        bufp->chgBit(oldp+95,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr));
        bufp->chgIData(oldp+96,(((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                                   & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb)) 
                                  << 0xcU) | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow) 
                                                        << 8U) 
                                                       | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                                                           ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                                                           : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data)))))))),32);
        bufp->chgBit(oldp+97,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)))));
        bufp->chgBit(oldp+98,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                               & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write))));
        bufp->chgBit(oldp+99,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break));
        bufp->chgCData(oldp+100,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc)
                                   ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write)
                                   : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data))),8);
        bufp->chgSData(oldp+101,((0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                              << 2U) 
                                             | (IData)(vlSelf->__VdfgTmp_h61863ee6__0)))),16);
        bufp->chgBit(oldp+102,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write));
        bufp->chgBit(oldp+103,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
        bufp->chgCData(oldp+104,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data),8);
        bufp->chgIData(oldp+105,((0x40000000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                                  << 0x12U) 
                                                 | (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                                                     << 0x10U) 
                                                    | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status))))),32);
        bufp->chgCData(oldp+106,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr),2);
        bufp->chgBit(oldp+107,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread));
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup),32);
        bufp->chgIData(oldp+109,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)),24);
        bufp->chgIData(oldp+110,((0xffffffU & ((0x7fffffU 
                                                & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                   >> 1U)) 
                                               - (IData)(1U)))),24);
        bufp->chgCData(oldp+111,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                        >> 0x1cU))),2);
        bufp->chgBit(oldp+112,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+113,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x18U))));
        bufp->chgBit(oldp+114,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+115,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x19U))));
        bufp->chgIData(oldp+116,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup),30);
        bufp->chgCData(oldp+117,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state),4);
        bufp->chgIData(oldp+118,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter),24);
        bufp->chgBit(oldp+119,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter));
        bufp->chgBit(oldp+120,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart));
        bufp->chgBit(oldp+121,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart));
        bufp->chgIData(oldp+122,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter),28);
        bufp->chgIData(oldp+123,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                << 4U))),28);
        bufp->chgBit(oldp+124,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch));
        bufp->chgBit(oldp+125,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time));
        bufp->chgCData(oldp+126,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg),8);
        bufp->chgBit(oldp+127,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity));
        bufp->chgBit(oldp+128,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr));
        bufp->chgCData(oldp+129,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[0]),8);
        bufp->chgCData(oldp+130,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[1]),8);
        bufp->chgCData(oldp+131,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[2]),8);
        bufp->chgCData(oldp+132,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[3]),8);
        bufp->chgCData(oldp+133,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[4]),8);
        bufp->chgCData(oldp+134,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[5]),8);
        bufp->chgCData(oldp+135,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[6]),8);
        bufp->chgCData(oldp+136,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[7]),8);
        bufp->chgCData(oldp+137,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[8]),8);
        bufp->chgCData(oldp+138,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[9]),8);
        bufp->chgCData(oldp+139,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[10]),8);
        bufp->chgCData(oldp+140,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[11]),8);
        bufp->chgCData(oldp+141,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[12]),8);
        bufp->chgCData(oldp+142,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[13]),8);
        bufp->chgCData(oldp+143,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[14]),8);
        bufp->chgCData(oldp+144,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[15]),8);
        bufp->chgCData(oldp+145,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data),8);
        bufp->chgCData(oldp+146,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write),8);
        bufp->chgCData(oldp+147,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr),4);
        bufp->chgCData(oldp+148,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr),4);
        bufp->chgCData(oldp+149,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next),4);
        bufp->chgBit(oldp+150,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow));
        bufp->chgBit(oldp+151,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow));
        bufp->chgBit(oldp+152,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc));
        bufp->chgCData(oldp+153,((0xfU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
        bufp->chgCData(oldp+154,((0xfU & ((IData)(2U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
        bufp->chgBit(oldp+155,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write));
        bufp->chgBit(oldp+156,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read));
        bufp->chgCData(oldp+157,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill),4);
        bufp->chgSData(oldp+158,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill),10);
        bufp->chgIData(oldp+159,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)),28);
        bufp->chgIData(oldp+160,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                                << 4U))),28);
        bufp->chgCData(oldp+161,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                        >> 0x1cU))),2);
        bufp->chgCData(oldp+162,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                        >> 0x1cU))),2);
        bufp->chgBit(oldp+163,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+164,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x18U))));
        bufp->chgBit(oldp+165,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+166,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x19U))));
        bufp->chgBit(oldp+167,((1U & (~ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                         >> 0x1eU)))));
        bufp->chgBit(oldp+168,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                      >> 0x18U))));
        bufp->chgIData(oldp+169,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup),31);
        bufp->chgIData(oldp+170,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter),28);
        bufp->chgCData(oldp+171,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state),4);
        bufp->chgCData(oldp+172,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data),8);
        bufp->chgBit(oldp+173,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity));
        bufp->chgBit(oldp+174,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter));
        bufp->chgBit(oldp+175,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state));
        bufp->chgBit(oldp+176,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n));
        bufp->chgBit(oldp+177,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n));
        bufp->chgBit(oldp+178,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts));
        bufp->chgBit(oldp+179,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2));
        bufp->chgBit(oldp+180,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
        bufp->chgCData(oldp+181,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[0]),8);
        bufp->chgCData(oldp+182,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[1]),8);
        bufp->chgCData(oldp+183,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[2]),8);
        bufp->chgCData(oldp+184,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[3]),8);
        bufp->chgCData(oldp+185,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[4]),8);
        bufp->chgCData(oldp+186,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[5]),8);
        bufp->chgCData(oldp+187,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[6]),8);
        bufp->chgCData(oldp+188,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[7]),8);
        bufp->chgCData(oldp+189,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[8]),8);
        bufp->chgCData(oldp+190,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[9]),8);
        bufp->chgCData(oldp+191,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[10]),8);
        bufp->chgCData(oldp+192,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[11]),8);
        bufp->chgCData(oldp+193,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[12]),8);
        bufp->chgCData(oldp+194,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[13]),8);
        bufp->chgCData(oldp+195,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[14]),8);
        bufp->chgCData(oldp+196,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[15]),8);
        bufp->chgCData(oldp+197,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data),8);
        bufp->chgCData(oldp+198,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write),8);
        bufp->chgCData(oldp+199,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr),4);
        bufp->chgCData(oldp+200,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr),4);
        bufp->chgCData(oldp+201,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next),4);
        bufp->chgBit(oldp+202,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow));
        bufp->chgBit(oldp+203,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow));
        bufp->chgBit(oldp+204,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc));
        bufp->chgCData(oldp+205,((0xfU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
        bufp->chgCData(oldp+206,((0xfU & ((IData)(2U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
        bufp->chgBit(oldp+207,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write));
        bufp->chgBit(oldp+208,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read));
        bufp->chgCData(oldp+209,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill),4);
        bufp->chgSData(oldp+210,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill),10);
        bufp->chgBit(oldp+211,(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
        bufp->chgBit(oldp+212,(vlSymsp->TOP__top__DOT__uart_rx_stream.valid));
        bufp->chgCData(oldp+213,(vlSymsp->TOP__top__DOT__uart_rx_stream.data),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+214,(vlSelf->top__DOT__u_engine__DOT__tx_state),2);
        bufp->chgBit(oldp+215,(vlSelf->top__DOT__u_engine__DOT__have_credit));
        bufp->chgBit(oldp+216,(vlSelf->top__DOT__u_engine__DOT__in_msg));
        bufp->chgSData(oldp+217,(vlSelf->top__DOT__u_engine__DOT__bytes_left),16);
        bufp->chgCData(oldp+218,(vlSelf->top__DOT__u_engine__DOT__chunk_len),8);
        bufp->chgCData(oldp+219,(vlSelf->top__DOT__u_engine__DOT__byte_idx),8);
        bufp->chgWData(oldp+220,(vlSelf->top__DOT__u_engine__DOT__chunk_buf),512);
        bufp->chgCData(oldp+236,(vlSelf->top__DOT__u_engine__DOT__cur_dst),8);
        bufp->chgSData(oldp+237,(vlSelf->top__DOT__u_engine__DOT__ready_cnt),16);
        bufp->chgBit(oldp+238,(((IData)(vlSelf->top__DOT__u_engine__DOT__in_msg) 
                                | (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid))));
        bufp->chgSData(oldp+239,(vlSelf->top__DOT__u_engine__DOT__tx_left),16);
        bufp->chgBit(oldp+240,(vlSelf->top__DOT__u_engine__DOT__rx_state));
        bufp->chgWData(oldp+241,(vlSelf->top__DOT__u_engine__DOT__rx_payload),512);
        bufp->chgCData(oldp+257,(vlSelf->top__DOT__u_engine__DOT__rx_len),8);
        bufp->chgCData(oldp+258,(vlSelf->top__DOT__u_engine__DOT__rx_idx),8);
        bufp->chgCData(oldp+259,(vlSelf->top__DOT__u_engine__DOT__rx_rem),8);
        bufp->chgCData(oldp+260,(vlSelf->top__DOT__u_serialiser__DOT__state),3);
        bufp->chgWData(oldp+261,(vlSelf->top__DOT__u_serialiser__DOT__pkt),536);
        bufp->chgCData(oldp+278,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx),8);
        bufp->chgCData(oldp+279,(vlSelf->top__DOT__u_serialiser__DOT__rem),8);
        bufp->chgCData(oldp+280,(vlSelf->top__DOT__u_test_core__DOT__state),2);
        bufp->chgIData(oldp+281,(vlSelf->top__DOT__u_test_core__DOT__settle_cnt),17);
        bufp->chgIData(oldp+282,(vlSelf->top__DOT__u_test_core__DOT__gap_cnt),20);
        bufp->chgSData(oldp+283,(vlSelf->top__DOT__u_test_core__DOT__word_idx),16);
        bufp->chgIData(oldp+284,(vlSelf->top__DOT__u_test_core__DOT__msg_num),32);
        bufp->chgBit(oldp+285,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid));
        bufp->chgBit(oldp+286,((2U == (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))));
        bufp->chgIData(oldp+287,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_data),32);
        bufp->chgBit(oldp+288,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_done));
        bufp->chgBit(oldp+289,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid));
        bufp->chgIData(oldp+290,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_data),32);
        bufp->chgCData(oldp+291,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_len),8);
        bufp->chgBit(oldp+292,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_last));
        bufp->chgBit(oldp+293,(vlSymsp->TOP__top__DOT__protocol_tx.valid));
        bufp->chgWData(oldp+294,(vlSymsp->TOP__top__DOT__protocol_tx.data),536);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgWData(oldp+311,(vlSelf->top__DOT__u_decoder__DOT__prot_buf),536);
    }
    bufp->chgBit(oldp+328,(vlSelf->i_clk));
    bufp->chgBit(oldp+329,(vlSelf->i_reset));
    bufp->chgBit(oldp+330,(vlSelf->i_uart_rx));
    bufp->chgBit(oldp+331,(vlSelf->o_uart_tx));
    bufp->chgBit(oldp+332,(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n));
    bufp->chgBit(oldp+333,(vlSelf->top__DOT__u_serialiser__DOT__iter_fire));
    bufp->chgIData(oldp+334,((((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                               << 0xdU) | ((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                                             & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write)) 
                                            << 0xcU) 
                                           | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->o_uart_tx) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0) 
                                                        << 8U) 
                                                       | ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0)
                                                           ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data)
                                                           : 0U)))))))),32);
    bufp->chgBit(oldp+335,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2));
    bufp->chgBit(oldp+336,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2));
    bufp->chgBit(oldp+337,(vlSymsp->TOP__top__DOT__protocol_rx.ready));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
