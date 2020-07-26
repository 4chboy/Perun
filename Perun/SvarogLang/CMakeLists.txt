cmake_minimum_required(VERSION 3.16)
project(SvarogLang)

set(SvarogLangSrcDir src)
set(SvarogLangPCHs
        ${SvarogLangSrcDir}/SvarogLangPCH.h
        )
set(SvarogLangHeaders
        ${SvarogLangSrcDir}/Definitions.h
        ${SvarogLangSrcDir}/SvarogLang/Utilities.h
        ${SvarogLangSrcDir}/SvarogLang/Exception.h
        ${SvarogLangSrcDir}/SvarogLang/LoggerHub.h
        ${SvarogLangSrcDir}/SvarogLang/Reader.h
        ${SvarogLangSrcDir}/SvarogLang/Token.h
        ${SvarogLangSrcDir}/SvarogLang/Scanner.h
        )
set(SvarogLangSources
        ${SvarogLangSrcDir}/SvarogLang/Utilities.cpp
        ${SvarogLangSrcDir}/SvarogLang/Exception.cpp
        ${SvarogLangSrcDir}/SvarogLang/LoggerHub.cpp
        ${SvarogLangSrcDir}/SvarogLang/Reader.cpp
        ${SvarogLangSrcDir}/SvarogLang/Token.cpp
        ${SvarogLangSrcDir}/SvarogLang/Scanner.cpp
        )

if (WIN32)
    add_definitions(-DSVAROGLANG_OS_WINDOWS -DSVAROGLANG_BUILD_DLL)
endif (WIN32)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    add_compile_options(/MP)
    add_compile_options(/W4 /wd4201 /WX)
else ()
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    add_compile_options(-W -Wall -Werror -Wpedantic)
endif ()

add_library(SvarogLang SHARED
        ${SvarogLangHeaders}
        ${SvarogLangSources}
        )
target_precompile_headers(SvarogLang PUBLIC
        ${SvarogLangPCHs}
        )
target_include_directories(SvarogLang PUBLIC
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/dep/spdlog/include"
        )
