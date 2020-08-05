#include <PerunEngine/Perun.h>

namespace perun {

    class PerunEditorApplication final : public Application {
    public:
        void Start() override;
        void Run() override;
        [[nodiscard]] bool ShouldClose() const override;

    private:
        std::unique_ptr<Window> window;
        std::unique_ptr<GraphicsContext> context;
        std::unique_ptr<GraphicsAPI> api;
    };
}
