#ifndef _PERUNENGINE_ENTRY_POINT_H
#define _PERUNENGINE_ENTRY_POINT_H

int main(int argc, char* argv[])
{
    auto application = perun::CreateApplication();
    application->Start();
    while (!application->ShouldClose()) {
        application->Run();
    }
};

#endif //_PERUNENGINE_ENTRY_POINT_H
