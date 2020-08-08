cmake_minimum_required(VERSION 3.16)
project(perun_engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Organize
#

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER CMake)

#
# Add
#

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)