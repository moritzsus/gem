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

        const Matrix2& operator*=(float scalar);
        const Matrix2& operator/=(float scalar);
        const Matrix2 operator*(float scalar) const;
        const Matrix2 operator/(float scalar) const;
        const Matrix2 operator-() const; // unary
        const Matrix2& operator+=(const Matrix2& mat);
        const Matrix2& operator-=(const Matrix2& mat);
        const Matrix2 operator+(const Matrix2& mat) const;
        const Matrix2 operator-(const Matrix2& mat) const;
        Vector2& operator[](size_t i);
        const Vector2& operator[](size_t i) const;
    };
}