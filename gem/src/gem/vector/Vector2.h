#pragma once

#include <iostream>

struct Vector2
{
    float x, y;

    Vector2();
    Vector2(float x, float y);

    float Magnitude() const;
    Vector2 Normalize() const;

    const Vector2& operator*=(float scalar);
    const Vector2& operator/=(float scalar);
    const Vector2 operator*(float scalar) const;
    const Vector2 operator/(float scalar) const;
    const Vector2 operator-() const; // unary
    float& operator[](size_t i);
    const float& operator[](size_t i) const;

    friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
};