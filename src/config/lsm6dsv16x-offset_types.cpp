#include "config/lsm6dsv16x-offset_types.hpp"

namespace lsm6dsv16x
{    
    void XOfsUsrRegister::log() const
    {
        ESP_LOGI(TAG, "offset_x=%u", raw_);
    }

    std::string XOfsUsrRegister::to_json() const
    {
        return std::string("{") + "\"offset_x\":" + std::to_string(raw_) + "}";
    }

    void YOfsUsrRegister::log() const
    {
        ESP_LOGI(TAG, "offset_y=%u", raw_);
    }

    std::string YOfsUsrRegister::to_json() const
    {
        return std::string("{") + "\"offset_y\":" + std::to_string(raw_) + "}";
    }

    void ZOfsUsrRegister::log() const
    {
        ESP_LOGI(TAG, "offset_z=%u", raw_);
    }

    std::string ZOfsUsrRegister::to_json() const
    {
        return std::string("{") + "\"offset_z\":" + std::to_string(raw_) + "}";
    }

} // namespace lsm6dsv16x
