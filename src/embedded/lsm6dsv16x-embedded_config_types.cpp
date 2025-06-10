#include "embedded/lsm6dsv16x-embedded_config_types.hpp"

namespace lsm6dsv16x
{

    const char *PageSelRegister::to_string(Page p)
    {
        switch (p)
        {
        case Page::BASE:
            return "BASE";
        case Page::EMB_FUNC:
            return "EMB_FUNC";
        case Page::SENSOR_HUB:
            return "SENSOR_HUB";
        case Page::MLC:
            return "MLC";
        case Page::FSM:
            return "FSM";
        case Page::ADVANCED_FEATURES:
            return "ADV_FEATURES";
        default:
            return "UNKNOWN";
        }
    }

    void PageSelRegister::log() const
    {
        ESP_LOGI(TAG, "PAGE_SEL: raw=0x%02X page_sel=%s", raw_, to_string(page_sel_enum()));
    }

    std::string PageSelRegister::to_json() const
    {
        return std::string("{") +
               "\"page_sel\":\"" + to_string(page_sel_enum()) + "\"" +
               "}";
    }

    void EmbFuncEnARegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_EN_A: raw=0x%02X mlc_before_fsm_en=%d sign_motion_en=%d tilt_en=%d pedo_en=%d sflp_game_en=%d",
                 raw_, mlc_before_fsm_en(), sign_motion_en(), tilt_en(), pedo_en(), sflp_game_en());
    }

    std::string EmbFuncEnARegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_before_fsm_en\":" + (mlc_before_fsm_en() ? "true" : "false") + "," +
               "\"sign_motion_en\":" + (sign_motion_en() ? "true" : "false") + "," +
               "\"tilt_en\":" + (tilt_en() ? "true" : "false") + "," +
               "\"pedo_en\":" + (pedo_en() ? "true" : "false") + "," +
               "\"sflp_game_en\":" + (sflp_game_en() ? "true" : "false") +
               "}";
    }

    void EmbFuncEnBRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_EN_B: raw=0x%02X mlc_en=%d fifo_compr_en=%d fsm_en=%d",
                 raw_, mlc_en(), fifo_compr_en(), fsm_en());
    }

    std::string EmbFuncEnBRegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_en\":" + (mlc_en() ? "true" : "false") + "," +
               "\"fifo_compr_en\":" + (fifo_compr_en() ? "true" : "false") + "," +
               "\"fsm_en\":" + (fsm_en() ? "true" : "false") +
               "}";
    }

    

    void PageAddressRegister::log() const
    {
        ESP_LOGI(TAG, "PAGE_ADDRESS: raw=0x%02X page_addr=0x%02X", raw_, page_addr());
    }

    std::string PageAddressRegister::to_json() const
    {
        return std::string("{") +
               "\"page_addr\": " + std::to_string(page_addr()) +
               "}";
    }

    void PageValueRegister::log() const
    {
        ESP_LOGI(TAG, "PAGE_VALUE: raw=0x%02X page_value=0x%02X", raw_, page_value());
    }

    std::string PageValueRegister::to_json() const
    {
        return std::string("{") +
               "\"page_value\": " + std::to_string(page_value()) +
               "}";
    }

    void EmbFuncInt1Register::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_INT1: raw=0x%02X int1_fsm_lc=%d int1_sig_mot=%d int1_tilt=%d int1_step_detector=%d",
                 raw_, int1_fsm_lc(), int1_sig_mot(), int1_tilt(), int1_step_detector());
    }

    std::string EmbFuncInt1Register::to_json() const
    {
        return std::string("{") +
               "\"int1_fsm_lc\":" + (int1_fsm_lc() ? "true" : "false") + "," +
               "\"int1_sig_mot\":" + (int1_sig_mot() ? "true" : "false") + "," +
               "\"int1_tilt\":" + (int1_tilt() ? "true" : "false") + "," +
               "\"int1_step_detector\":" + (int1_step_detector() ? "true" : "false") +
               "}";
    }

    void FsmInt1Register::log() const
    {
        ESP_LOGI(TAG, "FSM_INT1: raw=0x%02X fsm1=%d fsm2=%d fsm3=%d fsm4=%d fsm5=%d fsm6=%d fsm7=%d fsm8=%d",
                 raw_,
                 int1_fsm1(), int1_fsm2(), int1_fsm3(), int1_fsm4(),
                 int1_fsm5(), int1_fsm6(), int1_fsm7(), int1_fsm8());
    }

    std::string FsmInt1Register::to_json() const
    {
        return std::string("{") +
               "\"int1_fsm1\":" + (int1_fsm1() ? "true" : "false") + "," +
               "\"int1_fsm2\":" + (int1_fsm2() ? "true" : "false") + "," +
               "\"int1_fsm3\":" + (int1_fsm3() ? "true" : "false") + "," +
               "\"int1_fsm4\":" + (int1_fsm4() ? "true" : "false") + "," +
               "\"int1_fsm5\":" + (int1_fsm5() ? "true" : "false") + "," +
               "\"int1_fsm6\":" + (int1_fsm6() ? "true" : "false") + "," +
               "\"int1_fsm7\":" + (int1_fsm7() ? "true" : "false") + "," +
               "\"int1_fsm8\":" + (int1_fsm8() ? "true" : "false") +
               "}";
    }

    void MlcInt1Register::log() const
    {
        ESP_LOGI(TAG, "MLC_INT1: raw=0x%02X int1_mlc1=%d int1_mlc2=%d int1_mlc3=%d int1_mlc4=%d",
                 raw_, int1_mlc1(), int1_mlc2(), int1_mlc3(), int1_mlc4());
    }

    std::string MlcInt1Register::to_json() const
    {
        return std::string("{") +
               "\"int1_mlc1\":" + (int1_mlc1() ? "true" : "false") + "," +
               "\"int1_mlc2\":" + (int1_mlc2() ? "true" : "false") + "," +
               "\"int1_mlc3\":" + (int1_mlc3() ? "true" : "false") + "," +
               "\"int1_mlc4\":" + (int1_mlc4() ? "true" : "false") +
               "}";
    }

    void EmbFuncInt2Register::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_INT2: raw=0x%02X int2_fsm_lc=%d int2_sig_mot=%d int2_tilt=%d int2_step_detector=%d",
                 raw_, int2_fsm_lc(), int2_sig_mot(), int2_tilt(), int2_step_detector());
    }

    std::string EmbFuncInt2Register::to_json() const
    {
        return std::string("{") +
               "\"int2_fsm_lc\":" + (int2_fsm_lc() ? "true" : "false") + "," +
               "\"int2_sig_mot\":" + (int2_sig_mot() ? "true" : "false") + "," +
               "\"int2_tilt\":" + (int2_tilt() ? "true" : "false") + "," +
               "\"int2_step_detector\":" + (int2_step_detector() ? "true" : "false") +
               "}";
    }

    void FsmInt2Register::log() const
    {
        ESP_LOGI(TAG, "FSM_INT2: raw=0x%02X fsm1=%d fsm2=%d fsm3=%d fsm4=%d fsm5=%d fsm6=%d fsm7=%d fsm8=%d",
                 raw_,
                 int2_fsm1(), int2_fsm2(), int2_fsm3(), int2_fsm4(),
                 int2_fsm5(), int2_fsm6(), int2_fsm7(), int2_fsm8());
    }

    std::string FsmInt2Register::to_json() const
    {
        return std::string("{") +
               "\"int2_fsm1\":" + (int2_fsm1() ? "true" : "false") + "," +
               "\"int2_fsm2\":" + (int2_fsm2() ? "true" : "false") + "," +
               "\"int2_fsm3\":" + (int2_fsm3() ? "true" : "false") + "," +
               "\"int2_fsm4\":" + (int2_fsm4() ? "true" : "false") + "," +
               "\"int2_fsm5\":" + (int2_fsm5() ? "true" : "false") + "," +
               "\"int2_fsm6\":" + (int2_fsm6() ? "true" : "false") + "," +
               "\"int2_fsm7\":" + (int2_fsm7() ? "true" : "false") + "," +
               "\"int2_fsm8\":" + (int2_fsm8() ? "true" : "false") +
               "}";
    }

    void MlcInt2Register::log() const
    {
        ESP_LOGI(TAG, "MLC_INT2: raw=0x%02X int2_mlc1=%d int2_mlc2=%d int2_mlc3=%d int2_mlc4=%d",
                 raw_, int2_mlc1(), int2_mlc2(), int2_mlc3(), int2_mlc4());
    }

    std::string MlcInt2Register::to_json() const
    {
        return std::string("{") +
               "\"int2_mlc1\":" + (int2_mlc1() ? "true" : "false") + "," +
               "\"int2_mlc2\":" + (int2_mlc2() ? "true" : "false") + "," +
               "\"int2_mlc3\":" + (int2_mlc3() ? "true" : "false") + "," +
               "\"int2_mlc4\":" + (int2_mlc4() ? "true" : "false") +
               "}";
    }

    

    void PageRwRegister::log() const
    {
        ESP_LOGI(TAG, "PAGE_RW: raw=0x%02X emb_func_lir=%d page_write=%d page_read=%d",
                 raw_, emb_func_lir(), page_write(), page_read());
    }

    std::string PageRwRegister::to_json() const
    {
        return std::string("{") +
               "\"emb_func_lir\":" + (emb_func_lir() ? "true" : "false") + "," +
               "\"page_write\":" + (page_write() ? "true" : "false") + "," +
               "\"page_read\":" + (page_read() ? "true" : "false") +
               "}";
    }

    void EmbFuncFifoEnARegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_FIFO_EN_A: raw=0x%02X mlc_fifo=%d step_counter_fifo=%d sflp_gbias_fifo=%d sflp_gravity_fifo=%d sflp_game_fifo=%d",
                 raw_, mlc_fifo_en(), step_counter_fifo_en(), sflp_gbias_fifo_en(), sflp_gravity_fifo_en(), sflp_game_fifo_en());
    }

    std::string EmbFuncFifoEnARegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_fifo_en\":" + (mlc_fifo_en() ? "true" : "false") + "," +
               "\"step_counter_fifo_en\":" + (step_counter_fifo_en() ? "true" : "false") + "," +
               "\"sflp_gbias_fifo_en\":" + (sflp_gbias_fifo_en() ? "true" : "false") + "," +
               "\"sflp_gravity_fifo_en\":" + (sflp_gravity_fifo_en() ? "true" : "false") + "," +
               "\"sflp_game_fifo_en\":" + (sflp_game_fifo_en() ? "true" : "false") +
               "}";
    }

    void EmbFuncFifoEnBRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_FIFO_EN_B: raw=0x%02X mlc_filter_feature_fifo_en=%d",
                 raw_, mlc_filter_feature_fifo_en());
    }

    std::string EmbFuncFifoEnBRegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_filter_feature_fifo_en\":" + (mlc_filter_feature_fifo_en() ? "true" : "false") +
               "}";
    }

    void FsmEnableRegister::log() const
    {
        ESP_LOGI(TAG, "FSM_ENABLE: raw=0x%02X fsm1=%d fsm2=%d fsm3=%d fsm4=%d fsm5=%d fsm6=%d fsm7=%d fsm8=%d",
                 raw_,
                 fsm1_en(), fsm2_en(), fsm3_en(), fsm4_en(),
                 fsm5_en(), fsm6_en(), fsm7_en(), fsm8_en());
    }

    std::string FsmEnableRegister::to_json() const
    {
        return std::string("{") +
               "\"fsm1_en\":" + (fsm1_en() ? "true" : "false") + "," +
               "\"fsm2_en\":" + (fsm2_en() ? "true" : "false") + "," +
               "\"fsm3_en\":" + (fsm3_en() ? "true" : "false") + "," +
               "\"fsm4_en\":" + (fsm4_en() ? "true" : "false") + "," +
               "\"fsm5_en\":" + (fsm5_en() ? "true" : "false") + "," +
               "\"fsm6_en\":" + (fsm6_en() ? "true" : "false") + "," +
               "\"fsm7_en\":" + (fsm7_en() ? "true" : "false") + "," +
               "\"fsm8_en\":" + (fsm8_en() ? "true" : "false") +
               "}";
    }

    void FsmLongCounterRegister::log() const
    {
        ESP_LOGI(TAG, "FSM_LONG_COUNTER: raw=0x%04X (%u)", get_raw(), get_raw());
    }

    std::string FsmLongCounterRegister::to_json() const
    {
        return std::string("{") +
               "\"fsm_long_counter\": " + std::to_string(get_raw()) +
               "}";
    }

    void IntAckMaskRegister::log() const
    {
        ESP_LOGI(TAG, "INT_ACK_MASK: raw=0x%02X mask7=%d mask6=%d mask5=%d mask4=%d mask3=%d mask2=%d mask1=%d mask0=%d",
                 raw_,
                 iack_mask7(), iack_mask6(), iack_mask5(), iack_mask4(),
                 iack_mask3(), iack_mask2(), iack_mask1(), iack_mask0());
    }

    std::string IntAckMaskRegister::to_json() const
    {
        return std::string("{") +
               "\"iack_mask0\":" + (iack_mask0() ? "true" : "false") + "," +
               "\"iack_mask1\":" + (iack_mask1() ? "true" : "false") + "," +
               "\"iack_mask2\":" + (iack_mask2() ? "true" : "false") + "," +
               "\"iack_mask3\":" + (iack_mask3() ? "true" : "false") + "," +
               "\"iack_mask4\":" + (iack_mask4() ? "true" : "false") + "," +
               "\"iack_mask5\":" + (iack_mask5() ? "true" : "false") + "," +
               "\"iack_mask6\":" + (iack_mask6() ? "true" : "false") + "," +
               "\"iack_mask7\":" + (iack_mask7() ? "true" : "false") +
               "}";
    }

    const char *SflpOdrRegister::to_string(SflpGameOdr odr)
    {
        switch (odr)
        {
        case SflpGameOdr::HZ_15:
            return "15Hz";
        case SflpGameOdr::HZ_30:
            return "30Hz";
        case SflpGameOdr::HZ_60:
            return "60Hz";
        case SflpGameOdr::HZ_120:
            return "120Hz";
        case SflpGameOdr::HZ_240:
            return "240Hz";
        case SflpGameOdr::HZ_480:
            return "480Hz";
        default:
            return "Unknown";
        }
    }

    void SflpOdrRegister::log() const
    {
        ESP_LOGI(TAG, "SFLP_ODR: raw=0x%02X sflp_game_odr=%s",
                 raw_, to_string(sflp_game_odr()));
    }

    std::string SflpOdrRegister::to_json() const
    {
        return std::string("{") +
               "\"sflp_game_odr\":\"" + to_string(sflp_game_odr()) + "\"" +
               "}";
    }

    const char *FsmOdrRegister::to_string(FsmOdr odr)
    {
        switch (odr)
        {
        case FsmOdr::HZ_15:
            return "15Hz";
        case FsmOdr::HZ_30:
            return "30Hz";
        case FsmOdr::HZ_60:
            return "60Hz";
        case FsmOdr::HZ_120:
            return "120Hz";
        case FsmOdr::HZ_240:
            return "240Hz";
        case FsmOdr::HZ_480:
            return "480Hz";
        case FsmOdr::HZ_960:
            return "960Hz";
        default:
            return "Unknown";
        }
    }

    void FsmOdrRegister::log() const
    {
        ESP_LOGI(TAG, "FSM_ODR: raw=0x%02X fsm_odr=%s", raw_, to_string(fsm_odr()));
    }

    std::string FsmOdrRegister::to_json() const
    {
        return std::string("{") +
               "\"fsm_odr\":\"" + to_string(fsm_odr()) + "\"" +
               "}";
    }

    const char *MlcOdrRegister::to_string(MlcOdr odr)
    {
        switch (odr)
        {
        case MlcOdr::HZ_15:
            return "15Hz";
        case MlcOdr::HZ_30:
            return "30Hz";
        case MlcOdr::HZ_60:
            return "60Hz";
        case MlcOdr::HZ_120:
            return "120Hz";
        case MlcOdr::HZ_240:
            return "240Hz";
        default:
            return "Unknown";
        }
    }

    void MlcOdrRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_ODR: raw=0x%02X mlc_odr=%s", raw_, to_string(mlc_odr()));
    }

    // JSON
    std::string MlcOdrRegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_odr\":\"" + to_string(mlc_odr()) + "\"" +
               "}";
    }

    void EmbFuncInitARegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_INIT_A: raw=0x%02X MLC_INIT=%d SIG_MOT_INIT=%d TILT_INIT=%d STEP_DET_INIT=%d SFLP_INIT=%d",
                 raw_,
                 mlc_before_fsm_init(), sig_mot_init(), tilt_init(),
                 step_det_init(), sflp_game_init());
    }

    std::string EmbFuncInitARegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_before_fsm_init\":" + (mlc_before_fsm_init() ? "true" : "false") + "," +
               "\"sig_mot_init\":" + (sig_mot_init() ? "true" : "false") + "," +
               "\"tilt_init\":" + (tilt_init() ? "true" : "false") + "," +
               "\"step_det_init\":" + (step_det_init() ? "true" : "false") + "," +
               "\"sflp_game_init\":" + (sflp_game_init() ? "true" : "false") +
               "}";
    }

    void EmbFuncInitBRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_INIT_B: raw=0x%02X MLC_INIT=%d FIFO_COMPR_INIT=%d FSM_INIT=%d",
                 raw_, mlc_init(), fifo_compr_init(), fsm_init());
    }

    std::string EmbFuncInitBRegister::to_json() const
    {
        return std::string("{") +
               "\"mlc_init\":" + (mlc_init() ? "true" : "false") + "," +
               "\"fifo_compr_init\":" + (fifo_compr_init() ? "true" : "false") + "," +
               "\"fsm_init\":" + (fsm_init() ? "true" : "false") +
               "}";
    }

} // namespace lsm6dsv16x