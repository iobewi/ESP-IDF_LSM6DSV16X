#pragma once

#include "data/lsm6dsv16x-data_fifo_types.hpp"
#include "data/lsm6dsv16x-data_types.hpp"

#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class DATA : public INTERFACE
    {
    public:
        explicit DATA(I2CDevices &dev) : INTERFACE(dev) {}

        DEFINE_DATA(TimestampRegister, timestamp_us, double) 
        DEFINE_DATA(OutTempRegister, out_temp, int16_t)
        DEFINE_DATA(AhQvarOutRegister, out_ah_qvar, int16_t)

        DEFINE_DATA(OutXGRegister, out_gyro_x, int16_t)
        DEFINE_DATA(OutYGRegister, out_gyro_y, int16_t) 
        DEFINE_DATA(OutZGRegister, out_gyro_z, int16_t)

        DEFINE_DATA(OutXGOisEisRegister, ui_out_gyro_x, int16_t) 
        DEFINE_DATA(OutYGOisEisRegister, ui_out_gyro_y, int16_t) 
        DEFINE_DATA(OutZGOisEisRegister, ui_out_gyro_z, int16_t) 

        DEFINE_DATA(OutXARegister, out_acc_x, int16_t) 
        DEFINE_DATA(OutYARegister, out_acc_y, int16_t) 
        DEFINE_DATA(OutZARegister, out_acc_z, int16_t) 

        DEFINE_DATA(OutXAOisDualCRegister, ui_out_acc_x, int16_t) 
        DEFINE_DATA(OutYAOisDualCRegister, ui_out_acc_y, int16_t) 
        DEFINE_DATA(OutZAOisDualCRegister, ui_out_acc_z, int16_t)  

        DEFINE_DATA(FifoOutXRegister, fifo_out_x, int16_t) 
        DEFINE_DATA(FifoOutYRegister, fifo_out_y, int16_t) 
        DEFINE_DATA(FifoOutZRegister, fifo_out_z, int16_t) 
    private:
        inline static const char *TAG = "LSM6DSV16X-DATA";
    };
}
