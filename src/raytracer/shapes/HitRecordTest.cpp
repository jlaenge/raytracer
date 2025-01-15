#include <HitRecordTest.hpp>

#include <HitRecord.hpp>
#include <Logger.hpp>

HitRecordTest HitRecordTest::instance;
HitRecordTest* HitRecordTest::getInstance() {
    return &instance;
}

void HitRecordTest::run() {
    LOG_DEBUG("\tTesting HitRecord...");
    testNoHit();
    testHit();
    LOG_DEBUG("[passed]\n");
}

void HitRecordTest::testNoHit() {
    HitRecord r;
    assert(!r.hit());
}

void HitRecordTest::testHit() {
    HitRecord r(0.5, Vector3(1, 2, 3), Vector3(4, 5, 6), nullptr);
    assert(r.hit());
    TestSuite::floatEqual(r.t(), 0.5);

    Vector3 p = r.point();
    TestSuite::floatEqual(p.x(), 1);
    TestSuite::floatEqual(p.y(), 2);
    TestSuite::floatEqual(p.z(), 3);

    Vector3 n = r.normal();
    TestSuite::floatEqual(n.x(), 4);
    TestSuite::floatEqual(n.y(), 5);
    TestSuite::floatEqual(n.z(), 6);

    assert(r.material() == nullptr);
}
