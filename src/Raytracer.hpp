#ifndef RAYTRACER
#define RAYTRACER

#include <Hitable.hpp>
#include <Ray.hpp>
#include <Vector3.hpp>

#include <cstdint>

typedef Vector3 (*GammaCorrection)(Vector3);

class Raytracer {

public:
    Raytracer() {}
    virtual ~Raytracer() {}

    void render();

private:
    const uint32_t kWidth = 200;
    const uint32_t kHeight = 100;
    const uint32_t kNumSamples = 100;

    const GammaCorrection kGammaCorrection = Raytracer::gammaSqrt;
    static Vector3 gammaSqrt(Vector3 v);

    Vector3 randomInUnitSphere() const;
    Vector3 color(const Ray& ray, const Hitable& world) const;

};

#endif