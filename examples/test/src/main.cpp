#include <perun/core/entry_point.hpp>

class App : public perun::application
{
    virtual void start() override
    {
    }

    virtual void run() override
    {
    }

    [[nodiscard]] virtual bool should_close() const override
    {
        return true;
    }
};

std::unique_ptr<perun::application> perun::create_application()
{
    return std::make_unique<App>();
}