#pragma once

#include <cstdint>
#include <string>
#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    struct InternalFreqFineRegister : protected lsm6dsv16x::RegisterBase
{
    static constexpr uint8_t reg_addr = 0x4F;

    InternalFreqFineRegister() = default;
    explicit InternalFreqFineRegister(uint8_t raw) : raw_(raw) {}

    // Les 8 bits : FREQ_FINE[7:0], signed (two's complement), step = 0.13%
    int8_t freq_fine() const { return static_cast<int8_t>(raw_); }

    void set_raw(uint8_t raw) { raw_ = raw; }
    uint8_t get_raw() const { return raw_; }

    // Calcul du pourcentage (en float, si besoin)
    float percent() const { return freq_fine() * 0.13f; }

    void log() const
    {
        ESP_LOGI(TAG, "INTERNAL_FREQ_FINE = 0x%02X | FREQ_FINE = %d (%.2f%%)",
                 raw_, freq_fine(), percent());
    }

    std::string to_json() const
    {
        return std::string("{") +
               "\"freq_fine\":" + std::to_string(freq_fine()) + "," +
               "\"percent\":" + std::to_string(percent()) +
               "}";
    }

private:
    inline static const char *TAG = "LSM6DSV16X_INTERNAL_FREQ_FINE";
    uint8_t raw_ = 0;
};


    /// Types spécialisés
    struct OutTempRegister : public OutData16Register
    {
        OutTempRegister() : OutData16Register(0x20) {}
        inline static const char *TAG = "LSM6DSV16X_DATA_TEMPERATURE";
        void log() const override
        {
            ESP_LOGI(TAG, "temp_out = %d", raw_, data());
        }
    };

    struct OutXGRegister : public OutData16Register
    {
        OutXGRegister() : OutData16Register(0x22) {}
        inline static const char *TAG = "LSM6DSV16X_OUTX_G";
        void log() const override
        {
            ESP_LOGI(TAG, "GyroX = %d", raw_, data());
        }
    };

    // --- GYRO Y
    struct OutYGRegister : public OutData16Register
    {
        OutYGRegister() : OutData16Register(0x24) {}
        inline static const char *TAG = "LSM6DSV16X_OUTY_G";
        void log() const override
        {
            ESP_LOGI(TAG, "Gyro Y = %d", data());
        }
    };

    // --- GYRO Z
    struct OutZGRegister : public OutData16Register
    {
        OutZGRegister() : OutData16Register(0x26) {}
        inline static const char *TAG = "LSM6DSV16X_OUTZ_G";
        void log() const override
        {
            ESP_LOGI(TAG, "Gyro Z = %d", data());
        }
    };

    // --- ACCEL X
    struct OutXARegister : public OutData16Register
    {
        OutXARegister() : OutData16Register(0x28) {}
        inline static const char *TAG = "LSM6DSV16X_OUTX_A";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel X = %d", data());
        }
    };

    // --- ACCEL Y
    struct OutYARegister : public OutData16Register
    {
        OutYARegister() : OutData16Register(0x2A) {}
        inline static const char *TAG = "LSM6DSV16X_OUTY_A";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel Y = %d", data());
        }
    };

    // --- ACCEL Z
    struct OutZARegister : public OutData16Register
    {
        OutZARegister() : OutData16Register(0x2C) {}
        inline static const char *TAG = "LSM6DSV16X_OUTZ_A";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel Z = %d", data());
        }
    };

    // --- UI_OUTX_G_OIS_EIS
    struct OutXGOisEisRegister : public OutData16Register
    {
        OutXGOisEisRegister() : OutData16Register(0x2E) {}
        inline static const char *TAG = "LSM6DSV16X_OUTX_G_OIS_EIS";
        void log() const override
        {
            ESP_LOGI(TAG, "Gyro OIS EIS X = %d", data());
        }
    };

    // --- UI_OUTY_G_OIS_EIS
    struct OutYGOisEisRegister : public OutData16Register
    {
        OutYGOisEisRegister() : OutData16Register(0x30) {}
        inline static const char *TAG = "LSM6DSV16X_OUTY_G_OIS_EIS";
        void log() const override
        {
            ESP_LOGI(TAG, "Gyro OIS EIS Y = %d", data());
        }
    };

    // --- UI_OUTZ_G_OIS_EIS
    struct OutZGOisEisRegister : public OutData16Register
    {
        OutZGOisEisRegister() : OutData16Register(0x32) {}
        inline static const char *TAG = "LSM6DSV16X_OUTZ_G_OIS_EIS";
        void log() const override
        {
            ESP_LOGI(TAG, "Gyro OIS EIS Z = %d", data());
        }
    };

    // --- UI_OUTX_A_OIS_DualC
    struct OutXAOisDualCRegister : public OutData16Register
    {
        OutXAOisDualCRegister() : OutData16Register(0x34) {}
        inline static const char *TAG = "LSM6DSV16X_OUTX_A_OIS_DUALC";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel OIS DualC X = %d", data());
        }
    };

    // --- UI_OUTY_A_OIS_DualC
    struct OutYAOisDualCRegister : public OutData16Register
    {
        OutYAOisDualCRegister() : OutData16Register(0x36) {}
        inline static const char *TAG = "LSM6DSV16X_OUTY_A_OIS_DUALC";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel OIS DualC Y = %d", data());
        }
    };

    // --- UI_OUTZ_A_OIS_DualC
    struct OutZAOisDualCRegister : public OutData16Register
    {
        OutZAOisDualCRegister() : OutData16Register(0x38) {}
        inline static const char *TAG = "LSM6DSV16X_OUTZ_A_OIS_DUALC";
        void log() const override
        {
            ESP_LOGI(TAG, "Accel OIS DualC Z = %d", data());
        }
    };

    // --- AH_QVAR_OUT
    struct AhQvarOutRegister : public OutData16Register
    {
        AhQvarOutRegister() : OutData16Register(0x3A) {}
        inline static const char *TAG = "LSM6DSV16X_AH_QVAR_OUT";
        void log() const override
        {
            ESP_LOGI(TAG, "QVAR OUT = %d", data());
        }
    };

    class TimestampRegister
    {
    public:
        static constexpr uint8_t reg_addr = 0x40; // Adresse du premier octet (TIMESTAMP0)
        static constexpr size_t reg_len = 4;      // 4 octets (TIMESTAMP0-3)

        TimestampRegister() = default;
        explicit TimestampRegister(uint32_t raw) : raw_(raw) {}

        void set_raw(uint32_t raw) { raw_ = raw; }
        uint32_t get_raw() const { return raw_; }

        double timestamp_us() const
        {
            // 1 LSB = 21.75 µs typique
            return raw_ * 21.75;
        }

        void log() const
        {
            ESP_LOGI(TAG, "TimeStamp = %.2fus",
                     timestamp_us());
        }

        std::string to_json() const
        {
            return std::string("{") + "\"data\":" + std::to_string(timestamp_us()) + "}";
        }

    private:
        uint32_t raw_ = 0;
        inline static const char *TAG = "LSM6DSV16X_TIMESTAMP";
    };

}
