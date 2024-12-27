#ifndef PORTABLE_PIXELMAP
#define PORTABLE_PIXELMAP

#include <Image.hpp>

class PortablePixelmap {

public:
    static void store(Image* image);

private:
    const char* kFilename = "./image.ppm";

};

#endif