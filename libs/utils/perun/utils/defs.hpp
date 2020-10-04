#pragma once

#define PERUN_OS_WINDOWS 0
#define PERUN_OS_IOS 0
#define PERUN_OS_MACOS 0
#define PERUN_OS_ANDROID 0
#define PERUN_OS_LINUX 0

#if defined(_WIN32) || defined(WIN32) || defined(WIN64)
    #undef PERUN_OS_WINDOWS
    #define PERUN_OS_WINDOWS 1
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
        #undef PERUN_OS_IOS
        #define PERUN_OS_IOS 1
    #elif TARGET_OS_MAC == 1
        #undef PERUN_OS_MACOS
        #define PERUN_OS_MACOS 1
    #endif
#elif defined(__ANDROID__)
    #undef PERUN_OS_ANDROID
    #define PERUN_OS_ANDROID 1
#elif defined(__linux__)
    #undef PERUN_OS_LINUX
    #define PERUN_OS_LINUX 1
#endif

#if PERUN_OS_WINDOWS
    #if PERUN_SHARED_LIBRARY
        #define PERUN_API __declspec(dllexport)
    #elif PERUN_STATIC_LIBRARY
        #define PERUN_API
    #else
        #define PERUN_API __declspec(dllimport)
    #endif
#else
    #define PERUN_API __attribute__((__visibility__("default")))
#endif
