#include "bullet.h"
#include "constants.h"

Bullet::Bullet(Vector2 position, Vector2 direction, float speed)
    : position(position), direction(direction), speed(speed), active(true) {
}

void Bullet::update() {
    if (active) {
        position.x += direction.x * speed;
        position.y += direction.y * speed;
        
        if (isOffScreen()) {
            active = false;
        }
    }
}

void Bullet::draw() {
    if (active) {
        DrawCircleV(position, 5, RED);
    }
}

bool Bullet::isOffScreen() const {
    return (position.x < 0 || position.x > SCREEN_WIDTH || 
            position.y < 0 || position.y > SCREEN_HEIGHT);
}