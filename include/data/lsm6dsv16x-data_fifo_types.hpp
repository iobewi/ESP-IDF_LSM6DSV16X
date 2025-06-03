#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    class FifoDataOutTagRegister : public RegisterBase8<FifoDataOutTagRegister>
    {
    public:
        static constexpr uint8_t reg_addr = 0x78;

        FifoDataOutTagRegister() = default;
        explicit FifoDataOutTagRegister(uint8_t raw) : raw_(raw) {}

        enum class TagSensor : uint8_t
        {
            EMPTY = 0x00,            // FIFO empty
            GYRO_NC = 0x01,          // Gyroscope NC
            ACCEL_NC = 0x02,         // Accelerometer NC
            TEMPERATURE = 0x03,      // Temperature
            TIMESTAMP = 0x04,        // Timestamp
            CFG_CHANGE = 0x05,       // CFG_Change
            ACCEL_NC_T2 = 0x06,      // Accelerometer NC_T_2
            ACCEL_NC_T1 = 0x07,      // Accelerometer NC_T_1
            ACCEL_2C = 0x08,         // Accelerometer 2xC
            ACCEL_3C = 0x09,         // Accelerometer 3xC
            GYRO_NC_T2 = 0x0A,       // Gyroscope NC_T_2
            GYRO_NC_T1 = 0x0B,       // Gyroscope NC_T_1
            GYRO_2C = 0x0C,          // Gyroscope 2xC
            GYRO_3C = 0x0D,          // Gyroscope 3xC
            SHUB_SLAVE0 = 0x0E,      // Sensor hub slave 0
            SHUB_SLAVE1 = 0x0F,      // Sensor hub slave 1
            SHUB_SLAVE2 = 0x10,      // Sensor hub slave 2
            SHUB_SLAVE3 = 0x11,      // Sensor hub slave 3
            STEP_COUNTER = 0x12,     // Step counter
            SFLP_ROT_VEC = 0x13,     // SFLP game rotation vector
            SFLP_GYRO_BIAS = 0x16,   // SFLP gyroscope bias
            SFLP_GRAVITY_VEC = 0x17, // SFLP gravity vector
            SHUB_NACK = 0x19,        // Sensor hub nack
            MLC_RESULT = 0x1A,       // MLC result
            MLC_FILTER = 0x1B,       // MLC filter
            MLC_FEATURE = 0x1C,      // MLC feature
            ACCEL_DUALC = 0x1D,      // Accelerometer dualC
            EIS_GYRO = 0x1E,         // Enhanced EIS gyroscope
            UNKNOWN = 0xFF
        };

        // Champs utiles
        TagSensor tag_sensor() const { return get_field<0, 0, 5, TagSensor>(); }
        uint8_t tag_cnt() const { return get_field<0, 5, 2, uint8_t>(); }

        void set_raw(uint8_t raw) { raw_ = raw; }
        uint8_t get_raw() const { return raw_; }

        // Décodage du tag sensor sous forme de string
        static const char *to_string(TagSensor tag)
        {
            switch (tag)
            {
            case TagSensor::EMPTY:             return "FIFO empty";
            case TagSensor::GYRO_NC:           return "Gyroscope NC";
            case TagSensor::ACCEL_NC:          return "Accelerometer NC";
            case TagSensor::TEMPERATURE:       return "Temperature";
            case TagSensor::TIMESTAMP:         return "Timestamp";
            case TagSensor::CFG_CHANGE:        return "CFG_Change";
            case TagSensor::ACCEL_NC_T2:       return "Accelerometer NC_T_2";
            case TagSensor::ACCEL_NC_T1:       return "Accelerometer NC_T_1";
            case TagSensor::ACCEL_2C:          return "Accelerometer 2xC";
            case TagSensor::ACCEL_3C:          return "Accelerometer 3xC";
            case TagSensor::GYRO_NC_T2:        return "Gyroscope NC_T_2";
            case TagSensor::GYRO_NC_T1:        return "Gyroscope NC_T_1";
            case TagSensor::GYRO_2C:           return "Gyroscope 2xC";
            case TagSensor::GYRO_3C:           return "Gyroscope 3xC";
            case TagSensor::SHUB_SLAVE0:       return "Sensor hub slave 0";
            case TagSensor::SHUB_SLAVE1:       return "Sensor hub slave 1";
            case TagSensor::SHUB_SLAVE2:       return "Sensor hub slave 2";
            case TagSensor::SHUB_SLAVE3:       return "Sensor hub slave 3";
            case TagSensor::STEP_COUNTER:      return "Step counter";
            case TagSensor::SFLP_ROT_VEC:      return "SFLP game rotation vector";
            case TagSensor::SFLP_GYRO_BIAS:    return "SFLP gyroscope bias";
            case TagSensor::SFLP_GRAVITY_VEC:  return "SFLP gravity vector";
            case TagSensor::SHUB_NACK:         return "Sensor hub nack";
            case TagSensor::MLC_RESULT:        return "MLC result";
            case TagSensor::MLC_FILTER:        return "MLC filter";
            case TagSensor::MLC_FEATURE:       return "MLC feature";
            case TagSensor::ACCEL_DUALC:       return "Accelerometer dualC";
            case TagSensor::EIS_GYRO:          return "Enhanced EIS gyroscope";
            case TagSensor::UNKNOWN:           return "Unknown";
            default:                           return "Unrecognized";
            }
        }

        // Pour affichage/debug
        void log() const
        {
            ESP_LOGI(TAG, "raw=0x%02X, tag_sensor=0x%02X (%s), tag_cnt=%u",
                     raw_, tag_sensor(), to_string(tag_sensor()), tag_cnt());
        }
        std::string to_json() const
        {
            return std::string("{") +
                   "\"tag_sensor\": \"" + to_string(tag_sensor()) + "\"," +
                   "\"tag_cnt\": " + std::to_string(tag_cnt()) +
                   "}";
        }

    protected:
        uint8_t raw_ = 0;

    private:
        inline static const char *TAG = "LSM6DSV16X_FIFO_TAG";
    };

    // --- FIFO_DATA_OUT_X
    struct FifoOutXRegister : public OutData16Register
    {
        FifoOutXRegister() : OutData16Register(0x79) {}
        inline static const char *TAG = "LSM6DSV16X_FIFO_OUT_X";
        void log() const override
        {
            ESP_LOGI(TAG, "FIFO_OUT_X = %d", data());
        }
    };

    // --- FIFO_DATA_OUT_Y
    struct FifoOutYRegister : public OutData16Register
    {
        FifoOutYRegister() : OutData16Register(0x7B) {}
        inline static const char *TAG = "LSM6DSV16X_FIFO_OUT_Y";
        void log() const override
        {
            ESP_LOGI(TAG, "FIFO_OUT_Y = %d", data());
        }
    };
    // --- FIFO_DATA_OUT_Z
    struct FifoOutZRegister : public OutData16Register
    {
        FifoOutZRegister() : OutData16Register(0x7D) {}
        inline static const char *TAG = "LSM6DSV16X_FIFO_OUT_Z";
        void log() const override
        {
            ESP_LOGI(TAG, "FIFO_OUT_Z = %d", data());
        }
    };
}
