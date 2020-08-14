#pragma once

#include <PerunEngine/Perun.hpp>

int main(int argc, char* argv[])
{
    auto application = perun::CreateApplication();
    application->Start();
    while (!application->ShouldClose()) {
        application->Run();
    }
}
