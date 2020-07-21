#ifndef _SVAROGLANG_PCH_H
#define _SVAROGLANG_PCH_H

// SvarogLang/Exception.h
#include <string>

// SvarogLang/Logger.h
#include <memory>
#include <vector>
#include <map>

#define SVAROGLANG_NODISCARD [[nodiscard]]
#define SVAROGLANG_LIKELY    [[likely]]
#define SVAROGLANG_UNLIKELY  [[unlikely]]

#ifdef SVAROGLANG_OS_WINDOWS
    #ifdef SVAROGLANG_BUILD_DLL
        #define SVAROGLANG_API __declspec(dllexport)
    #else
        #define SVAROGLANG_API __declspec(dllimport)
    #endif
#else //SVAROGLANG_OS_WINDOWS
    #define SVAROGLANG_API
#endif //SVAROGLANG_OS_WINDOWS

#endif //_SVAROGLANG_PCH_H
