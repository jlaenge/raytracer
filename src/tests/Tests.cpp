#include <Tests.hpp>

Tests::Tests() {
    for(uint32_t i=0; i<kMaxTestSuites; i++) {
        testSuites[i] = nullptr;
    }
}

void Tests::registerTests(TestSuite* testSuite) {
    assert(numTestSuites < kMaxTestSuites);
    assert(testSuite != nullptr);
    testSuites[numTestSuites] = testSuite;
    numTestSuites++;
}

void Tests::runAll() {
    for(uint32_t i=0; i<numTestSuites; i++) {
        testSuites[i]->run();
    }
}