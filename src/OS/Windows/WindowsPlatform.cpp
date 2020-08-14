#if defined(PERUN_OS_WINDOWS)
    #include <PerunEnginePCH.hpp>
    #include <PerunEngine/Core/Platform.hpp>

    #include <OS/Windows/WindowsWindow.hpp>
    #include <OS/Windows/WindowsInput.hpp>

namespace perun
{
    std::unique_ptr<Window> Platform::CreateWindow(WindowProps windowProps, Window::SubmitFn submitFn)
    {
        return std::make_unique<WindowsWindow>(std::move(windowProps), std::move(submitFn));
    }

    std::unique_ptr<Input> Platform::CreateInput()
    {
        return std::make_unique<WindowsInput>();
    }
} // namespace perun

#endif
