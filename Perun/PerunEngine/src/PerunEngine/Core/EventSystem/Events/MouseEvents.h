#ifndef _PERUNENGINE_MOUSE_EVENTS_H
#define _PERUNENGINE_MOUSE_EVENTS_H
#include <cstdint>

#include "Event.h"
#include "PerunEngine/Core/Input/MouseCodes.h"

namespace perun {

    class MouseButtonEvent : public Event {
    public:
        MouseCode button;

    protected:
        MouseButtonEvent(EventType eventType, MouseCode button) noexcept :
            Event{ eventType, EventCategory::Input | EventCategory::Mouse },
            button{ button } { }
    };

    class MouseButtonPressedEvent final : public MouseButtonEvent {
    public:
        explicit MouseButtonPressedEvent(MouseCode button) noexcept :
            MouseButtonEvent{ EventType::MouseButtonPressed, button } { }
    };

    class MouseButtonReleasedEvent final : public MouseButtonEvent {
    public:
        explicit MouseButtonReleasedEvent(MouseCode button) noexcept :
            MouseButtonEvent{ EventType::MouseButtonReleased, button } { }
    };

    class MouseMovedEvent final : public Event {
    public:
        MouseMovedEvent(float x, float y) noexcept :
            Event{ EventType::MouseMoved, EventCategory::Input | EventCategory::Mouse },
            x{ x },
            y{ y } { }

        float x, y;
    };

    class MouseScrolledEvent final : public Event {
    public:
        MouseScrolledEvent(float dx, float dy) noexcept :
            Event{ EventType::MouseScrolled, EventCategory::Input | EventCategory::Mouse },
            dx{ dx },
            dy{ dy } { }

        float dx, dy;
    };
}

#endif //_PERUNENGINE_KEYBOARD_EVENTS_H
