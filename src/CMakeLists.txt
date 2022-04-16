find_package(Threads)

# Settings
set(targetName "physen" CACHE STRING "Name of the main library.")

# Get files to build
file(GLOB_RECURSE mathSourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/maths/*.cpp)
file(GLOB_RECURSE mathHeaderFiles ${CMAKE_CURRENT_SOURCE_DIR}/maths/*.hpp)

file(GLOB_RECURSE physSourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.cpp)
file(GLOB_RECURSE physHeaderFiles ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.hpp)

file(GLOB_RECURSE commonSourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp)
file(GLOB_RECURSE commonHeaderFiles ${CMAKE_CURRENT_SOURCE_DIR}/common/*.hpp)

# Create library
add_library(${targetName} STATIC
    # Common modules
    ${commonSourceFiles}
    ${commonHeaderFiles}

    # Maths modules
    ${mathSourceFiles}
    ${mathHeaderFiles}

    # Physics modules
    ${physSourceFiles}
    ${physHeaderFiles}
)

# Link to thread module for maths functions.
target_link_libraries(${targetName} PRIVATE ${CMAKE_THREAD_LIBS_INIT})

# Setup standard compiler warnings
include(../cmake/CompilerWarnings.cmake)
set_project_warnings(${targetName})

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=2)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=0)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${mathHeaderFiles} ${physHeaderFiles} ${commonHeaderFiles} DESTINATION include/physen)