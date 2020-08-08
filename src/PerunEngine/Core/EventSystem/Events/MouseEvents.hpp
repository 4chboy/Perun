#ifndef _PERUNENGINE_MOUSE_EVENTS_H
#define _PERUNENGINE_MOUSE_EVENTS_H
#include <cstdint>

#include "Event.hpp"
#include "PerunEngine/Core/Input/MouseCodes.hpp"

namespace perun
{
    class PERUNENGINE_API MouseButtonEvent : public Event
    {
    public:
        MouseCode button;

    protected:
        MouseButtonEvent(EventType eventType, MouseCode button) noexcept
            : Event{eventType, EventCategory::Input | EventCategory::Mouse}
            , button{button}
        {
        }
    };

    class PERUNENGINE_API MouseButtonPressedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(MouseCode button) noexcept
            : MouseButtonEvent{EventType::MouseButtonPressed, button}
        {
        }
    };

    class PERUNENGINE_API MouseButtonReleasedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleasedEvent(MouseCode button) noexcept
            : MouseButtonEvent{EventType::MouseButtonReleased, button}
        {
        }
    };

    class PERUNENGINE_API MouseMovedEvent final : public Event
    {
    public:
        MouseMovedEvent(float x, float y) noexcept
            : Event{EventType::MouseMoved, EventCategory::Input | EventCategory::Mouse}
            , x{x}
            , y{y}
        {
        }

        float x, y;
    };

    class PERUNENGINE_API MouseScrolledEvent final : public Event
    {
    public:
        MouseScrolledEvent(float dx, float dy) noexcept
            : Event{EventType::MouseScrolled, EventCategory::Input | EventCategory::Mouse}
            , dx{dx}
            , dy{dy}
        {
        }

        float dx, dy;
    };
} // namespace perun

#endif //_PERUNENGINE_KEYBOARD_EVENTS_H
