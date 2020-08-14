#ifndef _PERUN_WINDOW_H
#define _PERUN_WINDOW_H

#include "EventSystem/Events/Event.hpp"

namespace perun {

    struct PERUN_API WindowProps final
    {
        uint32_t width, height;
        std::string title;
    };

    class PERUN_API Window
    {
    public:
        using SubmitFn = std::function<void(Event*)>;
        struct WindowCore {
            WindowProps props;
            std::function<void(Event*)> submit;
        };

        virtual ~Window() = default;
      
        [[nodiscard]] inline uint32_t GetWidth()           const { return core.props.width; }
        [[nodiscard]] inline uint32_t GetHeight()          const { return core.props.height; }
        [[nodiscard]] inline const std::string& GetTitle() const { return core.props.title; }
        inline void SubmitEvent(Event* event)              const { core.submit(event); }

        virtual void Update() = 0;

    protected:
        explicit Window(SubmitFn submitFn) :
            core{ { }, std::move(submitFn) } { }
        Window(WindowProps windowProps, SubmitFn submitFn) :
            core{ std::move(windowProps), std::move(submitFn) } { }

        WindowCore core;
    };
} // namespace perun

#endif //_PERUN_WINDOW_H
