#include "lsm6dsv16x-config_types.hpp"

namespace lsm6dsv16x
{

    void FuncCfgAccessRegister::log() const
    {
        ESP_LOGI(TAG, "FUNC_CFG_ACCESS: raw=0x%02X emb_func_reg_access=%d shub_reg_access=%d fsm_wr_ctrl_en=%d sw_por=%d spi2_reset=%d ois_ctrl_from_ui=%d",
                 raw_, emb_func_reg_access(), shub_reg_access(), fsm_wr_ctrl_en(), sw_por(), spi2_reset(), ois_ctrl_from_ui());
    }
    std::string FuncCfgAccessRegister::to_json() const
    {
        return std::string("{") +
               "\"emb_func_reg_access\":" + (emb_func_reg_access() ? "true" : "false") + "," +
               "\"shub_reg_access\":" + (shub_reg_access() ? "true" : "false") + "," +
               "\"fsm_wr_ctrl_en\":" + (fsm_wr_ctrl_en() ? "true" : "false") + "," +
               "\"sw_por\":" + (sw_por() ? "true" : "false") + "," +
               "\"spi2_reset\":" + (spi2_reset() ? "true" : "false") + "," +
               "\"ois_ctrl_from_ui\":" + (ois_ctrl_from_ui() ? "true" : "false") +
               "}";
    }

    static const char *PinCtrlRegister::to_string(IbhrPorEn v)
    {
        switch (v)
        {
        case IbhrPorEn::CONFIG_RESET:
            return "Config reset";
        case IbhrPorEn::GLOBAL_RESET:
            return "Global reset";
        default:
            return "Unknown";
        }
    }

    void PinCtrlRegister::log() const
    {
        ESP_LOGI(TAG, "PIN_CTRL: raw=0x%02X ois_pu_dis=%d sdo_pu_en=%d ibhr_por_en=%s",
                 raw_, ois_pu_dis(), sdo_pu_en(), to_string(ibhr_por_en()));
    }
    std::string PinCtrlRegister::to_json() const
    {
        return std::string("{") +
               "\"ois_pu_dis\":" + (ois_pu_dis() ? "true" : "false") + "," +
               "\"sdo_pu_en\":" + (sdo_pu_en() ? "true" : "false") + "," +
               "\"ibhr_por_en\":\"" + to_string(ibhr_por_en()) + "\"" +
               "}";
    }

    void IfCfgRegister::log() const
    {
        ESP_LOGI(TAG, "IF_CFG: raw=0x%02X sda_pu_en=%d shub_pu_en=%d asf_ctrl=%d h_lactive=%d pp_od=%d sim=%d i2c_i3c_disable=%d",
                 raw_, sda_pu_en(), shub_pu_en(), asf_ctrl(), h_lactive(), pp_od(), sim(), i2c_i3c_disable());
    }
    std::string IfCfgRegister::to_json() const
    {
        return std::string("{") +
               "\"sda_pu_en\":" + (sda_pu_en() ? "true" : "false") + "," +
               "\"shub_pu_en\":" + (shub_pu_en() ? "true" : "false") + "," +
               "\"asf_ctrl\":" + (asf_ctrl() ? "true" : "false") + "," +
               "\"h_lactive\":" + (h_lactive() ? "true" : "false") + "," +
               "\"pp_od\":" + (pp_od() ? "true" : "false") + "," +
               "\"sim\":" + (sim() ? "true" : "false") + "," +
               "\"i2c_i3c_disable\":" + (i2c_i3c_disable() ? "true" : "false") +
               "}";
    }

    void OdrTrigCfgRegister::log() const
    {
        ESP_LOGI(TAG, "ODR_TRIG_CFG: raw=0x%02X odr_trig_nodr=%u", raw_, odr_trig_nodr());
    }
    std::string OdrTrigCfgRegister::to_json() const
    {
        return std::string("{") +
               "\"odr_trig_nodr\":" + std::to_string(odr_trig_nodr()) +
               "}";
    }

    const char *FifoCtrlRegister::to_string(UncomprRate v)
    {
        switch (v)
        {
        case UncomprRate::UNFORCED:
            return "Uncompressed not forced";
        case UncomprRate::EVERY_8:
            return "Every 8";
        case UncomprRate::EVERY_16:
            return "Every 16";
        case UncomprRate::EVERY_32:
            return "Every 32";
        default:
            return "Unknown";
        }
    }

    const char *FifoCtrlRegister::to_string(BdrGy v)
    {
        switch (v)
        {
        case BdrGy::NOT_BATCHED:
            return "Not batched";
        case BdrGy::HZ_1_875:
            return "1.875 Hz";
        case BdrGy::HZ_7_5:
            return "7.5 Hz";
        case BdrGy::HZ_15:
            return "15 Hz";
        case BdrGy::HZ_30:
            return "30 Hz";
        case BdrGy::HZ_60:
            return "60 Hz";
        case BdrGy::HZ_120:
            return "120 Hz";
        case BdrGy::HZ_240:
            return "240 Hz";
        case BdrGy::HZ_480:
            return "480 Hz";
        case BdrGy::HZ_960:
            return "960 Hz";
        case BdrGy::HZ_1_92K:
            return "1.92 kHz";
        case BdrGy::HZ_3_84K:
            return "3.84 kHz";
        case BdrGy::HZ_7_68K:
            return "7.68 kHz";
        case BdrGy::RESERVED:
            return "Reserved";
        default:
            return "Unknown";
        }
    }

    const char *FifoCtrlRegister::to_string(BdrXl v)
    {
        switch (v)
        {
        case BdrXl::NOT_BATCHED:
            return "Not batched";
        case BdrXl::HZ_1_875:
            return "1.875 Hz";
        case BdrXl::HZ_7_5:
            return "7.5 Hz";
        case BdrXl::HZ_15:
            return "15 Hz";
        case BdrXl::HZ_30:
            return "30 Hz";
        case BdrXl::HZ_60:
            return "60 Hz";
        case BdrXl::HZ_120:
            return "120 Hz";
        case BdrXl::HZ_240:
            return "240 Hz";
        case BdrXl::HZ_480:
            return "480 Hz";
        case BdrXl::HZ_960:
            return "960 Hz";
        case BdrXl::HZ_1_92K:
            return "1.92 kHz";
        case BdrXl::HZ_3_84K:
            return "3.84 kHz";
        case BdrXl::HZ_7_68K:
            return "7.68 kHz";
        case BdrXl::RESERVED:
            return "Reserved";
        default:
            return "Unknown";
        }
    }

    const char *FifoCtrlRegister::to_string(DecTsBatch v)
    {
        switch (v)
        {
        case DecTsBatch::NONE:
            return "None";
        case DecTsBatch::BY_8:
            return "By 8";
        case DecTsBatch::BY_16:
            return "By 16";
        case DecTsBatch::BY_32:
            return "By 32";
        default:
            return "Unknown";
        }
    }

    const char *FifoCtrlRegister::to_string(OdrTBatch v)
    {
        switch (v)
        {
        case OdrTBatch::NOT_BATCHED:
            return "Not batched";
        case OdrTBatch::HZ_1_875:
            return "1.875 Hz";
        case OdrTBatch::HZ_15:
            return "15 Hz";
        case OdrTBatch::HZ_60:
            return "60 Hz";
        default:
            return "Unknown";
        }
    }

    const char *FifoCtrlRegister::to_string(FifoMode v)
    {
        switch (v)
        {
        case FifoMode::BYPASS:
            return "Bypass";
        case FifoMode::FIFO:
            return "FIFO";
        case FifoMode::CONT_WTM2FULL:
            return "Continuous to WTM/full";
        case FifoMode::CONT2FIFO:
            return "Continuous to FIFO";
        case FifoMode::BYPASS2CONT:
            return "Bypass to Continuous";
        case FifoMode::RESERVED_101:
            return "Reserved";
        case FifoMode::CONTINUOUS:
            return "Continuous";
        case FifoMode::BYPASS2FIFO:
            return "Bypass to FIFO";
        default:
            return "Unknown";
        }
    }

    void FifoCtrlRegister::log() const
    {
        ESP_LOGI(TAG, "raw=0x%08X", raw_);
        ESP_LOGI(TAG, " stop_on_wtm=%d fifo_compr_rt_en=%d odr_chg_en=%d xl_dualc_batch_from_fsm=%d g_eis_fifo_en=%d",
                 stop_on_wtm(),
                 fifo_compr_rt_en(),
                 odr_chg_en(),
                 xl_dualc_batch_from_fsm(),
                 g_eis_fifo_en());
        ESP_LOGI(TAG, "uncompr_rate=%s", to_string(uncompr_rate()));
        ESP_LOGI(TAG, "bdr_gy=%s", to_string(bdr_gy()));
        ESP_LOGI(TAG, "bdr_xl=%s", to_string(bdr_xl()));
        ESP_LOGI(TAG, "dec_ts_batch=%s", to_string(dec_ts_batch()));
        ESP_LOGI(TAG, "odr_t_batch=%s", to_string(odr_t_batch()));
        ESP_LOGI(TAG, "fifo_mode=%s", to_string(fifo_mode()));
    }

    std::string FifoCtrlRegister::to_json() const
    {
        return std::string("{") +
               "\"wtm\":" + std::to_string(wtm()) + "\"," +
               "\"stop_on_wtm\":" + (stop_on_wtm() ? "true" : "false") + "," +
               "\"fifo_compr_rt_en\":" + (fifo_compr_rt_en() ? "true" : "false") + "," +
               "\"odr_chg_en\":" + (odr_chg_en() ? "true" : "false") + "," +
               "\"uncompr_rate\":\"" + to_string(uncompr_rate()) + "\"," +
               "\"xl_dualc_batch_from_fsm\":" + (xl_dualc_batch_from_fsm() ? "true" : "false") + "\"," +
               "\"bdr_gy\":\"" + to_string(bdr_gy()) + "\"," +
               "\"bdr_xl\":\"" + to_string(bdr_xl()) + "\"," +
               "\"dec_ts_batch\":\"" + to_string(dec_ts_batch()) + "\"," +
               "\"odr_t_batch\":\"" + to_string(odr_t_batch()) + "\"," +
               "\"g_eis_fifo_en\":" + (g_eis_fifo_en() ? "true" : "false") + "," +
               "\"fifo_mode\":\"" + to_string(fifo_mode()) + "\"" +
               "}";
    }

    static char *CounterBdrRegister::to_string(TrigCounterBdr v)
    {
        switch (v)
        {
        case TrigCounterBdr::ACCEL:
            return "Accelerometer batch";
        case TrigCounterBdr::GYRO:
            return "Gyroscope batch";
        case TrigCounterBdr::EIS:
            return "Gyro EIS batch";
        default:
            return "Reserved";
        }
    }

    void CounterBdrRegister::log() const
    {
        ESP_LOGI(TAG, "raw=0x%02X trig_counter_bdr=%s cnt_bdr_th=%u",
                 raw_, to_string(trig_counter_bdr()), cnt_bdr_th());
    }

    std::string CounterBdrRegister::to_json() const
    {
        return std::string("{") +
               "\"trig_counter_bdr\":\"" + to_string(trig_counter_bdr()) + "\"," +
               "\"cnt_bdr_th\":" + std::to_string(cnt_bdr_th()) +
               "}";
    }

    void IntCtrlRegister::log() const
    {
        ESP_LOGI(TAG, "raw=0x%04X " raw_)
        ESP_LOGI(TAG, "cnt_bdr=%d fifo_full=%d fifo_ovr=%d fifo_th=%d drdy_g=%d drdy_xl=%d",
                 cnt_bdr(), fifo_full(), fifo_ovr(), fifo_th(), drdy_g(), drdy_xl());
        ESP_LOGI(TAG, "emb_func_endop=%d cnt_bdr=%d fifo_full=%d fifo_ovr=%d fifo_th=%d drdy_g_eis=%d drdy_g=%d drdy_xl=%d",
                 emb_func_endop(), cnt_bdr(), fifo_full(), fifo_ovr(), fifo_th(), drdy_g_eis(), drdy_g(), drdy_xl());
    }

    std::string IntCtrlRegister::to_json() const
    {
        return std::string("{") +
               "\"cnt_bdr\":" + (cnt_bdr() ? "true" : "false") + "," +
               "\"fifo_full\":" + (fifo_full() ? "true" : "false") + "," +
               "\"fifo_ovr\":" + (fifo_ovr() ? "true" : "false") + "," +
               "\"fifo_th\":" + (fifo_th() ? "true" : "false") + "," +
               "\"drdy_g\":" + (drdy_g() ? "true" : "false") + "," +
               "\"drdy_xl\":" + (drdy_xl() ? "true" : "false") + "," +
               "\"emb_func_endop\":" + (emb_func_endop() ? "true" : "false") + "," +
               "\"cnt_bdr\":" + (cnt_bdr() ? "true" : "false") + "," +
               "\"fifo_full\":" + (fifo_full() ? "true" : "false") + "," +
               "\"fifo_ovr\":" + (fifo_ovr() ? "true" : "false") + "," +
               "\"fifo_th\":" + (fifo_th() ? "true" : "false") + "," +
               "\"drdy_g_eis\":" + (drdy_g_eis() ? "true" : "false") + "," +
               "\"drdy_g\":" + (drdy_g() ? "true" : "false") + "," +
               "\"drdy_xl\":" + (drdy_xl() ? "true" : "false") +
               "}";
    }

    const char *CtrlEisRegister::to_string(OdrGEis v)
    {
        switch (v)
        {
        case OdrGEis::OFF:
            return "EIS off";
        case OdrGEis::HZ_1920:
            return "1.92 kHz";
        case OdrGEis::HZ_960:
            return "960 Hz";
        case OdrGEis::RESERVED:
            return "Reserved";
        default:
            return "Unknown";
        }
    }

    const char *CtrlEisRegister::to_string(FsGEis v)
    {
        switch (v)
        {
        case FsGEis::DPS_125:
            return "±125 dps";
        case FsGEis::DPS_250:
            return "±250 dps";
        case FsGEis::DPS_500:
            return "±500 dps";
        case FsGEis::DPS_1000:
            return "±1000 dps";
        case FsGEis::DPS_2000:
            return "±2000 dps";
        case FsGEis::RESERVED_101:
            return "Reserved (101)";
        case FsGEis::RESERVED_110:
            return "Reserved (110)";
        case FsGEis::RESERVED_111:
            return "Reserved (111)";
        default:
            return "Unknown";
        }
    }

    void CtrlEisRegister::log() const
    {
        ESP_LOGI(TAG, "CTRL_EIS: raw=0x%02X", raw_);
        ESP_LOGI(TAG, "  ODR_G_EIS: %s", to_string(odr_g_eis()));
        ESP_LOGI(TAG, "  LPF_G_EIS_BW: %d", lpf_g_eis_bw());
        ESP_LOGI(TAG, "  G_EIS_ON_G_OIS_OUT_REG: %d", g_eis_on_g_ois_out_reg());
        ESP_LOGI(TAG, "  FS_G_EIS: %s", to_string(fs_g_eis()));
    }

    std::string CtrlEisRegister::to_json() const
    {
        return std::string("{") + "\"odr_g_eis\":\"" + to_string(odr_g_eis()) + "\"," + "\"lpf_g_eis_bw\":" + std::to_string(lpf_g_eis_bw()) + "," + "\"g_eis_on_g_ois_out_reg\":" + std::to_string(g_eis_on_g_ois_out_reg()) + "," + "\"fs_g_eis\":\"" + to_string(fs_g_eis()) + "\"" + "}";
    }

} // namespace lsm6dsv16x
