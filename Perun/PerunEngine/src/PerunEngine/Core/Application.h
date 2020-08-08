#ifndef _PERUNENGINE_APPLICATION_H
#define _PERUNENGINE_APPLICATION_H
#include <memory>
#include "Definitions.h"

namespace perun {

    class PERUNENGINE_API Application {
    public:
        virtual ~Application() = default;

        virtual void Start() = 0;
        virtual void Run() = 0;
        [[nodiscard]] virtual bool ShouldClose() const = 0;
    };

    std::unique_ptr<Application> CreateApplication();
}

#endif //_PERUNENGINE_APPLICATION_H
