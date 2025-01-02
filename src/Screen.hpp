#ifndef SCREEN
#define SCREEN

#include <Ray.hpp>
#include <Vector3.hpp>

#include <cstdint>

class Screen {

public:
    Screen() {}
    virtual ~Screen() {}

    void render();

private:
    const uint32_t kWidth = 200;
    const uint32_t kHeight = 100;

    Vector3 color(const Ray& ray);

};

#endif