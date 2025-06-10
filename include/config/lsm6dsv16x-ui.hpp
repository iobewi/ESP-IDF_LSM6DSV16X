#pragma once

#include "lsm6dsv16x-ui_types.hpp"

#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class UI : public INTERFACE
    {
    public:
        explicit UI(I2CDevices &dev) : INTERFACE(dev) {}

        // ----------- UiStatusRegister
        DEFINE_FIELD(UiHandshakeCtrlRegister, ui_shared_ack, bool)
        DEFINE_FIELD(UiHandshakeCtrlRegister, ui_shared_req, bool)
        DEFINE_REGOUT(UiHandshakeCtrlRegister)

        // ----------- UiSpi2SharedRegister
        DEFINE_FIELD(UiSpi2Shared0Register, spi2_shared0, uint8_t)
        DEFINE_FIELD(UiSpi2Shared1Register, spi2_shared1, uint8_t)
        DEFINE_FIELD(UiSpi2Shared2Register, spi2_shared2, uint8_t)
        DEFINE_FIELD(UiSpi2Shared3Register, spi2_shared3, uint8_t)
        DEFINE_FIELD(UiSpi2Shared4Register, spi2_shared4, uint8_t)
        DEFINE_FIELD(UiSpi2Shared5Register, spi2_shared5, uint8_t)
        DEFINE_REGOUT(UiSpi2Shared5Register)

        // ----------- UiIntOisRegister
        DEFINE_FIELD(UiIntOisRegister, int2_drdy_ois, bool)
        DEFINE_FIELD(UiIntOisRegister, drdy_mask_ois, bool)
        DEFINE_FIELD(UiIntOisRegister, st_ois_clampdis, bool)
        DEFINE_REGOUT(UiIntOisRegister)

        // ----------- UiCtrl1OisRegister
        DEFINE_FIELD(UiCtrl1OisRegister, sim_ois, bool)
        DEFINE_FIELD(UiCtrl1OisRegister, ois_xl_en, bool)
        DEFINE_FIELD(UiCtrl1OisRegister, ois_g_en, bool)
        DEFINE_FIELD(UiCtrl1OisRegister, spi2_read_en, bool)
        DEFINE_REGOUT(UiCtrl1OisRegister)

        // ----------- UiCtrl2OisRegister
        DEFINE_FIELD(UiCtrl2OisRegister, lpf1_g_ois_bw, UiCtrl2OisRegister::Lpf1GOisBw)
        DEFINE_FIELD(UiCtrl2OisRegister, fs_g_ois, UiCtrl2OisRegister::FsGOis)
        DEFINE_REGOUT(UiCtrl2OisRegister)

        // ----------- UiCtrl3OisRegister
        DEFINE_FIELD(UiCtrl3OisRegister, lpf_xl_ois_bw, UiCtrl3OisRegister::LpfXlOisBw)
        DEFINE_FIELD(UiCtrl3OisRegister, fs_xl_ois, UiCtrl3OisRegister::FsXlOis)
        DEFINE_REGOUT(UiCtrl3OisRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-UI";
    };
} // namespace lsm6dsv16x