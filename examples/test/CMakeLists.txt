include(${CMAKE_CURRENT_LIST_DIR}/CMakeSources.txt)

add_executable(perun_test
    ${PERUN_TEST_SOURCES}
)

target_link_libraries(perun_test
    perun_core
)