# The project settings contains informatioon for
#  - Build type
#  - Optimization settings
#  - Output directory

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type specified - 'Debug' used.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)

    set_property(CACHE CMAKE_BUILD_TYPE
            PROPERTY STRINGS
            "Debug"
            "Release")
endif()

set(CMAKE_DEBUG_POSTFIX d CACHE STRING "Add 'd' to lib name in Debug build")