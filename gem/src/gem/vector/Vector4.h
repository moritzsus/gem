#pragma once

#include <iostream>
#include "Vector3.h"

namespace gem
{
    struct Vector4
    {
        float x, y, z, w;

        Vector4();
        Vector4(float x, float y, float z, float w);
        Vector4(const Vector2& vec, float z, float w);
        Vector4(const Vector3& vec, float w);

        float Magnitude() const;
        const Vector4 Normalize() const;

        float Dot(const Vector4& vec) const;

        const Vector4 Project(const Vector4& vec) const;
        const Vector4 Reject(const Vector4& vec) const;

        explicit operator Vector2() const;
        explicit operator Vector3() const;
        const Vector4& operator*=(float scalar);
        const Vector4& operator/=(float scalar);
        const Vector4 operator*(float scalar) const;
        const Vector4 operator/(float scalar) const;
        const Vector4 operator-() const; // unary
        const Vector4& operator+=(const Vector4& vec);
        const Vector4& operator-=(const Vector4& vec);
        const Vector4 operator+(const Vector4& vec) const;
        const Vector4 operator-(const Vector4& vec) const;
        float& operator[](size_t i);
        const float& operator[](size_t i) const;

        friend std::ostream& operator<<(std::ostream& stream, const Vector4& vec);
    };

    // alternative call methods for class functions
    float magnitude(const Vector4& vec);
    const Vector4 normalize(const Vector4& vec);
    float dot(const Vector4& vec1, const Vector4& vec2);
    const Vector4 project(const Vector4& vec1, const Vector4& vec2);
    const Vector4 reject(const Vector4& vec1, const Vector4& vec2);
}
