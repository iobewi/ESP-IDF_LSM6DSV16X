#include "ctrl/lsm6dsv16x-ctrl_types.hpp"

namespace lsm6dsv16x
{

    // Conversion enum Odr -> string
    const char *Ctrl1Register::to_string(Odr odr)
    {
        switch (odr)
        {
        case Odr::POWER_DOWN:
            return "Power-down";
        case Odr::ODR_1_875Hz:
            return "1.875 Hz";
        case Odr::ODR_7_5Hz:
            return "7.5 Hz";
        case Odr::ODR_15Hz:
            return "15 Hz";
        case Odr::ODR_30Hz:
            return "30 Hz";
        case Odr::ODR_60Hz:
            return "60 Hz";
        case Odr::ODR_120Hz:
            return "120 Hz";
        case Odr::ODR_240Hz:
            return "240 Hz";
        case Odr::ODR_480Hz:
            return "480 Hz";
        case Odr::ODR_960Hz:
            return "960 Hz";
        case Odr::ODR_1920Hz:
            return "1.92 kHz";
        case Odr::ODR_3840Hz:
            return "3.84 kHz";
        case Odr::ODR_7680Hz:
            return "7.68 kHz";
        default:
            return "Reserved";
        }
    }

    // Conversion enum OpMode -> string
    const char *Ctrl1Register::to_string(OpMode mode)
    {
        switch (mode)
        {
        case OpMode::HIGH_PERFORMANCE:
            return "High-performance";
        case OpMode::HIGH_ACCURACY_ODR:
            return "High-accuracy ODR";
        case OpMode::RESERVED:
            return "Reserved";
        case OpMode::ODR_TRIGGERED:
            return "ODR-triggered";
        case OpMode::LOW_POWER_1:
            return "Low-power 1";
        case OpMode::LOW_POWER_2:
            return "Low-power 2";
        case OpMode::LOW_POWER_3:
            return "Low-power 3";
        case OpMode::NORMAL:
            return "Normal";
        default:
            return "Unknown";
        }
    }

    void Ctrl1Register::log() const
    {
        ESP_LOGI(TAG, "CTRL1: raw=0x%02X odr_xl=%s op_mode_xl=%s",
                 raw_,
                 to_string(odr_xl()),
                 to_string(op_mode_xl()));
    }

    std::string Ctrl1Register::to_json() const
    {
        return std::string("{") +
               "\"odr_xl\":\"" + to_string(odr_xl()) + "\"," +
               "\"op_mode_xl\":\"" + to_string(op_mode_xl()) + "\"" +
               "}";
    }

    const char *Ctrl2Register::to_string(Odr odr)
    {
        switch (odr)
        {
        case Odr::POWER_DOWN:
            return "Power-down";
        case Odr::ODR_7_5Hz:
            return "7.5 Hz";
        case Odr::ODR_15Hz:
            return "15 Hz";
        case Odr::ODR_30Hz:
            return "30 Hz";
        case Odr::ODR_60Hz:
            return "60 Hz";
        case Odr::ODR_120Hz:
            return "120 Hz";
        case Odr::ODR_240Hz:
            return "240 Hz";
        case Odr::ODR_480Hz:
            return "480 Hz";
        case Odr::ODR_960Hz:
            return "960 Hz";
        case Odr::ODR_1_92kHz:
            return "1.92 kHz";
        case Odr::ODR_3_84kHz:
            return "3.84 kHz";
        case Odr::ODR_7_68kHz:
            return "7.68 kHz";
        default:
            return "Reserved";
        }
    }

    const char *Ctrl2Register::to_string(OpMode mode)
    {
        switch (mode)
        {
        case OpMode::HIGH_PERFORMANCE:
            return "High-performance";
        case OpMode::HIGH_ACCURACY_ODR:
            return "High-accuracy ODR";
        case OpMode::RESERVED_1:
            return "Reserved 1";
        case OpMode::ODR_TRIGGERED:
            return "ODR-triggered";
        case OpMode::SLEEP:
            return "Sleep";
        case OpMode::LOW_POWER:
            return "Low-power";
        case OpMode::RESERVED_2:
            return "Reserved 2";
        case OpMode::RESERVED_3:
            return "Reserved 3";
        default:
            return "Unknown";
        }
    }

    void Ctrl2Register::log() const
    {
        ESP_LOGI(TAG, "CTRL2: raw=0x%02X odr_g=%s op_mode_g=%s",
                 raw_,
                 to_string(odr_g()),
                 to_string(op_mode_g()));
    }

    std::string Ctrl2Register::to_json() const
    {
        return std::string("{") +
               "\"odr_g\":\"" + to_string(odr_g()) + "\"," +
               "\"op_mode_g\":\"" + to_string(op_mode_g()) + "\"" +
               "}";
    }

    void Ctrl3Register::log() const
    {
        ESP_LOGI(TAG, "CTRL3: raw=0x%02X boot=%d bdu=%d if_inc=%d sw_reset=%d",
                 raw_, boot(), bdu(), if_inc(), sw_reset());
    }

    std::string Ctrl3Register::to_json() const
    {
        return std::string("{") +
               "\"boot\":" + (boot() ? "true" : "false") + "," +
               "\"bdu\":" + (bdu() ? "true" : "false") + "," +
               "\"if_inc\":" + (if_inc() ? "true" : "false") + "," +
               "\"sw_reset\":" + (sw_reset() ? "true" : "false") +
               "}";
    }

    void Ctrl4Register::log() const
    {
        ESP_LOGI(TAG, "CTRL4: raw=0x%02X int2_on_int1=%d drdy_mask=%d int2_drdy_temp=%d drdy_pulsed=%d int2_in_lh=%d",
                 raw_, int2_on_int1(), drdy_mask(), int2_drdy_temp(), drdy_pulsed(), int2_in_lh());
    }

    std::string Ctrl4Register::to_json() const
    {
        return std::string("{") +
               "\"int2_on_int1\":" + (int2_on_int1() ? "true" : "false") + "," +
               "\"drdy_mask\":" + (drdy_mask() ? "true" : "false") + "," +
               "\"int2_drdy_temp\":" + (int2_drdy_temp() ? "true" : "false") + "," +
               "\"drdy_pulsed\":" + (drdy_pulsed() ? "true" : "false") + "," +
               "\"int2_in_lh\":" + (int2_in_lh() ? "true" : "false") +
               "}";
    }

    const char *Ctrl5Register::to_string(BusActSel v)
    {
        switch (v)
        {
        case BusActSel::US_2:
            return "2us";
        case BusActSel::US_50:
            return "50us";
        case BusActSel::MS_1:
            return "1ms";
        case BusActSel::MS_25:
            return "25ms";
        default:
            return "Unknown";
        }
    }

    void Ctrl5Register::log() const
    {
        ESP_LOGI(TAG, "CTRL5: raw=0x%02X bus_act_sel=%s int_en_i3c=%d",
                 raw_, to_string(bus_act_sel()), int_en_i3c());
    }

    std::string Ctrl5Register::to_json() const
    {
        return std::string("{") +
               "\"bus_act_sel\":\"" + to_string(bus_act_sel()) + "\"," +
               "\"int_en_i3c\":" + (int_en_i3c() ? "true" : "false") +
               "}";
    }

    const char *Ctrl6Register::to_string(Lpf1GBw v)
    {
        switch (v)
        {
        case Lpf1GBw::BW_0:
            return "BW_0 (24.6–281 Hz)";
        case Lpf1GBw::BW_1:
            return "BW_1 (24.6–213 Hz)";
        case Lpf1GBw::BW_2:
            return "BW_2 (24.6–156 Hz)";
        case Lpf1GBw::BW_3:
            return "BW_3 (24.6–407 Hz)";
        case Lpf1GBw::BW_4:
            return "BW_4 (24.6–102 Hz)";
        case Lpf1GBw::BW_5:
            return "BW_5 (12.1–58.3 Hz)";
        case Lpf1GBw::BW_6:
            return "BW_6 (12.1–28.8 Hz)";
        case Lpf1GBw::BW_7:
            return "BW_7 (12.1–14.4 Hz)";
        default:
            return "Unknown";
        }
    }

    const char *Ctrl6Register::to_string(FsG v)
    {
        switch (v)
        {
        case FsG::DPS_125:
            return "±125 dps";
        case FsG::DPS_250:
            return "±250 dps";
        case FsG::DPS_500:
            return "±500 dps";
        case FsG::DPS_1000:
            return "±1000 dps";
        case FsG::DPS_2000:
            return "±2000 dps";
        case FsG::DPS_4000:
            return "±4000 dps";
        default:
            return "Reserved";
        }
    }

    void Ctrl6Register::log() const
    {
        ESP_LOGI(TAG, "CTRL6: raw=0x%02X lpf1_g_bw=%s fs_g=%s",
                 raw_,
                 to_string(lpf1_g_bw()),
                 to_string(fs_g()));
    }

    std::string Ctrl6Register::to_json() const
    {
        return std::string("{") +
               "\"lpf1_g_bw\":\"" + to_string(lpf1_g_bw()) + "\"," +
               "\"fs_g\":\"" + to_string(fs_g()) + "\"" +
               "}";
    }

    const char *Ctrl7Register::to_string(AhQvarCZin v)
    {
        switch (v)
        {
        case AhQvarCZin::G2_4:
            return "2.4 GΩ";
        case AhQvarCZin::M730:
            return "730 MΩ";
        case AhQvarCZin::M300:
            return "300 MΩ";
        case AhQvarCZin::M235:
            return "235 MΩ";
        default:
            return "Unknown";
        }
    }

    void Ctrl7Register::log() const
    {
        ESP_LOGI(TAG, "CTRL7: raw=0x%02X ah_qvar_en=%d int2_drdy_ah_qvar=%d ah_qvar_c_zin=%s lpf1_g_en=%d",
                 raw_, ah_qvar_en(), int2_drdy_ah_qvar(), to_string(ah_qvar_c_zin()), lpf1_g_en());
    }

    std::string Ctrl7Register::to_json() const
    {
        return std::string("{") +
               "\"ah_qvar_en\":" + (ah_qvar_en() ? "true" : "false") + "," +
               "\"int2_drdy_ah_qvar\":" + (int2_drdy_ah_qvar() ? "true" : "false") + "," +
               "\"ah_qvar_c_zin\":\"" + to_string(ah_qvar_c_zin()) + "\"," +
               "\"lpf1_g_en\":" + (lpf1_g_en() ? "true" : "false") +
               "}";
    }

    const char *Ctrl8Register::to_string(HpLpf2XlBw v)
    {
        switch (v)
        {
        case HpLpf2XlBw::ODR_4:
            return "ODR/4";
        case HpLpf2XlBw::ODR_10:
            return "ODR/10";
        case HpLpf2XlBw::ODR_20:
            return "ODR/20";
        case HpLpf2XlBw::ODR_45:
            return "ODR/45";
        case HpLpf2XlBw::ODR_100:
            return "ODR/100";
        case HpLpf2XlBw::ODR_200:
            return "ODR/200";
        case HpLpf2XlBw::ODR_400:
            return "ODR/400";
        case HpLpf2XlBw::ODR_800:
            return "ODR/800";
        default:
            return "Unknown";
        }
    }

    const char *Ctrl8Register::to_string(FsXl v)
    {
        switch (v)
        {
        case FsXl::G2:
            return "±2g";
        case FsXl::G4:
            return "±4g";
        case FsXl::G8:
            return "±8g";
        case FsXl::G16:
            return "±16g";
        default:
            return "Unknown";
        }
    }

    void Ctrl8Register::log() const
    {
        ESP_LOGI(TAG, "CTRL8: raw=0x%02X hp_lpf2_xl_bw=%s xl_dualc_en=%d fs_xl=%s",
                 raw_, to_string(hp_lpf2_xl_bw()), xl_dualc_en(), to_string(fs_xl()));
    }

    std::string Ctrl8Register::to_json() const
    {
        return std::string("{") +
               "\"hp_lpf2_xl_bw\":\"" + to_string(hp_lpf2_xl_bw()) + "\"," +
               "\"xl_dualc_en\":" + (xl_dualc_en() ? "true" : "false") + "," +
               "\"fs_xl\":\"" + to_string(fs_xl()) + "\"" +
               "}";
    }

    const char *Ctrl9Register::to_string(UsrOffW v)
    {
        switch (v)
        {
        case UsrOffW::POW_10:
            return "2^-10 g/LSB";
        case UsrOffW::POW_6:
            return "2^-6 g/LSB";
        default:
            return "Unknown";
        }
    }

    void Ctrl9Register::log() const
    {
        ESP_LOGI(TAG,
                 "CTRL9: raw=0x%02X hp_ref_mode_xl=%d xl_fastsettl_mode=%d hp_slope_xl_en=%d lpf2_xl_en=%d usr_off_w=%s usr_off_on_out=%d",
                 raw_,
                 hp_ref_mode_xl(),
                 xl_fastsettl_mode(),
                 hp_slope_xl_en(),
                 lpf2_xl_en(),
                 to_string(usr_off_w()),
                 usr_off_on_out());
    }

    std::string Ctrl9Register::to_json() const
    {
        return std::string("{") +
               "\"hp_ref_mode_xl\":" + (hp_ref_mode_xl() ? "true" : "false") + "," +
               "\"xl_fastsettl_mode\":" + (xl_fastsettl_mode() ? "true" : "false") + "," +
               "\"hp_slope_xl_en\":" + (hp_slope_xl_en() ? "true" : "false") + "," +
               "\"lpf2_xl_en\":" + (lpf2_xl_en() ? "true" : "false") + "," +
               "\"usr_off_w\":\"" + to_string(usr_off_w()) + "\"," +
               "\"usr_off_on_out\":" + (usr_off_on_out() ? "true" : "false") +
               "}";
    }

    const char *Ctrl10Register::to_string(StG v)
    {
        switch (v)
        {
        case StG::NORMAL:
            return "Normal";
        case StG::POS:
            return "Positive self-test";
        case StG::NEG:
            return "Negative self-test";
        case StG::RESERVED:
            return "Reserved";
        default:
            return "Unknown";
        }
    }

    const char *Ctrl10Register::to_string(StXl v)
    {
        switch (v)
        {
        case StXl::NORMAL:
            return "Normal";
        case StXl::POS:
            return "Positive self-test";
        case StXl::NEG:
            return "Negative self-test";
        case StXl::RESERVED:
            return "Reserved";
        default:
            return "Unknown";
        }
    }

    void Ctrl10Register::log() const
    {
        ESP_LOGI(TAG, "CTRL10: raw=0x%02X emb_func_debug=%d st_g=%s st_xl=%s",
                 raw_, emb_func_debug(), to_string(st_g()), to_string(st_xl()));
    }

    std::string Ctrl10Register::to_json() const
    {
        return std::string("{") +
               "\"emb_func_debug\":" + (emb_func_debug() ? "true" : "false") + "," +
               "\"st_g\":\"" + to_string(st_g()) + "\"," +
               "\"st_xl\":\"" + to_string(st_xl()) + "\"" +
               "}";
    }

} // namespace lsm6dsv16x
