#pragma once

#include "../vector/Vector3.h"

namespace gem
{
    struct Matrix3
    {
    private:
        //TODO store as 2d matrix of floats -> [][] access with math convention, but stored in col major order?
        Vector3 matrix[3];

    public:
        Matrix3(float a = 1.f);
        Matrix3(const Vector3& a, const Vector3& b, const Vector3& c);
        Matrix3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3);

        const Matrix3& operator*=(float scalar);
        const Matrix3& operator/=(float scalar);
        const Matrix3 operator*(float scalar) const;
        const Matrix3 operator/(float scalar) const;

        const Matrix3 operator-() const; // unary
        const Matrix3& operator+=(const Matrix3& mat);
        const Matrix3& operator-=(const Matrix3& mat);
        const Matrix3 operator+(const Matrix3& mat) const;
        const Matrix3 operator-(const Matrix3& mat) const;

        const Matrix3 operator*(const Matrix3& mat) const;
        const Vector3 operator*(const Vector3& vec) const;

        Vector3& operator[](size_t i);
        const Vector3& operator[](size_t i) const;
    };

    //TODO alternative call methods for class functions
}