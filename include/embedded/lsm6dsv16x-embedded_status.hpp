#pragma once

#include "embedded/lsm6dsv16x-embedded_status_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class EMB_STATUS : public INTERFACE
    {
    public:
        explicit EMB_STATUS(I2CDevices &dev) : INTERFACE(dev) {}

        // ----------- EmbFuncExecStatusRegister (0x07)
        DEFINE_DATA(EmbFuncExecStatusRegister, emb_func_exec_ovr, bool)
        DEFINE_DATA(EmbFuncExecStatusRegister, emb_func_endop, bool)
        DEFINE_REGOUT(EmbFuncExecStatusRegister)

        // ----------- EmbFuncStatusRegister (0x12)
        DEFINE_DATA(EmbFuncStatusRegister, is_fsm_lc, bool)
        DEFINE_DATA(EmbFuncStatusRegister, is_sigmot, bool)
        DEFINE_DATA(EmbFuncStatusRegister, is_tilt, bool)
        DEFINE_DATA(EmbFuncStatusRegister, is_step_det, bool)
        DEFINE_REGOUT(EmbFuncStatusRegister)

        // ----------- FsmStatusRegister (0x13)
        DEFINE_DATA(FsmStatusRegister, is_fsm1, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm2, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm3, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm4, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm5, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm6, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm7, bool)
        DEFINE_DATA(FsmStatusRegister, is_fsm8, bool)
        DEFINE_REGOUT(FsmStatusRegister)

        // ----------- MlcStatusRegister (0x15)
        DEFINE_DATA(MlcStatusRegister, is_mlc1, bool)
        DEFINE_DATA(MlcStatusRegister, is_mlc2, bool)
        DEFINE_DATA(MlcStatusRegister, is_mlc3, bool)
        DEFINE_DATA(MlcStatusRegister, is_mlc4, bool)
        DEFINE_REGOUT(MlcStatusRegister)

        // ----------- EmbFuncSrcRegister (0x64)
        DEFINE_DATA(EmbFuncSrcRegister, pedo_rst_step, bool)
        DEFINE_DATA(EmbFuncSrcRegister, step_detected, bool)
        DEFINE_DATA(EmbFuncSrcRegister, step_count_delta_ia, bool)
        DEFINE_DATA(EmbFuncSrcRegister, step_overflow, bool)
        DEFINE_DATA(EmbFuncSrcRegister, stepcounter_bit_set, bool)
        DEFINE_REGOUT(EmbFuncSrcRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-EMB_STATUS";
    };

} // namespace lsm6dsv16x
