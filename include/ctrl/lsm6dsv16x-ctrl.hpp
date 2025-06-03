#pragma once

#include <functional>

#include "ctrl/lsm6dsv16x-ctrl_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class CTRL : public INTERFACE
    {
    public:
        explicit CTRL(I2CDevices &dev) : INTERFACE(dev) {}

        template <typename RegT>
        esp_err_t configure(std::function<void(RegT &)> f);

        esp_err_t software_reset();

    private:
        template <typename RegT>
        esp_err_t read(RegT &reg);

        template <typename RegT>
        esp_err_t write(const RegT &reg);

// Déclaration groupée via macro
#define REG_DECL(n)                                \
        esp_err_t get_ctrl##n(Ctrl##n##Register &reg); \
        esp_err_t set_ctrl##n(const Ctrl##n##Register &reg);

            REG_DECL(1)
            REG_DECL(2)
            REG_DECL(3)
            REG_DECL(4)
            REG_DECL(5)
            REG_DECL(6)
            REG_DECL(7)
            REG_DECL(8)
            REG_DECL(9)
            REG_DECL(10)

#undef REG_DECL
        inline static const char *TAG = "LSM6DSV16X-CTRL";
    };

} // namespace lsm6dsv16x
