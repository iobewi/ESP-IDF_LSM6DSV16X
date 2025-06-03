#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"
#define RETURN_IF_ERROR(x)                       \
    do                                           \
    {                                            \
        esp_err_t __err_rc = (x);                \
        if (__err_rc != ESP_OK)                  \
        {                                        \
            ESP_LOGE("RETURN_IF_ERROR",          \
                     "%s failed at %s:%d → %s",  \
                     #x, __FILE__, __LINE__,     \
                     esp_err_to_name(__err_rc)); \
            return __err_rc;                     \
        }                                        \
    } while (0)

#define DEFINE_GENERIC_REGISTER_ADDR(NAME, RAWTYPE, ADDR)   \
    class NAME : public RegisterBase<NAME, RAWTYPE> \
    {                                               \
        friend class RegisterBase<NAME, RAWTYPE>;   \
                                                    \
    protected:                                      \
        RAWTYPE raw_ = 0;                           \
                                                    \
    public:                                         \
        static constexpr uint8_t reg_addr = ADDR;   \
        NAME() = default;                           \
        explicit NAME(RAWTYPE raw) : raw_(raw) {}   \
        void set_raw(RAWTYPE raw) { raw_ = raw; }   \
        RAWTYPE get_raw() const { return raw_; }    \
        void log() const;                           \
        std::string to_json() const;

#define DEFINE_GENERIC_REGISTER_DATA(NAME, ADDR)                    \
class NAME : public RegisterBase<NAME, uint16_t>                    \
{                                                                   \
    friend class RegisterBase<NAME, uint16_t>;                      \
protected:                                                          \
    uint16_t raw_ = 0;                                              \
public:                                                             \
    static constexpr uint8_t reg_addr = ADDR;                       \
    NAME() = default;                                               \
    explicit NAME(uint16_t raw) : raw_(raw) {}                      \
    void set_raw(uint16_t raw) { raw_ = raw; }                      \
    uint16_t get_raw() const { return raw_; }                       \
    int16_t data() const { return static_cast<int16_t>(raw_); }     \
    void log() const                                                \
    { ESP_LOGI(TAG, "raw=0x%02X, data=%d", raw_, data()); }         \
    std::string to_json() const                                     \
    { return std::string("{") + "\"data\":" + std::to_string(data()) + "}"; }

#define END_REGISTER \
    }                \
    ;

namespace lsm6dsv16x
{

    template <typename Derived, typename RawT>
    class RegisterBase
    {
    protected:
        RawT &raw()
        {
            return static_cast<Derived *>(this)->raw_;
        }

        const RawT &raw() const
        {
            return static_cast<const Derived *>(this)->raw_;
        }

        // Exemple : accès à un octet donné
        template <int IDX>
        uint8_t get_octet() const
        {
            return (raw() >> (8 * IDX)) & 0xFF;
        }

        template <int IDX>
        void set_octet(uint8_t v)
        {
            raw() = (raw() & ~(RawT(0xFF) << (8 * IDX))) | (RawT(v) << (8 * IDX));
        }

        template <int OCTET_IDX, int BIT_IDX>
        void set_flag(bool value)
        {
            uint8_t tmp = get_octet<OCTET_IDX>();
            set_bit(BIT_IDX, value, tmp);
            set_octet<OCTET_IDX>(tmp);
        }

        template <int OCTET_IDX, int BIT_IDX>
        bool get_flag() const
        {
            return get_bit(BIT_IDX, get_octet<OCTET_IDX>());
        }

        template <int OCTET_IDX, int POS, int SIZE, typename EnumT>
        void set_field(EnumT value)
        {
            uint8_t tmp = get_octet<OCTET_IDX>();
            set_bits(tmp, POS, SIZE, static_cast<uint8_t>(value));
            set_octet<OCTET_IDX>(tmp);
        }

        template <int OCTET_IDX, int POS, int SIZE, typename EnumT>
        EnumT get_field() const
        {
            return static_cast<EnumT>(get_bits(get_octet<OCTET_IDX>(), POS, SIZE));
        }

        // ------------- Helpers génériques -------------
        inline void set_bit(uint8_t bit, bool v, uint8_t &raw) const
        {
            if (v)
                raw |= (1 << bit);
            else
                raw &= ~(1 << bit);
        }

        inline bool get_bit(uint8_t bit, uint8_t raw) const
        {
            return (raw >> bit) & 0x1;
        }

        // Ecriture générique sur N bits à partir d'une position
        inline void set_bits(uint8_t &reg, uint8_t pos, uint8_t size, uint8_t val) const
        {
            reg = (reg & ~(((1u << size) - 1u) << pos)) | ((val & ((1u << size) - 1u)) << pos);
        }

        // Lecture générique sur N bits à partir d'une position
        inline uint8_t get_bits(uint8_t reg, uint8_t pos, uint8_t size) const
        {
            return (reg >> pos) & ((1u << size) - 1u);
        }
    };

    template <typename Derived>
    using RegisterBase8 = RegisterBase<Derived, uint8_t>;

    template <typename Derived>
    using RegisterBase16 = RegisterBase<Derived, uint16_t>;

    template <typename Derived>
    using RegisterBase32 = RegisterBase<Derived, uint32_t>;

} // namespace lsm6dsv16x