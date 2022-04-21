if(NOT BUILD_TESTS)
    return()
endif()

# Get Google Tests
include(FetchContent)
FetchContent_Declare(
  googletest
  # Used GTest commit
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

# Setup gtest target
set(targetName physen.gtest)

include_directories("../src/")                                   # Reference to header files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)     # Get all test source files

add_executable(${targetName} ${sources})                         # Create executable
target_link_libraries(${targetName} PUBLIC physen gtest_main)    # Link the physen library
set_target_properties(${targetName} PROPERTIES FOLDER "Source")  # Add to IDE folder "Source"

add_test(NAME ${targetName} COMMAND tests)
