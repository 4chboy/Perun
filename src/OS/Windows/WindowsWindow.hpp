#ifndef _PERUNENGINE_WINDOWS_WINDOW_H
#define _PERUNENGINE_WINDOWS_WINDOW_H
#include "PerunEngine/Core/Window.hpp"

typedef struct HWND__* HWND;

namespace perun
{
    class WindowsWindow final : public Window
    {
    public:
        explicit WindowsWindow(const WindowProps& props);
        ~WindowsWindow() override = default;

        void Update() override;

    private:
        HWND hWnd;
    };
} // namespace perun

#endif //_PERUNENGINE_WINDOWS_WINDOW_H
