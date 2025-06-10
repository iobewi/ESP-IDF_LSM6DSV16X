#pragma once

#include <cstdint>
#include <functional>
#include <optional>

#include "esp_err.h"
#include "esp_log.h"

#include "I2CDevices.hpp"

// Champ enum ou champ entier sur plusieurs bits
#define DEFINE_FIELD(REG, FIELD, TYPE)                             \
    esp_err_t FIELD(TYPE &out)                                     \
    {                                                              \
        return get_field<REG, TYPE>(                               \
            static_cast<TYPE (REG::*)() const>(&REG::FIELD), out); \
    }                                                              \
    esp_err_t FIELD(TYPE val)                                      \
    {                                                              \
        return set_field<REG, TYPE>(                               \
            static_cast<void (REG::*)(TYPE)>(&REG::FIELD), val);   \
    }

#define DEFINE_DATA(REG, FIELD, TYPE)                  \
    esp_err_t FIELD(TYPE &out)                         \
    {                                                  \
        return get_field<REG, TYPE>(&REG::FIELD, out); \
    }

#define DEFINE_REGOUT(REG)        \
    void log_##REG()              \
    {                             \
        REG reg;                  \
        if (get(reg) == ESP_OK)   \
            reg.log();            \
    }                             \
    std::string to_json_##REG()   \
    {                             \
        REG reg;                  \
        if (get(reg) == ESP_OK)   \
            return reg.to_json(); \
        return "{}";              \
    }

namespace lsm6dsv16x
{
    /**
     * @class INTERFACE
     * @brief Interface bas-niveau pour accéder aux registres du LSM6DSV16X via I2C.
     */
    class INTERFACE
    {
    public:
        explicit INTERFACE(I2CDevices &i2c_device) : i2c(i2c_device) {}

        template <typename RegT>
        esp_err_t get(RegT &reg)
        {
            using RawT = decltype(reg.get_raw());
            RawT raw_val = 0;
            RETURN_IF_ERROR(read_uX(RegT::reg_addr, raw_val));
            reg.set_raw(raw_val);
            return ESP_OK;
        }

        template <typename RegT>
        esp_err_t set(const RegT &reg)
        {
            return write_uX(RegT::reg_addr, reg.get_raw());
        }

        template <typename RegT>
        esp_err_t configure(std::function<void(RegT &)> f)
        {
            RegT reg;
            using RawT = decltype(reg.get_raw());

            RawT raw_val = 0;
            RETURN_IF_ERROR(read_uX(RegT::reg_addr, raw_val));
            reg.set_raw(raw_val);

            f(reg);

            return write_uX(RegT::reg_addr, reg.get_raw());
        }

        template <typename RegT, typename FieldT>
        esp_err_t get_field(FieldT (RegT::*getter)() const, FieldT &out)
        {
            RegT reg;
            esp_err_t err = get(reg);
            if (err != ESP_OK)
            {
                ESP_LOGE(TAG, "Failed to read register 0x%02X", RegT::reg_addr);
                return err;
            }
            out = (reg.*getter)();
            return ESP_OK;
        }

        template <typename RegT, typename FieldT>
        esp_err_t set_field(void (RegT::*setter)(FieldT), FieldT val)
        {
            return configure<RegT>([=](auto &reg)
                                   { (reg.*setter)(val); });
        }

        template <typename RegT, typename FieldT>
        esp_err_t write_field(void (RegT::*setter)(FieldT), FieldT value)
        {
            RegT reg;
            RETURN_IF_ERROR(get(reg));
            (reg.*setter)(value);
            return set(reg);
        }

    protected:
        I2CDevices &i2c;

    private:
        inline static const char *TAG = "LSM6DSV16X-INTERFACE";

        // Lecture générique
        template <typename T>
        esp_err_t read_uX(uint8_t reg, T &out)
        {
            static_assert(sizeof(T) == 1 || sizeof(T) == 2 || sizeof(T) == 4, "Unsupported size");
            uint8_t buffer[sizeof(T)] = {};
            esp_err_t err = read_register(reg, buffer, sizeof(T));
            if (err != ESP_OK)
                return err;

            // Little endian
            out = 0;
            for (size_t i = 0; i < sizeof(T); ++i)
                out |= static_cast<T>(buffer[i]) << (8 * i);

            return ESP_OK;
        }

        // Écriture générique
        template <typename T>
        esp_err_t write_uX(uint8_t reg, T value)
        {
            static_assert(sizeof(T) == 1 || sizeof(T) == 2 || sizeof(T) == 4, "Unsupported size");
            uint8_t buffer[sizeof(T)] = {};
            for (size_t i = 0; i < sizeof(T); ++i)
                buffer[i] = (value >> (8 * i)) & 0xFF;

            return write_register(reg, buffer, sizeof(T));
        }

        esp_err_t read_register(uint8_t reg, uint8_t *data, size_t len)
        {
            esp_err_t err = ESP_FAIL;
            const int max_attempts = 3;

            for (int attempt = 0; attempt < max_attempts; ++attempt)
            {
                err = i2c.read(reg, data, len);
                if (err == ESP_OK)
                {
                    // ESP_LOGI(TAG, "I2C READ -> Reg: 0x%02X | Len: %d", reg, static_cast<int>(len));
                    // ESP_LOG_BUFFER_HEX_LEVEL(TAG, data, len, ESP_LOG_INFO);
                    return ESP_OK;
                }
                vTaskDelay(pdMS_TO_TICKS(10));
            }

            ESP_LOGW(TAG, "Read failed at reg 0x%02X after %d attempts (err=0x%x)", reg, max_attempts, err);
            return err;
        }

        esp_err_t write_register(uint8_t reg, const uint8_t *data, size_t len)
        {
            esp_err_t err = ESP_FAIL;
            err = i2c.write(reg, data, len);
            if (err == ESP_OK)
            {
                // ESP_LOGI(TAG, "I2C WRITE -> Reg: 0x%02X | Len: %d", reg, static_cast<int>(len));
                // ESP_LOG_BUFFER_HEX_LEVEL(TAG, data, len, ESP_LOG_INFO);
                return ESP_OK;
            }

            ESP_LOGW(TAG, "Write failed at reg 0x%02X (err=0x%x)", reg, err);
            return err;
        }
    };

} // namespace lsm6dsv16x
