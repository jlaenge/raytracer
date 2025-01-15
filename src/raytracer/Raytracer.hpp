/******************************************************************************\
 * 
 * RAYTRACER
 * 
 * The raytracer class implements the main rendering function, i.e.:
 * - loop over all pixels of the image
 * - shoot our rays from the camera to the current pixel
 * - compute the pixels color from the resulting collisions
 * - render the final image
 * 
\******************************************************************************/

#ifndef RAYTRACER
#define RAYTRACER

#include <Hitable.hpp>
#include <HitableList.hpp>
#include <Ray.hpp>
#include <Vector3.hpp>

#include <cstdint>
#include <cstdio>

typedef Vector3 (*GammaCorrection)(Vector3);

class Raytracer {

public:
    Raytracer() {}
    virtual ~Raytracer() {}

    /**
     * Renders the scene to the given file.
     */
    void render(FILE* destination);

private:
    // image width and height, and number of rays shot for every pixel
    const uint32_t kWidth = 200;
    const uint32_t kHeight = 100;
    const uint32_t kNumSamples = 100;   // careful with incrementing this parameter, as it slows down the rendering significantly

    const uint32_t kMaxDepth = 50;

    const float ktMin = 0.001;
    const float ktMax = MAXFLOAT;

    HitableList& world = world1();ll

    // gamma correction function
    const GammaCorrection kGammaCorrection = Raytracer::gammaSqrt;
    static Vector3 gammaSqrt(Vector3 v);

    /**
     * Computes the color for a given ray in a world of hitable objects.
     */
    Vector3 color(const Ray& ray, const Hitable& world, int depth) const;

    // worlds to test with
    HitableList& world1();
    HitableList& world2();

};

#endif