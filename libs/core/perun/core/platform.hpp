#pragma once

#include <perun/window/window.hpp>
#include <perun/input/input.hpp>

#include <memory>

namespace perun
{
    class PERUN_API platform final
    {
    public:
        static std::unique_ptr<window> create_window(window_props props, window::submit_fn submiter);
        static std::unique_ptr<input> create_input();
    };
} // namespace perun
