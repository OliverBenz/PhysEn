find_package(Threads)

# Settings
include(CustomCommands.cmake)
set(targetName "physen" CACHE STRING "Name of the main library.")

# Get files to build
include(common/Files.cmake)
include(maths/Files.cmake)
include(physics/Files.cmake)

# Create library
add_library(${targetName} STATIC
    # Common modules
    ${commonHeaders}
    ${commonSources}

    # Maths modules
    ${mathHeaders}
    ${mathSources}

    # Physics modules
    ${physHeaders}
    ${physSources}
)


# Link to thread module for maths functions.
target_link_libraries(${targetName} PRIVATE ${CMAKE_THREAD_LIBS_INIT})

# Setup project settings
set_project_warnings(${targetName})  # Which warnings to enable
set_compile_options(${targetName})   # Which extra compiler flags to enable
set_output_directory(${targetName})  # Set the output directory of the library

# Copy header files to output after build
copy_headers_to_output(${targetName} "${mathHeaders};${physHeaders};${commonHeaders}")

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=1)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=1)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${mathHeaders} ${physHeaders} ${commonHeaders} DESTINATION include/physen)