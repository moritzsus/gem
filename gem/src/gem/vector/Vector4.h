#pragma once

#include <iostream>

namespace gem
{
    struct Vector4
    {
        float x, y, z, w;

        Vector4();
        Vector4(float x, float y, float z, float w);

        float Magnitude() const;
        Vector4 Normalize() const;

        const Vector4& operator*=(float scalar);
        const Vector4& operator/=(float scalar);
        const Vector4 operator*(float scalar) const;
        const Vector4 operator/(float scalar) const;
        const Vector4 operator-() const; // unary
        float& operator[](size_t i);
        const float& operator[](size_t i) const;

        friend std::ostream& operator<<(std::ostream& stream, const Vector4& vec);
    };
}
