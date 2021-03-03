//
// Created by Air on 03.03.2021.
//
#include "Image.h"

#ifndef MAIN_ROOM_H
#define MAIN_ROOM_H

struct Room {

    void RoomMaker();

    void Draw(Image &deststatic);

    std::pair<int, int> StartPos();

    char room_map[WINDOW_HEIGHT / tileSize][WINDOW_WIDTH / tileSize];

    bool checkWall(int coord_x, int coord_y);
};


#endif //MAIN_ROOM_H
