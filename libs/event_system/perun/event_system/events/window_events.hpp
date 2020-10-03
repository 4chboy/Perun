#pragma once

#include <cstdint>

#include "event.hpp"

namespace perun
{
    class PERUN_API window_moved_event final : public event
    {
    public:
        window_moved_event(int32_t x, int32_t y) noexcept
            : event{event_type::WindowMoved, event_category::Window}
            , x{x}
            , y{y}
        {
        }

        int32_t x, y;
    };

    class PERUN_API window_resized_event final : public event
    {
    public:
        window_resized_event(int32_t width, int32_t height) noexcept
            : event{event_type::WindowResized, event_category::Window}
            , width{width}
            , height{height}
        {
        }

        int32_t width, height;
    };

    class PERUN_API window_gained_focus_event final : public event
    {
    public:
        window_gained_focus_event() noexcept
            : event{event_type::WindowGainedFocus, event_category::Window}
        {
        }
    };

    class PERUN_API window_lost_focus_event final : public event
    {
    public:
        window_lost_focus_event() noexcept
            : event{event_type::WindowLostFocus, event_category::Window}
        {
        }
    };

    class PERUN_API window_created_event final : public event
    {
    public:
        window_created_event() noexcept
            : event{event_type::WindowCreated, event_category::Window}
        {
        }
    };

    class PERUN_API window_closed_event final : public event
    {
    public:
        window_closed_event() noexcept
            : event{event_type::WindowClosed, event_category::Window}
        {
        }
    };

    class PERUN_API window_minimized_event final : public event
    {
    public:
        window_minimized_event() noexcept
            : event{event_type::WindowMinimized, event_category::Window}
        {
        }
    };

    class PERUN_API window_maximized_event final : public event
    {
    public:
        window_maximized_event() noexcept
            : event{event_type::WindowMaximized, event_category::Window}
        {
        }
    };
} // namespace perun
