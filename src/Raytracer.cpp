#include <Raytracer.hpp>

#include <Image.hpp>
#include <PortablePixelmap.hpp>

#include <HitableList.hpp>
#include <Sphere.hpp>

void Raytracer::render() {
    Image image(kWidth, kHeight);

    Vector3 origin(0, 0, 0);
    Vector3 bottom_left(-2, -1, -1);
    Vector3 horizontal(4, 0, 0);
    Vector3 vertical(0, 2, 0);

    Sphere s1(Vector3(0, 0, -1), 0.5);
    Sphere s2(Vector3(0, -100.5, -1), 100);
    Hitable* list[] = { &s1, &s2 };
    HitableList world(list, 2);

    float* data = image.getData();
    for(uint32_t y=0; y<kHeight; y++) {
        for(uint32_t x=0; x<kWidth; x++) {
            float x_ = static_cast<float>(x) / static_cast<float>(kWidth);
            float y_ = static_cast<float>(kHeight-y-1) / static_cast<float>(kHeight);

            Ray ray(origin, bottom_left + x_ * horizontal + y_ * vertical);
            Vector3 color_ = color(ray, world);
            *data++ = color_.x();
            *data++ = color_.y();
            *data++ = color_.z();
            
        }
    }
    PortablePixelmap::store(&image);
}

Vector3 Raytracer::color(const Ray& ray, const Hitable& world) const {
    static Vector3 v1(1, 1, 1);
    static Vector3 v2(0.5, 0.7, 1.0);

    static Vector3 circleCenter(0, 0, -1);
    static float circleRadius = 0.5;

    HitRecord record = world.hit(ray, 0, MAXFLOAT);
    if(record.hit()) {
        return 0.5 * Vector3(record.normal() + Vector3(1, 1, 1));
    } else {
        Vector3 direction = ray.direction().make_unit();
        float t = 0.5 * (direction.y() + 1.0);
        return ((1.0-t)*v1 + t*v2);
    }
}