find_package(Threads)

add_library(maths SHARED
		vector.hpp
		matrix.hpp
		matrix.cpp
		matrixSolver.hpp
		matrixSolver.cpp
		integration.hpp
		integration.cpp
        complex.hpp
        complex.cpp
)

target_link_libraries(maths PUBLIC common ${CMAKE_THREAD_LIBS_INIT})