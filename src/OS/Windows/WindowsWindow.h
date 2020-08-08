#ifndef _PERUNENGINE_WINDOWS_WINDOW_H
#define _PERUNENGINE_WINDOWS_WINDOW_H
#include "PerunEngine/Core/Window.h"

typedef struct HWND__ *HWND;

namespace perun {

    class WindowsWindow final : public Window {
    public:
        explicit WindowsWindow(const WindowProps& props);
        ~WindowsWindow() override = default;

        void Update() override;

    private:
        HWND hWnd;
    };
}

#endif //_PERUNENGINE_WINDOWS_WINDOW_H
