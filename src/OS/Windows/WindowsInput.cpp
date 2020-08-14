#if defined(PERUN_OS_WINDOWS)
    #include "PerunEnginePCH.hpp"
    #include "WindowsInput.hpp"
    #include <Windows.h>

namespace perun
{
    bool WindowsInput::IsKeyDown(KeyCode key) const noexcept
    {
        auto state = GetAsyncKeyState(static_cast<int>(key));
        return state < 0;
    }

    bool WindowsInput::IsMouseButtonDown(MouseCode button) const noexcept
    {
        auto state = GetAsyncKeyState(static_cast<int>(button));
        return state < 0;
    }

    std::pair<float, float> WindowsInput::GetMousePos() const noexcept
    {
        POINT pos = {.x = 0, .y = 0};
        GetCursorPos(&pos);
        return {static_cast<float>(pos.x), static_cast<float>(pos.y)};
    }

    const size_t KeyCode::Undefined = 0;
    const size_t KeyCode::BackSpace = VK_BACK;
    const size_t KeyCode::Tab = VK_TAB;
    const size_t KeyCode::Enter = VK_RETURN;
    const size_t KeyCode::Shift = VK_SHIFT;
    const size_t KeyCode::Ctrl = VK_CONTROL;
    const size_t KeyCode::Alt = VK_MENU;
    const size_t KeyCode::CapsLock = VK_CAPITAL;
    const size_t KeyCode::Escape = VK_ESCAPE;
    const size_t KeyCode::Space = VK_SPACE;
    const size_t KeyCode::PageUp = VK_PRIOR;
    const size_t KeyCode::PageDown = VK_NEXT;
    const size_t KeyCode::End = VK_END;
    const size_t KeyCode::Home = VK_HOME;
    const size_t KeyCode::Left = VK_LEFT;
    const size_t KeyCode::Up = VK_UP;
    const size_t KeyCode::Right = VK_RIGHT;
    const size_t KeyCode::Down = VK_DOWN;
    const size_t KeyCode::Print = VK_PRINT;
    const size_t KeyCode::PrintScreen = VK_SNAPSHOT;
    const size_t KeyCode::Insert = VK_INSERT;
    const size_t KeyCode::Delete = VK_DELETE;
    const size_t KeyCode::K0 = 0x30;
    const size_t KeyCode::K1 = 0x31;
    const size_t KeyCode::K2 = 0x32;
    const size_t KeyCode::K3 = 0x33;
    const size_t KeyCode::K4 = 0x34;
    const size_t KeyCode::K5 = 0x35;
    const size_t KeyCode::K6 = 0x36;
    const size_t KeyCode::K7 = 0x37;
    const size_t KeyCode::K8 = 0x38;
    const size_t KeyCode::K9 = 0x39;
    const size_t KeyCode::A = 0x41;
    const size_t KeyCode::B = 0x42;
    const size_t KeyCode::C = 0x43;
    const size_t KeyCode::D = 0x44;
    const size_t KeyCode::E = 0x45;
    const size_t KeyCode::F = 0x46;
    const size_t KeyCode::G = 0x47;
    const size_t KeyCode::H = 0x48;
    const size_t KeyCode::I = 0x49;
    const size_t KeyCode::J = 0x4A;
    const size_t KeyCode::K = 0x4B;
    const size_t KeyCode::L = 0x4C;
    const size_t KeyCode::M = 0x4D;
    const size_t KeyCode::N = 0x4E;
    const size_t KeyCode::O = 0x4F;
    const size_t KeyCode::P = 0x50;
    const size_t KeyCode::Q = 0x51;
    const size_t KeyCode::R = 0x52;
    const size_t KeyCode::S = 0x53;
    const size_t KeyCode::T = 0x54;
    const size_t KeyCode::U = 0x55;
    const size_t KeyCode::V = 0x56;
    const size_t KeyCode::W = 0x57;
    const size_t KeyCode::X = 0x58;
    const size_t KeyCode::Y = 0x59;
    const size_t KeyCode::Z = 0x5A;
    const size_t KeyCode::NumPad0 = VK_NUMPAD0;
    const size_t KeyCode::NumPad1 = VK_NUMPAD1;
    const size_t KeyCode::NumPad2 = VK_NUMPAD2;
    const size_t KeyCode::NumPad3 = VK_NUMPAD3;
    const size_t KeyCode::NumPad4 = VK_NUMPAD4;
    const size_t KeyCode::NumPad5 = VK_NUMPAD5;
    const size_t KeyCode::NumPad6 = VK_NUMPAD6;
    const size_t KeyCode::NumPad7 = VK_NUMPAD7;
    const size_t KeyCode::NumPad8 = VK_NUMPAD8;
    const size_t KeyCode::NumPad9 = VK_NUMPAD9;
    const size_t KeyCode::Multiply = VK_MULTIPLY;
    const size_t KeyCode::Add = VK_ADD;
    const size_t KeyCode::NumPadEnter = VK_SEPARATOR;
    const size_t KeyCode::Subtract = VK_SUBTRACT;
    const size_t KeyCode::NumPadDot = VK_DECIMAL;
    const size_t KeyCode::Divide = VK_DIVIDE;
    const size_t KeyCode::F1 = VK_F1;
    const size_t KeyCode::F2 = VK_F2;
    const size_t KeyCode::F3 = VK_F3;
    const size_t KeyCode::F4 = VK_F4;
    const size_t KeyCode::F5 = VK_F5;
    const size_t KeyCode::F6 = VK_F6;
    const size_t KeyCode::F7 = VK_F7;
    const size_t KeyCode::F8 = VK_F8;
    const size_t KeyCode::F9 = VK_F9;
    const size_t KeyCode::F10 = VK_F10;
    const size_t KeyCode::F11 = VK_F11;
    const size_t KeyCode::F12 = VK_F12;
    const size_t KeyCode::F13 = VK_F13;
    const size_t KeyCode::F14 = VK_F14;
    const size_t KeyCode::F15 = VK_F15;
    const size_t KeyCode::F16 = VK_F16;
    const size_t KeyCode::F17 = VK_F17;
    const size_t KeyCode::F18 = VK_F18;
    const size_t KeyCode::F19 = VK_F19;
    const size_t KeyCode::F20 = VK_F20;
    const size_t KeyCode::F21 = VK_F21;
    const size_t KeyCode::F22 = VK_F22;
    const size_t KeyCode::F23 = VK_F23;
    const size_t KeyCode::F24 = VK_F24;
    const size_t KeyCode::NumLock = VK_NUMLOCK;
    const size_t KeyCode::LeftShift = VK_LSHIFT;
    const size_t KeyCode::RightShift = VK_RSHIFT;
    const size_t KeyCode::LeftCtrl = VK_LCONTROL;
    const size_t KeyCode::RightCtrl = VK_RCONTROL;
    const size_t KeyCode::LeftAlt = VK_LMENU;
    const size_t KeyCode::RightAlt = VK_RMENU;

    const size_t MouseCode::Undefined = 0;
    const size_t MouseCode::LeftButton = VK_LBUTTON;
    const size_t MouseCode::RightButton = VK_RBUTTON;
    const size_t MouseCode::MiddleButton = VK_MBUTTON;
    const size_t MouseCode::AdditionalButton1 = VK_XBUTTON1;
    const size_t MouseCode::AdditionalButton2 = VK_XBUTTON2;
} // namespace perun

#endif
