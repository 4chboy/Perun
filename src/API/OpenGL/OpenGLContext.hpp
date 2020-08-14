#ifndef _PERUNENGINE_OPENGL_CONTEXT_H
#define _PERUNENGINE_OPENGL_CONTEXT_H
#include "PerunEngine/GFX/GraphicsContext.hpp"

namespace perun
{
    class PERUNENGINE_API OpenGLContext final : public GraphicsContext
    {
    public:
        explicit OpenGLContext(std::unique_ptr<Window>& window);
        ~OpenGLContext() override;

        void SwapBuffers() override;

        [[nodiscard]] inline GladGLContext& operator*() const
        {
            return *context;
        }

    private:
        GladGLContext* context;
    };
} // namespace perun

#endif //_PERUNENGINE_OPENGL_CONTEXT_H
