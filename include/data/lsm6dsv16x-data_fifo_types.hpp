#pragma once

#include <cstdint>
#include <string>
#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
    class FifoDataOutTagRegister : protected RegisterBase
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

        // Décodage du tag sensor sous forme de string
        static const char *to_string(uint8_t tag)
        {
            switch (tag)
            {
            case 0x00:
                return "FIFO empty";
            case 0x01:
                return "Gyroscope NC";
            case 0x02:
                return "Accelerometer NC";
            case 0x03:
                return "Temperature";
            case 0x04:
                return "Timestamp";
            case 0x05:
                return "CFG_Change";
            case 0x06:
                return "Accelerometer NC_T_2";
            case 0x07:
                return "Accelerometer NC_T_1";
            case 0x08:
                return "Accelerometer 2xC";
            case 0x09:
                return "Accelerometer 3xC";
            case 0x0A:
                return "Gyroscope NC_T_2";
            case 0x0B:
                return "Gyroscope NC_T_1";
            case 0x0C:
                return "Gyroscope 2xC";
            case 0x0D:
                return "Gyroscope 3xC";
            case 0x0E:
                return "Sensor hub slave 0";
            case 0x0F:
                return "Sensor hub slave 1";
            case 0x10:
                return "Sensor hub slave 2";
            case 0x11:
                return "Sensor hub slave 3";
            case 0x12:
                return "Step counter";
            case 0x13:
                return "SFLP game rotation vector";
            case 0x16:
                return "SFLP gyroscope bias";
            case 0x17:
                return "SFLP gravity vector";
            case 0x19:
                return "Sensor hub nack";
            case 0x1A:
                return "MLC result";
            case 0x1B:
                return "MLC filter";
            case 0x1C:
                return "MLC feature";
            case 0x1D:
                return "Accelerometer dualC";
            case 0x1E:
                return "Enhanced EIS gyroscope";
            default:
                return "Unknown";
            }
        }

    private:
        inline static const char *TAG = "LSM6DSV16X_FIFO_TAG";
        uint8_t raw_ = 0;
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
