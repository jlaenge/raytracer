#ifndef IMAGE
#define IMAGE

#include <cstdint>
#include <cstdlib>
#include <cstring>

class Image {

public:
    Image(uint32_t width, uint32_t height) : kWidth(width), kHeight(height) {
        uint32_t size = sizeof(uint8_t) * width * height * kColorDimension;
        data = reinterpret_cast<uint8_t*>(malloc(size));
        memset(data, 0, size);
    }
    virtual ~Image() {
        free(data);
        data = nullptr;
    }

    uint32_t getColorDimension() { return kColorDimension; }
    uint32_t getWidth() { return kWidth; }
    uint32_t getHeight() { return kHeight; }
    uint8_t* getData() { return data; }

private:
    const uint32_t kColorDimension = 3;
    const uint32_t kWidth;
    const uint32_t kHeight;
    uint8_t* data;

};

#endif