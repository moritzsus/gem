#pragma once

#include <iostream>

namespace gem
{
    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);

        float Magnitude() const;
        Vector3 Normalize() const;

        const Vector3& operator*=(float scalar);
        const Vector3& operator/=(float scalar);
        const Vector3 operator*(float scalar) const;
        const Vector3 operator/(float scalar) const;
        const Vector3 operator-() const; // unary
        const Vector3& operator+=(const Vector3& vec);
        const Vector3& operator-=(const Vector3& vec);
        const Vector3 operator+(const Vector3& vec) const;
        const Vector3 operator-(const Vector3& vec) const;
        float& operator[](size_t i);
        const float& operator[](size_t i) const;

        friend std::ostream& operator<<(std::ostream& stream, const Vector3& vec);
    };
}
