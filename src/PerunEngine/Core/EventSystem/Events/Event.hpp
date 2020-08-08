#ifndef _PERUNENGINE_EVENT_H
#define _PERUNENGINE_EVENT_H

namespace perun {

    enum class EventType : size_t {
        Undefined = 0,
        // Keyboard
        KeyPressed, KeyReleased, KeyTyped,
        // Mouse
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        // Window
        WindowMoved, WindowResized, WindowGainedFocus, WindowLostFocus, WindowClosed,
        WindowMinimized, WindowMaximized,
    };

    enum class EventCategory : size_t {
        Undefined = 0b0000,
        Window    = 0b0001,
        Input     = 0b0010,
        Keyboard  = 0b0100,
        Mouse     = 0b1000,
    };

    constexpr inline size_t operator & (EventCategory lhs, EventCategory rhs) noexcept {
        return static_cast<size_t>(lhs) & static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator & (EventCategory lhs, size_t rhs) noexcept {
        return static_cast<size_t>(lhs) & rhs;
    }
    constexpr inline size_t operator & (size_t lhs, EventCategory rhs) noexcept {
        return lhs & static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator | (EventCategory lhs, EventCategory rhs) noexcept {
        return static_cast<size_t>(lhs) | static_cast<size_t>(rhs);
    }
    constexpr inline size_t operator | (EventCategory lhs, size_t rhs) noexcept {
        return static_cast<size_t>(lhs) | rhs;
    }
    constexpr inline size_t operator | (size_t lhs, EventCategory rhs) noexcept {
        return lhs | static_cast<size_t>(rhs);
    }

    class PERUNENGINE_API Event {
    public:
        Event() noexcept :
            handled{ false },
            type{ EventType::Undefined },
            categoryFlags{ static_cast<size_t>(EventCategory::Undefined) } { }
        virtual ~Event() noexcept = default;

        [[nodiscard]] inline EventType GetType() const noexcept {
            return type;
        }
        [[nodiscard]] virtual size_t GetCategoryFlags() const noexcept {
            return categoryFlags;
        }
        [[nodiscard]] inline bool IsInCategory(EventCategory eventCategory) const noexcept {
            return GetCategoryFlags() & eventCategory;
        }

        bool handled;

    protected:
        Event(EventType eventType, size_t eventCategoryFlags) noexcept :
                handled{ false },
                type{ eventType },
                categoryFlags{ eventCategoryFlags } { }
        Event(EventType eventType, EventCategory eventCategory) noexcept :
                Event{ eventType, static_cast<size_t>(eventCategory) } { }

    private:
        EventType type;
        size_t categoryFlags;
    };
}

#endif //_PERUNENGINE_EVENT_H