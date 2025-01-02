#ifndef RAY
#define RAY

#include <Vector3.hpp>

class Ray {

public:
    Ray(const Vector3& origin, const Vector3& direction) : origin_(origin), direction_(direction) {}
    virtual ~Ray() {}

    Vector3 direction() const { return Vector3(direction_); }
    Vector3 trace(float t) const { return origin_ + t * direction_; }

private:
    Vector3 origin_;
    Vector3 direction_;

};

#endif