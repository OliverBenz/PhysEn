cmake_minimum_required(VERSION 3.12)

project("Physics Engine")
set(CMAKE_CXX_STANDARD 17)

option(buildTests "Create the unit tests for the project." ON)
option(buildExamples "Create examples for the project." ON)


# Setup project settings
include(cmake/ProjectSettings.cmake)
include(cmake/CompilerWarnings.cmake)


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)
