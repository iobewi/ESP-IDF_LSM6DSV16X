#pragma once
#include "config/lsm6dsv16x-config_types.hpp"
#include "esp_err.h"

namespace lsm6dsv16x
{
    esp_err_t load_config_from_kconfig();
}
