#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    struct WhoAmIRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x0F;
        static constexpr uint8_t expected_value = 0x70;

        WhoAmIRegister() = default;
        explicit WhoAmIRegister(uint8_t raw) : raw_(raw) {}

        uint8_t value() const { return raw_; }
        bool is_valid() const { return raw_ == expected_value; }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_WHO_AM_I";
        uint8_t raw_ = 0;
    };

    class CtrlStatusRegister
    {
    public:
        static constexpr uint8_t reg_addr = 0x1A;

        CtrlStatusRegister() = default;
        explicit CtrlStatusRegister(uint8_t raw) : raw_(raw) {}

        // Getter : FSM_WR_CTRL_STATUS (bit 2)
        bool fsm_wr_ctrl_status() const { return get_flag<0, 2>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL_STATUS";
        uint8_t raw_ = 0;
    };

    class FifoStatusRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x1B; // adresse de base

        FifoStatusRegister() = default;
        explicit FifoStatusRegister(uint16_t raw) : raw_(raw) {}

        // FIFO_STATUS1 (bits 0-7)
        uint8_t diff_fifo_l() const { return get_octet<0>(); } // DIFF_FIFO[7:0]

        // FIFO_STATUS2 (bits 8-15)
        bool fifo_wtm_ia() const { return get_flag<1, 7>(); }
        bool fifo_ovr_ia() const { return get_flag<1, 6>(); }
        bool fifo_full_ia() const { return get_flag<1, 5>(); }
        bool counter_bdr_ia() const { return get_flag<1, 4>(); }
        bool fifo_ovr_latched() const { return get_flag<1, 3>(); }
        bool diff_fifo_h() const { return get_flag<1, 0>(); }
        // bits 9-10 (réservés)

        // Helper
        uint16_t diff_fifo() const
        { // sur 9 bits, si besoin
            return (diff_fifo_h() << 8) | diff_fifo_l();
        }

        void set_raw(uint16_t raw) { raw_ = raw; }
        uint16_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_FIFO_STATUS";
        uint16_t raw_ = 0;
    };

    class AllIntSrcRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x1D;

        AllIntSrcRegister() = default;
        explicit AllIntSrcRegister(uint8_t raw) : raw_(raw) {}

        bool emb_func_ia() const { return get_bit(7, raw_); }
        bool shub_ia() const { return get_bit(6, raw_); }
        bool sleep_change_ia() const { return get_bit(5, raw_); }
        bool d6d_ia() const { return get_bit(4, raw_); }
        // Bit 3 réservé (toujours à 0)
        bool tap_ia() const { return get_bit(2, raw_); }
        bool wu_ia() const { return get_bit(1, raw_); }
        bool ff_ia() const { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_ALL_INT_SRC";
        uint8_t raw_ = 0;
    };

    class StatusRegRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x1E;

        StatusRegRegister() = default;
        explicit StatusRegRegister(uint8_t raw) : raw_(raw) {}

        bool timestamp_endcount() const { return get_bit(7, raw_); }
        bool ois_drdy() const { return get_bit(5, raw_); }
        bool gda_eis() const { return get_bit(4, raw_); }
        bool ah_qvarda() const { return get_bit(3, raw_); }
        bool tda() const { return get_bit(2, raw_); }
        bool gda() const { return get_bit(1, raw_); }
        bool xlda() const { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_STATUS_REG";
        uint8_t raw_ = 0;
    };

    struct UiStatusRegOisRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x44;

        UiStatusRegOisRegister() = default;
        explicit UiStatusRegOisRegister(uint8_t raw) : raw_(raw) {}

        bool gyro_settling() const { return get_flag<0, 2>(); }
        bool gda_ois() const { return get_flag<0, 1>(); }
        bool xlda_ois() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_UI_STATUS_OIS";
        uint8_t raw_ = 0;
    };

    struct WakeUpSrcRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x45;

        WakeUpSrcRegister() = default;
        explicit WakeUpSrcRegister(uint8_t raw) : raw_(raw) {}

        bool sleep_change_ia() const { return get_flag<0, 6>(); }
        bool ff_ia() const { return get_flag<0, 5>(); }
        bool sleep_state() const { return get_flag<0, 4>(); }
        bool wu_ia() const { return get_flag<0, 3>(); }
        bool x_wu() const { return get_flag<0, 2>(); }
        bool y_wu() const { return get_flag<0, 1>(); }
        bool z_wu() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_WAKE_UP_SRC";
        uint8_t raw_ = 0;
    };

    struct TapSrcRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x46;

        TapSrcRegister() = default;
        explicit TapSrcRegister(uint8_t raw) : raw_(raw) {}

        bool tap_ia() const { return get_flag<0, 6>(); }
        bool single_tap() const { return get_flag<0, 5>(); }
        bool double_tap() const { return get_flag<0, 4>(); }
        bool tap_sign() const { return get_flag<0, 3>(); }
        bool x_tap() const { return get_flag<0, 2>(); }
        bool y_tap() const { return get_flag<0, 1>(); }
        bool z_tap() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_TAP_SRC";
        uint8_t raw_ = 0;
    };

    struct D6dSrcRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x47;

        D6dSrcRegister() = default;
        explicit D6dSrcRegister(uint8_t raw) : raw_(raw) {}

        bool d6d_ia() const { return get_flag<0, 6>(); }
        bool zh() const { return get_flag<0, 5>(); }
        bool zl() const { return get_flag<0, 4>(); }
        bool yh() const { return get_flag<0, 3>(); }
        bool yl() const { return get_flag<0, 2>(); }
        bool xh() const { return get_flag<0, 1>(); }
        bool xl() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_D6D_SRC";
        uint8_t raw_ = 0;
    };

    struct StatusMasterMainpageRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x48;

        StatusMasterMainpageRegister() = default;
        explicit StatusMasterMainpageRegister(uint8_t raw) : raw_(raw) {}

        bool wr_once_done() const { return get_flag<0, 7>(); }
        bool slave3_nack() const { return get_flag<0, 6>(); }
        bool slave2_nack() const { return get_flag<0, 5>(); }
        bool slave1_nack() const { return get_flag<0, 4>(); }
        bool slave0_nack() const { return get_flag<0, 3>(); }
        bool sens_hub_endop() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_STATUS_MASTER_MAINPAGE";
        uint8_t raw_ = 0;
    };

    struct EmbFuncStatusMainpageRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x49;

        EmbFuncStatusMainpageRegister() = default;
        explicit EmbFuncStatusMainpageRegister(uint8_t raw) : raw_(raw) {}

        bool is_fsm_lc() const { return get_flag<0, 7>(); }
        bool is_sigmot() const { return get_flag<0, 5>(); }
        bool is_tilt() const { return get_flag<0, 4>(); }
        bool is_step_det() const { return get_flag<0, 3>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const
        {
            ESP_LOGI(TAG, "EMB_FUNC_STATUS_MAINPAGE = 0x%02X | IS_FSM_LC=%d IS_SIGMOT=%d IS_TILT=%d IS_STEP_DET=%d",
                     raw_, is_fsm_lc(), is_sigmot(), is_tilt(), is_step_det());
        }

        std::string to_json() const
        {
            return std::string("{") +
                   "\"is_fsm_lc\":" + std::to_string(is_fsm_lc()) + "," +
                   "\"is_sigmot\":" + std::to_string(is_sigmot()) + "," +
                   "\"is_tilt\":" + std::to_string(is_tilt()) + "," +
                   "\"is_step_det\":" + std::to_string(is_step_det()) +
                   "}";
        }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_STATUS_MAINPAGE";
        uint8_t raw_ = 0;
    };

    struct FsmStatusMainpageRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x4A;

        FsmStatusMainpageRegister() = default;
        explicit FsmStatusMainpageRegister(uint8_t raw) : raw_(raw) {}

        bool is_fsm8() const { return get_flag<0, 7>(); }
        bool is_fsm7() const { return get_flag<0, 6>(); }
        bool is_fsm6() const { return get_flag<0, 5>(); }
        bool is_fsm5() const { return get_flag<0, 4>(); }
        bool is_fsm4() const { return get_flag<0, 3>(); }
        bool is_fsm3() const { return get_flag<0, 2>(); }
        bool is_fsm2() const { return get_flag<0, 1>(); }
        bool is_fsm1() const { return get_flag<0, 0>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;

        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_STATUS_MAINPAGE";
        uint8_t raw_ = 0;
    };

    struct MlcStatusMainpageRegister : protected lsm6dsv16x::RegisterBase
    {
        static constexpr uint8_t reg_addr = 0x4B;

        MlcStatusMainpageRegister() = default;
        explicit MlcStatusMainpageRegister(uint8_t raw) : raw_(raw) {}

        bool is_mlc4() const { return get_flag<0, 4>(); }
        bool is_mlc3() const { return get_flag<0, 3>(); }
        bool is_mlc2() const { return get_flag<0, 2>(); }
        bool is_mlc1() const { return get_flag<0, 1>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC_STATUS_MAINPAGE";
        uint8_t raw_ = 0;
    };

} // namespace lsm6dsv16x
