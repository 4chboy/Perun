#pragma once

#include <perun/utils/defs.hpp>
#include <perun/core/event_system/events/event.hpp>

#include <cstdint>
#include <string>
#include <functional>


namespace perun
{
    struct PERUN_API window_props final
    {
        uint32_t width, height;
        std::string title;
    };

    class PERUN_API window
    {
    public:
        using submit_fn = std::function<void(event*)>;
        struct window_core
        {
            window_props props;
            std::function<void(event*)> submit;
        };

        virtual ~window() = default;

        [[nodiscard]] inline uint32_t get_width() const
        {
            return core.props.width;
        }
        [[nodiscard]] inline uint32_t get_height() const
        {
            return core.props.height;
        }
        [[nodiscard]] inline const std::string& get_title() const
        {
            return core.props.title;
        }
        inline void submit_event(event* event) const
        {
            core.submit(event);
        }

        virtual void Update() = 0;

    protected:
        explicit window(const submit_fn& submitFn)
            : core{{}, std::move(submitFn)}
        {
        }
        window(const window_props& props, const submit_fn& submitFn)
            : core{props, submitFn}
        {
        }

        window_core core;
    };
} // namespace perun
