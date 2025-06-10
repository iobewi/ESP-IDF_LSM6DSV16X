#include "ctrl/lsm6dsv16x-ctrl.hpp"
#define RETURN_IF_ERROR(x)                       \
    do                                           \
    {                                            \
        esp_err_t __err_rc = (x);                \
        if (__err_rc != ESP_OK)                  \
        {                                        \
            ESP_LOGE("RETURN_IF_ERROR",          \
                     "%s failed at %s:%d → %s",  \
                     #x, __FILE__, __LINE__,     \
                     esp_err_to_name(__err_rc)); \
            return __err_rc;                     \
        }                                        \
    } while (0)

namespace lsm6dsv16x
{

} // namespace lsm6dsv16x
