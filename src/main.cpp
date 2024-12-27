#include <cstdio>
#include <cstdlib>

#include <Image.hpp>
#include <PortablePixelmap.hpp>
#include <Vector3.hpp>

void simpleImage1();
void simpleImage2();

int main() {

    Vector3 v(1, 2, 3);
    simpleImage2();

    return EXIT_SUCCESS;
}

void simpleImage() {
    int width = 200;
    int height = 100;
    printf("P3\n%d %d\n255\n", width, height);
    for(int j=0; j<height; j++) {
        for(int i=0; i<width; i++) {
            float r = float(i) / float(width);
            float g = float(j) / float(height);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            printf("%d %d %d\n", ir, ig, ib);
        }
    }
}
void simpleImage2() {
    Image image(3, 2);
    image.getData()[0]  = 255; image.getData()[1]  = 0;   image.getData()[2]  = 0;
    image.getData()[3]  = 0;   image.getData()[4]  = 255; image.getData()[5]  = 0;
    image.getData()[6]  = 255; image.getData()[7]  = 255; image.getData()[8]  = 0;
    image.getData()[9]  = 0;   image.getData()[10] = 0;   image.getData()[11] = 0;
    image.getData()[12] = 255; image.getData()[13] = 255; image.getData()[14] = 255;
    PortablePixelmap::store(&image);
}