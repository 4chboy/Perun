#ifndef _PERUNENGINE_ENTRY_POINT_H
#define _PERUNENGINE_ENTRY_POINT_H
#include <memory>

extern std::unique_ptr<perun::Application> perun::CreateApplication();

int main(int argc, char* argv[]) {
    auto application = perun::CreateApplication();
    application->Start();
    while (!application->ShouldClose()) {
        application->Run();
    }
};

#endif //_PERUNENGINE_ENTRY_POINT_H
