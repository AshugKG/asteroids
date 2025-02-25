#include "asteroid.h"
#include "constants.h"
#include <cmath>

Asteroid::Asteroid(Vector2 position, float radius) 
    : position(position), radius(radius), speed(100.0f) {
    reset();
}

void Asteroid::update(float deltaTime) {
    // Move asteroid in its direction
    position.x += direction.x * speed * deltaTime;
    position.y += direction.y * speed * deltaTime;
    
    // Wrap around screen edges
    if (position.x < -radius) position.x = SCREEN_WIDTH + radius;
    if (position.x > SCREEN_WIDTH + radius) position.x = -radius;
    if (position.y < -radius) position.y = SCREEN_HEIGHT + radius;
    if (position.y > SCREEN_HEIGHT + radius) position.y = -radius;
}

void Asteroid::draw() {
    DrawCircle((int)position.x, (int)position.y, radius, WHITE);
}

void Asteroid::reset() {