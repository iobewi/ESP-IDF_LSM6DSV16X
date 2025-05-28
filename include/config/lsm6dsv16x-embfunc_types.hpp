#pragma once

#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    class FunctionsEnableRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x50;

        enum class InactEn : uint8_t
        {
            NONE = 0b00,                  // stationary/motion-only interrupts generated
            XL_LOW_POWER = 0b01,          // acc low-power, ODR set by XL_INACT_ODR, gyro not changed
            XL_LOW_PWR_GYRO_SLEEP = 0b10, // acc low-power, ODR set by XL_INACT_ODR, gyro sleep
            XL_LOW_PWR_GYRO_PD = 0b11,    // acc low-power, ODR set by XL_INACT_ODR, gyro power down
        };

        static const char *to_string(InactEn v);

        // Setters
        void interrupts_enable(bool v) { set_bit(4, v, raw_); }
        void timestamp_en(bool v) { set_bit(3, v, raw_); }
        void dis_rst_lir_all_int(bool v) { set_bit(1, v, raw_); }
        void inact_en(InactEn v) { raw_ = (raw_ & ~0x03) | (static_cast<uint8_t>(v) & 0x03); }

        // Getters
        bool interrupts_enable() const { return get_bit(4, raw_); }
        bool timestamp_en() const { return get_bit(3, raw_); }
        bool dis_rst_lir_all_int() const { return get_bit(1, raw_); }
        InactEn inact_en() const { return static_cast<InactEn>(raw_ & 0x03); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_FUNCTIONS_ENABLE";
    };

    class DenRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x51;

        enum class TriggerMode : uint8_t
        {
            DISABLED = 0b00,  // ni lvl1 ni lvl2
            SENSITIVE = 0b10, // lvl1 only
            LATCHED = 0b11,   // lvl1 + lvl2
        };

        // Setters
        void lvl1_en(bool v) { set_bit(6, v, raw_); }
        void lvl2_en(bool v) { set_bit(5, v, raw_); }
        void den_xl_en(bool v) { set_bit(4, v, raw_); }
        void den_x(bool v) { set_bit(3, v, raw_); }
        void den_y(bool v) { set_bit(2, v, raw_); }
        void den_z(bool v) { set_bit(1, v, raw_); }
        void den_xl_g(bool v) { set_bit(0, v, raw_); }
        void trigger_mode(TriggerMode m)
        {
            lvl1_en((static_cast<uint8_t>(m) >> 1) & 0x01);
            lvl2_en(static_cast<uint8_t>(m) & 0x01);
        }

        // Getters
        bool lvl1_en() const { return get_bit(6, raw_); }
        bool lvl2_en() const { return get_bit(5, raw_); }
        bool den_xl_en() const { return get_bit(4, raw_); }
        bool den_x() const { return get_bit(3, raw_); }
        bool den_y() const { return get_bit(2, raw_); }
        bool den_z() const { return get_bit(1, raw_); }
        bool den_xl_g() const { return get_bit(0, raw_); }
        TriggerMode trigger_mode() const
        {
            return static_cast<TriggerMode>(
                (static_cast<uint8_t>(lvl1_en()) << 1) | static_cast<uint8_t>(lvl2_en()));
        }

        // Accès brut
        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        static const char *to_string(TriggerMode m);

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_DEN";
    };

    class InactivityDurRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x54;

        // Weight of threshold
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

        // ODR during inactivity
        enum class XlInactOdr : uint8_t
        {
            HZ_1_875 = 0b00,
            HZ_15 = 0b01, // default
            HZ_30 = 0b10,
            HZ_60 = 0b11
        };

        // Duration
        enum class InactDur : uint8_t
        {
            IMMEDIATE = 0b00, // transition immediately
            TWO = 0b01,       // after 2 overs
            THREE = 0b10,     // after 3 overs
            FOUR = 0b11       // after 4 overs
        };

        // Setters
        void sleep_status_on_int(bool v) { set_bit(6, v, raw_); }
        void wu_inact_ths_w(WuInactThsW v) { set_bits(raw_, 3, 3, static_cast<uint8_t>(v)); }
        void xl_inact_odr(XlInactOdr v) { set_bits(raw_, 1, 2, static_cast<uint8_t>(v)); }
        void inact_dur(InactDur v) { set_bits(raw_, 0, 2, static_cast<uint8_t>(v)); }

        // Getters
        bool sleep_status_on_int() const { return get_bit(6, raw_); }
        WuInactThsW wu_inact_ths_w() const { return static_cast<WuInactThsW>(get_bits(raw_, 3, 3)); }
        XlInactOdr xl_inact_odr() const { return static_cast<XlInactOdr>(get_bits(raw_, 1, 2)); }
        InactDur inact_dur() const { return static_cast<InactDur>(get_bits(raw_, 0, 2)); }

    // Raw
        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        static const char *to_string(WuInactThsW v);
        static const char *to_string(XlInactOdr v);
        static const char *to_string(InactDur v);

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_INACTIVITY_DUR";
    };

    class InactivityThsRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x55;

        // Seuil d’activité/inactivité sur 6 bits (résolution dépend de WU_INACT_THS_W dans INACTIVITY_DUR)
        void inact_ths(uint8_t value) { raw_ = value & 0x3F; }
        uint8_t inact_ths() const { return raw_ & 0x3F; }

        void set_raw(uint8_t raw) { raw_ = raw & 0x3F; }
        uint8_t get_raw() const { return raw_ & 0x3F; }

        void log() const
        {
            ESP_LOGI(TAG, "INACTIVITY_THS: raw=0x%02X inact_ths=%u", raw_ & 0x3F, inact_ths());
        }

        std::string to_json() const
        {
            return std::string("{") +
                   "\"inact_ths\":" + std::to_string(inact_ths()) +
                   "}";
        }

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_INACTIVITY_THS";
    };
    class TapCfg0Register : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x56;

        // LOW_PASS_ON_6D : bit 6
        void low_pass_on_6d(bool v) { set_bit(raw_, 6, v); }
        bool low_pass_on_6d() const { return get_bit(raw_, 6); }

        // HW_FUNC_MASK_XL_SETTL : bit 5
        void hw_func_mask_xl_settl(bool v) { set_bit(raw_, 5, v); }
        bool hw_func_mask_xl_settl() const { return get_bit(raw_, 5); }

        // SLOPE_FDS : bit 4
        void slope_fds(bool v) { set_bit(raw_, 4, v); }
        bool slope_fds() const { return get_bit(raw_, 4); }

        // TAP_X_EN : bit 3
        void tap_x_en(bool v) { set_bit(raw_, 3, v); }
        bool tap_x_en() const { return get_bit(raw_, 3); }

        // TAP_Y_EN : bit 2
        void tap_y_en(bool v) { set_bit(raw_, 2, v); }
        bool tap_y_en() const { return get_bit(raw_, 2); }

        // TAP_Z_EN : bit 1
        void tap_z_en(bool v) { set_bit(raw_, 1, v); }
        bool tap_z_en() const { return get_bit(raw_, 1); }

        // LIR : bit 0
        void lir(bool v) { set_bit(raw_, 0, v); }
        bool lir() const { return get_bit(raw_, 0); }

        void set_raw(uint8_t raw) { raw_ = raw & 0x7F; } // bit 7 non utilisé
        uint8_t get_raw() const { return raw_ & 0x7F; }

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_TAP_CFG0";
    };

    class TapCfg1Register : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x57;

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

        void tap_priority(TapPriority v) { set_bits(raw_, 5, 3, static_cast<uint8_t>(v)); }
        TapPriority tap_priority() const { return static_cast<TapPriority>(get_bits(raw_, 5, 3)); }

        void tap_ths_x(uint8_t ths) { set_bits(raw_, 0, 5, ths); }
        uint8_t tap_ths_x() const { return get_bits(raw_, 0, 5, ); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

        static const char *to_string(TapPriority v);

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_TAP_CFG1";
    };

    class TapCfg2Register
    {
    public:
        static constexpr uint8_t reg_addr = 0x58;

        void tap_ths_y(uint8_t ths) { raw_ = ths & 0x1F; }
        uint8_t tap_ths_y() const { return raw_ & 0x1F; }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_TAP_CFG2";
    };

    class TapThs6DRegister
    {
    public:
        static constexpr uint8_t reg_addr = 0x59;

        // D4D_EN : Bit 7
        void d4d_en(bool v) { set_bit(7, v, raw_); }
        bool d4d_en() const { return get_bit(7, raw_); }

        // SIXD_THS_[1:0] : Bits 6:5
        enum class SixdThs : uint8_t
        {
            DEG_80 = 0b00, // 80 degrees
            DEG_70 = 0b01, // 70 degrees
            DEG_60 = 0b10, // 60 degrees
            DEG_50 = 0b11  // 50 degrees
        };
        void sixd_ths(uint8_t v) { set_bits(raw_, 5, 2, v); }
        uint8_t sixd_ths() const { return get_bits(raw_, 5, 2); }

        // TAP_THS_Z_[4:0] : Bits 4:0
        void tap_ths_z(uint8_t val) { set_bits(raw_, 0, 5, val); }
        uint8_t tap_ths_z() const { return get_bits(raw_, 0, 5); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        static const char *to_string(SixdThs v);

        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_TAP_THS_6D";
    };

    class TapDurRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5A;

        // --- Setters / Getters par champ ---
        // DUR[3:0] : Duration of max time gap for double-tap recognition
        void dur(uint8_t v) { set_bits(raw_, 4, 4, v); }
        uint8_t dur() const { return get_bits(raw_, 4, 4); }

        // QUIET[1:0] : Expected quiet time after a tap detection
        void quiet(uint8_t v) { set_bits(raw_, 2, 2, v); }
        uint8_t quiet() const { return get_bits(raw_, 2, 2); }

        // SHOCK[1:0] : Max duration of overthreshold event
        void shock(uint8_t v) { set_bits(raw_, 0, 2, v); }
        uint8_t shock() const { return get_bits(raw_, 0, 2); }

        // --- Raw setter/getter ---
        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_TAP_DUR";
        uint8_t raw_ = 0;
    };

    class WakeUpThsRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5B;

        // SINGLE_DOUBLE_TAP : Bit 7
        void single_double_tap(bool v) { set_bit(7, v, raw_); }
        bool single_double_tap() const { return get_bit(7, raw_); }

        // USR_OFF_ON_WU : Bit 6
        void usr_off_on_wu(bool v) { set_bit(6, v, raw_); }
        bool usr_off_on_wu() const { return get_bit(6, raw_); }

        // WK_THS_[5:0] : Bits 5:0
        void wk_ths(uint8_t v) { set_bits(raw_, 0, 6, v); }
        uint8_t wk_ths() const { return get_bits(raw_, 0, 6); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_WAKE_UP_THS";
        uint8_t raw_ = 0;
    };

    class WakeUpDurRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5C;

        // FF_DUR_5 : Bit 7 (free-fall duration)
        void ff_dur_5(bool v) { set_bit(7, v, raw_); }
        bool ff_dur_5() const { return get_bit(7, raw_); }

        // WAKE_DUR_[1:0] : Bits 6:5 (wake-up duration)
        void wake_dur(uint8_t v) { set_bits(raw_, 5, 2, v); }
        uint8_t wake_dur() const { return get_bits(raw_, 5, 2); }

        // SLEEP_DUR_[3:0] : Bits 3:0 (sleep mode duration)
        void sleep_dur(uint8_t v) { set_bits(raw_, 0, 4, v); }
        uint8_t sleep_dur() const { return get_bits(raw_, 0, 4); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_WAKE_UP_DUR";
        uint8_t raw_ = 0;
    };

    class FreeFallRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5D;

        // FF_DUR_[4:0] : Bits 7:3 (free-fall duration)
        void ff_dur(uint8_t v) { set_bits(raw_, 3, 5, v); }
        uint8_t ff_dur() const { return get_bits(raw_, 3, 5); }

        // FF_THS_[2:0] : Bits 2:0 (free-fall threshold)
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

        void ff_ths(FfThs v) { set_bits(raw_, 0, 3, static_cast<uint8_t>(v)); }
        FfThs ff_ths() const { return static_cast<FfThs>(get_bits(raw_, 0, 3)); }

        static const char *to_string(FfThs v);

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_FREE_FALL";
        uint8_t raw_ = 0;
    };

    class Md1CfgRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5E;

        void int1_sleep_change(bool v) { set_bit(7, v, raw_); }
        bool int1_sleep_change() const { return get_bit(7, raw_); }

        void int1_single_tap(bool v) { set_bit(6, v, raw_); }
        bool int1_single_tap() const { return get_bit(6, raw_); }

        void int1_wu(bool v) { set_bit(5, v, raw_); }
        bool int1_wu() const { return get_bit(5, raw_); }

        void int1_ff(bool v) { set_bit(4, v, raw_); }
        bool int1_ff() const { return get_bit(4, raw_); }

        void int1_double_tap(bool v) { set_bit(3, v, raw_); }
        bool int1_double_tap() const { return get_bit(3, raw_); }

        void int1_6d(bool v) { set_bit(2, v, raw_); }
        bool int1_6d() const { return get_bit(2, raw_); }

        void int1_emb_func(bool v) { set_bit(1, v, raw_); }
        bool int1_emb_func() const { return get_bit(1, raw_); }

        void int1_shub(bool v) { set_bit(0, v, raw_); }
        bool int1_shub() const { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_MD1_CFG";
        uint8_t raw_ = 0;
    };

    class Md2CfgRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x5F;

        void int2_sleep_change(bool v) { set_bit(7, v, raw_); }
        bool int2_sleep_change() const { return get_bit(7, raw_); }

        void int2_single_tap(bool v) { set_bit(6, v, raw_); }
        bool int2_single_tap() const { return get_bit(6, raw_); }

        void int2_wu(bool v) { set_bit(5, v, raw_); }
        bool int2_wu() const { return get_bit(5, raw_); }

        void int2_ff(bool v) { set_bit(4, v, raw_); }
        bool int2_ff() const { return get_bit(4, raw_); }

        void int2_double_tap(bool v) { set_bit(3, v, raw_); }
        bool int2_double_tap() const { return get_bit(3, raw_); }

        void int2_6d(bool v) { set_bit(2, v, raw_); }
        bool int2_6d() const { return get_bit(2, raw_); }

        void int2_emb_func(bool v) { set_bit(1, v, raw_); }
        bool int2_emb_func() const { return get_bit(1, raw_); }

        void int2_timestamp(bool v) { set_bit(0, v, raw_); }
        bool int2_timestamp() const { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_MD2_CFG";
        uint8_t raw_ = 0;
    };

    class HaodrCfgRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x62;

        enum class HaodrSel : uint8_t
        {
            SET0 = 0b00,
            SET1 = 0b01,
            SET2 = 0b10,
            SET3 = 0b11
        };

        void haodr_sel(HaodrSel v) { set_bits(raw_, 0, 2, static_cast<uint8_t>(v)); }
        HaodrSel haodr_sel() const { return static_cast<HaodrSel>(get_bits(raw_, 0, 2)); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        static const char *to_string(HaodrSel v);

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_HAODR_CFG";
        uint8_t raw_ = 0;
    };

    class EmbFuncCfgRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x63;

        void xl_dualc_batch_from_if(bool v) { set_bit(7, v, raw_); }
        bool xl_dualc_batch_from_if() const { return get_bit(7, raw_); }

        void emb_func_irq_mask_g_settl(bool v) { set_bit(5, v, raw_); }
        bool emb_func_irq_mask_g_settl() const { return get_bit(5, raw_); }

        void emb_func_irq_mask_xl_settl(bool v) { set_bit(4, v, raw_); }
        bool emb_func_irq_mask_xl_settl() const { return get_bit(4, raw_); }

        void emb_func_disable(bool v) { set_bit(2, v, raw_); }
        bool emb_func_disable() const { return get_bit(2, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;

        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_CFG";
        uint8_t raw_ = 0;
    };

} // namespace lsm6dsv16x
