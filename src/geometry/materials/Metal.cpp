#include <Metal.hpp>

bool Metal::scatter(const Ray& incoming, const HitRecord& record, Vector3& attenuation, Ray& scattered) const {
    Vector3 reflected = reflect(incoming.direction().make_unit(), record.normal());
    scattered = Ray(record.point(), reflected);
    attenuation = albedo_;
    return (dot(scattered.direction(), record.normal()) > 0);
}

Vector3 Metal::reflect(const Vector3& incoming, const Vector3& normal) const {
    return incoming - 2*dot(incoming, normal)*normal;
}