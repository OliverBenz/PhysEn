add_library(math SHARED
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
)

target_link_libraries(math PUBLIC common)