#ifndef HIT_RECORD
#define HIT_RECORD

#include <Vector3.hpp>

class HitRecord {

public:
    HitRecord() : hit_(false), t_(0), point_(), normal_() {}
    HitRecord(float t, Vector3 point, Vector3 normal) : hit_(true), t_(t), point_(point), normal_(normal) {}

    HitRecord operator=(const HitRecord& record) {
        hit_ = record.hit_;
        t_ = record.t_;
        point_ = record.point_;
        normal_ = record.normal_;
        return *this;
    }

    bool hit() const { return hit_; }
    float t() const { return t_; }
    Vector3 point() const { return point_; }
    Vector3 normal() const { return normal_; }

private:
    bool hit_;
    float t_;
    Vector3 point_;
    Vector3 normal_;

};

#endif