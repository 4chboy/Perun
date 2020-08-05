#ifndef _PERUNENGINE_GRAPHICS_CONTEXT_H
#define _PERUNENGINE_GRAPHICS_CONTEXT_H
#include "PerunEngine/Core/Window.h"
#include "GraphicsAPIType.h"

namespace perun {

    class PERUNENGINE_API GraphicsContext {
    public:
        virtual ~GraphicsContext() = default;

        virtual void SwapBuffers() = 0;

        [[nodiscard]] inline const std::unique_ptr<Window>& GetWindow() const noexcept { return window; }
        [[nodiscard]] inline GraphicsAPIType GetType() const noexcept { return type; }
        [[nodiscard]] static std::unique_ptr<GraphicsContext> Create(std::unique_ptr<Window>& window, GraphicsAPIType apiType);

    protected:
        inline GraphicsContext(std::unique_ptr<Window>& window, GraphicsAPIType apiType) :
            window{ window },
            type{ apiType } { }

        std::unique_ptr<Window>& window;

    private:
        GraphicsAPIType type;
    };
}

#endif //_PERUNENGINE_GRAPHICS_CONTEXT_H
