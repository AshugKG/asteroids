#include "player.h"
#include "constants.h"
#include <cmath>

Player::Player(Vector2 position) {
    this->position = position;
    this->velocity = {0.0f, 0.0f};
    this->rotation = 0.0f;
    this->speed = 200.0f;         // Increased thrust power
    this->maxSpeed = 250.0f;      // Slightly higher max speed
    this->friction = 0.995f;      // Reduced friction for more space-like inertia
    this->thrusting = false;      // Add thruster state tracking
    
    // Try to load the sound effect with error handling
    const char* soundPath = "resources/laser.wav";
    if (FileExists(soundPath)) {
        this->shootSound = LoadSound(soundPath);
    }
}

Player::~Player() {
    // Clean up all bullets
    for (auto bullet : bullets) {
        delete bullet;
    }
    bullets.clear();
    
    // Unload sound
    UnloadSound(shootSound);
}

void Player::move(float deltaTime) {
    // Update rotation
    if (IsKeyDown(KEY_LEFT))
        rotation -= 240.0f * deltaTime; // Faster rotation for better control
    if (IsKeyDown(KEY_RIGHT))
        rotation += 240.0f * deltaTime;
    
    // Normalize rotation
    if (rotation > 360.0f) rotation -= 360.0f;
    if (rotation < 0.0f) rotation += 360.0f;
    
    // Track thrusting state for visual effects
    thrusting = IsKeyDown(KEY_UP);
        
    if (thrusting) {
        // Apply acceleration in the direction the ship is facing
        float accelerationX = speed * deltaTime * cosf(rotation * DEG2RAD);
        float accelerationY = speed * deltaTime * sinf(rotation * DEG2RAD);
        
        velocity.x += accelerationX;
        velocity.y += accelerationY;
    }
    
    // Calculate current speed
    float currentSpeed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
    
    // Cap the speed to maxSpeed
    if (currentSpeed > maxSpeed) {
        velocity.x = (velocity.x / currentSpeed) * maxSpeed;
        velocity.y = (velocity.y / currentSpeed) * maxSpeed;
    }
    
    // Apply friction to gradually reduce speed
    velocity.x *= friction;
    velocity.y *= friction;
    
    // Only stop completely if speed is extremely low (reduced from 5.0f to 0.5f)
    if (currentSpeed < 0.5f) {
        velocity.x = 0;
        velocity.y = 0;
    }
    
    // Update position based on velocity
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
    
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
    PlaySound(shootSound);
}

void Player::draw() {
    // Draw ship triangle
    DrawTriangle(
        (Vector2){ position.x + 20 * cosf(rotation * DEG2RAD), position.y + 20 * sinf(rotation * DEG2RAD) },
        (Vector2){ position.x - 10 * cosf((rotation + 120) * DEG2RAD), position.y - 10 * sinf((rotation + 120) * DEG2RAD) },
        (Vector2){ position.x - 10 * cosf((rotation - 120) * DEG2RAD), position.y - 10 * sinf((rotation - 120) * DEG2RAD) },
        WHITE
    );
    
    // Draw thruster flame when accelerating
    if (thrusting) {
        DrawTriangle(
            (Vector2){ position.x - 10 * cosf(rotation * DEG2RAD), position.y - 10 * sinf(rotation * DEG2RAD) },
            (Vector2){ position.x - 15 * cosf((rotation + 20) * DEG2RAD), position.y - 15 * sinf((rotation + 20) * DEG2RAD) },
            (Vector2){ position.x - 15 * cosf((rotation - 20) * DEG2RAD), position.y - 15 * sinf((rotation - 20) * DEG2RAD) },
            YELLOW
        );
        
    }
    
    // Draw bullets
    for (auto bullet : bullets) {
        bullet->draw();
    }
}