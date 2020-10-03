#pragma once

#if PERUN_OS_WINDOWS
    #include <perun/core/window.hpp>

using HWND = struct HWND__*;

namespace perun
{
    class windows_window final : public window
    {
    public:
        windows_window(window_props props, submit_fn submiter);
        ~windows_window() override;

        void Update() override;

    private:
        HWND wnd;
    };
} // namespace perun

#endif
