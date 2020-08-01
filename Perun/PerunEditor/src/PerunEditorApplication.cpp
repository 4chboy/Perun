#include "PerunEditorPCH.h"
#include "PerunEditorApplication.h"

#include <iostream>

namespace perun {

    void PerunEditorApplication::Start() {
        std::cout << "App was initialized" << std::endl;
    }

    void PerunEditorApplication::Run() {
        if (Input::IsKeyDown(KeyCode::A)) {
            std::cout << "A key is down" << std::endl;
        }
        window->Update();
        window->GetEventSystem().Dispatch(true);
    }

    bool PerunEditorApplication::ShouldClose() const {
        return window->IsShouldClose();
    }

    [[maybe_unused]] std::unique_ptr<Application> CreateApplication() {
        return std::make_unique<PerunEditorApplication>();
    }
}
