#pragma once

#include <perun/utils/defs.hpp>

#if PERUN_OS_WINDOWS
    #include <perun/core/input/input.hpp>

namespace perun
{
    class windows_input final : public input
    {
    public:
        windows_input() noexcept = default;
        ~windows_input() noexcept override = default;

        [[nodiscard]] bool is_key_down(key_code key) const noexcept override;
        [[nodiscard]] bool is_mouse_button_down(mouse_code button) const noexcept override;
        [[nodiscard]] std::pair<float, float> get_mouse_pos() const noexcept override;
    };
} // namespace perun

#endif
