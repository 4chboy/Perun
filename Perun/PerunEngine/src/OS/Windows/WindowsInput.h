#ifndef _PERUNENGINE_WINDOWS_INPUT_H
#define _PERUNENGINE_WINDOWS_INPUT_H
#include "PerunEngine/Core/Input/Input.h"

namespace perun {

    class WindowsInput final : public Input {
    public:
        WindowsInput() noexcept = default;
        ~WindowsInput() noexcept override = default;

        [[nodiscard]] bool IsKeyDown(KeyCode key) const noexcept override;
        [[nodiscard]] bool IsMouseButtonDown(MouseCode button) const noexcept override;
        [[nodiscard]] std::pair<float, float> GetMousePos() const noexcept override;
    };
}

#endif //_PERUNENGINE_WINDOWS_INPUT_H
