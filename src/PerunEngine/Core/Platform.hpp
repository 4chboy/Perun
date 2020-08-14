#pragma once

#include <PerunEngine/Core/Window.hpp>
#include <PerunEngine/Core/Input/Input.hpp>

namespace perun
{
    class PERUN_API Platform final
    {
    public:
        static std::unique_ptr<Window> CreateWindow(WindowProps windowProps, Window::SubmitFn submitFn);
        static std::unique_ptr<Input> CreateInput();
    };
} // namespace perun
