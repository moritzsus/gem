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
        Matrix4(Vector4& a, Vector4& b, Vector4& c, Vector4& d);
        Matrix4(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4);

        Vector4& operator[](size_t i);
        const Vector4& operator[](size_t i) const;
    };
}