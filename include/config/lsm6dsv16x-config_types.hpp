#pragma once

#include <cstdint>
#include <string>
#include "esp_log.h"

#include "lsm6dsv16x-register_base.hpp"

namespace lsm6dsv16x
{

    DEFINE_GENERIC_REGISTER_ADDR(FuncCfgAccessRegister, uint8_t, 0x01)
        public:
            // Setters
            void emb_func_reg_access(bool v) { set_flag<0, 7>(v); }
            void shub_reg_access(bool v) { set_flag<0, 6>(v); }
            void fsm_wr_ctrl_en(bool v) { set_flag<0, 4>(v); }
            void sw_por(bool v) { set_flag<0, 3>(v); }
            void spi2_reset(bool v) { set_flag<0, 2>(v); }
            void ois_ctrl_from_ui(bool v) { set_flag<0, 0>(v); }
            // Getters
            bool emb_func_reg_access() const { return get_flag<0, 7>(); }
            bool shub_reg_access() const { return get_flag<0, 6>(); }
            bool fsm_wr_ctrl_en() const { return get_flag<0, 4>(); }
            bool sw_por() const { return get_flag<0, 3>(); }
            bool spi2_reset() const { return get_flag<0, 2>(); }
            bool ois_ctrl_from_ui() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_FUNC_CFG_ACCESS";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(PinCtrlRegister, uint8_t, 0x02)
        public:
            enum class IbhrPorEn : uint8_t
            {
                CONFIG_RESET = 0, // 0: configuration reset (SW reset + dynamic address reset)
                GLOBAL_RESET = 1  // 1: global reset (POR reset)
            };

            // Setters
            void ois_pu_dis(bool v) { set_flag<0, 7>(v); }
            void sdo_pu_en(bool v) { set_flag<0, 6>(v); }
            void ibhr_por_en(IbhrPorEn v) { set_field<0, 1, 1>(v); }
            // Getters
            bool ois_pu_dis() const { return get_flag<0, 7>(); }
            bool sdo_pu_en() const { return get_flag<0, 6>(); }
            IbhrPorEn ibhr_por_en() const { return get_field<0, 1, 1, IbhrPorEn>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_PIN_CTRL";
            static const char *to_string(IbhrPorEn v);
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(IfCfgRegister, uint8_t, 0x03)
        public:
            // Setters
            void sda_pu_en(bool v) { set_flag<0, 7>(v); }
            void shub_pu_en(bool v) { set_flag<0, 6>(v); }
            void asf_ctrl(bool v) { set_flag<0, 5>(v); }
            void h_lactive(bool v) { set_flag<0, 4>(v); }
            void pp_od(bool v) { set_flag<0, 3>(v); }
            void sim(bool v) { set_flag<0, 2>(v); }
            void i2c_i3c_disable(bool v) { set_flag<0, 0>(v); }
            // Getters
            bool sda_pu_en() const { return get_flag<0, 7>(); }
            bool shub_pu_en() const { return get_flag<0, 6>(); }
            bool asf_ctrl() const { return get_flag<0, 5>(); }
            bool h_lactive() const { return get_flag<0, 4>(); }
            bool pp_od() const { return get_flag<0, 3>(); }
            bool sim() const { return get_flag<0, 2>(); }
            bool i2c_i3c_disable() const { return get_flag<0, 0>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_IF_CFG";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(OdrTrigCfgRegister, uint8_t, 0x06)
            // Setter
            void odr_trig_nodr(uint8_t v) { raw_ = v; }
            // Getter
            uint8_t odr_trig_nodr() const { return raw_; }

        private:
            inline static const char *TAG = "LSM6DSV16X_ODR_TRIG_CFG";
    END_REGISTER

    DEFINE_GENERIC_REGISTER_ADDR(FifoCtrlRegister, uint32_t, 0x07)
        public:
            // Enum Class
            enum class UncomprRate : uint8_t
            {
                UNFORCED = 0b00,
                EVERY_8 = 0b01,
                EVERY_16 = 0b10,
                EVERY_32 = 0b11,
            };
            enum class BdrGy : uint8_t
            {
                NOT_BATCHED = 0b0000,
                HZ_1_875 = 0b0001,
                HZ_7_5 = 0b0010,
                HZ_15 = 0b0011,
                HZ_30 = 0b0100,
                HZ_60 = 0b0101,
                HZ_120 = 0b0110,
                HZ_240 = 0b0111,
                HZ_480 = 0b1000,
                HZ_960 = 0b1001,
                HZ_1_92K = 0b1010,
                HZ_3_84K = 0b1011,
                HZ_7_68K = 0b1100,
                RESERVED = 0b1101
            };
            enum class BdrXl : uint8_t
            {
                NOT_BATCHED = 0b0000,
                HZ_1_875 = 0b0001,
                HZ_7_5 = 0b0010,
                HZ_15 = 0b0011,
                HZ_30 = 0b0100,
                HZ_60 = 0b0101,
                HZ_120 = 0b0110,
                HZ_240 = 0b0111,
                HZ_480 = 0b1000,
                HZ_960 = 0b1001,
                HZ_1_92K = 0b1010,
                HZ_3_84K = 0b1011,
                HZ_7_68K = 0b1100,
                RESERVED = 0b1101
            };

            enum class DecTsBatch : uint8_t
            {
                NONE = 0b00,
                BY_8 = 0b01,
                BY_16 = 0b10,
                BY_32 = 0b11
            };
            enum class OdrTBatch : uint8_t
            {
                NOT_BATCHED = 0b00,
                HZ_1_875 = 0b01,
                HZ_15 = 0b10,
                HZ_60 = 0b11
            };

            enum class FifoMode : uint8_t
            {
                BYPASS = 0b000,
                FIFO = 0b001,
                CONT_WTM2FULL = 0b010,
                CONT2FIFO = 0b011,
                BYPASS2CONT = 0b100,
                RESERVED_101 = 0b101,
                CONTINUOUS = 0b110,
                BYPASS2FIFO = 0b111,
            };

            // Setter
            void wtm(uint8_t v) { set_field<0, 0, 8>(v); }

            void stop_on_wtm(bool v) { set_flag<1, 7>(v); }
            void fifo_compr_rt_en(bool v) { set_flag<1, 6>(v); }
            void odr_chg_en(bool v) { set_flag<1, 4>(v); }
            void uncompr_rate(UncomprRate v) { set_field<1, 2, 2>(v); }
            void xl_dualc_batch_from_fsm(bool v) { set_flag<1, 0>(v); }

            void bdr_gy(BdrGy v) { set_field<2, 4, 4>(v); }
            void bdr_xl(BdrXl v) { set_field<2, 0, 4>(v); }

            void dec_ts_batch(DecTsBatch v) { set_field<3, 6, 2>(v); }
            void odr_t_batch(OdrTBatch v) { set_field<3, 4, 2>(v); }
            void g_eis_fifo_en(bool v) { set_flag<3, 3>(v); }
            void fifo_mode(FifoMode v) { set_field<3, 0, 3>(v); }

            // Setter
            uint8_t wtm() const { return get_field<0, 0, 8, uint8_t>(); }

            bool stop_on_wtm() const { return get_flag<1, 7>(); }
            bool fifo_compr_rt_en() const { return get_flag<1, 6>(); }
            bool odr_chg_en() const { return get_flag<1, 4>(); }
            UncomprRate uncompr_rate() const { return get_field<1, 2, 2, UncomprRate>(); }
            bool xl_dualc_batch_from_fsm() const { return get_flag<1, 0>(); }

            BdrGy bdr_gy() const { return get_field<2, 4, 4, BdrGy>(); }
            BdrXl bdr_xl() const { return get_field<2, 0, 4, BdrXl>(); }

            DecTsBatch dec_ts_batch() const { return get_field<3, 6, 2, DecTsBatch>(); }
            OdrTBatch odr_t_batch() const { return get_field<3, 4, 2, OdrTBatch>(); }
            bool g_eis_fifo_en() const { return get_flag<3, 3>(); }
            FifoMode fifo_mode() const { return get_field<3, 0, 3, FifoMode>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_FIFO_CTRL";

            static const char *to_string(UncomprRate v);
            static const char *to_string(BdrGy v);
            static const char *to_string(BdrXl v);
            static const char *to_string(DecTsBatch v);
            static const char *to_string(OdrTBatch v);
            static const char *to_string(FifoMode v);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(CounterBdrRegister, uint16_t, 0x0B)
        public:
            // --- Enum pour le champ multi-bits ---
            enum class TrigCounterBdr : uint8_t
            {
                ACCEL = 0b00,
                GYRO = 0b01,
                EIS = 0b10,
                EIS2 = 0b11 // Réservé, identique à EIS
            };

            // Setters
            void trig_counter_bdr(TrigCounterBdr v) { set_field<0, 4, 2>(v); }
            void cnt_bdr_th_h(uint8_t v) { set_field<0, 0, 2>(v); }

            void cnt_bdr_th_l(uint8_t v) { set_octet<1>(v); }

            // Getters
            TrigCounterBdr trig_counter_bdr() const { return get_field<0, 4, 2, TrigCounterBdr>(); }
            uint8_t cnt_bdr_th_h() const { return get_field<0, 0, 2, uint8_t>(); }
            
            uint8_t cnt_bdr_th_l() const { return get_octet<1>(); }

            // Helper
            uint16_t cnt_bdr_th() const
            { // sur 9 bits, si besoin
                return (cnt_bdr_th_h() << 8) | cnt_bdr_th_l();
            }
            void cnt_bdr_th(uint16_t v)
            {
                cnt_bdr_th_h((v >> 8) & 0x03); // Les 2 bits de poids fort (9:8)
                cnt_bdr_th_l(v & 0xFF);        // Les 8 bits de poids faible (7:0)
            }

        private:
            inline static const char *TAG = "LSM6DSV16X_COUNTER_BDR";
            static const char *to_string(TrigCounterBdr v);
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(IntCtrlRegister, uint16_t, 0x0D)
    public:
        // Setters
        void int1_cnt_bdr(bool v) { set_flag<0, 7>(v); }
        void int1_fifo_full(bool v) { set_flag<0, 6>(v); }
        void int1_fifo_ovr(bool v) { set_flag<0, 5>(v); }
        void int1_fifo_th(bool v) { set_flag<0, 4>(v); }
        void int1_drdy_g(bool v) { set_flag<0, 2>(v); }
        void int1_drdy_xl(bool v) { set_flag<0, 0>(v); }

        void int2_emb_func_endop(bool v) { set_flag<1, 7>(v); }
        void int2_cnt_bdr(bool v) { set_flag<1, 6>(v); }
        void int2_fifo_full(bool v) { set_flag<1, 5>(v); }
        void int2_fifo_ovr(bool v) { set_flag<1, 4>(v); }
        void int2_fifo_th(bool v) { set_flag<1, 3>(v); }
        void int2_drdy_g_eis(bool v) { set_flag<1, 2>(v); }
        void int2_drdy_g(bool v) { set_flag<1, 1>(v); }
        void int2_drdy_xl(bool v) { set_flag<1, 0>(v); }

        // Getters
        bool int1_cnt_bdr() const { return get_flag<0, 7>(); }
        bool int1_fifo_full() const { return get_flag<0, 6>(); }
        bool int1_fifo_ovr() const { return get_flag<0, 5>(); }
        bool int1_fifo_th() const { return get_flag<0, 4>(); }
        bool int1_drdy_g() const { return get_flag<0, 2>(); }
        bool int1_drdy_xl() const { return get_flag<0, 0>(); }

        bool int2_emb_func_endop() const { return get_flag<1, 7>(); }
        bool int2_cnt_bdr() const { return get_flag<1, 6>(); }
        bool int2_fifo_full() const { return get_flag<1, 5>(); }
        bool int2_fifo_ovr() const { return get_flag<1, 4>(); }
        bool int2_fifo_th() const { return get_flag<1, 3>(); }
        bool int2_drdy_g_eis() const { return get_flag<1, 2>(); }
        bool int2_drdy_g() const { return get_flag<1, 1>(); }
        bool int2_drdy_xl() const { return get_flag<1, 0>(); }

    private:
        inline static const char *TAG = "LSM6DSV16X_INT_CTRL";
END_REGISTER

DEFINE_GENERIC_REGISTER_ADDR(CtrlEisRegister, uint8_t, 0x6B)
        public:
            // Enum Class
            enum class OdrGEis : uint8_t
            {
                OFF = 0b00,
                HZ_1920 = 0b01,
                HZ_960 = 0b10,
                RESERVED = 0b11
            };

            enum class FsGEis : uint8_t
            {
                DPS_125 = 0b000,
                DPS_250 = 0b001,
                DPS_500 = 0b010,
                DPS_1000 = 0b011,
                DPS_2000 = 0b100,
                RESERVED_101 = 0b101,
                RESERVED_110 = 0b110,
                RESERVED_111 = 0b111,
            };
            
            // Setters
            void odr_g_eis(OdrGEis v) { set_field<0, 6, 2>(v); }
            void lpf_g_eis_bw(bool v) { set_flag<0, 5>(v); }
            void g_eis_on_g_ois_out_reg(bool v) { set_flag<0, 4>(v); }
            void fs_g_eis(FsGEis v) { set_field<0, 0, 3>(v); }

            // Getters
            OdrGEis odr_g_eis() const { return get_field<0, 6, 2, OdrGEis>(); }
            bool lpf_g_eis_bw() const { return get_flag<0, 5>(); }
            bool g_eis_on_g_ois_out_reg() const { return get_flag<0, 4>(); }
            FsGEis fs_g_eis() const { return get_field<0, 0, 3, FsGEis>(); }

        private:
            inline static const char *TAG = "LSM6DSV16X_CTRL_EIS";

            static const char *to_string(OdrGEis v);
            static const char *to_string(FsGEis v);
END_REGISTER

} // namespace lsm6dsv16x
