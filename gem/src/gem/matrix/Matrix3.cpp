#include "Matrix3.h"

namespace gem
{
    Matrix3::Matrix3(float a)
    {
        matrix[0].x = a;
        matrix[0].y = 0.f;
        matrix[0].z = 0.f;

        matrix[1].x = 0.f;
        matrix[1].y = a;
        matrix[1].z = 0.f;

        matrix[2].x = 0.f;
        matrix[2].y = 0.f;
        matrix[2].z = a;
    }

    Matrix3::Matrix3(const Vector3& a, const Vector3& b, const Vector3& c)
    {
        matrix[0] = a;
        matrix[1] = b;
        matrix[2] = c;
    }

    Matrix3::Matrix3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
    {
        matrix[0].x = a1;
        matrix[0].y = a2;
        matrix[0].z = a3;

        matrix[1].x = b1;
        matrix[1].y = b2;
        matrix[1].z = b3;

        matrix[2].x = c1;
        matrix[2].y = c2;
        matrix[2].z = c3;
    }

    const Matrix3& Matrix3::operator*=(float scalar)
    {
        matrix[0] *= scalar;
        matrix[1] *= scalar;
        matrix[2] *= scalar;

        return *this;
    }

    const Matrix3& Matrix3::operator/=(float scalar)
    {
        matrix[0] /= scalar;
        matrix[1] /= scalar;
        matrix[2] /= scalar;

        return *this;
    }

    const Matrix3 Matrix3::operator*(float scalar) const
    {
        Matrix3 res;

        res[0] = matrix[0] * scalar;
        res[1] = matrix[1] * scalar;
        res[2] = matrix[2] * scalar;

        return res;
    }

    const Matrix3 Matrix3::operator/(float scalar) const
    {
        Matrix3 res;

        res[0] = matrix[0] / scalar;
        res[1] = matrix[1] / scalar;
        res[2] = matrix[2] / scalar;

        return res;
    }

    const Matrix3 Matrix3::operator-() const // unary
    {
        return Matrix3(-matrix[0], -matrix[1], -matrix[2]);
    }

    const Matrix3& Matrix3::operator+=(const Matrix3& mat)
    {
        matrix[0] += mat[0];
        matrix[1] += mat[1];
        matrix[2] += mat[2];

        return *this;
    }

    const Matrix3& Matrix3::operator-=(const Matrix3& mat)
    {
        matrix[0] -= mat[0];
        matrix[1] -= mat[1];
        matrix[2] -= mat[2];

        return *this;
    }

    const Matrix3 Matrix3::operator+(const Matrix3& mat) const
    {
        Matrix3 res;

        res[0] = matrix[0] + mat[0];
        res[1] = matrix[1] + mat[1];
        res[2] = matrix[2] + mat[2];

        return res;
    }

    const Matrix3 Matrix3::operator-(const Matrix3& mat) const
    {
        Matrix3 res;

        res[0] = matrix[0] - mat[0];
        res[1] = matrix[1] - mat[1];
        res[2] = matrix[2] - mat[2];

        return res;
    }

    Vector3& Matrix3::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector3& Matrix3::operator[](size_t i) const
    {
        return matrix[i];
    }
}