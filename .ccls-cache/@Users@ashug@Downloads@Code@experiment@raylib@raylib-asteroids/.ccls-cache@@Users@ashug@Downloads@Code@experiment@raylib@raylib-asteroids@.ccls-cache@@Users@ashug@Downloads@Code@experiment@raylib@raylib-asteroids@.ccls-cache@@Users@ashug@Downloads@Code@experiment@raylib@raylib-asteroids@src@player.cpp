// filepath: /raylib-asteroids/raylib-asteroids/src/player.cpp

#include "player.h"
#include "constants.h"
#include <cmath>

Player::Player(Vector2 position) : position(position), rotation(0.0f), speed(200.0f) {
}

void Player::move(float deltaTime) {
    if (IsKeyDown(KEY_LEFT))
        rotation -= 180.0f * deltaTime;
    if (IsKeyDown(KEY_RIGHT))
        rotation += 180.0f * deltaTime;
        
    if (IsKeyDown(KEY_UP)) {
        position.x += speed * deltaTime * cosf(rotation * DEG2RAD);
        position.y += speed * deltaTime * sinf(rotation * DEG2RAD);
    }
    
    // Wrap around screen edges
    if (position.x > SCREEN_WIDTH) position.x = 0;
    if (position.x < 0) position.x = SCREEN_WIDTH;
    if (position.y > SCREEN_HEIGHT) position.y = 0;
    if (position.y < 0) position.y = SCREEN_HEIGHT;
}

void Player::shoot() {
    float bulletSpeed = 500.0f;
    Vector2 direction = {
        cosf((rotation - 90) * DEG2RAD),  // Adjust angle for proper direction
        sinf((rotation - 90) * DEG2RAD)
    };
    
    Vector2 bulletPos = {
        position.x + 30.0f * cosf((rotation - 90) * DEG2RAD),
        position.y + 30.0f * sinf((rotation - 90) * DEG2RAD)
    };
    
    bullets.push_back(new Bullet(bulletPos, direction, bulletSpeed));
}

void Player::draw() {
    // Draw triangular ship
    DrawTriangle(
        Vector2{ position.x + 20 * cosf((rotation - 90) * DEG2RAD), position.y + 20 * sinf((rotation - 90) * DEG2RAD) },
        Vector2{ position.x + 20 * cosf((rotation + 90) * DEG2RAD), position.y + 20 * sinf((rotation + 90) * DEG2RAD) },
        Vector2{ position.x + 30 * cosf(rotation * DEG2RAD), position.y + 30 * sinf(rotation * DEG2RAD) },
        WHITE
    );
    
    // Draw bullets
    for (auto bullet : bullets) {
        bullet->draw();
    }
}