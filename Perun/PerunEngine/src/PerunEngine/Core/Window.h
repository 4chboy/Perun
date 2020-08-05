#ifndef _PERUNENGINE_WINDOW_H
#define _PERUNENGINE_WINDOW_H
#include "EventSystem/EventSystem.h"

namespace perun {

    struct PERUNENGINE_API WindowProps final {
        std::uint32_t width, height;
        std::string title;
        bool fullScreen, vSync;
    };

    class PERUNENGINE_API Window {
    public:
        struct WindowCore {
            WindowProps props;
            EventSystem eventSystem;
            bool shouldClose;
        };

        virtual ~Window() = default;

        [[nodiscard]] inline const WindowProps& GetProps() const       { return core.props; }
        [[nodiscard]] inline EventSystem& GetEventSystem()             { return core.eventSystem; }
        [[nodiscard]] inline const EventSystem& GetEventSystem() const { return core.eventSystem; }
        [[nodiscard]] inline bool IsShouldClose() const                { return core.shouldClose; }

        virtual void Init() = 0;
        virtual void Update() = 0;
        [[nodiscard]] virtual std::unique_ptr<Window> CreateChild(const WindowProps& props) = 0;

        [[nodiscard]] static std::unique_ptr<Window> Create(const WindowProps& props);

    protected:
        explicit Window(const WindowProps& props) noexcept;

        WindowCore core;
    };
}

#endif //_PERUNENGINE_WINDOW_H
