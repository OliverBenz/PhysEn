#include <gtest/gtest.h>
#include <iostream>

#include "../../src/maths/Matrix.hpp"
#include "../../src/maths/MatrixSolver.hpp"

using namespace PhysEn;

TEST(Matrix, Solver){
	Size size(5);
	Maths::Matrix matrix(size);

	// Fill matrix
	for(size_t i = 0; i < size.rows; i++)
		for(size_t j = 0; j < size.columns; j++)
			matrix[i][j] = i + j;
	
	std::cout << matrix;
	makeUpperTriangle(matrix);
	std::cout << matrix;
	
}

TEST(Matrix, Operators){
	{  // []
		Size size(5);
		Maths::Matrix matrix(Maths::MatrixType::Unity, size);
		for(size_t i = 0; i < size.rows; i++){
			for(size_t j = 0; j < size.columns; j++) {
				if(i == j)
					ASSERT_EQ(matrix[i][j], 1);
				else
					ASSERT_EQ(matrix[i][j], 0);
			}
		}
		matrix[0][1] = 6;
		EXPECT_EQ(matrix[0][1], 6);
	}
}

TEST(Matrix, Calculations){
	// TODO: Write tests

	Maths::Matrix m1(Maths::MatrixType::Unity, Size(5, 5));
	Maths::Matrix m2 = (float)2*m1;

	Maths::Matrix multOne(Maths::MatrixType::Random, Size(3,2));
	Maths::Matrix multTwo(Maths::MatrixType::Random, Size(2, 7));
	Maths::Matrix m3 = multOne * multTwo;

	EXPECT_EQ(true, true);
}