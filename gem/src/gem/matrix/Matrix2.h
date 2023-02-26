#pragma once

#include "../vector/Vector2.h"

namespace gem
{
    struct Matrix2
    {   
    private:
        Vector2 matrix[2];

    public:
        Matrix2(float a = 1.f);
        Matrix2(Vector2& a, Vector2& b);
        Matrix2(float a1, float a2, float b1, float b2);

        Vector2& operator[](size_t i);
        const Vector2& operator[](size_t i) const;
    };
}