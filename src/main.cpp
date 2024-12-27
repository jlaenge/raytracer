#include <cstdio>
#include <cstdlib>

#include <PortablePixelmap.hpp>

void simpleImage1();
void simpleImage2();

int main() {

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
    PortablePixelmap ppm(3, 2);
    ppm.getData()[0]  = 255; ppm.getData()[1]  = 0;   ppm.getData()[2]  = 0;
    ppm.getData()[3]  = 0;   ppm.getData()[4]  = 255; ppm.getData()[5]  = 0;
    ppm.getData()[6]  = 255; ppm.getData()[7]  = 255; ppm.getData()[8]  = 0;
    ppm.getData()[9]  = 0;   ppm.getData()[10] = 0;   ppm.getData()[11] = 0;
    ppm.getData()[12] = 255; ppm.getData()[13] = 255; ppm.getData()[14] = 255;
    ppm.store();
}