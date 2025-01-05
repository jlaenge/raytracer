#include <Tests.hpp>
#include <ImageTest.hpp>
#include <PortablePixelmapTest.hpp>

#include <Image.hpp>
#include <PortablePixelmap.hpp>
#include <Raytracer.hpp>
#include <Vector3.hpp>

#include <cstdio>
#include <cstdlib>

void test();

int main() {

    test();

    Raytracer rayTracer;
    //rayTracer.render();

    return EXIT_SUCCESS;
}

void test() {
    fprintf(stderr, "Testing...\n");

    fprintf(stderr, "\tRegistering tests...\n");
    Tests tests;
    //tests.registerTests(ImageTest::getInstance());
    //tests.registerTests(PortablePixelmapTest::getInstance());

    fprintf(stderr, "\tRunning tests...\n");
    tests.runAll();

    fprintf(stderr, "\tAll tests passed!\n");
}