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

    Matrix2::Matrix2(Vector2& a, Vector2& b)
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

    Vector2& Matrix2::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector2& Matrix2::operator[](size_t i) const
    {
        return matrix[i];
    }
}