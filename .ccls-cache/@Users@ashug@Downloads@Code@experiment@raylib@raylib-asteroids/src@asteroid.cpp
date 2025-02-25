#include "asteroid.h"
#include "constants.h"
#include <cmath>

Asteroid::Asteroid(Vector2 position, float radius) 
    : position(position), radius(radius), speed(100.0f), rotation(0.0f) {
    // Random rotation speed between -60 and 60 degrees per second
    rotationSpeed = GetRandomValue(-60, 60);
    generateShape();
    reset();
}

void Asteroid::generateShape() {
    // Number of vertices for asteroid (between 6 and 10)
    int numVertices = GetRandomValue(6, 10);
    vertices.clear();
    
    // Generate irregular polygon vertices
    for (int i = 0; i < numVertices; i++) {
        float angle = (float)i / numVertices * 2 * PI;
        // Vary the radius a bit for each vertex (80% to 120% of nominal radius)
        float vertexRadius = radius * (0.8f + 0.4f * (float)GetRandomValue(0, 100) / 100.0f);
        
        Vector2 vertex = {
            cosf(angle) * vertexRadius,
            sinf(angle) * vertexRadius
        };
        vertices.push_back(vertex);
    }
}

void Asteroid::update(float deltaTime) {
    // Move asteroid in its direction
    position.x += direction.x * speed * deltaTime;
    position.y += direction.y * speed * deltaTime;
    
    // Update rotation
    rotation += rotationSpeed * deltaTime;
    if (rotation > 360.0f) rotation -= 360.0f;
    if (rotation < 0.0f) rotation += 360.0f;
    
    // Wrap around screen edges
    if (position.x < -radius) position.x = SCREEN_WIDTH + radius;
    if (position.x > SCREEN_WIDTH + radius) position.x = -radius;
    if (position.y < -radius) position.y = SCREEN_HEIGHT + radius;
    if (position.y > SCREEN_HEIGHT + radius) position.y = -radius;
}

void Asteroid::draw() {
    // Draw the irregular asteroid shape
    int vertexCount = vertices.size();
    for (int i = 0; i < vertexCount; i++) {
        // Calculate rotated and positioned vertices
        float angle = rotation * DEG2RAD;
        
        Vector2 v1 = vertices[i];
        Vector2 v2 = vertices[(i + 1) % vertexCount];
        
        // Apply rotation
        Vector2 rotated1 = {
            v1.x * cosf(angle) - v1.y * sinf(angle),
            v1.x * sinf(angle) + v1.y * cosf(angle)
        };
        
        Vector2 rotated2 = {
            v2.x * cosf(angle) - v2.y * sinf(angle),
            v2.x * sinf(angle) + v2.y * cosf(angle)
        };
        
        // Add position offset
        rotated1.x += position.x;
        rotated1.y += position.y;
        rotated2.x += position.x;
        rotated2.y += position.y;
        
        // Draw line segment
        DrawLineV(rotated1, rotated2, WHITE);
    }
    
    // Draw a small dot at center for debugging (optional)
    // DrawCircle(position.x, position.y, 2, RED);
}

void Asteroid::reset() {
    // Choose a random side of the screen to spawn from
    int side = GetRandomValue(0, 3);
    
    switch (side) {
        case 0: // Top
            position.x = GetRandomValue(0, SCREEN_WIDTH);
            position.y = -radius;
            break;
        case 1: // Right
            position.x = SCREEN_WIDTH + radius;
            position.y = GetRandomValue(0, SCREEN_HEIGHT);
            break;
        case 2: // Bottom
            position.x = GetRandomValue(0, SCREEN_WIDTH);
            position.y = SCREEN_HEIGHT + radius;
            break;
        case 3: // Left
            position.x = -radius;
            position.y = GetRandomValue(0, SCREEN_HEIGHT);
            break;
    }
    
    // Calculate direction vector towards a random point on the screen
    float targetX = GetRandomValue(SCREEN_WIDTH / 4, SCREEN_WIDTH * 3 / 4);
    float targetY = GetRandomValue(SCREEN_HEIGHT / 4, SCREEN_HEIGHT * 3 / 4);
    
    float dx = targetX - position.x;
    float dy = targetY - position.y;
    float length = sqrtf(dx * dx + dy * dy);
    
    direction.x = dx / length;
    direction.y = dy / length;
    
    // Generate a new shape for this asteroid
    generateShape();
    
    // Reset rotation
    rotation = GetRandomValue(0, 360);
}