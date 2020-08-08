#ifndef _PERUNENGINE_WINDOWS_INPUT_H
#define _PERUNENGINE_WINDOWS_INPUT_H
#include "PerunEngine/Core/Input/Input.hpp"

namespace perun {

    class WindowsInput final : public Input {
    public:
        WindowsInput() noexcept = default;
        ~WindowsInput() noexcept override = default;

    protected:
        [[nodiscard]] bool IsKeyDownImpl(KeyCode key) const noexcept override;
        [[nodiscard]] bool IsKeyOnImpl(KeyCode key) const noexcept override;
        [[nodiscard]] bool IsMouseButtonDownImpl(MouseCode button) const noexcept override;
        [[nodiscard]] std::pair<float, float> GetMousePosImpl() const noexcept override;
    };
}

#endif //_PERUNENGINE_WINDOWS_INPUT_H
