#ifndef PORTABLE_PIXELMAP_TEST
#define PORTABLE_PIXELMAP_TEST

#include <TestSuite.hpp>

class PortablePixelmapTest : public TestSuite {

public:
    static PortablePixelmapTest* getInstance();
    void run();

private:
    static PortablePixelmapTest instance;

};

#endif