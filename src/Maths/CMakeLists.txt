find_package(Threads)

add_library(Maths SHARED
	Vector.hpp
	Vector.cpp
	Matrix.hpp
	Matrix.cpp
	MatrixSolver.hpp
	MatrixSolver.cpp
	Integration.hpp
	Integration.cpp
	Complex.hpp
	Complex.cpp
        Statistics.cpp Statistics.hpp)

target_link_libraries(Maths PUBLIC Common ${CMAKE_THREAD_LIBS_INIT})