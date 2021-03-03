//
// Created by Air on 03.03.2021.
//

#include "Room.h"

void Room::RoomMaker() {
    char currentChar = 0;
    std::fstream fileToRead;

    fileToRead.open("../resources/E.txt", std::ios::in);
    fileToRead.get(currentChar);
    for (int currentCharString = 0; currentCharString < WINDOW_HEIGHT / tileSize; currentCharString++) {
        int currentCharNumber = 0;
        while (currentChar != '\n') {
            room_map[currentCharNumber++][currentCharString] = currentChar;
            fileToRead.get(currentChar);
        }
        fileToRead.get(currentChar);
    }
    fileToRead.close();
}

void Room::Draw(Image &dest) {

    for (int i = 0; i < WINDOW_HEIGHT / tileSize; ++i)
        for (int j = 0; j < WINDOW_WIDTH / tileSize; ++j) {
            if (room_map[i][j] == '#') {
                Image A("../resources/Wall.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == ' ') {
                Image A("../resources/Space.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'x') {
                Image A("../resources/X.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'Q') {
                Image A("../resources/Q.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'T') {
                Image A("../resources/Trap.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            }
        }
}

std::pair<int, int> Room::StartPos() {
    for (int i = 0; i < WINDOW_HEIGHT / tileSize; i++)
        for (int j = 0; j < WINDOW_WIDTH / tileSize; j++)
            if (room_map[i][j] == '@')
                return std::make_pair(i, j);
    return std::make_pair(WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2);
}

bool Room::checkWall(int coord_x, int coord_y) {
    return room_map[coord_x][coord_y] == '#';
}
