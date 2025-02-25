CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -I/opt/homebrew/include -Isrc
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = src/main.cpp src/game.cpp src/player.cpp src/asteroid.cpp src/bullet.cpp src/collision.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = raylib-asteroids

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)