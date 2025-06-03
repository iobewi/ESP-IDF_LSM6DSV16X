#pragma once

#include <cstdint>
#include <string>


#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
DEFINE_GENERIC_REGISTER_ADDR(InternalFreqFineRegister, uint8_t, 0x4F)
    public:
        // Les 8 bits : FREQ_FINE[7:0], signed (two's complement), step = 0.13%
        float percent() const { return raw_ * 0.13f; }
    private:
        inline static const char *TAG = "LSM6DSV16X-INTERNAL_FREQ_FINE";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(TimestampRegister, uint32_t, 0x40)
    public:
        // 1 LSB = 21.75 µs typique
        double timestamp_us() const { return raw_ * 21.75; }
    private:
        inline static const char *TAG = "LSM6DSV16X-TIMESTAMP";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutTempRegister, 0x20)
    private:
        inline static const char *TAG = "LSM6DSV16X-DATA_TEMPERATURE";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutXGRegister, 0x22)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTX_G";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutYGRegister, 0x24)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTY_G";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutZGRegister, 0x26)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTZ_G";
END_REGISTER
   
DEFINE_GENERIC_REGISTER_DATA(OutXARegister, 0x28)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTX_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutYARegister, 0x2A)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTY_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutZARegister, 0x2C)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTZ_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutXGOisEisRegister, 0x2E)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTX_G_OIS_EIS";
END_REGISTER
   
DEFINE_GENERIC_REGISTER_DATA(OutYGOisEisRegister, 0x30)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTY_G_OIS_EIS";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutZGOisEisRegister, 0x32)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTZ_G_OIS_EIS";
END_REGISTER
   
DEFINE_GENERIC_REGISTER_DATA(OutXAOisDualCRegister, 0x34)
    private:
        inline static const char *TAG = "LSM6DSV16X_OUTX_A_OIS_DUALC";
END_REGISTER
   
DEFINE_GENERIC_REGISTER_DATA(OutYAOisDualCRegister, 0x36)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTY_A_OIS_DUALC";
END_REGISTER

DEFINE_GENERIC_REGISTER_DATA(OutZAOisDualCRegister, 0x38)
    private:
        inline static const char *TAG = "LSM6DSV16X-OUTZ_A_OIS_DUALC";
END_REGISTER
    
DEFINE_GENERIC_REGISTER_DATA(AhQvarOutRegister, 0x3A)
    private:
        inline static const char *TAG = "LSM6DSV16X-AH_QVAR_OUT";
END_REGISTER
}
