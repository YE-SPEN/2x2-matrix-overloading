// Matrix2x2.cpp
// Purpose: Implement 2x2 Matrix ADT

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: June 22, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <istream>
#include <iomanip>
#include <array>
#include <stdexcept>
#include "Matrix2x2.h"

using std::array;
using std::ostream;
using std::istream;
using std::endl;

// default constructor
Mat2x2::Mat2x2() {
    matrix[0][0] = 0.0;
    matrix[0][1] = 0.0;
    matrix[1][0] = 0.0;
    matrix[1][1] = 0.0;
}

// parameterized constructor
Mat2x2::Mat2x2(double upLeft, double upRight, double downLeft, double downRight) {
    matrix[0][0] = upLeft;
    matrix[0][1] = upRight;
    matrix[1][0] = downLeft;
    matrix[1][1] = downRight;
}

bool Mat2x2::isInvertible() const {
    return (determinant() != 0.0);
}

bool Mat2x2::isSymmetric() const {
    return (matrix[0][1] == matrix[1][0]);
}

bool Mat2x2::isSimilar(Mat2x2& rhs) const {
    return ( (determinant() - rhs.determinant()) < 1.0E-6 ) && ( (trace() - rhs.trace()) < 1.0E-6 );
}

double Mat2x2::determinant() const {
    double determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return determinant;
}

double Mat2x2::trace() const {
    double trace = matrix[0][0] + matrix[1][1];
    return trace;
}

Mat2x2 Mat2x2::transpose() const {
    Mat2x2 temp(*this);
    double swap = temp.matrix[0][1];
    temp.matrix[0][1] = temp.matrix[1][0];
    temp.matrix[1][0] = swap;
    return temp;
}

Mat2x2 Mat2x2::inverse() const {
    Mat2x2 result(*this);

    if (isInvertible()) {
        // calculate determinant & move [0][0] to temporary position
        double det = result.determinant();
        double temp = result.matrix[0][0];

        result.matrix[0][0] = result.matrix[1][1] / det;
        result.matrix[0][1] = -result.matrix[0][1] / det;
        result.matrix[1][0] = -result.matrix[1][0] / det;
        result.matrix[1][1] = temp / det;
    }

    else {
        throw std::logic_error("Matrix is not invertible");
    }

    return result;
}

// ======================
// INPUT OUTPUT OVERLOADS

ostream& operator<<(ostream& os, const Mat2x2& mat) {   // << Mat2x2
    os << "------------------" << endl;
    os << std::fixed << std::setprecision(2); // Set output format to two decimal places

    // Set width for each element
    int numWidth = 6;

    // Print matrix elements
    os << "| " << std::setw(numWidth) << mat.matrix[0][0] << ", " << std::setw(numWidth) << mat.matrix[0][1] << " |" << endl;
    os << "| " << std::setw(numWidth) << mat.matrix[1][0] << ", " << std::setw(numWidth) << mat.matrix[1][1] << " |" << endl;

    os << "------------------" << endl;
    return os;
}

istream& operator>>(std::istream& is, Mat2x2& mat) {    // >> Mat2x2
    double upLeft, upRight, downLeft, downRight;
    is >> upLeft >> upRight >> downLeft >> downRight;
    mat = Mat2x2(upLeft, upRight, downLeft, downRight);
    return is;
}

// =============================
// SUBSCRIPT & FUNCTION OVERLOAD

double& Mat2x2::operator[](int index) {
    if (index >= 0 && index < 4) {
        return matrix[index / 2][index % 2];    // convert array index into column
    }
    else {
        throw std::out_of_range("Index out of bounds");
    }
}

const double& Mat2x2::operator[](int index) const {
    if (index >= 0 && index < 4) {
        return matrix[index / 2][index % 2];    // convert array index into column
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

double Mat2x2::operator()() {
    return determinant();
}

// =============================
// RELATIONAL EQUALITY & CONVERSION OPERATORS

bool Mat2x2::operator==(const Mat2x2& rhs) {    // Mat2x2 == Mat2x2
    const double tolerance = 1.0E-6;

    // check each index is within tolerance
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            double diff = std::abs(matrix[i][j] - rhs.matrix[i][j]);
            if (diff > tolerance) {
                return false;
            }
        }
    }
    return true; 
}

bool Mat2x2::operator!=(const Mat2x2& rhs) {    // Mat2x2 != Mat2x2
    return !(*this == rhs);     // use == to implement !=
}

bool Mat2x2::operator!() {
    return (!isInvertible());   // if (!Mat2x2)
}

Mat2x2::operator bool() const {
    return isInvertible();  // // if (Mat2x2)
}


// ===============
// UNARY OPERATORS

// pre-fix increment
Mat2x2& Mat2x2::operator++() {  // ++Mat2x2
    matrix[0][0]++;
    matrix[0][1]++;
    matrix[1][0]++;
    matrix[1][1]++;
    return *this;
}

// post-fix increment
Mat2x2 Mat2x2::operator++(int) {    // Mat2x2++   
    Mat2x2 temp(*this);
    operator++();
    return temp;
}

Mat2x2 Mat2x2::operator+() {    // +Mat2x2
    return *this;
}

// pre-fix decrement
Mat2x2& Mat2x2::operator--() {     // --Mat2x2
    matrix[0][0]--;
    matrix[0][1]--;
    matrix[1][0]--;
    matrix[1][1]--;
    return *this;
}

// post-fix decrement
Mat2x2 Mat2x2::operator--(int) {    // Mat2x2--
    Mat2x2 temp(*this);
    operator--();
    return temp;
}

Mat2x2 Mat2x2::operator-() {    // -Mat2x2
    Mat2x2 temp(*this);
    temp.matrix[0][0] *= -1;
    temp.matrix[0][1] *= -1;
    temp.matrix[1][0] *= -1;
    temp.matrix[1][1] *= -1;
    return temp;
}

// ================
// COMPOUND OPERATORS

Mat2x2& Mat2x2::operator+=(const Mat2x2& rhs) {     // Mat2x2 += Mat2x2
    matrix[0][0] += rhs.matrix[0][0];
    matrix[0][1] += rhs.matrix[0][1];
    matrix[1][0] += rhs.matrix[1][0];
    matrix[1][1] += rhs.matrix[1][1];
    return *this;
}

Mat2x2& Mat2x2::operator+=(const double& scalar) {  // Mat2x2 += x
    matrix[0][0] += scalar;
    matrix[0][1] += scalar;
    matrix[1][0] += scalar;
    matrix[1][1] += scalar;
    return *this;
}

Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs) {    // Mat2x2 + Mat2x2
    Mat2x2 temp(lhs);
    temp += rhs;
    return temp;
}

Mat2x2& Mat2x2::operator-=(const Mat2x2& rhs) {     // Mat2x2 -= Mat2x2
    matrix[0][0] -= rhs.matrix[0][0];
    matrix[0][1] -= rhs.matrix[0][1];
    matrix[1][0] -= rhs.matrix[1][0];
    matrix[1][1] -= rhs.matrix[1][1];
    return *this;
}

Mat2x2& Mat2x2::operator-=(const double& scalar) {  // Mat2x2 -= x
    matrix[0][0] -= scalar;
    matrix[0][1] -= scalar;
    matrix[1][0] -= scalar;
    matrix[1][1] -= scalar;
    return *this;
}

Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs) {    // Mat2x2 - Mat2x2
    Mat2x2 temp(lhs);
    temp -= rhs;
    return temp;
}

Mat2x2& Mat2x2::operator*=(const Mat2x2& rhs) {     // Mat2x2 *= Mat2x2
    Mat2x2 temp(*this);
    temp.matrix[0][0] = ( matrix[0][0] * rhs.matrix[0][0] ) + ( matrix[0][1] * rhs.matrix[1][0] );
    temp.matrix[0][1] = ( matrix[0][0] * rhs.matrix[0][1] ) + ( matrix[0][1] * rhs.matrix[1][1] );
    temp.matrix[1][0] = ( matrix[1][0] * rhs.matrix[0][0] ) + ( matrix[1][1] * rhs.matrix[1][0] );
    temp.matrix[1][1] = ( matrix[1][0] * rhs.matrix[0][1] ) + ( matrix[1][1] * rhs.matrix[1][1] );

    matrix[0][0] = temp.matrix[0][0];
    matrix[0][1] = temp.matrix[0][1];
    matrix[1][0] = temp.matrix[1][0];
    matrix[1][1] = temp.matrix[1][1];

    return *this;
}

Mat2x2& Mat2x2::operator*=(const double& scalar) {     // Mat2x2 *= x
    matrix[0][0] *= scalar;
    matrix[0][1] *= scalar;
    matrix[1][0] *= scalar;
    matrix[1][1] *= scalar;
    return *this;
}


Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs) {    // Mat2x2 * Mat2x2
    Mat2x2 temp(lhs);
    temp *= rhs;
    return temp;
}

Mat2x2& Mat2x2::operator/=(const Mat2x2& rhs) {     // Mat2x2 /= Mat2x2
    return *this *= rhs.inverse();
}

Mat2x2& Mat2x2::operator/=(const double& scalar) {  // Mat2x2 /= x
    if (scalar != 0) {
        *this *= 1 / scalar;
    }
    else {
        throw std::overflow_error("Cannot divide by zero");
    }
    return *this;
}

Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs) {    // Mat2x2 / Mat2x2
    Mat2x2 temp(lhs);
    temp /= rhs;
    return temp;
}

// ================
// SCALAR OPERATORS

Mat2x2 operator-(const Mat2x2& lhs, const double& scalar) {     // Mat2x2 - x
    Mat2x2 temp(lhs);
    return temp -= scalar;
}

Mat2x2 operator-(const double& scalar, const Mat2x2& rhs) {     // x - Mat2x2
    Mat2x2 temp(rhs);
    temp[0] = scalar - temp[0];
    temp[1] = scalar - temp[1];
    temp[2] = scalar - temp[2];
    temp[3] = scalar - temp[3];
    return temp;
}

Mat2x2 operator+(const Mat2x2& lhs, const double& scalar) {     // Mat2x2 + x
    Mat2x2 temp(lhs);
    return temp += scalar;
}

Mat2x2 operator+(const double& scalar, const Mat2x2& rhs) {     // x + Mat2x2
    return rhs + scalar;
}

Mat2x2 operator*(const Mat2x2& lhs, const double& scalar) {     // Mat2x2 * x
    Mat2x2 temp(lhs);
    return temp *= scalar;
}

Mat2x2 operator*(const double& scalar, const Mat2x2& rhs) {     // x * Mat2x2
    return rhs * scalar;
}

Mat2x2 operator/(const Mat2x2& lhs, const double& scalar) {     // Mat2x2 / x
    if (scalar == 0) {
        throw std::overflow_error("Divide by zero error.");
    }

    Mat2x2 temp(lhs);
    temp /= scalar;
    return temp;
}

Mat2x2 operator/(const double& scalar, const Mat2x2& rhs) {     // x / Mat2x2
    Mat2x2 temp(rhs.inverse());
    temp *= scalar;
    return temp;
}

