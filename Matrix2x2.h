// Matrix2x2.h
// Purpose: Define Matrix2x2 ADT member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: June 22, 2023

 ******************************************** */

#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <iostream>
#include <ostream>
#include <istream>
#include <array>

using std::array;
using std::ostream;
using std::istream;

class Mat2x2 {
private:
    array< array<double, 2>, 2 > matrix;

public:
    // special members
    Mat2x2();
    Mat2x2(double upLeft, double upRight, double downLeft, double downRight);
    Mat2x2(const Mat2x2& source) = default;
    Mat2x2(Mat2x2&& rhs) noexcept = default;
    ~Mat2x2() = default;
    Mat2x2& operator=(const Mat2x2& rhs) = default;
    Mat2x2& operator=(Mat2x2&& rhs) noexcept = default;

    // input/output overload
    friend ostream& operator<<(ostream& os, const Mat2x2& mat);
    friend istream& operator>>(istream& is, Mat2x2& mat);

    // matrix operations
    double determinant() const;
    double trace() const;
    Mat2x2 transpose() const;
    Mat2x2 inverse() const throw(std::overflow_error);
    bool isSymmetric() const;
    bool isInvertible() const;
    bool isSimilar(Mat2x2& rhs) const;

    // relational equality & conversion overloads 
    bool operator==(const Mat2x2& rhs);
    bool operator!=(const Mat2x2& rhs);
    bool operator!();
    explicit operator bool() const;

    // subscript & function overloads
    double& operator[](int index);
    const double& operator[](int index) const;
    double operator()();

    // unary operator overloads
    Mat2x2& operator++();
    Mat2x2 operator++(int);
    Mat2x2& operator--();
    Mat2x2 operator--(int);
    Mat2x2 operator+();
    Mat2x2 operator-();

    // compound operator overloads (as member)
    Mat2x2& operator-=(const Mat2x2& rhs);
    Mat2x2& operator-=(const double& scalar);
    Mat2x2& operator+=(const Mat2x2& rhs);
    Mat2x2& operator+=(const double& scalar);
    Mat2x2& operator*=(const Mat2x2& rhs);
    Mat2x2& operator*=(const double& scalar);
    Mat2x2& operator/=(const Mat2x2& rhs) throw(std::overflow_error);
    Mat2x2& operator/=(const double& scalar);

};

    // NON-MEMBER OVERLOAD OPERATORS
    
    // binary operator overloads
    Mat2x2 operator-(const Mat2x2& lhs, const Mat2x2& rhs);
    Mat2x2 operator+(const Mat2x2& lhs, const Mat2x2& rhs);
    Mat2x2 operator*(const Mat2x2& lhs, const Mat2x2& rhs);
    Mat2x2 operator/(const Mat2x2& lhs, const Mat2x2& rhs) throw(std::overflow_error);

    // scalar operator overloads
    Mat2x2 operator-(const Mat2x2& lhs, const double& scalar);
    Mat2x2 operator-(const double& scalar, const Mat2x2& rhs);
    Mat2x2 operator+(const Mat2x2& lhs, const double& scalar);
    Mat2x2 operator+(const double& scalar, const Mat2x2& rhs);
    Mat2x2 operator*(const Mat2x2& lhs, const double& scalar);
    Mat2x2 operator*(const double& scalar, const Mat2x2& rhs);
    Mat2x2 operator/(const Mat2x2& lhs, const double& scalar) throw(std::overflow_error);
    Mat2x2 operator/(const double& scalar, const Mat2x2& rhs) throw(std::overflow_error);

#endif
