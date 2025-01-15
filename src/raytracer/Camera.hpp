/******************************************************************************\
 * CAMERA
 * 
 * The camera class implements the perspective of the viewer on the scene. We
 * may also think of this as the eye of the beholder.
 * 
 * It has an origin in 3D space, as well as an angle in which it is looking.
 * The angle is implecitly implemented via the horizontal and vertical vectors.
 * These are used as they make it easier to implement compute the outgoing rays.
 * 
 * The most essential function of this class is the getRay(). It computes a ray
 * that leaves the camera and hits the given point. This is used to compute the
 * color of the given point.
 * 
\******************************************************************************/

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

    /**
     * Computes a ray that leaves the camera (at the origin) and hits the given
     * point.
     */
    Ray getRay(float x, float y) {
        return Ray(origin_, lowerLeft_ + x*horizontal_ + y*vertical_ - origin_);
    }

private:

    // orientation
    Vector3 lowerLeft_;
    Vector3 horizontal_;
    Vector3 vertical_;

    // origin
    Vector3 origin_;

};

#endif