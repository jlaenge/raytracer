#include <Lambertian.hpp>

#include <Random.hpp>

bool Lambertian::scatter(const Ray& incoming, const HitRecord& record, Vector3& attenuation, Ray& scattered) const {
    Vector3 target = record.point() + record.normal() + Random::getInstance()->randomInUnitSphere();
    scattered = Ray(record.point(), target - record.point());
    attenuation = albedo_;
    return true;
}