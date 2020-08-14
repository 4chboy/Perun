#pragma once

#include <memory>
#include <definitions.hpp>

namespace perun
{
    class PERUN_API application
    {
    public:
        virtual ~application() = default;

        virtual void start() = 0;
        virtual void run() = 0;
        [[nodiscard]] virtual bool should_close() const = 0;
    };

    std::unique_ptr<application> create_application();
} // namespace perun
