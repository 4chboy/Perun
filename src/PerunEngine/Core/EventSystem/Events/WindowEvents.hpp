#pragma once

#include <cstdint>

#include "Event.hpp"

namespace perun
{
    class PERUN_API WindowMovedEvent final : public Event
    {
    public:
        WindowMovedEvent(int32_t x, int32_t y) noexcept
            : Event{EventType::WindowMoved, EventCategory::Window}
            , x{x}
            , y{y}
        {
        }

        int32_t x, y;
    };

    class PERUN_API WindowResizedEvent final : public Event
    {
    public:
        WindowResizedEvent(int32_t width, int32_t height) noexcept
            : Event{EventType::WindowResized, EventCategory::Window}
            , width{width}
            , height{height}
        {
        }

        int32_t width, height;
    };

    class PERUN_API WindowGainedFocusEvent final : public Event
    {
    public:
        WindowGainedFocusEvent() noexcept
            : Event{EventType::WindowGainedFocus, EventCategory::Window}
        {
        }
    };

    class PERUN_API WindowLostFocusEvent final : public Event
    {
    public:
        WindowLostFocusEvent() noexcept
            : Event{EventType::WindowLostFocus, EventCategory::Window}
        {
        }
    };

    class PERUN_API WindowCreatedEvent final : public Event
    {
    public:
        WindowCreatedEvent() noexcept
            : Event{EventType::WindowCreated, EventCategory::Window}
        {
        }
    };

    class PERUN_API WindowClosedEvent final : public Event
    {
    public:
        WindowClosedEvent() noexcept
            : Event{EventType::WindowClosed, EventCategory::Window}
        {
        }
    };

    class PERUN_API WindowMinimizedEvent final : public Event
    {
    public:
        WindowMinimizedEvent() noexcept
            : Event{EventType::WindowMinimized, EventCategory::Window}
        {
        }
    };

    class PERUN_API WindowMaximizedEvent final : public Event
    {
    public:
        WindowMaximizedEvent() noexcept
            : Event{EventType::WindowMaximized, EventCategory::Window}
        {
        }
    };
} // namespace perun
