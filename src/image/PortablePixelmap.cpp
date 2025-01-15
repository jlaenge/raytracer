#include <PortablePixelmap.hpp>

#include <cassert>

void PortablePixelmap::store(Image* image, FILE* destination) {
    int status = 0;

    status = fprintf(destination, "P3\n%u %u\n255\n", image->getWidth(), image->getHeight());
    assert(status != 0);

    float* data = image->getData();
    for(int j=0; j<image->getHeight(); j++) {
        for(int i=0; i<image->getWidth(); i++) {
            int index = image->getColorDimension() * (j * image->getWidth() + i);
            float fr = data[index + 0];
            float fg = data[index + 1];
            float fb = data[index + 2];
            uint8_t ir = static_cast<uint8_t>(255.99 * fr);
            uint8_t ig = static_cast<uint8_t>(255.99 * fg);
            uint8_t ib = static_cast<uint8_t>(255.99 * fb);
            fprintf(destination, "%d %d %d\n", ir, ig, ib);
        }
    }
}