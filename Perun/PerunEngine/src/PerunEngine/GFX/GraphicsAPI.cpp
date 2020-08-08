#include "PerunEnginePCH.h"
#include "GraphicsAPI.h"
#include "API/OpenGL/OpenGLAPI.h"

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
