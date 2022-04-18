if(NOT BUILD_EXAMPLES)
    return()
endif()

include_directories("../src/physics")

# Example: Rocket
add_executable(rocket rocket.cpp)
target_link_libraries(rocket PRIVATE physen)