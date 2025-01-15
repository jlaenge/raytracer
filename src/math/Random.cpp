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

void Random::initialize() {
    //srand(time(NULL));
    srand(0x12345678);
}

float Random::getNext() {
    int ir = rand() % RAND_MAX;
    float fr = static_cast<float>(ir) / static_cast<float>(RAND_MAX);
    return fr;
}


Vector3 Random::randomInUnitSphere() const {
    Vector3 point;
    do {
        Vector3 randomPoint(Random::getInstance()->getNext(), Random::getInstance()->getNext(), Random::getInstance()->getNext());
        point = (2 * randomPoint) - Vector3(1, 1, 1);
    } while(point.length() * point.length() >= 1);
    return point;
}