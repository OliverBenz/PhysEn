#include "integration.hpp"

#include <array>
#include <vector>
#include <thread>

namespace phys::maths {

static constexpr double MAX_AREA = 100.0;
static constexpr double INTERVAL_STEP = 1e-3;

double integrate(double (*function)(double x), double limitA, double limitB) {
	if(limitA == limitB)
		return 0;

	// We can invert the bounds of the integral by changing the sign of the result
	bool invertBounds = false;
	if(limitA > limitB){
		std::swap(limitA, limitB);
		invertBounds = true;
	}

	// The interval_start/interval_end interval for first area
	double interval_start = limitA;
	double interval_end = limitA + MAX_AREA;

	// List of threads and results; threads get ID and add their result to results[ID].
	std::vector<std::thread> threads;
	std::vector<double> results;

	/**
    * @brief Calculate the integral for a specific interval.
    * @param start Start of interval.
    * @param end   End of interval.
    * @param id    Thread id. Used to store the result of the calculation.
    */
	auto calcIntegral = [&results, &function](double start, double end, std::size_t id){
		double pointA = start;
		double pointB = start + INTERVAL_STEP;

		double totArea = 0;
		while (pointB <= end){
			// Quadratic approximation
			// area = (b-a)/6 * ( f(a) + 4 * f((a+b)/2) + f(b) )
			totArea += (pointB-pointA)/6 * ((*function)(pointA) + 4 * (*function)((pointA + pointB) / 2) + (*function)(pointB));

			// Update
			pointA = pointB;
			pointB = pointA + INTERVAL_STEP;
		}

		// Make sure to include interval_end
		totArea += (end-pointA)/6 * ((*function)(pointA) + 4 * (*function)((pointA + end) / 2) + (*function)(end));

		// Thead number 2 adds its results for results[2].
		results[id] = totArea;
	};

	// If area small enough -> No need for multithreading.
	if (interval_end > limitB){
		results.emplace_back();
		calcIntegral(limitA, limitB, 0);
	}
	else {
		std::size_t id = 0;
		// Start a thread for every MAX_AREA interval.
		while(interval_end <= limitB){
			results.emplace_back(0);
			threads.emplace_back(std::thread(calcIntegral, interval_start, interval_end, id));

            interval_start = interval_end;
            interval_end += MAX_AREA;
			++id;
		}

		// The last interval can be partially outside the specified range. (interval_end > limitB BUT interval_start < limitB)
		// Cover last area manually.
		if(interval_start < limitB && interval_end > limitB) {
			results.emplace_back(0);
			calcIntegral(interval_start, limitB, id);
		}

		// Wait for all threads to finish
		for(std::thread& thread: threads)
			thread.join();
	}

	// Combine all results.
	double sum = 0;
	for(auto& n : results)
		sum += n;

	if(invertBounds)
		sum = -sum;

	return sum;
}

}
