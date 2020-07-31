#include "PerunEnginePCH.h"
#include "Window.h"
#include "OS/Windows/WindowsWindow.h"

namespace perun {

    std::unique_ptr<Window> Window::Create(const WindowProps& props) {
#ifdef PERUNENGINE_OS_WINDOWS
        return std::make_unique<WindowsWindow>(props);
#else
        return nullptr;
#endif
    }

    Window::Window(const WindowProps& props) noexcept :
        core{ .props = props, .eventSystem = EventSystem{ }, .shouldClose = false } { }
}
