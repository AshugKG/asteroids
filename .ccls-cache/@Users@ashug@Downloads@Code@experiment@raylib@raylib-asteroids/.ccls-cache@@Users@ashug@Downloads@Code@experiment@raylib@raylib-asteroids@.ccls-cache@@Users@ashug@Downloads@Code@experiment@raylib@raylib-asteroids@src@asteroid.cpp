#include "asteroid.h"
#include "constants.h"
#include <cmath>

Asteroid::Asteroid(Vector2 position, float radius) 
    : position(position), radius(radius), speed(100.0f) {
    reset();
}

void Asteroid::update(float deltaTime) {
    position.y += speed * deltaTime;
    if (position.y > SCREEN_HEIGHT + radius) {
        reset();
    }
}

void Asteroid::draw() {
    DrawCircle((int)position.x, (int)position.y, radius, WHITE);
}

void Asteroid::reset() {
    position.x = GetRandomValue(0, SCREEN_WIDTH);
    position.y = -radius;
}