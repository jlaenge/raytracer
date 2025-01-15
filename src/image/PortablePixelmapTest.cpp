#include <PortablePixelmapTest.hpp>

#include <Image.hpp>
#include <PortablePixelmap.hpp>

PortablePixelmapTest PortablePixelmapTest::instance;
PortablePixelmapTest* PortablePixelmapTest::getInstance() {
    return &instance;
}

void PortablePixelmapTest::run() {
    Image image(3, 2);
    image.getData()[0]  = 1; image.getData()[1]  = 0; image.getData()[2]  = 0;
    image.getData()[3]  = 0; image.getData()[4]  = 1; image.getData()[5]  = 0;
    image.getData()[6]  = 0; image.getData()[7]  = 0; image.getData()[8]  = 1;
    image.getData()[9]  = 1; image.getData()[10] = 1; image.getData()[11] = 0;
    image.getData()[12] = 1; image.getData()[13] = 1; image.getData()[14] = 1;
    image.getData()[15] = 0; image.getData()[16] = 0; image.getData()[17] = 0;
    PortablePixelmap::store(&image, stdout);
}