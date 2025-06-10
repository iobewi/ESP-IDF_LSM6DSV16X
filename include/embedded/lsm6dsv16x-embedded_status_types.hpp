#pragma once

#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
DEFINE_GENERIC_REGISTER_ADDR(EmbFuncExecStatusRegister, uint8_t, 0x07)
    public:
        // Getters uniquement (registre en lecture seule)
        bool emb_func_exec_ovr() const { return get_flag<0, 1>(); }
        bool emb_func_endop() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EXEC_STATUS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncStatusRegister, uint8_t, 0x12)
    public:
        // Getters (registre en lecture seule)
        bool is_fsm_lc() const { return get_flag<0, 7>(); }
        bool is_sigmot() const { return get_flag<0, 5>(); }
        bool is_tilt() const { return get_flag<0, 4>(); }
        bool is_step_det() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_STATUS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmStatusRegister, uint8_t, 0x13)
    public:
        // Getters
        bool is_fsm1() const { return get_flag<0, 0>(); }
        bool is_fsm2() const { return get_flag<0, 1>(); }
        bool is_fsm3() const { return get_flag<0, 2>(); }
        bool is_fsm4() const { return get_flag<0, 3>(); }
        bool is_fsm5() const { return get_flag<0, 4>(); }
        bool is_fsm6() const { return get_flag<0, 5>(); }
        bool is_fsm7() const { return get_flag<0, 6>(); }
        bool is_fsm8() const { return get_flag<0, 7>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_STATUS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(MlcStatusRegister, uint8_t, 0x15)
    public:
        // Getters (registre lecture seule)
        bool is_mlc1() const { return get_flag<0, 0>(); }
        bool is_mlc2() const { return get_flag<0, 1>(); }
        bool is_mlc3() const { return get_flag<0, 2>(); }
        bool is_mlc4() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC_STATUS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncSrcRegister, uint8_t, 0x64)
    public:
        // Setter (RW bit)
        void pedo_rst_step(bool v) { set_flag<0, 7>(v); }

        // Getters
        bool pedo_rst_step() const { return get_flag<0, 7>(); }
        bool step_detected() const { return get_flag<0, 5>(); }
        bool step_count_delta_ia() const { return get_flag<0, 4>(); }
        bool step_overflow() const { return get_flag<0, 3>(); }
        bool stepcounter_bit_set() const { return get_flag<0, 2>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_SRC";
END_REGISTER

} // namespace lsm6dsv16x
