#ifndef _PERUN_MOUSE_CODES_H
#define _PERUN_MOUSE_CODES_H

namespace perun
{
    class PERUN_API MouseCode final
    {
    public:
        static const size_t Undefined;
        static const size_t LeftButton;
        static const size_t RightButton;
        static const size_t MiddleButton;
        static const size_t AdditionalButton1;
        static const size_t AdditionalButton2;

        constexpr MouseCode(size_t value) :
            code{ value } { }
        template <typename T> requires std::is_convertible_v<T, size_t>
        explicit constexpr MouseCode(const T& value) :
            code{ static_cast<size_t>(value) } { }
        template <typename T> requires std::is_convertible_v<T, size_t>
        constexpr operator T() const { return static_cast<size_t>(code); }

        template <typename T> requires std::is_convertible_v<T, size_t>
        constexpr bool operator ! () const { return code == Undefined; }
        template <typename T> requires std::is_convertible_v<T, size_t>
        constexpr bool operator == (const T& value) const { return code == static_cast<size_t>(value); }
        template <typename T> requires std::is_convertible_v<T, size_t>
        constexpr bool operator != (const T& value) const { return code != static_cast<size_t>(value); }

    private:
        size_t code;
    };
} // namespace perun

#endif //_PERUN_MOUSE_CODES_H
