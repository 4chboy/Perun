#pragma once

#include <definitions.hpp>
#include <perun/core/input/key_codes.hpp>
#include <perun/core/input/mouse_codes.hpp>

#include <utility>

namespace perun
{
    class PERUN_API input
    {
    public:
        virtual ~input() noexcept = default;

        [[nodiscard]] virtual bool is_key_down(key_code key) const noexcept = 0;
        [[nodiscard]] inline bool is_key_up(key_code key) const noexcept
        {
            return !is_key_down(key);
        }
        [[nodiscard]] virtual bool is_mouse_button_down(mouse_code button) const noexcept = 0;
        [[nodiscard]] inline bool is_mouse_button_up(mouse_code button) const noexcept
        {
            return !is_mouse_button_down(button);
        }
        [[nodiscard]] virtual std::pair<float, float> get_mouse_pos() const noexcept = 0;
        [[nodiscard]] inline float get_mouse_pos_x() const noexcept
        {
            return get_mouse_pos().first;
        }
        [[nodiscard]] inline float get_mouse_pos_y() const noexcept
        {
            return get_mouse_pos().second;
        }

    protected:
        input() noexcept = default;
    };
} // namespace perun
