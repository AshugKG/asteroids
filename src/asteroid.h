#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"
#include <vector>

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
    Vector2 direction;
    float radius;
    float speed;
    float rotation;
    float rotationSpeed;
    std::vector<Vector2> vertices; // Store the shape vertices
    void generateShape(); // Create the irregular polygon shape
};

#endif // ASTEROID_H