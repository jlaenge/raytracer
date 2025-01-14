/******************************************************************************\
 * 
 * RAY
 * 
 * A ray has an origin and a direction. The most essential method of the class
 * is the trace(), which computes the points on the ray at a given time.
 * 
\******************************************************************************/

#ifndef RAY
#define RAY

#include <Vector3.hpp>

class Ray {

public:
    Ray(const Vector3& origin, const Vector3& direction) : origin_(origin), direction_(direction) {}
    virtual ~Ray() {}

    Vector3 origin() const { return origin_; }
    Vector3 direction() const { return direction_; }
    Vector3 trace(float t) const { return origin_ + t * direction_; }

private:
    const Vector3 origin_;
    const Vector3 direction_;

};

#endif