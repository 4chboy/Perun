#ifndef _PERUNENGINE_WINDOWS_WINDOW_H
#define _PERUNENGINE_WINDOWS_WINDOW_H
#include "PerunEngine/Core/Window.hpp"

typedef struct HWND__* HWND;

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

#endif //_PERUNENGINE_WINDOWS_WINDOW_H
