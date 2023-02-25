#include "Vector4.h"

namespace gem
{
    Vector4::Vector4()
        : x(1), y(1), z(1), w(1)
    { }

    Vector4::Vector4(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    { }

    float Vector4::Magnitude() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    Vector4 Vector4::Normalize() const
    {
        float m = Magnitude();
        return *this / m;
    }

    const Vector4& Vector4::operator*=(float scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;

        return *this;
    }

    const Vector4& Vector4::operator/=(float scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;

        return *this;
    }

    const Vector4 Vector4::operator*(float scalar) const
    {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    const Vector4 Vector4::operator/(float scalar) const
    {
        return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    const Vector4 Vector4::operator-() const
    {
        return Vector4(-x, -y, -z, -w);
    }

    const Vector4& Vector4::operator+=(const Vector4& vec)
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;
        return *this;
    }

    const Vector4& Vector4::operator-=(const Vector4& vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        w -= vec.w;
        return *this;
    }

    const Vector4 Vector4::operator+(const Vector4& vec) const
    {
        return Vector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
    }

    const Vector4 Vector4::operator-(const Vector4& vec) const
    {
        return Vector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
    }

    float& Vector4::operator[](size_t i)
    {
        return (&x)[i]; // no bound checking
    }

    const float& Vector4::operator[](size_t i) const
    {
        return (&x)[i]; // no bound checking
    }

    std::ostream& operator<<(std::ostream& stream, const Vector4& vec)
    {
        stream << "<" << vec.x << "," << vec.y << "," << vec.z << "," << vec.w << ">";
        return stream;
    }
}
