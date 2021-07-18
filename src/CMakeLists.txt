add_subdirectory(common)
add_subdirectory(maths)
add_subdirectory(objects)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp)

# Specify version
target_compile_definitions(main PUBLIC VERSION_MAJOR=1)
target_compile_definitions(main PUBLIC VERSION_MINOR=0)
target_compile_definitions(main PUBLIC VERSION_PATCH=0)