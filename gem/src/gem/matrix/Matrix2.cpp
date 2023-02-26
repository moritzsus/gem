#include "Matrix2.h"

namespace gem
{
    Matrix2::Matrix2(float a)
    {
        matrix[0].x = a;
        matrix[0].y = 0.f;

        matrix[1].x = 0.f;
        matrix[1].y = a;
    }

    Matrix2::Matrix2(const Vector2& a, const Vector2& b)
    {
        matrix[0] = a;
        matrix[1] = b;
    }

    Matrix2::Matrix2(float a1, float a2, float b1, float b2)
    {
        matrix[0].x = a1;
        matrix[0].y = a2;

        matrix[1].x = b1;
        matrix[1].y = b2;
    }

    const Matrix2& Matrix2::operator*=(float scalar)
    {
        matrix[0] *= scalar;
        matrix[1] *= scalar;

        return *this;
    }

    const Matrix2& Matrix2::operator/=(float scalar)
    {
        matrix[0] /= scalar;
        matrix[1] /= scalar;

        return *this;
    }

    const Matrix2 Matrix2::operator*(float scalar) const
    {
        Matrix2 res;

        res[0] = matrix[0] * scalar;
        res[1] = matrix[1] * scalar;

        return res;
    }

    const Matrix2 Matrix2::operator/(float scalar) const
    {
        Matrix2 res;

        res[0] = matrix[0] / scalar;
        res[1] = matrix[1] / scalar;

        return res;
    }

    const Matrix2 Matrix2::operator-() const // unary
    {
        return Matrix2(-matrix[0], -matrix[1]);
    }

    const Matrix2& Matrix2::operator+=(const Matrix2& mat)
    {
        matrix[0] += mat[0];
        matrix[1] += mat[1];

        return *this;
    }

    const Matrix2& Matrix2::operator-=(const Matrix2& mat)
    {
        matrix[0] -= mat[0];
        matrix[1] -= mat[1];

        return *this;
    }

    const Matrix2 Matrix2::operator+(const Matrix2& mat) const
    {
        Matrix2 res;

        res[0] = matrix[0] + mat[0];
        res[1] = matrix[1] + mat[1];

        return res;
    }

    const Matrix2 Matrix2::operator-(const Matrix2& mat) const
    {
        Matrix2 res;

        res[0] = matrix[0] - mat[0];
        res[1] = matrix[1] - mat[1];

        return res;
    }

    Vector2& Matrix2::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector2& Matrix2::operator[](size_t i) const
    {
        return matrix[i];
    }
}