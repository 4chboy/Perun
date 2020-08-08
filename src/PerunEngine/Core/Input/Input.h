#ifndef _PERUNENGINE_INPUT_H
#define _PERUNENGINE_INPUT_H
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace perun {

    class PERUNENGINE_API Input {
    public:
        virtual ~Input() noexcept = default;

        [[nodiscard]] static bool IsKeyDown(KeyCode key) noexcept {
            return instance->IsKeyDownImpl(key);
        }
        [[nodiscard]] static bool IsKeyOn(KeyCode key) noexcept {
            return instance->IsKeyOnImpl(key);
        }
        [[nodiscard]] static bool IsMouseButtonDown(MouseCode button) noexcept {
            return instance->IsMouseButtonDownImpl(button);
        }
        [[nodiscard]] static std::pair<float, float> GetMousePos() noexcept {
            return instance->GetMousePosImpl();
        }
        [[nodiscard]] static float GetMousePosX() noexcept {
            auto [ x, y ] = GetMousePos();
            return x;
        }
        [[nodiscard]] static float GetMousePosY() noexcept {
            auto [ x, y ] = GetMousePos();
            return y;
        }

    protected:
        Input() noexcept = default;

        [[nodiscard]] virtual bool IsKeyDownImpl(KeyCode key) const noexcept = 0;
        [[nodiscard]] virtual bool IsKeyOnImpl(KeyCode key) const noexcept = 0;
        [[nodiscard]] virtual bool IsMouseButtonDownImpl(MouseCode button) const noexcept = 0;
        [[nodiscard]] virtual std::pair<float, float> GetMousePosImpl() const noexcept = 0;

    private:
        static std::unique_ptr<Input> Create();
        inline static std::unique_ptr<Input> instance = Create();
    };
}

#endif //_PERUNENGINE_INPUT_H
