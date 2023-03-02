#include "Vector3.h"

namespace gem
{
    Vector3::Vector3()
        : x(1), y(1), z(1)
    { }

    Vector3::Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    { }

    Vector3::Vector3(const Vector2& vec, float z)
        : x(vec.x), y(vec.y), z(z)
    { }

    float Vector3::Magnitude() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    const Vector3 Vector3::Normalize() const
    {
        float m = Magnitude();
        return *this / m;
    }

    float Vector3::Dot(const Vector3& vec) const
    {
        return (x * vec.x + y * vec.y + z * vec.z);
    }

    const Vector3 Vector3::Cross(const Vector3& vec) const
    {
        return Vector3(
            y * vec.z - z * vec.y,
            z * vec.x - x * vec.z,
            x * vec.y - y * vec.x
        );
    }

    const Vector3& Vector3::operator*=(float scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }

    const Vector3& Vector3::operator/=(float scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;

        return *this;
    }

    const Vector3 Vector3::operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    const Vector3 Vector3::operator/(float scalar) const
    {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    const Vector3 Vector3::operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    const Vector3& Vector3::operator+=(const Vector3& vec)
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    const Vector3& Vector3::operator-=(const Vector3& vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        return *this;
    }

    const Vector3 Vector3::operator+(const Vector3& vec) const
    {
        return Vector3(x + vec.x, y + vec.y, z + vec.z);
    }

    const Vector3 Vector3::operator-(const Vector3& vec) const
    {
        return Vector3(x - vec.x, y - vec.y, z - vec.z);
    }

    float& Vector3::operator[](size_t i)
    {
        return (&x)[i]; // no bound checking
    }

    const float& Vector3::operator[](size_t i) const
    {
        return (&x)[i]; // no bound checking
    }

    std::ostream& operator<<(std::ostream& stream, const Vector3& vec)
    {
        stream << "<" << vec.x << "," << vec.y << "," << vec.z << ">";
        return stream;
    }

    // alternative call methods for class functions
    float magnitude(const Vector3& vec)
    {
        return vec.Magnitude();
    }

    const Vector3 normalize(const Vector3& vec)
    {
        return vec.Normalize();
    }

    float dot(const Vector3& vec1, const Vector3& vec2)
    {
        return vec1.Dot(vec2);
    }

    const Vector3 cross(const Vector3& vec1, const Vector3& vec2)
    {
        return vec1.Cross(vec2);
    }
}
