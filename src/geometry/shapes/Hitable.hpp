#ifndef HITABLE
#define HITABLE

#include <HitRecord.hpp>
#include <Ray.hpp>

class Hitable {

public:

    virtual HitRecord hit(const Ray& ray, float tmin, float tmax) const = 0;
    static bool inRange(float t, float min, float max) {
        return (min < t && t < max);
    }

};

#endif