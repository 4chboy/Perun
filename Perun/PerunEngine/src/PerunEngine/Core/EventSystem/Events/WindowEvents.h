#ifndef _PERUNENGINE_WINDOW_EVENTS_H
#define _PERUNENGINE_WINDOW_EVENTS_H
#include <cstdint>

#include "Event.h"

namespace perun {

    class WindowMovedEvent final : public Event {
    public:
        WindowMovedEvent(int32_t x, int32_t y) noexcept :
            Event{ EventType::WindowMoved, EventCategory::Window },
            x{ x },
            y{ y } { }

        int32_t x, y;
    };

    class WindowResizedEvent final : public Event {
    public:
        WindowResizedEvent(int32_t width, int32_t height) noexcept :
            Event{ EventType::WindowResized, EventCategory::Window },
            width{ width },
            height{ height } { }

        int32_t width, height;
    };

    class WindowGainedFocusEvent final : public Event {
    public:
        WindowGainedFocusEvent() noexcept :
            Event{ EventType::WindowGainedFocus, EventCategory::Window } { }
    };

    class WindowLostFocusEvent final : public Event {
    public:
        WindowLostFocusEvent() noexcept :
            Event{ EventType::WindowLostFocus, EventCategory::Window } { }
    };

    class WindowClosedFocusEvent final : public Event {
    public:
        WindowClosedFocusEvent() noexcept :
            Event{ EventType::WindowClosed, EventCategory::Window } { }
    };

    class WindowMinimizedEvent final : public Event {
    public:
        WindowMinimizedEvent() noexcept :
            Event{ EventType::WindowMinimized, EventCategory::Window } { }
    };

    class WindowMaximizedEvent final : public Event {
    public:
        WindowMaximizedEvent() noexcept :
            Event{ EventType::WindowMaximized, EventCategory::Window } { }
    };
}

#endif //_PERUNENGINE_WINDOW_EVENTS_H
