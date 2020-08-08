#ifndef _PERUNENGINE_KEY_CODES_H
#define _PERUNENGINE_KEY_CODES_H

namespace perun {

    enum class KeyCode : size_t {
#if defined(PERUNENGINE_OS_WINDOWS)
#endif
        BackSpace       = VK_BACK,
        Tab             = VK_TAB,
        Clear           = VK_CLEAR,
        Enter           = VK_RETURN,
        Shift           = VK_SHIFT,
        Ctrl            = VK_CONTROL,
        Alt             = VK_MENU,
        Pause           = VK_PAUSE,
        CapsLock        = VK_CAPITAL,
        Escape          = VK_ESCAPE,
        Space           = VK_SPACE,
        PageUp          = VK_PRIOR,
        PageDown        = VK_NEXT,
        End             = VK_END,
        Home            = VK_HOME,
        Left            = VK_LEFT,
        Up              = VK_UP,
        Right           = VK_RIGHT,
        Down            = VK_DOWN,
        Select          = VK_SELECT,
        Print           = VK_PRINT,
        Execute         = VK_EXECUTE,
        PrintScreen     = VK_SNAPSHOT,
        Insert          = VK_INSERT,
        Delete          = VK_DELETE,
        Help            = VK_HELP,
        K0              = 0x30,
        K1              = 0x31,
        K2              = 0x32,
        K3              = 0x33,
        K4              = 0x34,
        K5              = 0x35,
        K6              = 0x36,
        K7              = 0x37,
        K8              = 0x38,
        K9              = 0x39,
        A               = 0x41,
        B               = 0x42,
        C               = 0x43,
        D               = 0x44,
        E               = 0x45,
        F               = 0x46,
        G               = 0x47,
        H               = 0x48,
        I               = 0x49,
        J               = 0x4A,
        K               = 0x4B,
        L               = 0x4C,
        M               = 0x4D,
        N               = 0x4E,
        O               = 0x4F,
        P               = 0x50,
        Q               = 0x51,
        R               = 0x52,
        S               = 0x53,
        T               = 0x54,
        U               = 0x55,
        V               = 0x56,
        W               = 0x57,
        X               = 0x58,
        Y               = 0x59,
        Z               = 0x5A,
        Sleep           = VK_SLEEP,
        NumPad0         = VK_NUMPAD0,
        NumPad1         = VK_NUMPAD1,
        NumPad2         = VK_NUMPAD2,
        NumPad3         = VK_NUMPAD3,
        NumPad4         = VK_NUMPAD4,
        NumPad5         = VK_NUMPAD5,
        NumPad6         = VK_NUMPAD6,
        NumPad7         = VK_NUMPAD7,
        NumPad8         = VK_NUMPAD8,
        NumPad9         = VK_NUMPAD9,
        NumPadMultiply  = VK_MULTIPLY,
        NumPadAdd       = VK_ADD,
        NumPadEnter     = VK_SEPARATOR,
        NumPadSubtract  = VK_SUBTRACT,
        NumPadDot       = VK_DECIMAL,
        NumPadDivide    = VK_DIVIDE,
        F1              = VK_F1,
        F2              = VK_F2,
        F3              = VK_F3,
        F4              = VK_F4,
        F5              = VK_F5,
        F6              = VK_F6,
        F7              = VK_F7,
        F8              = VK_F8,
        F9              = VK_F9,
        F10             = VK_F10,
        F11             = VK_F11,
        F12             = VK_F12,
        F13             = VK_F13,
        F14             = VK_F14,
        F15             = VK_F15,
        F16             = VK_F16,
        F17             = VK_F17,
        F18             = VK_F18,
        F19             = VK_F19,
        F20             = VK_F20,
        F21             = VK_F21,
        F22             = VK_F22,
        F23             = VK_F23,
        F24             = VK_F24,
        NumLock         = VK_NUMLOCK,
        ScrollLock      = VK_SCROLL,
        LeftShift       = VK_LSHIFT,
        RightShift      = VK_RSHIFT,
        LeftCtrl        = VK_LCONTROL,
        RightCtrl       = VK_RCONTROL,
        LeftAlt         = VK_LMENU,
        RightAlt        = VK_RMENU,
    };
}

#endif //_PERUNENGINE_KEY_CODES_H