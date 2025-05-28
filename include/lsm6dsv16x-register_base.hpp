#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

namespace lsm6dsv16x
{

class RegisterBase
{
protected:
// --------- Pour un raw uint32_t membre de la classe ---------
    template <int IDX>
    uint8_t get_octet() const { return (raw_ >> (8 * IDX)) & 0xFF; }

    template <int IDX>
    void set_octet(uint8_t v) { raw_ = (raw_ & ~(0xFF << (8 * IDX))) | (uint32_t(v) << (8 * IDX)); }

    template <int OCTET_IDX, int BIT_IDX>
    void set_flag(bool value) {
        uint8_t tmp = get_octet<OCTET_IDX>();
        set_bit(BIT_IDX, value, tmp);
        set_octet<OCTET_IDX>(tmp);
    }

    template <int OCTET_IDX, int BIT_IDX>
    bool get_flag() const {
        return get_bit(BIT_IDX, get_octet<OCTET_IDX>());
    }

    template <int OCTET_IDX, int POS, int SIZE, typename EnumT>
    void set_field(EnumT value) {
        uint8_t tmp = get_octet<OCTET_IDX>();
        set_bits(tmp, POS, SIZE, static_cast<uint8_t>(value));
        set_octet<OCTET_IDX>(tmp);
    }

    template <int OCTET_IDX, int POS, int SIZE, typename EnumT>
    EnumT get_field() const {
        return static_cast<EnumT>(get_bits(get_octet<OCTET_IDX>(), POS, SIZE));
    }

    // ------------- Helpers génériques -------------
    inline void set_bit(uint8_t bit, bool v, uint8_t& raw) const
    {
        if (v) raw |= (1 << bit);
        else   raw &= ~(1 << bit);
    }

    inline bool get_bit(uint8_t bit, uint8_t raw) const
    {
        return (raw >> bit) & 0x1;
    }
    
    // Ecriture générique sur N bits à partir d'une position
    inline void set_bits(uint8_t &reg, uint8_t pos, uint8_t size, uint8_t val)
    {
        reg = (reg & ~(((1u << size) - 1u) << pos)) | ((val & ((1u << size) - 1u)) << pos);
    }

    // Lecture générique sur N bits à partir d'une position
    inline uint8_t get_bits(uint8_t reg, uint8_t pos, uint8_t size)
    {
        return (reg >> pos) & ((1u << size) - 1u);
    }
};

    class OutData16Register
    {
    public:
        explicit OutData16Register(uint8_t reg_addr) : reg_addr_(reg_addr) {}

        // Register RAW access
        void set_raw(uint16_t raw) { raw_ = raw; }
        uint16_t get_raw() const { return raw_; }

        int16_t data() const { return static_cast<int16_t>(raw_); }

        uint8_t reg_addr() const { return reg_addr_; }

        void log() const
        {
            ESP_LOGI("LSM6DSV16X_DATA", "raw=0x%02X, data=%d", raw_, data());
        }
        std::string to_json() const
        {
            return std::string("{") + "\"data\":" + std::to_string(data()) + "}";
        }

    protected:
        uint16_t raw_ = 0;
        uint8_t reg_addr_ = 0;
    };
} // namespace lsm6dsv16x
