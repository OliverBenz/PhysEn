#include <gtest/gtest.h>
#include <iostream>

#include "maths/matrix.hpp"
#include "maths/matrixSolver.hpp"

namespace phys::gtest {

template <std::size_t S>
using Vector = vector<double, S>;

TEST(Matrix, Solver) {
	// TODO: Add false tests

	{   // Upper triangle
		matrix<3, 3> mat{
            {2,  1,  -1},
            {-3, -1, 2},
            {-2, 1,  2}
		};

		matrix<3, 3> result{
            {1, 0.5, -0.5},
            {0, 1,   1},
            {0, 0,   1}
		};

		makeUpperTriangle(mat);
		EXPECT_TRUE(mat == result);
	}
	{   // Equation solver
		matrix<3, 3> componentMatrix{
            {3, 4, 2},
            {5, 2, 1},
            {0, 0, 7}
		};
		Vector<3> solution({1, 2, 3});

		Vector<3> result = solveEquation(componentMatrix, solution);
		EXPECT_NEAR(result[0], 3.0  / 7.0, 0.00001);
		EXPECT_NEAR(result[1], -2.0 / 7.0, 0.00001);
		EXPECT_NEAR(result[2], 3.0  / 7.0, 0.00001);
    }
}

TEST(Matrix, Construction){
	{   // unity matrix
		matrix<5, 5> matrixUnity(matrixType::unity);
		for(std::size_t i = 0; i != matrixUnity.rows(); i++){
			for(std::size_t j = 0; j != matrixUnity.cols(); j++){
				if(i == j)
					ASSERT_EQ(matrixUnity.at(i, j), 1);
				else
					ASSERT_EQ(matrixUnity.at(i, j), 0);
			}
		}

		// unity matrix has to be square
        auto constr = [](){
            matrix<2, 3> value(matrixType::unity);
        };
		EXPECT_THROW(constr(), std::invalid_argument);
	}

	{   // zero matrix
		matrix<5, 5> matrixZero(matrixType::zero);
		for(std::size_t i = 0; i != matrixZero.rows(); i++)
			for(std::size_t j = 0; j != matrixZero.cols(); j++)
				EXPECT_EQ(matrixZero.at(i, j), 0);
	}

	{   // vector Initialize
		matrix<3, 3> mat{
            {0, 1, 2},
            {1, 2, 3},
            {2, 3, 4}
		};

		for(std::size_t i = 0; i != mat.rows(); i++)
			for(std::size_t j = 0; j != mat.cols(); j++)
				EXPECT_EQ(mat.at(i, j), static_cast<double>(i+j));

		// Expect error if list does not match the specified dimension
		matrix<2, 3> sizeTest{
            {3, 4, 5},
            {5, 32, 2}
		};
		EXPECT_EQ(sizeTest.size(), dimension(2, 3));

		// Throw because columns count differs
		EXPECT_THROW((matrix<3, 3> {
            {3, 4, 5, 4},
            {5, 32, 2},
            {2, 3, 4}
		}), std::invalid_argument);
	}
}

TEST(Matrix, Submatrix){
	{  // 4x4 matrix
		matrix<4, 4> mat{
            {2, 3, 4, 5},
            {1, 2, 3, 4},
            {3, 6, 7, 2},
            {1, 4, 7, 0}
		};
		matrix<3, 3> resultExpected{
            {1, 2, 3},
            {3, 6, 7},
            {1, 4, 7}
		};

		matrix<3, 3> result = mat.getSubMatrix(0, 3);
		EXPECT_TRUE(result == resultExpected);
	}

	{
		// TODO: Handle 1x(any) matrix
	}

	{  // Invalid row/column index
		matrix<4, 4> mat{
            {2, 3, 4, 5},
            {1, 2, 3, 4},
            {3, 6, 7, 2},
            {1, 4, 7, 0}
		};

		// 4x4 matrix --> Cannot delete 5th entry (Index starts at 0)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
        EXPECT_THROW(mat.getSubMatrix(0, 4), std::out_of_range);
		EXPECT_THROW(mat.getSubMatrix(4, 0), std::out_of_range);

		// unsigned int
		EXPECT_THROW(mat.getSubMatrix(0, static_cast<std::size_t>(-1)), std::out_of_range);
#pragma GCC diagnostic pop
	}
}

TEST(Matrix, Determinant){
	{   // 2 x 2
		matrix<2, 2> mat{
            {1, 2},
            {3, 4}
		};
		EXPECT_NEAR(mat.determinant(), -2, 0.000001);
	}

	{   // 3 x 3
		matrix<3, 3> mat{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
		};
		EXPECT_NEAR(mat.determinant(), 0, 0.000001);
	}

	{  // 4 x 4
		matrix<4, 4> mat{
            {1, 3, 5, 9},
            {1, 3, 1, 7},
            {4, 3, 9, 7},
            {5, 2, 0, 9}
		};
		EXPECT_NEAR(mat.determinant(), -376, 0.000001);
	}

    {  // Test row-optimization
        matrix<13, 13> mat{
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

        EXPECT_NEAR(mat.determinant(), 0, 0.0000001);
    }

    {  // Test column-optimization
        matrix<13, 13> mat{
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

        EXPECT_NEAR(mat.determinant(), 0, 0.0000001);
    }

	{   // Non-Square matrix
		matrix<2, 3> mat{
            {2, 5, 7},
            {1, 5, 8}
		};

		// EXPECT_THROW(matrix.determinant(), std::invalid_argument);
    }

    {   // Too small
        matrix<1, 1> mat{
            {1}
        };
        // EXPECT_THROW(matrix.determinant(), std::domain_error);
    }
}

TEST(Matrix, Operators){
	{  // Access Function
		matrix<5, 5> mat(matrixType::unity);
		for(size_t i = 0; i < mat.rows(); i++){
			for(size_t j = 0; j < mat.cols(); j++) {
				if(i == j)
					ASSERT_EQ(mat.at(i, j), 1);
				else
					ASSERT_EQ(mat.at(i, j), 0);
			}
		}
		mat.at(0, 1) = 6;
		EXPECT_EQ(mat.at(0, 1), 6);

		// Invalid access
		matrix<2, 3> matrixUninitialized;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
		EXPECT_THROW(matrixUninitialized.at(6, 0), std::out_of_range);
		EXPECT_THROW(matrixUninitialized.at(2, 77), std::out_of_range);
#pragma GCC diagnostic pop

        matrix<3, 2> matAt = {
            {2, 5},
            {6, 8},
            {1, 9}
        };
        EXPECT_EQ(matAt.at(0, 0), 2);
        EXPECT_EQ(matAt.at(0, 1), 5);
        EXPECT_EQ(matAt.at(1, 0), 6);
        EXPECT_EQ(matAt.at(1, 1), 8);
        EXPECT_EQ(matAt.at(2, 0), 1);
        EXPECT_EQ(matAt.at(2, 1), 9);
	}

	{   // matrix Multiplication
		matrix<3, 2> matrixOne{
            {2, 3},
            {5, 5},
            {2, 2}
		};
		matrix<2, 5> matrixTwo{
            {2, 5, 4, 5, 6},
            {4, 2, 1, 0, 7}
		};

		matrix<3, 5> leftMultResExpect{
            {16, 16, 11, 10, 33},
            {30, 35, 25, 25, 65},
            {12, 14, 10, 10, 26}
        };

		matrix leftMultRes = matrixOne * matrixTwo;
		EXPECT_TRUE(leftMultRes == leftMultResExpect);

		// Invalid usage
		matrix<3, 5> matrixInvalid{
            {2, 5, 4, 5, 6},
            {4, 2, 1, 0, 7},
            {4, 1, 3, 5, 6}
		};
		EXPECT_THROW(matrixOne * matrixInvalid, std::invalid_argument);
	}

	{   // Scalar Multiplication
		constexpr double scalar = 7.4;
		matrix<5, 5> mat(matrixType::unity);
		mat *= scalar;

		for(size_t i = 0; i < mat.rows(); i++) {
			for (size_t j = 0; j < mat.cols(); j++) {
				if (i == j)
					EXPECT_NEAR(mat.at(i, j), scalar, 0.01);
				else
					EXPECT_EQ(mat.at(i, j), 0);
			}
		}
	}

	{ // Equality operator
		matrix<2, 3> first{
            {2, 4, 5},
            {2, 4, 5}
		};

		// Same matrix
		matrix<2, 3> second = first;
		EXPECT_TRUE(first == second);
		EXPECT_FALSE(first != second);

		// Small difference
		matrix<2, 3> third = second;
		third.at(1, 2) = 5.000000000000001;
		EXPECT_FALSE(first == third);
		EXPECT_TRUE(first != third);
	}
}

}
