#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl1Register, uint8_t, 0x10)
        public:
            enum class OpMode : uint8_t
            {
                HIGH_PERFORMANCE = 0b000,
                HIGH_ACCURACY_ODR = 0b001,
                RESERVED = 0b010,
                ODR_TRIGGERED = 0b011,
                LOW_POWER_1 = 0b100,
                LOW_POWER_2 = 0b101,
                LOW_POWER_3 = 0b110,
                NORMAL = 0b111,
            };

            enum class Odr : uint8_t
            {
                POWER_DOWN = 0b0000,
                ODR_1_875Hz = 0b0001,
                ODR_7_5Hz = 0b0010,
                ODR_15Hz = 0b0011,
                ODR_30Hz = 0b0100,
                ODR_60Hz = 0b0101,
                ODR_120Hz = 0b0110,
                ODR_240Hz = 0b0111,
                ODR_480Hz = 0b1000,
                ODR_960Hz = 0b1001,
                ODR_1920Hz = 0b1010,
                ODR_3840Hz = 0b1011,
                ODR_7680Hz = 0b1100,
                RESERVED = 0b1101
            };

            // Setters
            void odr_xl(Odr v) { set_field<0, 0, 4>(v); }
            void op_mode_xl(OpMode v) { set_field<0, 4, 3>(v); }

            // Getters
            Odr odr_xl() const { return get_field<0, 0, 4, Odr>(); }
            OpMode op_mode_xl() const { return get_field<0, 4, 3, OpMode>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL1";
            static const char *to_string(Odr odr);
            static const char *to_string(OpMode mode);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl2Register, uint8_t, 0x11)
        public:
            enum class OpMode : uint8_t
            {
                HIGH_PERFORMANCE = 0b000,
                HIGH_ACCURACY_ODR = 0b001,
                RESERVED_1 = 0b010,
                ODR_TRIGGERED = 0b011,
                SLEEP = 0b100,
                LOW_POWER = 0b101,
                RESERVED_2 = 0b110,
                RESERVED_3 = 0b111,
            };

            enum class Odr : uint8_t
            {
                POWER_DOWN = 0b0000,
                ODR_7_5Hz = 0b0001,
                ODR_15Hz = 0b0010,
                ODR_30Hz = 0b0011,
                ODR_60Hz = 0b0100,
                ODR_120Hz = 0b0101,
                ODR_240Hz = 0b0110,
                ODR_480Hz = 0b0111,
                ODR_960Hz = 0b1000,
                ODR_1_92kHz = 0b1001,
                ODR_3_84kHz = 0b1010,
                ODR_7_68kHz = 0b1011,
                RESERVED = 0b1100,
            };

            // Setters
            void odr_g(Odr v) { set_field<0, 0, 4>(v); }
            void op_mode_g(OpMode v) { set_field<0, 4, 3>(v); }

            // Getters
            Odr odr_g() const { return get_field<0, 0, 4, Odr>(); }
            OpMode op_mode_g() const { return get_field<0, 4, 3, OpMode>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL2";
            static const char *to_string(Odr odr);
            static const char *to_string(OpMode mode);

    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl3Register, uint8_t, 0x12)
        public:
            // Setters
            void boot(bool v) { set_flag<0, 7>(v); }
            void bdu(bool v) { set_flag<0, 6>(v); }
            void if_inc(bool v) { set_flag<0, 2>(v); }
            void sw_reset(bool v) { set_flag<0, 0>(v); }

            // Getters
            bool boot() const { return get_flag<0, 7>(); }
            bool bdu() const { return get_flag<0, 6>(); }
            bool if_inc() const { return get_flag<0, 2>(); }
            bool sw_reset() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL3";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl4Register, uint8_t, 0x13)
        public:
            // Setters
            void int2_on_int1(bool v) { set_flag<0, 4>(v); }
            void drdy_mask(bool v) { set_flag<0, 3>(v); }
            void int2_drdy_temp(bool v) { set_flag<0, 2>(v); }
            void drdy_pulsed(bool v) { set_flag<0, 1>(v); }
            void int2_in_lh(bool v) { set_flag<0, 0>(v); }

            // Getters
            bool int2_on_int1() const { return get_flag<0, 4>(); }
            bool drdy_mask() const { return get_flag<0, 3>(); }
            bool int2_drdy_temp() const { return get_flag<0, 2>(); }
            bool drdy_pulsed() const { return get_flag<0, 1>(); }
            bool int2_in_lh() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL4";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl5Register, uint8_t, 0x14)
        public:
            enum class BusActSel : uint8_t
            {
                US_2 = 0b00,
                US_50 = 0b01,
                MS_1 = 0b10,
                MS_25 = 0b11,
            };

            // Setters
            void bus_act_sel(BusActSel v) { set_field<0, 0, 2>(v); }
            void int_en_i3c(bool v) { set_flag<0, 7>(v); }

            // Getters
            BusActSel bus_act_sel() const { return get_field<0, 0, 2, BusActSel>(); }
            bool int_en_i3c() const { return get_flag<0, 7>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL5";
            static const char *to_string(BusActSel v);

    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl6Register, uint8_t, 0x15)
        public:
            enum class Lpf1GBw : uint8_t
            {
                BW_0 = 0b000,
                BW_1 = 0b001,
                BW_2 = 0b010,
                BW_3 = 0b011,
                BW_4 = 0b100,
                BW_5 = 0b101,
                BW_6 = 0b110,
                BW_7 = 0b111,
            };

            enum class FsG : uint8_t
            {
                DPS_125 = 0b0000,
                DPS_250 = 0b0001,
                DPS_500 = 0b0010,
                DPS_1000 = 0b0011,
                DPS_2000 = 0b0100,
                DPS_4000 = 0b1100,
                RESERVED = 0b1111,
            };

            // Setters
            void lpf1_g_bw(Lpf1GBw v) { set_field<0, 5, 3>(v); }
            void fs_g(FsG v) { set_field<0, 0, 5>(v); }

            // Getters
            Lpf1GBw lpf1_g_bw() const { return get_field<0, 5, 3, Lpf1GBw>(); }
            FsG fs_g() const { return get_field<0, 0, 5, FsG>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL6";
            static const char *to_string(Lpf1GBw v);
            static const char *to_string(FsG v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl7Register, uint8_t, 0x16)
        public:
            enum class AhQvarCZin : uint8_t
            {
                G2_4 = 0b00, // 2.4 GΩ (default)
                M730 = 0b01, // 730 MΩ
                M300 = 0b10, // 300 MΩ
                M235 = 0b11  // 235 MΩ
            };

            // Setters
            void ah_qvar_en(bool v) { set_flag<0, 7>(v); }
            void int2_drdy_ah_qvar(bool v) { set_flag<0, 6>(v); }
            void ah_qvar_c_zin(AhQvarCZin v) { set_field<0, 4, 2>(v); }
            void lpf1_g_en(bool v) { set_flag<0, 0>(v); }

            // Getters
            bool ah_qvar_en() const { return get_flag<0, 7>(); }
            bool int2_drdy_ah_qvar() const { return get_flag<0, 6>(); }
            AhQvarCZin ah_qvar_c_zin() const { return get_field<0, 4, 2, AhQvarCZin>(); }
            bool lpf1_g_en() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL7";
            static const char *to_string(AhQvarCZin v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl8Register, uint8_t, 0x17)
        public:
            // HP_LPF2_XL_BW_[2:0] : bits 7:5
            enum class HpLpf2XlBw : uint8_t
            {
                ODR_4 = 0b000,
                ODR_10 = 0b001,
                ODR_20 = 0b010,
                ODR_45 = 0b011,
                ODR_100 = 0b100,
                ODR_200 = 0b101,
                ODR_400 = 0b110,
                ODR_800 = 0b111
            };

            // FS_XL_[1:0] : bits 1:0
            enum class FsXl : uint8_t
            {
                G2 = 0b00, // ±2g (default)
                G4 = 0b01, // ±4g
                G8 = 0b10, // ±8g
                G16 = 0b11 // ±16g
            };

            // Setters
            void hp_lpf2_xl_bw(HpLpf2XlBw v) { set_field<0, 5, 3>(v); }
            void xl_dualc_en(bool v) { set_flag<0, 2>(v); }
            void fs_xl(FsXl v) { set_field<0, 0, 2>(v); }

            // Getters
            HpLpf2XlBw hp_lpf2_xl_bw() const { return get_field<0, 5, 3, HpLpf2XlBw>(); }
            bool xl_dualc_en() const { return get_flag<0, 2>(); }
            FsXl fs_xl() const { return get_field<0, 0, 2, FsXl>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL8";
            static const char *to_string(HpLpf2XlBw v);
            static const char *to_string(FsXl v);

    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl9Register, uint8_t, 0x18)
        public:
            enum class UsrOffW : uint8_t
            {
                POW_10 = 0, // 2^-10 g/LSB (default)
                POW_6 = 1,  // 2^-6 g/LSB
            };
            
            // Setters
            void hp_ref_mode_xl(bool v) { set_flag<0, 6>(v); }
            void xl_fastsettl_mode(bool v) { set_flag<0, 5>(v); }
            void hp_slope_xl_en(bool v) { set_flag<0, 4>(v); }
            void lpf2_xl_en(bool v) { set_flag<0, 3>(v); }
            void usr_off_w(UsrOffW v) { set_field<0, 2, 1>(v); }
            void usr_off_on_out(bool v) { set_flag<0, 1>(v); }

            // Getters
            bool hp_ref_mode_xl() const { return get_flag<0, 6>(); }
            bool xl_fastsettl_mode() const { return get_flag<0, 5>(); }
            bool hp_slope_xl_en() const { return get_flag<0, 4>(); }
            bool lpf2_xl_en() const { return get_flag<0, 3>(); }
            UsrOffW usr_off_w() const { return get_field<0, 2, 1, UsrOffW>(); }
            bool usr_off_on_out() const { return get_flag<0, 1>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL9";
            static const char *to_string(UsrOffW v);

    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(Ctrl10Register, uint8_t, 0x19)
        public:
            enum class StG : uint8_t
            {
                NORMAL = 0b00,
                POS = 0b01,
                NEG = 0b10,
                RESERVED = 0b11
            };
            enum class StXl : uint8_t
            {
                NORMAL = 0b00,
                POS = 0b01,
                NEG = 0b10,
                RESERVED = 0b11
            };

            // Setters
            void emb_func_debug(bool v) { set_flag<0, 5>(v); }
            void st_g(StG v) { set_field<0, 2, 2>(v); }
            void st_xl(StXl v) { set_field<0, 0, 2>(v); }

            // Getters
            bool emb_func_debug() const { return get_flag<0, 5>(); }
            StG st_g() const { return get_field<0, 2, 2, StG>(); }
            StXl st_xl() const { return get_field<0, 0, 2, StXl>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL10";

            static const char *to_string(StG v);
            static const char *to_string(StXl v);

    END_REGISTER

} // namespace lsm6dsv16x
