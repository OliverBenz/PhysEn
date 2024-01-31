# Settings
include(FetchGTest.cmake)
set(targetName "physen.gtest")

# Get files to build
include(common/Files.cmake)
include(maths/Files.cmake)
include(physics/Files.cmake)

# Create executable
add_executable(${targetName}
    ${commonTests}
    ${mathTests}
    ${physTests}
)

# Link to required libraries
target_include_directories(${targetName} PRIVATE "${CMAKE_BINARY_DIR}/out/include/physen")
target_link_libraries(${targetName} PUBLIC physen gtest_main)
set_target_properties(${targetName} PROPERTIES FOLDER "${ideFolderSource}")

# Setup project settings
set_project_warnings(${targetName})  # Which warnings to enable
set_compile_options(${targetName})   # Which extra compiler flags to enable

# Add tests
add_test(NAME ${targetName} COMMAND tests)