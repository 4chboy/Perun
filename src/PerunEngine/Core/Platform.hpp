#ifndef _PERUNENGINE_PLATFORM_H
#define _PERUNENGINE_PLATFORM_H

#include "Window.hpp"
#include "Input/Input.hpp"

namespace perun {

    class PERUNENGINE_API Platform final {
    public:
        static std::unique_ptr<Window> CreateWindow(WindowProps windowProps, Window::SubmitFn submitFn);
        static std::unique_ptr<Input> CreateInput();
    };
}

#endif //_PERUNENGINE_PLATFORM_H
