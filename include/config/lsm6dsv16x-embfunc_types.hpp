#pragma once

#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    DEFINE_GENERIC_REGISTER_ADDR(FunctionsEnableRegister, uint8_t, 0x50)
        public:
            enum class InactEn : uint8_t
            {
                NONE = 0b00,                  // stationary/motion-only interrupts generated
                XL_LOW_POWER = 0b01,          // acc low-power, ODR set by XL_INACT_ODR, gyro not changed
                XL_LOW_PWR_GYRO_SLEEP = 0b10, // acc low-power, ODR set by XL_INACT_ODR, gyro sleep
                XL_LOW_PWR_GYRO_PD = 0b11,    // acc low-power, ODR set by XL_INACT_ODR, gyro power down
            };

            // Setters
            void interrupts_enable(bool v) { set_flag<0, 4>(v); }
            void timestamp_en(bool v) { set_flag<0, 3>(v); }
            void dis_rst_lir_all_int(bool v) { set_flag<0, 1>(v); }
            void inact_en(InactEn v) { set_field<0, 0, 2>(v); }

            // Getters
            bool interrupts_enable() const { return get_flag<0, 4>(); }
            bool timestamp_en() const { return get_flag<0, 3>(); }
            bool dis_rst_lir_all_int() const { return get_flag<0, 1>(); }
            InactEn inact_en() const { return get_field<0, 0, 2, InactEn>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_FUNCTIONS_ENABLE";

            static const char *to_string(InactEn v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(DenRegister, uint8_t, 0x51)
        public:
            enum class TriggerMode : uint8_t
            {
                DISABLED = 0b00,  // ni lvl1 ni lvl2
                SENSITIVE = 0b10, // lvl1 only
                LATCHED = 0b11,   // lvl1 + lvl2
            };

            // Setters
            void lvl1_en(bool v) { set_flag<0, 6>(v); }
            void lvl2_en(bool v) { set_flag<0, 5>(v); }
            void den_xl_en(bool v) { set_flag<0, 4>(v); }
            void den_x(bool v) { set_flag<0, 3>(v); }
            void den_y(bool v) { set_flag<0, 2>(v); }
            void den_z(bool v) { set_flag<0, 1>(v); }
            void den_xl_g(bool v) { set_flag<0, 0>(v); }


            // Getters
            bool lvl1_en() const { return get_flag<0, 6>(); }
            bool lvl2_en() const { return get_flag<0, 5>(); }
            bool den_xl_en() const { return get_flag<0, 4>(); }
            bool den_x() const { return get_flag<0, 3>(); }
            bool den_y() const { return get_flag<0, 2>(); }
            bool den_z() const { return get_flag<0, 1>(); }
            bool den_xl_g() const { return get_flag<0, 0>(); }

            // Helper
            void trigger_mode(TriggerMode m)
            {
                lvl1_en((static_cast<uint8_t>(m) >> 1) & 0x01);
                lvl2_en(static_cast<uint8_t>(m) & 0x01);
            }
            TriggerMode trigger_mode() const
            {
                return static_cast<TriggerMode>(
                    (static_cast<uint8_t>(lvl1_en()) << 1) | static_cast<uint8_t>(lvl2_en()));
            }

        private:
            inline static const char *TAG = "LSM6DSV16X_DEN";
            static const char *to_string(TriggerMode m);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(InactivityDurRegister, uint8_t, 0x54)
    public:

        // Enum Class
        enum class WuInactThsW : uint8_t
        {
            MG_7_8 = 0b000,  // 7.8125 mg/LSB (default)
            MG_15_6 = 0b001, // 15.625 mg/LSB
            MG_31_3 = 0b010, // 31.25 mg/LSB
            MG_62_5 = 0b011, // 62.5 mg/LSB
            MG_125 = 0b100,  // 125 mg/LSB
            MG_250 = 0b101,  // 250 mg/LSB (also 110, 111)
            RESERVED = 0b110 // 110, 111
        };

        enum class XlInactOdr : uint8_t
        {
            HZ_1_875 = 0b00,
            HZ_15 = 0b01, // default
            HZ_30 = 0b10,
            HZ_60 = 0b11
        };

        enum class InactDur : uint8_t
        {
            IMMEDIATE = 0b00, // transition immediately
            TWO = 0b01,       // after 2 overs
            THREE = 0b10,     // after 3 overs
            FOUR = 0b11       // after 4 overs
        };

        // Setters
        void sleep_status_on_int(bool v) { set_flag<0, 6>(v); }
        void wu_inact_ths_w(WuInactThsW v) { set_field<0, 3, 3>(v); }
        void xl_inact_odr(XlInactOdr v) { set_field<0, 1, 2>(v); }
        void inact_dur(InactDur v) { set_field<0, 0, 2>(v); }

        // Getters
        bool sleep_status_on_int() const { return get_flag<0, 6>(); }
        WuInactThsW wu_inact_ths_w() const { return get_field<0, 3, 3, WuInactThsW>(); }
        XlInactOdr xl_inact_odr() const { return get_field<0, 1, 2, XlInactOdr>(); }
        InactDur inact_dur() const { return get_field<0, 0, 2, InactDur>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_INACTIVITY_DUR";
        static const char *to_string(WuInactThsW v);
        static const char *to_string(XlInactOdr v);
        static const char *to_string(InactDur v);
      END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(InactivityThsRegister, uint8_t, 0x55)
    public:
        // Seuil d’activité/inactivité sur 6 bits (résolution dépend de WU_INACT_THS_W dans INACTIVITY_DUR)
        void inact_ths(uint8_t value) { raw_ = value & 0x3F; }
        uint8_t inact_ths() const { return raw_ & 0x3F; }

    private:
        inline static const char *TAG = "LSM6DSV16X_INACTIVITY_THS";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(TapCfgRegister, uint32_t, 0x56)
    public:
        // Enum Class
        enum class TapPriority : uint8_t
        {
            XYZ = 0b000,
            YXZ = 0b001,
            YZX = 0b010,
            ZYX = 0b011,
            ZXY = 0b100,
            XZY = 0b101,
            XXZ = 0b110,
            ZZZ = 0b111
        };
        enum class SixdThs : uint8_t
        {
            DEG_80 = 0b00, // 80 degrees
            DEG_70 = 0b01, // 70 degrees
            DEG_60 = 0b10, // 60 degrees
            DEG_50 = 0b11  // 50 degrees
        };

        // Setters
        void low_pass_on_6d(bool v) { set_flag<0, 6>(v); }
        void hw_func_mask_xl_settl(bool v) { set_flag<0, 5>(v); }
        void slope_fds(bool v) { set_flag<0, 4>(v); }
        void tap_x_en(bool v) { set_flag<0, 3>(v); }
        void tap_y_en(bool v) { set_flag<0, 2>(v); }
        void tap_z_en(bool v) { set_flag<0, 1>(v); }
        void lir(bool v) { set_flag<0, 0>(v); }
        
        void tap_priority(TapPriority v) { set_field<1, 5, 3>(v); }
        void tap_ths_x(uint8_t ths) { set_field<1, 0, 5>(ths); }

        void tap_ths_y(uint8_t ths) { set_field<2, 0, 5>(ths); }

        void d4d_en(bool v) { set_flag<3, 7>(v); }
        void sixd_ths(uint8_t v) { set_field<3, 5, 2>(v); }
        void tap_ths_z(uint8_t val) { set_field<3, 0, 5>(val); }

        // Getters
        bool low_pass_on_6d() const { return get_flag<0, 6>(); }
        bool hw_func_mask_xl_settl() const { return get_flag<0, 5>(); }
        bool slope_fds() const { return get_flag<0, 4>(); }
        bool tap_x_en() const { return get_flag<0, 3>(); }
        bool tap_y_en() const { return get_flag<0, 2>(); }
        bool tap_z_en() const { return get_flag<0, 1>(); }
        bool lir() const { return get_flag<0, 0>(); }

        TapPriority tap_priority() const { return get_field<1, 5, 3, TapPriority>(); }
        uint8_t tap_ths_x() const { return get_field<1, 0, 5, uint8_t>(); }

        uint8_t tap_ths_y() const { return get_field<2, 0, 5, uint8_t>(); }

        bool d4d_en() const { return get_flag<3, 7>(); }
        SixdThs sixd_ths() const { return get_field<3, 5, 2, SixdThs>(); }
        uint8_t tap_ths_z() const { return get_field<3, 0, 5, uint8_t>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_TAP_CFG";
        static const char *to_string(TapPriority v);
        static const char *to_string(SixdThs v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(TapDurRegister, uint8_t, 0x5A)
    public:
        // Setters
        void dur(uint8_t v) { set_field<0, 4, 4>(v); }
        void quiet(uint8_t v) { set_field<0, 2, 2>(v); }
        void shock(uint8_t v) { set_field<0, 0, 2>(v); }

        // Getters
        uint8_t dur() const { return get_field<0, 4, 4, uint8_t>(); }
        uint8_t quiet() const { return get_field<0, 2, 2, uint8_t>(); }
        uint8_t shock() const { return get_field<0, 0, 2, uint8_t>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_TAP_DUR";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(WakeUpThsRegister, uint8_t, 0x5B)
    public:
        // Setters
        void single_double_tap(bool v) { set_flag<0, 7>(v); }
        void usr_off_on_wu(bool v) { set_flag<0, 6>(v); }
        void wk_ths(uint8_t v) { set_field<0, 0, 6>(v); }

        // Getters
        bool single_double_tap() const { return get_flag<0, 7>(); }
        bool usr_off_on_wu() const { return get_flag<0, 6>(); }
        uint8_t wk_ths() const { return get_field<0, 0, 6, uint8_t>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_WAKE_UP_THS";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(WakeUpDurRegister, uint8_t, 0x5C)
    public:
        // Setters
        void ff_dur_5(bool v) { set_flag<0, 7>(v); }
        void wake_dur(uint8_t v) { set_field<0, 5, 2>(v); }
        void sleep_dur(uint8_t v) { set_field<0, 0, 4>(v); }

        // Getters
        bool ff_dur_5() const { return get_flag<0, 7>(); }
        uint8_t wake_dur() const { return get_field<0, 5, 2, uint8_t>(); }
        uint8_t sleep_dur() const { return get_field<0, 0, 4, uint8_t>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_WAKE_UP_DUR";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(FreeFallRegister, uint8_t, 0x5D)
    public:
        // Enum Class
        enum class FfThs : uint8_t
        {
            MG_156 = 0b000,
            MG_219 = 0b001,
            MG_250 = 0b010,
            MG_312 = 0b011,
            MG_344 = 0b100,
            MG_406 = 0b101,
            MG_469 = 0b110,
            MG_500 = 0b111,
        };

        // Setters
        void ff_dur(uint8_t v) { set_field<0, 3, 5>(v); }
        void ff_ths(FfThs v) { set_field<0, 0, 3>(v); }

        // Getters
        uint8_t ff_dur() const { return get_field<0, 3, 5, uint8_t>(); }
        FfThs ff_ths() const { return get_field<0, 0, 3, FfThs>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FREE_FALL";
        static const char *to_string(FfThs v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(MdCfgRegister, uint16_t, 0x5E)
    public:

        // Setters
        void int1_sleep_change(bool v) { set_flag<0, 7>(v); }
        void int1_single_tap(bool v) { set_flag<0, 6>(v); }
        void int1_wu(bool v) { set_flag<0, 5>(v); }
        void int1_ff(bool v) { set_flag<0, 4>(v); }
        void int1_double_tap(bool v) { set_flag<0, 3>(v); }
        void int1_6d(bool v) { set_flag<0, 2>(v); }
        void int1_emb_func(bool v) { set_flag<0, 1>(v); }
        void int1_shub(bool v) { set_flag<0, 0>(v); }

        void int2_sleep_change(bool v) { set_flag<1, 7>(v); }
        void int2_single_tap(bool v) { set_flag<1, 6>(v); }
        void int2_wu(bool v) { set_flag<1, 5>(v); }
        void int2_ff(bool v) { set_flag<1, 4>(v); }
        void int2_double_tap(bool v) { set_flag<1, 3>(v); }
        void int2_6d(bool v) { set_flag<1, 2>(v); }
        void int2_emb_func(bool v) { set_flag<1, 1>(v); }
        void int2_timestamp(bool v) { set_flag<1, 0>(v); }

        // Getters
        bool int1_sleep_change() const { return get_flag<0, 7>(); }
        bool int1_single_tap() const { return get_flag<0, 6>(); }
        bool int1_wu() const { return get_flag<0, 5>(); }
        bool int1_ff() const { return get_flag<0, 4>(); }
        bool int1_double_tap() const { return get_flag<0, 3>(); }
        bool int1_6d() const { return get_flag<0, 2>(); }
        bool int1_emb_func() const { return get_flag<0, 1>(); }
        bool int1_shub() const { return get_flag<0, 0>(); }

        bool int2_sleep_change() const { return get_flag<1, 7>(); }
        bool int2_single_tap() const { return get_flag<1, 6>(); }
        bool int2_wu() const { return get_flag<1, 5>(); }
        bool int2_ff() const { return get_flag<1, 4>(); }
        bool int2_double_tap() const { return get_flag<1, 3>(); }
        bool int2_6d() const { return get_flag<1, 2>(); }
        bool int2_emb_func() const { return get_flag<1, 1>(); }
        bool int2_timestamp() const { return get_flag<1, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_MD_CFG";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(HaodrCfgRegister, uint8_t, 0x62)
    public:
        // Enum Class
        enum class HaodrSel : uint8_t
        {
            SET0 = 0b00,
            SET1 = 0b01,
            SET2 = 0b10,
            SET3 = 0b11
        };
        // Setters
        void haodr_sel(HaodrSel v) { set_field<0, 0, 2>(v); }

        // Getters
        HaodrSel haodr_sel() const { return get_field<0, 0, 2, HaodrSel>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_HAODR_CFG";
        static const char *to_string(HaodrSel v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(EmbFuncCfgRegister, uint8_t, 0x63)
    public:
         // Setters
        void xl_dualc_batch_from_if(bool v) { set_flag<0, 7>(v); }
        void emb_func_irq_mask_xl_settl(bool v) { set_flag<0, 4>(v); }
        void emb_func_disable(bool v) { set_flag<0, 2>(v); }
        void emb_func_irq_mask_g_settl(bool v) { set_flag<0, 5>(v); }

        // Getters
        bool emb_func_irq_mask_g_settl() const { return get_flag<0, 5>(); }
        bool xl_dualc_batch_from_if() const { return get_flag<0, 7>(); }
        bool emb_func_irq_mask_xl_settl() const { return get_flag<0, 4>(); }
        bool emb_func_disable() const { return get_flag<0, 2>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_CFG";
    END_REGISTER

} // namespace lsm6dsv16x
