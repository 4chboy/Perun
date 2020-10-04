#include <perun/core/platform.hpp>

#if PERUN_OS_WINDOWS
    #include <perun/window/internal/platform/windows/window.hpp>
    #include <perun/input/internal/platform/windows/input.hpp>

namespace perun
{
    std::unique_ptr<window> platform::create_window(window_props props, window::submit_fn submiter)
    {
        return std::make_unique<windows_window>(std::move(props), std::move(submiter));
    }

    std::unique_ptr<input> platform::create_input()
    {
        return std::make_unique<windows_input>();
    }
} // namespace perun

#endif
