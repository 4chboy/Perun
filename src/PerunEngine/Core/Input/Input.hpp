#pragma once

#include <PerunEngine/Core/Input/KeyCodes.hpp>
#include <PerunEngine/Core/Input/MouseCodes.hpp>
#include <Definitions.hpp>

namespace perun
{
    class PERUN_API Input
    {
    public:
        virtual ~Input() noexcept = default;

        [[nodiscard]] virtual bool IsKeyDown(KeyCode key) const noexcept = 0;
        [[nodiscard]] inline bool IsKeyUp(KeyCode key) const noexcept
        {
            return !IsKeyDown(key);
        }
        [[nodiscard]] virtual bool IsMouseButtonDown(MouseCode button) const noexcept = 0;
        [[nodiscard]] inline bool IsMouseButtonUp(MouseCode button) const noexcept
        {
            return !IsMouseButtonDown(button);
        }
        [[nodiscard]] virtual std::pair<float, float> GetMousePos() const noexcept = 0;
        [[nodiscard]] inline float GetMousePosX() const noexcept
        {
            return GetMousePos().first;
        }
        [[nodiscard]] inline float GetMousePosY() const noexcept
        {
            return GetMousePos().second;
        }

    protected:
        Input() noexcept = default;
    };
} // namespace perun
