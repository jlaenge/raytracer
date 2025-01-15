#include <RayTest.hpp>

#include <Ray.hpp>

RayTest RayTest::instance;
RayTest* RayTest::getInstance() {
    return &instance;
}

void RayTest::run() {
    testAttributes();
    testAssignment();
    testTrace();
}

void RayTest::testAttributes() {
    Ray r1;
    Vector3 origin1 = r1.origin();
    TestSuite::floatEqual(origin1.x(), 0);
    TestSuite::floatEqual(origin1.y(), 0);
    TestSuite::floatEqual(origin1.z(), 0);

    Vector3 direction1 = r1.direction();
    TestSuite::floatEqual(direction1.x(), 0);
    TestSuite::floatEqual(direction1.y(), 0);
    TestSuite::floatEqual(direction1.z(), 0);

    Ray r2(Vector3(1, 2, 3), Vector3(4, 5, 6));
    Vector3 origin2 = r2.origin();
    TestSuite::floatEqual(origin2.x(), 1);
    TestSuite::floatEqual(origin2.y(), 2);
    TestSuite::floatEqual(origin2.z(), 3);

    Vector3 direction2 = r2.direction();
    TestSuite::floatEqual(direction2.x(), 4);
    TestSuite::floatEqual(direction2.y(), 5);
    TestSuite::floatEqual(direction2.z(), 6);
}

void RayTest::testAssignment() {
    Ray r1(Vector3(1, 2, 3), Vector3(4, 5, 6));
    Ray r2(Vector3(7, 8, 9), Vector3(10, 11, 12));

    Vector3 origin1 = r1.origin();
    TestSuite::floatEqual(origin1.x(), 1);
    TestSuite::floatEqual(origin1.y(), 2);
    TestSuite::floatEqual(origin1.z(), 3);
    Vector3 direction1 = r1.direction();
    TestSuite::floatEqual(direction1.x(), 4);
    TestSuite::floatEqual(direction1.y(), 5);
    TestSuite::floatEqual(direction1.z(), 6);
    Vector3 origin2 = r2.origin();
    TestSuite::floatEqual(origin2.x(), 7);
    TestSuite::floatEqual(origin2.y(), 8);
    TestSuite::floatEqual(origin2.z(), 9);
    Vector3 direction2 = r2.direction();
    TestSuite::floatEqual(direction2.x(), 10);
    TestSuite::floatEqual(direction2.y(), 11);
    TestSuite::floatEqual(direction2.z(), 12);

    r2 = r1;
    origin1 = r1.origin();
    TestSuite::floatEqual(origin1.x(), 1);
    TestSuite::floatEqual(origin1.y(), 2);
    TestSuite::floatEqual(origin1.z(), 3);
    direction1 = r1.direction();
    TestSuite::floatEqual(direction1.x(), 4);
    TestSuite::floatEqual(direction1.y(), 5);
    TestSuite::floatEqual(direction1.z(), 6);
    origin2 = r2.origin();
    TestSuite::floatEqual(origin2.x(), 1);
    TestSuite::floatEqual(origin2.y(), 2);
    TestSuite::floatEqual(origin2.z(), 3);
    direction2 = r2.direction();
    TestSuite::floatEqual(direction2.x(), 4);
    TestSuite::floatEqual(direction2.y(), 5);
    TestSuite::floatEqual(direction2.z(), 6);
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