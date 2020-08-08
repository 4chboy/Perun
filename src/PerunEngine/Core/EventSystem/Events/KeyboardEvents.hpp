#ifndef _PERUNENGINE_KEYBOARD_EVENTS_H
#define _PERUNENGINE_KEYBOARD_EVENTS_H
#include <cstdint>

#include "Event.hpp"
#include "PerunEngine/Core/Input/KeyCodes.hpp"

namespace perun
{
    class PERUNENGINE_API KeyEvent : public Event
    {
    public:
        KeyCode keyCode;

    protected:
        KeyEvent(EventType eventType, KeyCode keyCode) noexcept
            : Event{eventType, EventCategory::Input | EventCategory::Keyboard}
            , keyCode{keyCode}
        {
        }
    };

    class PERUNENGINE_API KeyPressedEvent final : public KeyEvent
    {
    public:
        KeyPressedEvent(KeyCode keyCode, int32_t numOfRepeats) noexcept
            : KeyEvent{EventType::KeyPressed, keyCode}
            , numOfRepeats{numOfRepeats}
        {
        }

        int32_t numOfRepeats;
    };

    class PERUNENGINE_API KeyReleasedEvent final : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(KeyCode keyCode) noexcept
            : KeyEvent{EventType::KeyReleased, keyCode}
        {
        }
    };

    class PERUNENGINE_API KeyTypedEvent final : public KeyEvent
    {
    public:
        explicit KeyTypedEvent(KeyCode keyCode) noexcept
            : KeyEvent{EventType::KeyTyped, keyCode}
        {
        }
    };
} // namespace perun

#endif //_PERUNENGINE_KEYBOARD_EVENTS_H
