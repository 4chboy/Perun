#include "PerunEnginePCH.hpp"
#include "Application.hpp"

namespace perun
{
    Application::Application()
    {
        window = Window::Create({.width = 1280, .height = 720, .title = "Perun Application", .fullScreen = false, .vSync = false});
    }
} // namespace perun
