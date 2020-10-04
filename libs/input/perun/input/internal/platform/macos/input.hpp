#pragma once

#include <perun/utils/defs.hpp>

#if PERUN_OS_MACOS
    #include <perun/input/input.hpp>

namespace perun
{
    class macos_input final : public input
    {
    public:
        macos_input() noexcept = default;
        ~macos_input() noexcept override = default;

        [[nodiscard]] bool is_key_down(key_code key) const noexcept override;
        [[nodiscard]] bool is_mouse_button_down(mouse_code button) const noexcept override;
        [[nodiscard]] std::pair<float, float> get_mouse_pos() const noexcept override;
    };
} // namespace perun

#endif
