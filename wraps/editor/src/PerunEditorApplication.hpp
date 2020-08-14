#include <PerunEngine/Perun.hpp>

namespace perun
{
    class PerunEditorApplication final : public Application
    {
    public:
        void Start() override;
        void Run() override;
        [[nodiscard]] bool ShouldClose() const override;

    private:
        std::unique_ptr<Window> window;
        std::unique_ptr<GraphicsContext> context;
        std::unique_ptr<GraphicsAPI> api;
    };
} // namespace perun
