#pragma once

#include <array>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

#include "../common/size.hpp"

namespace phys::maths {

enum class MatrixType {
    Zero,
    Unity
};

template <std::size_t size_rows, std::size_t size_cols>
class Matrix {
    std::array<double, size_rows * size_cols> m_values = {0};

public:
    constexpr Matrix() = default;

    //! @brief Construct with specific values.
    constexpr Matrix(const std::initializer_list<std::initializer_list<double>> values) {
        if (values.size() != size_rows)
            throw std::invalid_argument("Argument row count does not match matrix row count!");

        auto valuesIterator = this->m_values.begin();
        for(std::size_t i = 0; i != size_rows; i++){
            if ((values.begin() + i)->size() != size_cols)
                throw std::invalid_argument("Argument columns count does not match matrix column count!");

            std::copy(
                    (values.begin() + i)->begin(),
                    (values.begin() + i)->end(),
                    valuesIterator
            );
            std::advance(valuesIterator, size_cols);
        }
    }

    //! @brief Construct a matrix  with a specific type.
    constexpr explicit Matrix(const MatrixType type) {
        switch (type){
            case MatrixType::Zero:
                std::fill(std::begin(m_values), std::end(m_values), 0);
                break;

            case MatrixType::Unity:
                if(!isSquare())
                    throw std::invalid_argument("Unity matrix has to be square!");

                std::fill(std::begin(m_values), std::end(m_values), 0);

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
     * @return Size struct containing number of rows and columns.
     */
    [[nodiscard]]
    constexpr inline Size size() const noexcept {
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
    constexpr const double& at(const std::size_t& row, const std::size_t& col) const {
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
    constexpr double& at(const std::size_t& row, const std::size_t& col) {
        if(row > size_rows - 1 || col > size_cols - 1)
            throw std::out_of_range("Row or column number out of range!");

        return m_values[row * size_cols + col];
    }

    /*!
     * @brief Calculate the determinant of the matrix.
     * @return Determinant of the matrix.
     */
    [[nodiscard]]
    constexpr double determinant() const;

    // Operators
    constexpr friend Matrix operator*(const double left, const Matrix& right) {
        Matrix<size_rows, size_cols> res;

        for(size_t i = 0; i != size_rows; i++){
            for(size_t j = 0; j != size_cols; j++){
                res.at(i, j) = right.at(i, j) * left;
            }
        }
        return res;
    }

    constexpr friend Matrix operator*(const Matrix& left, double right) {
        return right * left;
    }

    friend Matrix operator*=(Matrix& left, const double right) {
        for(std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                left.at(i, j) *= right;

        return left;
    }

    template <std::size_t r2, std::size_t c2>
    constexpr friend Matrix<size_rows, c2> operator*(const Matrix<size_rows, size_cols>& left, const Matrix<r2, c2>& right) {
        if(left.cols() != right.rows())
            throw std::invalid_argument("Matrix sizes do not line up for multiplication!");

        Matrix<size_rows, c2> result;

        // result_{ij} = \sum_{k=0}^{n-1} left_{ik} * right_{kj}
        for(std::size_t i = 0; i != result.rows(); i++){
            for(std::size_t j = 0; j != result.cols(); j++){
                for(std::size_t k = 0; k < left.cols(); k++)
                    result.at(i, j) += left.at(i, k) * right.at(k, j);
            }
        }

        return result;
    }

    constexpr friend bool operator==(const Matrix& left, const Matrix& right) {
        for (std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                if(left.at(i, j) != right.at(i, j))
                    return false;

        return true;
    }

    constexpr friend bool operator!=(const Matrix& left, const Matrix& right) {
        for (std::size_t i = 0; i != size_rows; i++)
            for(std::size_t j = 0; j != size_cols; j++)
                if(left.at(i, j) != right.at(i, j))
                    return true;

        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, Matrix& m){
        for(size_t i = 0; i != size_rows; i++){
            for(size_t j = 0; j != size_cols; j++)
                os << std::setw(4) << m.at(i, j);
            os << "\n";
        }
        return os;
    }

    [[nodiscard]]
    constexpr Matrix<size_rows - 1, size_cols - 1> getSubMatrix(std::size_t delRow, std::size_t delCol) const {
        if (delRow > size_rows - 1)
            throw std::out_of_range("Delete row out of range! Note that the row count starts at 0!");
        if(delCol > size_cols)
            throw std::out_of_range("Delete column out of range! Note that the column count starts at 0!");

        Matrix<size_rows-1, size_cols-1> result;

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
template <>
constexpr double Matrix<1, 1>::determinant() const {
    return m_values[0];
}
template <>
constexpr double Matrix<2, 2>::determinant() const {
    return m_values[0] * m_values[3] - m_values[1] * m_values[2];
}

template <std::size_t size_rows, std::size_t size_cols>
constexpr double Matrix<size_rows, size_cols>::determinant() const {
    if(!isSquare())
        throw std::invalid_argument("Determinant cannot be calculated for a non-square matrix!");
    if(size_rows < 1)
        throw std::domain_error("No determinant defined for matrix dimension < 2!");

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
    double determinant = 0.0f;
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
template<>
class Matrix<0, 0> {};

}