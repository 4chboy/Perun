#ifndef _PERUNENGINE_WINDOWS_WINDOW_H
#define _PERUNENGINE_WINDOWS_WINDOW_H
#include "PerunEngine/Core/Window.h"

#if defined(UNICODE) || defined(_UNICODE)
#define PERUNENGINE_WINDOWS_C_STR(str) L##str
#define PERUNENGINE_WINDOWS_STR(str) std::wstring{ std::begin(str), std::end(str) }
#else
#define PERUNENGINE_WINDOWS_C_STR(str) str
#define PERUNENGINE_WINDOWS_STR(str) str
#endif

namespace perun {

    class WindowsWindow final : public Window {
    public:
        explicit WindowsWindow(const WindowProps& props, HWND parent = nullptr);
        ~WindowsWindow() override = default;

        [[nodiscard]] inline HWND GetHWND() const { return hWnd; }

        void Init() override;
        void Update() override;
        [[nodiscard]] std::unique_ptr<Window> CreateChild(const WindowProps& props) override;

    private:
        static constexpr auto className = PERUNENGINE_WINDOWS_C_STR("WindowsWindowClass");
        static HINSTANCE hInstance;

        HWND hWnd, parent;
        WNDCLASS wc;
    };
}

#endif //_PERUNENGINE_WINDOWS_WINDOW_H
