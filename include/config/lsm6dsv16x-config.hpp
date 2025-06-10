#pragma once

#include "lsm6dsv16x-config_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class CONFIG : public INTERFACE
    {
    public:
        explicit CONFIG(I2CDevices &dev) : INTERFACE(dev) {}

    // ----------- FuncCfgAccessRegister (cxa)
    DEFINE_FIELD(FuncCfgAccessRegister, emb_func_reg_access, bool)
    DEFINE_FIELD(FuncCfgAccessRegister, shub_reg_access, bool)
    DEFINE_FIELD(FuncCfgAccessRegister, fsm_wr_ctrl_en, bool)
    DEFINE_FIELD(FuncCfgAccessRegister, sw_por, bool)
    DEFINE_FIELD(FuncCfgAccessRegister, spi2_reset, bool)
    DEFINE_FIELD(FuncCfgAccessRegister, ois_ctrl_from_ui, bool)
    DEFINE_REGOUT(FuncCfgAccessRegister)

    // ----------- PinCtrlRegister
    DEFINE_FIELD(PinCtrlRegister, ois_pu_dis, bool)
    DEFINE_FIELD(PinCtrlRegister, sdo_pu_en, bool)
    DEFINE_FIELD(PinCtrlRegister, ibhr_por_en, PinCtrlRegister::IbhrPorEn)
    DEFINE_REGOUT(PinCtrlRegister)

    // ----------- IfCfgRegister
    DEFINE_FIELD(IfCfgRegister, sda_pu_en, bool)
    DEFINE_FIELD(IfCfgRegister, shub_pu_en, bool)
    DEFINE_FIELD(IfCfgRegister, asf_ctrl, bool)
    DEFINE_FIELD(IfCfgRegister, h_lactive, bool)
    DEFINE_FIELD(IfCfgRegister, pp_od, bool)
    DEFINE_FIELD(IfCfgRegister, sim, bool)
    DEFINE_FIELD(IfCfgRegister, i2c_i3c_disable, bool)
    DEFINE_REGOUT(IfCfgRegister)

    // ----------- OdrTrigCfgRegister
    DEFINE_FIELD(OdrTrigCfgRegister, odr_trig_nodr, uint8_t)
    DEFINE_REGOUT(OdrTrigCfgRegister)

    // ----------- FifoCtrlRegister
    DEFINE_FIELD(FifoCtrlRegister, wtm, uint8_t)
    DEFINE_FIELD(FifoCtrlRegister, stop_on_wtm, bool)
    DEFINE_FIELD(FifoCtrlRegister, fifo_compr_rt_en, bool)
    DEFINE_FIELD(FifoCtrlRegister, odr_chg_en, bool)
    DEFINE_FIELD(FifoCtrlRegister, uncompr_rate, FifoCtrlRegister::UncomprRate)
    DEFINE_FIELD(FifoCtrlRegister, xl_dualc_batch_from_fsm, bool)
    DEFINE_FIELD(FifoCtrlRegister, bdr_gy, FifoCtrlRegister::BdrGy)
    DEFINE_FIELD(FifoCtrlRegister, bdr_xl, FifoCtrlRegister::BdrXl)
    DEFINE_FIELD(FifoCtrlRegister, dec_ts_batch, FifoCtrlRegister::DecTsBatch)
    DEFINE_FIELD(FifoCtrlRegister, odr_t_batch, FifoCtrlRegister::OdrTBatch)
    DEFINE_FIELD(FifoCtrlRegister, g_eis_fifo_en, bool)
    DEFINE_FIELD(FifoCtrlRegister, fifo_mode, FifoCtrlRegister::FifoMode)
    DEFINE_REGOUT(FifoCtrlRegister)

    // ----------- CounterBdrRegister
    DEFINE_FIELD(CounterBdrRegister, trig_counter_bdr, CounterBdrRegister::TrigCounterBdr)
    DEFINE_FIELD(CounterBdrRegister, cnt_bdr_th_h, uint8_t)
    DEFINE_FIELD(CounterBdrRegister, cnt_bdr_th_l, uint8_t)
    DEFINE_FIELD(CounterBdrRegister, cnt_bdr_th, uint16_t)
    DEFINE_REGOUT(CounterBdrRegister)

    // ----------- IntCtrlRegister (INT1 flags)
    DEFINE_FIELD(IntCtrlRegister, int1_cnt_bdr, bool)
    DEFINE_FIELD(IntCtrlRegister, int1_fifo_full, bool)
    DEFINE_FIELD(IntCtrlRegister, int1_fifo_ovr, bool)
    DEFINE_FIELD(IntCtrlRegister, int1_fifo_th, bool)
    DEFINE_FIELD(IntCtrlRegister, int1_drdy_g, bool)
    DEFINE_FIELD(IntCtrlRegister, int1_drdy_xl, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_emb_func_endop, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_cnt_bdr, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_fifo_full, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_fifo_ovr, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_fifo_th, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_drdy_g_eis, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_drdy_g, bool)
    DEFINE_FIELD(IntCtrlRegister, int2_drdy_xl, bool)
    DEFINE_REGOUT(IntCtrlRegister)

    // ----------- CtrlEisRegister
    DEFINE_FIELD(CtrlEisRegister, odr_g_eis, CtrlEisRegister::OdrGEis)
    DEFINE_FIELD(CtrlEisRegister, lpf_g_eis_bw, bool)
    DEFINE_FIELD(CtrlEisRegister, g_eis_on_g_ois_out_reg, bool)
    DEFINE_FIELD(CtrlEisRegister, fs_g_eis, CtrlEisRegister::FsGEis)
    DEFINE_REGOUT(CtrlEisRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-CONFIG";
    };
}
