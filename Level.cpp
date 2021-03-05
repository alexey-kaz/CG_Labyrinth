//
// Created by Air on 04.03.2021.
//

#include "Level.h"

void Level::LevelMaker() {
    char currentChar = 0;
    std::fstream fileToRead;

    fileToRead.open("../resources/Level.txt", std::ios::in);
    fileToRead.get(currentChar);
    for (int currentCharString = 0; currentCharString < 10; currentCharString++) {
        int currentCharNumber = 0;
        while (currentChar != '\n') {
            level_map[currentCharNumber++][currentCharString] = currentChar;
            fileToRead.get(currentChar);
        }
        fileToRead.get(currentChar);
    }
    fileToRead.close();
}

std::pair<int, int> Level::EntrancePos() {
    int a, b;
    for (int i = 0; i < WINDOW_HEIGHT / tileSize; i++)
        for (int j = 0; j < WINDOW_WIDTH / tileSize; j++)
            if (level_map[i][j] == 'E')
                a = i, b = j;
    return std::make_pair(a, b);
}
