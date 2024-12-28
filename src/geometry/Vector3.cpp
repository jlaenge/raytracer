#include <Vector3.hpp>

#include <cassert>

void Vector3::make_unit_vector() {
    float len = length();
    assert(len != 0);
    *this /= len;
}