#include "PerunEditorPCH.hpp"
#include "PerunEditorApplication.hpp"

#include <iostream>

namespace perun {

    void PerunEditorApplication::Start() {
        std::cout << "App was initialized" << std::endl;
    }

    void PerunEditorApplication::Run() {
        if (Input::IsKeyDown(KeyCode::A)) {
            std::cout << "A key is down" << std::endl;
        }
    }

    bool PerunEditorApplication::ShouldClose() const {
        return window->IsShouldClose();
    }

    [[maybe_unused]] std::unique_ptr<Application> CreateApplication() {
        return std::make_unique<PerunEditorApplication>();
    }
}
