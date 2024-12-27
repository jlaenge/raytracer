#include <PortablePixelmap.hpp>

#include <cassert>
#include <cstdio>

void PortablePixelmap::store(Image* image) {
    int status = 0;

    status = printf("P3\n%u %u\n255\n", image->getWidth(), image->getHeight());
    assert(status != 0);

    for(int j=0; j<image->getHeight(); j++) {
        for(int i=0; i<image->getWidth(); i++) {
            int index = image->getColorDimension() * (j * image->getWidth() + i);
            uint8_t r = image->getData()[index + 0];
            uint8_t g = image->getData()[index + 1];
            uint8_t b = image->getData()[index + 2];
            printf("%d %d %d\n", r, g, b);
        }
    }
}