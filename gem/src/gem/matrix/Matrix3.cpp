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

    Matrix3::Matrix3(Vector3& a, Vector3& b, Vector3& c)
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

    Vector3& Matrix3::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector3& Matrix3::operator[](size_t i) const
    {
        return matrix[i];
    }
}