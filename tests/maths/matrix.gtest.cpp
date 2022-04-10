#include <gtest/gtest.h>
#include <iostream>

#include "maths/matrix.hpp"
#include "maths/matrixSolver.hpp"

namespace PhysEn {
namespace GTest {

template <std::size_t S>
using Vector = Maths::Vector<double, S>;

TEST(Matrix, Solver) {
	// TODO: Add false tests

	{   // Upper triangle
		Maths::Matrix<3, 3> matrix{
				{2,  1,  -1},
				{-3, -1, 2},
				{-2, 1,  2}
		};

		Maths::Matrix<3, 3> result{
				{1, 0.5, -0.5},
				{0, 1,   1},
				{0, 0,   1}
		};

		Maths::makeUpperTriangle(matrix);
		EXPECT_TRUE(matrix == result);
	}
	{   // Equation solver
		Maths::Matrix<3, 3> componentMatrix{
				{3, 4, 2},
				{5, 2, 1},
				{0, 0, 7}
		};
		Vector<3> solution({1, 2, 3});

		Vector<3> result = Maths::solveEquation(componentMatrix, solution);
		EXPECT_NEAR(result[0], 3.0  / 7.0, 0.00001);
		EXPECT_NEAR(result[1], -2.0 / 7.0, 0.00001);
		EXPECT_NEAR(result[2], 3.0  / 7.0, 0.00001);

		// Invalid vector size
		Vector<4> solutionInvalid({4, 2, 3, 3});
		EXPECT_THROW(Maths::solveEquation(componentMatrix, solutionInvalid),
		             std::invalid_argument);
	}
}

TEST(Matrix, Construction){
	{   // Unity Matrix
		Maths::Matrix<5, 5> matrixUnity(Maths::Matrix::Type::Unity);
		for(size_t i = 0; i < matrixUnity.rows(); i++){
			for(size_t j = 0; j < matrixUnity.columns(); j++){
				if(i == j)
					ASSERT_EQ(matrixUnity.at(i, j), 1);
				else
					ASSERT_EQ(matrixUnity.at(i, j), 0);
			}
		}

		// Unity matrix has to be square
		EXPECT_THROW(Maths::Matrix<2, 3>(Maths::MatrixType::Unity),
		             std::invalid_argument);
	}

	{   // Zero Matrix
		Maths::Matrix<5, 5> matrixZero(Maths::Matrix::Type::Zero);
		for(size_t i = 0; i < matrixZero.rows(); i++)
			for(size_t j = 0; j < matrixZero.columns(); j++)
				EXPECT_EQ(matrixZero.at(i, j), 0);
	}

	{   // Vector Initialize
		Maths::Matrix matrix{
				{0, 1, 2},
				{1, 2, 3},
				{2, 3, 4}
		};

		for(size_t i = 0; i < matrix.getSize().rows; i++)
			for(size_t j = 0; j < matrix.getSize().columns; j++)
				EXPECT_EQ(matrix.at(i, j), static_cast<double>(i+j));

		// Expect error if list does not match the specified size
		Maths::Matrix<2, 3> sizeTest{
				{3, 4, 5},
				{5, 32, 2}
		};
		EXPECT_EQ(sizeTest.size(), Size(2, 3));

		// Throw because columns count differs
		EXPECT_THROW((Maths::Matrix<3, 3> {
				{3, 4, 5, 4},
				{5, 32, 2},
				{2, 3, 4}
		}), std::invalid_argument);
	}
}

TEST(Matrix, Submatrix){
	{  // 4x4 matrix
		Maths::Matrix<4, 4> matrix{
				{2, 3, 4, 5},
				{1, 2, 3, 4},
				{3, 6, 7, 2},
				{1, 4, 7, 0}
		};
		Maths::Matrix<3, 3> resultExpected{
				{1, 2, 3},
				{3, 6, 7},
				{1, 4, 7}
		};

		Maths::Matrix<3, 3> result = matrix.getSubMatrix(0, 3);
		EXPECT_TRUE(result == resultExpected);
	}

	{
		// TODO: Handle 1x(any) matrix -> How do we handle zero matrix size?
	}

	{  // Invalid row/column index
		Maths::Matrix<4, 4> matrix{
				{2, 3, 4, 5},
				{1, 2, 3, 4},
				{3, 6, 7, 2},
				{1, 4, 7, 0}
		};

		// 4x4 matrix --> Cannot delete 5th entry (Index starts at 0)
		EXPECT_THROW(matrix.getSubMatrix(0, 4), std::invalid_argument);
		EXPECT_THROW(matrix.getSubMatrix(4, 0), std::invalid_argument);

		// unsigned int
		EXPECT_THROW(matrix.getSubMatrix(0, -1), std::invalid_argument);
	}
}

TEST(Matrix, Determinant){
	{   // 2 x 2
		Maths::Matrix<2, 2> matrix{
				{1, 2},
				{3, 4}
		};
		EXPECT_NEAR(matrix.determinant(), -2, 0.000001);
	}

	{   // 3 x 3
		Maths::Matrix<3, 3> matrix{
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
		};
		EXPECT_NEAR(matrix.determinant(), 0, 0.000001);
	}

	{  // 4 x 4
		Maths::Matrix<4, 4> matrix{
				{1, 3, 5, 9},
				{1, 3, 1, 7},
				{4, 3, 9, 7},
				{5, 2, 0, 9}
		};
		EXPECT_NEAR(matrix.determinant(), -376, 0.000001);
	}

    {  // Test row-optimization
        Maths::Matrix<13, 13> matrix{
                {0, 3, 5, 9, 4, 3, 7, 7, 0, 2, 7, 0, 2},
                {0, 3, 1, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {0, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2}
        };
        EXPECT_NEAR(matrix.determinant(), 0, 0.0000001);
    }

    {  // Test column-optimization
        Maths::Matrix<13, 13> matrix{
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {3, 3, 1, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {4, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {6, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {4, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {4, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {8, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {2, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {1, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {3, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {6, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {1, 3, 9, 7, 2, 3, 4, 5, 6, 7, 7, 0, 2},
                {9, 2, 0, 9, 2, 3, 4, 5, 6, 7, 7, 0, 2}
        };
        EXPECT_NEAR(matrix.determinant(), 0, 0.0000001);
    }

	{   // Non-Square matrix
		Maths::Matrix<2, 3> matrix{
				{2, 5, 7},
				{1, 5, 8}
		};
		EXPECT_THROW(matrix.determinant(), std::invalid_argument);
	}
}

TEST(Matrix, Operators){
	{  // Access Function
		Maths::Matrix<5, 5> matrix(Maths::Matrix::Type::Unity);
		for(size_t i = 0; i < matrix.rows(); i++){
			for(size_t j = 0; j < matrix.columns(); j++) {
				if(i == j)
					ASSERT_EQ(matrix.at(i, j), 1);
				else
					ASSERT_EQ(matrix.at(i, j), 0);
			}
		}
		matrix.at(0, 1) = 6;
		EXPECT_EQ(matrix.at(0, 1), 6);

		// Invalid access
		Maths::Matrix<0, 0> matrixUninitialized;
		EXPECT_THROW(matrix.at(6, 0), std::out_of_range);
		EXPECT_THROW(matrix.at(2, 77), std::out_of_range);
	}

	{   // Matrix Multiplication
		Maths::Matrix<3, 2> matrixOne{
				{2, 3},
				{5, 5},
				{2, 2}
		};
		Maths::Matrix<2, 5> matrixTwo{
				{2, 5, 4, 5, 6},
				{4, 2, 1, 0, 7}
		};

		Maths::Matrix<3, 5> resultExpected{
				{16, 16, 11, 10, 33},
				{30, 35, 25, 25, 65},
				{12, 14, 10, 10, 26}
		};

		Maths::Matrix result = matrixOne * matrixTwo;
		EXPECT_TRUE(result == resultExpected);

		// Invalid usage
		Maths::Matrix<3, 5> matrixInvalid{
				{2, 5, 4, 5, 6},
				{4, 2, 1, 0, 7},
				{4, 1, 3, 5, 6}
		};
		EXPECT_THROW(matrixOne * matrixInvalid, std::invalid_argument);
	}

	{   // Scalar Multiplication
		constexpr double scalar = 7.4;
		Maths::Matrix<5, 5> matrix(Maths::Matrix::Type::Unity);
		matrix *= scalar;

		for(size_t i = 0; i < matrix.rows(); i++) {
			for (size_t j = 0; j < matrix.columns(); j++) {
				if (i == j)
					EXPECT_NEAR(matrix.at(i, j), scalar, 0.01);
				else
					EXPECT_EQ(matrix.at(i, j), 0);
			}
		}
	}

	{ // Equality operator
		Maths::Matrix<2, 3> first{
				{2, 4, 5},
				{2, 4, 5}
		};

		// Same matrix
		Maths::Matrix<2, 3> second = first;
		EXPECT_TRUE(first == second);
		EXPECT_FALSE(first != second);

		// Small difference
		Maths::Matrix<2, 3> third = second;
		third.at(1, 2) = 5.000000000000001;
		EXPECT_FALSE(first == third);
		EXPECT_TRUE(first != third);
	}
}

}
}
