add_library(math SHARED
	Vector.hpp
	Vector.cpp
	Matrix.hpp
	Matrix.cpp
)

target_link_libraries(math PUBLIC common)