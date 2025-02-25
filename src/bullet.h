#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
public:
    Bullet(Vector2 position, Vector2 direction, float speed);
    void update();
    void draw();
    bool isOffScreen() const;
    Vector2 getPosition() const { return position; }
    bool isActive() const { return active; }

private:
    Vector2 position;
    Vector2 direction;
    float speed;
    bool active;
};

#endif // BULLET_H