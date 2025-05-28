#include "config/lsm6dsv16x-embfunc_types.hpp"

namespace lsm6dsv16x
{

    const char *FunctionsEnableRegister::to_string(InactEn v)
    {
        switch (v)
        {
        case InactEn::NONE:
            return "stationary/motion-only interrupts";
        case InactEn::XL_LOW_POWER:
            return "acc low-power, gyro unchanged";
        case InactEn::XL_LOW_PWR_GYRO_SLEEP:
            return "acc low-power, gyro sleep";
        case InactEn::XL_LOW_PWR_GYRO_PD:
            return "acc low-power, gyro power-down";
        default:
            return "Unknown";
        }
    }

    void FunctionsEnableRegister::log() const
    {
        ESP_LOGI(TAG, "FUNCTIONS_ENABLE: raw=0x%02X interrupts_enable=%d timestamp_en=%d dis_rst_lir_all_int=%d inact_en=%s",
                 raw_,
                 interrupts_enable(),
                 timestamp_en(),
                 dis_rst_lir_all_int(),
                 to_string(inact_en()));
    }

    std::string FunctionsEnableRegister::to_json() const
    {
        return std::string("{") +
               "\"interrupts_enable\":" + (interrupts_enable() ? "true" : "false") + "," +
               "\"timestamp_en\":" + (timestamp_en() ? "true" : "false") + "," +
               "\"dis_rst_lir_all_int\":" + (dis_rst_lir_all_int() ? "true" : "false") + "," +
               "\"inact_en\":\"" + to_string(inact_en()) + "\"" +
               "}";
    }

    const char *DenRegister::to_string(TriggerMode m)
    {
        switch (m)
        {
        case TriggerMode::DISABLED:
            return "disabled";
        case TriggerMode::SENSITIVE:
            return "level-sensitive trigger";
        case TriggerMode::LATCHED:
            return "level-sensitive latched";
        default:
            return "unknown";
        }
    }

    void DenRegister::log() const
    {
        ESP_LOGI(TAG, "DEN: raw=0x%02X lvl1_en=%d lvl2_en=%d den_xl_en=%d den_x=%d den_y=%d den_z=%d den_xl_g=%d trigger_mode=%s",
                 raw_, lvl1_en(), lvl2_en(), den_xl_en(), den_x(), den_y(), den_z(), den_xl_g(), to_string(trigger_mode()));
    }

    std::string DenRegister::to_json() const
    {
        return std::string("{") +
               "\"lvl1_en\":" + (lvl1_en() ? "true" : "false") + "," +
               "\"lvl2_en\":" + (lvl2_en() ? "true" : "false") + "," +
               "\"den_xl_en\":" + (den_xl_en() ? "true" : "false") + "," +
               "\"den_x\":" + (den_x() ? "true" : "false") + "," +
               "\"den_y\":" + (den_y() ? "true" : "false") + "," +
               "\"den_z\":" + (den_z() ? "true" : "false") + "," +
               "\"den_xl_g\":" + (den_xl_g() ? "true" : "false") + "," +
               "\"trigger_mode\":\"" + to_string(trigger_mode()) + "\"" +
               "}";
    }

    const char *InactivityDurRegister::to_string(WuInactThsW v)
    {
        switch (v)
        {
        case WuInactThsW::MG_7_8:
            return "7.8 mg/LSB";
        case WuInactThsW::MG_15_6:
            return "15.6 mg/LSB";
        case WuInactThsW::MG_31_3:
            return "31.3 mg/LSB";
        case WuInactThsW::MG_62_5:
            return "62.5 mg/LSB";
        case WuInactThsW::MG_125:
            return "125 mg/LSB";
        case WuInactThsW::MG_250:
            return "250 mg/LSB";
        default:
            return "reserved";
        }
    }

    const char *InactivityDurRegister::to_string(XlInactOdr v)
    {
        switch (v)
        {
        case XlInactOdr::HZ_1_875:
            return "1.875 Hz";
        case XlInactOdr::HZ_15:
            return "15 Hz";
        case XlInactOdr::HZ_30:
            return "30 Hz";
        case XlInactOdr::HZ_60:
            return "60 Hz";
        default:
            return "unknown";
        }
    }

    const char *InactivityDurRegister::to_string(InactDur v)
    {
        switch (v)
        {
        case InactDur::IMMEDIATE:
            return "immediate";
        case InactDur::TWO:
            return "after two";
        case InactDur::THREE:
            return "after three";
        case InactDur::FOUR:
            return "after four";
        default:
            return "unknown";
        }
    }

    void InactivityDurRegister::log() const
    {
        ESP_LOGI(TAG, "INACTIVITY_DUR: raw=0x%02X sleep_status_on_int=%d wu_inact_ths_w=%s xl_inact_odr=%s inact_dur=%s",
                 raw_,
                 sleep_status_on_int(),
                 to_string(wu_inact_ths_w()),
                 to_string(xl_inact_odr()),
                 to_string(inact_dur()));
    }

    std::string InactivityDurRegister::to_json() const
    {
        return std::string("{") +
               "\"sleep_status_on_int\":" + (sleep_status_on_int() ? "true" : "false") + "," +
               "\"wu_inact_ths_w\":\"" + to_string(wu_inact_ths_w()) + "\"," +
               "\"xl_inact_odr\":\"" + to_string(xl_inact_odr()) + "\"," +
               "\"inact_dur\":\"" + to_string(inact_dur()) + "\"" +
               "}";
    }

    void TapCfg0Register::log() const
    {
        ESP_LOGI(TAG,
                 "TAP_CFG0: raw=0x%02X low_pass_on_6d=%d hw_func_mask_xl_settl=%d slope_fds=%d tap_x=%d tap_y=%d tap_z=%d lir=%d",
                 raw_,
                 low_pass_on_6d(),
                 hw_func_mask_xl_settl(),
                 slope_fds(),
                 tap_x_en(),
                 tap_y_en(),
                 tap_z_en(),
                 lir());
    }

    std::string TapCfg0Register::to_json() const
    {
        return std::string("{") +
               "\"low_pass_on_6d\":" + std::to_string(low_pass_on_6d()) + "," +
               "\"hw_func_mask_xl_settl\":" + std::to_string(hw_func_mask_xl_settl()) + "," +
               "\"slope_fds\":" + std::to_string(slope_fds()) + "," +
               "\"tap_x_en\":" + std::to_string(tap_x_en()) + "," +
               "\"tap_y_en\":" + std::to_string(tap_y_en()) + "," +
               "\"tap_z_en\":" + std::to_string(tap_z_en()) + "," +
               "\"lir\":" + std::to_string(lir()) +
               "}";
    }

    void TapCfg1Register::log() const
    {
        ESP_LOGI(TAG, "TAP_CFG1: raw=0x%02X tap_priority=%s tap_ths_x=%u",
                 raw_, to_string(tap_priority()), tap_ths_x());
    }

    std::string TapCfg1Register::to_json() const
    {
        return std::string("{") +
               "\"tap_priority\":\"" + to_string(tap_priority()) + "\"," +
               "\"tap_ths_x\":" + std::to_string(tap_ths_x()) +
               "}";
    }

    const char *TapCfg1Register::to_string(TapPriority v)
    {
        switch (v)
        {
        case TapPriority::XYZ:
            return "X>Y>Z";
        case TapPriority::YXZ:
            return "Y>X>Z";
        case TapPriority::YZX:
            return "Y>Z>X";
        case TapPriority::ZYX:
            return "Z>Y>X";
        case TapPriority::ZXY:
            return "Z>X>Y";
        case TapPriority::XZY:
            return "X>Z>Y";
        case TapPriority::XXZ:
            return "X>X>Z";
        case TapPriority::ZZZ:
            return "Z>Z>Z";
        default:
            return "Unknown";
        }
    }

    void TapCfg2Register::log() const
    {
        ESP_LOGI(TAG, "TAP_CFG2: raw=0x%02X tap_ths_y=%u", raw_, tap_ths_y());
    }

    std::string TapCfg2Register::to_json() const
    {
        return std::string("{") +
               "\"tap_ths_y\":" + std::to_string(tap_ths_y()) +
               "}";
    }

    static const char *TapThs6DRegister::to_string(SixdThs v)
    {
        switch (v)
        {
        case SixdThs::DEG_80:
            return "80 deg";
        case SixdThs::DEG_70:
            return "70 deg";
        case SixdThs::DEG_60:
            return "60 deg";
        case SixdThs::DEG_50:
            return "50 deg";
        default:
            return "Unknown";
        }
    }

    void TapThs6DRegister::log() const
    {
        ESP_LOGI(TAG, "TAP_THS_6D: raw=0x%02X d4d_en=%d sixd_ths=%s tap_ths_z=%d",
                 raw_, d4d_en(), to_string(sixd_ths()), tap_ths_z());
    }

    std::string TapThs6DRegister::to_json() const
    {
        return std::string("{") +
               "\"d4d_en\":" + std::to_string(d4d_en()) + "," +
               "\"sixd_ths\":\"" + to_string(sixd_ths()) + "\"," +
               "\"tap_ths_z\":" + std::to_string(tap_ths_z()) +
               "}";
    }

    void TapDurRegister::log() const
    {
        ESP_LOGI(TAG, "TAP_DUR (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  DUR  = %u", dur());
        ESP_LOGI(TAG, "  QUIET= %u", quiet());
        ESP_LOGI(TAG, "  SHOCK= %u", shock());
    }
    std::string TapDurRegister::to_json() const
    {
        return std::string("{") +
               "\"dur\":" + std::to_string(dur()) +
               ",\"quiet\":" + std::to_string(quiet()) +
               ",\"shock\":" + std::to_string(shock()) +
               "}";
    }

    void WakeUpThsRegister::log() const
    {
        ESP_LOGI(TAG, "WAKE_UP_THS (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  single_double_tap = %d", single_double_tap());
        ESP_LOGI(TAG, "  usr_off_on_wu     = %d", usr_off_on_wu());
        ESP_LOGI(TAG, "  wk_ths            = %u", wk_ths());
    }
    std::string WakeUpThsRegister::to_json() const
    {
        return std::string("{") +
               "\"single_double_tap\":" + std::to_string(single_double_tap()) +
               ",\"usr_off_on_wu\":" + std::to_string(usr_off_on_wu()) +
               ",\"wk_ths\":" + std::to_string(wk_ths()) +
               "}";
    }

    void WakeUpDurRegister::log() const
    {
        ESP_LOGI(TAG, "WAKE_UP_DUR (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  ff_dur_5   = %d", ff_dur_5());
        ESP_LOGI(TAG, "  wake_dur   = %u", wake_dur());
        ESP_LOGI(TAG, "  sleep_dur  = %u", sleep_dur());
    }

    std::string WakeUpDurRegister::to_json() const
    {
        return std::string("{") +
               "\"ff_dur_5\":" + std::to_string(ff_dur_5()) +
               ",\"wake_dur\":" + std::to_string(wake_dur()) +
               ",\"sleep_dur\":" + std::to_string(sleep_dur()) +
               "}";
    }

    static const char *FreeFallRegister::to_string(FfThs v)
    {
        switch (v)
        {
        case FfThs::MG_156:
            return "156 mg";
        case FfThs::MG_219:
            return "219 mg";
        case FfThs::MG_250:
            return "250 mg";
        case FfThs::MG_312:
            return "312 mg";
        case FfThs::MG_344:
            return "344 mg";
        case FfThs::MG_406:
            return "406 mg";
        case FfThs::MG_469:
            return "469 mg";
        case FfThs::MG_500:
            return "500 mg";
        default:
            return "Unknown";
        }
    }

    void FreeFallRegister::log() const
    {
        ESP_LOGI(TAG, "FREE_FALL (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  ff_dur    = %u", ff_dur());
        ESP_LOGI(TAG, "  ff_ths    = %u (%s)", static_cast<uint8_t>(ff_ths()), to_string(ff_ths()));
    }

    std::string FreeFallRegister::to_json() const
    {
        return std::string("{") +
               "\"ff_dur\":" + std::to_string(ff_dur()) +
               ",\"ff_ths\":" + std::to_string(static_cast<uint8_t>(ff_ths())) +
               ",\"ff_ths_str\":\"" + to_string(ff_ths()) + "\"" +
               "}";
    }

    void Md1CfgRegister::log() const
    {
        ESP_LOGI(TAG, "MD1_CFG (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  int1_sleep_change = %d", int1_sleep_change());
        ESP_LOGI(TAG, "  int1_single_tap   = %d", int1_single_tap());
        ESP_LOGI(TAG, "  int1_wu           = %d", int1_wu());
        ESP_LOGI(TAG, "  int1_ff           = %d", int1_ff());
        ESP_LOGI(TAG, "  int1_double_tap   = %d", int1_double_tap());
        ESP_LOGI(TAG, "  int1_6d           = %d", int1_6d());
        ESP_LOGI(TAG, "  int1_emb_func     = %d", int1_emb_func());
        ESP_LOGI(TAG, "  int1_shub         = %d", int1_shub());
    }

    std::string Md1CfgRegister::to_json() const
    {
        return std::string("{") +
               "\"int1_sleep_change\":" + std::to_string(int1_sleep_change()) + "," +
               "\"int1_single_tap\":" + std::to_string(int1_single_tap()) + "," +
               "\"int1_wu\":" + std::to_string(int1_wu()) + "," +
               "\"int1_ff\":" + std::to_string(int1_ff()) + "," +
               "\"int1_double_tap\":" + std::to_string(int1_double_tap()) + "," +
               "\"int1_6d\":" + std::to_string(int1_6d()) + "," +
               "\"int1_emb_func\":" + std::to_string(int1_emb_func()) + "," +
               "\"int1_shub\":" + std::to_string(int1_shub()) +
               "}";
    }

    void Md2CfgRegister::log() const
    {
        ESP_LOGI(TAG, "MD2_CFG (0x%02X): raw=0x%02X", reg_addr, raw_);
        ESP_LOGI(TAG, "  int2_sleep_change = %d", int2_sleep_change());
        ESP_LOGI(TAG, "  int2_single_tap   = %d", int2_single_tap());
        ESP_LOGI(TAG, "  int2_wu           = %d", int2_wu());
        ESP_LOGI(TAG, "  int2_ff           = %d", int2_ff());
        ESP_LOGI(TAG, "  int2_double_tap   = %d", int2_double_tap());
        ESP_LOGI(TAG, "  int2_6d           = %d", int2_6d());
        ESP_LOGI(TAG, "  int2_emb_func     = %d", int2_emb_func());
        ESP_LOGI(TAG, "  int2_timestamp    = %d", int2_timestamp());
    }

    std::string Md2CfgRegister::to_json() const
    {
        return std::string("{") +
               "\"int2_sleep_change\":" + std::to_string(int2_sleep_change()) + "," +
               "\"int2_single_tap\":" + std::to_string(int2_single_tap()) + "," +
               "\"int2_wu\":" + std::to_string(int2_wu()) + "," +
               "\"int2_ff\":" + std::to_string(int2_ff()) + "," +
               "\"int2_double_tap\":" + std::to_string(int2_double_tap()) + "," +
               "\"int2_6d\":" + std::to_string(int2_6d()) + "," +
               "\"int2_emb_func\":" + std::to_string(int2_emb_func()) + "," +
               "\"int2_timestamp\":" + std::to_string(int2_timestamp()) +
               "}";
    }

    static const char *HaodrCfgRegister::to_string(HaodrSel v)
    {
        switch (v)
        {
        case HaodrSel::SET0:
            return "SET0";
        case HaodrSel::SET1:
            return "SET1";
        case HaodrSel::SET2:
            return "SET2";
        case HaodrSel::SET3:
            return "SET3";
        default:
            return "Unknown";
        }
    }

    void HaodrCfgRegister::log() const
    {
        ESP_LOGI(TAG, "HAODR_CFG (0x%02X): raw=0x%02X haodr_sel=%s",
                 reg_addr, raw_, to_string(haodr_sel()));
    }
    std::string HaodrCfgRegister::to_json() const
    {
        return std::string("{") +
               "\"haodr_sel\":\"" + to_string(haodr_sel()) + "\"" +
               "}";
    }

    void EmbFuncCfgRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_CFG: raw=0x%02X", raw_);
        ESP_LOGI(TAG, "  xl_dualc_batch_from_if=%d", xl_dualc_batch_from_if());
        ESP_LOGI(TAG, "  emb_func_irq_mask_g_settl=%d", emb_func_irq_mask_g_settl());
        ESP_LOGI(TAG, "  emb_func_irq_mask_xl_settl=%d", emb_func_irq_mask_xl_settl());
        ESP_LOGI(TAG, "  emb_func_disable=%d", emb_func_disable());
    }

    std::string EmbFuncCfgRegister::to_json() const
    {
        return std::string("{") + "\"xl_dualc_batch_from_if\":" + std::to_string(xl_dualc_batch_from_if()) + "," + "\"emb_func_irq_mask_g_settl\":" + std::to_string(emb_func_irq_mask_g_settl()) + "," + "\"emb_func_irq_mask_xl_settl\":" + std::to_string(emb_func_irq_mask_xl_settl()) + "," + "\"emb_func_disable\":" + std::to_string(emb_func_disable()) + "}";
    }

} // namespace lsm6dsv16x
