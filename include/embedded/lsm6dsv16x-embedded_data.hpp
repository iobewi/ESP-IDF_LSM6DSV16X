#pragma once

#include "embedded/lsm6dsv16x-embedded_data_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class EMB_DATA : public INTERFACE
    {
    public:
        explicit EMB_DATA(I2CDevices &dev) : INTERFACE(dev) {}

        // ----------- FSM OUTS 1 à 8
        DEFINE_DATA(FsmOuts1Register, fsm1_p_x, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_n_x, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_p_y, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_n_y, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_p_z, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_n_z, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_p_v, bool)
        DEFINE_DATA(FsmOuts1Register, fsm1_n_v, bool)
        DEFINE_REGOUT(FsmOuts1Register)

        DEFINE_DATA(FsmOuts2Register, fsm2_p_x, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_n_x, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_p_y, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_n_y, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_p_z, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_n_z, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_p_v, bool)
        DEFINE_DATA(FsmOuts2Register, fsm2_n_v, bool)
        DEFINE_REGOUT(FsmOuts2Register)

        DEFINE_DATA(FsmOuts3Register, fsm3_p_x, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_n_x, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_p_y, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_n_y, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_p_z, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_n_z, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_p_v, bool)
        DEFINE_DATA(FsmOuts3Register, fsm3_n_v, bool)
        DEFINE_REGOUT(FsmOuts3Register)

        DEFINE_DATA(FsmOuts4Register, fsm4_p_x, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_n_x, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_p_y, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_n_y, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_p_z, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_n_z, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_p_v, bool)
        DEFINE_DATA(FsmOuts4Register, fsm4_n_v, bool)
        DEFINE_REGOUT(FsmOuts4Register)

        DEFINE_DATA(FsmOuts5Register, fsm5_p_x, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_n_x, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_p_y, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_n_y, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_p_z, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_n_z, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_p_v, bool)
        DEFINE_DATA(FsmOuts5Register, fsm5_n_v, bool)
        DEFINE_REGOUT(FsmOuts5Register)

        DEFINE_DATA(FsmOuts6Register, fsm6_p_x, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_n_x, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_p_y, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_n_y, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_p_z, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_n_z, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_p_v, bool)
        DEFINE_DATA(FsmOuts6Register, fsm6_n_v, bool)
        DEFINE_REGOUT(FsmOuts6Register)

        DEFINE_DATA(FsmOuts7Register, fsm7_p_x, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_n_x, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_p_y, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_n_y, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_p_z, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_n_z, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_p_v, bool)
        DEFINE_DATA(FsmOuts7Register, fsm7_n_v, bool)
        DEFINE_REGOUT(FsmOuts7Register)

        DEFINE_DATA(FsmOuts8Register, fsm8_p_x, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_n_x, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_p_y, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_n_y, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_p_z, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_n_z, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_p_v, bool)
        DEFINE_DATA(FsmOuts8Register, fsm8_n_v, bool)
        DEFINE_REGOUT(FsmOuts8Register)

        // ----------- Step Counter
        DEFINE_DATA(StepCounterRegister, step_counter, uint16_t)
        DEFINE_REGOUT(StepCounterRegister)

        // ----------- MLC Output (décision finale)
        DEFINE_DATA(Mlc1SrcRegister, mlc1_output, uint8_t)
        DEFINE_REGOUT(Mlc1SrcRegister)
        DEFINE_DATA(Mlc2SrcRegister, mlc2_output, uint8_t)
        DEFINE_REGOUT(Mlc2SrcRegister)
        DEFINE_DATA(Mlc3SrcRegister, mlc3_output, uint8_t)
        DEFINE_REGOUT(Mlc3SrcRegister)
        DEFINE_DATA(Mlc4SrcRegister, mlc4_output, uint8_t)
        DEFINE_REGOUT(Mlc4SrcRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-EMB_DATA";
    };

} // namespace lsm6dsv16x
