#include <RayTest.hpp>

#include <Ray.hpp>

RayTest RayTest::instance;
RayTest* RayTest::getInstance() {
    return &instance;
}

void RayTest::run() {
    testTrace();
}

void RayTest::testTrace() {
    Ray r1(Vector3(), Vector3(1, 2, 3));
    Vector3 p1 = r1.trace(0.5);
    TestSuite::floatEqual(p1.x(), 0.5);
    TestSuite::floatEqual(p1.y(), 1);
    TestSuite::floatEqual(p1.z(), 1.5);

    Vector3 p2 = r1.trace(1);
    TestSuite::floatEqual(p2.x(), 1);
    TestSuite::floatEqual(p2.y(), 2);
    TestSuite::floatEqual(p2.z(), 3);

    Vector3 p3 = r1.trace(10);
    TestSuite::floatEqual(p3.x(), 10);
    TestSuite::floatEqual(p3.y(), 20);
    TestSuite::floatEqual(p3.z(), 30);

    Ray r2(Vector3(1, 2, 3), Vector3(1, -1, 0));
    Vector3 p4 = r2.trace(0.5);
    TestSuite::floatEqual(p4.x(), 1.5);
    TestSuite::floatEqual(p4.y(), 1.5);
    TestSuite::floatEqual(p4.z(), 3);

    Vector3 p5 = r2.trace(1);
    TestSuite::floatEqual(p5.x(), 2);
    TestSuite::floatEqual(p5.y(), 1);
    TestSuite::floatEqual(p5.z(), 3);

    Vector3 p6 = r2.trace(10);
    TestSuite::floatEqual(p6.x(), 11);
    TestSuite::floatEqual(p6.y(), -8);
    TestSuite::floatEqual(p6.z(), 3);
}