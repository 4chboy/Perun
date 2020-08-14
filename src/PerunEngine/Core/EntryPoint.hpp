#pragma once

int main(int argc, char* argv[])
{
    auto application = perun::CreateApplication();
    application->Start();
    while (!application->ShouldClose()) {
        application->Run();
    }
}
