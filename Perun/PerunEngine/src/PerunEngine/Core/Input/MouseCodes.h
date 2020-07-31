#ifndef _PERUNENGINE_MOUSE_CODES_H
#define _PERUNENGINE_MOUSE_CODES_H

namespace perun {

    enum class MouseCode : size_t {
#if defined(PERUNENGINE_OS_WINDOWS)
#endif
        LeftButton          = VK_LBUTTON,
        RightButton         = VK_RBUTTON,
        MiddleButton        = VK_MBUTTON,
        AdditionalButton1   = VK_XBUTTON1,
        AdditionalButton2   = VK_XBUTTON2,
    };
}

#endif //_PERUNENGINE_MOUSE_CODES_H
