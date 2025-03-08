# raylib-asteroids

## Overview
This project is a simple game inspired by the classic Asteroids game, build in raylib.

## Project Structure
The project is organized into several directories and files:

- **src/**: Contains the source code for the game.
  - **main.cpp**: Entry point of the game.
  - **game.cpp**: Implements the Game class for managing game state and logic.
  - **game.h**: Header file for the Game class.
  - **player.cpp**: Implements the Player class for handling player actions.
  - **player.h**: Header file for the Player class.
  - **asteroid.cpp**: Implements the Asteroid class for managing asteroids.
  - **asteroid.h**: Header file for the Asteroid class.
  - **bullet.cpp**: Implements the Bullet class for managing bullets.
  - **bullet.h**: Header file for the Bullet class.
  - **collision.cpp**: Contains collision detection functions.
  - **collision.h**: Header file for collision detection functions.
  - **utils.h**: Contains utility functions and constants.

- **assets/**: Contains game assets such as sounds.
  - **sounds/**: Directory for sound files.

- **lib/**: Contains the raylib library files.

- **CMakeLists.txt**: Configuration file for CMake.

- **Makefile**: Build instructions for compiling the project.

## Setup Instructions
1. Ensure you have the raylib library installed on your system.
2. Clone this repository or download the project files.
3. Navigate to the project directory in your terminal.
4. Use CMake or Makefile to build the project:
   - To build using CMake:
     ```
     mkdir build
     cd build
     cmake ..
     make
     ```
   - To build using Makefile:
     ```
     make
     ```

## Gameplay
In this game, you control a spaceship that can move and shoot bullets to destroy incoming asteroids. The objective is to survive as long as possible while scoring points by destroying asteroids. 

## Controls
- Use arrow keys or WASD to move the spaceship.
- Press the spacebar to shoot bullets.

## Acknowledgments
This project is built using the raylib library, which provides a simple and easy-to-use interface for game development.
