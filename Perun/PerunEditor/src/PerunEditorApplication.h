#include <PerunEngine/Perun.h>

namespace perun {

    class PerunEditorApplication final : public Application {
    public:
        void Start() override;
        void Run() override;
        [[nodiscard]] bool ShouldClose() const override;
    };
}
