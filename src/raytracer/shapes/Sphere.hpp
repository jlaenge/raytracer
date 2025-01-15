/******************************************************************************\
 * 
 * SPHERE
 * 
 * The Sphere class implements a hitable. A sphere has a center and a radius.
 * 
\******************************************************************************/

#ifndef SPHERE
#define SPHERE

#include <Hitable.hpp>
#include <HitRecord.hpp>
#include <Material.hpp>
#include <Vector3.hpp>

class Sphere : public Hitable {

public:
    Sphere(Vector3 center, float radius, Material* material) : center_(center), radius_(radius), material_(material) {}

    Vector3 center() const { return center_; }
    float radius() const { return radius_; }
    const Material* material() const { return material_; }

    virtual HitRecord hit(const Ray& ray, float tmin, float tmax) const;

private:
    const Vector3 center_;
    const float radius_;
    const Material* material_;

};

#endif