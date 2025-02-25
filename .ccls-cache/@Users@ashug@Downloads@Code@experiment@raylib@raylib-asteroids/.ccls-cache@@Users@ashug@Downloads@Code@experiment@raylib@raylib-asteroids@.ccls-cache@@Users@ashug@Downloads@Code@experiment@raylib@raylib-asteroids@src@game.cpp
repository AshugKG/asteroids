#include "game.h"
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include "collision.h"
#include "utils.h"
#include <cmath>

Game::Game() noexcept : player(nullptr), gameOver(false), score(0) {
}

void Game::init() {
    InitRandom();
    player = new Player({SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f});
    
    // Create initial asteroids
    for (int i = 0; i < 5; i++) {
        Vector2 pos = {
            RandomFloat(0, SCREEN_WIDTH),
            RandomFloat(-100, 0)
        };
        asteroids.push_back(new Asteroid(pos, 20.0f));
    }
}

void Game::update() {
    if (gameOver) return;

    // Update player
    player->move(GetFrameTime());
    
    if (IsKeyPressed(KEY_SPACE)) {
        player->shoot();
    }

    // Update asteroids
    for (auto asteroid : asteroids) {
        asteroid->update(GetFrameTime());
    }

    // Update bullets and check collisions
    auto& bullets = player->getBullets();
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end();) {
        Bullet* bullet = *bulletIt;
        bullet->update();
        
        bool collided = false;
        
        // Check for bullet-asteroid collisions
        for (auto asteroid : asteroids) {
            if (checkCollision(*bullet, *asteroid)) {
                // Handle collision
                score += 100;
                asteroid->reset();
                delete bullet;
                bulletIt = bullets.erase(bulletIt);
                collided = true;
                break;
            }
        }
        
        if (!collided) {
            if (bullet->isOffScreen()) {
                delete bullet;
                bulletIt = bullets.erase(bulletIt);
            } else {
                ++bulletIt;
            }
        }
    }

    // Check for player-asteroid collisions
    for (auto asteroid : asteroids) {
        if (CheckCollisionCircles(
            player->getPosition(), 10.0f,
            asteroid->getPosition(), asteroid->getRadius())) {
            gameOver = true;
            break;
        }
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    if (!gameOver) {
        player->draw();  // This already draws the bullets inside player
        
        for (auto asteroid : asteroids) {
            asteroid->draw();
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);
    } else {
        DrawText("Game Over!", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2, 40, WHITE);
        DrawText(TextFormat("Final Score: %d", score), 
                 SCREEN_WIDTH/2 - 80, SCREEN_HEIGHT/2 + 50, 20, WHITE);
    }

    EndDrawing();
}

void Game::unload() {
    delete player;  // Player's destructor should handle its bullets
    for (auto asteroid : asteroids) delete asteroid;
}