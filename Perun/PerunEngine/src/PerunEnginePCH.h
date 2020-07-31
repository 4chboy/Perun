#ifndef _PERUNENGINE_PCH_H
#define _PERUNENGINE_PCH_H

#include <cstdint>
#include <memory>
#include <functional>

#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>

#include <Windows.h>
#include <Windowsx.h>

#ifdef PERUNENGINE_OS_WINDOWS
    #ifdef PERUNENGINE_BUILD_DLL
        #define PERUNENGINE_API __declspec(dllexport)
    #else
        #define PERUNENGINE_API __declspec(dllimport)
    #endif
#else
    #define PERUNENGINE_API
#endif

#endif //_PERUNENGINE_PCH_H
