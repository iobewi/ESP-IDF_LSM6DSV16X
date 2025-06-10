#pragma once

#include "embedded/lsm6dsv16x-embedded_config_types.hpp"
#include "lsm6dsv16x-interface.hpp"

namespace lsm6dsv16x
{
    static_assert(std::is_class<INTERFACE>::value, "INTERFACE is not a class");

    class EMB_CTRL : public INTERFACE
    {
    public:
        explicit EMB_CTRL(I2CDevices &dev) : INTERFACE(dev) {}

    // ----------- PageSelRegister
DEFINE_FIELD(PageSelRegister, page_sel, uint8_t)
DEFINE_REGOUT(PageSelRegister)

// ----------- EmbFuncEnARegister
DEFINE_FIELD(EmbFuncEnARegister, mlc_before_fsm_en, bool)
DEFINE_FIELD(EmbFuncEnARegister, sign_motion_en, bool)
DEFINE_FIELD(EmbFuncEnARegister, tilt_en, bool)
DEFINE_FIELD(EmbFuncEnARegister, pedo_en, bool)
DEFINE_FIELD(EmbFuncEnARegister, sflp_game_en, bool)
DEFINE_REGOUT(EmbFuncEnARegister)

// ----------- EmbFuncEnBRegister
DEFINE_FIELD(EmbFuncEnBRegister, mlc_en, bool)
DEFINE_FIELD(EmbFuncEnBRegister, fifo_compr_en, bool)
DEFINE_FIELD(EmbFuncEnBRegister, fsm_en, bool)
DEFINE_REGOUT(EmbFuncEnBRegister)

// ----------- PageAddressRegister
DEFINE_FIELD(PageAddressRegister, page_addr, uint8_t)
DEFINE_REGOUT(PageAddressRegister)

// ----------- PageValueRegister
DEFINE_FIELD(PageValueRegister, page_value, uint8_t)
DEFINE_REGOUT(PageValueRegister)

// ----------- EmbFuncInt1Register
DEFINE_FIELD(EmbFuncInt1Register, int1_fsm_lc, bool)
DEFINE_FIELD(EmbFuncInt1Register, int1_sig_mot, bool)
DEFINE_FIELD(EmbFuncInt1Register, int1_tilt, bool)
DEFINE_FIELD(EmbFuncInt1Register, int1_step_detector, bool)
DEFINE_REGOUT(EmbFuncInt1Register)

// ----------- FsmInt1Register
DEFINE_FIELD(FsmInt1Register, int1_fsm1, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm2, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm3, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm4, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm5, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm6, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm7, bool)
DEFINE_FIELD(FsmInt1Register, int1_fsm8, bool)
DEFINE_REGOUT(FsmInt1Register)

// ----------- MlcInt1Register
DEFINE_FIELD(MlcInt1Register, int1_mlc1, bool)
DEFINE_FIELD(MlcInt1Register, int1_mlc2, bool)
DEFINE_FIELD(MlcInt1Register, int1_mlc3, bool)
DEFINE_FIELD(MlcInt1Register, int1_mlc4, bool)
DEFINE_REGOUT(MlcInt1Register)

// ----------- EmbFuncInt2Register
DEFINE_FIELD(EmbFuncInt2Register, int2_fsm_lc, bool)
DEFINE_FIELD(EmbFuncInt2Register, int2_sig_mot, bool)
DEFINE_FIELD(EmbFuncInt2Register, int2_tilt, bool)
DEFINE_FIELD(EmbFuncInt2Register, int2_step_detector, bool)
DEFINE_REGOUT(EmbFuncInt2Register)

// ----------- FsmInt2Register
DEFINE_FIELD(FsmInt2Register, int2_fsm1, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm2, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm3, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm4, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm5, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm6, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm7, bool)
DEFINE_FIELD(FsmInt2Register, int2_fsm8, bool)
DEFINE_REGOUT(FsmInt2Register)

// ----------- MlcInt2Register
DEFINE_FIELD(MlcInt2Register, int2_mlc1, bool)
DEFINE_FIELD(MlcInt2Register, int2_mlc2, bool)
DEFINE_FIELD(MlcInt2Register, int2_mlc3, bool)
DEFINE_FIELD(MlcInt2Register, int2_mlc4, bool)
DEFINE_REGOUT(MlcInt2Register)

// ----------- PageRwRegister
DEFINE_FIELD(PageRwRegister, emb_func_lir, bool)
DEFINE_FIELD(PageRwRegister, page_write, bool)
DEFINE_FIELD(PageRwRegister, page_read, bool)
DEFINE_REGOUT(PageRwRegister)

// ----------- EmbFuncFifoEnARegister
DEFINE_FIELD(EmbFuncFifoEnARegister, mlc_fifo_en, bool)
DEFINE_FIELD(EmbFuncFifoEnARegister, step_counter_fifo_en, bool)
DEFINE_FIELD(EmbFuncFifoEnARegister, sflp_gbias_fifo_en, bool)
DEFINE_FIELD(EmbFuncFifoEnARegister, sflp_gravity_fifo_en, bool)
DEFINE_FIELD(EmbFuncFifoEnARegister, sflp_game_fifo_en, bool)
DEFINE_REGOUT(EmbFuncFifoEnARegister)

// ----------- EmbFuncFifoEnBRegister
DEFINE_FIELD(EmbFuncFifoEnBRegister, mlc_filter_feature_fifo_en, bool)
DEFINE_REGOUT(EmbFuncFifoEnBRegister)

// ----------- FsmEnableRegister
DEFINE_FIELD(FsmEnableRegister, fsm1_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm2_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm3_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm4_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm5_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm6_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm7_en, bool)
DEFINE_FIELD(FsmEnableRegister, fsm8_en, bool)
DEFINE_REGOUT(FsmEnableRegister)

// ----------- FsmLongCounterRegister
DEFINE_FIELD(FsmLongCounterRegister, fsm_long_counter, uint16_t)
DEFINE_REGOUT(FsmLongCounterRegister)

// ----------- IntAckMaskRegister
DEFINE_FIELD(IntAckMaskRegister, iack_mask0, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask1, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask2, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask3, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask4, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask5, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask6, bool)
DEFINE_FIELD(IntAckMaskRegister, iack_mask7, bool)
DEFINE_REGOUT(IntAckMaskRegister)

// ----------- SflpOdrRegister
DEFINE_FIELD(SflpOdrRegister, sflp_game_odr, SflpOdrRegister::SflpGameOdr)
DEFINE_REGOUT(SflpOdrRegister)

// ----------- FsmOdrRegister
DEFINE_FIELD(FsmOdrRegister, fsm_odr, FsmOdrRegister::FsmOdr)
DEFINE_REGOUT(FsmOdrRegister)

// ----------- MlcOdrRegister
DEFINE_FIELD(MlcOdrRegister, mlc_odr, MlcOdrRegister::MlcOdr)
DEFINE_REGOUT(MlcOdrRegister)

// ----------- EmbFuncInitARegister
DEFINE_FIELD(EmbFuncInitARegister, mlc_before_fsm_init, bool)
DEFINE_FIELD(EmbFuncInitARegister, sig_mot_init, bool)
DEFINE_FIELD(EmbFuncInitARegister, tilt_init, bool)
DEFINE_FIELD(EmbFuncInitARegister, step_det_init, bool)
DEFINE_FIELD(EmbFuncInitARegister, sflp_game_init, bool)
DEFINE_REGOUT(EmbFuncInitARegister)

// ----------- EmbFuncInitBRegister
DEFINE_FIELD(EmbFuncInitBRegister, mlc_init, bool)
DEFINE_FIELD(EmbFuncInitBRegister, fifo_compr_init, bool)
DEFINE_FIELD(EmbFuncInitBRegister, fsm_init, bool)
DEFINE_REGOUT(EmbFuncInitBRegister)

    private:
        inline static const char *TAG = "LSM6DSV16X-EMB_CTRL";
    };

} // namespace lsm6dsv16x
