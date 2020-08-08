#ifndef _PERUNENGINE_DEFINITIONS_H
#define _PERUNENGINE_DEFINITIONS_H

#if defined(_WIN32) || defined(WIN32) || defined(WIN64)
    #define PERUNENGINE_OS_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
        #define PERUNENGINE_OS_IOS
    #elif TARGET_OS_MAC == 1
        #define PERUNENGINE_OS_MACOS
    #endif
#elif defined(__ANDROID__)
    #define PERUNENGINE_OS_ANDROID
#elif defined(__linux__)
    #define PERUNENGINE_OS_LINUX
#endif

#if defined(PERUNENGINE_OS_WINDOWS)
    #ifdef PERUNENGINE_BUILD_DLL
        #define PERUNENGINE_API __declspec(dllexport)
    #else
        #define PERUNENGINE_API __declspec(dllimport)
    #endif
#else
    #define PERUNENGINE_API
#endif

#endif //_PERUNENGINE_DEFINITIONS_H
