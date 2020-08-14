#ifndef _PERUN_WINDOWS_WINDOW_H
#define _PERUN_WINDOWS_WINDOW_H
#include "PerunEngine/Core/Window.hpp"

using HWND = struct HWND__*;

namespace perun
{
    class WindowsWindow final : public Window
    {
    public:
        WindowsWindow(WindowProps windowProps, SubmitFn submitFn);
        ~WindowsWindow() override;

        void Update() override;

    private:
        HWND wnd;
    };
} // namespace perun

#endif //_PERUN_WINDOWS_WINDOW_H
