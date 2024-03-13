#define _USE_MATH_DEFINES

#include "Matrix2.h"
#include <cmath>

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

    const Matrix2 Matrix2::Transpose() const
    {
        return Matrix2(matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]);
    }

    float Matrix2::Det() const 
    {
        return (matrix[0].x * matrix[1].y) - (matrix[1].x * matrix[0].y);
    }

    const Matrix2 Matrix2::Inverse() const
    {
        float det = Det();

        if (det == 0)
        {
            //TODO log or try catch handling
            std::cout << "No Inverse" << std::endl;
            return Matrix2(0.f);
        }

        return Matrix2(matrix[1][1], -matrix[0][1], -matrix[1][0], matrix[0][0]) * (1 / Det());
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

    const Matrix2 Matrix2::operator*(const Matrix2& mat) const
    {
        return Matrix2(
            matrix[0].x * mat[0].x + matrix[1].x * mat[0].y,
            matrix[0].y * mat[0].x + matrix[1].y * mat[0].y,
            matrix[0].x * mat[1].x + matrix[1].x * mat[1].y,
            matrix[0].y * mat[1].x + matrix[1].y * mat[1].y
        );
    }

    const Vector2 Matrix2::operator*(const Vector2& vec) const
    {
        return Vector2(
            matrix[0].x * vec.x + matrix[1].x * vec.y,
            matrix[0].y * vec.x + matrix[1].y * vec.y
        );
    }

    Vector2& Matrix2::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector2& Matrix2::operator[](size_t i) const
    {
        return matrix[i];
    }

    // alternative call methods for class functions
    const Matrix2 transpose(const Matrix2& m)
    {
        return m.Transpose();
    }

    float det(const Matrix2& m)
    {
        return m.Det();
    }

    const Matrix2 inverse(const Matrix2& m)
    {
        return m.Inverse();
    }

    // returns aMatrix2 which can rotate vectors about given angle
    const Matrix2 make2dRotationDeg(float angleInDeg)
    {
        float radians = angleInDeg * (M_PI / 180.f);
        return Matrix2(cosf(radians), sinf(radians), -sinf(radians), cosf(radians));
    }

    // returns aMatrix2 which can rotate vectors about given angle
    const Matrix2 make2dRotationRad(float angleInRad)
    {
        return Matrix2(cosf(angleInRad), sinf(angleInRad), -sinf(angleInRad), cosf(angleInRad));
    }
}