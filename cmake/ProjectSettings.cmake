# The project settings contains information for
#  - Build type
#  - Optimization settings
#  - Output directory
#  - IDE project tree

# ----- Setup build type settings -----
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type specified - 'Debug' used.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)

    set_property(CACHE CMAKE_BUILD_TYPE
            PROPERTY STRINGS
            "Debug"
            "Release")
endif()

# Use different name for debug library.
set(CMAKE_DEBUG_POSTFIX d CACHE STRING "Add 'd' to lib name in Debug build")


# ----- Setup ide folders -----
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)  # In solution files; we want the projects to be categorized

set(ideFolderSource   "Source"   CACHE STRING "IDE folder for source projects.")
set(ideFolderExamples "Examples" CACHE STRING "IDE folder for example projects.")
set(ideFolderExternal "External" CACHE STRING "IDE folder for external projects.")


# ----- Helper functions -----
function(set_compile_options targetName)
    set(optionsDebug)
    set(optionsRelease)

    # ----- Setup variables -----
    # MSVC compiler flags
    set(MSVC_DEBUG
        /Od  # Disable optimization
        /ZI  # Create full PDB file
    )
    set(MSVC_RELEASE
        /O2  # Maximize speed
        /Zi  # Create small PDB while keeping optimization
    )

    # GCC compiler flags
    set(GCC_DEBUG
        -O0  # No optimization
        -g   # Create debugging information
    )
    set(GCC_RELEASE
        -O3  # Maximize optimization
        -g   # Create debugging information (May sometimes be weird because of optimization)
    )

    # Clang compiler flags
    set(CLANG_DEBUG
        -O0  # No optimization
        -g   # Create debugging information
    )
    set(CLANG_RELEASE
        -O3  # Maximize optimization
        -g   # Create debugging information (May sometimes be weird because of optimization)
    )

    # ----- Switch which variables to use -----
    # Use the correct set of warning depending on the compiler
    set(OPTIONS_DEBUG)
    set(OPTIONS_RELEASE)

    if(MSVC)                                         # MSVC
        set(OPTIONS_DEBUG   ${MSVC_DEBUG})
        set(OPTIONS_RELEASE ${MSVC_RELEASE})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")  # Clang
        set(OPTIONS_DEBUG   ${GCC_DEBUG})
        set(OPTIONS_RELEASE ${GCC_RELEASE})
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")     # GCC
        set(OPTIONS_DEBUG   ${CLANG_DEBUG})
        set(OPTIONS_RELEASE ${CLANG_RELEASE})
    else()                                           # Else
        message(AUTHOR_WARNING "No extra compiler flags set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
    endif()


    # ----- Print which flags used -----
    message(STATUS "Compiler flags for Debug   ${OPTIONS_DEBUG}")
    message(STATUS "Compiler flags for Release ${OPTIONS_RELEASE}")

    # ----- Add flags to target -----
    target_compile_options(${targetName} PRIVATE "$<$<CONFIG:DEBUG>:${OPTIONS_DEBUG}>")
    target_compile_options(${targetName} PRIVATE "$<$<CONFIG:RELEASE>:${OPTIONS_RELEASE}>")
endfunction()


function(set_compile_definitions targetName)
    # NOTE: NDEBUG is already defined by default
    # target_compile_definitions(${targetName} PRIVATE $<$<CONFIG:Debug>:DEBUG>>)
    # target_compile_definitions(${targetName} PRIVATE $<$<CONFIG:Release>:NDEBUG>>)
endfunction()


function(set_output_directory targetName)
    set_target_properties(${targetName}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin"
    )
endfunction()