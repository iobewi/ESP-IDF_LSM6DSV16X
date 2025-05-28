#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
class UiHandshakeCtrlRegister : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x64;

    // Setters
    void ui_shared_ack(bool v) { set_bit(1, v, raw_); }
    void ui_shared_req(bool v) { set_bit(0, v, raw_); }

    // Getters
    bool ui_shared_ack() const { return get_bit(1, raw_); }
    bool ui_shared_req() const { return get_bit(0, raw_); }

    void set_raw(uint8_t raw) { raw_ = raw; }
    uint8_t get_raw() const { return raw_; }

    // Log & JSON (à adapter selon ton style habituel)
    void log() const
    {
        ESP_LOGI("LSM6DSV16X_UI_HANDSHAKE_CTRL", "raw=0x%02X ui_shared_ack=%d ui_shared_req=%d", raw_, ui_shared_ack(), ui_shared_req());
    }
    std::string to_json() const
    {
        return std::string("{") +
            "\"ui_shared_ack\":" + (ui_shared_ack() ? "true" : "false") + "," +
            "\"ui_shared_req\":" + (ui_shared_req() ? "true" : "false") +
        "}";
    }

private:
    uint8_t raw_ = 0;
};

class UiSpi2SharedRegister
{
public:
    UiSpi2SharedRegister(uint8_t addr) : reg_addr(addr) {}

    void set_raw(uint8_t raw) { raw_ = raw; }
    uint8_t get_raw() const { return raw_; }

    void log() const
    {
        ESP_LOGI("LSM6DSV16X_UI_SPI2_SHARED", "reg_addr=0x%02X raw=0x%02X", reg_addr, raw_);
    }

    std::string to_json() const
    {
        return std::string("{") +
            "\"reg_addr\":0x" + to_hex(reg_addr) + "," +
            "\"raw\":0x" + to_hex(raw_) +
            "}";
    }

private:
    uint8_t reg_addr;
    uint8_t raw_ = 0;

    static std::string to_hex(uint8_t v)
    {
        char buf[5];
        snprintf(buf, sizeof(buf), "%02X", v);
        return std::string(buf);
    }
};

class UiSpi2Shared0Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x65) {}
};

class UiSpi2Shared1Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x66) {}
};

class UiSpi2Shared2Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x67) {}
};

class UiSpi2Shared3Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x68) {}
};

class UiSpi2Shared4Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x69) {}
};

class UiSpi2Shared5Register : public UiSpi2SharedRegister {
public:
    UiSpi2Shared0Register() : UiSpi2SharedRegister(0x6A) {}
};

class UiIntOisRegister : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x6F;

    // Setters
    void int2_drdy_ois(bool v)     { set_bit(7, v, raw_); }
    void drdy_mask_ois(bool v)     { set_bit(6, v, raw_); }
    void st_ois_clampdis(bool v)   { set_bit(3, v, raw_); }

    // Getters
    bool int2_drdy_ois()    const  { return get_bit(7, raw_); }
    bool drdy_mask_ois()    const  { return get_bit(6, raw_); }
    bool st_ois_clampdis()  const  { return get_bit(3, raw_); }

    void set_raw(uint8_t raw)      { raw_ = raw; }
    uint8_t get_raw()        const { return raw_; }

    // Logging et JSON
    void log() const;
    std::string to_json() const;

private:
    inline static const char* TAG = "LSM6DSV16X_UI_INT_OIS";
    uint8_t raw_ = 0;
};

class UiCtrl1OisRegister : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x70;

    // Setters
    void sim_ois(bool v)      { set_bit(5, v, raw_); } // Bit 5
    void ois_xl_en(bool v)    { set_bit(3, v, raw_); } // Bit 3
    void ois_g_en(bool v)     { set_bit(2, v, raw_); } // Bit 2
    void spi2_read_en(bool v) { set_bit(0, v, raw_); } // Bit 0

    // Getters
    bool sim_ois()      const { return get_bit(5, raw_); }
    bool ois_xl_en()    const { return get_bit(3, raw_); }
    bool ois_g_en()     const { return get_bit(2, raw_); }
    bool spi2_read_en() const { return get_bit(0, raw_); }

    void set_raw(uint8_t raw)   { raw_ = raw; }
    uint8_t get_raw() const     { return raw_; }

    void log() const;
    std::string to_json() const;

private:
    inline static const char* TAG = "LSM6DSV16X_UI_CTRL1_OIS";
    uint8_t raw_ = 0;
};

class UiCtrl2OisRegister : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x71;

    // Sélecteur du filtre passe-bas digital LPF1
    enum class Lpf1GOisBw : uint8_t {
        HZ_293 = 0b00,
        HZ_217 = 0b01,
        HZ_158 = 0b10,
        HZ_476 = 0b11
    };

    // Sélection du full-scale Gyro OIS
    enum class FsGOis : uint8_t {
        DPS_125   = 0b000,
        DPS_250   = 0b001,
        DPS_500   = 0b010,
        DPS_1000  = 0b011,
        DPS_2000  = 0b100,
        RESERVED_1= 0b101,
        RESERVED_2= 0b110,
        RESERVED_3= 0b111
    };

    // Setters
    void lpf1_g_ois_bw(Lpf1GOisBw v) { set_bits(raw_, 5, 2, static_cast<uint8_t>(v)); }
    void fs_g_ois(FsGOis v)          { set_bits(raw_, 0, 3, static_cast<uint8_t>(v)); }

    // Getters
    Lpf1GOisBw lpf1_g_ois_bw() const { return static_cast<Lpf1GOisBw>(get_bits(raw_, 5, 2)); }
    FsGOis fs_g_ois() const          { return static_cast<FsGOis>(get_bits(raw_, 0, 3)); }

    void set_raw(uint8_t raw)   { raw_ = raw; }
    uint8_t get_raw() const     { return raw_; }

    void log() const;
    std::string to_json() const;

    // Optionnel : to_string helpers
    static const char* to_string(Lpf1GOisBw v);
    static const char* to_string(FsGOis v);

private:
    inline static const char* TAG = "LSM6DSV16X_UI_CTRL2_OIS";
    uint8_t raw_ = 0;
};

class UiCtrl3OisRegister : protected RegisterBase
{
public:
    static constexpr uint8_t reg_addr = 0x72;

    // Enum bande passante LPF pour accéléromètre OIS
    enum class LpfXlOisBw : uint8_t
    {
        HZ_749  = 0b000,
        HZ_539  = 0b001,
        HZ_342  = 0b010,
        HZ_162  = 0b011,
        HZ_78_5 = 0b100,
        HZ_38_6 = 0b101,
        HZ_19_3 = 0b110,
        HZ_9_8  = 0b111
    };

    // Enum full-scale OIS accel
    enum class FsXlOis : uint8_t
    {
        G2  = 0b00,
        G4  = 0b01,
        G8  = 0b10,
        G16 = 0b11
    };

    // Setters
    void lpf_xl_ois_bw(LpfXlOisBw v) { set_bits(raw_, 5, 3, static_cast<uint8_t>(v)); }
    void fs_xl_ois(FsXlOis v)        { set_bits(raw_, 1, 2, static_cast<uint8_t>(v)); }

    // Getters
    LpfXlOisBw lpf_xl_ois_bw() const { return static_cast<LpfXlOisBw>(get_bits(raw_, 5, 3)); }
    FsXlOis fs_xl_ois() const        { return static_cast<FsXlOis>(get_bits(raw_, 1, 2)); }

    void set_raw(uint8_t raw)   { raw_ = raw; }
    uint8_t get_raw() const     { return raw_; }

    void log() const;
    std::string to_json() const;

    // Optionnel
    static const char* to_string(LpfXlOisBw v);
    static const char* to_string(FsXlOis v);

private:
    inline static const char* TAG = "LSM6DSV16X_UI_CTRL3_OIS";
    uint8_t raw_ = 0;
};


} // namespace lsm6dsv16x