project(raylib-asteroids)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

# Set the project name
project(RaylibAsteroids)

# Include raylib
include_directories(lib/raylib)

# Source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/asteroid.cpp
    src/bullet.cpp
    src/collision.cpp
)

# Create the executable
add_executable(RaylibAsteroids ${SOURCES})

# Link raylib
target_link_libraries(RaylibAsteroids raylib)