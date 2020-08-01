#include "PerunEnginePCH.h"
#include "Input.h"
#include "OS/Windows/WindowsInput.h"

namespace perun {

    std::unique_ptr<Input> Input::Create() {
#if defined(PERUNENGINE_OS_WINDOWS)
        return std::make_unique<WindowsInput>();
#else
        return nullptr;
#endif
    }
}
