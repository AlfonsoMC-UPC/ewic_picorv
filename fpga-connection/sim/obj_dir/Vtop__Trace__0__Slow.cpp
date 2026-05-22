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
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->declBit(c+287,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("iter", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+49,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+2,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+50,0,"prot_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
    tracep->declArray(c+67,0,"prot_buf_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
    tracep->declBus(c+84,0,"rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+85,0,"rem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+86,0,"byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+87,0,"byte_idx_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_engine", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+297,0,"POLL_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+287,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("req", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("rsp", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+252,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"paused_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"paused_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+254,0,"poll_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+5,0,"poll_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+6,0,"rsp_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"req_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"core_wr_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"rsp_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_serialiser", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+287,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("iter", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+298,0,"IterElemSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+255,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+293,0,"state_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+256,0,"pkt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
    tracep->declArray(c+8,0,"pkt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
    tracep->declBus(c+273,0,"byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+284,0,"byte_idx_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+274,0,"rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+285,0,"rem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+286,0,"iter_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_test_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+299,0,"SETTLE_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+298,0,"TX_BURSTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+300,0,"GAP_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+301,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+298,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+287,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__sdr_core_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+1,0,"fpga_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+275,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+276,0,"settle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+277,0,"burst_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+278,0,"gap_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 19,0);
    tracep->declBus(c+279,0,"burst_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_uart_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("to_core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("from_core", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+89,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"s_axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+302,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+92,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"s_axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"s_axi_bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+303,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+97,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"s_axi_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+302,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"s_axi_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+304,0,"SetupVal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+103,0,"uart_rx_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"uart_tx_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"uart_rxfifo_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"uart_txfifo_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"tx_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+108,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+109,0,"rx_data_accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"rx_byte_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+111,0,"rx_bytes_needed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+112,0,"rx_output_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("u_axiluart", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+304,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+305,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+306,0,"HARDWARE_FLOW_CONTROL_PRESENT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+305,0,"LCLLGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"C_AXI_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"C_AXI_DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+309,0,"OPT_SKIDBUFFER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+309,0,"OPT_LOWPOWER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+310,0,"ADDRLSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+287,0,"S_AXI_ACLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"S_AXI_ARESETN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"S_AXI_AWVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"S_AXI_AWREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"S_AXI_AWADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+302,0,"S_AXI_AWPROT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+92,0,"S_AXI_WVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"S_AXI_WREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"S_AXI_WDATA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"S_AXI_WSTRB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"S_AXI_BVALID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"S_AXI_BREADY",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+303,0,"S_AXI_BRESP",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+97,0,"S_AXI_ARVALID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"S_AXI_ARREADY",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+99,0,"S_AXI_ARADDR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+302,0,"S_AXI_ARPROT",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"S_AXI_RVALID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"S_AXI_RREADY",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"S_AXI_RDATA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"S_AXI_RRESP",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+289,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"i_cts_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"o_rts_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"o_uart_rx_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"o_uart_tx_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"o_uart_rxfifo_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"o_uart_txfifo_int",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+288,0,"i_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"axil_write_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+114,0,"awskd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+93,0,"wskd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"wskd_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+95,0,"axil_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"axil_read_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+116,0,"arskd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+102,0,"axil_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"axil_read_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"tx_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"uart_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+119,0,"rx_stb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"rx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"rx_perr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"rx_ferr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"ck_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"rx_uart_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+125,0,"rx_uart_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"rx_empty_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rx_fifo_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"rxf_axil_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+128,0,"rxf_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+129,0,"rxf_axil_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"r_rx_perr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"r_rx_ferr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+312,0,"check_cutoff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+132,0,"axil_rx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+133,0,"tx_empty_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"txf_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"tx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"txf_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+138,0,"txf_axil_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"tx_uart_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"txf_axil_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+294,0,"axil_tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"axil_fifo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"r_axil_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+143,0,"r_preread",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"new_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"UART_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+313,0,"UART_FIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+314,0,"UART_RXREG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+315,0,"UART_TXREG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+135,0,"r_tx_break",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+316,0,"apply_wstrb__Vstatic__k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+311,0,"unused",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("SIMPLE_READS", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+98,0,"axil_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("SIMPLE_WRITES", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+90,0,"axil_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+304,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+317,0,"RXU_BIT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+318,0,"RXU_BIT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+319,0,"RXU_BIT_TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+320,0,"RXU_BIT_THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+321,0,"RXU_BIT_SEVEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+322,0,"RXU_PARITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+323,0,"RXU_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+324,0,"RXU_SECOND_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+312,0,"RXU_BREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+325,0,"RXU_RESET_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+326,0,"RXU_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+295,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"i_setup",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+289,0,"i_uart_rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"o_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+120,0,"o_break",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"o_parity_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"o_frame_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"o_ck_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+145,0,"clocks_per_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+146,0,"half_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+147,0,"data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+148,0,"use_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"parity_even",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"dblstop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"fixd_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"r_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+153,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+154,0,"baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+155,0,"zero_baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"q_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"qq_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"ck_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"chg_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+159,0,"break_condition",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBit(c+160,0,"line_synch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+161,0,"half_baud_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+162,0,"data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+163,0,"calc_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+164,0,"pre_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rxfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+327,0,"BW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+305,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+306,0,"RXFIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+328,0,"FLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+296,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+103,0,"o_empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"i_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+128,0,"o_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+126,0,"o_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+165+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+181,0,"r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+182,0,"last_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+183,0,"wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+184,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+185,0,"r_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+186,0,"will_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"will_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"osrc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+189,0,"w_waddr_plus_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+190,0,"w_waddr_plus_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+191,0,"w_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"w_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"r_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+305,0,"lglen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+105,0,"w_half_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+194,0,"w_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->popPrefix();
    tracep->pushPrefix("tx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+304,0,"INITIAL_SETUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+317,0,"TXU_BIT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+318,0,"TXU_BIT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+319,0,"TXU_BIT_TWO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+320,0,"TXU_BIT_THREE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+321,0,"TXU_BIT_SEVEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+322,0,"TXU_PARITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+323,0,"TXU_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+324,0,"TXU_SECOND_STOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+325,0,"TXU_BREAK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+326,0,"TXU_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"i_setup",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBit(c+135,0,"i_break",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+311,0,"i_cts_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"o_uart_tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"o_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"clocks_per_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+196,0,"break_condition",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+197,0,"i_data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+198,0,"data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+199,0,"use_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"parity_odd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"dblstop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"fixd_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"fixdp_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"hw_flow_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"i_parity_odd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"r_setup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 30,0);
    tracep->declBus(c+206,0,"baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+207,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+208,0,"lcl_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+209,0,"calc_parity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"r_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"zero_baud_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"last_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"q_cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"qq_cts_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"ck_cts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"unused",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("txfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+327,0,"BW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+305,0,"LGFLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+309,0,"RXFIFO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+328,0,"FLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+287,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"i_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+133,0,"o_empty_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"i_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"o_status",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+134,0,"o_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+217+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+233,0,"r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"last_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+235,0,"wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+236,0,"rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+237,0,"r_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+238,0,"will_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"will_underflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"osrc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"w_waddr_plus_one",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+242,0,"w_waddr_plus_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+243,0,"w_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"w_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+245,0,"r_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+305,0,"lglen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+106,0,"w_half_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"w_fill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
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
    tracep->declBus(c+301,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+298,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+280,0,"wr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"wr_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+281,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+329,0,"wr_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+26,0,"rd_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"rd_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"rd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"rd_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_tx_stream__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+298,0,"ITER_ELEM_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+282,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+247,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__uart_rx_stream__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+298,0,"ITER_ELEM_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+248,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+249,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+250,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_tx__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+331,0,"PAYLOAD_WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+29,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+31,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__protocol_rx__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+331,0,"PAYLOAD_WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+251,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+50,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 527,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__pkg_sdr_ctrl_protocol__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+332,0,"MAX_PAYLOAD_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    bufp->fullIData(oldp+297,(0x3e8U),32);
    bufp->fullIData(oldp+298,(8U),32);
    bufp->fullIData(oldp+299,(0x186a0U),32);
    bufp->fullIData(oldp+300,(0x927c0U),32);
    bufp->fullIData(oldp+301,(0x20U),32);
    bufp->fullCData(oldp+302,(0U),3);
    bufp->fullCData(oldp+303,(0U),2);
    bufp->fullIData(oldp+304,(0x364U),31);
    bufp->fullCData(oldp+305,(4U),4);
    bufp->fullBit(oldp+306,(1U));
    bufp->fullIData(oldp+307,(4U),32);
    bufp->fullIData(oldp+308,(0x20U),32);
    bufp->fullBit(oldp+309,(0U));
    bufp->fullIData(oldp+310,(2U),32);
    bufp->fullBit(oldp+311,(0U));
    bufp->fullCData(oldp+312,(0xdU),4);
    bufp->fullCData(oldp+313,(1U),2);
    bufp->fullCData(oldp+314,(2U),2);
    bufp->fullCData(oldp+315,(3U),2);
    bufp->fullIData(oldp+316,(4U),32);
    bufp->fullCData(oldp+317,(0U),4);
    bufp->fullCData(oldp+318,(1U),4);
    bufp->fullCData(oldp+319,(2U),4);
    bufp->fullCData(oldp+320,(3U),4);
    bufp->fullCData(oldp+321,(7U),4);
    bufp->fullCData(oldp+322,(8U),4);
    bufp->fullCData(oldp+323,(9U),4);
    bufp->fullCData(oldp+324,(0xaU),4);
    bufp->fullCData(oldp+325,(0xeU),4);
    bufp->fullCData(oldp+326,(0xfU),4);
    bufp->fullIData(oldp+327,(8U),32);
    bufp->fullIData(oldp+328,(0x10U),32);
    bufp->fullCData(oldp+329,(4U),8);
    bufp->fullBit(oldp+330,(1U));
    bufp->fullIData(oldp+331,(2U),32);
    bufp->fullIData(oldp+332,(0x40U),32);
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
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__u_decoder__DOT__state_n),2);
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__u_engine__DOT__state_n));
    bufp->fullBit(oldp+4,(vlSelf->top__DOT__u_engine__DOT__paused_n));
    bufp->fullSData(oldp+5,(vlSelf->top__DOT__u_engine__DOT__poll_cnt_n),10);
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__u_engine__DOT__rsp_fire));
    bufp->fullBit(oldp+7,(((IData)(vlSymsp->TOP__top__DOT__protocol_tx.valid) 
                           & (IData)(vlSymsp->TOP__top__DOT__protocol_tx.ready))));
    bufp->fullWData(oldp+8,(vlSelf->top__DOT__u_serialiser__DOT__pkt_n),528);
    bufp->fullBit(oldp+25,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_ready));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_valid));
    bufp->fullIData(oldp+27,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_data),32);
    bufp->fullCData(oldp+28,(vlSymsp->TOP__top__DOT__sdr_core_if.rd_len),8);
    bufp->fullBit(oldp+29,(vlSymsp->TOP__top__DOT__protocol_tx.valid));
    bufp->fullBit(oldp+30,(vlSymsp->TOP__top__DOT__protocol_tx.ready));
    bufp->fullWData(oldp+31,(vlSymsp->TOP__top__DOT__protocol_tx.data),528);
    bufp->fullBit(oldp+48,(vlSymsp->TOP__top__DOT__protocol_rx.ready));
    bufp->fullCData(oldp+49,(vlSelf->top__DOT__u_decoder__DOT__state),2);
    bufp->fullWData(oldp+50,(vlSelf->top__DOT__u_decoder__DOT__prot_buf),528);
    bufp->fullWData(oldp+67,(vlSelf->top__DOT__u_decoder__DOT__prot_buf_n),528);
    bufp->fullCData(oldp+84,(vlSelf->top__DOT__u_decoder__DOT__rem),8);
    bufp->fullCData(oldp+85,(vlSelf->top__DOT__u_decoder__DOT__rem_n),8);
    bufp->fullCData(oldp+86,(vlSelf->top__DOT__u_decoder__DOT__byte_idx),8);
    bufp->fullCData(oldp+87,(vlSelf->top__DOT__u_decoder__DOT__byte_idx_n),8);
    bufp->fullCData(oldp+88,((0xffU & (vlSelf->top__DOT__u_decoder__DOT__prot_buf[0x10U] 
                                       >> 8U))),8);
    bufp->fullBit(oldp+89,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awvalid));
    bufp->fullBit(oldp+90,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready));
    bufp->fullCData(oldp+91,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr),4);
    bufp->fullBit(oldp+92,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wvalid));
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wdata),32);
    bufp->fullCData(oldp+94,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_wstrb),4);
    bufp->fullBit(oldp+95,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid));
    bufp->fullBit(oldp+96,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_bready));
    bufp->fullBit(oldp+97,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_arvalid));
    bufp->fullBit(oldp+98,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready));
    bufp->fullCData(oldp+99,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr),4);
    bufp->fullBit(oldp+100,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid));
    bufp->fullBit(oldp+101,(vlSelf->top__DOT__u_uart_top__DOT__s_axi_rready));
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data),32);
    bufp->fullBit(oldp+103,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow)))));
    bufp->fullBit(oldp+104,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow)))));
    bufp->fullBit(oldp+105,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill) 
                                   >> 3U))));
    bufp->fullBit(oldp+106,((1U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill) 
                                   >> 3U))));
    bufp->fullCData(oldp+107,(vlSelf->top__DOT__u_uart_top__DOT__tx_state),2);
    bufp->fullCData(oldp+108,(vlSelf->top__DOT__u_uart_top__DOT__state),3);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__u_uart_top__DOT__rx_data_accum),32);
    bufp->fullCData(oldp+110,(vlSelf->top__DOT__u_uart_top__DOT__rx_byte_count),5);
    bufp->fullCData(oldp+111,(vlSelf->top__DOT__u_uart_top__DOT__rx_bytes_needed),5);
    bufp->fullCData(oldp+112,(vlSelf->top__DOT__u_uart_top__DOT__rx_output_idx),5);
    bufp->fullBit(oldp+113,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n));
    bufp->fullCData(oldp+114,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_awaddr) 
                                     >> 2U))),2);
    bufp->fullBit(oldp+115,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready));
    bufp->fullCData(oldp+116,((3U & ((IData)(vlSelf->top__DOT__u_uart_top__DOT__s_axi_araddr) 
                                     >> 2U))),2);
    bufp->fullBit(oldp+117,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy));
    bufp->fullIData(oldp+118,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup),31);
    bufp->fullBit(oldp+119,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb));
    bufp->fullBit(oldp+120,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break));
    bufp->fullBit(oldp+121,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr));
    bufp->fullBit(oldp+122,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr));
    bufp->fullBit(oldp+123,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart));
    bufp->fullCData(oldp+124,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data),8);
    bufp->fullBit(oldp+125,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset));
    bufp->fullBit(oldp+126,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
                             & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb))));
    bufp->fullCData(oldp+127,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc)
                                ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write)
                                : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data))),8);
    bufp->fullSData(oldp+128,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status),16);
    bufp->fullBit(oldp+129,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read));
    bufp->fullBit(oldp+130,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr));
    bufp->fullBit(oldp+131,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr));
    bufp->fullIData(oldp+132,(((((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write)) 
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
    bufp->fullBit(oldp+133,((1U & (~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow)))));
    bufp->fullBit(oldp+134,(((~ (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write)) 
                             & (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write))));
    bufp->fullBit(oldp+135,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break));
    bufp->fullCData(oldp+136,(((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc)
                                ? (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write)
                                : (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data))),8);
    bufp->fullSData(oldp+137,((0x4000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                           << 2U) | (IData)(vlSelf->__VdfgTmp_h61863ee6__0)))),16);
    bufp->fullBit(oldp+138,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write));
    bufp->fullBit(oldp+139,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset));
    bufp->fullCData(oldp+140,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data),8);
    bufp->fullIData(oldp+141,((0x40000000U | (((IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill) 
                                               << 0x12U) 
                                              | (((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
                                                  << 0x10U) 
                                                 | (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status))))),32);
    bufp->fullCData(oldp+142,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr),2);
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread));
    bufp->fullIData(oldp+144,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup),32);
    bufp->fullIData(oldp+145,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup)),24);
    bufp->fullIData(oldp+146,((0xffffffU & ((0x7fffffU 
                                             & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                                >> 1U)) 
                                            - (IData)(1U)))),24);
    bufp->fullCData(oldp+147,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                     >> 0x1cU))),2);
    bufp->fullBit(oldp+148,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x1aU))));
    bufp->fullBit(oldp+149,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x18U))));
    bufp->fullBit(oldp+150,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x1bU))));
    bufp->fullBit(oldp+151,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                   >> 0x19U))));
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup),30);
    bufp->fullCData(oldp+153,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state),4);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter),24);
    bufp->fullBit(oldp+155,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter));
    bufp->fullBit(oldp+156,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart));
    bufp->fullBit(oldp+157,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart));
    bufp->fullIData(oldp+158,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter),28);
    bufp->fullIData(oldp+159,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup 
                                             << 4U))),28);
    bufp->fullBit(oldp+160,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch));
    bufp->fullBit(oldp+161,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time));
    bufp->fullCData(oldp+162,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg),8);
    bufp->fullBit(oldp+163,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity));
    bufp->fullBit(oldp+164,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr));
    bufp->fullCData(oldp+165,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[0]),8);
    bufp->fullCData(oldp+166,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[1]),8);
    bufp->fullCData(oldp+167,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[2]),8);
    bufp->fullCData(oldp+168,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[3]),8);
    bufp->fullCData(oldp+169,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[4]),8);
    bufp->fullCData(oldp+170,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[5]),8);
    bufp->fullCData(oldp+171,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[6]),8);
    bufp->fullCData(oldp+172,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[7]),8);
    bufp->fullCData(oldp+173,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[8]),8);
    bufp->fullCData(oldp+174,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[9]),8);
    bufp->fullCData(oldp+175,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[10]),8);
    bufp->fullCData(oldp+176,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[11]),8);
    bufp->fullCData(oldp+177,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[12]),8);
    bufp->fullCData(oldp+178,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[13]),8);
    bufp->fullCData(oldp+179,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[14]),8);
    bufp->fullCData(oldp+180,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo[15]),8);
    bufp->fullCData(oldp+181,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data),8);
    bufp->fullCData(oldp+182,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write),8);
    bufp->fullCData(oldp+183,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr),4);
    bufp->fullCData(oldp+184,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr),4);
    bufp->fullCData(oldp+185,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next),4);
    bufp->fullBit(oldp+186,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow));
    bufp->fullBit(oldp+187,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow));
    bufp->fullBit(oldp+188,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc));
    bufp->fullCData(oldp+189,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
    bufp->fullCData(oldp+190,((0xfU & ((IData)(2U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr)))),4);
    bufp->fullBit(oldp+191,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write));
    bufp->fullBit(oldp+192,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read));
    bufp->fullCData(oldp+193,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill),4);
    bufp->fullSData(oldp+194,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill),10);
    bufp->fullIData(oldp+195,((0xffffffU & vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup)),28);
    bufp->fullIData(oldp+196,((0xffffff0U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                             << 4U))),28);
    bufp->fullCData(oldp+197,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                     >> 0x1cU))),2);
    bufp->fullCData(oldp+198,((3U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                     >> 0x1cU))),2);
    bufp->fullBit(oldp+199,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x1aU))));
    bufp->fullBit(oldp+200,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x18U))));
    bufp->fullBit(oldp+201,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x1bU))));
    bufp->fullBit(oldp+202,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                   >> 0x19U))));
    bufp->fullBit(oldp+203,((1U & (~ (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup 
                                      >> 0x1eU)))));
    bufp->fullBit(oldp+204,((1U & (vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup 
                                   >> 0x18U))));
    bufp->fullIData(oldp+205,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup),31);
    bufp->fullIData(oldp+206,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter),28);
    bufp->fullCData(oldp+207,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state),4);
    bufp->fullCData(oldp+208,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data),8);
    bufp->fullBit(oldp+209,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity));
    bufp->fullBit(oldp+210,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter));
    bufp->fullBit(oldp+211,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state));
    bufp->fullBit(oldp+212,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n));
    bufp->fullBit(oldp+213,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n));
    bufp->fullBit(oldp+214,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts));
    bufp->fullBit(oldp+215,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2));
    bufp->fullBit(oldp+216,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6));
    bufp->fullCData(oldp+217,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[0]),8);
    bufp->fullCData(oldp+218,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[1]),8);
    bufp->fullCData(oldp+219,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[2]),8);
    bufp->fullCData(oldp+220,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[3]),8);
    bufp->fullCData(oldp+221,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[4]),8);
    bufp->fullCData(oldp+222,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[5]),8);
    bufp->fullCData(oldp+223,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[6]),8);
    bufp->fullCData(oldp+224,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[7]),8);
    bufp->fullCData(oldp+225,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[8]),8);
    bufp->fullCData(oldp+226,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[9]),8);
    bufp->fullCData(oldp+227,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[10]),8);
    bufp->fullCData(oldp+228,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[11]),8);
    bufp->fullCData(oldp+229,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[12]),8);
    bufp->fullCData(oldp+230,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[13]),8);
    bufp->fullCData(oldp+231,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[14]),8);
    bufp->fullCData(oldp+232,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo[15]),8);
    bufp->fullCData(oldp+233,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data),8);
    bufp->fullCData(oldp+234,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write),8);
    bufp->fullCData(oldp+235,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr),4);
    bufp->fullCData(oldp+236,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr),4);
    bufp->fullCData(oldp+237,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next),4);
    bufp->fullBit(oldp+238,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow));
    bufp->fullBit(oldp+239,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow));
    bufp->fullBit(oldp+240,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc));
    bufp->fullCData(oldp+241,((0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
    bufp->fullCData(oldp+242,((0xfU & ((IData)(2U) 
                                       + (IData)(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr)))),4);
    bufp->fullBit(oldp+243,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write));
    bufp->fullBit(oldp+244,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read));
    bufp->fullCData(oldp+245,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill),4);
    bufp->fullSData(oldp+246,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill),10);
    bufp->fullBit(oldp+247,(vlSymsp->TOP__top__DOT__uart_tx_stream.ready));
    bufp->fullBit(oldp+248,(vlSymsp->TOP__top__DOT__uart_rx_stream.valid));
    bufp->fullCData(oldp+249,(vlSymsp->TOP__top__DOT__uart_rx_stream.data),8);
    bufp->fullBit(oldp+250,(vlSymsp->TOP__top__DOT__uart_rx_stream.ready));
    bufp->fullBit(oldp+251,(vlSymsp->TOP__top__DOT__protocol_rx.valid));
    bufp->fullBit(oldp+252,(vlSelf->top__DOT__u_engine__DOT__state));
    bufp->fullBit(oldp+253,(vlSelf->top__DOT__u_engine__DOT__paused_r));
    bufp->fullSData(oldp+254,(vlSelf->top__DOT__u_engine__DOT__poll_cnt),10);
    bufp->fullCData(oldp+255,(vlSelf->top__DOT__u_serialiser__DOT__state),2);
    bufp->fullWData(oldp+256,(vlSelf->top__DOT__u_serialiser__DOT__pkt),528);
    bufp->fullCData(oldp+273,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx),8);
    bufp->fullCData(oldp+274,(vlSelf->top__DOT__u_serialiser__DOT__rem),8);
    bufp->fullCData(oldp+275,(vlSelf->top__DOT__u_test_core__DOT__state),2);
    bufp->fullIData(oldp+276,(vlSelf->top__DOT__u_test_core__DOT__settle_cnt),17);
    bufp->fullCData(oldp+277,(vlSelf->top__DOT__u_test_core__DOT__burst_cnt),4);
    bufp->fullIData(oldp+278,(vlSelf->top__DOT__u_test_core__DOT__gap_cnt),20);
    bufp->fullIData(oldp+279,(vlSelf->top__DOT__u_test_core__DOT__burst_num),32);
    bufp->fullBit(oldp+280,((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state))));
    bufp->fullIData(oldp+281,(vlSymsp->TOP__top__DOT__sdr_core_if.wr_data),32);
    bufp->fullBit(oldp+282,(vlSymsp->TOP__top__DOT__uart_tx_stream.valid));
    bufp->fullCData(oldp+283,(vlSymsp->TOP__top__DOT__uart_tx_stream.data),8);
    bufp->fullCData(oldp+284,(vlSelf->top__DOT__u_serialiser__DOT__byte_idx_n),8);
    bufp->fullCData(oldp+285,(vlSelf->top__DOT__u_serialiser__DOT__rem_n),8);
    bufp->fullBit(oldp+286,(vlSelf->top__DOT__u_serialiser__DOT__iter_fire));
    bufp->fullBit(oldp+287,(vlSelf->i_clk));
    bufp->fullBit(oldp+288,(vlSelf->i_reset));
    bufp->fullBit(oldp+289,(vlSelf->i_uart_rx));
    bufp->fullBit(oldp+290,(vlSelf->o_uart_tx));
    bufp->fullBit(oldp+291,(vlSelf->top__DOT____Vcellinp__u_serialiser__rst_n));
    bufp->fullBit(oldp+292,(((1U == (IData)(vlSelf->top__DOT__u_test_core__DOT__state)) 
                             & (IData)(vlSymsp->TOP__top__DOT__sdr_core_if.wr_ready))));
    bufp->fullCData(oldp+293,(vlSelf->top__DOT__u_serialiser__DOT__state_n),2);
    bufp->fullIData(oldp+294,((((IData)(vlSelf->__VdfgTmp_h61863ee6__0) 
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
    bufp->fullBit(oldp+295,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2));
    bufp->fullBit(oldp+296,(vlSelf->top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2));
}
