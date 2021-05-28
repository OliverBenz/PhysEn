#include <gtest/gtest.h>
#include <iostream>

#include "../../src/maths/Matrix.hpp"
#include "../../src/maths/MatrixSolver.hpp"

using namespace PhysEn;

TEST(Matrix, Solver){
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
        EXPECT_NEAR(result[0], 3.0f  / 7.0f, 0.00001);
        EXPECT_NEAR(result[1], -2.0f / 7.0f, 0.00001);
        EXPECT_NEAR(result[2], 3.0f  / 7.0f, 0.00001);
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
				EXPECT_EQ(matrix[i][j], static_cast<float>(i+j));
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
	}

    {   // Scalar Multiplication
        float scalar = 7.4;
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