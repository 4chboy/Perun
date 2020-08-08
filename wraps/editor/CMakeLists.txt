cmake_minimum_required(VERSION 3.16)
project(PerunEditor)

set(CMAKE_CXX_STANDARD 20)

set(PerunEditorSrcDir
        ${PROJECT_SOURCE_DIR}/src
        )
set(PerunEditorPCHs
        ${PerunEditorSrcDir}/PerunEditorPCH.h
        )
set(PerunEditorHeaders
        ${PerunEditorSrcDir}/PerunEditorApplication.h
        )
set(PerunEditorSources
        ${PerunEditorSrcDir}/PerunEditorApplication.cpp
        )

add_executable(PerunEditor ${PerunEditorHeaders} ${PerunEditorSources})
target_precompile_headers(PerunEditor PUBLIC
        ${PerunEditorSrcDir}/PerunEditorPCH.h
        )
target_include_directories(PerunEditor PUBLIC ../PerunEngine/src)

if (WIN32)
    target_compile_definitions(PerunEditor PUBLIC
            -DPERUNENGINE_OS_WINDOWS
            )
elseif (APPLE)
    target_compile_definitions(PerunEditor PUBLIC
            -DPERUNENGINE_OS_MACOSX
            )
elseif (IOS)
    target_compile_definitions(PerunEditor PUBLIC
            -DPERUNENGINE_OS_IOS
            )
elseif (ANDROID)
    target_compile_definitions(PerunEditor PUBLIC
            -DPERUNENGINE_OS_ANDROID
            )
elseif (UNIX)
    target_compile_definitions(PerunEditor PUBLIC
            -DPERUNENGINE_OS_LINUX
            )
endif ()

target_link_directories(PerunEditor PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(PerunEditor PUBLIC PerunEngine)
