#pragma once

#include "../maths/matrix.hpp"

namespace phys {

/**
 * @brief Struct containing information about a lens.
 */
struct Lens {
	// maths::matrix position;
	double n;   ///< Break index n
	double r1;  ///< Radius lens left
	double r2;  ///< Radius lens right
	double w;   ///< Width of lens
};

/**
 * @brief Create matrix that describes light passing through both ends of a lens.
 * @param l Lens struct containing information.
 * @param n1 Break index of medium before lens.
 * @param n2 Break index of medium after lens.
 * @return matrix describing break information.
 *
 * @latex Note: latex.n1 = n1; latex.n2 = lens.n; latex.n3 = n2
 * \left(
 *   \begin{matrix}
 *     1 + d \frac{n_1-n_2}{R_1 n_2} & d \frac{n_1}{n_2} \\
 *     1 + d \frac{n_1-n_2}{R_1 n_2} + \frac{n_2(n_1-n_2)}{R_1 n_2 n_3} & \frac{n_1}{n_3} + d \frac{n_1(n_2-n_3)}{R_2 n_2 n_3}
 *   \end{matrix}
 * \right)
 */
matrix<2,2> getLensMatrix(Lens& l, double n1, double n2);

/**
 * @brief Create a matrix that describes light traveling on a straight path.
 * @param length Length of the path.
 * @return matrix describing the travel information.
 *
 * @latex Note: l = Path length
 *  \left(
 *    \begin{matrix}
 *      1 & l \\
 *      0 & 1
 *   \end{matrix}
 * \right)
 */
matrix<2,2> getPathMatrix(double length);

}
