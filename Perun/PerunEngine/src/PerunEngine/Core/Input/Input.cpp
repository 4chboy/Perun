#include "PerunEnginePCH.h"
#include "Input.h"
#include "OS/Windows/WindowsInput.h"

namespace perun {

#if defined(PERUNENGINE_OS_WINDOWS)
    std::unique_ptr<Input> Input::instance = std::make_unique<WindowsInput>();
#else
    std::unique_ptr<Input> Input::instance = nullptr;
#endif
}
