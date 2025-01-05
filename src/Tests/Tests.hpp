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