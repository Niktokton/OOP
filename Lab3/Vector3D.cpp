
#include "Vector3D.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int Vector3D::createdCount = 0;

Vector3D::Vector3D()
    : x(0.0), y(0.0), z(0.0), accessCount(0)
{
    ++createdCount;
}

Vector3D::Vector3D(double xValue, double yValue, double zValue)
    : x(xValue), y(yValue), z(zValue), accessCount(0)
{
    ++createdCount;
}

Vector3D::Vector3D(const Vector3D& other)
    : x(other.x),
      y(other.y),
      z(other.z),
      accessCount(0)
{
    ++createdCount;
}

Vector3D::Vector3D(double value)
    : x(value), y(value), z(value), accessCount(0)
{
    ++createdCount;
}

Vector3D::~Vector3D()
{
    cout << "\nVector3D destroyed: ("<< x << ", " << y << ", " << z << ")";
}

double Vector3D::getX() const
{
    ++accessCount;
    return x;
}

double Vector3D::getY() const
{
    ++accessCount;
    return y;
}

double Vector3D::getZ() const
{
    ++accessCount;
    return z;
}

double Vector3D::length() const
{
    ++accessCount;
    return sqrt(x * x + y * y + z * z);
}

int Vector3D::getAccessCount() const
{
    return accessCount;
}

int Vector3D::getCreatedCount()
{
    return createdCount;
}

void Vector3D::print() const
{
    cout << "(" << x << ", " << y << ", " << z << ")";
}

Vector3D& Vector3D::operator+=(const Vector3D& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3D& Vector3D::operator*=(const Vector3D& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3D& Vector3D::operator/=(const Vector3D& other)
{
    if (other.x == 0.0 || other.y == 0.0 || other.z == 0.0)
    {
        throw invalid_argument(
            "Division by a vector with a zero coordinate");
    }

    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vector3D& Vector3D::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3D& Vector3D::operator/=(double scalar)
{
    if (scalar == 0.0)
    {
        throw invalid_argument("Division by zero");
    }

    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other) const
{
    Vector3D result(*this);
    result += other;
    return result;
}

Vector3D Vector3D::operator-(const Vector3D& other) const
{
    Vector3D result(*this);
    result -= other;
    return result;
}

Vector3D Vector3D::operator*(const Vector3D& other) const
{
    Vector3D result(*this);
    result *= other;
    return result;
}

Vector3D Vector3D::operator/(const Vector3D& other) const
{
    Vector3D result(*this);
    result /= other;
    return result;
}

Vector3D Vector3D::operator*(double scalar) const
{
    Vector3D result(*this);
    result *= scalar;
    return result;
}

Vector3D Vector3D::operator/(double scalar) const
{
    Vector3D result(*this);
    result /= scalar;
    return result;
}

Vector3D& Vector3D::operator++()
{
    *this *= 1.01;
    return *this;
}

Vector3D Vector3D::operator++(int)
{
    Vector3D old(*this);
    *this *= 1.01;
    return old;
}

Vector3D& Vector3D::operator--()
{
    *this *= 0.99;
    return *this;
}

Vector3D Vector3D::operator--(int)
{
    Vector3D old(*this);
    *this *= 0.99;
    return old;
}

Vector3D Vector3D::operator+() const
{
    return Vector3D(x, y, z);
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}

bool Vector3D::operator<(const Vector3D& other) const
{
    return length() < other.length();
}

bool Vector3D::operator>(const Vector3D& other) const
{
    return other < *this;
}

bool Vector3D::operator<=(const Vector3D& other) const
{
    return !(*this > other);
}

bool Vector3D::operator>=(const Vector3D& other) const
{
    return !(*this < other);
}

bool Vector3D::operator==(const Vector3D& other) const
{
    return length() == other.length();
}

bool Vector3D::operator!=(const Vector3D& other) const
{
    return !(*this == other);
}

Vector3D operator*(double scalar, const Vector3D& vector)
{
    return vector * scalar;
}
