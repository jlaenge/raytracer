#include <Random.hpp>

#include <cstdlib>
#include <ctime>

bool Random::isInitialized = false;
Random Random::instance;

Random* Random::getInstance() {
    if(!isInitialized) {
        initialize();
        isInitialized = true;
    }
    return &instance;
}

float Random::getNext() {
    int ir = rand() % RAND_MAX;
    float fr = static_cast<float>(ir) / static_cast<float>(RAND_MAX);
    return fr;
}

void Random::initialize() {
    //srand(time(NULL));
    srand(0x12345678);
}