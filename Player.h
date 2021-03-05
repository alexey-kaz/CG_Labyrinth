#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include "Room.h"
#include "Level.h"

enum class MovementDir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Player {
    explicit Player(Point pos) {
        level.LevelMaker();
        level_pos = std::make_pair(level.EntrancePos().first, level.EntrancePos().second);
        room.RoomMaker('E');
        pos.x = room.StartPos().first * tileSize + 1;
        pos.y = WINDOW_HEIGHT - room.StartPos().second * tileSize - tileSize + 1;
        coords = pos;
        old_coords = coords;
    };

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

    void NextRoom(MovementDir dir);

    bool direction_lr = true;

    Room room{};

    Level level{};
private:
    Point coords{.x = 10, .y = 10};
    Point old_coords{.x = 10, .y = 10};
    Pixel color{.r = 255, .g = 0, .b = 255, .a = 255};
    int move_speed = 8;
    std::pair<int, int> level_pos;

};

#endif //MAIN_PLAYER_H
