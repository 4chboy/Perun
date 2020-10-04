include(CMakeSources.txt)

set(PERUN_LIB_NAME perun_utils)
set(PERUN_LIB_TYPE STATIC)

add_library(${PERUN_LIB_NAME} ${PERUN_LIB_TYPE} ${PERUN_UTILS_SOURCES})
target_include_directories(${PERUN_LIB_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})