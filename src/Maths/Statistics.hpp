#pragma once

#include <vector>

namespace PhysEn {
namespace Maths {

/**
 * @brief Calculate the mean of a set of values.
 * @param values Values to calculate the mean of.
 * @return Mean of the set of values.
 */
double Mean(const std::vector<double>& values);

/**
 * @brief Calculate the standard deviation of a set of values.
 * @param values Values to calculate the standard deviation of.
 * @return Standard deviation of the set of values.
 */
double StdDeviation(const std::vector<double>& values);

/**
 * @brief Find all values whose difference to mean is > 3 stdDeviations.
 * @param values Values to scan for peaks.
 * @return Set of peaks.
 */
std::vector<double> FindPeaks(const std::vector<double>& values);
}
}
