#pragma once

#include "lsm6dsv16x-offset_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class OFFSET : public INTERFACE
    {
    public:
        explicit OFFSET (I2CDevices &dev) : INTERFACE(dev) {}

        DEFINE_FIELD(XOfsUsrRegister, offset_x, uint8_t)
        DEFINE_REGOUT(XOfsUsrRegister)
        DEFINE_FIELD(YOfsUsrRegister, offset_y, uint8_t)
        DEFINE_REGOUT(YOfsUsrRegister)
        DEFINE_FIELD(ZOfsUsrRegister, offset_z, uint8_t)
        DEFINE_REGOUT(ZOfsUsrRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-OFFSET";
    };
} // namespace lsm6dsv16x
