#ifndef _PERUNENGINE_KEYBOARD_EVENTS_H
#define _PERUNENGINE_KEYBOARD_EVENTS_H
#include <cstdint>

#include "Event.h"
#include "PerunEngine/Core/Input/KeyCodes.h"

namespace perun {

    class KeyEvent : public Event {
    public:
        KeyCode keyCode;

    protected:
        KeyEvent(EventType eventType, KeyCode keyCode) noexcept :
            Event{ eventType, EventCategory::Input | EventCategory::Keyboard },
            keyCode{ keyCode } { }
    };

    class KeyPressedEvent final : public KeyEvent {
    public:
        KeyPressedEvent(KeyCode keyCode, int32_t numOfRepeats) noexcept :
            KeyEvent{ EventType::KeyPressed, keyCode },
            numOfRepeats{ numOfRepeats } { }

        int32_t numOfRepeats;
    };

    class KeyReleasedEvent final : public KeyEvent {
    public:
        explicit KeyReleasedEvent(KeyCode keyCode) noexcept :
            KeyEvent{ EventType::KeyReleased, keyCode } { }
    };

    class KeyTypedEvent final : public KeyEvent {
    public:
        explicit KeyTypedEvent(KeyCode keyCode) noexcept :
            KeyEvent{ EventType::KeyTyped, keyCode } { }
    };
}

#endif //_PERUNENGINE_KEYBOARD_EVENTS_H
