#include "Matrix4.h"
#include <iostream>

namespace gem
{
    Matrix4::Matrix4(float a)
    {
        matrix[0].x = a;
        matrix[0].y = 0.f;
        matrix[0].z = 0.f;
        matrix[0].w = 0.f;

        matrix[1].x = 0.f;
        matrix[1].y = a;
        matrix[1].z = 0.f;
        matrix[1].w = 0.f;

        matrix[2].x = 0.f;
        matrix[2].y = 0.f;
        matrix[2].z = a;
        matrix[2].w = 0.f;

        matrix[3].x = 0.f;
        matrix[3].y = 0.f;
        matrix[3].z = 0.f;
        matrix[3].w = a;
    }

    Matrix4::Matrix4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
    {
        matrix[0] = a;
        matrix[1] = b;
        matrix[2] = c;
        matrix[3] = d;
    }

    Matrix4::Matrix4(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4)
    {
        matrix[0].x = a1;
        matrix[0].y = a2;
        matrix[0].z = a3;
        matrix[0].w = a4;

        matrix[1].x = b1;
        matrix[1].y = b2;
        matrix[1].z = b3;
        matrix[1].w = b4;

        matrix[2].x = c1;
        matrix[2].y = c2;
        matrix[2].z = c3;
        matrix[2].w = c4;

        matrix[3].x = d1;
        matrix[3].y = d2;
        matrix[3].z = d3;
        matrix[3].w = d4;
    }

    float Matrix4::Det() const
    {
        if (matrix[0].w == 0.f && matrix[1].w == 0.f && matrix[2].w == 0.f && matrix[3].w == 1.f)
        {
            return Det3x3(matrix[0].x, matrix[0].y, matrix[0].z, matrix[1].x, matrix[1].y, matrix[1].z, matrix[2].x, matrix[2].y, matrix[2].z);
        }
        return (
              matrix[0].x * Det3x3(matrix[1].y, matrix[1].z, matrix[1].w, matrix[2].y, matrix[2].z, matrix[2].w, matrix[3].y, matrix[3].z, matrix[3].w)
            - matrix[0].y * Det3x3(matrix[1].x, matrix[1].z, matrix[1].w, matrix[2].x, matrix[2].z, matrix[2].w, matrix[3].x, matrix[3].z, matrix[3].w)
            + matrix[0].z * Det3x3(matrix[1].x, matrix[1].y, matrix[1].w, matrix[2].x, matrix[2].y, matrix[2].w, matrix[3].x, matrix[3].y, matrix[3].w)
            - matrix[0].w * Det3x3(matrix[1].x, matrix[1].y, matrix[1].z, matrix[2].x, matrix[2].y, matrix[2].z, matrix[3].x, matrix[3].y, matrix[3].z)
            );
    }

    float Matrix4::Det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3) const
    {
        return (
              a1 * b2 * c3
            + b1 * c2 * a3
            + c1 * a2 * b3
            - a3 * b2 * c1
            - b3 * c2 * a1
            - c3 * a2 * b1
            );
    }

    const Matrix4& Matrix4::operator*=(float scalar)
    {
        matrix[0] *= scalar;
        matrix[1] *= scalar;
        matrix[2] *= scalar;
        matrix[3] *= scalar;

        return *this;
    }

    const Matrix4& Matrix4::operator/=(float scalar)
    {
        matrix[0] /= scalar;
        matrix[1] /= scalar;
        matrix[2] /= scalar;
        matrix[3] /= scalar;

        return *this;
    }

    const Matrix4 Matrix4::operator*(float scalar) const
    {
        Matrix4 res;

        res[0] = matrix[0] * scalar;
        res[1] = matrix[1] * scalar;
        res[2] = matrix[2] * scalar;
        res[3] = matrix[3] * scalar;

        return res;
    }

    const Matrix4 Matrix4::operator/(float scalar) const
    {
        Matrix4 res;

        res[0] = matrix[0] / scalar;
        res[1] = matrix[1] / scalar;
        res[2] = matrix[2] / scalar;
        res[3] = matrix[3] / scalar;

        return res;
    }

    const Matrix4 Matrix4::operator-() const // unary
    {
        return Matrix4(-matrix[0], -matrix[1], -matrix[2], -matrix[3]);
    }

    const Matrix4& Matrix4::operator+=(const Matrix4& mat)
    {
        matrix[0] += mat[0];
        matrix[1] += mat[1];
        matrix[2] += mat[2];
        matrix[3] += mat[3];

        return *this;
    }

    const Matrix4& Matrix4::operator-=(const Matrix4& mat)
    {
        matrix[0] -= mat[0];
        matrix[1] -= mat[1];
        matrix[2] -= mat[2];
        matrix[3] -= mat[3];

        return *this;
    }

    const Matrix4 Matrix4::operator+(const Matrix4& mat) const
    {
        Matrix4 res;

        res[0] = matrix[0] + mat[0];
        res[1] = matrix[1] + mat[1];
        res[2] = matrix[2] + mat[2];
        res[3] = matrix[3] + mat[3];

        return res;
    }

    const Matrix4 Matrix4::operator-(const Matrix4& mat) const
    {
        Matrix4 res;

        res[0] = matrix[0] - mat[0];
        res[1] = matrix[1] - mat[1];
        res[2] = matrix[2] - mat[2];
        res[3] = matrix[3] - mat[3];

        return res;
    }

    const Matrix4 Matrix4::operator*(const Matrix4& mat) const
    {
        return Matrix4(
            matrix[0].x * mat[0].x + matrix[1].x * mat[0].y + matrix[2].x * mat[0].z + matrix[3].x * mat[0].w,
            matrix[0].y * mat[0].x + matrix[1].y * mat[0].y + matrix[2].y * mat[0].z + matrix[3].y * mat[0].w,
            matrix[0].z * mat[0].x + matrix[1].z * mat[0].y + matrix[2].z * mat[0].z + matrix[3].z * mat[0].w,
            matrix[0].w * mat[0].x + matrix[1].w * mat[0].y + matrix[2].w * mat[0].z + matrix[3].w * mat[0].w,

            matrix[0].x * mat[1].x + matrix[1].x * mat[1].y + matrix[2].x * mat[1].z + matrix[3].x * mat[1].w,
            matrix[0].y * mat[1].x + matrix[1].y * mat[1].y + matrix[2].y * mat[1].z + matrix[3].y * mat[1].w,
            matrix[0].z * mat[1].x + matrix[1].z * mat[1].y + matrix[2].z * mat[1].z + matrix[3].z * mat[1].w,
            matrix[0].w * mat[1].x + matrix[1].w * mat[1].y + matrix[2].w * mat[1].z + matrix[3].w * mat[1].w,

            matrix[0].x * mat[2].x + matrix[1].x * mat[2].y + matrix[2].x * mat[2].z + matrix[3].x * mat[2].w,
            matrix[0].y * mat[2].x + matrix[1].y * mat[2].y + matrix[2].y * mat[2].z + matrix[3].y * mat[2].w,
            matrix[0].z * mat[2].x + matrix[1].z * mat[2].y + matrix[2].z * mat[2].z + matrix[3].z * mat[2].w,
            matrix[0].w * mat[2].x + matrix[1].w * mat[2].y + matrix[2].w * mat[2].z + matrix[3].w * mat[2].w,

            matrix[0].x * mat[3].x + matrix[1].x * mat[3].y + matrix[2].x * mat[3].z + matrix[3].x * mat[3].w,
            matrix[0].y * mat[3].x + matrix[1].y * mat[3].y + matrix[2].y * mat[3].z + matrix[3].y * mat[3].w,
            matrix[0].z * mat[3].x + matrix[1].z * mat[3].y + matrix[2].z * mat[3].z + matrix[3].z * mat[3].w,
            matrix[0].w * mat[3].x + matrix[1].w * mat[3].y + matrix[2].w * mat[3].z + matrix[3].w * mat[3].w
        );
    }

    const Vector4 Matrix4::operator*(const Vector4& vec) const
    {
        return Vector4(
            matrix[0].x * vec.x + matrix[1].x * vec.y + matrix[2].x * vec.z + matrix[3].x * vec.w,
            matrix[0].y * vec.x + matrix[1].y * vec.y + matrix[2].y * vec.z + matrix[3].y * vec.w,
            matrix[0].z * vec.x + matrix[1].z * vec.y + matrix[2].z * vec.z + matrix[3].z * vec.w,
            matrix[0].w * vec.x + matrix[1].w * vec.y + matrix[2].w * vec.z + matrix[3].w * vec.w
        );
    }

    Vector4& Matrix4::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector4& Matrix4::operator[](size_t i) const
    {
        return matrix[i];
    }

    // alternative call methods for class functions
    float det(const Matrix4& m)
    {
        return m.Det();
    }
}