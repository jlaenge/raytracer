#ifndef SPHERE
#define SPHERE

#include <Vector3.hpp>

class Sphere {

public:
    Sphere(Vector3 center, float radius) : center_(center), radius_(radius) {}

    Vector3 center() const { return center_; }
    float radius() const { return radius_; }

private:
    const Vector3 center_;
    const float radius_;

};

#endif