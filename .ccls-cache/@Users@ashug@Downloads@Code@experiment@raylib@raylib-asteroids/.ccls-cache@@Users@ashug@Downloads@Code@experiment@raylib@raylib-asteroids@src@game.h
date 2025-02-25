#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include <vector>

class Game {
public:
    Game() noexcept;
    void init();
    void update();
    void draw();
    void unload();

private:
    Player* player;
    std::vector<Asteroid*> asteroids;
    bool gameOver;
    int score;
};

#endif // GAME_H