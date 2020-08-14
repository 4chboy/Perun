#ifndef _PERUN_APPLICATION_H
#define _PERUN_APPLICATION_H

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

#endif //_PERUN_APPLICATION_H
