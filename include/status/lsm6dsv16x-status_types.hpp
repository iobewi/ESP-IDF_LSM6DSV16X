#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    DEFINE_GENERIC_REGISTER_ADDR(WhoAmIRegister, uint8_t, 0x0F)
        public:
            uint8_t value() const { return raw_; }
            bool is_valid() const { return raw_ == expected_value; }

        private:
            inline static const char *TAG = "LSM6DSV16X_WHO_AM_I";
            static constexpr uint8_t expected_value = 0x70;
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(CtrlStatusRegister, uint8_t, 0x1A)
        public:
            bool fsm_wr_ctrl_status() const { return get_flag<0, 2>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL_STATUS";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(FifoStatusRegister, uint16_t, 0x1B)
        public:
            bool fifo_wtm_ia() const { return get_flag<1, 7>(); }
            bool fifo_ovr_ia() const { return get_flag<1, 6>(); }
            bool fifo_full_ia() const { return get_flag<1, 5>(); }
            bool counter_bdr_ia() const { return get_flag<1, 4>(); }
            bool fifo_ovr_latched() const { return get_flag<1, 3>(); }
            uint16_t diff_fifo() const { return (diff_fifo_h() << 8) | diff_fifo_l(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_FIFO_STATUS";
            uint8_t diff_fifo_l() const { return get_field<0, 0, 8, uint8_t>(); } // DIFF_FIFO[7:0]
            bool diff_fifo_h() const { return get_flag<1, 0>(); }
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(AllIntSrcRegister, uint8_t, 0x1D)
        public:
            bool emb_func_ia() const { return get_bit(7, raw_); }
            bool shub_ia() const { return get_bit(6, raw_); }
            bool sleep_change_ia() const { return get_bit(5, raw_); }
            bool d6d_ia() const { return get_bit(4, raw_); }
            // Bit 3 réservé (toujours à 0)
            bool tap_ia() const { return get_bit(2, raw_); }
            bool wu_ia() const { return get_bit(1, raw_); }
            bool ff_ia() const { return get_bit(0, raw_); }

        private:
            inline static const char *TAG = "LSM6DSV16X_ALL_INT_SRC";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(StatusRegRegister, uint8_t, 0x1E)
        public:
            bool timestamp_endcount() const { return get_bit(7, raw_); }
            bool ois_drdy() const { return get_bit(5, raw_); }
            bool gda_eis() const { return get_bit(4, raw_); }
            bool ah_qvarda() const { return get_bit(3, raw_); }
            bool tda() const { return get_bit(2, raw_); }
            bool gda() const { return get_bit(1, raw_); }
            bool xlda() const { return get_bit(0, raw_); }

        private:
            inline static const char *TAG = "LSM6DSV16X_STATUS_REG";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(UiStatusRegOisRegister, uint8_t, 0x44)
        public:
            bool gyro_settling() const { return get_flag<0, 2>(); }
            bool gda_ois() const { return get_flag<0, 1>(); }
            bool xlda_ois() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_UI_STATUS_OIS";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(WakeUpSrcRegister, uint8_t, 0x45)
        public:
            bool sleep_change_ia() const { return get_flag<0, 6>(); }
            bool ff_ia() const { return get_flag<0, 5>(); }
            bool sleep_state() const { return get_flag<0, 4>(); }
            bool wu_ia() const { return get_flag<0, 3>(); }
            bool x_wu() const { return get_flag<0, 2>(); }
            bool y_wu() const { return get_flag<0, 1>(); }
            bool z_wu() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_WAKE_UP_SRC";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(TapSrcRegister, uint8_t, 0x46)
        public:
            bool tap_ia() const { return get_flag<0, 6>(); }
            bool single_tap() const { return get_flag<0, 5>(); }
            bool double_tap() const { return get_flag<0, 4>(); }
            bool tap_sign() const { return get_flag<0, 3>(); }
            bool x_tap() const { return get_flag<0, 2>(); }
            bool y_tap() const { return get_flag<0, 1>(); }
            bool z_tap() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_TAP_SRC";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(D6dSrcRegister, uint8_t, 0x47)
        public:
            bool d6d_ia() const { return get_flag<0, 6>(); }
            bool zh() const { return get_flag<0, 5>(); }
            bool zl() const { return get_flag<0, 4>(); }
            bool yh() const { return get_flag<0, 3>(); }
            bool yl() const { return get_flag<0, 2>(); }
            bool xh() const { return get_flag<0, 1>(); }
            bool xl() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_D6D_SRC";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(StatusMasterMainpageRegister, uint8_t, 0x48)
        public:
            bool wr_once_done() const { return get_flag<0, 7>(); }
            bool slave3_nack() const { return get_flag<0, 6>(); }
            bool slave2_nack() const { return get_flag<0, 5>(); }
            bool slave1_nack() const { return get_flag<0, 4>(); }
            bool slave0_nack() const { return get_flag<0, 3>(); }
            bool sens_hub_endop() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_STATUS_MASTER_MAINPAGE";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(EmbFuncStatusMainpageRegister, uint8_t, 0x49)
        public:
            bool is_fsm_lc() const { return get_flag<0, 7>(); }
            bool is_sigmot() const { return get_flag<0, 5>(); }
            bool is_tilt() const { return get_flag<0, 4>(); }
            bool is_step_det() const { return get_flag<0, 3>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_STATUS_MAINPAGE";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(FsmStatusMainpageRegister, uint8_t, 0x4A)
        public:
            bool is_fsm8() const { return get_flag<0, 7>(); }
            bool is_fsm7() const { return get_flag<0, 6>(); }
            bool is_fsm6() const { return get_flag<0, 5>(); }
            bool is_fsm5() const { return get_flag<0, 4>(); }
            bool is_fsm4() const { return get_flag<0, 3>(); }
            bool is_fsm3() const { return get_flag<0, 2>(); }
            bool is_fsm2() const { return get_flag<0, 1>(); }
            bool is_fsm1() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_FSM_STATUS_MAINPAGE";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(MlcStatusMainpageRegister, uint8_t, 0x4B)
        public:
            bool is_mlc4() const { return get_flag<0, 4>(); }
            bool is_mlc3() const { return get_flag<0, 3>(); }
            bool is_mlc2() const { return get_flag<0, 2>(); }
            bool is_mlc1() const { return get_flag<0, 1>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_MLC_STATUS_MAINPAGE";
    END_REGISTER

} // namespace lsm6dsv16x
