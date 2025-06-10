#pragma once

#include "lsm6dsv16x-status_types.hpp"

#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class STATUS : public INTERFACE
    {
    public:
        explicit STATUS(I2CDevices &dev) : INTERFACE(dev) {}
        DEFINE_DATA(WhoAmIRegister, is_valid, bool)
        DEFINE_REGOUT(WhoAmIRegister)

        DEFINE_DATA(CtrlStatusRegister,fsm_wr_ctrl_status,bool)
        DEFINE_REGOUT(CtrlStatusRegister)

        DEFINE_DATA(FifoStatusRegister,fifo_ovr_ia,bool)
        DEFINE_DATA(FifoStatusRegister,fifo_full_ia,bool)
        DEFINE_DATA(FifoStatusRegister,counter_bdr_ia,bool)
        DEFINE_DATA(FifoStatusRegister,fifo_ovr_latched,bool)
        DEFINE_DATA(FifoStatusRegister,diff_fifo,uint16_t)
        DEFINE_REGOUT(FifoStatusRegister)

        DEFINE_DATA(AllIntSrcRegister,int_emb_func_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_shub_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_sleep_change_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_d6d_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_tap_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_wu_ia,bool)
        DEFINE_DATA(AllIntSrcRegister,int_ff_ia,bool)
        DEFINE_REGOUT(AllIntSrcRegister)

        DEFINE_DATA(StatusRegRegister,timestamp_endcount,bool)
        DEFINE_DATA(StatusRegRegister,ois_drdy,bool)
        DEFINE_DATA(StatusRegRegister,gda_eis,bool)
        DEFINE_DATA(StatusRegRegister,ah_qvarda,bool)
        DEFINE_DATA(StatusRegRegister,tda,bool)
        DEFINE_DATA(StatusRegRegister,gda,bool)
        DEFINE_DATA(StatusRegRegister,xlda,bool)
        DEFINE_REGOUT(StatusRegRegister)

        DEFINE_DATA(UiStatusRegOisRegister,gyro_settling,bool)
        DEFINE_DATA(UiStatusRegOisRegister,gda_ois,bool)
        DEFINE_DATA(UiStatusRegOisRegister,xlda_ois,bool)
        DEFINE_REGOUT(UiStatusRegOisRegister)

        DEFINE_DATA(WakeUpSrcRegister,sleep_change_ia,bool)
        DEFINE_DATA(WakeUpSrcRegister,ff_ia,bool)
        DEFINE_DATA(WakeUpSrcRegister,sleep_state,bool)
        DEFINE_DATA(WakeUpSrcRegister,wu_ia,bool)
        DEFINE_DATA(WakeUpSrcRegister,x_wu,bool)
        DEFINE_DATA(WakeUpSrcRegister,y_wu,bool)
        DEFINE_DATA(WakeUpSrcRegister,z_wu,bool)    
        DEFINE_REGOUT(WakeUpSrcRegister) 

        DEFINE_DATA(TapSrcRegister, tap_ia, bool)
        DEFINE_DATA(TapSrcRegister, single_tap, bool)
        DEFINE_DATA(TapSrcRegister, double_tap, bool)
        DEFINE_DATA(TapSrcRegister, tap_sign, bool)
        DEFINE_DATA(TapSrcRegister, x_tap, bool)
        DEFINE_DATA(TapSrcRegister, y_tap, bool)
        DEFINE_DATA(TapSrcRegister, z_tap, bool)
        DEFINE_REGOUT(TapSrcRegister)

        DEFINE_DATA(D6dSrcRegister, d6d_ia, bool)
        DEFINE_DATA(D6dSrcRegister, zh, bool)
        DEFINE_DATA(D6dSrcRegister, zl, bool)
        DEFINE_DATA(D6dSrcRegister, yh, bool)
        DEFINE_DATA(D6dSrcRegister, yl, bool)
        DEFINE_DATA(D6dSrcRegister, xh, bool)
        DEFINE_DATA(D6dSrcRegister, xl, bool)
        DEFINE_REGOUT(D6dSrcRegister)

        DEFINE_DATA(StatusMasterMainpageRegister, wr_once_done, bool)
        DEFINE_DATA(StatusMasterMainpageRegister, slave3_nack, bool)
        DEFINE_DATA(StatusMasterMainpageRegister, slave2_nack, bool)
        DEFINE_DATA(StatusMasterMainpageRegister, slave1_nack, bool)
        DEFINE_DATA(StatusMasterMainpageRegister, slave0_nack, bool)
        DEFINE_DATA(StatusMasterMainpageRegister, sens_hub_endop, bool)
        DEFINE_REGOUT(StatusMasterMainpageRegister)

        DEFINE_DATA(EmbFuncStatusMainpageRegister, is_fsm_lc, bool)
        DEFINE_DATA(EmbFuncStatusMainpageRegister, is_sigmot, bool)
        DEFINE_DATA(EmbFuncStatusMainpageRegister, is_tilt, bool)
        DEFINE_DATA(EmbFuncStatusMainpageRegister, is_step_det, bool)
        DEFINE_REGOUT(EmbFuncStatusMainpageRegister)

        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm8, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm7, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm6, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm5, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm4, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm3, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm2, bool)
        DEFINE_DATA(FsmStatusMainpageRegister, is_fsm1, bool)
        DEFINE_REGOUT(FsmStatusMainpageRegister)

        DEFINE_DATA(MlcStatusMainpageRegister, is_mlc4, bool)
        DEFINE_DATA(MlcStatusMainpageRegister, is_mlc3, bool)
        DEFINE_DATA(MlcStatusMainpageRegister, is_mlc2, bool)
        DEFINE_DATA(MlcStatusMainpageRegister, is_mlc1, bool)
        DEFINE_REGOUT(MlcStatusMainpageRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-STATUS";
    };
}
