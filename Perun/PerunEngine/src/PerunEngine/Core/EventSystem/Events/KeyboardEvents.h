#ifndef _PERUNENGINE_KEYBOARD_EVENTS_H
#define _PERUNENGINE_KEYBOARD_EVENTS_H
#include <cstdint>

#include "Event.h"
#include "PerunEngine/Core/Input/KeyCodes.h"

namespace perun {

    class PERUNENGINE_API KeyEvent : public Event {
    public:
        KeyCode keyCode;

    protected:
        KeyEvent(EventType eventType, KeyCode keyCode) noexcept :
            Event{ eventType, EventCategory::Input | EventCategory::Keyboard },
            keyCode{ keyCode } { }
    };

    class PERUNENGINE_API KeyPressedEvent final : public KeyEvent {
    public:
        KeyPressedEvent(KeyCode keyCode, uint32_t numOfRepeats) noexcept :
            KeyEvent{ EventType::KeyPressed, keyCode },
            numOfRepeats{ numOfRepeats } { }

        uint32_t numOfRepeats;
    };

    class PERUNENGINE_API KeyReleasedEvent final : public KeyEvent {
    public:
        explicit KeyReleasedEvent(KeyCode keyCode) noexcept :
            KeyEvent{ EventType::KeyReleased, keyCode } { }
    };

    class PERUNENGINE_API KeyTypedEvent final : public KeyEvent {
    public:
        explicit KeyTypedEvent(KeyCode keyCode, char character) noexcept :
            KeyEvent{ EventType::KeyTyped, keyCode },
            character{ character } { }

        char character;
    };
}

#endif //_PERUNENGINE_KEYBOARD_EVENTS_H
