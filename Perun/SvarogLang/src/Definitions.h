#ifndef _SVAROGLANG_DEFINITIONS_H
#define _SVAROGLANG_DEFINITIONS_H

#define SVAROGLANG_NODISCARD [[nodiscard]]
#define SVAROGLANG_LIKELY    [[likely]]
#define SVAROGLANG_UNLIKELY  [[unlikely]]

#ifdef SVAROGLANG_OS_WINDOWS
    #ifdef SVAROGLANG_BUILD_DLL
        #define SVAROGLANG_API __declspec(dllexport)
    #else //SVAROGLANG_BUILD_DLL
        #define SVAROGLANG_API __declspec(dllimport)
    #endif //SVAROGLANG_BUILD_DLL
#else //SVAROGLANG_OS_WINDOWS
    #define SVAROGLANG_API
#endif //SVAROGLANG_OS_WINDOWS

#endif //_SVAROGLANG_DEFINITIONS_H
