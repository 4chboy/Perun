include(CMakeSources.txt)

set(PERUN_LIB_NAME perun_core)
set(PERUN_LIB_TYPE STATIC)

add_library(${PERUN_LIB_NAME} ${PERUN_LIB_TYPE} ${PERUN_CORE_SOURCES})
target_include_directories(${PERUN_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PERUN_LIB_NAME}
    perun_event_system
    perun_input
    perun_utils
    perun_window
)