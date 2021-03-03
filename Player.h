#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include "Room.h"

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player {
    explicit Player(Point pos) {
        room.RoomMaker();
        pos.x = room.StartPos().first * tileSize;
        pos.y = room.StartPos().second * tileSize;
        coords = pos;
        old_coords = coords;
    };

    bool Moved() const;

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

    bool direction_lr = true;

    Room room{};
private:
    Point coords{.x = 10, .y = 10};
    Point old_coords{.x = 10, .y = 10};
    Pixel color{.r = 255, .g = 0, .b = 255, .a = 255};
    int move_speed = 8;
    char level_map[WINDOW_HEIGHT / tileSize][WINDOW_WIDTH / tileSize]{};
};

#endif //MAIN_PLAYER_H
