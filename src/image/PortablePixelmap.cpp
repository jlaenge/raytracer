#include <PortablePixelmap.hpp>

#include <cassert>

uint8_t* PortablePixelmap::getData() {
    return data;
}

void PortablePixelmap::store() {
    int status = 0;

    status = printf("P3\n%u %u\n255\n", kWidth, kHeight);
    assert(status != 0);

    for(int j=0; j<kHeight; j++) {
        for(int i=0; i<kWidth; i++) {
            int index = kColorSize * (j * kWidth + i);
            uint8_t r = data[index + 0];
            uint8_t g = data[index + 1];
            uint8_t b = data[index + 2];
            printf("%d %d %d\n", r, g, b);
        }
    }
}