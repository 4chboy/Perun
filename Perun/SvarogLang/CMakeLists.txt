cmake_minimum_required(VERSION 3.16)
project(SvarogLang)

set(SvarogLangSrcDir src/SvarogLang)
set(SvarogLangPCHs src/SvarogLangPCH.h)
set(SvarogLangHeaders ${SvarogLangSrcDir}/Exception.h ${SvarogLangSrcDir}/LoggerHub.h)
set(SvarogLangSources ${SvarogLangSrcDir}/Exception.cpp ${SvarogLangSrcDir}/LoggerHub.cpp)

if (WIN32)
    add_definitions(-DSVAROGLANG_OS_WINDOWS -DSVAROGLANG_BUILD_DLL)
endif (WIN32)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif(MSVC)

add_library(SvarogLang SHARED ${SvarogLangHeaders} ${SvarogLangSources})
set_target_properties(SvarogLang PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )
target_precompile_headers(SvarogLang PUBLIC ${SvarogLangPCHs})
target_include_directories(SvarogLang PUBLIC src dep/spdlog/include)