#include <gtest/gtest.h>
#include <iostream>

#include "../../src/maths/Matrix.hpp"
#include "../../src/maths/MatrixSolver.hpp"

using namespace PhysEn;

TEST(Matrix, Solver){
	// TODO: Add false tests

	{   // Upper triangle
		Size size(3);
		Maths::Matrix matrix(size, {
				{2, 1, -1},
				{-3, -1, 2},
				{-2, 1, 2}
		});
		Maths::Matrix result(size, {
				{1, 0.5, -0.5},
				{0, 1, 1},
				{0, 0, 1}
		});

		Maths::makeUpperTriangle(matrix);
		EXPECT_EQ(matrix == result, true);
	}

	{   // Equation solver
		Maths::Matrix componentMatrix(Size(3), {
				{3, 4, 2},
				{5, 2, 1},
				{0, 0, 7}
		});
		Maths::Vector solution({1, 2, 3});

		Maths::Vector result = Maths::solveEquation(componentMatrix, solution);
		EXPECT_NEAR(result[0], 3.0  / 7.0, 0.00001);
		EXPECT_NEAR(result[1], -2.0 / 7.0, 0.00001);
		EXPECT_NEAR(result[2], 3.0  / 7.0, 0.00001);

		// Invalid vector size
		Maths::Vector solutionInvalid({4, 2, 3, 3});
		EXPECT_THROW(Maths::solveEquation(componentMatrix, solutionInvalid),
					 std::invalid_argument);
	}
}

TEST(Matrix, Construction){
	Size size(5);

	{   // Unity Matrix
		Maths::Matrix matrixUnity(size, Maths::MatrixType::Unity);
		for(size_t i = 0; i < size.rows; i++){
			for(size_t j = 0; j < size.columns; j++){
				if(i == j)
					ASSERT_EQ(matrixUnity[i][j], 1);
				else
					ASSERT_EQ(matrixUnity[i][j], 0);
			}
		}

		// Unity matrix has to be square
		EXPECT_THROW(Maths::Matrix(Size(2, 3), Maths::MatrixType::Unity),
					 std::invalid_argument);
	}

	{   // Zero Matrix
		Maths::Matrix matrixZero(size, Maths::MatrixType::Zero);
		for(size_t i = 0; i < size.rows; i++)
			for(size_t j = 0; j < size.columns; j++)
				ASSERT_EQ(matrixZero[i][j], 0);

	}

	{   // Vector Initialize
		Maths::Matrix matrix(Size(3), {
			{0, 1, 2},
			{1, 2, 3},
			{2, 3, 4}
		});

		for(size_t i = 0; i < matrix.getSize().rows; i++)
			for(size_t j = 0; j < matrix.getSize().columns; j++)
				EXPECT_EQ(matrix[i][j], static_cast<double>(i+j));

		// Expect error if list does not match the specified size
		EXPECT_THROW(Maths::Matrix(Size(3), {
				{3, 4, 5},
				{5, 32, 2}
		}), std::invalid_argument);

		EXPECT_THROW(Maths::Matrix(Size(3), {
				{3, 4, 5, 4},
				{5, 32, 2},
				{2, 3, 4}
		}), std::invalid_argument);
	}
}

TEST(Matrix, Submatrix){
	{  // 4x4 matrix
		Maths::Matrix matrix(Size(4),{
				{2, 3, 4, 5},
				{1, 2, 3, 4},
				{3, 6, 7, 2},
				{1, 4, 7, 0}
		});
		Maths::Matrix resultExpected(Size(3),{
				{1, 2, 3},
				{3, 6, 7},
				{1, 4, 7}
		});
		Maths::Matrix result = matrix.getSubMatrix(0, 3);
		EXPECT_EQ(result == resultExpected, true);
	}

	{
		// TODO: Handle 1x(any) matrix -> How do we handle zero matrix size?
	}

	{  // Invalid row/column index
		Maths::Matrix matrix(Size(4),{
				{2, 3, 4, 5},
				{1, 2, 3, 4},
				{3, 6, 7, 2},
				{1, 4, 7, 0}
		});

		// 4x4 matrix --> Cannot delete 5th entry (Index starts at 0)
		EXPECT_THROW(matrix.getSubMatrix(0, 4), std::invalid_argument);
		EXPECT_THROW(matrix.getSubMatrix(4, 0), std::invalid_argument);

		// unsigned int
		EXPECT_THROW(matrix.getSubMatrix(0, -1), std::invalid_argument);
	}
}

TEST(Matrix, Determinant){
	{   // 2 x 2
		Maths::Matrix matrix(Size(2),{
				{1, 2},
				{3, 4}
		});
		EXPECT_NEAR(matrix.getDeterminant(), -2, 0.000001);
	}

	{   // 3 x 3
		Maths::Matrix matrix(Size(3), {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
		});
		EXPECT_NEAR(matrix.getDeterminant(), 0, 0.000001);
	}

	{  // 4 x 4
		Maths::Matrix matrix(Size(4), {
				{1, 3, 5, 9},
				{1, 3, 1, 7},
				{4, 3, 9, 7},
				{5, 2, 0, 9}
		});

		EXPECT_NEAR(matrix.getDeterminant(), -376, 0.000001);
	}

	{   // Non-Square matrix
		Maths::Matrix matrix(Size(2, 3), {
				{2, 5, 7},
				{1, 5, 8}
		});

		EXPECT_THROW(matrix.getDeterminant(), std::invalid_argument);
	}
}

TEST(Matrix, Operators){
	{  // Access Operator
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

		// Invalid access
		Maths::Matrix matrixUninitialized;
		EXPECT_THROW(matrix[6], std::out_of_range);
		EXPECT_THROW(matrixUninitialized[2], std::logic_error);

		// TODO: error found -> Can list column that is out of range
		// EXPECT_THROW(matrix[2][77], std::out_of_range);
	}

	{   // Matrix Multiplication
		Maths::Matrix matrixOne(Size(3, 2), {
			{2, 3},
			{5, 5},
			{2, 2}
		});
		Maths::Matrix matrixTwo(Size(2, 5), {
			{2, 5, 4, 5, 6},
			{4, 2, 1, 0, 7}
		});

		Maths::Matrix resultExpected(Size(3, 5), {
			{16, 16, 11, 10, 33},
			{30, 35, 25, 25, 65},
			{12, 14, 10, 10, 26}
		});
		
		Maths::Matrix result = matrixOne * matrixTwo;
		EXPECT_EQ(result == resultExpected, true);

		// Invalid usage
		Maths::Matrix matrixInvalid(Size(3, 5), {
				{2, 5, 4, 5, 6},
				{4, 2, 1, 0, 7},
				{4, 1, 3, 5, 6}
		});
		EXPECT_THROW(matrixOne * matrixInvalid, std::invalid_argument);
	}

	{   // Scalar Multiplication
		double scalar = 7.4;
		Maths::Matrix matrix(Size(5), Maths::MatrixType::Unity);
		matrix *= scalar;

		for(size_t i = 0; i < matrix.getSize().rows; i++) {
			for (size_t j = 0; j < matrix.getSize().columns; j++) {
				if (i == j)
					EXPECT_NEAR(matrix[i][j], scalar, 0.01);
				else
					EXPECT_EQ(matrix[i][j], 0);
			}
		}
	}
}