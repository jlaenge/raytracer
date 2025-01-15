#ifndef HITRECORD_TEST
#define HITRECORD_TEST

#include <TestSuite.hpp>

class HitRecordTest : public TestSuite {

public:
    static HitRecordTest* getInstance();
    void run();

private:
    static HitRecordTest instance;

    void testNoHit();
    void testHit();

};

#endif