if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type specified - 'Debug' used.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)

    set_property(CACHE CMAKE_BUILD_TYPE
            PROPERTY STRINGS
            "Debug"
            "Release")
endif()