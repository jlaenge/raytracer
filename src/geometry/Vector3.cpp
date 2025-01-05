#include <Vector3.hpp>

#include <cassert>

Vector3 Vector3::make_unit() const {
    Vector3 result(*this);
    float len = length();
    assert(len != 0);
    return result;
}