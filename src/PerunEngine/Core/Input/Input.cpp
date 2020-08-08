#include "PerunEnginePCH.hpp"
#include "Input.hpp"
#include "OS/Windows/WindowsInput.hpp"

namespace perun
{
    std::unique_ptr<Input> Input::Create()
    {
#if defined(PERUNENGINE_OS_WINDOWS)
        return std::make_unique<WindowsInput>();
#else
        return nullptr;
#endif
    }
} // namespace perun
