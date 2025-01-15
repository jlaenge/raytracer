/******************************************************************************\
 * 
 * RANDOM
 * 
 * The Ramdom class implements the singleton pattern. It implements utility
 * functions for computing random values.
 * 
\******************************************************************************/

#ifndef RANDOM
#define RANDOM

#include <Vector3.hpp>

class Random {

public:
    static Random* getInstance();

    /**
     * Computes a random float in [0,1)
     */
    float getNext();

    /**
     * Computes a random vector on the unit sphere. This function is used for
     * diffuse materials, to compute the outgoing ray.
     */
    Vector3 randomInUnitSphere() const;

private:
    static bool isInitialized;
    static Random instance;

    static void initialize();

};

#endif