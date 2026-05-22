// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Tue Apr 28 18:01:33 2026
// Host        : alfonso-Modern-14-B4MW running 64-bit Ubuntu 24.04.2 LTS
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ uart_fifo_sim_netlist.v
// Design      : uart_fifo
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xcu280-fsvh2892-2L-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "uart_fifo,fifo_generator_v13_2_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "fifo_generator_v13_2_9,Vivado 2023.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
   (clk,
    srst,
    din,
    wr_en,
    rd_en,
    dout,
    full,
    empty,
    wr_rst_busy,
    rd_rst_busy);
  (* x_interface_info = "xilinx.com:signal:clock:1.0 core_clk CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME core_clk, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, INSERT_VIP 0" *) input clk;
  input srst;
  (* x_interface_info = "xilinx.com:interface:fifo_write:1.0 FIFO_WRITE WR_DATA" *) input [7:0]din;
  (* x_interface_info = "xilinx.com:interface:fifo_write:1.0 FIFO_WRITE WR_EN" *) input wr_en;
  (* x_interface_info = "xilinx.com:interface:fifo_read:1.0 FIFO_READ RD_EN" *) input rd_en;
  (* x_interface_info = "xilinx.com:interface:fifo_read:1.0 FIFO_READ RD_DATA" *) output [7:0]dout;
  (* x_interface_info = "xilinx.com:interface:fifo_write:1.0 FIFO_WRITE FULL" *) output full;
  (* x_interface_info = "xilinx.com:interface:fifo_read:1.0 FIFO_READ EMPTY" *) output empty;
  output wr_rst_busy;
  output rd_rst_busy;

  wire clk;
  wire [7:0]din;
  wire [7:0]dout;
  wire empty;
  wire full;
  wire rd_en;
  wire rd_rst_busy;
  wire srst;
  wire wr_en;
  wire wr_rst_busy;
  wire NLW_U0_almost_empty_UNCONNECTED;
  wire NLW_U0_almost_full_UNCONNECTED;
  wire NLW_U0_axi_ar_dbiterr_UNCONNECTED;
  wire NLW_U0_axi_ar_overflow_UNCONNECTED;
  wire NLW_U0_axi_ar_prog_empty_UNCONNECTED;
  wire NLW_U0_axi_ar_prog_full_UNCONNECTED;
  wire NLW_U0_axi_ar_sbiterr_UNCONNECTED;
  wire NLW_U0_axi_ar_underflow_UNCONNECTED;
  wire NLW_U0_axi_aw_dbiterr_UNCONNECTED;
  wire NLW_U0_axi_aw_overflow_UNCONNECTED;
  wire NLW_U0_axi_aw_prog_empty_UNCONNECTED;
  wire NLW_U0_axi_aw_prog_full_UNCONNECTED;
  wire NLW_U0_axi_aw_sbiterr_UNCONNECTED;
  wire NLW_U0_axi_aw_underflow_UNCONNECTED;
  wire NLW_U0_axi_b_dbiterr_UNCONNECTED;
  wire NLW_U0_axi_b_overflow_UNCONNECTED;
  wire NLW_U0_axi_b_prog_empty_UNCONNECTED;
  wire NLW_U0_axi_b_prog_full_UNCONNECTED;
  wire NLW_U0_axi_b_sbiterr_UNCONNECTED;
  wire NLW_U0_axi_b_underflow_UNCONNECTED;
  wire NLW_U0_axi_r_dbiterr_UNCONNECTED;
  wire NLW_U0_axi_r_overflow_UNCONNECTED;
  wire NLW_U0_axi_r_prog_empty_UNCONNECTED;
  wire NLW_U0_axi_r_prog_full_UNCONNECTED;
  wire NLW_U0_axi_r_sbiterr_UNCONNECTED;
  wire NLW_U0_axi_r_underflow_UNCONNECTED;
  wire NLW_U0_axi_w_dbiterr_UNCONNECTED;
  wire NLW_U0_axi_w_overflow_UNCONNECTED;
  wire NLW_U0_axi_w_prog_empty_UNCONNECTED;
  wire NLW_U0_axi_w_prog_full_UNCONNECTED;
  wire NLW_U0_axi_w_sbiterr_UNCONNECTED;
  wire NLW_U0_axi_w_underflow_UNCONNECTED;
  wire NLW_U0_axis_dbiterr_UNCONNECTED;
  wire NLW_U0_axis_overflow_UNCONNECTED;
  wire NLW_U0_axis_prog_empty_UNCONNECTED;
  wire NLW_U0_axis_prog_full_UNCONNECTED;
  wire NLW_U0_axis_sbiterr_UNCONNECTED;
  wire NLW_U0_axis_underflow_UNCONNECTED;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_m_axi_arvalid_UNCONNECTED;
  wire NLW_U0_m_axi_awvalid_UNCONNECTED;
  wire NLW_U0_m_axi_bready_UNCONNECTED;
  wire NLW_U0_m_axi_rready_UNCONNECTED;
  wire NLW_U0_m_axi_wlast_UNCONNECTED;
  wire NLW_U0_m_axi_wvalid_UNCONNECTED;
  wire NLW_U0_m_axis_tlast_UNCONNECTED;
  wire NLW_U0_m_axis_tvalid_UNCONNECTED;
  wire NLW_U0_overflow_UNCONNECTED;
  wire NLW_U0_prog_empty_UNCONNECTED;
  wire NLW_U0_prog_full_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_s_axis_tready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire NLW_U0_underflow_UNCONNECTED;
  wire NLW_U0_valid_UNCONNECTED;
  wire NLW_U0_wr_ack_UNCONNECTED;
  wire [4:0]NLW_U0_axi_ar_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_ar_rd_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_ar_wr_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_aw_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_aw_rd_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_aw_wr_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_b_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_b_rd_data_count_UNCONNECTED;
  wire [4:0]NLW_U0_axi_b_wr_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_r_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_r_rd_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_r_wr_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_w_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_w_rd_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axi_w_wr_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axis_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axis_rd_data_count_UNCONNECTED;
  wire [10:0]NLW_U0_axis_wr_data_count_UNCONNECTED;
  wire [9:0]NLW_U0_data_count_UNCONNECTED;
  wire [31:0]NLW_U0_m_axi_araddr_UNCONNECTED;
  wire [1:0]NLW_U0_m_axi_arburst_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_arcache_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_arid_UNCONNECTED;
  wire [7:0]NLW_U0_m_axi_arlen_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_arlock_UNCONNECTED;
  wire [2:0]NLW_U0_m_axi_arprot_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_arqos_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_arregion_UNCONNECTED;
  wire [2:0]NLW_U0_m_axi_arsize_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_aruser_UNCONNECTED;
  wire [31:0]NLW_U0_m_axi_awaddr_UNCONNECTED;
  wire [1:0]NLW_U0_m_axi_awburst_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_awcache_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_awid_UNCONNECTED;
  wire [7:0]NLW_U0_m_axi_awlen_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_awlock_UNCONNECTED;
  wire [2:0]NLW_U0_m_axi_awprot_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_awqos_UNCONNECTED;
  wire [3:0]NLW_U0_m_axi_awregion_UNCONNECTED;
  wire [2:0]NLW_U0_m_axi_awsize_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_awuser_UNCONNECTED;
  wire [63:0]NLW_U0_m_axi_wdata_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_wid_UNCONNECTED;
  wire [7:0]NLW_U0_m_axi_wstrb_UNCONNECTED;
  wire [0:0]NLW_U0_m_axi_wuser_UNCONNECTED;
  wire [7:0]NLW_U0_m_axis_tdata_UNCONNECTED;
  wire [0:0]NLW_U0_m_axis_tdest_UNCONNECTED;
  wire [0:0]NLW_U0_m_axis_tid_UNCONNECTED;
  wire [0:0]NLW_U0_m_axis_tkeep_UNCONNECTED;
  wire [0:0]NLW_U0_m_axis_tstrb_UNCONNECTED;
  wire [3:0]NLW_U0_m_axis_tuser_UNCONNECTED;
  wire [9:0]NLW_U0_rd_data_count_UNCONNECTED;
  wire [0:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [0:0]NLW_U0_s_axi_buser_UNCONNECTED;
  wire [63:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [0:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;
  wire [0:0]NLW_U0_s_axi_ruser_UNCONNECTED;
  wire [9:0]NLW_U0_wr_data_count_UNCONNECTED;

  (* C_ADD_NGC_CONSTRAINT = "0" *) 
  (* C_APPLICATION_TYPE_AXIS = "0" *) 
  (* C_APPLICATION_TYPE_RACH = "0" *) 
  (* C_APPLICATION_TYPE_RDCH = "0" *) 
  (* C_APPLICATION_TYPE_WACH = "0" *) 
  (* C_APPLICATION_TYPE_WDCH = "0" *) 
  (* C_APPLICATION_TYPE_WRCH = "0" *) 
  (* C_AXIS_TDATA_WIDTH = "8" *) 
  (* C_AXIS_TDEST_WIDTH = "1" *) 
  (* C_AXIS_TID_WIDTH = "1" *) 
  (* C_AXIS_TKEEP_WIDTH = "1" *) 
  (* C_AXIS_TSTRB_WIDTH = "1" *) 
  (* C_AXIS_TUSER_WIDTH = "4" *) 
  (* C_AXIS_TYPE = "0" *) 
  (* C_AXI_ADDR_WIDTH = "32" *) 
  (* C_AXI_ARUSER_WIDTH = "1" *) 
  (* C_AXI_AWUSER_WIDTH = "1" *) 
  (* C_AXI_BUSER_WIDTH = "1" *) 
  (* C_AXI_DATA_WIDTH = "64" *) 
  (* C_AXI_ID_WIDTH = "1" *) 
  (* C_AXI_LEN_WIDTH = "8" *) 
  (* C_AXI_LOCK_WIDTH = "1" *) 
  (* C_AXI_RUSER_WIDTH = "1" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_AXI_WUSER_WIDTH = "1" *) 
  (* C_COMMON_CLOCK = "1" *) 
  (* C_COUNT_TYPE = "0" *) 
  (* C_DATA_COUNT_WIDTH = "10" *) 
  (* C_DEFAULT_VALUE = "BlankString" *) 
  (* C_DIN_WIDTH = "8" *) 
  (* C_DIN_WIDTH_AXIS = "1" *) 
  (* C_DIN_WIDTH_RACH = "32" *) 
  (* C_DIN_WIDTH_RDCH = "64" *) 
  (* C_DIN_WIDTH_WACH = "1" *) 
  (* C_DIN_WIDTH_WDCH = "64" *) 
  (* C_DIN_WIDTH_WRCH = "2" *) 
  (* C_DOUT_RST_VAL = "0" *) 
  (* C_DOUT_WIDTH = "8" *) 
  (* C_ENABLE_RLOCS = "0" *) 
  (* C_ENABLE_RST_SYNC = "1" *) 
  (* C_EN_SAFETY_CKT = "0" *) 
  (* C_ERROR_INJECTION_TYPE = "0" *) 
  (* C_ERROR_INJECTION_TYPE_AXIS = "0" *) 
  (* C_ERROR_INJECTION_TYPE_RACH = "0" *) 
  (* C_ERROR_INJECTION_TYPE_RDCH = "0" *) 
  (* C_ERROR_INJECTION_TYPE_WACH = "0" *) 
  (* C_ERROR_INJECTION_TYPE_WDCH = "0" *) 
  (* C_ERROR_INJECTION_TYPE_WRCH = "0" *) 
  (* C_FAMILY = "virtexuplusHBM" *) 
  (* C_FULL_FLAGS_RST_VAL = "0" *) 
  (* C_HAS_ALMOST_EMPTY = "0" *) 
  (* C_HAS_ALMOST_FULL = "0" *) 
  (* C_HAS_AXIS_TDATA = "1" *) 
  (* C_HAS_AXIS_TDEST = "0" *) 
  (* C_HAS_AXIS_TID = "0" *) 
  (* C_HAS_AXIS_TKEEP = "0" *) 
  (* C_HAS_AXIS_TLAST = "0" *) 
  (* C_HAS_AXIS_TREADY = "1" *) 
  (* C_HAS_AXIS_TSTRB = "0" *) 
  (* C_HAS_AXIS_TUSER = "1" *) 
  (* C_HAS_AXI_ARUSER = "0" *) 
  (* C_HAS_AXI_AWUSER = "0" *) 
  (* C_HAS_AXI_BUSER = "0" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_AXI_RD_CHANNEL = "1" *) 
  (* C_HAS_AXI_RUSER = "0" *) 
  (* C_HAS_AXI_WR_CHANNEL = "1" *) 
  (* C_HAS_AXI_WUSER = "0" *) 
  (* C_HAS_BACKUP = "0" *) 
  (* C_HAS_DATA_COUNT = "0" *) 
  (* C_HAS_DATA_COUNTS_AXIS = "0" *) 
  (* C_HAS_DATA_COUNTS_RACH = "0" *) 
  (* C_HAS_DATA_COUNTS_RDCH = "0" *) 
  (* C_HAS_DATA_COUNTS_WACH = "0" *) 
  (* C_HAS_DATA_COUNTS_WDCH = "0" *) 
  (* C_HAS_DATA_COUNTS_WRCH = "0" *) 
  (* C_HAS_INT_CLK = "0" *) 
  (* C_HAS_MASTER_CE = "0" *) 
  (* C_HAS_MEMINIT_FILE = "0" *) 
  (* C_HAS_OVERFLOW = "0" *) 
  (* C_HAS_PROG_FLAGS_AXIS = "0" *) 
  (* C_HAS_PROG_FLAGS_RACH = "0" *) 
  (* C_HAS_PROG_FLAGS_RDCH = "0" *) 
  (* C_HAS_PROG_FLAGS_WACH = "0" *) 
  (* C_HAS_PROG_FLAGS_WDCH = "0" *) 
  (* C_HAS_PROG_FLAGS_WRCH = "0" *) 
  (* C_HAS_RD_DATA_COUNT = "0" *) 
  (* C_HAS_RD_RST = "0" *) 
  (* C_HAS_RST = "0" *) 
  (* C_HAS_SLAVE_CE = "0" *) 
  (* C_HAS_SRST = "1" *) 
  (* C_HAS_UNDERFLOW = "0" *) 
  (* C_HAS_VALID = "0" *) 
  (* C_HAS_WR_ACK = "0" *) 
  (* C_HAS_WR_DATA_COUNT = "0" *) 
  (* C_HAS_WR_RST = "0" *) 
  (* C_IMPLEMENTATION_TYPE = "6" *) 
  (* C_IMPLEMENTATION_TYPE_AXIS = "1" *) 
  (* C_IMPLEMENTATION_TYPE_RACH = "1" *) 
  (* C_IMPLEMENTATION_TYPE_RDCH = "1" *) 
  (* C_IMPLEMENTATION_TYPE_WACH = "1" *) 
  (* C_IMPLEMENTATION_TYPE_WDCH = "1" *) 
  (* C_IMPLEMENTATION_TYPE_WRCH = "1" *) 
  (* C_INIT_WR_PNTR_VAL = "0" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_MEMORY_TYPE = "4" *) 
  (* C_MIF_FILE_NAME = "BlankString" *) 
  (* C_MSGON_VAL = "1" *) 
  (* C_OPTIMIZATION_MODE = "0" *) 
  (* C_OVERFLOW_LOW = "0" *) 
  (* C_POWER_SAVING_MODE = "0" *) 
  (* C_PRELOAD_LATENCY = "2" *) 
  (* C_PRELOAD_REGS = "1" *) 
  (* C_PRIM_FIFO_TYPE = "1kx18" *) 
  (* C_PRIM_FIFO_TYPE_AXIS = "1kx18" *) 
  (* C_PRIM_FIFO_TYPE_RACH = "512x36" *) 
  (* C_PRIM_FIFO_TYPE_RDCH = "512x72" *) 
  (* C_PRIM_FIFO_TYPE_WACH = "512x36" *) 
  (* C_PRIM_FIFO_TYPE_WDCH = "512x72" *) 
  (* C_PRIM_FIFO_TYPE_WRCH = "512x36" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL = "2" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_AXIS = "1022" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_RACH = "1022" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_RDCH = "1022" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_WACH = "1022" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_WDCH = "1022" *) 
  (* C_PROG_EMPTY_THRESH_ASSERT_VAL_WRCH = "1022" *) 
  (* C_PROG_EMPTY_THRESH_NEGATE_VAL = "3" *) 
  (* C_PROG_EMPTY_TYPE = "0" *) 
  (* C_PROG_EMPTY_TYPE_AXIS = "0" *) 
  (* C_PROG_EMPTY_TYPE_RACH = "0" *) 
  (* C_PROG_EMPTY_TYPE_RDCH = "0" *) 
  (* C_PROG_EMPTY_TYPE_WACH = "0" *) 
  (* C_PROG_EMPTY_TYPE_WDCH = "0" *) 
  (* C_PROG_EMPTY_TYPE_WRCH = "0" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_AXIS = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_RACH = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_RDCH = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_WACH = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_WDCH = "1023" *) 
  (* C_PROG_FULL_THRESH_ASSERT_VAL_WRCH = "1023" *) 
  (* C_PROG_FULL_THRESH_NEGATE_VAL = "1022" *) 
  (* C_PROG_FULL_TYPE = "0" *) 
  (* C_PROG_FULL_TYPE_AXIS = "0" *) 
  (* C_PROG_FULL_TYPE_RACH = "0" *) 
  (* C_PROG_FULL_TYPE_RDCH = "0" *) 
  (* C_PROG_FULL_TYPE_WACH = "0" *) 
  (* C_PROG_FULL_TYPE_WDCH = "0" *) 
  (* C_PROG_FULL_TYPE_WRCH = "0" *) 
  (* C_RACH_TYPE = "0" *) 
  (* C_RDCH_TYPE = "0" *) 
  (* C_RD_DATA_COUNT_WIDTH = "10" *) 
  (* C_RD_DEPTH = "1024" *) 
  (* C_RD_FREQ = "1" *) 
  (* C_RD_PNTR_WIDTH = "10" *) 
  (* C_REG_SLICE_MODE_AXIS = "0" *) 
  (* C_REG_SLICE_MODE_RACH = "0" *) 
  (* C_REG_SLICE_MODE_RDCH = "0" *) 
  (* C_REG_SLICE_MODE_WACH = "0" *) 
  (* C_REG_SLICE_MODE_WDCH = "0" *) 
  (* C_REG_SLICE_MODE_WRCH = "0" *) 
  (* C_SELECT_XPM = "0" *) 
  (* C_SYNCHRONIZER_STAGE = "2" *) 
  (* C_UNDERFLOW_LOW = "0" *) 
  (* C_USE_COMMON_OVERFLOW = "0" *) 
  (* C_USE_COMMON_UNDERFLOW = "0" *) 
  (* C_USE_DEFAULT_SETTINGS = "0" *) 
  (* C_USE_DOUT_RST = "1" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_ECC_AXIS = "0" *) 
  (* C_USE_ECC_RACH = "0" *) 
  (* C_USE_ECC_RDCH = "0" *) 
  (* C_USE_ECC_WACH = "0" *) 
  (* C_USE_ECC_WDCH = "0" *) 
  (* C_USE_ECC_WRCH = "0" *) 
  (* C_USE_EMBEDDED_REG = "1" *) 
  (* C_USE_FIFO16_FLAGS = "0" *) 
  (* C_USE_FWFT_DATA_COUNT = "0" *) 
  (* C_USE_PIPELINE_REG = "0" *) 
  (* C_VALID_LOW = "0" *) 
  (* C_WACH_TYPE = "0" *) 
  (* C_WDCH_TYPE = "0" *) 
  (* C_WRCH_TYPE = "0" *) 
  (* C_WR_ACK_LOW = "0" *) 
  (* C_WR_DATA_COUNT_WIDTH = "10" *) 
  (* C_WR_DEPTH = "1024" *) 
  (* C_WR_DEPTH_AXIS = "1024" *) 
  (* C_WR_DEPTH_RACH = "16" *) 
  (* C_WR_DEPTH_RDCH = "1024" *) 
  (* C_WR_DEPTH_WACH = "16" *) 
  (* C_WR_DEPTH_WDCH = "1024" *) 
  (* C_WR_DEPTH_WRCH = "16" *) 
  (* C_WR_FREQ = "1" *) 
  (* C_WR_PNTR_WIDTH = "10" *) 
  (* C_WR_PNTR_WIDTH_AXIS = "10" *) 
  (* C_WR_PNTR_WIDTH_RACH = "4" *) 
  (* C_WR_PNTR_WIDTH_RDCH = "10" *) 
  (* C_WR_PNTR_WIDTH_WACH = "4" *) 
  (* C_WR_PNTR_WIDTH_WDCH = "10" *) 
  (* C_WR_PNTR_WIDTH_WRCH = "4" *) 
  (* C_WR_RESPONSE_LATENCY = "1" *) 
  (* is_du_within_envelope = "true" *) 
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_fifo_generator_v13_2_9 U0
       (.almost_empty(NLW_U0_almost_empty_UNCONNECTED),
        .almost_full(NLW_U0_almost_full_UNCONNECTED),
        .axi_ar_data_count(NLW_U0_axi_ar_data_count_UNCONNECTED[4:0]),
        .axi_ar_dbiterr(NLW_U0_axi_ar_dbiterr_UNCONNECTED),
        .axi_ar_injectdbiterr(1'b0),
        .axi_ar_injectsbiterr(1'b0),
        .axi_ar_overflow(NLW_U0_axi_ar_overflow_UNCONNECTED),
        .axi_ar_prog_empty(NLW_U0_axi_ar_prog_empty_UNCONNECTED),
        .axi_ar_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_ar_prog_full(NLW_U0_axi_ar_prog_full_UNCONNECTED),
        .axi_ar_prog_full_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_ar_rd_data_count(NLW_U0_axi_ar_rd_data_count_UNCONNECTED[4:0]),
        .axi_ar_sbiterr(NLW_U0_axi_ar_sbiterr_UNCONNECTED),
        .axi_ar_underflow(NLW_U0_axi_ar_underflow_UNCONNECTED),
        .axi_ar_wr_data_count(NLW_U0_axi_ar_wr_data_count_UNCONNECTED[4:0]),
        .axi_aw_data_count(NLW_U0_axi_aw_data_count_UNCONNECTED[4:0]),
        .axi_aw_dbiterr(NLW_U0_axi_aw_dbiterr_UNCONNECTED),
        .axi_aw_injectdbiterr(1'b0),
        .axi_aw_injectsbiterr(1'b0),
        .axi_aw_overflow(NLW_U0_axi_aw_overflow_UNCONNECTED),
        .axi_aw_prog_empty(NLW_U0_axi_aw_prog_empty_UNCONNECTED),
        .axi_aw_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_aw_prog_full(NLW_U0_axi_aw_prog_full_UNCONNECTED),
        .axi_aw_prog_full_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_aw_rd_data_count(NLW_U0_axi_aw_rd_data_count_UNCONNECTED[4:0]),
        .axi_aw_sbiterr(NLW_U0_axi_aw_sbiterr_UNCONNECTED),
        .axi_aw_underflow(NLW_U0_axi_aw_underflow_UNCONNECTED),
        .axi_aw_wr_data_count(NLW_U0_axi_aw_wr_data_count_UNCONNECTED[4:0]),
        .axi_b_data_count(NLW_U0_axi_b_data_count_UNCONNECTED[4:0]),
        .axi_b_dbiterr(NLW_U0_axi_b_dbiterr_UNCONNECTED),
        .axi_b_injectdbiterr(1'b0),
        .axi_b_injectsbiterr(1'b0),
        .axi_b_overflow(NLW_U0_axi_b_overflow_UNCONNECTED),
        .axi_b_prog_empty(NLW_U0_axi_b_prog_empty_UNCONNECTED),
        .axi_b_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_b_prog_full(NLW_U0_axi_b_prog_full_UNCONNECTED),
        .axi_b_prog_full_thresh({1'b0,1'b0,1'b0,1'b0}),
        .axi_b_rd_data_count(NLW_U0_axi_b_rd_data_count_UNCONNECTED[4:0]),
        .axi_b_sbiterr(NLW_U0_axi_b_sbiterr_UNCONNECTED),
        .axi_b_underflow(NLW_U0_axi_b_underflow_UNCONNECTED),
        .axi_b_wr_data_count(NLW_U0_axi_b_wr_data_count_UNCONNECTED[4:0]),
        .axi_r_data_count(NLW_U0_axi_r_data_count_UNCONNECTED[10:0]),
        .axi_r_dbiterr(NLW_U0_axi_r_dbiterr_UNCONNECTED),
        .axi_r_injectdbiterr(1'b0),
        .axi_r_injectsbiterr(1'b0),
        .axi_r_overflow(NLW_U0_axi_r_overflow_UNCONNECTED),
        .axi_r_prog_empty(NLW_U0_axi_r_prog_empty_UNCONNECTED),
        .axi_r_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axi_r_prog_full(NLW_U0_axi_r_prog_full_UNCONNECTED),
        .axi_r_prog_full_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axi_r_rd_data_count(NLW_U0_axi_r_rd_data_count_UNCONNECTED[10:0]),
        .axi_r_sbiterr(NLW_U0_axi_r_sbiterr_UNCONNECTED),
        .axi_r_underflow(NLW_U0_axi_r_underflow_UNCONNECTED),
        .axi_r_wr_data_count(NLW_U0_axi_r_wr_data_count_UNCONNECTED[10:0]),
        .axi_w_data_count(NLW_U0_axi_w_data_count_UNCONNECTED[10:0]),
        .axi_w_dbiterr(NLW_U0_axi_w_dbiterr_UNCONNECTED),
        .axi_w_injectdbiterr(1'b0),
        .axi_w_injectsbiterr(1'b0),
        .axi_w_overflow(NLW_U0_axi_w_overflow_UNCONNECTED),
        .axi_w_prog_empty(NLW_U0_axi_w_prog_empty_UNCONNECTED),
        .axi_w_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axi_w_prog_full(NLW_U0_axi_w_prog_full_UNCONNECTED),
        .axi_w_prog_full_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axi_w_rd_data_count(NLW_U0_axi_w_rd_data_count_UNCONNECTED[10:0]),
        .axi_w_sbiterr(NLW_U0_axi_w_sbiterr_UNCONNECTED),
        .axi_w_underflow(NLW_U0_axi_w_underflow_UNCONNECTED),
        .axi_w_wr_data_count(NLW_U0_axi_w_wr_data_count_UNCONNECTED[10:0]),
        .axis_data_count(NLW_U0_axis_data_count_UNCONNECTED[10:0]),
        .axis_dbiterr(NLW_U0_axis_dbiterr_UNCONNECTED),
        .axis_injectdbiterr(1'b0),
        .axis_injectsbiterr(1'b0),
        .axis_overflow(NLW_U0_axis_overflow_UNCONNECTED),
        .axis_prog_empty(NLW_U0_axis_prog_empty_UNCONNECTED),
        .axis_prog_empty_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axis_prog_full(NLW_U0_axis_prog_full_UNCONNECTED),
        .axis_prog_full_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .axis_rd_data_count(NLW_U0_axis_rd_data_count_UNCONNECTED[10:0]),
        .axis_sbiterr(NLW_U0_axis_sbiterr_UNCONNECTED),
        .axis_underflow(NLW_U0_axis_underflow_UNCONNECTED),
        .axis_wr_data_count(NLW_U0_axis_wr_data_count_UNCONNECTED[10:0]),
        .backup(1'b0),
        .backup_marker(1'b0),
        .clk(clk),
        .data_count(NLW_U0_data_count_UNCONNECTED[9:0]),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .din(din),
        .dout(dout),
        .empty(empty),
        .full(full),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .int_clk(1'b0),
        .m_aclk(1'b0),
        .m_aclk_en(1'b0),
        .m_axi_araddr(NLW_U0_m_axi_araddr_UNCONNECTED[31:0]),
        .m_axi_arburst(NLW_U0_m_axi_arburst_UNCONNECTED[1:0]),
        .m_axi_arcache(NLW_U0_m_axi_arcache_UNCONNECTED[3:0]),
        .m_axi_arid(NLW_U0_m_axi_arid_UNCONNECTED[0]),
        .m_axi_arlen(NLW_U0_m_axi_arlen_UNCONNECTED[7:0]),
        .m_axi_arlock(NLW_U0_m_axi_arlock_UNCONNECTED[0]),
        .m_axi_arprot(NLW_U0_m_axi_arprot_UNCONNECTED[2:0]),
        .m_axi_arqos(NLW_U0_m_axi_arqos_UNCONNECTED[3:0]),
        .m_axi_arready(1'b0),
        .m_axi_arregion(NLW_U0_m_axi_arregion_UNCONNECTED[3:0]),
        .m_axi_arsize(NLW_U0_m_axi_arsize_UNCONNECTED[2:0]),
        .m_axi_aruser(NLW_U0_m_axi_aruser_UNCONNECTED[0]),
        .m_axi_arvalid(NLW_U0_m_axi_arvalid_UNCONNECTED),
        .m_axi_awaddr(NLW_U0_m_axi_awaddr_UNCONNECTED[31:0]),
        .m_axi_awburst(NLW_U0_m_axi_awburst_UNCONNECTED[1:0]),
        .m_axi_awcache(NLW_U0_m_axi_awcache_UNCONNECTED[3:0]),
        .m_axi_awid(NLW_U0_m_axi_awid_UNCONNECTED[0]),
        .m_axi_awlen(NLW_U0_m_axi_awlen_UNCONNECTED[7:0]),
        .m_axi_awlock(NLW_U0_m_axi_awlock_UNCONNECTED[0]),
        .m_axi_awprot(NLW_U0_m_axi_awprot_UNCONNECTED[2:0]),
        .m_axi_awqos(NLW_U0_m_axi_awqos_UNCONNECTED[3:0]),
        .m_axi_awready(1'b0),
        .m_axi_awregion(NLW_U0_m_axi_awregion_UNCONNECTED[3:0]),
        .m_axi_awsize(NLW_U0_m_axi_awsize_UNCONNECTED[2:0]),
        .m_axi_awuser(NLW_U0_m_axi_awuser_UNCONNECTED[0]),
        .m_axi_awvalid(NLW_U0_m_axi_awvalid_UNCONNECTED),
        .m_axi_bid(1'b0),
        .m_axi_bready(NLW_U0_m_axi_bready_UNCONNECTED),
        .m_axi_bresp({1'b0,1'b0}),
        .m_axi_buser(1'b0),
        .m_axi_bvalid(1'b0),
        .m_axi_rdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .m_axi_rid(1'b0),
        .m_axi_rlast(1'b0),
        .m_axi_rready(NLW_U0_m_axi_rready_UNCONNECTED),
        .m_axi_rresp({1'b0,1'b0}),
        .m_axi_ruser(1'b0),
        .m_axi_rvalid(1'b0),
        .m_axi_wdata(NLW_U0_m_axi_wdata_UNCONNECTED[63:0]),
        .m_axi_wid(NLW_U0_m_axi_wid_UNCONNECTED[0]),
        .m_axi_wlast(NLW_U0_m_axi_wlast_UNCONNECTED),
        .m_axi_wready(1'b0),
        .m_axi_wstrb(NLW_U0_m_axi_wstrb_UNCONNECTED[7:0]),
        .m_axi_wuser(NLW_U0_m_axi_wuser_UNCONNECTED[0]),
        .m_axi_wvalid(NLW_U0_m_axi_wvalid_UNCONNECTED),
        .m_axis_tdata(NLW_U0_m_axis_tdata_UNCONNECTED[7:0]),
        .m_axis_tdest(NLW_U0_m_axis_tdest_UNCONNECTED[0]),
        .m_axis_tid(NLW_U0_m_axis_tid_UNCONNECTED[0]),
        .m_axis_tkeep(NLW_U0_m_axis_tkeep_UNCONNECTED[0]),
        .m_axis_tlast(NLW_U0_m_axis_tlast_UNCONNECTED),
        .m_axis_tready(1'b0),
        .m_axis_tstrb(NLW_U0_m_axis_tstrb_UNCONNECTED[0]),
        .m_axis_tuser(NLW_U0_m_axis_tuser_UNCONNECTED[3:0]),
        .m_axis_tvalid(NLW_U0_m_axis_tvalid_UNCONNECTED),
        .overflow(NLW_U0_overflow_UNCONNECTED),
        .prog_empty(NLW_U0_prog_empty_UNCONNECTED),
        .prog_empty_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .prog_empty_thresh_assert({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .prog_empty_thresh_negate({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .prog_full(NLW_U0_prog_full_UNCONNECTED),
        .prog_full_thresh({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .prog_full_thresh_assert({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .prog_full_thresh_negate({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .rd_clk(1'b0),
        .rd_data_count(NLW_U0_rd_data_count_UNCONNECTED[9:0]),
        .rd_en(rd_en),
        .rd_rst(1'b0),
        .rd_rst_busy(rd_rst_busy),
        .rst(1'b0),
        .s_aclk(1'b0),
        .s_aclk_en(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arcache({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arid(1'b0),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlock(1'b0),
        .s_axi_arprot({1'b0,1'b0,1'b0}),
        .s_axi_arqos({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arregion({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_aruser(1'b0),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awcache({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awid(1'b0),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlock(1'b0),
        .s_axi_awprot({1'b0,1'b0,1'b0}),
        .s_axi_awqos({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awregion({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awuser(1'b0),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_buser(NLW_U0_s_axi_buser_UNCONNECTED[0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[63:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_ruser(NLW_U0_s_axi_ruser_UNCONNECTED[0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wid(1'b0),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wuser(1'b0),
        .s_axi_wvalid(1'b0),
        .s_axis_tdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axis_tdest(1'b0),
        .s_axis_tid(1'b0),
        .s_axis_tkeep(1'b0),
        .s_axis_tlast(1'b0),
        .s_axis_tready(NLW_U0_s_axis_tready_UNCONNECTED),
        .s_axis_tstrb(1'b0),
        .s_axis_tuser({1'b0,1'b0,1'b0,1'b0}),
        .s_axis_tvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .sleep(1'b0),
        .srst(srst),
        .underflow(NLW_U0_underflow_UNCONNECTED),
        .valid(NLW_U0_valid_UNCONNECTED),
        .wr_ack(NLW_U0_wr_ack_UNCONNECTED),
        .wr_clk(1'b0),
        .wr_data_count(NLW_U0_wr_data_count_UNCONNECTED[9:0]),
        .wr_en(wr_en),
        .wr_rst(1'b0),
        .wr_rst_busy(wr_rst_busy));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2023.2"
`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
gcDjvJ18gZEH8C+LHMq/N7AaYWSyHgvjIQn585rdUOTVX2orO9n8j6LNiga3BYkS91+lbHAjAieW
oD/8serz9uvKt9uVuyMIE6oOFFScZR6q2wQk1d1Qzq717+8yPCwgBT9HIhfJIHLujHt+cA2l2L5t
tux9aNBdVKkk1MHv7yY=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
exhH3ieiewq538XhQByQWj7PMh1Y+pzdDw+4bALHgOXUMTZleYL0Pvhip/E5VwYBOb3/5i/ElWf3
Vm6OeE9b1Jj8xb7x10akeyRaNdCJYAtTqgb7gFS/crjXeoaYKJgLqCiyaB7LdWR9BiZOWqxEPSxe
/lr/8F8psti0kra2jACCbz94iU3qDIdZWH5kqd21Pp2/YczWpJBQzh+bBz9V+EuMAeZIzY3x2GZy
jOMZPemqiqFhSEcDf09mKK3xKEUxE+TPz82hd9ZrF5OjFst6mWMVye10lkzmY5Hmmx5Y/PVgPx3R
fN0tTAZfIDGH/YUu758U8UWOIcMzBHF6rytqmg==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
Umfm0FNxPKfdryB9QccnkcrzqkPtalTpE+R0M3D9kxaXOa1YOGT+9jGc1TRZMLcN5NyGN3UIZcH4
LWFVfGg80k9RmFHBDZaHzOXaomQhoPSO++ArXvmvO5zgttfCHEl7jypYkuPgwfQMfjK7YII9Deex
KOC8JtqORVWmhq47cpQ=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
cm7WeJnXtFlUdJuJH7wHYfinJTaBhpglyFWD2YwmOuS4fmVA4nXbX0IMaU1F1WGO1VK25KlFf8Nm
w8L6BJ6ZpH12xPIl3J17rMT4/3KHv9tpBWqeC080GeV5nISo8JrhOpIKa4+HBHZ6lYLce8LBAu/Z
EiBmDqw22aLsAuPAzAMh9yuHT5rpX9ykD9u0uZ5UplK05S0TsvYMUqcHNQ2hijt/lbxvUxXHTa+W
GJ5RRQAdw98wG1mc65u16hfZPsLimnw4BHwpyNGOPadShqb78rQihc+YiBTn4lgN1HhquWRGqCYZ
ZEjBmtWOJm8WJSTWtcpFEkmPlOTDmNX82e9mnw==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
a1mMNsEVIHwFCxw3sHygQ6eU3z5whgDQI+YHUmPAwU6q4vqfu2NVxu0z42QL1rV1rCsm39SqZ078
EGEqt7XUt6bdvI3yu4dU8gF+jou5njJ2UU34VmbOw/MQt48Hmi+hxtH1/zSlbNe2iOksDFEFTHmW
WGHgPS2bACG/KtAZMYK3gBtbnb9dtu+p5hxiQtwMOFnv9kQGBxcMaciN0yqy2TE5fygwKcNEua29
jiGUF0qgPS1k6qN+zLrYWkaVT0amR1MFXpv0WcwL+xVkxj6bBQhe5D7t5xCIsfLR4xqa5WVpa0dN
FkxGlIoufL17G/cGRr4nV4QP0sqcDCCHYpRoIA==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2022_10", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
rPFWI49JcHqYFxRrTG2uFixmE4jeIWIero9KijBFo7+FOCC7hJeSlCuNlwb8mBsI0Up57fm7C8t9
tb1l2QCfvy82JqTvEuH49UmS+8/GEnbK1QbVHsDIiv3/8cFn+0zw/VSuVeaN8L0yzeNIo8m59iAq
AQ9wOyqKFEhKKkbn+nVg+hQW3L/P25hisjV06sqmfsA0Rx4bYhFoxEvIw3A4x9LsBIIfDpgDsPzS
NICAEhfA7fWXKK6UsOmuq1NZLTDmFe2zEHijVMovzm/qqvHfu7fCt5POlGtLOPZhXGCDZi0v1yiq
VyT7JTUW5P/rcLgzkfyKToozq36lEkXd6VSaLg==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
T4EV2kKcg5a7rlvEGr4AG3uvv0JzSoc0NQb9aIeE2gsKGq0oLel4q0oZ7eO6He8noW5KEowgkY0O
xDnerk/R4qxdSePYeRRmUg3KZ7hAHVEQrHpQ2RbYwK5mUIpQLjxCWRWzBjeWOce2bh0dAMR/4OH6
t95V8b9VWpgepcUXynGvLDv31tVgr+8LtXlgWTNBiJj2mTZ3gEVxpgGRwMGsampw9yKqBKoR+/hg
++FP8JJkrOSdB2bhnNaD4fZotMLkhYDrWvQm9z6rW7fwxA2oEI+oUqi+K+82oiLzeVWy7FhVyzgS
Y273uSE53DWk35UE9A6ebcI/xUl1iGqwdeZihA==

`pragma protect key_keyowner="Atrenta", key_keyname="ATR-SG-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=384)
`pragma protect key_block
gZRrJLrBkbil4BLf1tia07NzGL28f+Pk9zyPElbTDf8NEXCsuwTum6RjR5lvY/odzAYHlcKxpG+6
gwjafT2OV5gHqqtPXrRHcVU4p5LEzOOl5p3puqvK+1z2+YpHqxOZIIZPIH9kjtzNgcBmcU7S2sFN
zTxyAYuLL9sAN+AIQ9UrW4MXDWxUtdkwPaSyFIvuKoxOKUD5IXEY9NtBpz1zsABMKNHneOO8pAix
qg8S/uQ/XJ8Qggr+vE7HDUUMCsijNXvqbkLM3xf6dXFpOqanKxd6/GfTcob4sezm/hMOZ2xiXcfS
hsYUMRdO9H6fmhECfszoK2XMsMt6xM+vlLywWJ0I6u468qVFxROkf9vL+ZDq/tMiJOm7E1p+HDif
98f5v1OybtzlZJP9bDMwWYcsCqcDejCMQyYOgPCgg+2jTR1JezxuK7PpjyliT0rnu7FfI/0tRzbL
d5YqO79RN0byWVTTdIlTWzL/qBD8BLVqXzWs3M+up46dGPxbkzv44od4

`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="CDS_RSA_KEY_VER_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
A79lFm/8JnoMxv1MOWkY+AtU24uc6/CeGf6bjoYWLJXkzzHQooKleg9l+jH7oajoC3oVQh/sMXdi
3QmwZ5SKMt6sb03SC5BW7xPky8zyP6w8FRMCI2Tz1/GhozqjIbgSstUfCaemxIgj3rG7GkRYZ/2k
ualG2mpYDNyaxz1lMYaHfm7stH/IQlkCh6HHMbi7ImYJ6pILa828Ls3VREjo7dtXPS2ZDFxreSIH
2SZ3NpLJO0/umchZaUkt1xN0bsxgtGdOzSqGDpTJrU/ltmclBX199pmrXQa5p/q0FSLj2WkB043l
l3x1Rdipn49DvChkvbVzJP9aej4kwSPhvxHnHQ==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
GFpXmWYmUY46GvuVucUW1VOu3+gGtLxYW4Ho/p4wggZ+jWrpUVhz2RSAxu+ufiLHtM9oYgKPaSYT
DOeuIJGTnxGr20Vh6Nn3cc41TyKAf0vxN2fGISEQQWrjh9OOgNcBmJfaHsSq7+5dhCaIWlGrInVr
GD5TqclLzw6cHAuPGxMi2wD4rq16RkDJnQbPf8ptaskWz81NxZfyWAL4T2E24soybpln8+vuF+72
IQYfLQh/dDDsNHKNKwTKAtGjpFS8eVSbYnS+k3Am4loN8JRflh0+c4yGUo4EkuRzUFiIBrJOKylp
qicgwQw7vdbe+yPl6moUlvA1U2CjJ87bsXk5CA==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-PREC-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
Hzklq501x4qEym07A6+Vh+O6T5Q1srpTjckVi/KQ8/P6I6xpFqHBBikoKASz9mkWuvFaf6aly934
etGfnzZuPuKCoMPixevIcq9cgFblu43p0H0FR4BSbqN+A/K2utwAblPur01qwtH9nc1azxOtPedI
3KLsEBUN2ObidzkZIUbiQlQ72wru0lGZ5uN6iiNcLRnEhqjdjWiOHf5qGo+df2QyP6S5zRR7hGOd
N5h9/9towH2UQ++6hnOd4pjtl7PKHWlU92421M+LhruDkz4Bw6c7d7EVdbIcZ3ub+l/OnCyNwQsr
WUo2E+j4vd3zIVA0gzTA1oLX73BJ1oxwQdO3JA==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 51472)
`pragma protect data_block
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
jA==
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
