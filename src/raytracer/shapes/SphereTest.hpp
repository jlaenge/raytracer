#ifndef SPHERE_TEST
#define SPHERE_TEST

#include <TestSuite.hpp>

class SphereTest : public TestSuite {

public:
    static SphereTest* getInstance();
    void run();

private:
    static SphereTest instance;

    void testAttributes();
    void testHit();

};

#endif