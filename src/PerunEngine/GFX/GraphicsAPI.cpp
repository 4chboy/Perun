#include "PerunEnginePCH.hpp"
#include "GraphicsAPI.hpp"
#include "API/OpenGL/OpenGLAPI.hpp"

namespace perun {

    std::unique_ptr<GraphicsAPI> GraphicsAPI::Create(std::unique_ptr<GraphicsContext>& context) {
        switch (context->GetType()) {
        case GraphicsAPIType::OpenGL: {
            return std::make_unique<OpenGLAPI>(context);
        }
        case GraphicsAPIType::Undefined: [[fallthrough]];
        default: {
            return nullptr;
        }
        }
    }
}
