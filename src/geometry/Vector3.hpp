#ifndef VECTOR3
#define VECTOR3

#include <cmath>

class Vector3 {

public:
    Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}
    Vector3() : Vector3(0, 0, 0) {}

    inline float x() { return x_; }
    inline float y() { return y_; }
    inline float z() { return z_; }

    void operator/=(float f);

    inline float length() { return static_cast<float>(sqrt(x_*x_ + y_*y_ + z_*z_)); }
    void make_unit_vector();

private:
    float x_;
    float y_;
    float z_;

};

#endif