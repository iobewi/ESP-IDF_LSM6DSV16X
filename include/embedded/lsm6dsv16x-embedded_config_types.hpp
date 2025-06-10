#pragma once

#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{
DEFINE_GENERIC_REGISTER_ADDR(PageSelRegister, uint8_t, 0x02)
    public:
        // Setters
        void page_sel(uint8_t v) { set_field<0, 0, 4>(v); } // PAGE_SEL[3:0]

        // Getters
        uint8_t page_sel() const { return get_field<0, 0, 4, uint8_t>(); }

        // Helpers (optionnel)
        enum class Page : uint8_t
        {
            BASE = 0x0,
            EMB_FUNC = 0x1,
            SENSOR_HUB = 0x2,
            MLC = 0x3,
            FSM = 0x4,
            ADVANCED_FEATURES = 0x5,
            // Tu peux ajouter les pages spécifiques selon la datasheet complète
        };

        void page_sel_enum(Page p) { page_sel(static_cast<uint8_t>(p)); }
        Page page_sel_enum() const { return static_cast<Page>(page_sel()); }

    private:
        inline static const char *TAG = "LSM6DSV16X_PAGE_SEL";
        static const char *to_string(Page p);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncEnARegister, uint8_t, 0x04)
    public:
        // Setters
        void mlc_before_fsm_en(bool v) { set_flag<0, 7>(v); }
        void sign_motion_en(bool v) { set_flag<0, 5>(v); }
        void tilt_en(bool v) { set_flag<0, 4>(v); }
        void pedo_en(bool v) { set_flag<0, 3>(v); }
        void sflp_game_en(bool v) { set_flag<0, 1>(v); }

        // Getters
        bool mlc_before_fsm_en() const { return get_flag<0, 7>(); }
        bool sign_motion_en() const { return get_flag<0, 5>(); }
        bool tilt_en() const { return get_flag<0, 4>(); }
        bool pedo_en() const { return get_flag<0, 3>(); }
        bool sflp_game_en() const { return get_flag<0, 1>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_EN_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncEnBRegister, uint8_t, 0x05)
    public:
        // Setters
        void mlc_en(bool v) { set_flag<0, 4>(v); }
        void fifo_compr_en(bool v) { set_flag<0, 3>(v); }
        void fsm_en(bool v) { set_flag<0, 1>(v); }

        // Getters
        bool mlc_en() const { return get_flag<0, 4>(); }
        bool fifo_compr_en() const { return get_flag<0, 3>(); }
        bool fsm_en() const { return get_flag<0, 1>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_EN_B";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(PageAddressRegister, uint8_t, 0x08)
    public:
        // Setter
        void page_addr(uint8_t v) { raw_ = v; }

        // Getter
        uint8_t page_addr() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_PAGE_ADDRESS";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(PageValueRegister, uint8_t, 0x09)
    public:
        // Setter
        void page_value(uint8_t v) { raw_ = v; }

        // Getter
        uint8_t page_value() const { return raw_; }

    private:
        inline static const char *TAG = "LSM6DSV16X_PAGE_VALUE";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncInt1Register, uint8_t, 0x0A)
    public:
        // Setters
        void int1_fsm_lc(bool v) { set_flag<0, 7>(v); }
        void int1_sig_mot(bool v) { set_flag<0, 5>(v); }
        void int1_tilt(bool v) { set_flag<0, 4>(v); }
        void int1_step_detector(bool v) { set_flag<0, 3>(v); }

        // Getters
        bool int1_fsm_lc() const { return get_flag<0, 7>(); }
        bool int1_sig_mot() const { return get_flag<0, 5>(); }
        bool int1_tilt() const { return get_flag<0, 4>(); }
        bool int1_step_detector() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_INT1";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmInt1Register, uint8_t, 0x0B)
    public:
        // Setters
        void int1_fsm1(bool v) { set_flag<0, 0>(v); }
        void int1_fsm2(bool v) { set_flag<0, 1>(v); }
        void int1_fsm3(bool v) { set_flag<0, 2>(v); }
        void int1_fsm4(bool v) { set_flag<0, 3>(v); }
        void int1_fsm5(bool v) { set_flag<0, 4>(v); }
        void int1_fsm6(bool v) { set_flag<0, 5>(v); }
        void int1_fsm7(bool v) { set_flag<0, 6>(v); }
        void int1_fsm8(bool v) { set_flag<0, 7>(v); }

        // Getters
        bool int1_fsm1() const { return get_flag<0, 0>(); }
        bool int1_fsm2() const { return get_flag<0, 1>(); }
        bool int1_fsm3() const { return get_flag<0, 2>(); }
        bool int1_fsm4() const { return get_flag<0, 3>(); }
        bool int1_fsm5() const { return get_flag<0, 4>(); }
        bool int1_fsm6() const { return get_flag<0, 5>(); }
        bool int1_fsm7() const { return get_flag<0, 6>(); }
        bool int1_fsm8() const { return get_flag<0, 7>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_INT1";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(MlcInt1Register, uint8_t, 0x0D)
    public:
        // Setters
        void int1_mlc1(bool v) { set_flag<0, 0>(v); }
        void int1_mlc2(bool v) { set_flag<0, 1>(v); }
        void int1_mlc3(bool v) { set_flag<0, 2>(v); }
        void int1_mlc4(bool v) { set_flag<0, 3>(v); }

        // Getters
        bool int1_mlc1() const { return get_flag<0, 0>(); }
        bool int1_mlc2() const { return get_flag<0, 1>(); }
        bool int1_mlc3() const { return get_flag<0, 2>(); }
        bool int1_mlc4() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC_INT1";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncInt2Register, uint8_t, 0x0E)
    public:
        // Setters
        void int2_fsm_lc(bool v) { set_flag<0, 7>(v); }
        void int2_sig_mot(bool v) { set_flag<0, 5>(v); }
        void int2_tilt(bool v) { set_flag<0, 4>(v); }
        void int2_step_detector(bool v) { set_flag<0, 3>(v); }

        // Getters
        bool int2_fsm_lc() const { return get_flag<0, 7>(); }
        bool int2_sig_mot() const { return get_flag<0, 5>(); }
        bool int2_tilt() const { return get_flag<0, 4>(); }
        bool int2_step_detector() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_INT2";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmInt2Register, uint8_t, 0x0F)
    public:
        // Setters
        void int2_fsm1(bool v) { set_flag<0, 0>(v); }
        void int2_fsm2(bool v) { set_flag<0, 1>(v); }
        void int2_fsm3(bool v) { set_flag<0, 2>(v); }
        void int2_fsm4(bool v) { set_flag<0, 3>(v); }
        void int2_fsm5(bool v) { set_flag<0, 4>(v); }
        void int2_fsm6(bool v) { set_flag<0, 5>(v); }
        void int2_fsm7(bool v) { set_flag<0, 6>(v); }
        void int2_fsm8(bool v) { set_flag<0, 7>(v); }

        // Getters
        bool int2_fsm1() const { return get_flag<0, 0>(); }
        bool int2_fsm2() const { return get_flag<0, 1>(); }
        bool int2_fsm3() const { return get_flag<0, 2>(); }
        bool int2_fsm4() const { return get_flag<0, 3>(); }
        bool int2_fsm5() const { return get_flag<0, 4>(); }
        bool int2_fsm6() const { return get_flag<0, 5>(); }
        bool int2_fsm7() const { return get_flag<0, 6>(); }
        bool int2_fsm8() const { return get_flag<0, 7>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_INT2";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(MlcInt2Register, uint8_t, 0x11)
    public:
        // Setters
        void int2_mlc1(bool v) { set_flag<0, 0>(v); }
        void int2_mlc2(bool v) { set_flag<0, 1>(v); }
        void int2_mlc3(bool v) { set_flag<0, 2>(v); }
        void int2_mlc4(bool v) { set_flag<0, 3>(v); }

        // Getters
        bool int2_mlc1() const { return get_flag<0, 0>(); }
        bool int2_mlc2() const { return get_flag<0, 1>(); }
        bool int2_mlc3() const { return get_flag<0, 2>(); }
        bool int2_mlc4() const { return get_flag<0, 3>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC_INT2";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(PageRwRegister, uint8_t, 0x17)
    public:
        // Setters
        void emb_func_lir(bool v) { set_flag<0, 7>(v); }
        void page_write(bool v) { set_flag<0, 6>(v); }
        void page_read(bool v) { set_flag<0, 5>(v); }

        // Getters
        bool emb_func_lir() const { return get_flag<0, 7>(); }
        bool page_write() const { return get_flag<0, 6>(); }
        bool page_read() const { return get_flag<0, 5>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_PAGE_RW";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncFifoEnARegister, uint8_t, 0x44)
    public:
        // Setters
        void mlc_fifo_en(bool v) { set_flag<0, 7>(v); }
        void step_counter_fifo_en(bool v) { set_flag<0, 6>(v); }
        void sflp_gbias_fifo_en(bool v) { set_flag<0, 5>(v); }
        void sflp_gravity_fifo_en(bool v) { set_flag<0, 4>(v); }
        void sflp_game_fifo_en(bool v) { set_flag<0, 2>(v); }

        // Getters
        bool mlc_fifo_en() const { return get_flag<0, 7>(); }
        bool step_counter_fifo_en() const { return get_flag<0, 6>(); }
        bool sflp_gbias_fifo_en() const { return get_flag<0, 5>(); }
        bool sflp_gravity_fifo_en() const { return get_flag<0, 4>(); }
        bool sflp_game_fifo_en() const { return get_flag<0, 2>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_FIFO_EN_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncFifoEnBRegister, uint8_t, 0x45)
    public:
        // Setter
        void mlc_filter_feature_fifo_en(bool v) { set_flag<0, 0>(v); }

        // Getter
        bool mlc_filter_feature_fifo_en() const { return get_flag<0, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_FIFO_EN_B";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmEnableRegister, uint8_t, 0x46)
    public:
        // Setters
        void fsm1_en(bool v) { set_flag<0, 0>(v); }
        void fsm2_en(bool v) { set_flag<0, 1>(v); }
        void fsm3_en(bool v) { set_flag<0, 2>(v); }
        void fsm4_en(bool v) { set_flag<0, 3>(v); }
        void fsm5_en(bool v) { set_flag<0, 4>(v); }
        void fsm6_en(bool v) { set_flag<0, 5>(v); }
        void fsm7_en(bool v) { set_flag<0, 6>(v); }
        void fsm8_en(bool v) { set_flag<0, 7>(v); }

        // Getters
        bool fsm1_en() const { return get_flag<0, 0>(); }
        bool fsm2_en() const { return get_flag<0, 1>(); }
        bool fsm3_en() const { return get_flag<0, 2>(); }
        bool fsm4_en() const { return get_flag<0, 3>(); }
        bool fsm5_en() const { return get_flag<0, 4>(); }
        bool fsm6_en() const { return get_flag<0, 5>(); }
        bool fsm7_en() const { return get_flag<0, 6>(); }
        bool fsm8_en() const { return get_flag<0, 7>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_ENABLE";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmLongCounterRegister, uint16_t, 0x48)
    public:
        // Setter
        void fsm_long_counter(uint16_t v) { raw_ = v; }

        // Getter
        uint16_t fsm_long_counter() const { return raw_; }
    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_LONG_COUNTER";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(IntAckMaskRegister, uint8_t, 0x4B)
    public:
        // Setters
        void iack_mask0(bool v) { set_flag<0, 0>(v); }
        void iack_mask1(bool v) { set_flag<0, 1>(v); }
        void iack_mask2(bool v) { set_flag<0, 2>(v); }
        void iack_mask3(bool v) { set_flag<0, 3>(v); }
        void iack_mask4(bool v) { set_flag<0, 4>(v); }
        void iack_mask5(bool v) { set_flag<0, 5>(v); }
        void iack_mask6(bool v) { set_flag<0, 6>(v); }
        void iack_mask7(bool v) { set_flag<0, 7>(v); }

        // Getters
        bool iack_mask0() const { return get_flag<0, 0>(); }
        bool iack_mask1() const { return get_flag<0, 1>(); }
        bool iack_mask2() const { return get_flag<0, 2>(); }
        bool iack_mask3() const { return get_flag<0, 3>(); }
        bool iack_mask4() const { return get_flag<0, 4>(); }
        bool iack_mask5() const { return get_flag<0, 5>(); }
        bool iack_mask6() const { return get_flag<0, 6>(); }
        bool iack_mask7() const { return get_flag<0, 7>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_INT_ACK_MASK";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(SflpOdrRegister, uint8_t, 0x5E)
    public:
        enum class SflpGameOdr : uint8_t
        {
            HZ_15   = 0b000,
            HZ_30   = 0b001,
            HZ_60   = 0b010,
            HZ_120  = 0b011, // default
            HZ_240  = 0b100,
            HZ_480  = 0b101
        };

        // Setter
        void sflp_game_odr(SflpGameOdr v) { set_field<0, 3, 3>(v); }

        // Getter
        SflpGameOdr sflp_game_odr() const { return get_field<0, 3, 3, SflpGameOdr>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_SFLP_ODR";

        static const char *to_string(SflpGameOdr odr);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(FsmOdrRegister, uint8_t, 0x5F)
    public:
        enum class FsmOdr : uint8_t
        {
            HZ_15   = 0b000,
            HZ_30   = 0b001, // default
            HZ_60   = 0b010,
            HZ_120  = 0b011,
            HZ_240  = 0b100,
            HZ_480  = 0b101,
            HZ_960  = 0b110,
        };

        // Setter
        void fsm_odr(FsmOdr v) { set_field<0, 3, 3>(v); }

        // Getter
        FsmOdr fsm_odr() const { return get_field<0, 3, 3, FsmOdr>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_FSM_ODR";
        static const char *to_string(FsmOdr odr);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(MlcOdrRegister, uint8_t, 0x60)
    public:
        enum class MlcOdr : uint8_t
        {
            HZ_15  = 0b000,
            HZ_30  = 0b001, // default
            HZ_60  = 0b010,
            HZ_120 = 0b011,
            HZ_240 = 0b100,
        };

        // Setter
        void mlc_odr(MlcOdr v) { set_field<0, 3, 3>(v); }

        // Getter
        MlcOdr mlc_odr() const { return get_field<0, 3, 3, MlcOdr>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_MLC_ODR";
        static const char *to_string(MlcOdr odr);

END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncInitARegister, uint8_t, 0x66)
    public:
        // Setters
        void mlc_before_fsm_init(bool v) { set_flag<0, 7>(v); }
        void sig_mot_init(bool v)        { set_flag<0, 5>(v); }
        void tilt_init(bool v)           { set_flag<0, 4>(v); }
        void step_det_init(bool v)       { set_flag<0, 3>(v); }
        void sflp_game_init(bool v)      { set_flag<0, 1>(v); }

        // Getters
        bool mlc_before_fsm_init() const { return get_flag<0, 7>(); }
        bool sig_mot_init()        const { return get_flag<0, 5>(); }
        bool tilt_init()           const { return get_flag<0, 4>(); }
        bool step_det_init()       const { return get_flag<0, 3>(); }
        bool sflp_game_init()      const { return get_flag<0, 1>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_INIT_A";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(EmbFuncInitBRegister, uint8_t, 0x67)
    public:
        // Setters
        void mlc_init(bool v)         { set_flag<0, 5>(v); }
        void fifo_compr_init(bool v)  { set_flag<0, 4>(v); }
        void fsm_init(bool v)         { set_flag<0, 1>(v); }

        // Getters
        bool mlc_init() const         { return get_flag<0, 5>(); }
        bool fifo_compr_init() const  { return get_flag<0, 4>(); }
        bool fsm_init() const         { return get_flag<0, 1>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_EMB_FUNC_INIT_B";
END_REGISTER


} // namespace lsm6dsv16x
