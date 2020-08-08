add_library(stb
        ${CMAKE_CURRENT_LIST_DIR}/stb_image.h
        ${CMAKE_CURRENT_LIST_DIR}/stb_image.cpp
        )

target_include_directories(stb PUBLIC ${CMAKE_CURRENT_LIST_DIR})