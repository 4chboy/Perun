#include "window.hpp"

#if PERUN_OS_WINDOWS
    #include <Windows.h>
    #include <Windowsx.h>

    #if defined(UNICODE) || defined(_UNICODE)
        #define PERUN_WINDOWS_C_STR(str) L##str
        #define PERUN_WINDOWS_STR(str)         \
            std::wstring                       \
            {                                  \
                std::begin(str), std::end(str) \
            }
    #else
        #define PERUN_WINDOWS_C_STR(str) str
        #define PERUN_WINDOWS_STR(str) str
    #endif

    #include <perun/event_system/events/keyboard_events.hpp>
    #include <perun/event_system/events/mouse_events.hpp>
    #include <perun/event_system/events/window_events.hpp>

    #ifndef WM_MOUSEHWHEEL
        #define WM_MOUSEHWHEEL 0x020E
    #endif

namespace perun
{
    namespace details
    {
        static LRESULT key_down_callback(auto& core, WPARAM w_param, LPARAM l_param);
        static LRESULT key_up_callback(auto& core, WPARAM w_param, LPARAM l_param);
        static LRESULT key_char_callback(auto& core, WPARAM w_param, LPARAM l_param);
        static LRESULT mouse_button_down_callback(auto& core, mouse_code button);
        static LRESULT mouse_button_up_callback(auto& core, mouse_code button);
        static LRESULT mouse_button_double_clicked_callback(auto& core, mouse_code button);
        static LRESULT mouse_move_callback(auto& core, LPARAM l_param);
        static LRESULT mouse_scroll_callback(auto& core, WPARAM w_param);
        static LRESULT mouse_horizontal_scroll_callback(auto& core, WPARAM w_param);
        static LRESULT window_move_callback(auto& core, LPARAM l_param);
        static LRESULT window_size_callback(auto& core, LPARAM l_param);
        static LRESULT window_focus_callback(auto& core, WPARAM w_param);
        static LRESULT window_create_callback(auto& core);
        static LRESULT window_destroy_callback(auto& core);
        static LRESULT window_minimize_callback(auto& core);
        static LRESULT window_maximize_callback(auto& core);
    } // namespace details

    LRESULT CALLBACK perun_wnd_proc(HWND wnd, UINT msg, WPARAM w_param, LPARAM l_param)
    {
        using namespace perun::details;
        auto& core = *reinterpret_cast<windows_window::window_core*>(GetWindowLongPtr(wnd, GWLP_USERDATA));
        switch (msg) {
            case WM_KEYDOWN: {
                return key_down_callback(core, w_param, l_param);
            }
            case WM_KEYUP: {
                return key_up_callback(core, w_param, l_param);
            }
            case WM_CHAR: {
                return key_char_callback(core, w_param, l_param);
            }
            case WM_LBUTTONDOWN: {
                return mouse_button_down_callback(core, mouse_code::LeftButton);
            }
            case WM_MBUTTONDOWN: {
                return mouse_button_down_callback(core, mouse_code::MiddleButton);
            }
            case WM_RBUTTONDOWN: {
                return mouse_button_down_callback(core, mouse_code::RightButton);
            }
            case WM_XBUTTONDOWN: {
                return mouse_button_down_callback(core, HIWORD(w_param) == XBUTTON1 ? mouse_code::AdditionalButton1 : mouse_code::AdditionalButton2);
            }
            case WM_LBUTTONUP: {
                return mouse_button_up_callback(core, mouse_code::LeftButton);
            }
            case WM_MBUTTONUP: {
                return mouse_button_up_callback(core, mouse_code::MiddleButton);
            }
            case WM_RBUTTONUP: {
                return mouse_button_up_callback(core, mouse_code::RightButton);
            }
            case WM_XBUTTONUP: {
                return mouse_button_up_callback(core, HIWORD(w_param) == XBUTTON1 ? mouse_code::AdditionalButton1 : mouse_code::AdditionalButton2);
            }
            case WM_LBUTTONDBLCLK: {
                return mouse_button_double_clicked_callback(core, mouse_code::LeftButton);
            }
            case WM_MBUTTONDBLCLK: {
                return mouse_button_double_clicked_callback(core, mouse_code::MiddleButton);
            }
            case WM_RBUTTONDBLCLK: {
                return mouse_button_double_clicked_callback(core, mouse_code::RightButton);
            }
            case WM_XBUTTONDBLCLK: {
                return mouse_button_double_clicked_callback(core, HIWORD(w_param) == XBUTTON1 ? mouse_code::AdditionalButton1 : mouse_code::AdditionalButton2);
            }
            case WM_MOUSEMOVE: {
                return mouse_move_callback(core, l_param);
            }
            case WM_MOUSEWHEEL: {
                return mouse_scroll_callback(core, w_param);
            }
            case WM_MOUSEHWHEEL: {
                return mouse_horizontal_scroll_callback(core, w_param);
            }
            case WM_MOVE:
                [[fallthrough]];
            case WM_MOVING: {
                return window_move_callback(core, l_param);
            }
            case WM_SIZE:
                [[fallthrough]];
            case WM_SIZING: {
                return window_size_callback(core, l_param);
            }
            case WM_ACTIVATE: {
                return window_focus_callback(core, w_param);
            }
            case WM_CREATE: {
                return window_create_callback(core);
            }
            case WM_CLOSE: {
                return window_destroy_callback(core);
            }
            case WM_SYSCOMMAND: {
                switch (w_param) {
                    case SC_MINIMIZE: {
                        return window_minimize_callback(core);
                    }
                    case SC_MAXIMIZE: {
                        return window_maximize_callback(core);
                    }
                    default: {
                        return DefWindowProc(wnd, msg, w_param, l_param);
                    }
                }
            }
            case WM_DESTROY: {
                PostQuitMessage(0);
                return 0;
            }
            default: {
                return DefWindowProc(wnd, msg, w_param, l_param);
            }
        }
    }

    windows_window::windows_window(window_props props, submit_fn submiter)
        : window{std::move(props), std::move(submiter)}
    {
        constexpr auto class_name = PERUN_WINDOWS_C_STR("PerunEngineWndClass");
        auto instance = GetModuleHandle(nullptr);

        WNDCLASSEX wce;
        wce.cbSize = sizeof(WNDCLASSEX);
        if (!GetClassInfoExA(instance, class_name, &wce)) {
            std::memset(&wce, 0, sizeof(WNDCLASS));
            wce.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
            wce.hCursor = LoadCursor(nullptr, IDC_ARROW);
            wce.lpfnWndProc = perun_wnd_proc;
            wce.hInstance = instance;
            wce.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
            wce.lpszClassName = class_name;
            RegisterClassEx(&wce);
        }

        auto width = core.props.width == 0 ? static_cast<int>(core.props.width) : CW_USEDEFAULT;
        auto height = core.props.height == 0 ? static_cast<int>(core.props.height) : CW_USEDEFAULT;

        wnd = CreateWindowEx(
            0, // Optional styles
            class_name,
            PERUN_WINDOWS_STR(core.props.title).c_str(),
            WS_OVERLAPPEDWINDOW, // Style
            CW_USEDEFAULT,
            CW_USEDEFAULT, // Position
            width,
            height, // Size
            nullptr,      // Parent window
            nullptr,      // Menu
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

    windows_window::~windows_window()
    {
        DestroyWindow(wnd);
    }

    void windows_window::Update()
    {
        MSG msg;
        while (PeekMessage(&msg, wnd, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    namespace details
    {
        union key_data final
        {
            struct
            {
                int32_t repeat_count : 16;
                int32_t scan_code : 8;
                bool is_extended : 1;
                int32_t reserved : 4;
                bool context_code : 1;
                bool previous_state : 1;
                bool transition_state : 1;
            };
            int32_t data;
        };

        LRESULT key_down_callback(auto& core, WPARAM w_param, LPARAM l_param)
        {
            key_data data{.data = static_cast<int32_t>(l_param)};
            core.submit(new key_pressed_event{static_cast<key_code>(w_param), static_cast<uint32_t>(data.repeat_count)});
            return 0;
        }

        LRESULT key_up_callback(auto& core, WPARAM w_param, LPARAM l_param)
        {
            (void) l_param; // could be used to create keyData

            core.submit(new key_released_event{static_cast<key_code>(w_param)});
            return 0;
        }

        LRESULT key_char_callback(auto& core, WPARAM w_param, LPARAM l_param)
        {
            (void) l_param; // could be used to create keyData

            auto keyCode = static_cast<key_code>((w_param >= 'a' && w_param <= 'z') ? w_param - 32 : w_param);
            core.submit(new key_typed_event{keyCode, static_cast<char>(w_param)});
            return 0;
        }

        LRESULT mouse_button_down_callback(auto& core, mouse_code button)
        {
            core.submit(new mouse_button_pressed_event{button});
            return 0;
        }

        LRESULT mouse_button_up_callback(auto& core, mouse_code button)
        {
            core.submit(new mouse_button_released_event{button});
            return 0;
        }

        LRESULT mouse_button_double_clicked_callback(auto& core, mouse_code button)
        {
            core.submit(new mouse_button_double_clicked_event{button});
            return 0;
        }

        LRESULT mouse_move_callback(auto& core, LPARAM l_param)
        {
            float x = GET_X_LPARAM(l_param);
            float y = GET_Y_LPARAM(l_param);
            core.submit(new mouse_moved_event{x, y});
            return 0;
        }

        LRESULT mouse_scroll_callback(auto& core, WPARAM w_param)
        {
            auto delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param)) / static_cast<float>(WHEEL_DELTA);
            core.submit(new mouse_scrolled_event{0.0f, delta});
            return 0;
        }

        LRESULT mouse_horizontal_scroll_callback(auto& core, WPARAM w_param)
        {
            auto delta = static_cast<float>(GET_WHEEL_DELTA_WPARAM(w_param)) / static_cast<float>(WHEEL_DELTA);
            core.submit(new mouse_scrolled_event{delta, 0.0f});
            return 0;
        }

        LRESULT window_move_callback(auto& core, LPARAM l_param)
        {
            int32_t x = LOWORD(l_param);
            int32_t y = HIWORD(l_param);
            core.submit(new window_moved_event{x, y});
            return 0;
        }

        LRESULT window_size_callback(auto& core, LPARAM l_param)
        {
            int32_t width = LOWORD(l_param);
            int32_t height = HIWORD(l_param);
            core.submit(new window_resized_event{width, height});
            return 0;
        }

        LRESULT window_focus_callback(auto& core, WPARAM w_param)
        {
            switch (w_param) {
                case WA_ACTIVE:
                    [[fallthrough]];
                case WA_CLICKACTIVE: {
                    core.submit(new window_gained_focus_event{});
                    return 0;
                }
                case WA_INACTIVE:
                    [[fallthrough]];
                default: {
                    core.submit(new window_lost_focus_event{});
                    return 0;
                }
            }
        }

        LRESULT window_create_callback(auto& core)
        {
            core.submit(new window_created_event{});
            return 0;
        }

        LRESULT window_destroy_callback(auto& core)
        {
            core.submit(new window_closed_event{});
            return 0;
        }

        LRESULT window_minimize_callback(auto& core)
        {
            core.submit(new window_minimized_event{});
            return 0;
        }

        LRESULT window_maximize_callback(auto& core)
        {
            core.submit(new window_maximized_event{});
            return 0;
        }
    } // namespace details
} // namespace perun

#endif
