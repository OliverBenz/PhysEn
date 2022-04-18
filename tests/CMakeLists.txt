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

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include_directories("../src/")

# Get all test source files.
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(targetName physen.gtest)
add_executable(${targetName} ${sources})
target_link_libraries(${targetName} PUBLIC physen gtest_main)

add_test(NAME ${targetName} COMMAND tests)
