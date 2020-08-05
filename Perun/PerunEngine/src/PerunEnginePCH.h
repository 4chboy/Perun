#ifndef _PERUNENGINE_PCH_H
#define _PERUNENGINE_PCH_H

#include <fstream>
#include <sstream>

#include <cstdint>
#include <memory>
#include <functional>
#include <thread>
#include <atomic>

#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>

#include "Definitions.h"

#ifdef PERUNENGINE_OS_WINDOWS
    #include <Windows.h>
    #include <Windowsx.h>
    #include <WinGdi.h>
    #include <glad/wgl.h>
#else
    #include <glad/gl.h>
#endif

#endif //_PERUNENGINE_PCH_H
