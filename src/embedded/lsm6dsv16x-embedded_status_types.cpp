#include "embedded/lsm6dsv16x-embedded_status_types.hpp"

namespace lsm6dsv16x
{
void EmbFuncExecStatusRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_EXEC_STATUS: raw=0x%02X emb_func_exec_ovr=%d emb_func_endop=%d",
                 raw_, emb_func_exec_ovr(), emb_func_endop());
    }

    std::string EmbFuncExecStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"emb_func_exec_ovr\":" + (emb_func_exec_ovr() ? "true" : "false") + "," +
               "\"emb_func_endop\":" + (emb_func_endop() ? "true" : "false") +
               "}";
    }

    void EmbFuncStatusRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_STATUS: raw=0x%02X is_fsm_lc=%d is_sigmot=%d is_tilt=%d is_step_det=%d",
                 raw_, is_fsm_lc(), is_sigmot(), is_tilt(), is_step_det());
    }

    std::string EmbFuncStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"is_fsm_lc\":" + (is_fsm_lc() ? "true" : "false") + "," +
               "\"is_sigmot\":" + (is_sigmot() ? "true" : "false") + "," +
               "\"is_tilt\":" + (is_tilt() ? "true" : "false") + "," +
               "\"is_step_det\":" + (is_step_det() ? "true" : "false") +
               "}";
    }

    void FsmStatusRegister::log() const
    {
        ESP_LOGI(TAG, "FSM_STATUS: raw=0x%02X fsm1=%d fsm2=%d fsm3=%d fsm4=%d fsm5=%d fsm6=%d fsm7=%d fsm8=%d",
                 raw_,
                 is_fsm1(), is_fsm2(), is_fsm3(), is_fsm4(),
                 is_fsm5(), is_fsm6(), is_fsm7(), is_fsm8());
    }

    std::string FsmStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"fsm1\":" + (is_fsm1() ? "true" : "false") + "," +
               "\"fsm2\":" + (is_fsm2() ? "true" : "false") + "," +
               "\"fsm3\":" + (is_fsm3() ? "true" : "false") + "," +
               "\"fsm4\":" + (is_fsm4() ? "true" : "false") + "," +
               "\"fsm5\":" + (is_fsm5() ? "true" : "false") + "," +
               "\"fsm6\":" + (is_fsm6() ? "true" : "false") + "," +
               "\"fsm7\":" + (is_fsm7() ? "true" : "false") + "," +
               "\"fsm8\":" + (is_fsm8() ? "true" : "false") +
               "}";
    }

    void MlcStatusRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_STATUS: raw=0x%02X is_mlc1=%d is_mlc2=%d is_mlc3=%d is_mlc4=%d",
                 raw_, is_mlc1(), is_mlc2(), is_mlc3(), is_mlc4());
    }

    std::string MlcStatusRegister::to_json() const
    {
        return std::string("{") +
               "\"is_mlc1\":" + (is_mlc1() ? "true" : "false") + "," +
               "\"is_mlc2\":" + (is_mlc2() ? "true" : "false") + "," +
               "\"is_mlc3\":" + (is_mlc3() ? "true" : "false") + "," +
               "\"is_mlc4\":" + (is_mlc4() ? "true" : "false") +
               "}";
    }

    void EmbFuncSrcRegister::log() const
    {
        ESP_LOGI(TAG, "EMB_FUNC_SRC: raw=0x%02X PEDO_RST_STEP=%d STEP_DETECTED=%d STEP_COUNT_DELTA_IA=%d STEP_OVERFLOW=%d BIT_SET=%d",
                 raw_,
                 pedo_rst_step(),
                 step_detected(),
                 step_count_delta_ia(),
                 step_overflow(),
                 stepcounter_bit_set());
    }

    std::string EmbFuncSrcRegister::to_json() const
    {
        return std::string("{") +
               "\"pedo_rst_step\":" + (pedo_rst_step() ? "true" : "false") + "," +
               "\"step_detected\":" + (step_detected() ? "true" : "false") + "," +
               "\"step_count_delta_ia\":" + (step_count_delta_ia() ? "true" : "false") + "," +
               "\"step_overflow\":" + (step_overflow() ? "true" : "false") + "," +
               "\"stepcounter_bit_set\":" + (stepcounter_bit_set() ? "true" : "false") +
               "}";
    }
} // namespace lsm6dsv16x