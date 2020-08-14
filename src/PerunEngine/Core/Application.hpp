#pragma once

#include <memory>
#include "Definitions.hpp"

namespace perun
{
    class PERUN_API Application
    {
    public:
        virtual ~Application() = default;

        virtual void Start() = 0;
        virtual void Run() = 0;
        [[nodiscard]] virtual bool ShouldClose() const = 0;
    };

    std::unique_ptr<Application> CreateApplication();
} // namespace perun
