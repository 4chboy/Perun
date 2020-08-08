#include "PerunEnginePCH.h"
#include "Application.h"

namespace perun {

    Application::Application() {
        window = Window::Create({
            .width = 1280,
            .height = 720,
            .title = "Perun Application",
            .fullScreen = false,
            .vSync = false
        });
    }
}
