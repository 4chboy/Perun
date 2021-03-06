#pragma once

#include <perun/event_system/events/event.hpp>

#include <functional>

namespace perun
{
    class PERUN_API event_dispatcher final
    {
    public:
        explicit event_dispatcher(event& event_to_dispatch) noexcept
            : m_event{event_to_dispatch}
        {
        }

        [[nodiscard]] bool dispatch(const std::function<bool(event&)>& dispatcher, event_type type) noexcept
        {
            if (m_event.get_type() == type) {
                m_event.handled = dispatcher(m_event);
                return true;
            }
            return false;
        }

    private:
        event& m_event;
    };
} // namespace perun
