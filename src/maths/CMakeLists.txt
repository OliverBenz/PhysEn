find_package(Threads)

add_library(maths SHARED
		vector.hpp
		matrix.hpp
        matrixSolver.hpp
        integration.hpp
		integration.cpp
        complex.hpp
        complex.cpp
)

target_link_libraries(maths PUBLIC common ${CMAKE_THREAD_LIBS_INIT})