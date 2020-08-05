#include "PerunEnginePCH.h"
#include "OpenGLContext.h"

#include "OS/Windows/WindowsWindow.h"

namespace perun {

    OpenGLContext::OpenGLContext(std::unique_ptr<Window>& window) :
        GraphicsContext{ window, GraphicsAPIType::OpenGL } {
        context = reinterpret_cast<GladGLContext*>(malloc(sizeof(GladGLContext)));
        gladLoadGLContext(context, reinterpret_cast<GLADloadfunc>(wglGetProcAddress));
#if defined(PERUNENGINE_OS_WINDOWS)
        auto hdc = GetDC(dynamic_cast<WindowsWindow*>(window.get())->GetHWND());
        gladLoadWGL(hdc, reinterpret_cast<GLADloadfunc>(wglGetProcAddress));
#endif
        wglSwapIntervalEXT((window->GetProps().vSync ? 1 : 0));
    }

    OpenGLContext::~OpenGLContext() {
        free(context);
    }

    void OpenGLContext::SwapBuffers() {
#if defined(PERUNENGINE_OS_WINDOWS)
        auto hdc = GetDC(dynamic_cast<WindowsWindow*>(window.get())->GetHWND());
        wglSwapLayerBuffers(hdc, WGL_SWAP_MAIN_PLANE);
#endif
    }
}
