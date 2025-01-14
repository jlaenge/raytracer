/******************************************************************************\
 * 
 * MAIN
 * 
 * The main logic is implemented in the Raytracer class. The main function in
 * this file only creates an instance of the Raytracer and invokes its render()
 * function.
 * 
\******************************************************************************/
#include <Tests.hpp>
#include <ImageTest.hpp>
#include <PortablePixelmapTest.hpp>
#include <RayTest.hpp>
#include <Vector3Test.hpp>

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
    rayTracer.render();

    return EXIT_SUCCESS;
}

/**
 * Simple testing function. As the images are output via stdout, only one test
 * can run at a given time and the program can only either test or run the
 * current scene.
 */
void test() {
    fprintf(stderr, "Testing...\n");

    fprintf(stderr, "\tRegistering tests...\n");
    Tests tests;
    //tests.registerTests(ImageTest::getInstance());
    //tests.registerTests(PortablePixelmapTest::getInstance());
    tests.registerTests(Vector3Test::getInstance());
    tests.registerTests(RayTest::getInstance());

    fprintf(stderr, "\tRunning tests...\n");
    tests.runAll();

    fprintf(stderr, "\tAll tests passed!\n");
}