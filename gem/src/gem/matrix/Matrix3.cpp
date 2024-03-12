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

    const Matrix3 Matrix3::Transpose() const
    {
        return Matrix3(matrix[0][0], matrix[1][0], matrix[2][0],
                       matrix[0][1], matrix[1][1], matrix[2][1],
                       matrix[0][2], matrix[1][2], matrix[2][2]);
    }

    float Matrix3::Det() const
    {
        return (
              matrix[0].x * matrix[1].y * matrix[2].z
            + matrix[1].x * matrix[2].y * matrix[0].z
            + matrix[2].x * matrix[0].y * matrix[1].z
            - matrix[0].z * matrix[1].y * matrix[2].x
            - matrix[1].z * matrix[2].y * matrix[0].x
            - matrix[2].z * matrix[0].y * matrix[1].x
            );
    }

    const Matrix3 Matrix3::Inverse() const
    {
        const Vector3 v0 = matrix[1].Cross(matrix[2]);
        const Vector3 v1 = matrix[2].Cross(matrix[0]);
        const Vector3 v2 = matrix[0].Cross(matrix[1]);

        // Determinant = Skalar triple product (a x b * c)
        float det = v2.Dot(matrix[2]);

        if (det == 0)
        {
            //TODO log or try catch handling
            std::cout << "No Inverse" << std::endl;
            return Matrix3(0.f);
        }

        float detInverse = 1 / det;

        return Matrix3(v0.x * detInverse, v1.x * detInverse, v2.x * detInverse,
                       v0.y * detInverse, v1.y * detInverse, v2.y * detInverse, 
                       v0.z * detInverse, v1.z * detInverse, v2.z * detInverse);
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

    const Matrix3 Matrix3::operator*(const Matrix3& mat) const
    {
        return Matrix3(
            matrix[0].x * mat[0].x + matrix[1].x * mat[0].y + matrix[2].x * mat[0].z,
            matrix[0].y * mat[0].x + matrix[1].y * mat[0].y + matrix[2].y * mat[0].z,
            matrix[0].z * mat[0].x + matrix[1].z * mat[0].y + matrix[2].z * mat[0].z,

            matrix[0].x * mat[1].x + matrix[1].x * mat[1].y + matrix[2].x * mat[1].z,
            matrix[0].y * mat[1].x + matrix[1].y * mat[1].y + matrix[2].y * mat[1].z,
            matrix[0].z * mat[1].x + matrix[1].z * mat[1].y + matrix[2].z * mat[1].z,

            matrix[0].x * mat[2].x + matrix[1].x * mat[2].y + matrix[2].x * mat[2].z,
            matrix[0].y * mat[2].x + matrix[1].y * mat[2].y + matrix[2].y * mat[2].z,
            matrix[0].z * mat[2].x + matrix[1].z * mat[2].y + matrix[2].z * mat[2].z
        );
    }

    const Vector3 Matrix3::operator*(const Vector3& vec) const
    {
        return Vector3(
            matrix[0].x * vec.x + matrix[1].x * vec.y + matrix[2].x * vec.z,
            matrix[0].y * vec.x + matrix[1].y * vec.y + matrix[2].y * vec.z,
            matrix[0].z * vec.x + matrix[1].z * vec.y + matrix[2].z * vec.z
        );
    }

    Vector3& Matrix3::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector3& Matrix3::operator[](size_t i) const
    {
        return matrix[i];
    }

    // alternative call methods for class functions
    const Matrix3 transpose(const Matrix3& m)
    {
        return m.Transpose();
    }

    float det(const Matrix3& m)
    {
        return m.Det();
    }

    const Matrix3 inverse(const Matrix3& m)
    {
        return m.Inverse();
    }
}