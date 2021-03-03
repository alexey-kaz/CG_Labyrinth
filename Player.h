#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player {
    explicit Player(Point pos = {.x = 5, .y = 5}) :
            coords(pos), old_coords(coords) {};

    bool Moved() const;

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

    void MapMaker(Image &dest);

private:
    Point coords{.x = 10, .y = 10};
    Point old_coords{.x = 10, .y = 10};
    Pixel color{.r = 255, .g = 0, .b = 255, .a = 255};
    int move_speed = 8;
    char map[WINDOW_HEIGHT / tileSize][WINDOW_WIDTH / tileSize]{};

};

#endif //MAIN_PLAYER_H
