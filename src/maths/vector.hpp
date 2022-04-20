#pragma once

#include <array>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>

namespace phys {

//! @brief Mathematical vector implementation.
template <typename T, std::size_t S>
class vector {
	std::array<T, S> values = {0};

public:
	// Constructors
	constexpr vector() = default;

	/*!
	 * @brief Initialize a vector with dimension of list and elements in list.
	 * @param list List of all elements in the vector.
	 */
	explicit constexpr vector(std::array<T, S> list);
	explicit constexpr vector(std::initializer_list<T> list);

	/*!
	 * @param right The vector right of the cross product.
	 * @return Cross product result vector.
	 */
	static constexpr vector<T, 3> crossProduct(vector<T, 3>& left, vector<T, 3>& right);

	// Member Functions
	//!  @return Dimension of the vector.
	[[nodiscard]] constexpr std::size_t size() const;

	//! @return Iterator to the first element in the vector.
	constexpr typename std::array<T, S>::iterator begin(){ return values.begin(); };

	//! @return Iterator to the last element in the vector.
	constexpr typename std::array<T, S>::iterator end() { return values.end(); };

	// Operators
	constexpr T& operator[](size_t row);
	constexpr T operator[](size_t row) const;

	friend constexpr vector<T, S> operator +(const vector<T, S>& left, const vector<T, S>& right){
		if (left.size() != right.size())
			throw std::invalid_argument("Vectors are not of equal dimension!");

		vector<T, S> result;
		for (size_t i = 0; i < result.size(); i++)
			result[i] = left[i] + right[i];
		return result;
	}

	friend constexpr vector<T, S> operator -(const vector<T, S>& left, const vector<T, S>& right) {
		if (left.size() != right.size())
			throw std::invalid_argument("Vectors are not of equal dimension!");

		vector<T, S> result;
		for (size_t i = 0; i < result.size(); i++)
			result[i] = left[i] - right[i];
		return result;
	}

	friend constexpr T operator *(vector<T, S>& left, vector<T, S>& right) {
		if (left.size() != right.size())
			throw std::invalid_argument("Vectors are not of equal dimension!");

		T result = 0;
		for(size_t i = 0; i < left.size(); i++)
			result += left[i] * right[i];
		return result;
	}

	friend constexpr vector<T, S> operator *(T left, const vector<T, S>& right) {
		vector<T, S> result;
		for(size_t i = 0; i < right.size(); i++)
			result[i] = right[i] * left;
		return result;
	}

	friend constexpr vector<T, S> operator *(const vector<T, S>& left, T right) {
		return right * left;
	}

	friend constexpr void operator *=(vector<T, S>& left, T right) {
		for(size_t i = 0; i < left.size(); i++)
			left[i] *= right;
	}

	// TODO: Handle floating point differently from integer values and class values.
	friend constexpr bool operator ==(const vector<T, S>& left, const vector<T, S>& right) {
		if (left.size() != right.size())
			throw std::invalid_argument("Vectors are not of equal dimension!");

		for(size_t i = 0; i < left.size(); i++)
			if(fabs(left[i] - right[i]) > std::numeric_limits<T>::epsilon())
				return false;
		return true;
	}

	friend constexpr bool operator !=(const vector<T, S>& left, const vector<T, S>& right) {
		return !(left == right);
	}

	friend std::ostream& operator << (std::ostream& os, const vector<T, S>& vec) {
		os << "(";
		for(size_t i = 0; i < vec.size() - 1; i++)
			os << vec[i] << " ,";
		return (os << vec[vec.size()-1] << ")\n");
	}
};

/*!
 * @brief Helper class for the vector norm function to accumulate a vector with each element squared.
 * @tparam T Datatype
 */
template<typename T>
struct square {
	constexpr T operator()(const T& left, const T& right) {
		return (left + right*right);
	}
};

/*!
 * @brief Get the 2-Norm of a vector.
 * @param value vector.
 * @return 2-Norm of the vector.
 */
template <typename T, std::size_t S>
double normTwo(vector<T, S>& value){
	return sqrt(std::accumulate(value.begin(), value.end(), 0.0f, square<double>()));
}

/*!
 * @brief Get the supremum norm of a vector. (infinity-norm)
 * @param value vector.
 * @return Supremum norm of the vector.
 */
template <typename T, std::size_t S>
double normSupremum(vector<T, S>& value){
	return *std::max_element(value.begin(), value.end());
}

template <typename T, std::size_t S>
constexpr vector<T, S>::vector(std::array<T, S> list) : values(list)
{}

template <typename T, std::size_t S>
constexpr vector<T, S>::vector(std::initializer_list<T> list)
{
    std::size_t i = 0;
	for(auto it = list.begin(); it != list.end(); it++) {
		values[i] = *it;
		++i;
	}
}

template <typename T, std::size_t S>
constexpr std::size_t vector<T, S>::size() const {
	return S;
}

template <typename T, std::size_t S>
constexpr vector<T, 3> vector<T, S>::crossProduct(vector<T, 3>& left, vector<T, 3>& right){
	vector<T, 3> res({
		left[1] * right[2] - left[2] * right[1],
		left[2] * right[0] - left[0] * right[2],
		left[0] * right[1] - left[1] * right[0]
	});
	return res;
}

template <typename T, std::size_t S>
constexpr T& vector<T, S>::operator[](std::size_t row){
	if(row > values.size())
		throw std::out_of_range("vector row number out of range!");

	return values[row];
}

template <typename T, std::size_t S>
constexpr T vector<T, S>::operator[](std::size_t row) const {
	if(row > values.size())
		throw std::out_of_range("vector row number out of range!");

	return values[row];
}

}