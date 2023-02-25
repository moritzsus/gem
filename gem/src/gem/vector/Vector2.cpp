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

    Vector2 Vector2::Normalize() const
    {
        float m = Magnitude();
        return *this / m;
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
}
