#include <Vector3.hpp>

#include <cassert>

void Vector3::operator/=(float f) {
    assert(f != 0);
    x_ /= f;
    y_ /= f;
    z_ /= f;
}

void Vector3::make_unit_vector() {
    float len = length();
    assert(len != 0);
    *this /= len;
}