#pragma once

extern perun::application perun::create_application();

int main(int argc, char* argv[])
{
    auto application = perun::create_application();
    application->start();
    while (!application->should_close()) {
        application->run();
    }
}
