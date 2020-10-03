#include <perun/core/platform.hpp>

#if PERUN_OS_MACOS
    #include <perun/window/internal/platform/macos/window.hpp>
    #include <perun/input/internal/platform/macos/input.hpp>

namespace perun
{
    std::unique_ptr<window> platform::create_window(window_props props, window::submit_fn submiter)
    {
        return std::make_unique<macos_window>(std::move(props), std::move(submiter));
    }

    std::unique_ptr<input> platform::create_input()
    {
        return std::make_unique<macos_input>();
    }
} // namespace perun

#endif
