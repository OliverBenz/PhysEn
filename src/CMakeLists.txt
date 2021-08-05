find_package(Threads)

set(targetName "physen" CACHE STRING "Name of the main library.")

add_library(${targetName} STATIC
    # Common modules
    common/size.hpp common/size.cpp

    # Maths modules
    maths/vector.hpp
    maths/matrix.hpp
    maths/matrixSolver.hpp
    maths/integration.hpp maths/integration.cpp
    maths/complex.hpp maths/complex.cpp

    # Physics modules
    physics/object.hpp physics/object.cpp
    physics/circle.hpp physics/circle.cpp
    physics/rectangle.hpp physics/rectangle.cpp
    physics/optics.hpp physics/optics.cpp
    )

target_link_libraries(${targetName} PRIVATE ${CMAKE_THREAD_LIBS_INIT})


# Setup standard compiler warnings
include(../cmake/CompilerWarnings.cmake)
set_project_warnings(${targetName})


# Specify version
target_compile_definitions(${targetName} PUBLIC VERSION_MAJOR=0)
target_compile_definitions(${targetName} PUBLIC VERSION_MINOR=2)
target_compile_definitions(${targetName} PUBLIC VERSION_PATCH=0)
