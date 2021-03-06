//
// Created by Air on 03.03.2021.
//
#include "Image.h"

#ifndef MAIN_ROOM_H
#define MAIN_ROOM_H

struct Room {

    void RoomMaker(char file_name);

    void Draw(Image &deststatic);

    std::pair<int, int> StartPos();

    char room_map[WINDOW_HEIGHT / tileSize][WINDOW_WIDTH / tileSize]{};

    bool checkSym(int coord_x, int coord_y, char c);

    float frame = 0;
};


#endif //MAIN_ROOM_H
