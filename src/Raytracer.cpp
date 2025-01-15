#include <Raytracer.hpp>

#include <Camera.hpp>
#include <HitableList.hpp>
#include <Image.hpp>
#include <PortablePixelmap.hpp>
#include <Random.hpp>
#include <Sphere.hpp>

void Raytracer::render() {
    Image image(kWidth, kHeight);

    Sphere s1(Vector3(0, 0, -1), 0.5);
    Sphere s2(Vector3(0, -100.5, -1), 100);
    Hitable* list[] = { &s1, &s2 };
    HitableList world(list, 2);

    Camera camera(Vector3(-2, -1, -1), Vector3(4, 0, 0), Vector3(0, 2, 0), Vector3(0, 0, 0));
    float* data = image.getData();
    for(uint32_t y=0; y<kHeight; y++) {
        for(uint32_t x=0; x<kWidth; x++) {

            Vector3 color_(0, 0, 0);
            for(int s=0; s < kNumSamples; s++) {

                float x_ = static_cast<float>(x+Random::getInstance()->getNext()) / static_cast<float>(kWidth);
                float y_ = static_cast<float>(kHeight-y-1+Random::getInstance()->getNext()) / static_cast<float>(kHeight);

                Ray ray = camera.getRay(x_, y_);
                Vector3 point = ray.trace(2.0);
                color_ += color(ray, world);
            }
            color_ /= static_cast<float>(kNumSamples);
            color_ = kGammaCorrection(color_);
            *data++ = color_.x();
            *data++ = color_.y();
            *data++ = color_.z();
            
        }
    }
    PortablePixelmap::store(&image);
}

Vector3 Raytracer::gammaSqrt(Vector3 v) {
    return Vector3(sqrt(v.x()), sqrt(v.y()), sqrt(v.z()));
}

Vector3 Raytracer::color(const Ray& ray, const Hitable& world) const {
    static Vector3 v1(1, 1, 1);
    static Vector3 v2(0.5, 0.7, 1.0);

    static Vector3 circleCenter(0, 0, -1);
    static float circleRadius = 0.5;

    HitRecord record = world.hit(ray, ktMin, ktMax);
    if(record.hit()) {
        Vector3 target = record.point() + record.normal() + Random::getInstance()->randomInUnitSphere();
        return 0.5 * color(Ray(record.point(), target-record.point()), world);
    } else {
        Vector3 direction = ray.direction().make_unit();
        float t = 0.5 * (direction.y() + 1.0);
        return ((1.0-t)*v1 + t*v2);
    }
}