#ifndef IMAGE
#define IMAGE

#include <cstdint>
#include <cstdlib>
#include <cstring>

class Image {

public:
    Image(uint32_t width, uint32_t height) : kWidth(width), kHeight(height) {
        uint32_t size = sizeof(float) * width * height * kColorDimension;
        data = reinterpret_cast<float*>(malloc(size));
        memset(data, 0, size);
    }
    virtual ~Image() {
        free(data);
        data = nullptr;
    }

    uint32_t getColorDimension() { return kColorDimension; }
    uint32_t getWidth() { return kWidth; }
    uint32_t getHeight() { return kHeight; }
    float* getData() { return data; }

private:
    const uint32_t kColorDimension = 3;
    const uint32_t kWidth;
    const uint32_t kHeight;
    float* data;

};

#endif