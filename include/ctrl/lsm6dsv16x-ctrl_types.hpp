#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    class Ctrl1Register
    {
    public:
        static constexpr uint8_t reg_addr = 0x10;

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


            static const char *to_string(Odr odr);
            static const char *to_string(OpMode mode);

        // Setters
        void odr_xl(Odr v)     { raw_ = (raw_ & 0xF0) | (static_cast<uint8_t>(v) & 0x0F); }
        void op_mode_xl(OpMode v) { raw_ = (raw_ & 0x8F) | ((static_cast<uint8_t>(v) & 0x07) << 4); }

        // Getters
        Odr odr_xl() const     { return static_cast<Odr>(raw_ & 0x0F); }
        OpMode op_mode_xl() const { return static_cast<OpMode>((raw_ >> 4) & 0x07); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL1";
        uint8_t raw_ = 0;
    };

    class Ctrl2Register
    {
    public:
        static constexpr uint8_t reg_addr = 0x11;

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

            static const char *to_string(Odr odr);
            static const char *to_string(OpMode mode);

        // Setters
        void odr_g(Odr v)      { raw_ = (raw_ & 0xF0) | (static_cast<uint8_t>(v) & 0x0F); }
        void op_mode_g(OpMode v) { raw_ = (raw_ & 0x8F) | ((static_cast<uint8_t>(v) & 0x07) << 4); }

        // Getters
        Odr odr_g() const      { return static_cast<Odr>(raw_ & 0x0F); }
        OpMode op_mode_g() const { return static_cast<OpMode>((raw_ >> 4) & 0x07); }


        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL2";
        uint8_t raw_ = 0;
    };

    class Ctrl3Register : protected RegisterBase
    {
    public:
        static constexpr uint8_t reg_addr = 0x12;

        // Setters
        void boot(bool v)       { set_bit(7, v, raw_); }
        void bdu(bool v)        { set_bit(6, v, raw_); }
        void if_inc(bool v)     { set_bit(2, v, raw_); }
        void sw_reset(bool v)   { set_bit(0, v, raw_); }

        // Getters
        bool boot() const       { return get_bit(7, raw_); }
        bool bdu() const        { return get_bit(6, raw_); }
        bool if_inc() const     { return get_bit(2, raw_); }
        bool sw_reset() const   { return get_bit(0, raw_); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL3";
        uint8_t raw_ = 0;
    };

   class Ctrl4Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x13;

    // Setters
    void int2_on_int1(bool v)    { set_bit(4, v, raw_); }
    void drdy_mask(bool v)       { set_bit(3, v, raw_); }
    void int2_drdy_temp(bool v)  { set_bit(2, v, raw_); }
    void drdy_pulsed(bool v)     { set_bit(1, v, raw_); }
    void int2_in_lh(bool v)      { set_bit(0, v, raw_); }

    // Getters
    bool int2_on_int1() const    { return get_bit(4, raw_); }
    bool drdy_mask() const       { return get_bit(3, raw_); }
    bool int2_drdy_temp() const  { return get_bit(2, raw_); }
    bool drdy_pulsed() const     { return get_bit(1, raw_); }
    bool int2_in_lh() const      { return get_bit(0, raw_); }

    // Raw access
    void set_raw(uint8_t raw) { raw_ = raw; }
    uint8_t get_raw() const   { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL4";
};

class Ctrl5Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x14;

    enum class BusActSel : uint8_t
    {
        US_2  = 0b00,
        US_50 = 0b01,
        MS_1  = 0b10,
        MS_25 = 0b11,
    };
    static const char* to_string(BusActSel v);

    // Setters
    void bus_act_sel(BusActSel v)  { raw_ = (raw_ & ~0x03) | (static_cast<uint8_t>(v) & 0x03); }
    void int_en_i3c(bool v)        { set_bit(7, v, raw_); }

    // Getters
    BusActSel bus_act_sel() const  { return static_cast<BusActSel>(raw_ & 0x03); }
    bool int_en_i3c() const        { return get_bit(7, raw_); }

    // Raw access
    void set_raw(uint8_t raw)      { raw_ = raw; }
    uint8_t get_raw() const        { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL5";
};

    class Ctrl6Register
    {
    public:
        static constexpr uint8_t reg_addr = 0x15;

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

            static const char *to_string(Lpf1GBw v);
            static const char *to_string(FsG v);

 // Setters
    void lpf1_g_bw(Lpf1GBw v)   { raw_ = (raw_ & 0x1F) | (static_cast<uint8_t>(v) << 5); }
    void fs_g(FsG v)            { raw_ = (raw_ & 0xE0) | (static_cast<uint8_t>(v) & 0x1F); }

    // Getters
    Lpf1GBw lpf1_g_bw() const   { return static_cast<Lpf1GBw>((raw_ >> 5) & 0x07); }
    FsG fs_g() const            { return static_cast<FsG>(raw_ & 0x1F); }

    // Raw access
    void set_raw(uint8_t raw)   { raw_ = raw; }
    uint8_t get_raw() const     { return raw_; }

        void log() const;
        std::string to_json() const;

    private:
        inline static const char *TAG = "LSM6DSV16X_CTRL6";
        uint8_t raw_ = 0;
    };

    class Ctrl7Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x16;

    enum class AhQvarCZin : uint8_t
    {
        G2_4 = 0b00, // 2.4 GΩ (default)
        M730 = 0b01, // 730 MΩ
        M300 = 0b10, // 300 MΩ
        M235 = 0b11  // 235 MΩ
    };

    static const char* to_string(AhQvarCZin v);

    // Setters
    void ah_qvar_en(bool v)         { set_bit(7, v, raw_); }
    void int2_drdy_ah_qvar(bool v)  { set_bit(6, v, raw_); }
    void ah_qvar_c_zin(AhQvarCZin v){ raw_ = (raw_ & ~(0x03 << 4)) | (static_cast<uint8_t>(v) << 4); }
    void lpf1_g_en(bool v)          { set_bit(0, v, raw_); }

    // Getters
    bool ah_qvar_en() const         { return get_bit(7, raw_); }
    bool int2_drdy_ah_qvar() const  { return get_bit(6, raw_); }
    AhQvarCZin ah_qvar_c_zin() const{ return static_cast<AhQvarCZin>((raw_ >> 4) & 0x03, raw_); }
    bool lpf1_g_en() const          { return get_bit(0, raw_); }

    // Raw access
    void set_raw(uint8_t raw)       { raw_ = raw; }
    uint8_t get_raw() const         { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL7";
};

    class Ctrl8Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x17;

    // HP_LPF2_XL_BW_[2:0] : bits 7:5
    enum class HpLpf2XlBw : uint8_t
    {
        ODR_4   = 0b000,
        ODR_10  = 0b001,
        ODR_20  = 0b010,
        ODR_45  = 0b011,
        ODR_100 = 0b100,
        ODR_200 = 0b101,
        ODR_400 = 0b110,
        ODR_800 = 0b111
    };

    // FS_XL_[1:0] : bits 1:0
    enum class FsXl : uint8_t
    {
        G2  = 0b00, // ±2g (default)
        G4  = 0b01, // ±4g
        G8  = 0b10, // ±8g
        G16 = 0b11  // ±16g
    };

    static const char* to_string(HpLpf2XlBw v);
    static const char* to_string(FsXl v);

    // Setters
    void hp_lpf2_xl_bw(HpLpf2XlBw v) { raw_ = (raw_ & 0x1F) | (static_cast<uint8_t>(v) << 5); }
    void xl_dualc_en(bool v)         { set_bit(2, v, raw_); }
    void fs_xl(FsXl v)               { raw_ = (raw_ & ~0x03) | (static_cast<uint8_t>(v) & 0x03); }

    // Getters
    HpLpf2XlBw hp_lpf2_xl_bw() const { return static_cast<HpLpf2XlBw>((raw_ >> 5) & 0x07); }
    bool xl_dualc_en() const         { return get_bit(2, raw_); }
    FsXl fs_xl() const               { return static_cast<FsXl>(raw_ & 0x03); }

    // Raw access
    void set_raw(uint8_t raw)        { raw_ = raw; }
    uint8_t get_raw() const          { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL8";
};

    class Ctrl9Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x18;

    enum class UsrOffW : uint8_t
    {
        POW_10 = 0, // 2^-10 g/LSB (default)
        POW_6  = 1, // 2^-6 g/LSB
    };

    static const char* to_string(UsrOffW v);

    // Setters
    void hp_ref_mode_xl(bool v)     { set_bit(6, v, raw_); }
    void xl_fastsettl_mode(bool v)  { set_bit(5, v, raw_); }
    void hp_slope_xl_en(bool v)     { set_bit(4, v, raw_); }
    void lpf2_xl_en(bool v)         { set_bit(3, v, raw_); }
    void usr_off_w(UsrOffW v)       { set_bit(2, static_cast<uint8_t>(v) & 0x01, raw_); }
    void usr_off_on_out(bool v)     { set_bit(1, v, raw_); }

    // Getters
    bool hp_ref_mode_xl() const     { return get_bit(6, raw_); }
    bool xl_fastsettl_mode() const  { return get_bit(5, raw_); }
    bool hp_slope_xl_en() const     { return get_bit(4, raw_); }
    bool lpf2_xl_en() const         { return get_bit(3, raw_); }
    UsrOffW usr_off_w() const       { return static_cast<UsrOffW>((raw_ >> 2) & 0x01, raw_); }
    bool usr_off_on_out() const     { return get_bit(1, raw_); }

    // Raw access
    void set_raw(uint8_t raw)       { raw_ = raw; }
    uint8_t get_raw() const         { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL9";
};

   class Ctrl10Register : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x19;

    enum class StG : uint8_t
    {
        NORMAL    = 0b00,
        POS       = 0b01,
        NEG       = 0b10,
        RESERVED  = 0b11
    };
    enum class StXl : uint8_t
    {
        NORMAL    = 0b00,
        POS       = 0b01,
        NEG       = 0b10,
        RESERVED  = 0b11
    };

    static const char* to_string(StG v);
    static const char* to_string(StXl v);

    // Setters
    void emb_func_debug(bool v)    { set_bit(5, v, raw_); }
    void st_g(StG v)               { raw_ = (raw_ & ~(0x03 << 2)) | (static_cast<uint8_t>(v) << 2); }
    void st_xl(StXl v)             { raw_ = (raw_ & ~0x03) | (static_cast<uint8_t>(v) & 0x03); }

    // Getters
    bool emb_func_debug() const    { return get_bit(5, raw_); }
    StG st_g() const               { return static_cast<StG>((raw_ >> 2) & 0x03); }
    StXl st_xl() const             { return static_cast<StXl>(raw_ & 0x03); }

    // Raw access
    void set_raw(uint8_t raw)      { raw_ = raw; }
    uint8_t get_raw() const        { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    uint8_t raw_ = 0;
    inline static const char* TAG = "LSM6DSV16X_CTRL10";
};

} // namespace lsm6dsv16x
