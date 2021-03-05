//
// Created by Air on 04.03.2021.
//
#include "Image.h"

#ifndef MAIN_LEVEL_H
#define MAIN_LEVEL_H


struct Level {

    void LevelMaker();

    char level_map[10][10];

    std::pair<int, int> EntrancePos();
};


#endif //MAIN_LEVEL_H
