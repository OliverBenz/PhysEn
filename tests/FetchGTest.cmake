# Get Google Tests
include(FetchContent)
FetchContent_Declare(
        googletest
        # Used GTest commit
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

# In IDE - Sort under folder "External"
set_target_properties(gtest      PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gtest_main PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gmock      PROPERTIES FOLDER "${ideFolderExternal}")
set_target_properties(gmock_main PROPERTIES FOLDER "${ideFolderExternal}")
