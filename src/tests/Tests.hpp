/******************************************************************************\
 * 
 * TESTS
 * 
 * The Tests class bundles all tests of the project. They can be registered via
 * the registerTests() method and then run via runAll(). In case of a test
 * failure an assertion violation is raised.
 * 
 * Note: The number of tests is limited via the kMaxTestSuites parameter. In
 * case this limit is surpassed, the parameter needs to be updated.
 * 
\******************************************************************************/

#ifndef TESTS
#define TESTS

#include <TestSuite.hpp>

#include <cstdint>

class Tests {

public:
    Tests();

    void registerTests(TestSuite* testSuite);
    void runAll();

private:
    static const uint32_t kMaxTestSuites = 256;
    TestSuite* testSuites[kMaxTestSuites];
    uint32_t numTestSuites = 0;

};

#endif