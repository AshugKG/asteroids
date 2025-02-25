#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <ctime>
#include "constants.h"

// Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Utility function to generate a random float between min and max
float RandomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

// Utility function to initialize random seed
void InitRandom() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

#endif // UTILS_H