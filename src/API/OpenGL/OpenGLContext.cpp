#include "PerunEnginePCH.hpp"
#include "OpenGLContext.hpp"

#include "OS/Windows/WindowsWindow.hpp"

namespace perun
{
    OpenGLContext::OpenGLContext(std::unique_ptr<Window>& window)
        : GraphicsContext{window, GraphicsAPIType::OpenGL}
    {
        context = reinterpret_cast<GladGLContext*>(malloc(sizeof(GladGLContext)));
    }

    OpenGLContext::~OpenGLContext()
    {
        free(context);
    }

    void OpenGLContext::SwapBuffers()
    {
    }
} // namespace perun
