#include <ImageTest.hpp>

#include <cstdio>

ImageTest ImageTest::instance;
ImageTest* ImageTest::getInstance() {
    return &instance;
}

void ImageTest::run() {
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