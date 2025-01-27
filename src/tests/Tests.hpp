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

    /**
     * Registers the given testsuite for testing.
     * ATTENTION: The test suites should always be added from low-level to
     * high-level. I.e. the tests for low-level functionnality should always be
     * added before tests for high-level functions using these low-level
     * components are registered. This ensures, that a mistake is found as soon
     * as possible.
     */
    void registerTests(TestSuite* testSuite);
    void runAll();

private:
    static const uint32_t kMaxTestSuites = 256;
    TestSuite* testSuites[kMaxTestSuites];
    uint32_t numTestSuites = 0;

};

#endif