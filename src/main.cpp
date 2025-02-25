#include "raylib.h"
#include "game.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib Asteroids");
    InitAudioDevice();  // Add this line before creating game objects

    Game game;
    game.init();

    SetTargetFPS(60); // Set the game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) {
        game.update();
        game.draw();
    }

    // Unload game resources
    game.unload();

    CloseAudioDevice();  // Add this line before closing
    CloseWindow(); // Close window and OpenGL context

    return 0;
}