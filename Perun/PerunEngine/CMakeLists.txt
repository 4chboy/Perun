cmake_minimum_required(VERSION 3.16)
project(PerunEngine)

set(CMAKE_CXX_STANDARD 20)

set(PerunEngineSrcDir src)
set(PerunEnginePCHs
        ${PerunEngineSrcDir}/PerunEnginePCH.h
        )
set(PerunEngineHeaders
        ${PerunEngineSrcDir}/PerunEngine/Shape.h
        )
set(PerunEngineSources
        ${PerunEngineSrcDir}/PerunEngine/Shape.h
        )

add_executable(PerunEngine ${PerunEngineHeaders} ${PerunEngineSources})
target_precompile_headers(PerunEngine PUBLIC
        ${PerunEnginePCHs}
        )
target_include_directories(PerunEngine PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        )