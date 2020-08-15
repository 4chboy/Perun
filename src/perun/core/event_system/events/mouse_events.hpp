#pragma once

#include <perun_pch.hpp>

#include <perun/core/event_system/events/event.hpp>
#include <perun/core/input/mouse_codes.hpp>

namespace perun
{
    class PERUN_API mouse_button_event : public event
    {
    public:
        mouse_code button;

    protected:
        mouse_button_event(event_type type, mouse_code button) noexcept
            : event{type, event_category::Input | event_category::Mouse}
            , button{button}
        {
        }
    };

    class PERUN_API mouse_button_pressed_event final : public mouse_button_event
    {
    public:
        explicit mouse_button_pressed_event(mouse_code button) noexcept
            : mouse_button_event{event_type::MouseButtonPressed, button}
        {
        }
    };

    class PERUN_API mouse_button_released_event final : public mouse_button_event
    {
    public:
        explicit mouse_button_released_event(mouse_code button) noexcept
            : mouse_button_event{event_type::MouseButtonReleased, button}
        {
        }
    };

    class PERUN_API mouse_button_double_clicked_event final : public mouse_button_event
    {
    public:
        explicit mouse_button_double_clicked_event(mouse_code button) noexcept
            : mouse_button_event{event_type::MouseButtonDoubleClicked, button}
        {
        }
    };

    class PERUN_API mouse_moved_event final : public event
    {
    public:
        mouse_moved_event(float x, float y) noexcept
            : event{event_type::MouseMoved, event_category::Input | event_category::Mouse}
            , x{x}
            , y{y}
        {
        }

        float x, y;
    };

    class PERUN_API mouse_scrolled_event final : public event
    {
    public:
        mouse_scrolled_event(float dx, float dy) noexcept
            : event{event_type::MouseScrolled, event_category::Input | event_category::Mouse}
            , dx{dx}
            , dy{dy}
        {
        }

        float dx, dy;
    };
} // namespace perun
