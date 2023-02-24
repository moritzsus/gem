#include "Vector3.h"

Vector3::Vector3()
    : x(1), y(1), z(1)
{ }

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{ }

float Vector3::Magnitude() const
{
    return sqrt(x * x + y * y + z*z);
}

Vector3 Vector3::Normalize() const
{
    float m = Magnitude();
    return *this / m;
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