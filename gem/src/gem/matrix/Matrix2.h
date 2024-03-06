#pragma once

#include "../vector/Vector2.h"

namespace gem
{
    struct Matrix2
    {   
    private:
        Vector2 matrix[2];

    public:
        Matrix2(float a = 1.f);
        Matrix2(const Vector2& a, const Vector2& b);
        Matrix2(float a1, float a2, float b1, float b2);

        float Det() const;

        const Matrix2& operator*=(float scalar);
        const Matrix2& operator/=(float scalar);
        const Matrix2 operator*(float scalar) const;
        const Matrix2 operator/(float scalar) const;

        const Matrix2 operator-() const; // unary
        const Matrix2& operator+=(const Matrix2& mat);
        const Matrix2& operator-=(const Matrix2& mat);
        const Matrix2 operator+(const Matrix2& mat) const;
        const Matrix2 operator-(const Matrix2& mat) const;

        const Matrix2 operator*(const Matrix2& mat) const;
        const Vector2 operator*(const Vector2& vec) const;

        Vector2& operator[](size_t i);
        const Vector2& operator[](size_t i) const;
    };

    // alternative call methods for class functions
    float det(const Matrix2& m);
}