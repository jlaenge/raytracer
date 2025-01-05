#ifndef IMAGE_TEST
#define IMAGE_TEST

#include <TestSuite.hpp>

class ImageTest : public TestSuite {

public:
    static ImageTest* getInstance();
    void run();

private:
    static ImageTest instance;

};

#endif