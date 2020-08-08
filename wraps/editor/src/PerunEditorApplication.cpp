#include "PerunEditorPCH.hpp"
#include "PerunEditorApplication.hpp"

#include <iostream>

namespace perun {

    void PerunEditorApplication::Start() {
        window = Window::Create({
            .width = 1280,
            .height = 720,
            .title = "PerunApp",
            .fullScreen = false,
            .vSync = false
        });
        context = GraphicsContext::Create(window, GraphicsAPIType::OpenGL);
        api = GraphicsAPI::Create(context);

        window->GetEventSystem().AddEventListener({
            .eventType = EventType::WindowResized,
            .dispatchFn = [&](Event& event) -> bool {
                auto resizeEvent = dynamic_cast<WindowResizedEvent*>(&event);
                api->SetViewport(0, 0, resizeEvent->width, resizeEvent->height);
                return true;
            }
        });
    }

    void PerunEditorApplication::Run() {
        api->Clear(0.3f, 0.3f, 0.3f, 1.0f);
        window->Update();
        window->GetEventSystem().Dispatch(true);
        context->SwapBuffers();
    }

    bool PerunEditorApplication::ShouldClose() const {
        return window->IsShouldClose();
    }

    [[maybe_unused]] std::unique_ptr<Application> CreateApplication() {
        return std::make_unique<PerunEditorApplication>();
    }
}
