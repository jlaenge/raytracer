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