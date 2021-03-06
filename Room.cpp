//
// Created by Air on 03.03.2021.
//

#include "Room.h"
#include "Level.h"
#include "cmath"

void Room::RoomMaker(char file_name) {
    char currentChar = 0;
    std::fstream fileToRead;
    std::string file_path("./resources/");
    file_path += file_name;
    file_path.append(".txt");
    fileToRead.open(file_path, std::ios::in);
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
                Image A("./resources/Wall.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == ' ') {
                int fr = fmod(floor(frame), 4);
                Image A("./resources/tex_tile.png");
                std::string file = "./resources/Fire/Fire";
                file += std::to_string(fr) + ".png";
                Image B(file);
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
                drawImage(B, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'x') {
                Image A("./resources/X.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'Q') {
                int fr = fmod(floor(frame), 8);
                Image A("./resources/tex_tile.png");
                std::string file = "./resources/Q/Q";
                file += std::to_string(fr) + ".png";
                Image B(file);
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
                drawImage(B, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == 'T') {
                int fr = fmod(floor(frame), 8);
                std::string file = "./resources/Trap/Trap";
                file += std::to_string(fr) + ".png";
                Image A(file);
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (room_map[i][j] == '.' || room_map[i][j] == '@') {
                Image A("./resources/tex_tile.png");
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

bool Room::checkSym(int coord_x, int coord_y, char c) {
    switch (c) {
        case '#':
            return (room_map[coord_x / tileSize][(WINDOW_HEIGHT - 1 - coord_y) / tileSize] == '#' ||
                    room_map[(coord_x + tileSize - 2) / tileSize][(WINDOW_HEIGHT - 1 - coord_y) / tileSize] == '#' ||
                    room_map[coord_x / tileSize][(WINDOW_HEIGHT - coord_y - tileSize + 1) / tileSize] == '#' ||
                    room_map[(coord_x + tileSize - 2) / tileSize][(WINDOW_HEIGHT - coord_y - tileSize + 1) /
                                                                  tileSize] == '#');
        case 'x':
            return (room_map[coord_x / tileSize][(WINDOW_HEIGHT - coord_y - tileSize + 1) / tileSize] == 'x');
        case 'Q':
            return (room_map[coord_x / tileSize][(WINDOW_HEIGHT - coord_y - tileSize + 1) / tileSize] == 'Q');
        case 'T':
        case ' ':
            return (room_map[(coord_x + tileSize / 2 - 1) / tileSize][(WINDOW_HEIGHT - 1 - coord_y - tileSize / 2) /
                                                                      tileSize] == 'T' ||
                    room_map[(coord_x + tileSize / 2) / tileSize][(WINDOW_HEIGHT - 1 - coord_y - tileSize / 2) /
                                                                  tileSize] == 'T' ||
                    room_map[(coord_x + tileSize / 2 - 1) / tileSize][(WINDOW_HEIGHT - coord_y - tileSize / 2) /
                                                                      tileSize] == 'T' ||
                    room_map[(coord_x + tileSize / 2) / tileSize][(WINDOW_HEIGHT - coord_y - tileSize / 2) /
                                                                  tileSize] == 'T' ||
                    room_map[(coord_x + tileSize / 2 - 1) / tileSize][(WINDOW_HEIGHT - 1 - coord_y - tileSize / 2) /
                                                                      tileSize] == ' ' ||
                    room_map[(coord_x + tileSize / 2) / tileSize][(WINDOW_HEIGHT - 1 - coord_y - tileSize / 2) /
                                                                  tileSize] == ' ' ||
                    room_map[(coord_x + tileSize / 2 - 1) / tileSize][(WINDOW_HEIGHT - coord_y - tileSize / 2) /
                                                                      tileSize] == ' ' ||
                    room_map[(coord_x + tileSize / 2) / tileSize][(WINDOW_HEIGHT - coord_y - tileSize / 2) /
                                                                  tileSize] == ' ');
        default:
            return false;
    }
}
