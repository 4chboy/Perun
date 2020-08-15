#pragma once

#include <definitions.hpp>

#include <cstddef>
#include <type_traits>

namespace perun
{
    class PERUN_API key_code final
    {
    public:
        static const size_t Undefined;
        static const size_t BackSpace;
        static const size_t Tab;
        static const size_t Enter;
        static const size_t Shift;
        static const size_t Ctrl;
        static const size_t Alt;
        static const size_t CapsLock;
        static const size_t Escape;
        static const size_t Space;
        static const size_t PageUp;
        static const size_t PageDown;
        static const size_t End;
        static const size_t Home;
        static const size_t Left;
        static const size_t Up;
        static const size_t Right;
        static const size_t Down;
        static const size_t Print;
        static const size_t PrintScreen;
        static const size_t Insert;
        static const size_t Delete;
        static const size_t K0;
        static const size_t K1;
        static const size_t K2;
        static const size_t K3;
        static const size_t K4;
        static const size_t K5;
        static const size_t K6;
        static const size_t K7;
        static const size_t K8;
        static const size_t K9;
        static const size_t A;
        static const size_t B;
        static const size_t C;
        static const size_t D;
        static const size_t E;
        static const size_t F;
        static const size_t G;
        static const size_t H;
        static const size_t I;
        static const size_t J;
        static const size_t K;
        static const size_t L;
        static const size_t M;
        static const size_t N;
        static const size_t O;
        static const size_t P;
        static const size_t Q;
        static const size_t R;
        static const size_t S;
        static const size_t T;
        static const size_t U;
        static const size_t V;
        static const size_t W;
        static const size_t X;
        static const size_t Y;
        static const size_t Z;
        static const size_t NumPad0;
        static const size_t NumPad1;
        static const size_t NumPad2;
        static const size_t NumPad3;
        static const size_t NumPad4;
        static const size_t NumPad5;
        static const size_t NumPad6;
        static const size_t NumPad7;
        static const size_t NumPad8;
        static const size_t NumPad9;
        static const size_t Multiply;
        static const size_t Add;
        static const size_t NumPadEnter;
        static const size_t Subtract;
        static const size_t NumPadDot;
        static const size_t Divide;
        static const size_t F1;
        static const size_t F2;
        static const size_t F3;
        static const size_t F4;
        static const size_t F5;
        static const size_t F6;
        static const size_t F7;
        static const size_t F8;
        static const size_t F9;
        static const size_t F10;
        static const size_t F11;
        static const size_t F12;
        static const size_t F13;
        static const size_t F14;
        static const size_t F15;
        static const size_t F16;
        static const size_t F17;
        static const size_t F18;
        static const size_t F19;
        static const size_t F20;
        static const size_t F21;
        static const size_t F22;
        static const size_t F23;
        static const size_t F24;
        static const size_t NumLock;
        static const size_t LeftShift;
        static const size_t RightShift;
        static const size_t LeftCtrl;
        static const size_t RightCtrl;
        static const size_t LeftAlt;
        static const size_t RightAlt;

        constexpr key_code(size_t value)
            : code{value}
        {
        }
        template<typename T, typename = std::enable_if_t<std::is_convertible_v<T, size_t>>>
        explicit constexpr key_code(const T& value)
            : code{static_cast<size_t>(value)}
        {
        }
        template<typename T, typename = std::enable_if_t<std::is_convertible_v<size_t, T>>>
        constexpr operator T() const
        {
            return static_cast<T>(code);
        }

        constexpr bool operator!() const
        {
            return code == Undefined;
        }
        template<typename T, typename = std::enable_if_t<std::is_convertible_v<T, size_t>>>
        constexpr bool operator==(const T& value) const
        {
            return code == static_cast<size_t>(value);
        }
        template<typename T, typename = std::enable_if_t<std::is_convertible_v<T, size_t>>>
        constexpr bool operator!=(const T& value) const
        {
            return code != static_cast<size_t>(value);
        }

    private:
        size_t code;
    };
} // namespace perun
