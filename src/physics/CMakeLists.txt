# Settings
set(targetName "physen")

# Files
set(physHeaders
    ${CMAKE_CURRENT_LIST_DIR}/object.hpp
    ${CMAKE_CURRENT_LIST_DIR}/circle.hpp
    ${CMAKE_CURRENT_LIST_DIR}/rectangle.hpp

    ${CMAKE_CURRENT_LIST_DIR}/optics.hpp
    ${CMAKE_CURRENT_LIST_DIR}/operators.hpp
)

set(physSources
    ${CMAKE_CURRENT_LIST_DIR}/object.cpp
    ${CMAKE_CURRENT_LIST_DIR}/circle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/rectangle.cpp

    ${CMAKE_CURRENT_LIST_DIR}/optics.cpp
    ${CMAKE_CURRENT_LIST_DIR}/operators.cpp
)


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
copy_headers_to_output(${targetName} "${physHeaders}" "physen")

# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=1)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=1)

# System installation
install(TARGETS ${targetName} DESTINATION lib)
install(FILES ${physHeaders} DESTINATION include/physen)
