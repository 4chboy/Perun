#include "PerunEnginePCH.h"
#include "GraphicsContext.hpp"

#include "API/OpenGL/OpenGLContext.hpp"

namespace perun
{
    std::unique_ptr<GraphicsContext> GraphicsContext::Create(std::unique_ptr<Window>& window, GraphicsAPIType apiType)
    {
        switch (apiType) {
            case GraphicsAPIType::OpenGL: {
                return std::make_unique<OpenGLContext>(window);
            }
            case GraphicsAPIType::Undefined:
                [[fallthrough]];
            default: {
                return nullptr;
            }
        }
    }
} // namespace perun
