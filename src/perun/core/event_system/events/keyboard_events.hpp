#pragma once

#include <definitions.hpp>

#include <perun/core/event_system/events/event.hpp>
#include <perun/core/input/key_codes.hpp>

#include <cstdint>

namespace perun
{
    class PERUN_API key_event : public event
    {
    public:
        key_code code;

    protected:
        key_event(event_type type, key_code code) noexcept
            : event{type, event_category::Input | event_category::Keyboard}
            , code{code}
        {
        }
    };

    class PERUN_API key_pressed_event final : public key_event
    {
    public:
        key_pressed_event(key_code code, uint32_t repeat_count) noexcept
            : key_event{event_type::KeyPressed, code}
            , repeat_count{repeat_count}
        {
        }

        uint32_t repeat_count;
    };

    class PERUN_API key_released_event final : public key_event
    {
    public:
        explicit key_released_event(key_code code) noexcept
            : key_event{event_type::KeyReleased, code}
        {
        }
    };

    class PERUN_API key_typed_event final : public key_event
    {
    public:
        explicit key_typed_event(key_code code, char character) noexcept
            : key_event{event_type::KeyTyped, code}
            , character{character}
        {
        }

        char character;
    };
} // namespace perun
