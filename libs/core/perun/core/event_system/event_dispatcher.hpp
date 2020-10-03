#pragma once

#include <perun/core/event_system/events/event.hpp>

#include <functional>

namespace perun
{
    class PERUN_API event_dispatcher final
    {
    public:
        explicit event_dispatcher(event& event_to_dispatch) noexcept
            : event{event_to_dispatch}
        {
        }

        [[nodiscard]] bool dispatch(const std::function<bool(event&)>& dispatcher, event_type type) noexcept
        {
            if (event.get_type() == type) {
                event.handled = dispatcher(event);
                return true;
            }
            return false;
        }

    private:
        event& event;
    };
} // namespace perun
