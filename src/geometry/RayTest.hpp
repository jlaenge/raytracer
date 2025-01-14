#ifndef RAY_TEST
#define RAY_TEST

#include <TestSuite.hpp>

class RayTest : public TestSuite {

public:
    static RayTest* getInstance();
    void run();

private:
    static RayTest instance;

    void testTrace();

};

#endif