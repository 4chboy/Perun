#ifndef _PERUN_DEFINITIONS_H
#define _PERUN_DEFINITIONS_H

#if defined(_WIN32) || defined(WIN32) || defined(WIN64)
    #define PERUN_OS_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
        #define PERUN_OS_IOS
    #elif TARGET_OS_MAC == 1
        #define PERUN_OS_MACOS
    #endif
#elif defined(__ANDROID__)
    #define PERUN_OS_ANDROID
#elif defined(__linux__)
    #define PERUN_OS_LINUX
#endif

#ifdef PERUN_OS_WINDOWS
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

#endif //_PERUN_DEFINITIONS_H
