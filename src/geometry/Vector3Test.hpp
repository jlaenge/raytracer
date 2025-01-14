#ifndef VECTOR3_TEST
#define VECTOR3_TEST

#include <TestSuite.hpp>

class Vector3Test : public TestSuite {

public:
    static Vector3Test* getInstance();
    void run();

private:
    static Vector3Test instance;

    void testAttributes();
    void testAssignment();
    void testOperatorAssignment();
    void testOperatorConstructor();
    void testLength();
    void testMakeUnit();
    void testOperatorRHS();
    void testDotAndCross();

};

#endif