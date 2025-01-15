#include <Raytracer.hpp>

#include <Camera.hpp>
#include <HitableList.hpp>
#include <Image.hpp>
#include <Lambertian.hpp>
#include <Material.hpp>
#include <Metal.hpp>
#include <PortablePixelmap.hpp>
#include <Random.hpp>
#include <Sphere.hpp>

void Raytracer::render(FILE* destination) {
    Image image(kWidth, kHeight);

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
                color_ += color(ray, world, 0);
            }
            color_ /= static_cast<float>(kNumSamples);
            color_ = kGammaCorrection(color_);
            *data++ = color_.x();
            *data++ = color_.y();
            *data++ = color_.z();
            
        }
    }
    PortablePixelmap::store(&image, destination);
}

Vector3 Raytracer::gammaSqrt(Vector3 v) {
    return Vector3(sqrt(v.x()), sqrt(v.y()), sqrt(v.z()));
}

Vector3 Raytracer::color(const Ray& ray, const Hitable& world, int depth) const {
    static const Vector3 v1(1, 1, 1);
    static const Vector3 v2(0.5, 0.7, 1.0);

    static const Vector3 circleCenter(0, 0, -1);
    static const float circleRadius = 0.5;

    HitRecord record = world.hit(ray, ktMin, ktMax);
    if(record.hit()) {
        Ray scattered;
        Vector3 attenuation;
        if(depth < kMaxDepth && record.material()->scatter(ray, record, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth+1);
        } else {
            return Vector3();
        }
    } else {
        Vector3 direction = ray.direction().make_unit();
        float t = 0.5 * (direction.y() + 1.0);
        return ((1.0-t)*v1 + t*v2);
    }
}

HitableList& Raytracer::world1() {
    static Lambertian l1(Vector3(0.8, 0.3, 0.3));
    static Lambertian l2(Vector3(0.8, 0.8, 0.0));
    static Metal m1(Vector3(0.8, 0.6, 0.2));
    static Metal m2(Vector3(0.8, 0.8, 0.8));
    static Sphere s1(Vector3(0, 0, -1), 0.5, &l1);
    static Sphere s2(Vector3(0, -100.5, -1), 100, &l2);
    static Sphere s3(Vector3(1, 0, -1), 0.5,  &m1);
    static Sphere s4(Vector3(-1, 0, -1), 0.5, &m2);

    static Hitable* list[] = { &s1, &s2, &s3, &s4 };
    static HitableList world(list, 4);
    return world;
}

HitableList& Raytracer::world2() {
    static Lambertian l1(Vector3(0.8, 0.3, 0.3));
    static Metal m1(Vector3(0.8, 0.6, 0.2));
    static Sphere s1(Vector3(0, -100.5, -1), 100, &l1);
    static Sphere s2(Vector3(0, 0, -1), 0.5, &m1);

    static Hitable* list[] = { &s1, &s2 };
    static HitableList world(list, 2);
    return world;
}