#include "bullet.h"
#include "constants.h"

Bullet::Bullet(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed), active(true) {
}

void Bullet::update() {
    if (active) {
        position.x += direction.x * speed * GetFrameTime();
        position.y += direction.y * speed * GetFrameTime();
    }
}

void Bullet::draw() {
    if (active) {
        // Use the same radius (5.0f) as in collision.cpp for consistency
        DrawCircleV(position, 5.0f, RED);
    }
}

bool Bullet::isOffScreen() const {
    return (position.x < 0 || position.x > SCREEN_WIDTH || 
            position.y < 0 || position.y > SCREEN_HEIGHT);
}