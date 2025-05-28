#include "status/lsm6dsv16x-status_types.hpp"

namespace lsm6dsv16x
{

    void WhoAmIRegister::log() const
    {
        ESP_LOGI(TAG, "WHO_AM_I = 0x%02X | %s", raw_, is_valid() ? "VALID" : "INVALID");
    }

    std::string WhoAmIRegister::to_json() const
    {
        return std::string("{") +
               "\"who_am_i\": " + std::to_string(value()) + "," +
               "\"is_valid\": " + (is_valid() ? "true" : "false") +
               "}";
    }

    void CtrlStatusRegister::log() const
    {
        ESP_LOGI(TAG, "CTRL_STATUS: raw=0x%02X fsm_wr_ctrl_status=%d", raw_, fsm_wr_ctrl_status());
    }

    std::string CtrlStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"fsm_wr_ctrl_status\":" + std::to_string(fsm_wr_ctrl_status()) +
               "}";
    }

    void FifoStatusRegister::log() const
    {
        ESP_LOGI(TAG,
                 "FIFO_STATUS2: raw=0x%04X diff_fifo=%d fifo_wtm_ia=%d fifo_ovr_ia=%d fifo_full_ia=%d counter_bdr_ia=%d fifo_ovr_latched=%d",
                 raw_,
                 diff_fifo(),
                 fifo_wtm_ia(),
                 fifo_ovr_ia(),
                 fifo_full_ia(),
                 counter_bdr_ia(),
                 fifo_ovr_latched()

        );
    }

    std::string FifoStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"diff_fifo\":" + std::to_string(diff_fifo()) + "," +
               "\"fifo_wtm_ia\":" + std::to_string(fifo_wtm_ia()) + "," +
               "\"fifo_ovr_ia\":" + std::to_string(fifo_ovr_ia()) + "," +
               "\"fifo_full_ia\":" + std::to_string(fifo_full_ia()) + "," +
               "\"counter_bdr_ia\":" + std::to_string(counter_bdr_ia()) + "," +
               "\"fifo_ovr_latched\":" + std::to_string(fifo_ovr_latched()) +
               "}";
    }

    void AllIntSrcRegister::log() const
    {
        ESP_LOGI(TAG,
                 "ALL_INT_SRC: raw=0x%02X emb_func_ia=%d shub_ia=%d sleep_change_ia=%d d6d_ia=%d tap_ia=%d wu_ia=%d ff_ia=%d",
                 raw_,
                 emb_func_ia(),
                 shub_ia(),
                 sleep_change_ia(),
                 d6d_ia(),
                 tap_ia(),
                 wu_ia(),
                 ff_ia());
    }

    std::string AllIntSrcRegister::to_json() const
    {
        return std::string("{") +
               "\"emb_func_ia\":" + std::to_string(emb_func_ia()) + "," +
               "\"shub_ia\":" + std::to_string(shub_ia()) + "," +
               "\"sleep_change_ia\":" + std::to_string(sleep_change_ia()) + "," +
               "\"d6d_ia\":" + std::to_string(d6d_ia()) + "," +
               "\"tap_ia\":" + std::to_string(tap_ia()) + "," +
               "\"wu_ia\":" + std::to_string(wu_ia()) + "," +
               "\"ff_ia\":" + std::to_string(ff_ia()) +
               "}";
    }

    void StatusRegRegister::log() const
    {
        ESP_LOGI(TAG,
                 "STATUS_REG: raw=0x%02X timestamp_endcount=%d ois_drdy=%d gda_eis=%d ah_qvarda=%d tda=%d gda=%d xlda=%d",
                 raw_,
                 timestamp_endcount(),
                 ois_drdy(),
                 gda_eis(),
                 ah_qvarda(),
                 tda(),
                 gda(),
                 xlda());
    }

    std::string StatusRegRegister::to_json() const
    {
        return std::string("{") +
               "\"timestamp_endcount\":" + std::to_string(timestamp_endcount()) + "," +
               "\"ois_drdy\":" + std::to_string(ois_drdy()) + "," +
               "\"gda_eis\":" + std::to_string(gda_eis()) + "," +
               "\"ah_qvarda\":" + std::to_string(ah_qvarda()) + "," +
               "\"tda\":" + std::to_string(tda()) + "," +
               "\"gda\":" + std::to_string(gda()) + "," +
               "\"xlda\":" + std::to_string(xlda()) +
               "}";
    }

    void UiStatusRegOisRegister::log() const
    {
        ESP_LOGI(TAG, "UI_STATUS_REG_OIS = 0x%02X | GYRO_SETTLING=%d GDA_OIS=%d XLDA_OIS=%d",
                 raw_, gyro_settling(), gda_ois(), xlda_ois());
    }

    std::string UiStatusRegOisRegister::to_json() const
    {
        return std::string("{") +
               "\"gyro_settling\":" + std::to_string(gyro_settling()) + "," +
               "\"gda_ois\":" + std::to_string(gda_ois()) + "," +
               "\"xlda_ois\":" + std::to_string(xlda_ois()) +
               "}";
    }

    void WakeUpSrcRegister::log() const
    {
        ESP_LOGI(TAG, "SLEEP_CHANGE_IA=%d FF_IA=%d SLEEP_STATE=%d WU_IA=%d X_WU=%d Y_WU=%d Z_WU=%d",
                 sleep_change_ia(), ff_ia(), sleep_state(), wu_ia(), x_wu(), y_wu(), z_wu());
    }

    std::string WakeUpSrcRegister::to_json() const
    {
        return std::string("{") +
               "\"sleep_change_ia\":" + std::to_string(sleep_change_ia()) + "," +
               "\"ff_ia\":" + std::to_string(ff_ia()) + "," +
               "\"sleep_state\":" + std::to_string(sleep_state()) + "," +
               "\"wu_ia\":" + std::to_string(wu_ia()) + "," +
               "\"x_wu\":" + std::to_string(x_wu()) + "," +
               "\"y_wu\":" + std::to_string(y_wu()) + "," +
               "\"z_wu\":" + std::to_string(z_wu()) +
               "}";
    }

    void TapSrcRegister::log() const
    {
        ESP_LOGI(TAG, "TAP_SRC = 0x%02X | TAP_IA=%d SINGLE_TAP=%d DOUBLE_TAP=%d TAP_SIGN=%d X_TAP=%d Y_TAP=%d Z_TAP=%d",
                 raw_, tap_ia(), single_tap(), double_tap(), tap_sign(), x_tap(), y_tap(), z_tap());
    }

    std::string TapSrcRegister::to_json() const
    {
        return std::string("{") +
               "\"tap_ia\":" + std::to_string(tap_ia()) + "," +
               "\"single_tap\":" + std::to_string(single_tap()) + "," +
               "\"double_tap\":" + std::to_string(double_tap()) + "," +
               "\"tap_sign\":" + std::to_string(tap_sign()) + "," +
               "\"x_tap\":" + std::to_string(x_tap()) + "," +
               "\"y_tap\":" + std::to_string(y_tap()) + "," +
               "\"z_tap\":" + std::to_string(z_tap()) +
               "}";
    }

    void D6dSrcRegister::log() const
    {
        ESP_LOGI(TAG, "D6D_SRC = 0x%02X | D6D_IA=%d ZH=%d ZL=%d YH=%d YL=%d XH=%d XL=%d",
                 raw_, d6d_ia(), zh(), zl(), yh(), yl(), xh(), xl());
    }

    std::string D6dSrcRegister::to_json() const
    {
        return std::string("{") +
               "\"d6d_ia\":" + std::to_string(d6d_ia()) + "," +
               "\"zh\":" + std::to_string(zh()) + "," +
               "\"zl\":" + std::to_string(zl()) + "," +
               "\"yh\":" + std::to_string(yh()) + "," +
               "\"yl\":" + std::to_string(yl()) + "," +
               "\"xh\":" + std::to_string(xh()) + "," +
               "\"xl\":" + std::to_string(xl()) +
               "}";
    }

    void StatusMasterMainpageRegister::log() const
    {
        ESP_LOGI(TAG, "STATUS_MASTER_MAINPAGE = 0x%02X | WR_ONCE_DONE=%d SLAVE3_NACK=%d SLAVE2_NACK=%d SLAVE1_NACK=%d SLAVE0_NACK=%d SENS_HUB_ENDOP=%d",
                 raw_, wr_once_done(), slave3_nack(), slave2_nack(), slave1_nack(), slave0_nack(), sens_hub_endop());
    }

    std::string StatusMasterMainpageRegister::to_json() const
    {
        return std::string("{") +
               "\"wr_once_done\":" + std::to_string(wr_once_done()) + "," +
               "\"slave3_nack\":" + std::to_string(slave3_nack()) + "," +
               "\"slave2_nack\":" + std::to_string(slave2_nack()) + "," +
               "\"slave1_nack\":" + std::to_string(slave1_nack()) + "," +
               "\"slave0_nack\":" + std::to_string(slave0_nack()) + "," +
               "\"sens_hub_endop\":" + std::to_string(sens_hub_endop()) +
               "}";
    }

    void EmbFuncStatusMainpageRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_STATUS_MAINPAGE = 0x%02X | IS_FSM_LC=%d IS_SIGMOT=%d IS_TILT=%d IS_STEP_DET=%d",
                 raw_, is_fsm_lc(), is_sigmot(), is_tilt(), is_step_det());
    }

    std::string EmbFuncStatusMainpageRegister::to_json() const
    {
        return std::string("{") +
               "\"is_fsm_lc\":" + std::to_string(is_fsm_lc()) + "," +
               "\"is_sigmot\":" + std::to_string(is_sigmot()) + "," +
               "\"is_tilt\":" + std::to_string(is_tilt()) + "," +
               "\"is_step_det\":" + std::to_string(is_step_det()) +
               "}";
    }

    void FsmStatusMainpageRegister::log() const
    {
        ESP_LOGI(TAG, "FSM_STATUS_MAINPAGE = 0x%02X | IS_FSM8=%d IS_FSM7=%d IS_FSM6=%d IS_FSM5=%d IS_FSM4=%d IS_FSM3=%d IS_FSM2=%d IS_FSM1=%d",
                 raw_, is_fsm8(), is_fsm7(), is_fsm6(), is_fsm5(), is_fsm4(), is_fsm3(), is_fsm2(), is_fsm1());
    }

    std::string FsmStatusMainpageRegister::to_json() const
    {
        return std::string("{") +
               "\"is_fsm8\":" + std::to_string(is_fsm8()) + "," +
               "\"is_fsm7\":" + std::to_string(is_fsm7()) + "," +
               "\"is_fsm6\":" + std::to_string(is_fsm6()) + "," +
               "\"is_fsm5\":" + std::to_string(is_fsm5()) + "," +
               "\"is_fsm4\":" + std::to_string(is_fsm4()) + "," +
               "\"is_fsm3\":" + std::to_string(is_fsm3()) + "," +
               "\"is_fsm2\":" + std::to_string(is_fsm2()) + "," +
               "\"is_fsm1\":" + std::to_string(is_fsm1()) +
               "}";
    }

    void MlcStatusMainpageRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_STATUS_MAINPAGE = 0x%02X | IS_MLC4=%d IS_MLC3=%d IS_MLC2=%d IS_MLC1=%d",
                 raw_, is_mlc4(), is_mlc3(), is_mlc2(), is_mlc1());
    }

    std::string MlcStatusMainpageRegister::to_json() const
    {
        return std::string("{") +
               "\"is_mlc4\":" + std::to_string(is_mlc4()) + "," +
               "\"is_mlc3\":" + std::to_string(is_mlc3()) + "," +
               "\"is_mlc2\":" + std::to_string(is_mlc2()) + "," +
               "\"is_mlc1\":" + std::to_string(is_mlc1()) +
               "}";
    }

} // namespace lsm6dsv16x
