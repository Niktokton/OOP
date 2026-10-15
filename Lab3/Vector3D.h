
#pragma once

class Vector3D
{
private:
    double x;
    double y;
    double z;

    mutable int accessCount;
    static int createdCount;

public:
    Vector3D();
    Vector3D(double xValue, double yValue, double zValue);
    Vector3D(const Vector3D& other);
    explicit Vector3D(double value);

    ~Vector3D();

    double getX() const;
    double getY() const;
    double getZ() const;
    double length() const;
    int getAccessCount() const;

    static int getCreatedCount();

    void print() const;

    Vector3D& operator+=(const Vector3D& other);
    Vector3D& operator-=(const Vector3D& other);
    Vector3D& operator*=(const Vector3D& other);
    Vector3D& operator/=(const Vector3D& other);

    Vector3D& operator*=(double scalar);
    Vector3D& operator/=(double scalar);

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(const Vector3D& other) const;
    Vector3D operator/(const Vector3D& other) const;

    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;

    Vector3D& operator++();
    Vector3D operator++(int);

    Vector3D& operator--();
    Vector3D operator--(int);

    Vector3D operator+() const;
    Vector3D operator-() const;

    bool operator<(const Vector3D& other) const;
    bool operator>(const Vector3D& other) const;
    bool operator<=(const Vector3D& other) const;
    bool operator>=(const Vector3D& other) const;
    bool operator==(const Vector3D& other) const;
    bool operator!=(const Vector3D& other) const;
};

Vector3D operator*(double scalar, const Vector3D& vector);
