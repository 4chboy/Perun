#include "PerunEnginePCH.h"

#include <Windows.h>
#include <Windowsx.h>

#if defined(UNICODE) || defined(_UNICODE)
#define PERUNENGINE_WINDOWS_C_STR(str) L##str
#define PERUNENGINE_WINDOWS_STR(str) std::wstring{ std::begin(str), std::end(str) }
#else
#define PERUNENGINE_WINDOWS_C_STR(str) str
#define PERUNENGINE_WINDOWS_STR(str) str
#endif

#include "WindowsWindow.h"

#include "PerunEngine/Core/EventSystem/Events/KeyboardEvents.h"
#include "PerunEngine/Core/EventSystem/Events/MouseEvents.h"
#include "PerunEngine/Core/EventSystem/Events/WindowEvents.h"

#ifndef WM_MOUSEHWHEEL
#define WM_MOUSEHWHEEL 0x020E
#endif

namespace perun {

    namespace details {

        static LRESULT KeyDownCallback(auto& core, WPARAM wParam, LPARAM lParam);
        static LRESULT KeyUpCallback(auto& core, WPARAM wParam, LPARAM lParam);
        static LRESULT KeyCharCallback(auto& core, WPARAM wParam, LPARAM lParam);
        static LRESULT MouseButtonDownCallback(auto& core, MouseCode button);
        static LRESULT MouseButtonUpCallback(auto& core, MouseCode button);
        static LRESULT MouseButtonDoubleClickedCallback(auto& core, MouseCode button);
        static LRESULT MouseMoveCallback(auto& core, LPARAM lParam);
        static LRESULT MouseScrollCallback(auto& core, WPARAM wParam);
        static LRESULT MouseHorizontalScrollCallback(auto& core, WPARAM wParam);
        static LRESULT WindowMoveCallback(auto& core, LPARAM lParam);
        static LRESULT WindowSizeCallback(auto& core, LPARAM lParam);
        static LRESULT WindowFocusCallback(auto& core, WPARAM wParam);
        static LRESULT WindowCreateCallback(auto& core);
        static LRESULT WindowDestroyCallback(auto& core);
        static LRESULT WindowMinimizeCallback(auto& core);
        static LRESULT WindowMaximizeCallback(auto& core);
    }

    LRESULT CALLBACK PerunEngineWndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        using namespace perun::details;
        auto& core = *reinterpret_cast<WindowsWindow::WindowCore*>(GetWindowLongPtr(wnd, GWLP_USERDATA));
        switch (msg) {
        case WM_KEYDOWN:       { return KeyDownCallback(core, wParam, lParam); }
        case WM_KEYUP:         { return KeyUpCallback(core, wParam, lParam); }
        case WM_CHAR:          { return KeyCharCallback(core, wParam, lParam); }
        case WM_LBUTTONDOWN:   { return MouseButtonDownCallback(core, MouseCode::LeftButton); }
        case WM_MBUTTONDOWN:   { return MouseButtonDownCallback(core, MouseCode::MiddleButton); }
        case WM_RBUTTONDOWN:   { return MouseButtonDownCallback(core, MouseCode::RightButton); }
        case WM_XBUTTONDOWN:   {
            return MouseButtonDownCallback(core, HIWORD(wParam) == XBUTTON1 ?
                MouseCode::AdditionalButton1 :
                MouseCode::AdditionalButton2);
        }
        case WM_LBUTTONUP:     { return MouseButtonUpCallback(core, MouseCode::LeftButton); }
        case WM_MBUTTONUP:     { return MouseButtonUpCallback(core, MouseCode::MiddleButton); }
        case WM_RBUTTONUP:     { return MouseButtonUpCallback(core, MouseCode::RightButton); }
        case WM_XBUTTONUP:     {
            return MouseButtonUpCallback(core, HIWORD(wParam) == XBUTTON1 ?
            MouseCode::AdditionalButton1 :
            MouseCode::AdditionalButton2);
        }
        case WM_LBUTTONDBLCLK: { return MouseButtonDoubleClickedCallback(core, MouseCode::LeftButton); }
        case WM_MBUTTONDBLCLK: { return MouseButtonDoubleClickedCallback(core, MouseCode::MiddleButton); }
        case WM_RBUTTONDBLCLK: { return MouseButtonDoubleClickedCallback(core, MouseCode::RightButton); }
        case WM_XBUTTONDBLCLK: {
            return MouseButtonDoubleClickedCallback(core, HIWORD(wParam) == XBUTTON1 ?
            MouseCode::AdditionalButton1 :
            MouseCode::AdditionalButton2);
        }
        case WM_MOUSEMOVE:     { return MouseMoveCallback(core, lParam); }
        case WM_MOUSEWHEEL:    { return MouseScrollCallback(core, wParam); }
        case WM_MOUSEHWHEEL:   { return MouseHorizontalScrollCallback(core, wParam); }
        case WM_MOVE:          [[fallthrough]];
        case WM_MOVING:        { return WindowMoveCallback(core, lParam); }
        case WM_SIZE:          [[fallthrough]];
        case WM_SIZING:        { return WindowSizeCallback(core, lParam); }
        case WM_ACTIVATE:      { return WindowFocusCallback(core, wParam); }
        case WM_CREATE:        { return WindowCreateCallback(core); }
        case WM_CLOSE:         { return WindowDestroyCallback(core); }
        case WM_SYSCOMMAND:    {
            switch (wParam)    {
            case SC_MINIMIZE:  { return WindowMinimizeCallback(core); }
            case SC_MAXIMIZE:  { return WindowMaximizeCallback(core); }
            }
        }
        case WM_DESTROY:       { PostQuitMessage(0); return 0; }
        default:               { return DefWindowProc(wnd, msg, wParam, lParam); }
        }
    }

    WindowsWindow::WindowsWindow(WindowProps windowProps, SubmitFn submitFn) :
        Window{ std::move(windowProps), std::move(submitFn) } {
        constexpr auto className = PERUNENGINE_WINDOWS_C_STR("PerunEngineWndClass");
        auto instance = GetModuleHandle(nullptr);

        WNDCLASSEX wce;
        wce.cbSize = sizeof(WNDCLASSEX);
        if (!GetClassInfoExA(instance, className, &wce)) {
            std::memset(&wce, 0, sizeof(WNDCLASS));
            wce.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
            wce.hCursor       = LoadCursor(nullptr, IDC_ARROW);
            wce.lpfnWndProc   = PerunEngineWndProc;
            wce.hInstance     = instance;
            wce.style         = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
            wce.lpszClassName = className;
            RegisterClassEx(&wce);
        }

        auto windowWidth  = core.props.width  == 0 ? static_cast<int>(core.props.width)  : CW_USEDEFAULT;
        auto windowHeight = core.props.height == 0 ? static_cast<int>(core.props.height) : CW_USEDEFAULT;

        wnd = CreateWindowEx(
                0, // Optional styles
                className,
                PERUNENGINE_WINDOWS_STR(core.props.title).c_str(),
                WS_OVERLAPPEDWINDOW, // Style
                CW_USEDEFAULT, CW_USEDEFAULT, // Position
                windowWidth, windowHeight, // Size
                nullptr, // Parent window
                nullptr, // Menu
                instance,
                nullptr // Additional data
                );

        if (wnd == nullptr) {
            // Log error message
            return;
        }

        SetWindowLongPtr(wnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&core));
        ShowWindow(wnd, SW_SHOWNORMAL);
    }

    WindowsWindow::~WindowsWindow() {
        DestroyWindow(wnd);
    }

    void WindowsWindow::Update() {
        MSG msg;
        while (PeekMessage(&msg, wnd, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    namespace details {

        union KeyData final{
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
        };

        LRESULT KeyDownCallback(auto& core, WPARAM wParam, LPARAM lParam) {
            KeyData keyData{ .data = static_cast<int32_t>(lParam) };
            core.submit(new KeyPressedEvent{ static_cast<KeyCode>(wParam), static_cast<uint32_t>(keyData.repeatCount) });
            return 0;
        }

        LRESULT KeyUpCallback(auto& core, WPARAM wParam, LPARAM lParam) {
            (void)lParam; // could be used to create keyData

            core.submit(new KeyReleasedEvent{ static_cast<KeyCode>(wParam) });
            return 0;
        }

        LRESULT KeyCharCallback(auto& core, WPARAM wParam, LPARAM lParam) {
            (void)lParam; // could be used to create keyData

            auto keyCode = static_cast<KeyCode>((wParam >= 'a' && wParam <= 'z') ? wParam - 32 : wParam);
            core.submit(new KeyTypedEvent{ keyCode, static_cast<char>(wParam) });
            return 0;
        }

        LRESULT MouseButtonDownCallback(auto& core, MouseCode button) {
            core.submit(new MouseButtonPressedEvent{ button });
            return 0;
        }

        LRESULT MouseButtonUpCallback(auto& core, MouseCode button) {
            core.submit(new MouseButtonReleasedEvent{ button });
            return 0;
        }

        LRESULT MouseButtonDoubleClickedCallback(auto& core, MouseCode button) {
            core.submit(new MouseButtonDoubleClickedEvent{ button });
            return 0;
        }

        LRESULT MouseMoveCallback(auto& core, LPARAM lParam) {
            float x = GET_X_LPARAM(lParam);
            float y = GET_Y_LPARAM(lParam);
            core.submit(new MouseMovedEvent{ x, y });
            return 0;
        }

        LRESULT MouseScrollCallback(auto& core, WPARAM wParam) {
            auto delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(wParam)) / static_cast<float>(WHEEL_DELTA);
            core.submit(new MouseScrolledEvent{ 0.0f, delta });
            return 0;
        }

        LRESULT MouseHorizontalScrollCallback(auto& core, WPARAM wParam) {
            auto delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(wParam)) / static_cast<float>(WHEEL_DELTA);
            core.submit(new MouseScrolledEvent{ delta, 0.0f });
            return 0;
        }

        LRESULT WindowMoveCallback(auto& core, LPARAM lParam) {
            int32_t x = LOWORD(lParam);
            int32_t y = HIWORD(lParam);
            core.submit(new WindowMovedEvent{ x, y });
            return 0;
        }

        LRESULT WindowSizeCallback(auto& core, LPARAM lParam) {
            int32_t width  = LOWORD(lParam);
            int32_t height = HIWORD(lParam);
            core.submit(new WindowResizedEvent{ width, height });
            return 0;
        }

        LRESULT WindowFocusCallback(auto& core, WPARAM wParam) {
            switch (wParam) {
            case WA_ACTIVE:      [[fallthrough]];
            case WA_CLICKACTIVE: { core.submit(new WindowGainedFocusEvent{ }); return 0; }
            case WA_INACTIVE:    [[fallthrough]];
            default:             { core.submit(new WindowLostFocusEvent{ });   return 0; }
            }
        }

        LRESULT WindowCreateCallback(auto& core) {
            core.submit(new WindowCreatedEvent{ });
            return 0;
        }

        LRESULT WindowDestroyCallback(auto& core) {
            core.submit(new WindowClosedEvent{ });
            return 0;
        }

        LRESULT WindowMinimizeCallback(auto& core) {
            core.submit(new WindowMinimizedEvent{ });
            return 0;
        }

        LRESULT WindowMaximizeCallback(auto& core) {
            core.submit(new WindowMaximizedEvent{ });
            return 0;
        }
    }
}
