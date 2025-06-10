#pragma once

#include "lsm6dsv16x-embfunc_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class EMBFUNC : public INTERFACE
    {
    public:
        explicit EMBFUNC(I2CDevices &dev) : INTERFACE(dev) {}

        // ----------- FunctionsEnableRegister
        DEFINE_FIELD(FunctionsEnableRegister, interrupts_enable, bool)
        DEFINE_FIELD(FunctionsEnableRegister, timestamp_en, bool)
        DEFINE_FIELD(FunctionsEnableRegister, dis_rst_lir_all_int, bool)
        DEFINE_FIELD(FunctionsEnableRegister, inact_en, FunctionsEnableRegister::InactEn)
        DEFINE_REGOUT(FunctionsEnableRegister)

        // ----------- DenCtrlRegister
        DEFINE_FIELD(DenRegister, lvl1_en, bool)
        DEFINE_FIELD(DenRegister, lvl2_en, bool)
        DEFINE_FIELD(DenRegister, den_xl_en, bool)
        DEFINE_FIELD(DenRegister, den_x, bool)
        DEFINE_FIELD(DenRegister, den_y, bool)
        DEFINE_FIELD(DenRegister, den_z, bool)
        DEFINE_FIELD(DenRegister, den_xl_g, bool)
        DEFINE_FIELD(DenRegister, trigger_mode, DenRegister::TriggerMode)
        DEFINE_REGOUT(DenRegister)

        // ----------- InactivityDurRegister
        DEFINE_FIELD(InactivityDurRegister, sleep_status_on_int, bool)
        DEFINE_FIELD(InactivityDurRegister, wu_inact_ths_w, InactivityDurRegister::WuInactThsW)
        DEFINE_FIELD(InactivityDurRegister, xl_inact_odr, InactivityDurRegister::XlInactOdr)
        DEFINE_FIELD(InactivityDurRegister, inact_dur, InactivityDurRegister::InactDur)
        DEFINE_REGOUT(InactivityDurRegister)

        // ----------- TapCfgRegister
        DEFINE_FIELD(TapCfgRegister, low_pass_on_6d, bool)
        DEFINE_FIELD(TapCfgRegister, hw_func_mask_xl_settl, bool)
        DEFINE_FIELD(TapCfgRegister, slope_fds, bool)
        DEFINE_FIELD(TapCfgRegister, tap_x_en, bool)
        DEFINE_FIELD(TapCfgRegister, tap_y_en, bool)
        DEFINE_FIELD(TapCfgRegister, tap_z_en, bool)
        DEFINE_FIELD(TapCfgRegister, lir, bool)
        DEFINE_FIELD(TapCfgRegister, tap_priority, TapCfgRegister::TapPriority)
        DEFINE_FIELD(TapCfgRegister, tap_ths_x, uint8_t)
        DEFINE_FIELD(TapCfgRegister, tap_ths_y, uint8_t)
        DEFINE_FIELD(TapCfgRegister, d4d_en, bool)
        DEFINE_FIELD(TapCfgRegister, sixd_ths, TapCfgRegister::SixdThs)
        DEFINE_FIELD(TapCfgRegister, tap_ths_z, uint8_t)
        DEFINE_REGOUT(TapCfgRegister)

        // ----------- TapDurRegister 
        DEFINE_FIELD(TapDurRegister, dur, uint8_t)
        DEFINE_FIELD(TapDurRegister, quiet, uint8_t)
        DEFINE_FIELD(TapDurRegister, shock, uint8_t)
        DEFINE_REGOUT(TapDurRegister)

        // ----------- WakeUpThsRegister
        DEFINE_FIELD(WakeUpThsRegister, single_double_tap, bool)
        DEFINE_FIELD(WakeUpThsRegister, usr_off_on_wu, bool)
        DEFINE_FIELD(WakeUpThsRegister, wk_ths, uint8_t)
        DEFINE_REGOUT(WakeUpThsRegister)

        // ----------- WakeUpDurRegister
        DEFINE_FIELD(WakeUpDurRegister, ff_dur_5, bool)
        DEFINE_FIELD(WakeUpDurRegister, wake_dur, uint8_t)
        DEFINE_FIELD(WakeUpDurRegister, sleep_dur, uint8_t)
        DEFINE_REGOUT(WakeUpDurRegister)

        // ----------- FreeFallRegister (ou autre nom exact du registre)
        DEFINE_FIELD(FreeFallRegister, ff_dur, uint8_t)
        DEFINE_FIELD(FreeFallRegister, ff_ths, FreeFallRegister::FfThs)
        DEFINE_REGOUT(FreeFallRegister)

        // ----------- MdCfgRegister
        DEFINE_FIELD(MdCfgRegister, int1_sleep_change, bool)
        DEFINE_FIELD(MdCfgRegister, int1_single_tap, bool)
        DEFINE_FIELD(MdCfgRegister, int1_wu, bool)
        DEFINE_FIELD(MdCfgRegister, int1_ff, bool)
        DEFINE_FIELD(MdCfgRegister, int1_double_tap, bool)
        DEFINE_FIELD(MdCfgRegister, int1_6d, bool)
        DEFINE_FIELD(MdCfgRegister, int1_emb_func, bool)
        DEFINE_FIELD(MdCfgRegister, int1_shub, bool)
        DEFINE_FIELD(MdCfgRegister, int2_sleep_change, bool)
        DEFINE_FIELD(MdCfgRegister, int2_single_tap, bool)
        DEFINE_FIELD(MdCfgRegister, int2_wu, bool)
        DEFINE_FIELD(MdCfgRegister, int2_ff, bool)
        DEFINE_FIELD(MdCfgRegister, int2_double_tap, bool)
        DEFINE_FIELD(MdCfgRegister, int2_6d, bool)
        DEFINE_FIELD(MdCfgRegister, int2_emb_func, bool)
        DEFINE_FIELD(MdCfgRegister, int2_timestamp, bool)
        DEFINE_REGOUT(MdCfgRegister)

        // ----------- HaodrCfgRegister
        DEFINE_FIELD(HaodrCfgRegister, haodr_sel, HaodrCfgRegister::HaodrSel)
        DEFINE_REGOUT(HaodrCfgRegister)

        // ----------- EmbFuncCfgRegister
        DEFINE_FIELD(EmbFuncCfgRegister, xl_dualc_batch_from_if, bool)
        DEFINE_FIELD(EmbFuncCfgRegister, emb_func_irq_mask_xl_settl, bool)
        DEFINE_FIELD(EmbFuncCfgRegister, emb_func_disable, bool)
        DEFINE_FIELD(EmbFuncCfgRegister, emb_func_irq_mask_g_settl, bool)
        DEFINE_REGOUT(EmbFuncCfgRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-EMBFUNC";
    };
}
