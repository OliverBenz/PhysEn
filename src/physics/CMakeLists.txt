# Settings
set(targetName "physen")

# Get files to build
include(Files.cmake)

# Create library
add_library(${targetName} STATIC
    ${physHeaders}
    ${physSources}
)

# Link to thread module for maths functions.
target_include_directories(${targetName} PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(${targetName} PRIVATE common maths)
set_target_properties(${targetName} PROPERTIES FOLDER "${ideFolderSource}")

# Setup project settings
set_project_warnings(${targetName})  # Which warnings to enable
set_compile_options(${targetName})   # Which extra compiler flags to enable
set_output_directory(${targetName})  # Set the output directory of the library

# Copy header files to output after build
copy_headers_to_output(${targetName} "${physHeaders}" "")

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=1)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=1)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${physHeaders} DESTINATION include/physen)