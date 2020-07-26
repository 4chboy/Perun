cmake_minimum_required(VERSION 3.16)
project(Sandbox)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    add_compile_options(/MP)
    add_compile_options(/W4 /wd4201 /WX)
else()
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    add_compile_options(-W -Wall -Werror)
endif()

set(SandboxHeaders

        )
set(SandboxSources
        src/EntryPoint.cpp
        )

add_subdirectory(dep/lua-5.4.0)

add_executable(Sandbox ${SandboxHeaders} ${SandboxSources})
target_link_libraries(Sandbox PUBLIC LuaLib)
