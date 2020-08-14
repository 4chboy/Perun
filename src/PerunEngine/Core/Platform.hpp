#pragma once

#include "Window.hpp"
#include "Input/Input.hpp"

namespace perun
{
    class PERUN_API Platform final
    {
    public:
        static std::unique_ptr<Window> CreateWindow(WindowProps windowProps, Window::SubmitFn submitFn);
        static std::unique_ptr<Input> CreateInput();
    };
} // namespace perun
