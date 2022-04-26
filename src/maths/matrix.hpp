#pragma once

#include <array>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

#include "value.hpp"
#include "../common/dimension.hpp"

namespace phys {

enum class matrixType {
    zero,
    unity
};

template <typename T, std::size_t size_rows, std::size_t size_cols>
class matrix {
    std::array<value<T>, size_rows * size_cols> m_values;

public:
    constexpr matrix() = default;

    //! @brief Construct with specific values.
    constexpr matrix(const std::initializer_list<std::initializer_list<T>> values) {
        if (values.size() != size_rows)
            throw std::invalid_argument("Argument row count does not match matrix row count!");

        for(std::size_t i = 0; i != values.size(); ++i) {
            if ((values.begin() + i)->size() != size_cols)
                throw std::invalid_argument("Argument columns count does not match matrix column count!");

            for(std::size_t j = 0; j != (values.begin()+i)->size(); ++j){
                m_values[i * size_cols + j] = *((values.begin()+i)->begin() + j);
            }
        }
    }

    //! @brief Construct a matrix  with a specific type.
    constexpr explicit matrix(const matrixType type) {
        switch (type){
            case matrixType::zero:
                break;

            case matrixType::unity:
                if(!isSquare())
                    throw std::invalid_argument("unity matrix has to be square!");

                for(std::size_t i = 0; i < size_rows; i++)
                    m_values[i * size_rows + i] = 1;
                break;
        }
    }

    /*!
     * @brief Get number of rows of the matrix.
     * @return Number of rows.
     */
    [[nodiscard]]
    constexpr inline std::size_t rows() const noexcept {
        return size_rows;
    }

    /*!
     * @brief Get the number of columns of the matrix.
     * @return Number of columns.
     */
    [[nodiscard]]
    constexpr inline std::size_t cols() const noexcept {
        return size_cols;
    }

    /*!
     * @brief Get the matrix dimension.
     * @return dimension struct containing number of rows and columns.
     */
    [[nodiscard]]
    constexpr inline dimension size() const noexcept {
        return {size_rows, size_cols};
    }

    /*!
     * @brief Check if the matrix is a square matrix.
     * @return True if the row count equals the column count.
     */
    [[nodiscard]]
    constexpr inline bool isSquare() const noexcept {
        return size_rows == size_cols;
    }

    /*!
     * @brief  Access the element at a specific row and column.
     * @param row Row in the matrix (starts at zero).
     * @param col Column in the matrix (starts at zero).
     * @return Value at specified row and column.
     */
    [[nodiscard]]
    constexpr const value<T>& at(const std::size_t& row, const std::size_t& col) const {
        if (row > size_rows - 1 || col > size_cols - 1)
            throw std::out_of_range("Row or column number out of range!");

        return m_values[row * size_cols + col];
    }

    /*!
     * @brief  Access the element at a specific row and column.
     * @param row Row in the matrix (starts at zero).
     * @param col Column in the matrix (starts at zero).
     * @return Value at specified row and column.
     */
    [[nodiscard]]
    constexpr value<T>& at(const std::size_t& row, const std::size_t& col) {
        if(row > size_rows - 1 || col > size_cols - 1)
            throw std::out_of_range("Row or column number out of range!");

        return m_values[row * size_cols + col];
    }

    /*!
     * @brief Calculate the determinant of the matrix.
     * @return Determinant of the matrix.
     */
    [[nodiscard]]
    constexpr value<T> determinant() const;

    // Operators
    constexpr friend matrix operator*(const value<T> left, const matrix& right) {
        matrix<T, size_rows, size_cols> res;

        for(size_t i = 0; i != size_rows; i++){
            for(size_t j = 0; j != size_cols; j++){
                res.at(i, j) = right.at(i, j) * left;
            }
        }
        return res;
    }

    constexpr friend matrix operator*(const matrix& left, value<T> right) {
        return right * left;
    }

    friend matrix operator*=(matrix& left, const value<T> right) {
        for(std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                left.at(i, j) *= right;

        return left;
    }

    template <std::size_t r2, std::size_t c2>
    constexpr friend matrix<T, size_rows, c2> operator*(const matrix<T, size_rows, size_cols>& left, const matrix<T, r2, c2>& right) {
        if(left.cols() != right.rows())
            throw std::invalid_argument("matrix sizes do not line up for multiplication!");

        matrix<T, size_rows, c2> result;

        // result_{ij} = \sum_{k=0}^{n-1} left_{ik} * right_{kj}
        for(std::size_t i = 0; i != result.rows(); i++){
            for(std::size_t j = 0; j != result.cols(); j++){
                for(std::size_t k = 0; k < left.cols(); k++)
                    result.at(i, j) += left.at(i, k) * right.at(k, j);
            }
        }

        return result;
    }

    constexpr friend bool operator==(const matrix& left, const matrix& right) {
        for (std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                if(left.at(i, j) != right.at(i, j))
                    return false;

        return true;
    }

    constexpr friend bool operator!=(const matrix& left, const matrix& right) {
        for (std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                if(left.at(i, j) != right.at(i, j))
                    return true;

        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, matrix& m){
        for(size_t i = 0; i != size_rows; i++){
            for(size_t j = 0; j != size_cols; j++)
                os << std::setw(4) << m.at(i, j);
            os << "\n";
        }
        return os;
    }

    [[nodiscard]]
    constexpr matrix<T, size_rows - 1, size_cols - 1> getSubMatrix(std::size_t delRow, std::size_t delCol) const {
        if (delRow > size_rows - 1)
            throw std::out_of_range("Delete row out of range! Note that the row count starts at 0!");
        if(delCol > size_cols)
            throw std::out_of_range("Delete column out of range! Note that the column count starts at 0!");

        matrix<T, size_rows - 1, size_cols - 1> result;

        std::size_t resRow = 0;
        std::size_t resCol = 0;
        for(size_t i = 0; i != size_rows; i++){
            if(i == delRow)
                continue;

            resCol = 0;
            for(size_t j = 0; j != size_cols; j++){
                if(j == delCol)
                    continue;

                result.at(resRow, resCol) = m_values[i * size_cols + j];
                ++resCol;
            }
            ++resRow;
        }

        return result;
    }
};

// Determinant
template <typename T, std::size_t size_rows, std::size_t size_cols>
constexpr value<T> matrix<T, size_rows, size_cols>::determinant() const {
    if(!isSquare())
        throw std::invalid_argument("Determinant cannot be calculated for a non-square matrix!");
    if(size_rows < 1)
        throw std::domain_error("No determinant defined for matrix dimension < 2!");

    // Exit conditions
    if(size_rows == 1)
        return m_values[0];
    else if(size_rows == 2)
        return m_values[0] * m_values[3] - m_values[1] * m_values[2];

    // Check if row or columns has more 0-entries.
    // index > 0 : More 0 in columns.
    // index < 0 : More 0 in rows.
    int zeroIndex = 0;
    for(size_t i = 0; i != size_rows; i++) {
        if (m_values[i * size_cols] == 0)
            zeroIndex -= 1;
        if (m_values[i] == 0)
            zeroIndex += 1;
    }

    // Calculate determinant
    double sgn = 1.0;
    double determinant = 0.0;
    if(zeroIndex >= 0) {
        for (size_t j = 0; j != size_cols; j++) {
            if(m_values[j] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
                determinant += sgn * m_values[j] * getSubMatrix(0, j).determinant();
            sgn = -sgn;
        }
    } else {
        for (size_t i = 0; i != size_rows; i++) {
            if(m_values[i * size_cols] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
                determinant += sgn * m_values[i * size_cols] * getSubMatrix(i, 0).determinant();
            sgn = -sgn;
        }
    }

    return determinant;
}

// Special specialize to prevent usage.
template<typename T>
class matrix<T, 0, 0> {};

}