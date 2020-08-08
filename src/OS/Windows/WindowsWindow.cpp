#include "PerunEnginePCH.hpp"
#include "WindowsWindow.hpp"

#include "PerunEngine/Core/EventSystem/Events/KeyboardEvents.hpp"
#include "PerunEngine/Core/EventSystem/Events/MouseEvents.hpp"
#include "PerunEngine/Core/EventSystem/Events/WindowEvents.hpp"

#if defined(UNICODE) || defined(_UNICODE)
    #define PERUNENGINE_WINDOWS_C_STR(str) L##str
    #define PERUNENGINE_WINDOWS_STR(str)   \
        std::wstring                       \
        {                                  \
            std::begin(str), std::end(str) \
        }
#else
    #define PERUNENGINE_WINDOWS_C_STR(str) str
    #define PERUNENGINE_WINDOWS_STR(str) str
#endif

namespace perun
{
    [[nodiscard]] static Window::WindowCore& GetWindowCore(HWND hWnd) noexcept
    {
        auto lpUserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        return *reinterpret_cast<Window::WindowCore*>(lpUserData);
    }

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        auto& core = GetWindowCore(hWnd);

        switch (uMsg) {
            case WM_KEYDOWN: {
                break;
            }

            case WM_MOUSEMOVE: {
                float x = GET_X_LPARAM(lParam);
                float y = GET_Y_LPARAM(lParam);
                core.eventSystem.SubmitEvent(new MouseMovedEvent{x, y});
                break;
            }

            case WM_SIZE: {
                int32_t width = LOWORD(lParam);
                int32_t height = HIWORD(lParam);
                core.eventSystem.SubmitEvent(new WindowResizedEvent{width, height});
                break;
            }
            case WM_PAINT: {
                PAINTSTRUCT ps = {};
                HDC hDc = BeginPaint(hWnd, &ps);
                FillRect(hDc, &ps.rcPaint, (HBRUSH) COLOR_WINDOW);
                EndPaint(hWnd, &ps);
                break;
            }
            case WM_CLOSE: {
                DestroyWindow(hWnd);
                core.shouldClose = true;
                break;
            }
            case WM_DESTROY: {
                PostQuitMessage(0);
                return 0;
            }
            default: {
                break;
            }
        }

        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
        : Window{props}
    {
        constexpr auto className = PERUNENGINE_WINDOWS_C_STR("WindowsWindowClass");
        auto hInstance = GetModuleHandle(nullptr);
        WNDCLASS wc = {};
        wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        wc.lpszClassName = className;
        RegisterClass(&wc);

        hWnd = CreateWindowEx(
            // Optional Styles
            0,
            // Class Name
            className,
            // Window Title
            PERUNENGINE_WINDOWS_STR(props.title).c_str(),
            // Style
            WS_OVERLAPPEDWINDOW,
            // Position
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            // Size
            static_cast<int>(props.width),
            static_cast<int>(props.height),
            // Parent Window
            nullptr,
            // Menu
            nullptr,
            // Instance
            hInstance,
            // Additional Data
            //&core
            nullptr);

        if (!hWnd) {
            return;
        }

        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&core));
        ShowWindow(hWnd, SW_SHOWNORMAL);
    }

    void WindowsWindow::Update()
    {
        MSG msg = {};
        while (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
} // namespace perun
