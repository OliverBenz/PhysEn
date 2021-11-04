#include "Statistics.hpp"

#include <stdexcept>
#include <cmath>

namespace PhysEn {
namespace Maths {

double Mean(const std::vector<double>& values){
	if(values.empty())
		throw std::invalid_argument("No data to calculate mean of!");

	double sum = 0;
	for (const double& val: values)
		sum += val;

	return sum / static_cast<double>(values.size());
}

double StdDeviation(const std::vector<double>& values){
	if(values.empty())
		throw std::invalid_argument("No data to calculate the standard deviation of!");

	double mean = Mean(values);

	double sum = 0;
	for (const double& val: values) {
		double temp = val - mean;
		sum += temp*temp;
	}

	return std::sqrt(sum / static_cast<double>(values.size()));
}

std::vector<double> FindPeaks(const std::vector<double>& values){
	std::vector<bool> peakMask(values.size());
	// TODO: Finish, need masked mean/stddev function.
	bool updated = false;
	do {

	}
}

}
}
