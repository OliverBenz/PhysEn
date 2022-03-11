include(FetchContent)
FetchContent_Declare(
  googletest
  # Used GTest commit
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
# TODO: Add executable for every type of test (math, physics etc)
include_directories("../src/")

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(tests ${sources})

target_link_libraries(tests PUBLIC physics maths gtest_main)

add_test(NAME tests COMMAND tests)
