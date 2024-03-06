#pragma once

#include "../vector/Vector4.h"

namespace gem
{
    struct Matrix4
    {
    private:
        Vector4 matrix[4];

    public:
        Matrix4(float a = 1.f);
        Matrix4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);
        Matrix4(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4);

        float Det() const;

        const Matrix4& operator*=(float scalar);
        const Matrix4& operator/=(float scalar);
        const Matrix4 operator*(float scalar) const;
        const Matrix4 operator/(float scalar) const;

        const Matrix4 operator-() const; // unary
        const Matrix4& operator+=(const Matrix4& mat);
        const Matrix4& operator-=(const Matrix4& mat);
        const Matrix4 operator+(const Matrix4& mat) const;
        const Matrix4 operator-(const Matrix4& mat) const;

        const Matrix4 operator*(const Matrix4& mat) const;
        const Vector4 operator*(const Vector4& vec) const;

        Vector4& operator[](size_t i);
        const Vector4& operator[](size_t i) const;

    private:
        float Det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3) const;
    };

    // alternative call methods for class functions
    float det(const Matrix4& m);
}