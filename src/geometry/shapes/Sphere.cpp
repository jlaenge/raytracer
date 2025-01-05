#include <Sphere.hpp>

#include <cmath>

HitRecord Sphere::hit(const Ray& ray, float tmin, float tmax) const {
    Vector3 origin_to_center = ray.origin() - center_;
    float a = dot(ray.direction(), ray.direction());
    float b = dot(origin_to_center, ray.direction());
    float c = dot(origin_to_center, origin_to_center) - radius_*radius_;
    float discriminant = b*b - a*c;

    // no hit
    if(discriminant <= 0) {
        return HitRecord();
    }

    // in range
    float tmp = (-b - sqrt(b*b-a*c)) / a;
    if( !Hitable::inRange(tmp, tmin, tmax) ) {
        tmp = (-b + sqrt(b*b-a*c)) / a;
    }
    if( Hitable::inRange(tmp, tmin, tmax) ) {
        float t = tmp;
        Vector3 point = ray.trace(t);
        Vector3 normal = (point - center_) / radius_;
        return HitRecord(t, point, normal);
    }

    return HitRecord();

}