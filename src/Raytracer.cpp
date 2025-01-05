#include <Raytracer.hpp>

#include <Image.hpp>
#include <PortablePixelmap.hpp>

void Raytracer::render() {
    Image image(kWidth, kHeight);

    Vector3 origin(0, 0, 0);
    Vector3 bottom_left(-2, -1, -1);
    Vector3 horizontal(4, 0, 0);
    Vector3 vertical(0, 2, 0);

    float* data = image.getData();
    for(uint32_t y=0; y<kHeight; y++) {
        for(uint32_t x=0; x<kWidth; x++) {
            float x_ = static_cast<float>(x) / static_cast<float>(kWidth);
            float y_ = static_cast<float>(kHeight-y-1) / static_cast<float>(kHeight);

            Ray ray(origin, bottom_left + x_ * horizontal + y_ * vertical);
            Vector3 color_ = color(ray);
            *data++ = color_.x();
            *data++ = color_.y();
            *data++ = color_.z();
            
        }
    }
    PortablePixelmap::store(&image);
}

bool Raytracer::hitsSphere(const Vector3& center, float radius, const Ray& ray) {
    Vector3 origin_to_center = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = 2.0 * dot(origin_to_center, ray.direction());
    float c = dot(origin_to_center, origin_to_center) - radius*radius;
    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

Vector3 Raytracer::color(const Ray& ray) {
    static Vector3 v1(1, 1, 1);
    static Vector3 v2(0.5, 0.7, 1.0);

    if(hitsSphere(Vector3(0, 0, -1), 0.5, ray)) {
        return Vector3(1, 0, 0);
    }

    Vector3 direction = ray.direction();
    direction.make_unit_vector();
    float t = 0.5 * (direction.y() + 1.0);
    Vector3 result = ((1.0-t)*v1 + t*v2);
    return result;
}