#pragma once

#include <definitions.hpp>
#include <cstddef>

namespace perun
{
    enum class event_type : size_t
    {
        Undefined = 0,
        // Keyboard
        KeyPressed,
        KeyReleased,
        KeyTyped,
        // Mouse
        MouseButtonPressed,
        MouseButtonReleased,
        MouseButtonDoubleClicked,
        MouseMoved,
        MouseScrolled,
        // Window
        WindowMoved,
        WindowResized,
        WindowGainedFocus,
        WindowLostFocus,
        WindowCreated,
        WindowClosed,
        WindowMinimized,
        WindowMaximized,
    };

    enum class event_category : size_t
    {
        Undefined = 0b0000,
        Window = 0b0001,
        Input = 0b0010,
        Keyboard = 0b0100,
        Mouse = 0b1000,
    };

    constexpr inline size_t operator&(event_category lhs, event_category rhs) noexcept
    {
        return static_cast<size_t>(lhs) & static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator&(event_category lhs, size_t rhs) noexcept
    {
        return static_cast<size_t>(lhs) & rhs;
    }
    constexpr inline size_t operator&(size_t lhs, event_category rhs) noexcept
    {
        return lhs & static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator|(event_category lhs, event_category rhs) noexcept
    {
        return static_cast<size_t>(lhs) | static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator|(event_category lhs, size_t rhs) noexcept
    {
        return static_cast<size_t>(lhs) | rhs;
    }
    constexpr inline size_t operator|(size_t lhs, event_category rhs) noexcept
    {
        return lhs | static_cast<size_t>(rhs);
    }

    class PERUN_API event
    {
    public:
        event() noexcept
            : handled{false}
            , type{event_type::Undefined}
            , category_flags{static_cast<size_t>(event_category::Undefined)}
        {
        }
        virtual ~event() noexcept = default;

        [[nodiscard]] inline event_type get_type() const noexcept
        {
            return type;
        }
        [[nodiscard]] virtual size_t get_category_flags() const noexcept
        {
            return category_flags;
        }
        [[nodiscard]] inline bool is_in_category(event_category eventCategory) const noexcept
        {
            return category_flags & eventCategory;
        }

        bool handled;

    protected:
        event(event_type type, size_t category_flags) noexcept
            : handled{false}
            , type{type}
            , category_flags{category_flags}
        {
        }
        event(event_type type, event_category category_flag) noexcept
            : event{type, static_cast<size_t>(category_flag)}
        {
        }

    private:
        event_type type;
        size_t category_flags;
    };
} // namespace perun
