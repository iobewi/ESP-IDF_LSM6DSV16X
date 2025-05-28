#include "config/lsm6dsv16x-ui_types.hpp"

namespace lsm6dsv16x
{

void UiIntOisRegister::log() const
{
    ESP_LOGI(TAG, "UI_INT_OIS: raw=0x%02X", raw_);
    ESP_LOGI(TAG, "  INT2_DRDY_OIS: %d", int2_drdy_ois());
    ESP_LOGI(TAG, "  DRDY_MASK_OIS: %d", drdy_mask_ois());
    ESP_LOGI(TAG, "  ST_OIS_CLAMPDIS: %d", st_ois_clampdis());
}

std::string UiIntOisRegister::to_json() const
{
    return std::string("{")
        + "\"int2_drdy_ois\":" + std::to_string(int2_drdy_ois()) + ","
        + "\"drdy_mask_ois\":" + std::to_string(drdy_mask_ois()) + ","
        + "\"st_ois_clampdis\":" + std::to_string(st_ois_clampdis())
        + "}";
}

void UiCtrl1OisRegister::log() const
{
    ESP_LOGI(TAG, "UI_CTRL1_OIS: raw=0x%02X", raw_);
    ESP_LOGI(TAG, "  SIM_OIS: %d", sim_ois());
    ESP_LOGI(TAG, "  OIS_XL_EN: %d", ois_xl_en());
    ESP_LOGI(TAG, "  OIS_G_EN: %d", ois_g_en());
    ESP_LOGI(TAG, "  SPI2_READ_EN: %d", spi2_read_en());
}

std::string UiCtrl1OisRegister::to_json() const
{
    return std::string("{")
        + "\"sim_ois\":" + std::to_string(sim_ois()) + ","
        + "\"ois_xl_en\":" + std::to_string(ois_xl_en()) + ","
        + "\"ois_g_en\":" + std::to_string(ois_g_en()) + ","
        + "\"spi2_read_en\":" + std::to_string(spi2_read_en())
        + "}";
}

const char* UiCtrl2OisRegister::to_string(Lpf1GOisBw v)
{
    switch (v) {
    case Lpf1GOisBw::HZ_293: return "293 Hz";
    case Lpf1GOisBw::HZ_217: return "217 Hz";
    case Lpf1GOisBw::HZ_158: return "158 Hz";
    case Lpf1GOisBw::HZ_476: return "476 Hz";
    default: return "Unknown";
    }
}

const char* UiCtrl2OisRegister::to_string(FsGOis v)
{
    switch (v) {
    case FsGOis::DPS_125:   return "±125 dps";
    case FsGOis::DPS_250:   return "±250 dps";
    case FsGOis::DPS_500:   return "±500 dps";
    case FsGOis::DPS_1000:  return "±1000 dps";
    case FsGOis::DPS_2000:  return "±2000 dps";
    case FsGOis::RESERVED_1:
    case FsGOis::RESERVED_2:
    case FsGOis::RESERVED_3: return "Reserved";
    default: return "Unknown";
    }
}

void UiCtrl2OisRegister::log() const
{
    ESP_LOGI(TAG, "UI_CTRL2_OIS: raw=0x%02X", raw_);
    ESP_LOGI(TAG, "  LPF1_G_OIS_BW: %s", to_string(lpf1_g_ois_bw()));
    ESP_LOGI(TAG, "  FS_G_OIS: %s", to_string(fs_g_ois()));
}

std::string UiCtrl2OisRegister::to_json() const
{
    return std::string("{")
        + "\"lpf1_g_ois_bw\":\"" + to_string(lpf1_g_ois_bw()) + "\","
        + "\"fs_g_ois\":\"" + to_string(fs_g_ois()) + "\""
        + "}";
}

const char* UiCtrl3OisRegister::to_string(LpfXlOisBw v)
{
    switch (v) {
        case LpfXlOisBw::HZ_749:   return "749 Hz";
        case LpfXlOisBw::HZ_539:   return "539 Hz";
        case LpfXlOisBw::HZ_342:   return "342 Hz";
        case LpfXlOisBw::HZ_162:   return "162 Hz";
        case LpfXlOisBw::HZ_78_5:  return "78.5 Hz";
        case LpfXlOisBw::HZ_38_6:  return "38.6 Hz";
        case LpfXlOisBw::HZ_19_3:  return "19.3 Hz";
        case LpfXlOisBw::HZ_9_8:   return "9.8 Hz";
        default: return "Unknown";
    }
}

const char* UiCtrl3OisRegister::to_string(FsXlOis v)
{
    switch (v) {
        case FsXlOis::G2:  return "±2g";
        case FsXlOis::G4:  return "±4g";
        case FsXlOis::G8:  return "±8g";
        case FsXlOis::G16: return "±16g";
        default: return "Unknown";
    }
}

void UiCtrl3OisRegister::log() const
{
    ESP_LOGI(TAG, "UI_CTRL3_OIS: raw=0x%02X", raw_);
    ESP_LOGI(TAG, "  LPF_XL_OIS_BW: %s", to_string(lpf_xl_ois_bw()));
    ESP_LOGI(TAG, "  FS_XL_OIS: %s", to_string(fs_xl_ois()));
}

std::string UiCtrl3OisRegister::to_json() const
{
    return std::string("{")
        + "\"lpf_xl_ois_bw\":\"" + to_string(lpf_xl_ois_bw()) + "\","
        + "\"fs_xl_ois\":\"" + to_string(fs_xl_ois()) + "\""
        + "}";
}


} // namespace lsm6dsv16x