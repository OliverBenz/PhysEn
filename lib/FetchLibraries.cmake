cmake_minimum_required(VERSION 3.14)

include(FetchContent)

# GTest
# Version 1.13.0
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        b796f7d44681514f58a683a3a71ff17c94edb0c1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For Windows: Prevent overriding the parent project's compiler/linker settings

FetchContent_MakeAvailable(googletest)
set_target_properties(gtest      PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gtest_main PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gmock      PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gmock_main PROPERTIES FOLDER "${ideFolderExternal}")