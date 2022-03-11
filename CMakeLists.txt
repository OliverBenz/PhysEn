cmake_minimum_required(VERSION 3.12)
project(PhysEn)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic)

add_subdirectory(src)
add_subdirectory(tests)

# TODO: Only build when specified
add_subdirectory(examples)
