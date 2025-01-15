#ifndef LAMBERTIAN
#define LAMBERTIAN

#include <Material.hpp>

class Lambertian : public Material {

public:
    Lambertian(const Vector3& albedo) : albedo_(albedo) {}
    bool scatter(const Ray& incoming, const HitRecord& record, Vector3& attenuation, Ray& scattered) const;

private:
    const Vector3 albedo_;

};

#endif