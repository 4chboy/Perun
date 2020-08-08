#ifndef _PERUNENGINE_EVENT_DISPATCHER_H
#define _PERUNENGINE_EVENT_DISPATCHER_H
#include "PerunEngine/Core/EventSystem/Events/Event.hpp"

namespace perun
{
    class PERUNENGINE_API EventDispatcher final
    {
    public:
        explicit EventDispatcher(Event& eventToDispatch) noexcept
            : event{eventToDispatch}
        {
        }

        [[nodiscard]] bool Dispatch(const std::function<bool(Event&)>& dispatchFn, EventType eventType) noexcept
        {
            if (event.GetType() == eventType) {
                event.handled = dispatchFn(event);
                return true;
            }
            return false;
        }

    private:
        Event& event;
    };
} // namespace perun

#endif //_PERUNENGINE_EVENT_DISPATCHER_H
