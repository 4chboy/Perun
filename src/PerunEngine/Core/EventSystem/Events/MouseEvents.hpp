#pragma once

#include <PerunEnginePCH.hpp>

#include <PerunEngine/Core/EventSystem/Events/Event.hpp>
#include <PerunEngine/Core/Input/MouseCodes.hpp>

namespace perun
{
    class PERUN_API MouseButtonEvent : public Event
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

    class PERUN_API MouseButtonPressedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(MouseCode button) noexcept
            : MouseButtonEvent{EventType::MouseButtonPressed, button}
        {
        }
    };

    class PERUN_API MouseButtonReleasedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleasedEvent(MouseCode button) noexcept
            : MouseButtonEvent{EventType::MouseButtonReleased, button}
        {
        }
    };

    class PERUN_API MouseButtonDoubleClickedEvent final : public MouseButtonEvent
    {
    public:
        explicit MouseButtonDoubleClickedEvent(MouseCode button) noexcept
            : MouseButtonEvent{EventType::MouseButtonDoubleClicked, button}
        {
        }
    };

    class PERUN_API MouseMovedEvent final : public Event
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

    class PERUN_API MouseScrolledEvent final : public Event
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
