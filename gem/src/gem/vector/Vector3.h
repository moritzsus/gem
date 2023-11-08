#pragma once

#include <iostream>
#include "Vector2.h"

namespace gem
{
    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);
        Vector3(const Vector2& vec, float z);

        float Magnitude() const;
        const Vector3 Normalize() const;

        float Dot(const Vector3& vec) const;
        const Vector3 Cross(const Vector3& vec) const;

        const Vector3 Project(const Vector3& vec) const;
        const Vector3 Reject(const Vector3& vec) const;

        //TODO operator* (componentwise?)
        explicit operator Vector2() const;
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

    // alternative call methods for class functions
    float magnitude(const Vector3& vec);
    const Vector3 normalize(const Vector3& vec);
    float dot(const Vector3& vec1, const Vector3& vec2);
    const Vector3 cross(const Vector3& vec1, const Vector3& vec2);
    const Vector3 project(const Vector3& vec1, const Vector3& vec2);
    const Vector3 reject(const Vector3& vec1, const Vector3& vec2);
}
