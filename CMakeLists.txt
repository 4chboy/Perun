cmake_minimum_required(VERSION 3.16)
project(perun_engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PERUN_SHARED OFF)

#
# Organize
#

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER CMake)

if(PERUN_SHARED)
    add_definitions("-DPERUN_SHARED_LIBRARY=1")
    add_definitions("-DPERUN_STATIC_LIBRARY=0")
else()
    add_definitions("-DPERUN_SHARED_LIBRARY=0")
    add_definitions("-DPERUN_STATIC_LIBRARY=1")
endif()

#
# Add
#

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)