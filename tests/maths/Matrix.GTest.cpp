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

TEST(Matrix, Construction){
	// TODO: Test all constructors
	{   // Type constructions
		Maths::Matrix matrix;

	}
	{   // Test initialize with vector
		Maths::Matrix matrix(Size(3), {
			{0, 1, 2},
			{1, 2, 3},
			{2, 3, 4}
		});

		for(size_t i = 0; i < matrix.getSize().rows; i++)
			for(size_t j = 0; j < matrix.getSize().columns; j++)
				EXPECT_EQ(matrix[i][j], static_cast<float>(i+j));
	}
}

TEST(Matrix, Operators){
	// TODO: Finish tests

	{  // []
		Size size(5);
		Maths::Matrix matrix(size, Maths::MatrixType::Unity);
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
	// TODO: Finish tests
	Maths::Matrix m1(Size(5, 5), Maths::MatrixType::Unity);
	Maths::Matrix m2 = (float)2*m1;

	Maths::Matrix multOne(Size(3, 2), Maths::MatrixType::Random);
	Maths::Matrix multTwo(Size(2, 7), Maths::MatrixType::Random);
	Maths::Matrix m3 = multOne * multTwo;

	EXPECT_EQ(true, true);
}