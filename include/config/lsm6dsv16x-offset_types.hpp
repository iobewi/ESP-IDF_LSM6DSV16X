#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    class OffsetUsrRegister : public RegisterBase<OffsetUsrRegister>
    {
    public:
        // Constructeur : adresse du registre
        explicit OffsetUsrRegister(uint8_t reg_addr) : reg_addr_(reg_addr) {}

        static constexpr int8_t MIN = -127;
        static constexpr int8_t MAX = 127;

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        void set_offset(int8_t val) { raw_ = static_cast<uint8_t>(val); }
        int8_t get_offset() const { return static_cast<int8_t>(raw_); }

        uint8_t reg_addr() const { return reg_addr_; }

        virtual void log() const
        {
            ESP_LOGI("LSM6DSV16X_OFFSET", "raw=0x%02X, offset=%d", raw_, get_offset());
        }
        virtual std::string to_json() const
        {
            return std::string("{") + "\"offset\":" + std::to_string(get_offset()) + "}";
        }

    protected:
        uint8_t raw_ = 0;
        uint8_t reg_addr_ = 0;
    };

    /// Types spécialisés
    struct XOfsUsrRegister : public OffsetUsrRegister
    {
        XOfsUsrRegister() : OffsetUsrRegister(0x73) {}
        inline static const char *TAG = "LSM6DSV16X_X_OFS_USR";
        void log() const override
        {
            ESP_LOGI(TAG, "raw=0x%02X, offset=%d", raw_, get_offset());
        }
    };
    struct YOfsUsrRegister : public OffsetUsrRegister
    {
        YOfsUsrRegister() : OffsetUsrRegister(0x74) {}
        inline static const char *TAG = "LSM6DSV16X_Y_OFS_USR";
        void log() const override
        {
            ESP_LOGI(TAG, "raw=0x%02X, offset=%d", raw_, get_offset());
        }
    };
    struct ZOfsUsrRegister : public OffsetUsrRegister
    {
        ZOfsUsrRegister() : OffsetUsrRegister(0x75) {}
        inline static const char *TAG = "LSM6DSV16X_Z_OFS_USR";
        void log() const override
        {
            ESP_LOGI(TAG, "raw=0x%02X, offset=%d", raw_, get_offset());
        }
    };

} // namespace lsm6dsv16x
