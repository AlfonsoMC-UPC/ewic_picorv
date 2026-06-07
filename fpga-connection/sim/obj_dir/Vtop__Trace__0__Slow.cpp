// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("pkg_sdr_ctrl_protocol", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sdr_core_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("uart_tx_stream", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("uart_rx_stream", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("protocol_tx", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("protocol_rx", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_decoder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+329,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("iter", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+51,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+3,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+312,0,"prot_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
    tracep->declArray(c+4,0,"prot_buf_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
    tracep->declBus(c+52,0,"rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+21,0,"rem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+53,0,"byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+22,0,"byte_idx_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_engine", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+339,0,"READY_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+329,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("req", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("rsp", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+340,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+341,0,"DATA_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+342,0,"PAY_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+23,0,"rsp_is_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"rsp_is_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+215,0,"tx_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+216,0,"have_credit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"in_msg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+218,0,"bytes_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+219,0,"chunk_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+220,0,"byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+221,0,"chunk_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+237,0,"cur_dst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+238,0,"ready_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+27,0,"req_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"tx_msg_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+240,0,"tx_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+241,0,"rx_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+242,0,"rx_payload",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+258,0,"rx_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+259,0,"rx_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+260,0,"rx_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_serialiser", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+329,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("iter", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+343,0,"IterElemSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+261,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+28,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+262,0,"pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
    tracep->declArray(c+29,0,"pkt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
    tracep->declBus(c+279,0,"byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+46,0,"byte_idx_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+280,0,"rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+47,0,"rem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+334,0,"iter_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_test_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+344,0,"SETTLE_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+345,0,"MSG_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+346,0,"GAP_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+340,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+343,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+329,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+341,0,"WORD_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+347,0,"MSG_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1,0,"fpga_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+282,0,"settle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+283,0,"gap_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+284,0,"word_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+285,0,"msg_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_uart_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("to_core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("from_core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+54,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"s_axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+348,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+57,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"s_axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+60,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"s_axi_bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+349,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+62,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"s_axi_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+348,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+65,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axi_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+350,0,"SetupVal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+68,0,"uart_rx_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"uart_tx_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"uart_rxfifo_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"uart_txfifo_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+72,0,"tx_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+73,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+74,0,"rx_data_accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"rx_byte_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+76,0,"rx_bytes_needed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+77,0,"rx_output_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("u_axiluart", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+350,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+351,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+352,0,"HARDWARE_FLOW_CONTROL_PRESENT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+351,0,"LCLLGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+353,0,"C_AXI_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+354,0,"C_AXI_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+355,0,"OPT_SKIDBUFFER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+355,0,"OPT_LOWPOWER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+356,0,"ADDRLSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+329,0,"S_AXI_ACLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"S_AXI_ARESETN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"S_AXI_AWVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"S_AXI_AWREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"S_AXI_AWADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+348,0,"S_AXI_AWPROT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+57,0,"S_AXI_WVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"S_AXI_WREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"S_AXI_WDATA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"S_AXI_WSTRB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+60,0,"S_AXI_BVALID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"S_AXI_BREADY",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+349,0,"S_AXI_BRESP",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+62,0,"S_AXI_ARVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"S_AXI_ARREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"S_AXI_ARADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+348,0,"S_AXI_ARPROT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+65,0,"S_AXI_RVALID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"S_AXI_RREADY",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"S_AXI_RDATA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"S_AXI_RRESP",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+331,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"i_cts_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"o_rts_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"o_uart_rx_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"o_uart_tx_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"o_uart_rxfifo_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"o_uart_txfifo_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"i_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"axil_write_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"awskd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"wskd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"wskd_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+60,0,"axil_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"axil_read_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"arskd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"axil_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"axil_read_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"tx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"uart_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+84,0,"rx_stb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"rx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"rx_perr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"rx_ferr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"ck_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"rx_uart_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+90,0,"rx_uart_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"rx_empty_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"rx_fifo_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"rxf_axil_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"rxf_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+94,0,"rxf_axil_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"r_rx_perr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"r_rx_ferr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+358,0,"check_cutoff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+97,0,"axil_rx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"tx_empty_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"txf_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"tx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"txf_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+103,0,"txf_axil_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"tx_uart_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"txf_axil_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+335,0,"axil_tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"axil_fifo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"r_axil_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+108,0,"r_preread",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"new_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+349,0,"UART_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+359,0,"UART_FIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+360,0,"UART_RXREG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+361,0,"UART_TXREG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+100,0,"r_tx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+362,0,"apply_wstrb__Vstatic__k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+357,0,"unused",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("SIMPLE_READS", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+63,0,"axil_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("SIMPLE_WRITES", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+55,0,"axil_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+350,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+363,0,"RXU_BIT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+364,0,"RXU_BIT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+365,0,"RXU_BIT_TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+366,0,"RXU_BIT_THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+367,0,"RXU_BIT_SEVEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+368,0,"RXU_PARITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+369,0,"RXU_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+370,0,"RXU_SECOND_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+358,0,"RXU_BREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+371,0,"RXU_RESET_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+372,0,"RXU_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"i_setup",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+331,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"o_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+85,0,"o_break",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"o_parity_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"o_frame_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"o_ck_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"clocks_per_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+111,0,"half_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+112,0,"data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+113,0,"use_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"parity_even",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"dblstop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+116,0,"fixd_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+117,0,"r_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+118,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+119,0,"baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+120,0,"zero_baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"q_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"qq_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"ck_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"chg_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+124,0,"break_condition",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBit(c+125,0,"line_synch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"half_baud_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+128,0,"calc_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"pre_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rxfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+373,0,"BW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+352,0,"RXFIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+374,0,"FLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+337,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+68,0,"o_empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"i_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+93,0,"o_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+91,0,"o_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+130+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+146,0,"r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+147,0,"last_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+148,0,"wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+149,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+150,0,"r_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+151,0,"will_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"will_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"osrc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+154,0,"w_waddr_plus_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+155,0,"w_waddr_plus_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+156,0,"w_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"w_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"r_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+351,0,"lglen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+70,0,"w_half_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"w_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->popPrefix();
    tracep->pushPrefix("tx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+350,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+363,0,"TXU_BIT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+364,0,"TXU_BIT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+365,0,"TXU_BIT_TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+366,0,"TXU_BIT_THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+367,0,"TXU_BIT_SEVEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+368,0,"TXU_PARITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+369,0,"TXU_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+370,0,"TXU_SECOND_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+371,0,"TXU_BREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+372,0,"TXU_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+83,0,"i_setup",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+100,0,"i_break",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+357,0,"i_cts_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"o_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"clocks_per_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+161,0,"break_condition",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+162,0,"i_data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+163,0,"data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+164,0,"use_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"parity_odd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"dblstop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+167,0,"fixd_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"fixdp_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"hw_flow_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"i_parity_odd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,0,"r_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+171,0,"baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+172,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+173,0,"lcl_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+174,0,"calc_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"r_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"zero_baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"last_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"q_cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"qq_cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"ck_cts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"unused",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("txfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+373,0,"BW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+351,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+355,0,"RXFIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+374,0,"FLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+329,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+98,0,"o_empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"i_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"o_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+99,0,"o_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+182+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+198,0,"r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+199,0,"last_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+200,0,"wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+201,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+202,0,"r_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+203,0,"will_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"will_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"osrc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"w_waddr_plus_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+207,0,"w_waddr_plus_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+208,0,"w_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"w_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+210,0,"r_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+351,0,"lglen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+71,0,"w_half_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+211,0,"w_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+340,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+343,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+375,0,"TOTAL_LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+286,0,"wr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+287,0,"wr_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"wr_total_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"wr_dst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+289,0,"wr_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"rd_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+377,0,"rd_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+291,0,"rd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+292,0,"rd_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+293,0,"rd_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+343,0,"ITER_ELEM_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+48,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+212,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+343,0,"ITER_ELEM_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+213,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+214,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+378,0,"PAYLOAD_WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+294,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+295,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+378,0,"PAYLOAD_WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+26,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+312,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 535,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+379,0,"BUFFER_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+379,0,"MAX_PAYLOAD_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+339,(0xc350U),32);
    bufp->fullIData(oldp+340,(0x20U),32);
    bufp->fullIData(oldp+341,(4U),32);
    bufp->fullIData(oldp+342,(0x200U),32);
    bufp->fullIData(oldp+343,(8U),32);
    bufp->fullIData(oldp+344,(0x186a0U),32);
    bufp->fullIData(oldp+345,(0xc8U),32);
    bufp->fullIData(oldp+346,(0x927c0U),32);
    bufp->fullIData(oldp+347,(0x32U),32);
    bufp->fullCData(oldp+348,(0U),3);
    bufp->fullCData(oldp+349,(0U),2);
    bufp->fullIData(oldp+350,(0x364U),31);
    bufp->fullCData(oldp+351,(4U),4);
    bufp->fullBit(oldp+352,(1U));
    bufp->fullIData(oldp+353,(4U),32);
    bufp->fullIData(oldp+354,(0x20U),32);
    bufp->fullBit(oldp+355,(0U));
    bufp->fullIData(oldp+356,(2U),32);
    bufp->fullBit(oldp+357,(0U));
    bufp->fullCData(oldp+358,(0xdU),4);
    bufp->fullCData(oldp+359,(1U),2);
    bufp->fullCData(oldp+360,(2U),2);
    bufp->fullCData(oldp+361,(3U),2);
    bufp->fullIData(oldp+362,(4U),32);
    bufp->fullCData(oldp+363,(0U),4);
    bufp->fullCData(oldp+364,(1U),4);
    bufp->fullCData(oldp+365,(2U),4);
    bufp->fullCData(oldp+366,(3U),4);
    bufp->fullCData(oldp+367,(7U),4);
    bufp->fullCData(oldp+368,(8U),4);
    bufp->fullCData(oldp+369,(9U),4);
    bufp->fullCData(oldp+370,(0xaU),4);
    bufp->fullCData(oldp+371,(0xeU),4);
    bufp->fullCData(oldp+372,(0xfU),4);
    bufp->fullIData(oldp+373,(8U),32);
    bufp->fullIData(oldp+374,(0x10U),32);
    bufp->fullIData(oldp+375,(0x10U),32);
    bufp->fullSData(oldp+376,(0xc8U),16);
    bufp->fullBit(oldp+377,(1U));
    bufp->fullIData(oldp+378,(2U),32);
    bufp->fullIData(oldp+379,(0x40U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__u_test_core__DOT__fpga_id),32);
    bufp->fullCData(oldp+2,((0xffU & (1U ^ vlSelf->top__DOT__u_test_core__DOT__fpga_id))),8);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__u_decoder__DOT__state_n),3);
    bufp->fullWData(oldp+4,(vlSelf->top__DOT__u_decoder__DOT__prot_buf_n),536);
    bufp->fullCData(oldp+21,(vlSelf->top__DOT__u_decoder__DOT__rem_n),8);
    bufp->fullCData(oldp+22,(vlSelf->top__DOT__u_decoder__DOT__byte_idx_n),8);
    bufp->fullBit(oldp+23,(vlSelf->top__DOT__u_engine__DOT__rsp_is_ready));
    bufp->fullBit(oldp+24,(vlSelf->top__DOT__u_engine__DOT__rsp_is_data));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__top__DOT__uart_rx_stream.ready));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__top__DOT__protocol_rx.valid));
    bufp->fullBit(oldp+27,(vlSelf->top__DOT__u_engine__DOT__req_fire));
    bufp->fullCData(oldp+28,(vlSelf->top__DOT__u_serialiser__DOT__state_n),3);
    bufp->fullWData(oldp+29,(vlSelf->top__DOT__u_serialiser__DOT__pkt_n),536);
    bufp->fullCData(oldp+46,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n),8);
    bufp->fullCData(oldp+47,(vlSelf->top__DOT__u_serialiser__DOT__rem_n),8);
    bufp->fullBit(oldp+48,(vlSymsp->TOP__top__DOT__uart_tx_stream.valid));
    bufp->fullCData(oldp+49,(vlSymsp->TOP__top__DOT__uart_tx_stream.data),8);
    bufp->fullBit(oldp+50,(vlSymsp->TOP__top__DOT__protocol_tx.ready));
    bufp->fullCData(oldp+51,(vlSelf->top__DOT__u_decoder__DOT__state),3);
    bufp->fullCData(oldp+52,(vlSelf->top__DOT__u_decoder__DOT__rem),8);
    bufp->fullCData(oldp+53,(vlSelf->top__DOT__u_decoder__DOT__byte_idx),8);
    bufp->fullBit(oldp+54,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid));
    bufp->fullBit(oldp+55,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready));
    bufp->fullCData(oldp+56,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr),4);
    bufp->fullBit(oldp+57,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid));
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata),32);
    bufp->fullCData(oldp+59,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb),4);
    bufp->fullBit(oldp+60,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid));
    bufp->fullBit(oldp+61,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready));
    bufp->fullBit(oldp+62,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid));
    bufp->fullBit(oldp+63,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
    bufp->fullCData(oldp+64,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr),4);
    bufp->fullBit(oldp+65,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid));
    bufp->fullBit(oldp+66,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready));
    bufp->fullIData(oldp+67,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data),32);
    bufp->fullBit(oldp+68,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)))));
    bufp->fullBit(oldp+69,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)))));
    bufp->fullBit(oldp+70,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                  >> 3U))));
    bufp->fullBit(oldp+71,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                  >> 3U))));
    bufp->fullCData(oldp+72,(vlSelf->top__DOT__u_uart_top__DOT__tx_state),2);
    bufp->fullCData(oldp+73,(vlSelf->top__DOT__u_uart_top__DOT__state),3);
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum),32);
    bufp->fullCData(oldp+75,(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count),5);
    bufp->fullCData(oldp+76,(vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed),5);
    bufp->fullCData(oldp+77,(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx),5);
    bufp->fullBit(oldp+78,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n));
    bufp->fullCData(oldp+79,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr) 
                                    >> 2U))),2);
    bufp->fullBit(oldp+80,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready));
    bufp->fullCData(oldp+81,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr) 
                                    >> 2U))),2);
    bufp->fullBit(oldp+82,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy));
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup),31);
    bufp->fullBit(oldp+84,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb));
    bufp->fullBit(oldp+85,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break));
    bufp->fullBit(oldp+86,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr));
    bufp->fullBit(oldp+87,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr));
    bufp->fullBit(oldp+88,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart));
    bufp->fullCData(oldp+89,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data),8);
    bufp->fullBit(oldp+90,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
    bufp->fullBit(oldp+91,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                            & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb))));
    bufp->fullCData(oldp+92,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                               ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                               : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data))),8);
    bufp->fullSData(oldp+93,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status),16);
    bufp->fullBit(oldp+94,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
    bufp->fullBit(oldp+95,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr));
    bufp->fullBit(oldp+96,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr));
    bufp->fullIData(oldp+97,(((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
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
    bufp->fullBit(oldp+98,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)))));
    bufp->fullBit(oldp+99,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                            & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write))));
    bufp->fullBit(oldp+100,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break));
    bufp->fullCData(oldp+101,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc)
                                ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write)
                                : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data))),8);
    bufp->fullSData(oldp+102,((0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                           << 2U) | (IData)(vlSelf->__VdfgTmp_h61863ee6__0)))),16);
    bufp->fullBit(oldp+103,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write));
    bufp->fullBit(oldp+104,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
    bufp->fullCData(oldp+105,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data),8);
    bufp->fullIData(oldp+106,((0x40000000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                               << 0x12U) 
                                              | (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                                                  << 0x10U) 
                                                 | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status))))),32);
    bufp->fullCData(oldp+107,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr),2);
    bufp->fullBit(oldp+108,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread));
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup),32);
    bufp->fullIData(oldp+110,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)),24);
    bufp->fullIData(oldp+111,((0xffffffU & ((0x7fffffU 
                                             & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                >> 1U)) 
                                            - (IData)(1U)))),24);
    bufp->fullCData(oldp+112,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                     >> 0x1cU))),2);
    bufp->fullBit(oldp+113,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x1aU))));
    bufp->fullBit(oldp+114,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x18U))));
    bufp->fullBit(oldp+115,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x1bU))));
    bufp->fullBit(oldp+116,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x19U))));
    bufp->fullIData(oldp+117,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup),30);
    bufp->fullCData(oldp+118,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state),4);
    bufp->fullIData(oldp+119,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter),24);
    bufp->fullBit(oldp+120,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter));
    bufp->fullBit(oldp+121,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart));
    bufp->fullIData(oldp+123,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter),28);
    bufp->fullIData(oldp+124,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                             << 4U))),28);
    bufp->fullBit(oldp+125,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch));
    bufp->fullBit(oldp+126,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time));
    bufp->fullCData(oldp+127,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg),8);
    bufp->fullBit(oldp+128,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity));
    bufp->fullBit(oldp+129,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr));
    bufp->fullCData(oldp+130,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[0]),8);
    bufp->fullCData(oldp+131,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[1]),8);
    bufp->fullCData(oldp+132,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[2]),8);
    bufp->fullCData(oldp+133,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[3]),8);
    bufp->fullCData(oldp+134,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[4]),8);
    bufp->fullCData(oldp+135,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[5]),8);
    bufp->fullCData(oldp+136,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[6]),8);
    bufp->fullCData(oldp+137,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[7]),8);
    bufp->fullCData(oldp+138,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[8]),8);
    bufp->fullCData(oldp+139,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[9]),8);
    bufp->fullCData(oldp+140,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[10]),8);
    bufp->fullCData(oldp+141,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[11]),8);
    bufp->fullCData(oldp+142,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[12]),8);
    bufp->fullCData(oldp+143,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[13]),8);
    bufp->fullCData(oldp+144,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[14]),8);
    bufp->fullCData(oldp+145,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[15]),8);
    bufp->fullCData(oldp+146,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data),8);
    bufp->fullCData(oldp+147,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write),8);
    bufp->fullCData(oldp+148,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr),4);
    bufp->fullCData(oldp+149,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr),4);
    bufp->fullCData(oldp+150,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next),4);
    bufp->fullBit(oldp+151,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow));
    bufp->fullBit(oldp+152,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow));
    bufp->fullBit(oldp+153,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc));
    bufp->fullCData(oldp+154,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
    bufp->fullCData(oldp+155,((0xfU & ((IData)(2U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
    bufp->fullBit(oldp+156,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write));
    bufp->fullBit(oldp+157,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read));
    bufp->fullCData(oldp+158,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill),4);
    bufp->fullSData(oldp+159,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill),10);
    bufp->fullIData(oldp+160,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)),28);
    bufp->fullIData(oldp+161,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                             << 4U))),28);
    bufp->fullCData(oldp+162,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                     >> 0x1cU))),2);
    bufp->fullCData(oldp+163,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                     >> 0x1cU))),2);
    bufp->fullBit(oldp+164,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x1aU))));
    bufp->fullBit(oldp+165,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x18U))));
    bufp->fullBit(oldp+166,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x1bU))));
    bufp->fullBit(oldp+167,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x19U))));
    bufp->fullBit(oldp+168,((1U & (~ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1eU)))));
    bufp->fullBit(oldp+169,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                   >> 0x18U))));
    bufp->fullIData(oldp+170,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup),31);
    bufp->fullIData(oldp+171,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter),28);
    bufp->fullCData(oldp+172,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state),4);
    bufp->fullCData(oldp+173,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data),8);
    bufp->fullBit(oldp+174,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity));
    bufp->fullBit(oldp+175,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter));
    bufp->fullBit(oldp+176,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state));
    bufp->fullBit(oldp+177,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n));
    bufp->fullBit(oldp+178,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n));
    bufp->fullBit(oldp+179,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts));
    bufp->fullBit(oldp+180,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2));
    bufp->fullBit(oldp+181,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
    bufp->fullCData(oldp+182,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[0]),8);
    bufp->fullCData(oldp+183,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[1]),8);
    bufp->fullCData(oldp+184,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[2]),8);
    bufp->fullCData(oldp+185,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[3]),8);
    bufp->fullCData(oldp+186,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[4]),8);
    bufp->fullCData(oldp+187,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[5]),8);
    bufp->fullCData(oldp+188,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[6]),8);
    bufp->fullCData(oldp+189,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[7]),8);
    bufp->fullCData(oldp+190,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[8]),8);
    bufp->fullCData(oldp+191,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[9]),8);
    bufp->fullCData(oldp+192,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[10]),8);
    bufp->fullCData(oldp+193,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[11]),8);
    bufp->fullCData(oldp+194,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[12]),8);
    bufp->fullCData(oldp+195,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[13]),8);
    bufp->fullCData(oldp+196,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[14]),8);
    bufp->fullCData(oldp+197,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[15]),8);
    bufp->fullCData(oldp+198,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data),8);
    bufp->fullCData(oldp+199,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write),8);
    bufp->fullCData(oldp+200,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr),4);
    bufp->fullCData(oldp+201,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr),4);
    bufp->fullCData(oldp+202,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next),4);
    bufp->fullBit(oldp+203,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow));
    bufp->fullBit(oldp+204,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow));
    bufp->fullBit(oldp+205,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc));
    bufp->fullCData(oldp+206,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
    bufp->fullCData(oldp+207,((0xfU & ((IData)(2U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
    bufp->fullBit(oldp+208,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write));
    bufp->fullBit(oldp+209,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read));
    bufp->fullCData(oldp+210,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill),4);
    bufp->fullSData(oldp+211,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill),10);
    bufp->fullBit(oldp+212,(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
    bufp->fullBit(oldp+213,(vlSymsp->TOP__top__DOT__uart_rx_stream.valid));
    bufp->fullCData(oldp+214,(vlSymsp->TOP__top__DOT__uart_rx_stream.data),8);
    bufp->fullCData(oldp+215,(vlSelf->top__DOT__u_engine__DOT__tx_state),2);
    bufp->fullBit(oldp+216,(vlSelf->top__DOT__u_engine__DOT__have_credit));
    bufp->fullBit(oldp+217,(vlSelf->top__DOT__u_engine__DOT__in_msg));
    bufp->fullSData(oldp+218,(vlSelf->top__DOT__u_engine__DOT__bytes_left),16);
    bufp->fullCData(oldp+219,(vlSelf->top__DOT__u_engine__DOT__chunk_len),8);
    bufp->fullCData(oldp+220,(vlSelf->top__DOT__u_engine__DOT__byte_idx),8);
    bufp->fullWData(oldp+221,(vlSelf->top__DOT__u_engine__DOT__chunk_buf),512);
    bufp->fullCData(oldp+237,(vlSelf->top__DOT__u_engine__DOT__cur_dst),8);
    bufp->fullSData(oldp+238,(vlSelf->top__DOT__u_engine__DOT__ready_cnt),16);
    bufp->fullBit(oldp+239,(((IData)(vlSelf->top__DOT__u_engine__DOT__in_msg) 
                             | (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid))));
    bufp->fullSData(oldp+240,(vlSelf->top__DOT__u_engine__DOT__tx_left),16);
    bufp->fullBit(oldp+241,(vlSelf->top__DOT__u_engine__DOT__rx_state));
    bufp->fullWData(oldp+242,(vlSelf->top__DOT__u_engine__DOT__rx_payload),512);
    bufp->fullCData(oldp+258,(vlSelf->top__DOT__u_engine__DOT__rx_len),8);
    bufp->fullCData(oldp+259,(vlSelf->top__DOT__u_engine__DOT__rx_idx),8);
    bufp->fullCData(oldp+260,(vlSelf->top__DOT__u_engine__DOT__rx_rem),8);
    bufp->fullCData(oldp+261,(vlSelf->top__DOT__u_serialiser__DOT__state),3);
    bufp->fullWData(oldp+262,(vlSelf->top__DOT__u_serialiser__DOT__pkt),536);
    bufp->fullCData(oldp+279,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx),8);
    bufp->fullCData(oldp+280,(vlSelf->top__DOT__u_serialiser__DOT__rem),8);
    bufp->fullCData(oldp+281,(vlSelf->top__DOT__u_test_core__DOT__state),2);
    bufp->fullIData(oldp+282,(vlSelf->top__DOT__u_test_core__DOT__settle_cnt),17);
    bufp->fullIData(oldp+283,(vlSelf->top__DOT__u_test_core__DOT__gap_cnt),20);
    bufp->fullSData(oldp+284,(vlSelf->top__DOT__u_test_core__DOT__word_idx),16);
    bufp->fullIData(oldp+285,(vlSelf->top__DOT__u_test_core__DOT__msg_num),32);
    bufp->fullBit(oldp+286,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_valid));
    bufp->fullBit(oldp+287,((2U == (IData)(vlSelf->top__DOT__u_engine__DOT__tx_state))));
    bufp->fullIData(oldp+288,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_data),32);
    bufp->fullBit(oldp+289,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_done));
    bufp->fullBit(oldp+290,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid));
    bufp->fullIData(oldp+291,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_data),32);
    bufp->fullCData(oldp+292,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_len),8);
    bufp->fullBit(oldp+293,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_last));
    bufp->fullBit(oldp+294,(vlSymsp->TOP__top__DOT__protocol_tx.valid));
    bufp->fullWData(oldp+295,(vlSymsp->TOP__top__DOT__protocol_tx.data),536);
    bufp->fullWData(oldp+312,(vlSelf->top__DOT__u_decoder__DOT__prot_buf),536);
    bufp->fullBit(oldp+329,(vlSelf->i_clk));
    bufp->fullBit(oldp+330,(vlSelf->i_reset));
    bufp->fullBit(oldp+331,(vlSelf->i_uart_rx));
    bufp->fullBit(oldp+332,(vlSelf->o_uart_tx));
    bufp->fullBit(oldp+333,(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n));
    bufp->fullBit(oldp+334,(vlSelf->top__DOT__u_serialiser__DOT__iter_fire));
    bufp->fullIData(oldp+335,((((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
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
    bufp->fullBit(oldp+336,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2));
    bufp->fullBit(oldp+337,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2));
    bufp->fullBit(oldp+338,(vlSymsp->TOP__top__DOT__protocol_rx.ready));
}
