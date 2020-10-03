#pragma once

#include <perun/utils/defs.hpp>

#if PERUN_OS_MACOS
    #include <perun/window/window.hpp>

namespace perun
{
    class windows_window final : public window
    {
    public:
        windows_window(window_props props, submit_fn submiter);
        ~windows_window() override;

        void Update() override;

    private:
    };
} // namespace perun

#endif
