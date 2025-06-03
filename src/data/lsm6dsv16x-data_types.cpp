#include "data/lsm6dsv16x-data_types.hpp"

#include "esp_log.h"

namespace lsm6dsv16x
{

        void InternalFreqFineRegister::log() const
        {
            ESP_LOGI(TAG, " data = %d (%.2f%%)", percent());
        }

        std::string InternalFreqFineRegister::to_json() const
        {
            return std::string("{") + "\"data\":" + std::to_string(percent()) +  "}";
        }

        void TimestampRegister::log() const
        {
            ESP_LOGI(TAG, "TimeStamp = %.2fus", timestamp_us());
        }

        std::string TimestampRegister::to_json() const
        {
            return std::string("{") + "\"data\":" + std::to_string(timestamp_us()) + "}";

        }

}
