# Settings
set(targetName "common")

# Files
set(commonSources
    ${CMAKE_CURRENT_LIST_DIR}/dimension.cpp
)

set(commonHeaders
    ${CMAKE_CURRENT_LIST_DIR}/dimension.hpp
    ${CMAKE_CURRENT_LIST_DIR}/constants.hpp
)


# Create library
add_library(${targetName} STATIC
    ${commonHeaders}
    ${commonSources}
)

# Link to thread module for maths functions.
set_target_properties(${targetName} PROPERTIES FOLDER "${ideFolderSource}")

# Setup project settings
set_project_warnings(${targetName})  # Which warnings to enable
set_compile_options(${targetName})   # Which extra compiler flags to enable
set_output_directory(${targetName})  # Set the output directory of the library

# Copy header files to output after build
copy_headers_to_output(${targetName} "${commonHeaders}" "physen/common")

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=1)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=1)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${physHeaders} DESTINATION include/physen/common)
