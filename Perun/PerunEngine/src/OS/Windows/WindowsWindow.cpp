#include "PerunEnginePCH.h"
#include "WindowsWindow.h"

#include "PerunEngine/Core/EventSystem/Events/KeyboardEvents.h"
#include "PerunEngine/Core/EventSystem/Events/MouseEvents.h"
#include "PerunEngine/Core/EventSystem/Events/WindowEvents.h"

namespace perun {

    [[nodiscard]] static Window::WindowCore& GetWindowCore(HWND hWnd) noexcept {
        auto lpUserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        return *reinterpret_cast<Window::WindowCore*>(lpUserData);
    }

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        auto& core = GetWindowCore(hWnd);

        switch (uMsg) {
        case WM_KEYDOWN: {
            union {
                struct {
                    int32_t  repeatCount     : 16;
                    int32_t  scanCode        : 8;
                    bool     isExtended      : 1;
                    int32_t  reserved        : 4;
                    bool     contextCode     : 1;
                    bool     previousState   : 1;
                    bool     transitionState : 1;
                };
                int32_t data;
            } keyData{ };
            keyData.data = static_cast<int32_t>(lParam);
            core.eventSystem.SubmitEvent(new KeyPressedEvent(static_cast<KeyCode>(wParam), keyData.repeatCount));
            return 0;
        }
        case WM_KEYUP: {
            core.eventSystem.SubmitEvent(new KeyReleasedEvent(static_cast<KeyCode>(wParam)));
            return 0;
        }
        case WM_CHAR: {
            auto character = (wParam >= 'a' && wParam <= 'z') ? wParam - 32 : wParam;
            auto keyCode = static_cast<KeyCode>(character);
            core.eventSystem.SubmitEvent(new KeyTypedEvent(keyCode, static_cast<char>(wParam)));
            return 0;
        }
        case WM_LBUTTONDOWN: {
            core.eventSystem.SubmitEvent(new MouseButtonPressedEvent(MouseCode::LeftButton));
            return 0;
        }
        case WM_MBUTTONDOWN: {
            core.eventSystem.SubmitEvent(new MouseButtonPressedEvent(MouseCode::MiddleButton));
            return 0;
        }
        case WM_RBUTTONDOWN: {
            core.eventSystem.SubmitEvent(new MouseButtonPressedEvent(MouseCode::RightButton));
            return 0;
        }
        case WM_XBUTTONDOWN: {
            auto button = HIWORD(wParam);
            if (button == XBUTTON1) {
                core.eventSystem.SubmitEvent(new MouseButtonPressedEvent(MouseCode::AdditionalButton1));
            }
            else {
                core.eventSystem.SubmitEvent(new MouseButtonPressedEvent(MouseCode::AdditionalButton2));
            }
            return 0;
        }
        case WM_LBUTTONUP: {
                core.eventSystem.SubmitEvent(new MouseButtonReleasedEvent(MouseCode::LeftButton));
                return 0;
            }
        case WM_MBUTTONUP: {
                core.eventSystem.SubmitEvent(new MouseButtonReleasedEvent(MouseCode::MiddleButton));
                return 0;
            }
        case WM_RBUTTONUP: {
                core.eventSystem.SubmitEvent(new MouseButtonReleasedEvent(MouseCode::RightButton));
                return 0;
            }
        case WM_XBUTTONUP: {
                auto button = HIWORD(wParam);
                if (button == XBUTTON1) {
                    core.eventSystem.SubmitEvent(new MouseButtonReleasedEvent(MouseCode::AdditionalButton1));
                }
                else {
                    core.eventSystem.SubmitEvent(new MouseButtonReleasedEvent(MouseCode::AdditionalButton2));
                }
                return 0;
            }
        case WM_LBUTTONDBLCLK: {
                core.eventSystem.SubmitEvent(new MouseButtonDoubleClickedEvent(MouseCode::LeftButton));
                return 0;
            }
        case WM_MBUTTONDBLCLK: {
                core.eventSystem.SubmitEvent(new MouseButtonDoubleClickedEvent(MouseCode::MiddleButton));
                return 0;
            }
        case WM_RBUTTONDBLCLK: {
                core.eventSystem.SubmitEvent(new MouseButtonDoubleClickedEvent(MouseCode::RightButton));
                return 0;
            }
        case WM_XBUTTONDBLCLK: {
                auto button = HIWORD(wParam);
                if (button == XBUTTON1) {
                    core.eventSystem.SubmitEvent(new MouseButtonDoubleClickedEvent(MouseCode::AdditionalButton1));
                }
                else {
                    core.eventSystem.SubmitEvent(new MouseButtonDoubleClickedEvent(MouseCode::AdditionalButton2));
                }
                return 0;
            }
        case WM_MOUSEMOVE: {
            float x = GET_X_LPARAM(lParam);
            float y = GET_Y_LPARAM(lParam);
            core.eventSystem.SubmitEvent(new MouseMovedEvent{ x, y });
            return 0;
        }
        case WM_MOUSEWHEEL: {
            auto delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(wParam)) / static_cast<float>(WHEEL_DELTA);
            core.eventSystem.SubmitEvent(new MouseScrolledEvent(0.0f, delta));
            return 0;
        }
        case WM_MOVE: [[fallthrough]];
        case WM_MOVING: {
            int32_t x = LOWORD(lParam);
            int32_t y = HIWORD(lParam);
            core.eventSystem.SubmitEvent(new WindowMovedEvent(x, y));
            return 0;
        }
        case WM_SIZE: [[fallthrough]];
        case WM_SIZING: {
            int32_t width  = LOWORD(lParam);
            int32_t height = HIWORD(lParam);
            core.eventSystem.SubmitEvent(new WindowResizedEvent(width, height));
            return 0;
        }
        case WM_ACTIVATE: {
            auto focus = LOWORD(wParam);
            if (focus == WA_ACTIVE || focus == WA_CLICKACTIVE) {
                core.eventSystem.SubmitEvent(new WindowGainedFocusEvent());
            }
            else {
                core.eventSystem.SubmitEvent(new WindowLostFocusEvent());
            }
            return 0;
        }
        case WM_CREATE: {
            core.eventSystem.SubmitEvent(new WindowCreatedEvent());
            return 0;
        }
        case WM_CLOSE: {
            DestroyWindow(hWnd);
            core.eventSystem.SubmitEvent(new WindowClosedEvent());
            core.shouldClose = true;
            return 0;
        }
        case WM_DESTROY: {
                PostQuitMessage(0);
                return 0;
            }
        case WM_SYSCOMMAND: {
            switch (wParam) {
            case SC_MINIMIZE: {
                core.eventSystem.SubmitEvent(new WindowMinimizedEvent());
                break;
            }
            case SC_MAXIMIZE: {
                core.eventSystem.SubmitEvent(new WindowMaximizedEvent());
                break;
            }
            default: {
                break;
            }
            }
            [[fallthrough]];
        }
        default: {
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
        }
    }

    WindowsWindow::WindowsWindow(const WindowProps& props, HWND parent) :
        Window{ props }, parent{ parent } {
        memset(&wc, 0, sizeof(wc));
        wc.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
        wc.lpfnWndProc   = WindowProc;
        wc.hInstance     = hInstance;
        wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
        wc.lpszClassName = className;
        RegisterClass(&wc);
    }

    void WindowsWindow::Init() {

        hWnd = CreateWindowEx(
                // Optional Styles
                0,
                // Class Name
                className,
                // Window Title
                PERUNENGINE_WINDOWS_STR(core.props.title).c_str(),
                // Style
                WS_OVERLAPPEDWINDOW,
                // Position
                CW_USEDEFAULT, CW_USEDEFAULT,
                // Size
                static_cast<int>(core.props.width), static_cast<int>(core.props.height),
                // Parent Window
                parent,
                // Menu
                nullptr,
                // Instance
                hInstance,
                // Additional Data
                //&core
                nullptr
        );

        if (!hWnd) {
            return;
        }

        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&core));
        ShowWindow(hWnd, SW_SHOWNORMAL);
    }

    void WindowsWindow::Update() {
        MSG msg = { };
        while (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    std::unique_ptr<Window> WindowsWindow::CreateChild(const WindowProps& props) {
        return std::make_unique<WindowsWindow>(props, hWnd);
    }

    HINSTANCE WindowsWindow::hInstance = GetModuleHandle(nullptr);
}
