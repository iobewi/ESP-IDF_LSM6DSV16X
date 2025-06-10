#pragma once

#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
DEFINE_GENERIC_REGISTER_ADDR(FsmOuts1Register, uint8_t, 0x4C)
    public:
        // Getters uniquement (registre lecture seule)
        bool fsm1_p_x() const { return get_flag<0, 7>(); }
        bool fsm1_n_x() const { return get_flag<0, 6>(); }
        bool fsm1_p_y() const { return get_flag<0, 5>(); }
        bool fsm1_n_y() const { return get_flag<0, 4>(); }
        bool fsm1_p_z() const { return get_flag<0, 3>(); }
        bool fsm1_n_z() const { return get_flag<0, 2>(); }
        bool fsm1_p_v() const { return get_flag<0, 1>(); }
        bool fsm1_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS1";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts2Register, uint8_t, 0x4D)
    public:
        // Getters (registre lecture seule)
        bool fsm2_p_x() const { return get_flag<0, 7>(); }
        bool fsm2_n_x() const { return get_flag<0, 6>(); }
        bool fsm2_p_y() const { return get_flag<0, 5>(); }
        bool fsm2_n_y() const { return get_flag<0, 4>(); }
        bool fsm2_p_z() const { return get_flag<0, 3>(); }
        bool fsm2_n_z() const { return get_flag<0, 2>(); }
        bool fsm2_p_v() const { return get_flag<0, 1>(); }
        bool fsm2_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS2";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts3Register, uint8_t, 0x4E)
    public:
        // Getters
        bool fsm3_p_x() const { return get_flag<0, 7>(); }
        bool fsm3_n_x() const { return get_flag<0, 6>(); }
        bool fsm3_p_y() const { return get_flag<0, 5>(); }
        bool fsm3_n_y() const { return get_flag<0, 4>(); }
        bool fsm3_p_z() const { return get_flag<0, 3>(); }
        bool fsm3_n_z() const { return get_flag<0, 2>(); }
        bool fsm3_p_v() const { return get_flag<0, 1>(); }
        bool fsm3_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS3";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts4Register, uint8_t, 0x4F)
    public:
        // Getters
        bool fsm4_p_x() const { return get_flag<0, 7>(); }
        bool fsm4_n_x() const { return get_flag<0, 6>(); }
        bool fsm4_p_y() const { return get_flag<0, 5>(); }
        bool fsm4_n_y() const { return get_flag<0, 4>(); }
        bool fsm4_p_z() const { return get_flag<0, 3>(); }
        bool fsm4_n_z() const { return get_flag<0, 2>(); }
        bool fsm4_p_v() const { return get_flag<0, 1>(); }
        bool fsm4_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS4";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts5Register, uint8_t, 0x50)
    public:
        // Getters
        bool fsm5_p_x() const { return get_flag<0, 7>(); }
        bool fsm5_n_x() const { return get_flag<0, 6>(); }
        bool fsm5_p_y() const { return get_flag<0, 5>(); }
        bool fsm5_n_y() const { return get_flag<0, 4>(); }
        bool fsm5_p_z() const { return get_flag<0, 3>(); }
        bool fsm5_n_z() const { return get_flag<0, 2>(); }
        bool fsm5_p_v() const { return get_flag<0, 1>(); }
        bool fsm5_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS5";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts6Register, uint8_t, 0x51)
    public:
        // Getters
        bool fsm6_p_x() const { return get_flag<0, 7>(); }
        bool fsm6_n_x() const { return get_flag<0, 6>(); }
        bool fsm6_p_y() const { return get_flag<0, 5>(); }
        bool fsm6_n_y() const { return get_flag<0, 4>(); }
        bool fsm6_p_z() const { return get_flag<0, 3>(); }
        bool fsm6_n_z() const { return get_flag<0, 2>(); }
        bool fsm6_p_v() const { return get_flag<0, 1>(); }
        bool fsm6_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS6";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts7Register, uint8_t, 0x52)
    public:
        // Getters
        bool fsm7_p_x() const { return get_flag<0, 7>(); }
        bool fsm7_n_x() const { return get_flag<0, 6>(); }
        bool fsm7_p_y() const { return get_flag<0, 5>(); }
        bool fsm7_n_y() const { return get_flag<0, 4>(); }
        bool fsm7_p_z() const { return get_flag<0, 3>(); }
        bool fsm7_n_z() const { return get_flag<0, 2>(); }
        bool fsm7_p_v() const { return get_flag<0, 1>(); }
        bool fsm7_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS7";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOuts8Register, uint8_t, 0x53)
    public:
        // Getters
        bool fsm8_p_x() const { return get_flag<0, 7>(); }
        bool fsm8_n_x() const { return get_flag<0, 6>(); }
        bool fsm8_p_y() const { return get_flag<0, 5>(); }
        bool fsm8_n_y() const { return get_flag<0, 4>(); }
        bool fsm8_p_z() const { return get_flag<0, 3>(); }
        bool fsm8_n_z() const { return get_flag<0, 2>(); }
        bool fsm8_p_v() const { return get_flag<0, 1>(); }
        bool fsm8_n_v() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_OUTS8";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(StepCounterRegister, uint16_t, 0x62)
    public:
        // Setter
        void step_counter(uint16_t v) { raw_ = v; }

        // Getter
        uint16_t step_counter() const { return raw_; }
    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_LONG_COUNTER";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(Mlc1SrcRegister , uint8_t, 0x70)
    public:
         // Getters
        uint8_t mlc1_output() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC1_SRC";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(Mlc2SrcRegister , uint8_t, 0x71)
    public:
         // Getters
        uint8_t mlc2_output() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC2_SRC";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(Mlc3SrcRegister , uint8_t, 0x72)
    public:
         // Getters
        uint8_t mlc3_output() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC3_SRC";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(Mlc4SrcRegister , uint8_t, 0x73)
    public:
         // Getters
        uint8_t mlc4_output() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC4_SRC";
END_REGISTER
} // namespace lsm6dsv16x
