# Settings
set(targetName "maths")

# Files
set(mathHeaders
    ${CMAKE_CURRENT_LIST_DIR}/complex.hpp
    ${CMAKE_CURRENT_LIST_DIR}/integration.hpp
    ${CMAKE_CURRENT_LIST_DIR}/matrix.hpp
    ${CMAKE_CURRENT_LIST_DIR}/matrixSolver.hpp
    ${CMAKE_CURRENT_LIST_DIR}/vector.hpp
)

set(mathSources
    ${CMAKE_CURRENT_LIST_DIR}/complex.cpp
    ${CMAKE_CURRENT_LIST_DIR}/integration.cpp
)


# Create library
add_library(${targetName} STATIC
    ${mathHeaders}
    ${mathSources}
)

# Link to thread module for maths functions.
target_link_libraries(${targetName} PRIVATE common)
set_target_properties(${targetName} PROPERTIES FOLDER "${ideFolderSource}")

# Setup project settings
set_project_warnings(${targetName})  # Which warnings to enable
set_compile_options(${targetName})   # Which extra compiler flags to enable
set_output_directory(${targetName})  # Set the output directory of the library

# Copy header files to output after build
copy_headers_to_output(${targetName} "${mathHeaders}" "physen/maths")

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=1)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=1)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${physHeaders} DESTINATION include/physen/maths)