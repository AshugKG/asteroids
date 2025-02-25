#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "bullet.h"
#include <vector>

class Player {
public:
    Player(Vector2 position = {400, 300});
    ~Player();  // Add destructor for cleaning up resources
    void move(float deltaTime);
    void shoot();
    void draw();
    Vector2 getPosition() const { return position; }
    float getRotation() const { return rotation; }
    std::vector<Bullet*>& getBullets() { return bullets; }
    
private:
    Vector2 position;
    Vector2 velocity;
    float rotation;
    float speed;
    float maxSpeed;
    float friction;
    bool thrusting;
    Sound shootSound;  // Sound effect for shooting
    std::vector<Bullet*> bullets;
};

#endif // PLAYER_H