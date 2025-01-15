/******************************************************************************\
 * 
 * HITABLE
 * 
 * The hitable interface can be implemented by 3D objects (or lists of objects),
 * so that they can be used in the raytracer. The raytracer is given a world,
 * which consists of hitables and determines the collision between its outgoing
 * rays and these hitable objects.
 * 
 * Every class that wishes to implement the hitable interface needs to implement
 * the abstract hit() method.
 *  
\******************************************************************************/

#ifndef HITABLE
#define HITABLE

#include <HitRecord.hpp>
#include <Ray.hpp>

class Hitable {

public:

    /**
     * Computes details for the collision of the given ray. In particular,
     * a HitRecord will track if the ray hits this object, and where the
     * collision takes place.
     * @param ray - ray that tries to hit this object
     * @param tmin - minimum time of collision
     * @param tmax - maximum time of collision
     */
    virtual HitRecord hit(const Ray& ray, float tmin, float tmax) const = 0;

    /**
     * Is the time parameter t within the min-max range?
     */
    static bool inRange(float t, float min, float max) {
        return (min < t && t < max);
    }

};

#endif