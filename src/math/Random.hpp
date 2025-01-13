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

class Random {

public:
    static Random* getInstance();

    /**
     * Computes a random float in [0,1)
     */
    float getNext();

private:
    static bool isInitialized;
    static Random instance;

    static void initialize();

};

#endif