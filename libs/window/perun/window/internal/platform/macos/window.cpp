#include "window.hpp"

#if PERUN_OS_MACOS

    #include <perun/event_system/events/mouse_events.hpp>

namespace perun
{
    macos_window::macos_window(window_props props, submit_fn submiter)
        : window{std::move(props), std::move(submiter)}
    {
    }

    macos_window::~macos_window()
    {
    }

    void macos_window::Update()
    {
    }
} // namespace perun

#endif
