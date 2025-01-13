/******************************************************************************\
 * 
 * PORTABLEPIXELMAP
 * 
 * The PortablePixelmap is a static class which stores a given image as PPM.
 * The resulting image is output to stdout via the store() function.
 * 
\******************************************************************************/

#ifndef PORTABLE_PIXELMAP
#define PORTABLE_PIXELMAP

#include <Image.hpp>

class PortablePixelmap {

public:

    /**
     * Outputs the given image in the PPM format to stdout.
     */
    static void store(Image* image);

};

#endif