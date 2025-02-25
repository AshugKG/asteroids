// filepath: /raylib-asteroids/raylib-asteroids/src/collision.cpp

#include "collision.h"
#include "bullet.h"
#include "asteroid.h"
#include "raymath.h"

bool checkCollision(const Bullet& bullet, const Asteroid& asteroid) {
    // Check if the bullet's position is within the asteroid's bounds
    const float bulletRadius = 5.0f; // Use the same radius as in bullet's draw function
    float asteroidRadius = asteroid.getRadius();
    Vector2 bulletPosition = bullet.getPosition();
    Vector2 asteroidPosition = asteroid.getPosition();

    // Using raylib's built-in collision check
    return CheckCollisionCircles(bulletPosition, bulletRadius, 
                               asteroidPosition, asteroidRadius);
}