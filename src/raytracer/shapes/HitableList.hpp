/******************************************************************************\
 * 
 * HITABLELIST
 * 
 * The hitableList class bundles a group of hitables in one class. Thus it
 * implements the compositon pattern on the Hitable interface.
 * 
 * When computing a hit, the collision of the ray is checked agains all hitables
 * in the list and the object with the closest collision (smallest t-value) is
 * returned (if any).
 * 
\******************************************************************************/

#ifndef HITABLE_LIST
#define HITABLE_LIST

#include <Hitable.hpp>

#include <cassert>
#include <cstdint>

class HitableList : public Hitable {

public:
    HitableList() {}
    HitableList(Hitable** list, uint32_t size) : list_(list), size_(size) { assert(list != nullptr); }

    HitRecord hit(const Ray& ray, float tmin, float tmax) const;

private:
    Hitable** list_;
    uint32_t size_;

};

#endif