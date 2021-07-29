add_subdirectory(Common)
add_subdirectory(Maths)
add_subdirectory(Physics)

add_executable(main main.cpp)

# Specify version
target_compile_definitions(main PUBLIC VERSION_MAJOR=0)
target_compile_definitions(main PUBLIC VERSION_MINOR=1)
target_compile_definitions(main PUBLIC VERSION_PATCH=0)
