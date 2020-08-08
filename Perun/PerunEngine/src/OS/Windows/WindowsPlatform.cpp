#include "PerunEnginePCH.h"
#include "PerunEngine/Core/Platform.h"

#include "WindowsWindow.h"
#include "WindowsInput.h"

namespace perun {

    std::unique_ptr<Window> Platform::CreateWindow(WindowProps windowProps, Window::SubmitFn submitFn) {
        return std::make_unique<WindowsWindow>(std::move(windowProps), std::move(submitFn));;
    }

    std::unique_ptr<Input> Platform::CreateInput() {
        return std::make_unique<WindowsInput>();
    }
}
