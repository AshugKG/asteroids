#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "asteroid.h"
#include "bullet.h"

bool checkCollision(const Player& player, const Asteroid& asteroid);
bool checkCollision(const Bullet& bullet, const Asteroid& asteroid);

#endif // COLLISION_H