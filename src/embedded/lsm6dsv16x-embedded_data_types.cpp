#include "embedded/lsm6dsv16x-embedded_data_types.hpp"

namespace lsm6dsv16x
{

    void FsmOuts1Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS1: raw=0x%02X P_X=%d N_X=%d P_Y=%d N_Y=%d P_Z=%d N_Z=%d P_V=%d N_V=%d",
                 raw_, fsm1_p_x(), fsm1_n_x(), fsm1_p_y(), fsm1_n_y(),
                 fsm1_p_z(), fsm1_n_z(), fsm1_p_v(), fsm1_n_v());
    }

    std::string FsmOuts1Register::to_json() const
    {
        return std::string("{") +
               "\"p_x\":" + (fsm1_p_x() ? "true" : "false") + "," +
               "\"n_x\":" + (fsm1_n_x() ? "true" : "false") + "," +
               "\"p_y\":" + (fsm1_p_y() ? "true" : "false") + "," +
               "\"n_y\":" + (fsm1_n_y() ? "true" : "false") + "," +
               "\"p_z\":" + (fsm1_p_z() ? "true" : "false") + "," +
               "\"n_z\":" + (fsm1_n_z() ? "true" : "false") + "," +
               "\"p_v\":" + (fsm1_p_v() ? "true" : "false") + "," +
               "\"n_v\":" + (fsm1_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts2Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS2: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm2_p_x(), fsm2_n_x(), fsm2_p_y(), fsm2_n_y(),
                 fsm2_p_z(), fsm2_n_z(), fsm2_p_v(), fsm2_n_v());
    }

    std::string FsmOuts2Register::to_json() const
    {
        return std::string("{") +
               "\"fsm2_p_x\":" + (fsm2_p_x() ? "true" : "false") + "," +
               "\"fsm2_n_x\":" + (fsm2_n_x() ? "true" : "false") + "," +
               "\"fsm2_p_y\":" + (fsm2_p_y() ? "true" : "false") + "," +
               "\"fsm2_n_y\":" + (fsm2_n_y() ? "true" : "false") + "," +
               "\"fsm2_p_z\":" + (fsm2_p_z() ? "true" : "false") + "," +
               "\"fsm2_n_z\":" + (fsm2_n_z() ? "true" : "false") + "," +
               "\"fsm2_p_v\":" + (fsm2_p_v() ? "true" : "false") + "," +
               "\"fsm2_n_v\":" + (fsm2_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts3Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS3: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm3_p_x(), fsm3_n_x(), fsm3_p_y(), fsm3_n_y(),
                 fsm3_p_z(), fsm3_n_z(), fsm3_p_v(), fsm3_n_v());
    }

    std::string FsmOuts3Register::to_json() const
    {
        return std::string("{") +
               "\"fsm3_p_x\":" + (fsm3_p_x() ? "true" : "false") + "," +
               "\"fsm3_n_x\":" + (fsm3_n_x() ? "true" : "false") + "," +
               "\"fsm3_p_y\":" + (fsm3_p_y() ? "true" : "false") + "," +
               "\"fsm3_n_y\":" + (fsm3_n_y() ? "true" : "false") + "," +
               "\"fsm3_p_z\":" + (fsm3_p_z() ? "true" : "false") + "," +
               "\"fsm3_n_z\":" + (fsm3_n_z() ? "true" : "false") + "," +
               "\"fsm3_p_v\":" + (fsm3_p_v() ? "true" : "false") + "," +
               "\"fsm3_n_v\":" + (fsm3_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts4Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS4: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm4_p_x(), fsm4_n_x(), fsm4_p_y(), fsm4_n_y(),
                 fsm4_p_z(), fsm4_n_z(), fsm4_p_v(), fsm4_n_v());
    }

    std::string FsmOuts4Register::to_json() const
    {
        return std::string("{") +
               "\"fsm4_p_x\":" + (fsm4_p_x() ? "true" : "false") + "," +
               "\"fsm4_n_x\":" + (fsm4_n_x() ? "true" : "false") + "," +
               "\"fsm4_p_y\":" + (fsm4_p_y() ? "true" : "false") + "," +
               "\"fsm4_n_y\":" + (fsm4_n_y() ? "true" : "false") + "," +
               "\"fsm4_p_z\":" + (fsm4_p_z() ? "true" : "false") + "," +
               "\"fsm4_n_z\":" + (fsm4_n_z() ? "true" : "false") + "," +
               "\"fsm4_p_v\":" + (fsm4_p_v() ? "true" : "false") + "," +
               "\"fsm4_n_v\":" + (fsm4_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts5Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS5: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm5_p_x(), fsm5_n_x(), fsm5_p_y(), fsm5_n_y(),
                 fsm5_p_z(), fsm5_n_z(), fsm5_p_v(), fsm5_n_v());
    }

    std::string FsmOuts5Register::to_json() const
    {
        return std::string("{") +
               "\"fsm5_p_x\":" + (fsm5_p_x() ? "true" : "false") + "," +
               "\"fsm5_n_x\":" + (fsm5_n_x() ? "true" : "false") + "," +
               "\"fsm5_p_y\":" + (fsm5_p_y() ? "true" : "false") + "," +
               "\"fsm5_n_y\":" + (fsm5_n_y() ? "true" : "false") + "," +
               "\"fsm5_p_z\":" + (fsm5_p_z() ? "true" : "false") + "," +
               "\"fsm5_n_z\":" + (fsm5_n_z() ? "true" : "false") + "," +
               "\"fsm5_p_v\":" + (fsm5_p_v() ? "true" : "false") + "," +
               "\"fsm5_n_v\":" + (fsm5_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts6Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS6: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm6_p_x(), fsm6_n_x(), fsm6_p_y(), fsm6_n_y(),
                 fsm6_p_z(), fsm6_n_z(), fsm6_p_v(), fsm6_n_v());
    }

    std::string FsmOuts6Register::to_json() const
    {
        return std::string("{") +
               "\"fsm6_p_x\":" + (fsm6_p_x() ? "true" : "false") + "," +
               "\"fsm6_n_x\":" + (fsm6_n_x() ? "true" : "false") + "," +
               "\"fsm6_p_y\":" + (fsm6_p_y() ? "true" : "false") + "," +
               "\"fsm6_n_y\":" + (fsm6_n_y() ? "true" : "false") + "," +
               "\"fsm6_p_z\":" + (fsm6_p_z() ? "true" : "false") + "," +
               "\"fsm6_n_z\":" + (fsm6_n_z() ? "true" : "false") + "," +
               "\"fsm6_p_v\":" + (fsm6_p_v() ? "true" : "false") + "," +
               "\"fsm6_n_v\":" + (fsm6_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts7Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS7: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm7_p_x(), fsm7_n_x(), fsm7_p_y(), fsm7_n_y(),
                 fsm7_p_z(), fsm7_n_z(), fsm7_p_v(), fsm7_n_v());
    }

    std::string FsmOuts7Register::to_json() const
    {
        return std::string("{") +
               "\"fsm7_p_x\":" + (fsm7_p_x() ? "true" : "false") + "," +
               "\"fsm7_n_x\":" + (fsm7_n_x() ? "true" : "false") + "," +
               "\"fsm7_p_y\":" + (fsm7_p_y() ? "true" : "false") + "," +
               "\"fsm7_n_y\":" + (fsm7_n_y() ? "true" : "false") + "," +
               "\"fsm7_p_z\":" + (fsm7_p_z() ? "true" : "false") + "," +
               "\"fsm7_n_z\":" + (fsm7_n_z() ? "true" : "false") + "," +
               "\"fsm7_p_v\":" + (fsm7_p_v() ? "true" : "false") + "," +
               "\"fsm7_n_v\":" + (fsm7_n_v() ? "true" : "false") +
               "}";
    }

    void FsmOuts8Register::log() const
    {
        ESP_LOGI(TAG, "FSM_OUTS8: raw=0x%02X p_x=%d n_x=%d p_y=%d n_y=%d p_z=%d n_z=%d p_v=%d n_v=%d",
                 raw_,
                 fsm8_p_x(), fsm8_n_x(), fsm8_p_y(), fsm8_n_y(),
                 fsm8_p_z(), fsm8_n_z(), fsm8_p_v(), fsm8_n_v());
    }

    std::string FsmOuts8Register::to_json() const
    {
        return std::string("{") +
               "\"fsm8_p_x\":" + (fsm8_p_x() ? "true" : "false") + "," +
               "\"fsm8_n_x\":" + (fsm8_n_x() ? "true" : "false") + "," +
               "\"fsm8_p_y\":" + (fsm8_p_y() ? "true" : "false") + "," +
               "\"fsm8_n_y\":" + (fsm8_n_y() ? "true" : "false") + "," +
               "\"fsm8_p_z\":" + (fsm8_p_z() ? "true" : "false") + "," +
               "\"fsm8_n_z\":" + (fsm8_n_z() ? "true" : "false") + "," +
               "\"fsm8_p_v\":" + (fsm8_p_v() ? "true" : "false") + "," +
               "\"fsm8_n_v\":" + (fsm8_n_v() ? "true" : "false") +
               "}";
    }
   
     void StepCounterRegister::log() const
    {
        ESP_LOGI(TAG, "STEP_COUNTER: raw=0x%04X step_count=%u", get_raw(), step_counter());
    }

    std::string StepCounterRegister::to_json() const
    {
        return std::string("{") +
               "\"step_count\":" + std::to_string(step_counter()) +
               "}";
    }

      void Mlc1SrcRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_SRC: raw=0x%02X output=%u", raw_, mlc1_output());
    }

    std::string Mlc1SrcRegister::to_json() const
    {
        return std::string("{") +
               "\"output\":" + std::to_string(mlc1_output()) +
               "}";
    }

    void Mlc2SrcRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_SRC: raw=0x%02X output=%u", raw_, mlc2_output());
    }

    std::string Mlc2SrcRegister::to_json() const
    {
        return std::string("{") +
               "\"output\":" + std::to_string(mlc2_output()) +
               "}";
    }

    void Mlc3SrcRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_SRC: raw=0x%02X output=%u", raw_, mlc3_output());
    }

    std::string Mlc3SrcRegister::to_json() const
    {
        return std::string("{") +
               "\"output\":" + std::to_string(mlc3_output()) +
               "}";
    }

    void Mlc4SrcRegister::log() const
    {
        ESP_LOGI(TAG, "MLC_SRC: raw=0x%02X output=%u", raw_, mlc4_output());
    }

    std::string Mlc4SrcRegister::to_json() const
    {
        return std::string("{") +
               "\"output\":" + std::to_string(mlc4_output()) +
               "}";
    }
} // namespace lsm6dsv16x