#ifndef _PERUNENGINE_WINDOW_EVENTS_H
#define _PERUNENGINE_WINDOW_EVENTS_H
#include <cstdint>

#include "Event.hpp"

namespace perun {

    class PERUNENGINE_API WindowMovedEvent final : public Event {
    public:
        WindowMovedEvent(int32_t x, int32_t y) noexcept :
            Event{ EventType::WindowMoved, EventCategory::Window },
            x{ x },
            y{ y } { }

        int32_t x, y;
    };

    class PERUNENGINE_API WindowResizedEvent final : public Event {
    public:
        WindowResizedEvent(int32_t width, int32_t height) noexcept :
            Event{ EventType::WindowResized, EventCategory::Window },
            width{ width },
            height{ height } { }

        int32_t width, height;
    };

    class PERUNENGINE_API WindowGainedFocusEvent final : public Event {
    public:
        WindowGainedFocusEvent() noexcept :
            Event{ EventType::WindowGainedFocus, EventCategory::Window } { }
    };

    class PERUNENGINE_API WindowLostFocusEvent final : public Event {
    public:
        WindowLostFocusEvent() noexcept :
            Event{ EventType::WindowLostFocus, EventCategory::Window } { }
    };

    class PERUNENGINE_API WindowCreatedEvent final : public Event {
    public:
        WindowCreatedEvent() noexcept :
            Event{ EventType::WindowCreated, EventCategory::Window } { }
    };

    class PERUNENGINE_API WindowClosedEvent final : public Event {
    public:
        WindowClosedEvent() noexcept :
            Event{ EventType::WindowClosed, EventCategory::Window } { }
    };

    class PERUNENGINE_API WindowMinimizedEvent final : public Event {
    public:
        WindowMinimizedEvent() noexcept :
            Event{ EventType::WindowMinimized, EventCategory::Window } { }
    };

    class PERUNENGINE_API WindowMaximizedEvent final : public Event {
    public:
        WindowMaximizedEvent() noexcept :
            Event{ EventType::WindowMaximized, EventCategory::Window } { }
    };
}

#endif //_PERUNENGINE_WINDOW_EVENTS_H
