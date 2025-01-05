#ifndef RAYTRACER
#define RAYTRACER

#include <Ray.hpp>
#include <Vector3.hpp>

#include <cstdint>

class Raytracer {

public:
    Raytracer() {}
    virtual ~Raytracer() {}

    void render();

private:
    const uint32_t kWidth = 200;
    const uint32_t kHeight = 100;

    float hitsSphere(const Vector3& center, float radius, const Ray& ray) const;

    Vector3 color(const Ray& ray) const;

};

#endif