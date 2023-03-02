#include "Vector2.h"

namespace gem
{
    Vector2::Vector2()
        : x(1), y(1)
    { }

    Vector2::Vector2(float x, float y)
        : x(x), y(y)
    { }

    float Vector2::Magnitude() const
    {
        return sqrt(x * x + y * y);
    }

    const Vector2 Vector2::Normalize() const
    {
        float m = Magnitude();
        return *this / m;
    }

    float Vector2::Dot(const Vector2& vec) const
    {
        return (x * vec.x + y * vec.y);
    }

    const Vector2 Vector2::Project(const Vector2& vec) const
    {
        return vec * (Dot(vec) / vec.Dot(vec));
    }

    const Vector2 Vector2::Reject(const Vector2& vec) const
    {
        return *this - Project(vec);
    }

    const Vector2& Vector2::operator*=(float scalar)
    {
        this->x *= scalar;
        this->y *= scalar;

        return *this;
    }

    const Vector2& Vector2::operator/=(float scalar)
    {
        this->x /= scalar;
        this->y /= scalar;

        return *this;
    }

    const Vector2 Vector2::operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    const Vector2 Vector2::operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    const Vector2 Vector2::operator-() const
    {
        return Vector2(-x, -y);
    }

    const Vector2& Vector2::operator+=(const Vector2& vec)
    {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    const Vector2& Vector2::operator-=(const Vector2& vec)
    {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    const Vector2 Vector2::operator+(const Vector2& vec) const
    {
        return Vector2(x + vec.x, y + vec.y);
    }

    const Vector2 Vector2::operator-(const Vector2& vec) const
    {
        return Vector2(x - vec.x, y - vec.y);
    }

    float& Vector2::operator[](size_t i)
    {
        return (&x)[i]; // no bound checking
    }

    const float& Vector2::operator[](size_t i) const
    {
        return (&x)[i]; // no bound checking
    }

    std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
    {
        stream << "<" << vec.x << "," << vec.y << ">";
        return stream;
    }

    // alternative call methods for class functions
    float magnitude(const Vector2& vec)
    {
        return vec.Magnitude();
    }

    const Vector2 normalize(const Vector2& vec)
    {
        return vec.Normalize();
    }

    float dot(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.Dot(vec2);
    }

    const Vector2 project(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.Project(vec2);
    }

    const Vector2 reject(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.Reject(vec2);
    }
}
