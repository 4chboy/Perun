#pragma once

#include <perun/utils/defs.hpp>

#if PERUN_OS_MACOS
    #include <perun/window/window.hpp>

namespace perun
{
    class macos_window final : public window
    {
    public:
        macos_window(window_props props, submit_fn submiter);
        ~macos_window() override;

        void Update() override;

    private:
    };
} // namespace perun

#endif
