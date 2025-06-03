#include "ctrl/lsm6dsv16x-ctrl.hpp"

namespace lsm6dsv16x
{
    // Lecture / écriture générique
    template <typename RegT>
    esp_err_t CTRL::read(RegT &reg)
    {
        uint8_t raw = 0;
        esp_err_t err = read_u8(RegT::reg_addr, raw);
        if (err != ESP_OK)
            return err;
        reg.set_raw(raw);
        return ESP_OK;
    }

    template <typename RegT>
    esp_err_t CTRL::write(const RegT &reg)
    {
        return write_u8(RegT::reg_addr, reg.get_raw());
    }

    // Méthode configure générique
    template <typename RegT>
    esp_err_t CTRL::configure(std::function<void(RegT &)> f)
    {
        RegT reg;
        RETURN_IF_ERROR(read(reg));
        f(reg);
        return write(reg);
    }

    // Instanciations explicites pour éviter les erreurs de linkage
    template esp_err_t CTRL::configure<Ctrl1Register>(std::function<void(Ctrl1Register &)>);
    template esp_err_t CTRL::configure<Ctrl2Register>(std::function<void(Ctrl2Register &)>);
    template esp_err_t CTRL::configure<Ctrl3Register>(std::function<void(Ctrl3Register &)>);
    template esp_err_t CTRL::configure<Ctrl4Register>(std::function<void(Ctrl4Register &)>);
    template esp_err_t CTRL::configure<Ctrl5Register>(std::function<void(Ctrl5Register &)>);
    template esp_err_t CTRL::configure<Ctrl6Register>(std::function<void(Ctrl6Register &)>);
    template esp_err_t CTRL::configure<Ctrl7Register>(std::function<void(Ctrl7Register &)>);
    template esp_err_t CTRL::configure<Ctrl8Register>(std::function<void(Ctrl8Register &)>);
    template esp_err_t CTRL::configure<Ctrl9Register>(std::function<void(Ctrl9Register &)>);
    template esp_err_t CTRL::configure<Ctrl10Register>(std::function<void(Ctrl10Register &)>);

    // Implémentation de software_reset
    esp_err_t CTRL::software_reset()
    {
        return configure<Ctrl3Register>([](auto &reg)
                                        { reg.sw_reset(true); });
    }

// Méthodes privées get/set par registre
#define REG_IMPL(n)                                                           \
    esp_err_t CTRL::get_ctrl##n(Ctrl##n##Register &reg) { return read(reg); } \
    esp_err_t CTRL::set_ctrl##n(const Ctrl##n##Register &reg) { return write(reg); }

    REG_IMPL(1)
    REG_IMPL(2)
    REG_IMPL(3)
    REG_IMPL(4)
    REG_IMPL(5)
    REG_IMPL(6)
    REG_IMPL(7)
    REG_IMPL(8)
    REG_IMPL(9)
    REG_IMPL(10)

#undef REG_IMPL

} // namespace lsm6dsv16x
