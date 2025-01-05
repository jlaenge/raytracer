#ifndef CAMERA
#define CAMERA

#include <Ray.hpp>
#include <Vector3.hpp>

class Camera {

public:
    Camera(Vector3 lowerLeft, Vector3 horizontal, Vector3 vertical, Vector3 origin) :
        lowerLeft_(lowerLeft), horizontal_(horizontal), vertical_(vertical), origin_(origin) {}

    Vector3 lowerLeft() const { return lowerLeft_; }
    Vector3 horizontal() const { return horizontal_; }
    Vector3 vertical() const { return vertical_; }
    Vector3 origin() const { return origin_; }

    Ray getRay(float x, float y) {
        return Ray(origin_, lowerLeft_ + x*horizontal_ + y*vertical_ - origin_);
    }

private:
    Vector3 lowerLeft_;
    Vector3 horizontal_;
    Vector3 vertical_;
    Vector3 origin_;

};

#endif