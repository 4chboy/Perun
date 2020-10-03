#include "input.hpp"

#if PERUN_OS_WINDOWS
    #include <Windows.h>

namespace perun
{
    bool windows_input::is_key_down(key_code key) const noexcept
    {
        auto state = GetAsyncKeyState(static_cast<int>(key));
        return state < 0;
    }

    bool windows_input::is_mouse_button_down(mouse_code button) const noexcept
    {
        auto state = GetAsyncKeyState(static_cast<int>(button));
        return state < 0;
    }

    std::pair<float, float> windows_input::get_mouse_pos() const noexcept
    {
        POINT pos = {.x = 0, .y = 0};
        GetCursorPos(&pos);
        return {static_cast<float>(pos.x), static_cast<float>(pos.y)};
    }

    const size_t key_code::Undefined = 0;
    const size_t key_code::BackSpace = VK_BACK;
    const size_t key_code::Tab = VK_TAB;
    const size_t key_code::Enter = VK_RETURN;
    const size_t key_code::Shift = VK_SHIFT;
    const size_t key_code::Ctrl = VK_CONTROL;
    const size_t key_code::Alt = VK_MENU;
    const size_t key_code::CapsLock = VK_CAPITAL;
    const size_t key_code::Escape = VK_ESCAPE;
    const size_t key_code::Space = VK_SPACE;
    const size_t key_code::PageUp = VK_PRIOR;
    const size_t key_code::PageDown = VK_NEXT;
    const size_t key_code::End = VK_END;
    const size_t key_code::Home = VK_HOME;
    const size_t key_code::Left = VK_LEFT;
    const size_t key_code::Up = VK_UP;
    const size_t key_code::Right = VK_RIGHT;
    const size_t key_code::Down = VK_DOWN;
    const size_t key_code::Print = VK_PRINT;
    const size_t key_code::PrintScreen = VK_SNAPSHOT;
    const size_t key_code::Insert = VK_INSERT;
    const size_t key_code::Delete = VK_DELETE;
    const size_t key_code::K0 = 0x30;
    const size_t key_code::K1 = 0x31;
    const size_t key_code::K2 = 0x32;
    const size_t key_code::K3 = 0x33;
    const size_t key_code::K4 = 0x34;
    const size_t key_code::K5 = 0x35;
    const size_t key_code::K6 = 0x36;
    const size_t key_code::K7 = 0x37;
    const size_t key_code::K8 = 0x38;
    const size_t key_code::K9 = 0x39;
    const size_t key_code::A = 0x41;
    const size_t key_code::B = 0x42;
    const size_t key_code::C = 0x43;
    const size_t key_code::D = 0x44;
    const size_t key_code::E = 0x45;
    const size_t key_code::F = 0x46;
    const size_t key_code::G = 0x47;
    const size_t key_code::H = 0x48;
    const size_t key_code::I = 0x49;
    const size_t key_code::J = 0x4A;
    const size_t key_code::K = 0x4B;
    const size_t key_code::L = 0x4C;
    const size_t key_code::M = 0x4D;
    const size_t key_code::N = 0x4E;
    const size_t key_code::O = 0x4F;
    const size_t key_code::P = 0x50;
    const size_t key_code::Q = 0x51;
    const size_t key_code::R = 0x52;
    const size_t key_code::S = 0x53;
    const size_t key_code::T = 0x54;
    const size_t key_code::U = 0x55;
    const size_t key_code::V = 0x56;
    const size_t key_code::W = 0x57;
    const size_t key_code::X = 0x58;
    const size_t key_code::Y = 0x59;
    const size_t key_code::Z = 0x5A;
    const size_t key_code::NumPad0 = VK_NUMPAD0;
    const size_t key_code::NumPad1 = VK_NUMPAD1;
    const size_t key_code::NumPad2 = VK_NUMPAD2;
    const size_t key_code::NumPad3 = VK_NUMPAD3;
    const size_t key_code::NumPad4 = VK_NUMPAD4;
    const size_t key_code::NumPad5 = VK_NUMPAD5;
    const size_t key_code::NumPad6 = VK_NUMPAD6;
    const size_t key_code::NumPad7 = VK_NUMPAD7;
    const size_t key_code::NumPad8 = VK_NUMPAD8;
    const size_t key_code::NumPad9 = VK_NUMPAD9;
    const size_t key_code::Multiply = VK_MULTIPLY;
    const size_t key_code::Add = VK_ADD;
    const size_t key_code::NumPadEnter = VK_SEPARATOR;
    const size_t key_code::Subtract = VK_SUBTRACT;
    const size_t key_code::NumPadDot = VK_DECIMAL;
    const size_t key_code::Divide = VK_DIVIDE;
    const size_t key_code::F1 = VK_F1;
    const size_t key_code::F2 = VK_F2;
    const size_t key_code::F3 = VK_F3;
    const size_t key_code::F4 = VK_F4;
    const size_t key_code::F5 = VK_F5;
    const size_t key_code::F6 = VK_F6;
    const size_t key_code::F7 = VK_F7;
    const size_t key_code::F8 = VK_F8;
    const size_t key_code::F9 = VK_F9;
    const size_t key_code::F10 = VK_F10;
    const size_t key_code::F11 = VK_F11;
    const size_t key_code::F12 = VK_F12;
    const size_t key_code::F13 = VK_F13;
    const size_t key_code::F14 = VK_F14;
    const size_t key_code::F15 = VK_F15;
    const size_t key_code::F16 = VK_F16;
    const size_t key_code::F17 = VK_F17;
    const size_t key_code::F18 = VK_F18;
    const size_t key_code::F19 = VK_F19;
    const size_t key_code::F20 = VK_F20;
    const size_t key_code::F21 = VK_F21;
    const size_t key_code::F22 = VK_F22;
    const size_t key_code::F23 = VK_F23;
    const size_t key_code::F24 = VK_F24;
    const size_t key_code::NumLock = VK_NUMLOCK;
    const size_t key_code::LeftShift = VK_LSHIFT;
    const size_t key_code::RightShift = VK_RSHIFT;
    const size_t key_code::LeftCtrl = VK_LCONTROL;
    const size_t key_code::RightCtrl = VK_RCONTROL;
    const size_t key_code::LeftAlt = VK_LMENU;
    const size_t key_code::RightAlt = VK_RMENU;

    const size_t mouse_code::Undefined = 0;
    const size_t mouse_code::LeftButton = VK_LBUTTON;
    const size_t mouse_code::RightButton = VK_RBUTTON;
    const size_t mouse_code::MiddleButton = VK_MBUTTON;
    const size_t mouse_code::AdditionalButton1 = VK_XBUTTON1;
    const size_t mouse_code::AdditionalButton2 = VK_XBUTTON2;
} // namespace perun

#endif
