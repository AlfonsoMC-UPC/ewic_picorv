// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_core_sdr_if;
class Vtop_iter_if;
class Vtop_sdr_ctrl_protocol_if;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_core_sdr_if* __PVT__top__DOT__sdr_core_if;
    Vtop_iter_if* __PVT__top__DOT__uart_tx_stream;
    Vtop_iter_if* __PVT__top__DOT__uart_rx_stream;
    Vtop_sdr_ctrl_protocol_if* __PVT__top__DOT__protocol_tx;
    Vtop_sdr_ctrl_protocol_if* __PVT__top__DOT__protocol_rx;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(i_clk,0,0);
        CData/*0:0*/ top__DOT____Vcellinp__u_serialiser__rst_n;
        VL_IN8(i_reset,0,0);
        VL_IN8(i_uart_rx,0,0);
        VL_OUT8(o_uart_tx,0,0);
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_awvalid;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__s_axi_awaddr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_wvalid;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__s_axi_wstrb;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_bready;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_arvalid;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_arready;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__s_axi_araddr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__s_axi_rready;
        CData/*1:0*/ top__DOT__u_uart_top__DOT__tx_state;
        CData/*2:0*/ top__DOT__u_uart_top__DOT__state;
        CData/*4:0*/ top__DOT__u_uart_top__DOT__rx_byte_count;
        CData/*4:0*/ top__DOT__u_uart_top__DOT__rx_bytes_needed;
        CData/*4:0*/ top__DOT__u_uart_top__DOT__rx_output_idx;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__o_rts_n;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_bvalid;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_ready;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_valid;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_stb;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_break;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_perr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_ferr;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_data;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx_uart_reset;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_axil_read;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_perr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_rx_ferr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_write;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx_uart_reset;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txf_axil_data;
        CData/*1:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_axil_addr;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_preread;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rx____pinNumber2;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__rxfifo____pinNumber2;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber6;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT____Vcellinp__txfifo____pinNumber2;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__r_tx_break;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_WRITES__DOT__axil_awready;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__SIMPLE_READS__DOT__axil_arready;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT____VdfgTmp_hf5e0b888__0;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__state;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__zero_baud_counter;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__q_uart;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__qq_uart;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__ck_uart;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__line_synch;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__half_baud_time;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__data_reg;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__calc_parity;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__pre_wr;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_data;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__last_write;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__wr_addr;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__rd_addr;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_next;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_overflow;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__will_underflow;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__osrc;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_waddr_plus_one;
    };
    struct {
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_write;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_read;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__r_fill;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_data;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__last_write;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__wr_addr;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__rd_addr;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_next;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_overflow;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__will_underflow;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__osrc;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_waddr_plus_one;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_write;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_read;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__r_fill;
        CData/*3:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__state;
        CData/*7:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__lcl_data;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__calc_parity;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_busy;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__zero_baud_counter;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__last_state;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__q_cts_n;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__qq_cts_n;
        CData/*0:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__ck_cts;
        CData/*2:0*/ top__DOT__u_serialiser__DOT__state;
        CData/*2:0*/ top__DOT__u_serialiser__DOT__state_n;
        CData/*7:0*/ top__DOT__u_serialiser__DOT__byte_idx;
        CData/*7:0*/ top__DOT__u_serialiser__DOT__byte_idx_n;
        CData/*7:0*/ top__DOT__u_serialiser__DOT__rem;
        CData/*7:0*/ top__DOT__u_serialiser__DOT__rem_n;
        CData/*0:0*/ top__DOT__u_serialiser__DOT__iter_fire;
        CData/*2:0*/ top__DOT__u_decoder__DOT__state;
        CData/*2:0*/ top__DOT__u_decoder__DOT__state_n;
        CData/*7:0*/ top__DOT__u_decoder__DOT__rem;
        CData/*7:0*/ top__DOT__u_decoder__DOT__rem_n;
        CData/*7:0*/ top__DOT__u_decoder__DOT__byte_idx;
        CData/*7:0*/ top__DOT__u_decoder__DOT__byte_idx_n;
        CData/*0:0*/ top__DOT__u_engine__DOT__rsp_is_ready;
        CData/*0:0*/ top__DOT__u_engine__DOT__rsp_is_data;
        CData/*1:0*/ top__DOT__u_engine__DOT__tx_state;
        CData/*0:0*/ top__DOT__u_engine__DOT__have_credit;
        CData/*0:0*/ top__DOT__u_engine__DOT__in_msg;
        CData/*7:0*/ top__DOT__u_engine__DOT__chunk_len;
        CData/*7:0*/ top__DOT__u_engine__DOT__byte_idx;
        CData/*7:0*/ top__DOT__u_engine__DOT__cur_dst;
        CData/*0:0*/ top__DOT__u_engine__DOT__req_fire;
        CData/*0:0*/ top__DOT__u_engine__DOT__tx_msg_active;
        CData/*0:0*/ top__DOT__u_engine__DOT__rx_state;
        CData/*7:0*/ top__DOT__u_engine__DOT__rx_len;
        CData/*7:0*/ top__DOT__u_engine__DOT__rx_idx;
        CData/*7:0*/ top__DOT__u_engine__DOT__rx_rem;
        CData/*1:0*/ top__DOT__u_test_core__DOT__state;
        CData/*1:0*/ __VdfgTmp_h61863ee6__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_serialiser__DOT__iter_fire__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_engine__DOT__rsp_is_data__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__i_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT____Vcellinp__u_serialiser__rst_n__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
    };
    struct {
        SData/*15:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxf_status;
        SData/*9:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__w_fill;
        SData/*9:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__w_fill;
        SData/*15:0*/ top__DOT__u_engine__DOT__bytes_left;
        SData/*15:0*/ top__DOT__u_engine__DOT__ready_cnt;
        SData/*15:0*/ top__DOT__u_engine__DOT__tx_left;
        SData/*15:0*/ top__DOT__u_test_core__DOT__word_idx;
        IData/*31:0*/ top__DOT__u_uart_top__DOT__s_axi_wdata;
        IData/*31:0*/ top__DOT__u_uart_top__DOT__rx_data_accum;
        IData/*31:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__axil_read_data;
        IData/*30:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__uart_setup;
        IData/*31:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__new_setup;
        IData/*29:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__r_setup;
        IData/*23:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__baud_counter;
        IData/*27:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__rx__DOT__chg_counter;
        IData/*30:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__r_setup;
        IData/*27:0*/ top__DOT__u_uart_top__DOT__u_axiluart__DOT__tx__DOT__baud_counter;
        VlWide<16>/*511:0*/ top__DOT__u_engine__DOT__chunk_buf;
        VlWide<16>/*511:0*/ top__DOT__u_engine__DOT__rx_payload;
        IData/*31:0*/ top__DOT__u_test_core__DOT__fpga_id;
        IData/*16:0*/ top__DOT__u_test_core__DOT__settle_cnt;
        IData/*19:0*/ top__DOT__u_test_core__DOT__gap_cnt;
        IData/*31:0*/ top__DOT__u_test_core__DOT__msg_num;
        IData/*31:0*/ __Vfunc_top__DOT__u_uart_top__DOT__u_axiluart__DOT__apply_wstrb__0__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        VlWide<17>/*535:0*/ top__DOT__u_serialiser__DOT__pkt;
        VlWide<17>/*535:0*/ top__DOT__u_serialiser__DOT__pkt_n;
        VlWide<17>/*535:0*/ top__DOT__u_decoder__DOT__prot_buf;
        VlWide<17>/*535:0*/ top__DOT__u_decoder__DOT__prot_buf_n;
        VlUnpacked<CData/*7:0*/, 16> top__DOT__u_uart_top__DOT__u_axiluart__DOT__rxfifo__DOT__fifo;
        VlUnpacked<CData/*7:0*/, 16> top__DOT__u_uart_top__DOT__u_axiluart__DOT__txfifo__DOT__fifo;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };
    VlTriggerVec<3> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
