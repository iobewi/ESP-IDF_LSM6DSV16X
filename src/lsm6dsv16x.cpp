#include "lsm6dsv16x.hpp"
#include "config/lsm6dsv16x-config_macro.hpp"
#include "esp_log.h"
#include <math.h>

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

#define HANDLE_OUTPUT(format, obj)               \
    do {                                         \
        switch (format)                          \
        {                                        \
        case OutputFormat::Log:                  \
            obj.log();                           \
            break;                               \
        case OutputFormat::JSON:                 \
            printf("%s\n", obj.to_json().c_str());\
            break;                               \
        default:                                 \
            break;                               \
        }                                        \
    } while (0)

namespace lsm6dsv16x
{
    inline esp_err_t return_if_not_ready(bool ready, const char* tag)
    {
        if (!ready)
        {
            ESP_LOGE(tag, "Tentative d’utilisation sans initialisation préalable");
            return ESP_ERR_INVALID_STATE;
        }
        return ESP_OK;
    }

     LSM6DSV16XManager:: LSM6DSV16XManager(I2CDevices &i2c)
        : i2c_(i2c),
          cfg_(i2c_),
          drdy_gpio_(gpio_num_t(CONFIG_LSM6DSV16X_INT_GPIO)),
          status_(i2c_),
          ctrl_(i2c_)
          {}

    void  LSM6DSV16XManager::init()
    {
        xTaskCreatePinnedToCore(task_wrapper, " LSM6DSV16X_Task", 4096, this, 5, &task_handle_, 0);
    }

    esp_err_t  LSM6DSV16XManager::init_device()
    {
        RETURN_IF_ERROR(is_ready());
        // Si besoin, charger depuis KConfig :
        //cfg_.datas() = load_config_from_kconfig();
        RETURN_IF_ERROR(get_status());
        RETURN_IF_ERROR(apply_config(cfg_));
        return ESP_OK;
    }

    esp_err_t  LSM6DSV16XManager::is_ready()
    {
        const int max_attempts = 10;
        const int delay_ms = 50;
        
        bool valid;

        for (int attempt = 0; attempt < max_attempts; ++attempt)
        {
            valid = status_.is_valid();
            if (valid == 1)
            {
                ESP_LOGI(TAG, " LSM6DSV16X détecté sur le bus (tentative %d)", attempt + 1);
                break;
            }
            ESP_LOGW(TAG, "Tentative %d/%d :  LSM6DSV16X non prêt", attempt + 1, max_attempts);
            vTaskDelay(pdMS_TO_TICKS(delay_ms));
        }
        if (valid != 1)
        {
            ESP_LOGE(TAG, " LSM6DSV16X non détecté après %d tentatives", max_attempts);
            ready_ = false;
            return ESP_ERR_TIMEOUT;
        }
        ready_ = true;
        return ESP_OK;
    }

    esp_err_t LSM6DSV16XManager::apply_config()
    {   
        RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
        ESP_LOGI(TAG, "Set config");
        load_config_from_kconfig();
        return ESP_OK;
    }

    esp_err_t  LSM6DSV16XManager::handle_drdy()
    {
        RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
        RETURN_IF_ERROR(status_.get());
        // Ici, ajouter la logique spécifique DRDY si besoin (lecture, callback…)
        return ESP_OK;
    }

    esp_err_t  LSM6DSV16XManager::reset()
    {
        RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
        return ctrl_.sw_reset(1);
    }

    esp_err_t  LSM6DSV16XManager::get_status(OutputFormat format)
    {
        RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
        RETURN_IF_ERROR(status_.get());
        return ESP_OK;
    }

esp_err_t  LSM6DSV16XManager::get_measurements(OutputFormat format)
{
    // 1. Lire le status jusqu'à avoir Zyxda=1
    RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
     do {
    RETURN_IF_ERROR(get_status());
    } while (status_.status.get_values().zyxda == 0 ); // Zyxda = bit 3 (cf. doc)
    
    
    // 2. Lire les registres bruts OUTX_L/H, OUTY_L/H, OUTZ_L/H
    RETURN_IF_ERROR(ctrl_.get_all());

    HANDLE_OUTPUT(format, ctrl_);
    return ESP_OK;
}

esp_err_t  LSM6DSV16XManager::get_compass()
{
    // 1. Lire le status jusqu'à avoir Zyxda=1
    RETURN_IF_ERROR(return_if_not_ready(ready_, TAG));
     do {
    RETURN_IF_ERROR(get_status());
    } while (status_.status.get_values().zyxda == 0 ); // Zyxda = bit 3 (cf. doc)
    
    
    // 2. Lire les registres bruts OUTX_L/H, OUTY_L/H, OUTZ_L/H
    RETURN_IF_ERROR(ctrl_.get_all());

    float heading = atan2(-ctrl_.out_y.get_milligauss(), ctrl_.out_x.get_milligauss()) * 180.0f / M_PI;
    if (heading < 0) heading += 360.0f;
    ESP_LOGI("COMPASS", "Heading = %.1f°", heading);
    return ESP_OK;
}

esp_err_t  LSM6DSV16XManager::calibrate_hard_iron(uint16_t samples, TickType_t delay_ms)
{
    int16_t x_min = 32767, x_max = -32768;
    int16_t y_min = 32767, y_max = -32768;
    int16_t z_min = 32767, z_max = -32768;
    int16_t x = 0, y = 0, z = 0;

    ESP_LOGI(TAG, "Début calibration hard-iron  LSM6DSV16X sur %d échantillons", samples);
    ESP_LOGI(TAG, "Tourner le capteur dans tous les axes…");

    for (uint16_t i = 0; i < samples; ++i) {
        // Lire une mesure brute (à adapter selon ton API)
        RETURN_IF_ERROR(get_measurements());
        x = ctrl_.out_x.get_value();
        y = ctrl_.out_y.get_value();
        z = ctrl_.out_z.get_value();
        if (x < x_min) x_min = x;
        if (x > x_max) x_max = x;
        if (y < y_min) y_min = y;
        if (y > y_max) y_max = y;
        if (z < z_min) z_min = z;
        if (z > z_max) z_max = z;

        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }

    int16_t offset_x = (x_max + x_min) / 2;
    int16_t offset_y = (y_max + y_min) / 2;
    int16_t offset_z = (z_max + z_min) / 2;

    ESP_LOGI(TAG, "Calibration terminée. Offsets trouvés : X=%d, Y=%d, Z=%d", offset_x, offset_y, offset_z);

    // On écrit dans les registres d’offset (voir ta classe OffsetRegister)

    cfg_.datas().offset.offset_x.set_value(offset_x);
    cfg_.datas().offset.offset_y.set_value(offset_y);
    cfg_.datas().offset.offset_z.set_value(offset_z);

    RETURN_IF_ERROR(cfg_.set_offset_x());
    RETURN_IF_ERROR(cfg_.set_offset_y());
    RETURN_IF_ERROR(cfg_.set_offset_z());

    ESP_LOGI(TAG, "Offsets écrits dans les registres matériels  LSM6DSV16X.");
    return ESP_OK;
}

    void  LSM6DSV16XManager::task_wrapper(void *arg)
    {
        static_cast< LSM6DSV16XManager *>(arg)->task_main();
    }

    void IRAM_ATTR  LSM6DSV16XManager::gpio_isr_handler(void *arg)
    {
        auto *self = static_cast< LSM6DSV16XManager *>(arg);
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        vTaskNotifyGiveFromISR(self->task_handle_, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }

    void  LSM6DSV16XManager::setup_interrupt(gpio_num_t gpio)
    {
        static bool isr_installed = false;
        gpio_config_t io_conf = {};
        io_conf.intr_type = GPIO_INTR_NEGEDGE;
        io_conf.mode = GPIO_MODE_INPUT;
        io_conf.pin_bit_mask = (1ULL << gpio);
        io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
        gpio_config(&io_conf);

        if (!isr_installed)
        {
            esp_err_t err = gpio_install_isr_service(ESP_INTR_FLAG_LEVEL3);
            if (err == ESP_OK || err == ESP_ERR_INVALID_STATE)
            {
                isr_installed = true;
            }
            else
            {
                ESP_LOGE(TAG, "Failed to install ISR service: %s", esp_err_to_name(err));
            }
        }

        gpio_isr_handler_add(gpio, gpio_isr_handler, this);
    }

    void  LSM6DSV16XManager::task_main()
    {
        setup_interrupt(drdy_gpio_);
        init_device();
        
        while (true)
        {
            if (gpio_get_level(drdy_gpio_) == 0 || ulTaskNotifyTake(pdTRUE, portMAX_DELAY))
            {
                if (gpio_get_level(drdy_gpio_) == 0)
                {
                    ESP_LOGI(TAG, "DRDY interrupt detected");
                    handle_drdy();
                }
            }
        }
    }
};
