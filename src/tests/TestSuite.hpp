/******************************************************************************\
 * 
 * TESTSUITE
 * 
 * The TestSuite interface is used for all tests. All classes that wish to
 * implement a test need to implement the abstract run() function. This function
 * has a return type of void. The implementation should fail an assertion in
 * case of a failing test.
 * 
\******************************************************************************/

#ifndef TEST_SUITE
#define TEST_SUITE

#include <cassert>

class TestSuite {

public:
    virtual void run() = 0;

    static void floatEqual(float a, float b) {
        assert(a-epsilon <= b && b <= a+epsilon);
    }

private:
    static constexpr float epsilon = 0.0001;

};

#endif