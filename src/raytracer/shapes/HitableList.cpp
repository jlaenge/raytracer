#include <HitableList.hpp>

HitRecord HitableList::hit(const Ray& ray, float tmin, float tmax) const {
    HitRecord record;
    float closest = tmax;

    int index = -1;
    for(int i=0; i<size_; i++) {
        HitRecord currentRecord = list_[i]->hit(ray, tmin, closest);
        if(currentRecord.hit()) {
            record = currentRecord;
            closest = currentRecord.t();

        }
    }
    
    return record;
}