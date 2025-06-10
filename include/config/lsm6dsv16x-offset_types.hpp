#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    DEFINE_GENERIC_REGISTER_ADDR(XOfsUsrRegister, uint8_t, 0x73)
            // Setter
            void offset_x(uint8_t v) { raw_ = v; }
            // Getter
            uint8_t offset_x() const { return raw_; }
        private:
            inline static const char *TAG = "LSM6DSV16X_X_OFS_USR";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(YOfsUsrRegister, uint8_t, 0x74)
            // Setter
            void offset_y(uint8_t v) { raw_ = v; }
            // Getter
            uint8_t offset_y() const { return raw_; }
        private:
            inline static const char *TAG = "LSM6DSV16X_Y_OFS_USR";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(ZOfsUsrRegister, uint8_t, 0x75)
            // Setter
            void offset_z(uint8_t v) { raw_ = v; }
            // Getter
            uint8_t offset_z() const { return raw_; }
        private:
            inline static const char *TAG = "LSM6DSV16X_Z_OFS_USR";
    END_REGISTER
    
} // namespace lsm6dsv16x
