#include <SphereTest.hpp>

#include <Lambertian.hpp>
#include <Sphere.hpp>

#include <cstdio>

SphereTest SphereTest::instance;
SphereTest* SphereTest::getInstance() {
    return &instance;
}

void SphereTest::run() {
    testAttributes();
    testHit();
}

void SphereTest::testAttributes() {
    Material* m = new Lambertian(Vector3(1, 2, 3));
    Sphere s(Vector3(1, 2, 3), 42, m);
    Vector3 c = s.center();
    TestSuite::floatEqual(c.x(), 1);
    TestSuite::floatEqual(c.y(), 2);
    TestSuite::floatEqual(c.z(), 3);
    TestSuite::floatEqual(s.radius(), 42);
    assert(s.material() == m);
    free(m);
}

void SphereTest::testHit() {
    Ray r(Vector3(0, 0, 0), Vector3(0, 0, 1));
    Sphere s(Vector3(0, 0, 10), 0.5, nullptr);
    HitRecord rec = s.hit(r, 0, 100);
    assert(rec.hit());
    TestSuite::floatEqual(rec.t(), 9.5);

    Vector3 p = rec.point();
    TestSuite::floatEqual(p.x(), 0);
    TestSuite::floatEqual(p.y(), 0);
    TestSuite::floatEqual(p.z(), 9.5);

    Vector3 n = rec.normal();
    TestSuite::floatEqual(n.x(), 0);
    TestSuite::floatEqual(n.y(), 0);
    TestSuite::floatEqual(n.z(), -1);
}