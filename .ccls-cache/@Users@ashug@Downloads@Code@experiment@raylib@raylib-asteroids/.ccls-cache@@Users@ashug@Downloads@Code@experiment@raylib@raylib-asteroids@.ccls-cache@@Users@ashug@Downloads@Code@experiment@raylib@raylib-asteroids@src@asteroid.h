#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"

class Asteroid {
public:
    Asteroid(Vector2 position, float radius);
    void update(float deltaTime);
    void draw();
    void reset();
    Vector2 getPosition() const { return position; }
    float getRadius() const { return radius; }

private:
    Vector2 position;
    float radius;
    float speed;
};

#endif // ASTEROID_H