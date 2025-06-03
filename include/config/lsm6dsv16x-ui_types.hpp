#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

DEFINE_GENERIC_REGISTER_ADDR(UiHandshakeCtrlRegister, uint8_t, 0x64)
    public:
        // Setters
        void ui_shared_ack(bool v) { set_flag<0, 1>(v); }
        void ui_shared_req(bool v) { set_flag<0, 0>(v); }

        // Getters
        bool ui_shared_ack() const { return get_flag<0, 1>(); }
        bool ui_shared_req() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "HANDSHAKE_CTRL";

END_REGISTER

    class UiSpi2SharedRegister
    {
    public:
        UiSpi2SharedRegister(uint8_t addr) : reg_addr(addr) {}

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void log() const;
        std::string to_json() const;

    protected:
        uint8_t raw_ = 0;

    private:
        uint8_t reg_addr;
        static std::string to_hex(uint8_t v);
        inline static const char *TAG = "LSM6DSV16X_UI_SPI2_SHARED";
    };

    class UiSpi2Shared0Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared0Register() : UiSpi2SharedRegister(0x65) {}
    };

    class UiSpi2Shared1Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared1Register() : UiSpi2SharedRegister(0x66) {}
    };

    class UiSpi2Shared2Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared2Register() : UiSpi2SharedRegister(0x67) {}
    };

    class UiSpi2Shared3Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared3Register() : UiSpi2SharedRegister(0x68) {}
    };

    class UiSpi2Shared4Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared4Register() : UiSpi2SharedRegister(0x69) {}
    };

    class UiSpi2Shared5Register : public UiSpi2SharedRegister
    {
    public:
        UiSpi2Shared5Register() : UiSpi2SharedRegister(0x6A) {}
    };

DEFINE_GENERIC_REGISTER_ADDR(UiIntOisRegister, uint8_t, 0x6F)
    public:
        // Setters
        void int2_drdy_ois(bool v)      { set_flag<0, 7>(v); }
        void drdy_mask_ois(bool v)      { set_flag<0, 6>(v); }
        void st_ois_clampdis(bool v)    { set_flag<0, 3>(v); }

        // Getters
        bool int2_drdy_ois() const      { return get_flag<0, 7>(); }
        bool drdy_mask_ois() const      { return get_flag<0, 6>(); }
        bool st_ois_clampdis() const    { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_UI_INT_OIS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(UiCtrl1OisRegister, uint8_t, 0x70)
    public:
        // Setters
        void sim_ois(bool v)        { set_flag<0, 5>(v); } // Bit 5
        void ois_xl_en(bool v)      { set_flag<0, 3>(v); } // Bit 3
        void ois_g_en(bool v)       { set_flag<0, 2>(v); } // Bit 2
        void spi2_read_en(bool v)   { set_flag<0, 0>(v); } // Bit 0

        // Getters
        bool sim_ois() const        { return get_flag<0, 5>(); }
        bool ois_xl_en() const      { return get_flag<0, 3>(); }
        bool ois_g_en() const       { return get_flag<0, 2>(); }
        bool spi2_read_en() const   { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_UI_CTRL1_OIS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(UiCtrl2OisRegister, uint8_t, 0x71)

    public:
        // Enum Class
        enum class Lpf1GOisBw : uint8_t
        {
            HZ_293 = 0b00,
            HZ_217 = 0b01,
            HZ_158 = 0b10,
            HZ_476 = 0b11
        };

        enum class FsGOis : uint8_t
        {
            DPS_125 = 0b000,
            DPS_250 = 0b001,
            DPS_500 = 0b010,
            DPS_1000 = 0b011,
            DPS_2000 = 0b100,
            RESERVED_1 = 0b101,
            RESERVED_2 = 0b110,
            RESERVED_3 = 0b111
        };

        // Setters
        void lpf1_g_ois_bw(Lpf1GOisBw v) { set_field<0, 5, 2>(v); }
        void fs_g_ois(FsGOis v) { set_field<0, 0, 3>(v); }

        // Getters
        Lpf1GOisBw lpf1_g_ois_bw() const { return get_field<0, 5, 2, Lpf1GOisBw>(); }
        FsGOis fs_g_ois() const { return get_field<0, 0, 3, FsGOis>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_UI_CTRL2_OIS";
        static const char *to_string(Lpf1GOisBw v);
        static const char *to_string(FsGOis v);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(UiCtrl3OisRegister, uint8_t, 0x72)
    public:
        // Enum Class
        enum class LpfXlOisBw : uint8_t
        {
            HZ_749 = 0b000,
            HZ_539 = 0b001,
            HZ_342 = 0b010,
            HZ_162 = 0b011,
            HZ_78_5 = 0b100,
            HZ_38_6 = 0b101,
            HZ_19_3 = 0b110,
            HZ_9_8 = 0b111
        };
        enum class FsXlOis : uint8_t
        {
            G2 = 0b00,
            G4 = 0b01,
            G8 = 0b10,
            G16 = 0b11
        };

        // Setters
        void lpf_xl_ois_bw(LpfXlOisBw v) { set_field<0, 5, 3>(v); }
        void fs_xl_ois(FsXlOis v) { set_field<0, 1, 2>(v); }

        // Getters
        LpfXlOisBw lpf_xl_ois_bw() const { return get_field<0, 5, 3, LpfXlOisBw>(); }
        FsXlOis fs_xl_ois() const { return get_field<0, 1, 2, FsXlOis>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_UI_CTRL3_OIS";

                static const char *to_string(LpfXlOisBw v);
        static const char *to_string(FsXlOis v);
END_REGISTER

} // namespace lsm6dsv16x