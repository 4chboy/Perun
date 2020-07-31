cmake_minimum_required(VERSION 3.16)
project(PerunEngine)

set(CMAKE_CXX_STANDARD 20)

set(PerunEngineSrcDir
        ${PROJECT_SOURCE_DIR}/src
        )
set(PerunEnginePCHs
        ${PerunEngineSrcDir}/PerunEnginePCH.h
        )
set(PerunEngineHeaders
        ${PerunEngineSrcDir}/PerunEngine/Core/Input/KeyCodes.h
        ${PerunEngineSrcDir}/PerunEngine/Core/Input/MouseCodes.h
        ${PerunEngineSrcDir}/PerunEngine/Core/Input/Input.h
        ${PerunEngineSrcDir}/OS/Windows/WindowsInput.h

        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/Events/Event.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/Events/KeyboardEvents.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/Events/MouseEvents.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/Events/WindowEvents.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/EventDispatcher.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EventSystem/EventSystem.h

        ${PerunEngineSrcDir}/PerunEngine/Core/Window.h
        ${PerunEngineSrcDir}/OS/Windows/WindowsWindow.h

        ${PerunEngineSrcDir}/PerunEngine/Core/Application.h
        ${PerunEngineSrcDir}/PerunEngine/Core/EntryPoint.h

        ${PerunEngineSrcDir}/PerunEngine/Perun.h
        )
set(PerunEngineSources
        ${PerunEngineSrcDir}/PerunEngine/Core/Input/Input.cpp
        ${PerunEngineSrcDir}/OS/Windows/WindowsInput.cpp

        ${PerunEngineSrcDir}/PerunEngine/Core/Window.cpp
        ${PerunEngineSrcDir}/OS/Windows/WindowsWindow.cpp

        ${PerunEngineSrcDir}/PerunEngine/Core/Application.cpp
        )

add_library(PerunEngine SHARED ${PerunEngineHeaders} ${PerunEngineSources})
target_precompile_headers(PerunEngine PUBLIC
        ${PerunEnginePCHs}
        )
target_include_directories(PerunEngine PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/dep/glm
        )

if (WIN32)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_WINDOWS
            -DPERUNENGINE_BUILD_DLL
            )
elseif (APPLE)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_MACOSX
            )
elseif (IOS)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_IOS
            )
elseif (ANDROID)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_ANDROID
            )
elseif (UNIX)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_LINUX
            )
endif ()
