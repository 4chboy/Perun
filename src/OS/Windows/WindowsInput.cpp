#include "PerunEnginePCH.h"
#include "WindowsInput.h"

namespace perun {

    bool WindowsInput::IsKeyDownImpl(KeyCode key) const noexcept {
        auto state = GetAsyncKeyState(static_cast<int>(key));
        return state < 0;
    }

    bool WindowsInput::IsKeyOnImpl(KeyCode key) const noexcept {
        auto state = GetAsyncKeyState(static_cast<int>(key));
        return (state & 1) != 0;
    }

    bool WindowsInput::IsMouseButtonDownImpl(MouseCode button) const noexcept {
        auto state = GetAsyncKeyState(static_cast<int>(button));
        return state < 0;
    }

    std::pair<float, float> WindowsInput::GetMousePosImpl() const noexcept {
        POINT pos = { .x = 0, .y = 0 };
        GetCursorPos(&pos);
        return { static_cast<float>(pos.x), static_cast<float>(pos.y) };
    }
}