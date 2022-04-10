#include <array>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

#include "../common/size.hpp"

namespace PhysEn {
namespace Maths {

template <std::size_t size_rows, std::size_t size_cols>
class Matrix {
    std::array<double, size_rows * size_cols> values;

public:
    enum class Type {
        Zero,
        Unity
    };

    //! Default
    constexpr Matrix() = default;

    // Construct with specific values.
    constexpr Matrix(const std::initializer_list<std::initializer_list<double>> values) {
        if (values.size() != size_rows)
            throw std::invalid_argument("Argument row count does not match matrix row count!");

        auto valuesIterator = this->values.begin();
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

    //! Custruct with specific type.
    constexpr Matrix(const Type type) {
        switch (type){
            case Type::Zero:
                std::fill(std::begin(values), std::end(values), 0);
                break;

            case Type::Unity:
                if(!isSquare())
                    throw std::invalid_argument("Unity matrix has to be square!");

                std::fill(std::begin(values), std::end(values), 0);

                for(std::size_t i = 0; i < size_rows; i++)
                    values[i*size_rows + i] = 1;
                break;
        }
    }

    [[nodiscard]]
    constexpr inline double rows() const noexcept {
        return size_rows;
    }

    [[nodiscard]]
    constexpr inline double cols() const noexcept {
        return size_cols;
    }

    [[nodiscard]]
    constexpr inline Size size() const noexcept {
        return {size_rows, size_cols};
    }

    [[nodiscard]]
    constexpr inline bool isSquare() const noexcept {
        return size_rows == size_cols;
    }

    [[nodiscard]]
    constexpr const double& at(const std::size_t& row, const std::size_t& col) const {
        if (row > size_rows - 1 || col > size_cols - 1)
            throw std::invalid_argument("Row or column number out of range!");

        return values[row*size_rows + col];
    }

    [[nodiscard]]
    constexpr double& at(const std::size_t& row, const std::size_t& col) {
        if(row > size_rows - 1 || col > size_cols - 1)
            throw std::invalid_argument("Row or column number out of range!");

        return values[row*size_rows + col];
    }

    [[nodiscard]]
    constexpr double determinant() const;

    // Operators
    template <std::size_t rows, std::size_t cols>
    constexpr friend Matrix operator*(const double left, const Matrix& right);

    template <std::size_t rows, std::size_t cols>
    constexpr friend Matrix operator*(const Matrix& left, const double right);

    template <std::size_t rows, std::size_t cols>
    friend Matrix operator*=(Matrix& left, const double right);

    template <std::size_t r1, std::size_t c1, std::size_t r2, std::size_t c2>
    constexpr friend Matrix operator*(const Matrix& left, const Matrix& right);

    template <std::size_t rows, std::size_t cols>
    constexpr friend bool operator==(const Matrix& left, const Matrix& right);

    template <std::size_t rows, std::size_t cols>
    constexpr friend bool operator==(const Matrix& left, const Matrix& right);

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
            throw std::invalid_argument("Delete row out of range! Note that the row count starts at 0!");
        if(delCol > size_cols)
            throw std::invalid_argument("Delete column out of range! Note that the column count starts at 0!");

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

                result.at(resRow, resCol) = values[i * size_cols + j];
                ++resCol;
            }
            ++resRow;
        }

        return result;
    }
};

// Determinant
template <>
constexpr double Matrix<2, 2>::determinant() const{
    return values[0] * values[3] - values[1] * values[2];
}

template <std::size_t size_rows, std::size_t size_cols>
constexpr double Matrix<size_rows, size_cols>::determinant() const {
    if(!isSquare())
        throw std::invalid_argument("Determinant cannot be calculated for a non-square matrix!");

    // Check if row or columns has more 0-entries.
    // index > 0 : More 0 in columns.
    // index < 0 : More 0 in rows.
    int zeroIndex = 0;
    for(size_t i = 0; i != size_rows; i++) {
        if (values[i * size_cols] == 0)
            zeroIndex -= 1;
        if (values[i] == 0)
            zeroIndex += 1;
    }

    // Calculate determinant
    double sgn = 1.0;
    double determinant = 0.0f;
    if(zeroIndex >= 0) {
        for (size_t j = 0; j != size_cols; j++) {
            if(values[j] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
                determinant += sgn * values[j] * getSubMatrix(0, j).determinant();
            sgn = -sgn;
        }
    } else {
        for (size_t i = 0; i != size_rows; i++) {
            if(values[i] != 0)  // We can skip computation of any sub-matrix that would be multiplied by 0!
                determinant += sgn * values[i * size_cols] * getSubMatrix(i, 0).determinant();
            sgn = -sgn;
        }
    }

    return determinant;
}

// Operators
template <std::size_t rows, std::size_t cols>
constexpr Matrix<rows, cols> operator*(const double left, const Matrix<rows, cols>& right) {
    Matrix<rows, cols> res;

    for(size_t i = 0; i != rows; i++){
        for(size_t j = 0; j != cols; j++){
            res.at(i, j) = right.at(i, j) * left;
        }
    }
    return res;
}

template <std::size_t rows, std::size_t cols>
constexpr Matrix<rows, cols> operator*(const Matrix<rows, cols>& left, const double right) {
    return right * left;
}

// Cannot be used constexpr (Because matrix is constant obviously..)
template <std::size_t rows, std::size_t cols>
Matrix<rows, cols>& operator*=(Matrix<rows, cols>& left, const double right) {
    for(std::size_t i = 0; i != rows; i++)
        for(std::size_t j = 0; j != cols; j++)
            left.at(i, j) *= right;

    return left;
}


template <std::size_t r1, std::size_t c1, std::size_t r2, std::size_t c2>
constexpr Matrix<r1, c2> operator*(const Matrix<r1, c1>& left, const Matrix<r2, c2>& right) {
    if(c1 != r2)
        throw std::invalid_argument("Matrix sizes do not line up for multiplication!");

    Matrix<r1, c2> result;

    for(std::size_t res_i = 0; res_i != result.rows(); res_i++){
        for(std::size_t res_j = 0; res_j != result.cols(); res_j++){
            result.at(res_i, res_j) = 0;

            for(std::size_t r = 0; r < c1; r++)
                result.at(res_i, res_j) += left.at(res_i, r) * right.at(r, res_j);
        }
    }

    return result;
}

template <std::size_t rows, std::size_t cols>
constexpr bool operator==(const Matrix<rows, cols>& left, const Matrix<rows, cols>& right) {
    for (std::size_t i = 0; i != rows; i++)
        for(std::size_t j = 0; j != cols; j++)
            if(left.at(i, j) != right.at(i, j))
                return false;

    return true;
}

template <std::size_t rows, std::size_t cols>
constexpr bool operator!=(const Matrix<rows, cols>& left, const Matrix<rows, cols>& right) {
    for (std::size_t i = 0; i != rows; i++)
        for(std::size_t j = 0; j != cols; j++)
            if(left.at(i, j) != right.at(i, j))
                return true;

    return false;
}
}
}