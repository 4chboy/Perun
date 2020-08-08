include(CMakeSources.txt)

add_library(perun_engine SHARED ${PERUN_SOURCES})

target_include_directories(perun_engine PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_precompile_headers(perun_engine PUBLIC
    ${PERUN_PCH}
)

target_link_libraries(perun_engine
    glm
    Glad
)

if (WIN32)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUNENGINE_OS_WINDOWS
            -DPERUNENGINE_BUILD_DLL
            )
elseif (APPLE)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUNENGINE_OS_MACOSX
            )
elseif (IOS)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUNENGINE_OS_IOS
            )
elseif (ANDROID)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUNENGINE_OS_ANDROID
            )
elseif (UNIX)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUNENGINE_OS_LINUX
            )
endif ()