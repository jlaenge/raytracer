/******************************************************************************\
 * 
 * MATERIAL
 * 
 * The material interface can be implemented by a surface material. It determins
 * how incoming rays are scattered (absorbed, reflected) by the surface material
 * on contact.
 * 
 * Every class that wishes to implement the scatter interface needs to implement
 * the abstract scatter() method.
 *  
\******************************************************************************/

#ifndef MATERIAL
#define MATERIAL

#include <HitRecord.hpp>
#include <Ray.hpp>
#include <Vector3.hpp>

class HitRecord;

class Material {

public:

    /**
     * Computes the scattering of the ray upon collision.
     * @param incoming - incoming ray
     * @param record - details of collision
     * @param attenuation - absorption factor
     * @param scatter - stores resulting scattered ray
     */
    virtual bool scatter(const Ray& incoming, const HitRecord& record, Vector3& attenuation, Ray& scattered) const = 0;

};

#endif