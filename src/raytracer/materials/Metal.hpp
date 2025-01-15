#ifndef METAL
#define METAL

#include <Material.hpp>

class Metal : public Material {

public:
    Metal(Vector3 albedo) : albedo_(albedo) {}
    bool scatter(const Ray& incoming, const HitRecord& record, Vector3& attenuation, Ray& scattered) const;

private:
    const Vector3 albedo_;

    /**
     * Reflection is computed by:
     * "Angle of incidence equals angle of reflection"
     * @param incoming - vector of incoming ray
     * @param normal - surface normal at hitpoint
     * @returns outgoing vector
     */
    Vector3 reflect(const Vector3& incoming, const Vector3& unit) const;

};

#endif