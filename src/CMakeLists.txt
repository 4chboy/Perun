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

target_compile_options(perun_engine PUBLIC "-fconcepts")

if (WIN32)
    target_compile_definitions(perun_engine PUBLIC
            -DPERUN_BUILD_DLL
            )
endif ()