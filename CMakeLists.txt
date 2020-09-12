cmake_minimum_required(VERSION 3.12)
project(PhysicsEngine)

add_executable(main main.cpp)

# Specify version
target_compile_definitions(main PUBLIC VERSION_MAJOR=1)
target_compile_definitions(main PUBLIC VERSION_MINOR=0)
target_compile_definitions(main PUBLIC VERSION_PATCH=2)

# Add libraries
add_subdirectory(lib)

target_link_libraries(main PUBLIC object)
target_link_libraries(main PUBLIC math)
