cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

set(GLAD_VERSION 4.6.0)
project(Glad VERSION ${GLAD_VERSION} LANGUAGES C)
message(STATUS "Glad: Version ${GLAD_VERSION}")

set(GLAD_HEADERS include/glad/gl.h include/KHR/khrplatform.h)
set(GLAD_SOURCES src/gl.c)

if (WIN32)
    set(WGL_HEADERS include/glad/wgl.h)
    set(WGL_SOURCES src/wgl.c)
endif ()

add_library(Glad INTERFACE)
target_include_directories(Glad INTERFACE include)

if (BUILD_STATIC_LIBS)
    add_library(Glad_static STATIC
            ${GLAD_SOURCES} ${GLAD_HEADERS}
            ${WGL_SOURCES}  ${WGL_HEADERS}
            )
    set_target_properties(Glad_static PROPERTIES LINKER_LANGUAGE C)
    target_link_libraries(Glad_static PUBLIC Glad)
    add_library(Glad::Glad_static ALIAS Glad_static)
endif ()

if (BUILD_SHARED_LIBS)
    add_library(Glad_shared SHARED
            ${GLAD_SOURCES} ${GLAD_HEADERS}
            ${WGL_SOURCES}  ${WGL_HEADERS}
            )
    target_link_libraries(Glad_shared PUBLIC Glad)
    add_library(Glad::Glad_shared ALIAS Glad_shared)
    target_compile_definitions(Glad::Glad_shared PUBLIC
            -DGLAD_API_CALL_EXPORT
            -DGLAD_API_CALL_EXPORT_BUILD
            )
endif ()
