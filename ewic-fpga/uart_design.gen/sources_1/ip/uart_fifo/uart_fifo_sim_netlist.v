// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Tue Apr 28 18:01:34 2026
// Host        : alfonso-Modern-14-B4MW running 64-bit Ubuntu 24.04.2 LTS
// Command     : write_verilog -force -mode funcsim
//               /home/alfonso/TFM/ewic-fpga_v2/ewic-fpga/uart_design.gen/sources_1/ip/uart_fifo/uart_fifo_sim_netlist.v
// Design      : uart_fifo
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xcu280-fsvh2892-2L-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "uart_fifo,fifo_generator_v13_2_9,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "fifo_generator_v13_2_9,Vivado 2023.2" *) 
(* NotValidForBitStream *)
module uart_fifo
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
  uart_fifo_fifo_generator_v13_2_9 U0
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
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 51376)
`pragma protect data_block
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
MNyjX6xRquyWuG2NmGrZ8V2L7C9EL14vbFeqa3UJ+pPl1DuCqchfgzW34kbGSzZhz0tOrmfsbK+7
HqZdXQJIkvuhKgkNo86ybUysm/9ET4kEYZq9VB6/XN4zR9ruu8uFCuxm8kyAXnUl9BQHR76/1Q2g
+q6MWyqf0WhyOMUHq1i5/IWZnMr0I12WBdVhmQpx2ZC3g1Q1hNdX/fMkIuXlVRqbwK1h6MQuvTZF
TS3aRNVFBCqyd5pJJx6RELu1A+rTHX2vgfOJo1s4GDI+efIfJzsX7ILgPPgWL3HjAg+eQ4o5qpZW
q25nEaeDpc8xVX2Y+6bn0k4irWcir3dQdlOUeAi97KlFbHhTM8spJBMCQLjIPlpxV2w1iITkOy6Z
q2mXUipE6akDXjeeBaE+r6Pjt5CC6lVF8Q7NzecgjbMXo2dXJcNXNFxKcF9CoilX7G3KApvxFoTK
rKDYb3QFlb++v9to/dHBgytgDgVwsDowpQ7/9r9Qfc1T5Zj+kFnmg5a+HaZsg8xuNd2OZSllmBAL
3l0IXT7ZGEJmKVn4iwym45LJvlmM6l25r6ZVLQqWRHX4XRVewiIpJeoZrJSd89I98nnrp6P3Ku2P
ty2Gute5KIke0znRJhuZ8JZ075ZvsAKAvL84STl3k3S0pGGwMnTfo3NK+HeWEynZJKIsjjsCNP5r
vGkAjoFRQSoDKQ+EedcGzGymlFkuHL8rwenA2IxnvGXY8WowCOsMKjmD96C0azTOCpA4Z8MS2LTY
0dtWsCL03RpTRSgGfXeDDBZcyKNccyyfZSf587zoKOmDGI2pVNTgNgZJFQK9IobqfAe9skGOrYGa
NXJs72u4bquLxbmfa5bybZIorrHwnxpMKGzn/0HY4au01cXsERx/t65HadN7JmLaZKthbuVPPn1G
D18QHKGBq7e/gfnKh4YKIzpv/KaxiHiSCeL1NTawN0sBSbXupkbdrHU+qWMZ8Py3eFeG+aDfbJM+
oQNgahWFaZlKZSMr1piBqQZdxtTAJyZINFn/3iQ0eXv7paKHfa7axMs5Q8Ie2ANbeTmWTvKzdyKf
NhbgkiIsYtSUiDL/16SLqywcLZ7rgra+wqVl30qJa2bUDC7e1S/cefuPz/4VOhqNy1vfDA+DK3BH
wpw3FpFM7Ds2sLfZDegr0X+XfyYgUMLYzv893JsFixekg9vVL3jYW/NQ2tJwPVFc6jzbc/NR74eh
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
ZVTA2ur900q2obLGuTR55tuxLA==
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
