#ifndef VECTOR3
#define VECTOR3

#include <cassert>
#include <cmath>

class Vector3 {

public:
    Vector3(const Vector3& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}
    Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}
    Vector3() : Vector3(0, 0, 0) {}

    inline float x() const { return x_; }
    inline float y() const { return y_; }
    inline float z() const { return z_; }

    inline void operator+=(const Vector3& v) { x_ += v.x_; y_ += v.y_; z_ += v.z_; }
    inline void operator-=(const Vector3& v) { x_ -= v.x_; y_ -= v.y_; z_ -= v.z_; }
    inline void operator*=(float f) { x_ *= f; y_ *= f; z_ *= f; }
    inline void operator/=(float f) { assert(f != 0); x_ /= f; y_ /= f; z_ /= f; }

    inline Vector3 operator+(const Vector3& v) const { return Vector3(x_ + v.x_, y_ + v.y_, z_ + v.z_); }
    inline Vector3 operator-(const Vector3& v) const { return Vector3(x_ - v.x_, y_ - v.y_, z_ - v.z_); }
    inline Vector3 operator*(float f) const { return Vector3(x_ * f, y_ * f, z_ * f); }
    inline Vector3 operator/(float f) const { assert(f != 0); return Vector3(x_ / f, y_ / f, z_ / f); }

    inline float length() { return static_cast<float>(sqrt(x_*x_ + y_*y_ + z_*z_)); }
    void make_unit_vector();

private:
    float x_;
    float y_;
    float z_;

};

inline Vector3 operator*(float f, const Vector3& v) { return Vector3(f * v.x(), f* v.y(), f * v.z()); }
inline Vector3 operator/(float f, const Vector3& v) { assert(f != 0); return Vector3(f / v.x(), f / v.y(), f / v.z()); }

#endif