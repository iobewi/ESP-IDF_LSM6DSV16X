#pragma once

#include "ctrl/lsm6dsv16x-ctrl_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class CTRL : public INTERFACE
    {
    public:
        explicit CTRL(I2CDevices &dev) : INTERFACE(dev) {}

        // ----------- Ctrl1Register
        DEFINE_FIELD(Ctrl1Register, odr_xl, Ctrl1Register::Odr)
        DEFINE_FIELD(Ctrl1Register, op_mode_xl, Ctrl1Register::OpMode)
        DEFINE_REGOUT(Ctrl1Register)

        // ----------- Ctrl2Register
        DEFINE_FIELD(Ctrl2Register, odr_g, Ctrl2Register::Odr)
        DEFINE_FIELD(Ctrl2Register, op_mode_g, Ctrl2Register::OpMode)
        DEFINE_REGOUT(Ctrl2Register)

        // ----------- Ctrl3Register
        DEFINE_FIELD(Ctrl3Register, boot, bool)
        DEFINE_FIELD(Ctrl3Register, bdu, bool)
        DEFINE_FIELD(Ctrl3Register, if_inc, bool)
        DEFINE_FIELD(Ctrl3Register, sw_reset, bool)
        DEFINE_REGOUT(Ctrl3Register)

        // ----------- Ctrl4Register
        DEFINE_FIELD(Ctrl4Register, int2_on_int1, bool)
        DEFINE_FIELD(Ctrl4Register, drdy_mask, bool)
        DEFINE_FIELD(Ctrl4Register, int2_drdy_temp, bool)
        DEFINE_FIELD(Ctrl4Register, drdy_pulsed, bool)
        DEFINE_FIELD(Ctrl4Register, int2_in_lh, bool)
        DEFINE_REGOUT(Ctrl4Register)

        // ----------- Ctrl5Register
        DEFINE_FIELD(Ctrl5Register, bus_act_sel, Ctrl5Register::BusActSel)
        DEFINE_FIELD(Ctrl5Register, int_en_i3c, bool)
        DEFINE_REGOUT(Ctrl5Register)

        // ----------- Ctrl6Register
        DEFINE_FIELD(Ctrl6Register, lpf1_g_bw, Ctrl6Register::Lpf1GBw)
        DEFINE_FIELD(Ctrl6Register, fs_g, Ctrl6Register::FsG)
        DEFINE_REGOUT(Ctrl6Register)

        // ----------- Ctrl7Register
        DEFINE_FIELD(Ctrl7Register, ah_qvar_en, bool)
        DEFINE_FIELD(Ctrl7Register, int2_drdy_ah_qvar, bool)
        DEFINE_FIELD(Ctrl7Register, ah_qvar_c_zin, Ctrl7Register::AhQvarCZin)
        DEFINE_FIELD(Ctrl7Register, lpf1_g_en, bool)
        DEFINE_REGOUT(Ctrl7Register)

        // ----------- Ctrl8Register
        DEFINE_FIELD(Ctrl8Register, hp_lpf2_xl_bw, Ctrl8Register::HpLpf2XlBw)
        DEFINE_FIELD(Ctrl8Register, xl_dualc_en, bool)
        DEFINE_FIELD(Ctrl8Register, fs_xl, Ctrl8Register::FsXl)
        DEFINE_REGOUT(Ctrl8Register)

        // ----------- Ctrl9Register
        DEFINE_FIELD(Ctrl9Register, hp_ref_mode_xl, bool)
        DEFINE_FIELD(Ctrl9Register, xl_fastsettl_mode, bool)
        DEFINE_FIELD(Ctrl9Register, hp_slope_xl_en, bool)
        DEFINE_FIELD(Ctrl9Register, lpf2_xl_en, bool)
        DEFINE_FIELD(Ctrl9Register, usr_off_w, Ctrl9Register::UsrOffW)
        DEFINE_FIELD(Ctrl9Register, usr_off_on_out, bool)
        DEFINE_REGOUT(Ctrl9Register)

        // ----------- Ctrl10Register
        DEFINE_FIELD(Ctrl10Register, emb_func_debug, bool)
        DEFINE_FIELD(Ctrl10Register, st_g, Ctrl10Register::StG)
        DEFINE_FIELD(Ctrl10Register, st_xl, Ctrl10Register::StXl)
        DEFINE_REGOUT(Ctrl10Register)

    private:
        inline static const char *TAG = "LSM6DSV16X-CTRL";
    };

} // namespace lsm6dsv16x
