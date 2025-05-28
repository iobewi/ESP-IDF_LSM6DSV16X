#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    // ------------------- FUNC_CFG_ACCESS -------------------
    class FuncCfgAccessRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x01;

        // Setters
        void emb_func_reg_access(bool v) { set_bit(7, v); }
        void shub_reg_access(bool v) { set_bit(6, v); }
        void fsm_wr_ctrl_en(bool v) { set_bit(4, v); }
        void sw_por(bool v) { set_bit(3, v); }
        void spi2_reset(bool v) { set_bit(2, v); }
        void ois_ctrl_from_ui(bool v) { set_bit(0, v); }
        // Getters
        bool emb_func_reg_access() const { return get_bit(7); }
        bool shub_reg_access() const { return get_bit(6); }
        bool fsm_wr_ctrl_en() const { return get_bit(4); }
        bool sw_por() const { return get_bit(3); }
        bool spi2_reset() const { return get_bit(2); }
        bool ois_ctrl_from_ui() const { return get_bit(0); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }
        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_FUNC_CFG_ACCESS";
    };

    // ------------------- PIN_CTRL -------------------
    class PinCtrlRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x02;
        enum class IbhrPorEn : uint8_t
        {
            CONFIG_RESET = 0, // 0: configuration reset (SW reset + dynamic address reset)
            GLOBAL_RESET = 1  // 1: global reset (POR reset)
        };

        static const char *to_string(IbhrPorEn v);

        // Setters
        void ois_pu_dis(bool v) { set_bit(7, v, raw_); }
        void sdo_pu_en(bool v) { set_bit(6, v, raw_); }
        void ibhr_por_en(IbhrPorEn v) { set_bits(raw_, 1, 1, static_cast<uint8_t>(v)); }

        // Getters
        bool ois_pu_dis() const { return get_bit(7, raw_); }
        bool sdo_pu_en() const { return get_bit(6), raw_; }
        IbhrPorEn ibhr_por_en() const { return static_cast<IbhrPorEn>(get_bits(raw_, 1, 1)); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }
        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_PIN_CTRL";
    };

    // ------------------- IF_CFG -------------------
    class IfCfgRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x03;
        // Setters
        void sda_pu_en(bool v) { set_bit(7, v), raw_; }
        void shub_pu_en(bool v) { set_bit(6, v, raw_); }
        void asf_ctrl(bool v) { set_bit(5, v), raw_; }
        void h_lactive(bool v) { set_bit(4, v), raw_; }
        void pp_od(bool v) { set_bit(3, v), raw_; }
        void sim(bool v) { set_bit(2, v), raw_; }
        void i2c_i3c_disable(bool v) { set_bit(0, v, raw_); }
        // Getters
        bool sda_pu_en() const { return get_bit(7, raw_); }
        bool shub_pu_en() const { return get_bit(, raw_6); }
        bool asf_ctrl() const { return get_bit(5, raw_); }
        bool h_lactive() const { return get_bit(4, raw_); }
        bool pp_od() const { return get_bit(3, raw_); }
        bool sim() const { return get_bit(2, raw_); }
        bool i2c_i3c_disable() const { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }
        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_IF_CFG";
    };

    // ------------------- ODR_TRIG_CFG -------------------
    class OdrTrigCfgRegister
    {
    public:
        static constexpr uint8_t reg_addr = 0x06;
        // Setter
        void odr_trig_nodr(uint8_t v) { raw_ = v; }
        // Getter
        uint8_t odr_trig_nodr() const { return raw_; }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }
        void log() const;
        std::string to_json() const;

    private:
        uint8_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_ODR_TRIG_CFG";
    };

    class FifoCtrlRegister
    {
    public:
        static constexpr uint8_t reg_addr = 0x07;
        static constexpr size_t reg_len = 4;

        FifoCtrlRegisters() = default;
        explicit FifoCtrlRegisters(uint32_t raw) : raw_(raw) {}

        // FIFO_CTRL1
        void wtm(uint8_t val) { set_octet<0>(val); }
        uint8_t wtm() const { return get_octet<0>(); }

        // FIFO_CTRL2
        void stop_on_wtm(bool v) { set_flag<1, 7>(v); }
        bool stop_on_wtm() const { return get_flag<1, 7>(); }

        void fifo_compr_rt_en(bool v) { set_flag<1, 6>(v); }
        bool fifo_compr_rt_en() const { return get_flag<1, 6>(); }

        void odr_chg_en(bool v) { set_flag<1, 4>(v); }
        bool odr_chg_en() const { return get_flag<1, 4>(); }

        enum class UncomprRate : uint8_t
        {
            UNFORCED = 0b00,
            EVERY_8 = 0b01,
            EVERY_16 = 0b10,
            EVERY_32 = 0b11,
        };
        static const char *to_string(UncomprRate v);
        void uncompr_rate(UncomprRate v) { set_field<1, 2, 2>(v); }
        UncomprRate uncompr_rate() const { return get_field<1, 2, 2, UncomprRate>(); }

        void xl_dualc_batch_from_fsm(bool v) { set_flag<1, 0>(v); }
        bool xl_dualc_batch_from_fsm() const { return get_flag<1, 0>(); }

        // FIFO_CTRL3
        enum class BdrGy : uint8_t
        {
            NOT_BATCHED = 0b0000,
            HZ_1_875 = 0b0001,
            HZ_7_5 = 0b0010,
            HZ_15 = 0b0011,
            HZ_30 = 0b0100,
            HZ_60 = 0b0101,
            HZ_120 = 0b0110,
            HZ_240 = 0b0111,
            HZ_480 = 0b1000,
            HZ_960 = 0b1001,
            HZ_1_92K = 0b1010,
            HZ_3_84K = 0b1011,
            HZ_7_68K = 0b1100,
            RESERVED = 0b1101
        };
        static const char *to_string(BdrGy v);
        void bdr_gy(BdrGy v) { set_field<2, 4, 4>(v); }
        BdrGy bdr_gy() const { return get_field<2, 4, 4, BdrGy>(); }

        enum class BdrXl : uint8_t
        {
            NOT_BATCHED = 0b0000,
            HZ_1_875 = 0b0001,
            HZ_7_5 = 0b0010,
            HZ_15 = 0b0011,
            HZ_30 = 0b0100,
            HZ_60 = 0b0101,
            HZ_120 = 0b0110,
            HZ_240 = 0b0111,
            HZ_480 = 0b1000,
            HZ_960 = 0b1001,
            HZ_1_92K = 0b1010,
            HZ_3_84K = 0b1011,
            HZ_7_68K = 0b1100,
            RESERVED = 0b1101
        };
        static const char *to_string(BdrXl v);
        void bdr_xl(BdrXl v) { set_field<2, 0, 4>(v); }
        BdrXl bdr_xl() const { return get_field<2, 0, 4, BdrXl>(); }

        // FIFO_CTRL4
        enum class DecTsBatch : uint8_t
        {
            NONE = 0b00,
            BY_8 = 0b01,
            BY_16 = 0b10,
            BY_32 = 0b11
        };
        static const char *to_string(DecTsBatch v);
        void dec_ts_batch(DecTsBatch v) { set_field<3, 6, 2>(v); }
        DecTsBatch dec_ts_batch() const { return get_field<3, 6, 2, DecTsBatch>(); }

        enum class OdrTBatch : uint8_t
        {
            NOT_BATCHED = 0b00,
            HZ_1_875 = 0b01,
            HZ_15 = 0b10,
            HZ_60 = 0b11
        };
        static const char *to_string(OdrTBatch v);
        void odr_t_batch(OdrTBatch v) { set_field<3, 4, 2>(v); }
        OdrTBatch odr_t_batch() const { return get_field<3, 4, 2, OdrTBatch>(); }

        void g_eis_fifo_en(bool v) { set_flag<3, 3>(v); }
        bool g_eis_fifo_en() const { return get_flag<3, 3>(); }

        enum class FifoMode : uint8_t
        {
            BYPASS = 0b000,
            FIFO = 0b001,
            CONT_WTM2FULL = 0b010,
            CONT2FIFO = 0b011,
            BYPASS2CONT = 0b100,
            RESERVED_101 = 0b101,
            CONTINUOUS = 0b110,
            BYPASS2FIFO = 0b111,
        };
        static const char *to_string(FifoMode v);
        void fifo_mode(FifoMode v) { set_field<3, 0, 3>(v); }
        FifoMode fifo_mode() const { return get_field<3, 0, 3, FifoMode>(); }

        // Raw access
        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        uint32_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_FIFO_CTRL";
    };

    class CounterBdrRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x0B;

        CounterBdrRegister() = default;
        explicit CounterBdrRegister(uint16_t raw) : raw_(raw) {}

        // --- Enum pour le champ multi-bits ---
        enum class TrigCounterBdr : uint8_t
        {
            ACCEL = 0b00,
            GYRO = 0b01,
            EIS = 0b10,
            EIS2 = 0b11 // Réservé, identique à EIS
        };
        static const char *to_string(TrigCounterBdr v);

        // Setters
        void trig_counter_bdr(TrigCounterBdr v) { set_field<0, 4, 2>(v); }
        void cnt_bdr_th_h(uint8_t v) { set_field<0, 0, 2>(v); }
        void cnt_bdr_th_l(uint8_t v) { set_octet<1>(v); }

        // Getters
        TrigCounterBdr trig_counter_bdr() const { return get_field<0, 4, 2, TrigCounterBdr>(); }
        uint8_t cnt_bdr_th_h() const { return get_field<0, 0, 2, uint8_t>(); }
        uint8_t cnt_bdr_th_l() const { return get_octet<1>(); }

        // Helper
        uint16_t cnt_bdr_th() const
        { // sur 9 bits, si besoin
            return (cnt_bdr_th_h() << 8) | cnt_bdr_th_l();
        }

        void cnt_bdr_th(uint16_t v)
        {
            cnt_bdr_th_h((v >> 8) & 0x03); // Les 2 bits de poids fort (9:8)
            cnt_bdr_th_l(v & 0xFF);        // Les 8 bits de poids faible (7:0)
        }

        // Register RAW access
        void set_raw(uint16_t raw) { raw_ = raw; }
        uint16_t get_raw() const { return raw_; }

        // Debug/log
        void log() const;
        std::string to_json() const;

    private:
        uint16_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_COUNTER_BDR";
    };

    class IntCtrlRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x0D;

        IntCtrlRegister() = default;
        explicit IntCtrlRegister(uint16_t raw) : raw_(raw) {}

        // Setters
        void cnt_bdr(bool v) { set_flag<0, 7>(v); }
        void fifo_full(bool v) { set_flag<0, 6>(v); }
        void fifo_ovr(bool v) { set_flag<0, 5>(v); }
        void fifo_th(bool v) { set_flag<0, 4>(v); }
        void drdy_g(bool v) { set_flag<0, 2>(v); }
        void drdy_xl(bool v) { set_flag<0, 0>(v); }
        void emb_func_endop(bool v) { set_flag<1, 7>(v); }
        void cnt_bdr(bool v) { set_flag<1, 6>(v); }
        void fifo_full(bool v) { set_flag<1, 5>(v); }
        void fifo_ovr(bool v) { set_flag<1, 4>(v); }
        void fifo_th(bool v) { set_flag<1, 3>(v); }
        void drdy_g_eis(bool v) { set_flag<1, 2>(v); }
        void drdy_g(bool v) { set_flag<1, 1>(v); }
        void drdy_xl(bool v) { set_flag<1, 0>(v); }

        // Getters
        bool cnt_bdr() const { return get_flag<0, 7>(); }
        bool fifo_full() const { return get_flag<0, 6>(); }
        bool fifo_ovr() const { return get_flag<0, 5>(); }
        bool fifo_th() const { return get_flag<0, 4>(); }
        bool drdy_g() const { return get_flag<0, 2>(); }
        bool drdy_xl() const { return get_flag<0, 0>(); }
        bool emb_func_endop() const { return get_flag<1, 7>(); }
        bool cnt_bdr() const { return get_flag<1, 6>(); }
        bool fifo_full() const { return get_flag<1, 5>(); }
        bool fifo_ovr() const { return get_flag<1, 4>(); }
        bool fifo_th() const { return get_flag<1, 3>(); }
        bool drdy_g_eis() const { return get_flag<1, 2>(); }
        bool drdy_g() const { return get_flag<1, 1>(); }
        bool drdy_xl() const { return get_flag<1, 0>(); }

        // Register RAW access
        void set_raw(uint16_t raw) { raw_ = raw; }
        uint16_t get_raw() const { return raw_; }

        // Debug/log
        void log() const;
        std::string to_json() const;

    private:
        uint16_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_INT_CTRL";
    };

    class CtrlEisRegister : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x6B;

        // ODR_G_EIS_[1:0]
        enum class OdrGEis : uint8_t
        {
            OFF = 0b00,
            HZ_1920 = 0b01,
            HZ_960 = 0b10,
            RESERVED = 0b11
        };

        // FS_G_EIS_[2:0]
        enum class FsGEis : uint8_t
        {
            DPS_125 = 0b000,
            DPS_250 = 0b001,
            DPS_500 = 0b010,
            DPS_1000 = 0b011,
            DPS_2000 = 0b100,
            RESERVED_101 = 0b101,
            RESERVED_110 = 0b110,
            RESERVED_111 = 0b111,
        };

        // Setters
        void odr_g_eis(OdrGEis v) { set_bits(raw_, 6, 2, static_cast<uint8_t>(v)); }
        void lpf_g_eis_bw(bool v) { set_bit(5, v, raw_); }
        void g_eis_on_g_ois_out_reg(bool v) { set_bit(4, v, raw_); }
        void fs_g_eis(FsGEis v) { set_bits(raw_, 0, 3, static_cast<uint8_t>(v)); }

        // Getters
        OdrGEis odr_g_eis() const { return static_cast<OdrGEis>(get_bits(raw_, 6, 2)); }
        bool lpf_g_eis_bw() const { return get_bit(5, raw_); }
        bool g_eis_on_g_ois_out_reg() const { return get_bit(4, raw_); }
        FsGEis fs_g_eis() const { return static_cast<FsGEis>(get_bits(raw_, 0, 3)); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        // Logging et JSON
        void log() const;
        std::string to_json() const;

        static const char *to_string(OdrGEis v);
        static const char *to_string(FsGEis v);

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL_EIS";
        uint8_t raw_ = 0;
    };
} // namespace lsm6dsv16x
