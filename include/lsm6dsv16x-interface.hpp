#pragma once

#include <cstdint>

#include "esp_err.h"
#include "esp_log.h"

#include "I2CDevices.hpp"

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

        esp_err_t read_register(uint8_t reg, uint8_t *data, size_t len)
        {
            esp_err_t err = ESP_FAIL;
            const int max_attempts = 3;

            for (int attempt = 0; attempt < max_attempts; ++attempt)
            {
                err = i2c.read(reg, data, len);
                if (err == ESP_OK)
                {
                    //ESP_LOGI(TAG, "I2C READ -> Reg: 0x%02X | Len: %d", reg, static_cast<int>(len));
                    //ESP_LOG_BUFFER_HEX_LEVEL(TAG, data, len, ESP_LOG_INFO);
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
                //ESP_LOGI(TAG, "I2C WRITE -> Reg: 0x%02X | Len: %d", reg, static_cast<int>(len));
                //ESP_LOG_BUFFER_HEX_LEVEL(TAG, data, len, ESP_LOG_INFO);
                return ESP_OK;
            }

            ESP_LOGW(TAG, "Write failed at reg 0x%02X (err=0x%x)", reg, err);
            return err;
        }

        esp_err_t read_u8(uint8_t reg, uint8_t &out)
        {
            return read_register(reg, &out, 1);
        }

        esp_err_t write_u8(uint8_t reg_addr, uint8_t value)
        {
            uint8_t buffer[2];
            buffer[0] = reg_addr;                       // adresse du registre à écrire
            buffer[1] = value;
            return write_register(buffer[0], &buffer[1], 1); // i2c_.write(reg, data, len)
        }

    protected:
        I2CDevices &i2c;

    private:
        inline static const char *TAG = "LSM6DSV16X-INTERFACE";
    };

} // namespace lsm6dsv16x
