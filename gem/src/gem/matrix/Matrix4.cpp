#include "Matrix4.h"

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

    Matrix4::Matrix4(Vector4& a, Vector4& b, Vector4& c, Vector4& d)
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

    Vector4& Matrix4::operator[](size_t i)
    {
        return matrix[i];
    }

    const Vector4& Matrix4::operator[](size_t i) const
    {
        return matrix[i];
    }
}