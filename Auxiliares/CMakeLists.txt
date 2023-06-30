cmake_minimum_required(VERSION 3.25)
project(PSS)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif ()


add_subdirectory("Auxiliar 3")
add_subdirectory("Auxiliar 6")
add_subdirectory("Auxiliar 10")
add_subdirectory("Auxiliar 12")