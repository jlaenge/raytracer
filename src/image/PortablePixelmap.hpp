#ifndef PORTABLE_PIXELMAP
#define PORTABLE_PIXELMAP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class PortablePixelmap {

public:
    PortablePixelmap(uint32_t width, uint32_t height) : kWidth(width), kHeight(height) {
        uint32_t size = sizeof(uint8_t) * width * height * kColorSize;
        data = reinterpret_cast<uint8_t*>(malloc(size));
        memset(data, 0, size);
    }
    virtual ~PortablePixelmap() {
        free(data);
        data = nullptr;
    }
    uint8_t* getData();
    void store();

private:
    const char* kFilename = "./image.ppm";
    const uint32_t kColorSize = 3;

    const uint32_t kWidth;
    const uint32_t kHeight;
    uint8_t* data;

};

#endif