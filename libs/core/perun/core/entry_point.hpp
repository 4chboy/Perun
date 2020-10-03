#pragma once

#include <perun/core/application.hpp>

int main(int argc, char* argv[])
{
    auto application = perun::create_application();
    application->start();
    while (!application->should_close()) {
        application->run();
    }
}
