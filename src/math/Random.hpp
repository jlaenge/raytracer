#ifndef RANDOM
#define RANDOM

class Random {

public:
    static Random* getInstance();

    float getNext();

private:
    static bool isInitialized;
    static Random instance;

    static void initialize();

};

#endif