#pragma once

#include "Events/Event.hpp"
#include "EventDispatcher.hpp"

namespace perun
{
    struct PERUN_API EventListener final
    {
        EventType eventType;
        std::function<bool(Event&)> dispatchFn;
    };

    class PERUN_API EventSystem final
    {
    public:
        void SubmitEvent(Event* event)
        {
            eventQueue.push_back(event);
        }
        void PushEvent(Event* event) const noexcept
        {
            DispatchEvent(*event);
        }
        void AddEventListener(EventListener listener)
        {
            eventListeners[listener.eventType] = std::move(listener.dispatchFn);
        }

        void Dispatch(bool clearEventQueue = false) noexcept
        {
            for (auto eventIter = eventQueue.end(); eventIter != eventQueue.begin();) {
                auto& event = *(--eventIter);
                if (DispatchEvent(*event)) {
                    eventIter = eventQueue.erase(eventIter);
                }
            }
            if (clearEventQueue) {
                eventQueue.clear();
            }
        }

    private:
        bool DispatchEvent(Event& event) const noexcept
        {
            EventDispatcher dispatcher(event);
            for (auto& eventListener : eventListeners) {
                if (dispatcher.Dispatch(eventListener.second, eventListener.first)) {
                    return true;
                }
            }
            return false;
        }

        std::vector<Event*> eventQueue;
        std::map<EventType, std::function<bool(Event&)>> eventListeners;
    };
} // namespace perun
