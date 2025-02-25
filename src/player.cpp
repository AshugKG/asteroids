#include "player.h"
#include "constants.h"
#include <cmath>

Player::Player(Vector2 position) {
    this->position = position;
    this->rotation = 0.0f;
    this->speed = 200.0f;
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
    
    // Match direction with ship's facing direction
    Vector2 direction = {
        cosf(rotation * DEG2RAD),
        sinf(rotation * DEG2RAD)
    };
    
    // Create bullet at the tip of the ship
    Vector2 bulletPos = {
        position.x + 20.0f * cosf(rotation * DEG2RAD),
        position.y + 20.0f * sinf(rotation * DEG2RAD)
    };
    
    bullets.push_back(new Bullet(bulletPos, direction, bulletSpeed));
}

void Player::draw() {
    // Simpler ship drawing
    DrawTriangle(
        // Front tip of the ship
        (Vector2){ position.x + 20 * cosf(rotation * DEG2RAD), position.y + 20 * sinf(rotation * DEG2RAD) },
        // Left wing
        (Vector2){ position.x - 10 * cosf((rotation + 120) * DEG2RAD), position.y - 10 * sinf((rotation + 120) * DEG2RAD) },
        // Right wing
        (Vector2){ position.x - 10 * cosf((rotation - 120) * DEG2RAD), position.y - 10 * sinf((rotation - 120) * DEG2RAD) },
        WHITE
    );
    
    // Draw bullets
    for (auto bullet : bullets) {
        bullet->draw();
    }
}