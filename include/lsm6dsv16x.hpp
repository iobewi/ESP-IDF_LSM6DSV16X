#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "sdkconfig.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_intr_alloc.h"

#include "config/lsm6dsv16x-config.hpp"
#include "config/lsm6dsv16x-embfunc.hpp"
#include "config/lsm6dsv16x-offset.hpp"
#include "config/lsm6dsv16x-ui.hpp"

#include "ctrl/lsm6dsv16x-ctrl.hpp"
#include "data/lsm6dsv16x-data.hpp"
#include "status/lsm6dsv16x-status.hpp"

#include "embedded/lsm6dsv16x-embedded_config.hpp"
#include "embedded/lsm6dsv16x-embedded_data.hpp"
#include "embedded/lsm6dsv16x-embedded_status.hpp"

namespace lsm6dsv16x
{
    enum class OutputFormat
    {
        None,
        Log,
        JSON
    };

    class LSM6DSV16XManager
    {
    public:
        LSM6DSV16XManager(I2CDevices &i2c);

        // === API PUBLIQUE ===

        /// Initialise la task
        void init();

        /// Initialise la configuration capteur
        esp_err_t init_device();

        /// Soft reset capteur
        esp_err_t reset();

        /// Applique la configuration software au capteur
        esp_err_t apply_config();

        /// Gère l’interruption data ready
        esp_err_t handle_drdy();

        // Effectue une calibration hard-iron sur N échantillons, écrit le résultat dans les registres d’offset
        esp_err_t calibrate_hard_iron(uint16_t samples = 500, TickType_t delay_ms = 20);

        /// Récupère les mesures courantes
        esp_err_t get_measurements(OutputFormat format = OutputFormat::None);

        /// Affichage état status/config
        esp_err_t get_status(OutputFormat format = OutputFormat::None);

        esp_err_t get_gyro();
        esp_err_t get_acc();

        esp_err_t get_ui_gyro();
        esp_err_t get_ui_acc();

        esp_err_t get_();
        

    private:
        I2CDevices &i2c_;
        CONFIG cfg_;
        gpio_num_t drdy_gpio_;
        STATUS status_;
        CTRL ctrl_;

        inline static const char *TAG = "LSM6DSV16X-MANAGER";
        bool ready_ = false;
        esp_err_t is_ready();

        TaskHandle_t task_handle_ = nullptr;

        static void task_wrapper(void *arg);
        static void IRAM_ATTR gpio_isr_handler(void *arg);
        void setup_interrupt(gpio_num_t gpio);
        void task_main();
    };

}