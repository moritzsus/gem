#pragma once

#include <iostream>

namespace gem
{
    struct Vector2
    {
        float x, y;

        Vector2();
        Vector2(float x, float y);

        float Magnitude() const;
        const Vector2 Normalize() const;

        float Dot(const Vector2& vec) const;

        const Vector2 Project(const Vector2& vec) const;
        const Vector2 Reject(const Vector2& vec) const;

        bool operator==(const Vector2& vec) const;
        const Vector2& operator*=(float scalar);
        const Vector2& operator/=(float scalar);
        const Vector2 operator*(float scalar) const;
        const Vector2 operator/(float scalar) const;
        const Vector2 operator-() const; // unary
        const Vector2& operator+=(const Vector2& vec);
        const Vector2& operator-=(const Vector2& vec);
        const Vector2 operator+(const Vector2& vec) const;
        const Vector2 operator-(const Vector2& vec) const;
        float& operator[](size_t i);
        const float& operator[](size_t i) const;

        friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
    };

    // alternative call methods for class functions
    float magnitude(const Vector2& vec);
    const Vector2 normalize(const Vector2& vec);
    float dot(const Vector2& vec1, const Vector2& vec2);
    const Vector2 project(const Vector2& vec1, const Vector2& vec2);
    const Vector2 reject(const Vector2& vec1, const Vector2& vec2);
}
