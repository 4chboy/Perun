cmake_minimum_required(VERSION 3.16)
project(PerunEngine)

set(CMAKE_CXX_STANDARD 20)

set(PerunEngineSrcDir
        ${PROJECT_SOURCE_DIR}/src
        )
file(GLOB_RECURSE PerunEnginePCHs    ${PerunEngineSrcDir}/*PCH.h)
file(GLOB_RECURSE PerunEngineHeaders ${PerunEngineSrcDir}/*.h)
file(GLOB_RECURSE PerunEngineSources ${PerunEngineSrcDir}/*.cpp)
file(GLOB_RECURSE StbHeaders         ${PROJECT_SOURCE_DIR}/dep/stb/include/*.h)
file(GLOB_RECURSE StbSources         ${PROJECT_SOURCE_DIR}/dep/stb/include/*.cpp)

set(BUILD_STATIC_LIBS ON)
add_subdirectory(dep/glm)
add_subdirectory(dep/glad)

add_library(PerunEngine SHARED
        ${PerunEngineHeaders}
        ${PerunEngineSources}
        ${StbHeaders}
        ${StbSources}
        )
target_precompile_headers(PerunEngine PUBLIC
        ${PerunEnginePCHs}
        )
target_include_directories(PerunEngine PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/dep/glm
        ${PROJECT_SOURCE_DIR}/dep/glad/include
        ${PROJECT_SOURCE_DIR}/dep/stb/include
        )
target_link_libraries(PerunEngine PUBLIC
        glm::glm_static
        Glad::Glad_static
        )

if (WIN32)
    target_compile_definitions(PerunEngine PUBLIC
            -DPERUNENGINE_OS_WINDOWS
            -DPERUNENGINE_BUILD_DLL
            )
    target_link_libraries(PerunEngine PUBLIC
            user32.lib
            opengl32.lib
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
