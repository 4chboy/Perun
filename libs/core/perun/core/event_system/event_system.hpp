#pragma once

#include <perun/core/event_system/events/event.hpp>
#include <perun/core/event_system/event_dispatcher.hpp>

namespace perun
{
    struct PERUN_API event_listener final
    {
        event_type type;
        std::function<bool(event&)> dispatcher;
    };

    class PERUN_API event_system final
    {
    public:
        void submit_event(event* event)
        {
            event_queue.push_back(event);
        }
        void push_event(event* event) const noexcept
        {
            dispatch_event(*event);
        }
        void add_event_listener(const event_listener& listener)
        {
            listeners[listener.type] = listener.dispatcher;
        }

        void dispatch(bool clear_event_queue = false) noexcept
        {
            for (auto event_iter = event_queue.end(); event_iter != event_queue.begin();) {
                auto& event = *(--event_iter);
                if (dispatch_event(*event)) {
                    event_iter = event_queue.erase(event_iter);
                }
            }
            if (clear_event_queue) {
                event_queue.clear();
            }
        }

    private:
        bool dispatch_event(event& event) const noexcept
        {
            event_dispatcher dispatcher(event);
            for (auto& listener : listeners) {
                if (dispatcher.dispatch(listener.second, listener.first)) {
                    return true;
                }
            }
            return false;
        }

        std::vector<event*> event_queue;
        std::unordered_map<event_type, std::function<bool(event&)>> listeners;
    };
} // namespace perun
