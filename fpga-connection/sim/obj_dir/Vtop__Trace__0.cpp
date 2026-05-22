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
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__u_decoder__DOT__state_n),2);
        bufp->chgBit(oldp+2,(vlSelf->top__DOT__u_engine__DOT__state_n));
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__u_engine__DOT__paused_n));
        bufp->chgSData(oldp+4,(vlSelf->top__DOT__u_engine__DOT__poll_cnt_n),10);
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__u_engine__DOT__rsp_fire));
        bufp->chgBit(oldp+6,(((IData)(vlSymsp->TOP__top__DOT__protocol_tx.valid) 
                              & (IData)(vlSymsp->TOP__top__DOT__protocol_tx.ready))));
        bufp->chgWData(oldp+7,(vlSelf->top__DOT__u_serialiser__DOT__pkt_n),528);
        bufp->chgBit(oldp+24,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_ready));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid));
        bufp->chgIData(oldp+26,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_data),32);
        bufp->chgCData(oldp+27,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_len),8);
        bufp->chgBit(oldp+28,(vlSymsp->TOP__top__DOT__protocol_tx.valid));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__top__DOT__protocol_tx.ready));
        bufp->chgWData(oldp+30,(vlSymsp->TOP__top__DOT__protocol_tx.data),528);
        bufp->chgBit(oldp+47,(vlSymsp->TOP__top__DOT__protocol_rx.ready));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+48,(vlSelf->top__DOT__u_decoder__DOT__state),2);
        bufp->chgWData(oldp+49,(vlSelf->top__DOT__u_decoder__DOT__prot_buf),528);
        bufp->chgWData(oldp+66,(vlSelf->top__DOT__u_decoder__DOT__prot_buf_n),528);
        bufp->chgCData(oldp+83,(vlSelf->top__DOT__u_decoder__DOT__rem),8);
        bufp->chgCData(oldp+84,(vlSelf->top__DOT__u_decoder__DOT__rem_n),8);
        bufp->chgCData(oldp+85,(vlSelf->top__DOT__u_decoder__DOT__byte_idx),8);
        bufp->chgCData(oldp+86,(vlSelf->top__DOT__u_decoder__DOT__byte_idx_n),8);
        bufp->chgCData(oldp+87,((0xffU & (vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U] 
                                          >> 8U))),8);
        bufp->chgBit(oldp+88,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid));
        bufp->chgBit(oldp+89,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready));
        bufp->chgCData(oldp+90,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr),4);
        bufp->chgBit(oldp+91,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+92,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata),32);
        bufp->chgCData(oldp+93,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb),4);
        bufp->chgBit(oldp+94,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid));
        bufp->chgBit(oldp+95,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready));
        bufp->chgBit(oldp+96,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid));
        bufp->chgBit(oldp+97,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
        bufp->chgCData(oldp+98,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr),4);
        bufp->chgBit(oldp+99,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid));
        bufp->chgBit(oldp+100,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready));
        bufp->chgIData(oldp+101,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data),32);
        bufp->chgBit(oldp+102,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)))));
        bufp->chgBit(oldp+103,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)))));
        bufp->chgBit(oldp+104,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                      >> 3U))));
        bufp->chgBit(oldp+105,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                      >> 3U))));
        bufp->chgCData(oldp+106,(vlSelf->top__DOT__u_uart_top__DOT__tx_state),2);
        bufp->chgCData(oldp+107,(vlSelf->top__DOT__u_uart_top__DOT__state),3);
        bufp->chgIData(oldp+108,(vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum),32);
        bufp->chgCData(oldp+109,(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count),5);
        bufp->chgCData(oldp+110,(vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed),5);
        bufp->chgCData(oldp+111,(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx),5);
        bufp->chgBit(oldp+112,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n));
        bufp->chgCData(oldp+113,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr) 
                                        >> 2U))),2);
        bufp->chgBit(oldp+114,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready));
        bufp->chgCData(oldp+115,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr) 
                                        >> 2U))),2);
        bufp->chgBit(oldp+116,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy));
        bufp->chgIData(oldp+117,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup),31);
        bufp->chgBit(oldp+118,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb));
        bufp->chgBit(oldp+119,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break));
        bufp->chgBit(oldp+120,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr));
        bufp->chgBit(oldp+121,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr));
        bufp->chgBit(oldp+122,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart));
        bufp->chgCData(oldp+123,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data),8);
        bufp->chgBit(oldp+124,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
        bufp->chgBit(oldp+125,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                                & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb))));
        bufp->chgCData(oldp+126,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                                   ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                                   : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data))),8);
        bufp->chgSData(oldp+127,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status),16);
        bufp->chgBit(oldp+128,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
        bufp->chgBit(oldp+129,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr));
        bufp->chgBit(oldp+130,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr));
        bufp->chgIData(oldp+131,(((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
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
        bufp->chgBit(oldp+132,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)))));
        bufp->chgBit(oldp+133,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                                & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write))));
        bufp->chgBit(oldp+134,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break));
        bufp->chgCData(oldp+135,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc)
                                   ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write)
                                   : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data))),8);
        bufp->chgSData(oldp+136,((0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                              << 2U) 
                                             | (IData)(vlSelf->__VdfgTmp_h61863ee6__0)))),16);
        bufp->chgBit(oldp+137,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write));
        bufp->chgBit(oldp+138,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
        bufp->chgCData(oldp+139,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data),8);
        bufp->chgIData(oldp+140,((0x40000000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                                  << 0x12U) 
                                                 | (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                                                     << 0x10U) 
                                                    | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status))))),32);
        bufp->chgCData(oldp+141,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr),2);
        bufp->chgBit(oldp+142,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread));
        bufp->chgIData(oldp+143,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup),32);
        bufp->chgIData(oldp+144,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)),24);
        bufp->chgIData(oldp+145,((0xffffffU & ((0x7fffffU 
                                                & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                   >> 1U)) 
                                               - (IData)(1U)))),24);
        bufp->chgCData(oldp+146,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                        >> 0x1cU))),2);
        bufp->chgBit(oldp+147,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+148,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x18U))));
        bufp->chgBit(oldp+149,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+150,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                      >> 0x19U))));
        bufp->chgIData(oldp+151,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup),30);
        bufp->chgCData(oldp+152,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state),4);
        bufp->chgIData(oldp+153,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter),24);
        bufp->chgBit(oldp+154,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter));
        bufp->chgBit(oldp+155,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart));
        bufp->chgBit(oldp+156,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart));
        bufp->chgIData(oldp+157,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter),28);
        bufp->chgIData(oldp+158,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                << 4U))),28);
        bufp->chgBit(oldp+159,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch));
        bufp->chgBit(oldp+160,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time));
        bufp->chgCData(oldp+161,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg),8);
        bufp->chgBit(oldp+162,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity));
        bufp->chgBit(oldp+163,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr));
        bufp->chgCData(oldp+164,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[0]),8);
        bufp->chgCData(oldp+165,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[1]),8);
        bufp->chgCData(oldp+166,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[2]),8);
        bufp->chgCData(oldp+167,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[3]),8);
        bufp->chgCData(oldp+168,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[4]),8);
        bufp->chgCData(oldp+169,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[5]),8);
        bufp->chgCData(oldp+170,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[6]),8);
        bufp->chgCData(oldp+171,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[7]),8);
        bufp->chgCData(oldp+172,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[8]),8);
        bufp->chgCData(oldp+173,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[9]),8);
        bufp->chgCData(oldp+174,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[10]),8);
        bufp->chgCData(oldp+175,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[11]),8);
        bufp->chgCData(oldp+176,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[12]),8);
        bufp->chgCData(oldp+177,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[13]),8);
        bufp->chgCData(oldp+178,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[14]),8);
        bufp->chgCData(oldp+179,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[15]),8);
        bufp->chgCData(oldp+180,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data),8);
        bufp->chgCData(oldp+181,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write),8);
        bufp->chgCData(oldp+182,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr),4);
        bufp->chgCData(oldp+183,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr),4);
        bufp->chgCData(oldp+184,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next),4);
        bufp->chgBit(oldp+185,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow));
        bufp->chgBit(oldp+186,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow));
        bufp->chgBit(oldp+187,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc));
        bufp->chgCData(oldp+188,((0xfU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
        bufp->chgCData(oldp+189,((0xfU & ((IData)(2U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
        bufp->chgBit(oldp+190,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write));
        bufp->chgBit(oldp+191,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read));
        bufp->chgCData(oldp+192,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill),4);
        bufp->chgSData(oldp+193,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill),10);
        bufp->chgIData(oldp+194,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)),28);
        bufp->chgIData(oldp+195,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                                << 4U))),28);
        bufp->chgCData(oldp+196,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                        >> 0x1cU))),2);
        bufp->chgCData(oldp+197,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                        >> 0x1cU))),2);
        bufp->chgBit(oldp+198,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+199,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x18U))));
        bufp->chgBit(oldp+200,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+201,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x19U))));
        bufp->chgBit(oldp+202,((1U & (~ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                         >> 0x1eU)))));
        bufp->chgBit(oldp+203,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                      >> 0x18U))));
        bufp->chgIData(oldp+204,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup),31);
        bufp->chgIData(oldp+205,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter),28);
        bufp->chgCData(oldp+206,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state),4);
        bufp->chgCData(oldp+207,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data),8);
        bufp->chgBit(oldp+208,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity));
        bufp->chgBit(oldp+209,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter));
        bufp->chgBit(oldp+210,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state));
        bufp->chgBit(oldp+211,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n));
        bufp->chgBit(oldp+212,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n));
        bufp->chgBit(oldp+213,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts));
        bufp->chgBit(oldp+214,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2));
        bufp->chgBit(oldp+215,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
        bufp->chgCData(oldp+216,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[0]),8);
        bufp->chgCData(oldp+217,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[1]),8);
        bufp->chgCData(oldp+218,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[2]),8);
        bufp->chgCData(oldp+219,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[3]),8);
        bufp->chgCData(oldp+220,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[4]),8);
        bufp->chgCData(oldp+221,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[5]),8);
        bufp->chgCData(oldp+222,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[6]),8);
        bufp->chgCData(oldp+223,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[7]),8);
        bufp->chgCData(oldp+224,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[8]),8);
        bufp->chgCData(oldp+225,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[9]),8);
        bufp->chgCData(oldp+226,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[10]),8);
        bufp->chgCData(oldp+227,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[11]),8);
        bufp->chgCData(oldp+228,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[12]),8);
        bufp->chgCData(oldp+229,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[13]),8);
        bufp->chgCData(oldp+230,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[14]),8);
        bufp->chgCData(oldp+231,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[15]),8);
        bufp->chgCData(oldp+232,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data),8);
        bufp->chgCData(oldp+233,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write),8);
        bufp->chgCData(oldp+234,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr),4);
        bufp->chgCData(oldp+235,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr),4);
        bufp->chgCData(oldp+236,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next),4);
        bufp->chgBit(oldp+237,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow));
        bufp->chgBit(oldp+238,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow));
        bufp->chgBit(oldp+239,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc));
        bufp->chgCData(oldp+240,((0xfU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
        bufp->chgCData(oldp+241,((0xfU & ((IData)(2U) 
                                          + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
        bufp->chgBit(oldp+242,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write));
        bufp->chgBit(oldp+243,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read));
        bufp->chgCData(oldp+244,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill),4);
        bufp->chgSData(oldp+245,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill),10);
        bufp->chgBit(oldp+246,(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
        bufp->chgBit(oldp+247,(vlSymsp->TOP__top__DOT__uart_rx_stream.valid));
        bufp->chgCData(oldp+248,(vlSymsp->TOP__top__DOT__uart_rx_stream.data),8);
        bufp->chgBit(oldp+249,(vlSymsp->TOP__top__DOT__uart_rx_stream.ready));
        bufp->chgBit(oldp+250,(vlSymsp->TOP__top__DOT__protocol_rx.valid));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+251,(vlSelf->top__DOT__u_engine__DOT__state));
        bufp->chgBit(oldp+252,(vlSelf->top__DOT__u_engine__DOT__paused_r));
        bufp->chgSData(oldp+253,(vlSelf->top__DOT__u_engine__DOT__poll_cnt),10);
        bufp->chgCData(oldp+254,(vlSelf->top__DOT__u_serialiser__DOT__state),2);
        bufp->chgWData(oldp+255,(vlSelf->top__DOT__u_serialiser__DOT__pkt),528);
        bufp->chgCData(oldp+272,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx),8);
        bufp->chgCData(oldp+273,(vlSelf->top__DOT__u_serialiser__DOT__rem),8);
        bufp->chgCData(oldp+274,(vlSelf->top__DOT__u_test_core__DOT__state),2);
        bufp->chgIData(oldp+275,(vlSelf->top__DOT__u_test_core__DOT__settle_cnt),17);
        bufp->chgCData(oldp+276,(vlSelf->top__DOT__u_test_core__DOT__burst_cnt),4);
        bufp->chgIData(oldp+277,(vlSelf->top__DOT__u_test_core__DOT__gap_cnt),20);
        bufp->chgIData(oldp+278,(vlSelf->top__DOT__u_test_core__DOT__burst_num),32);
        bufp->chgBit(oldp+279,((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state))));
        bufp->chgIData(oldp+280,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_data),32);
        bufp->chgBit(oldp+281,(vlSymsp->TOP__top__DOT__uart_tx_stream.valid));
        bufp->chgCData(oldp+282,(vlSymsp->TOP__top__DOT__uart_tx_stream.data),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgCData(oldp+283,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n),8);
        bufp->chgCData(oldp+284,(vlSelf->top__DOT__u_serialiser__DOT__rem_n),8);
        bufp->chgBit(oldp+285,(vlSelf->top__DOT__u_serialiser__DOT__iter_fire));
    }
    bufp->chgBit(oldp+286,(vlSelf->i_clk));
    bufp->chgBit(oldp+287,(vlSelf->i_reset));
    bufp->chgBit(oldp+288,(vlSelf->i_uart_rx));
    bufp->chgBit(oldp+289,(vlSelf->o_uart_tx));
    bufp->chgBit(oldp+290,(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n));
    bufp->chgBit(oldp+291,(((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state)) 
                            & (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_ready))));
    bufp->chgCData(oldp+292,(vlSelf->top__DOT__u_serialiser__DOT__state_n),2);
    bufp->chgIData(oldp+293,((((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
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
    bufp->chgBit(oldp+294,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2));
    bufp->chgBit(oldp+295,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2));
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
}
