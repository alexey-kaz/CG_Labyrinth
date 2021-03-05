#include "Player.h"


void Player::ProcessInput(MovementDir dir) {
    int move_dist = move_speed * 1;
    switch (dir) {
        case MovementDir::UP:

            if ((WINDOW_HEIGHT - coords.y - tileSize - 1 >= WINDOW_HEIGHT) ||
                room.checkSym(coords.x / tileSize, (WINDOW_HEIGHT - coords.y - tileSize - 1) / tileSize, '#'))
                break;
            old_coords.y = coords.y;
            coords.y += move_dist;
            break;
        case MovementDir::DOWN:
            if ((WINDOW_HEIGHT - coords.y - 1 <= 0) ||
                room.checkSym(coords.x / tileSize, (WINDOW_HEIGHT - coords.y - 1) / tileSize, '#'))
                break;
            old_coords.y = coords.y;
            coords.y -= move_dist;
            break;
        case MovementDir::LEFT:
            if ((coords.x - 1 <= 0) ||
                room.checkSym((coords.x - 1) / tileSize, (WINDOW_HEIGHT - coords.y) / tileSize, '#'))
                break;
            old_coords.x = coords.x;
            coords.x -= move_dist;
            break;
        case MovementDir::RIGHT:
            if ((coords.x + tileSize + 1 >= WINDOW_WIDTH) ||
                room.checkSym((coords.x + tileSize + 1) / tileSize, (WINDOW_HEIGHT - coords.y) / tileSize, '#'))
                break;
            old_coords.x = coords.x;
            coords.x += move_dist;
            break;
        default:
            break;
    }
    if (room.checkSym(coords.x / tileSize, (WINDOW_HEIGHT - coords.y - tileSize + 1) / tileSize, 'x')
        && ((coords.y + tileSize >= WINDOW_HEIGHT) || (coords.x + tileSize >= WINDOW_WIDTH) ||
            (coords.x - 1 <= 0) || (coords.y - 1 <= 0)))
        NextRoom(dir);
}

void Player::Draw(Image &screen) {
    Image back("../resources/tex.png");
    Image player("../resources/Rogue_R.png");
    if (coords.x > old_coords.x)
        direction_lr = true;
    else if (coords.x < old_coords.x)
        direction_lr = false;
    for (int y = coords.y; y < coords.y - 1 + tileSize; ++y) {
        for (int x = coords.x; x < coords.x - 1 + tileSize; ++x) {
            if (direction_lr)
                screen.PutPixel(x, WINDOW_HEIGHT - y, BlendPixel(screen.GetPixel(x, WINDOW_HEIGHT - y),
                                                                 player.GetPixel(x - coords.x,
                                                                                 tileSize - y + coords.y - 1)));
            else {
                screen.PutPixel(x, WINDOW_HEIGHT - y, BlendPixel(screen.GetPixel(x, WINDOW_HEIGHT - y),
                                                                 player.GetPixel(tileSize - x + coords.x - 1,
                                                                                 tileSize - y + coords.y - 1)));
            }
        }
    }
}

void Player::NextRoom(MovementDir dir) {
    switch (dir) {
        case MovementDir::UP:
            if (coords.y + tileSize + 1 >= WINDOW_HEIGHT) {
                --level_pos.second;
                coords.y = 0;
            }
            break;
        case MovementDir::DOWN:
            if (coords.y - 1 <= 0) {
                ++level_pos.second;
                coords.y = WINDOW_HEIGHT - tileSize;
            }
            break;
        case MovementDir::LEFT:
            if (coords.x - 1 <= 0) {
                --level_pos.first;
                coords.x = WINDOW_WIDTH - tileSize;
            }
            break;
        case MovementDir::RIGHT:
            if (coords.x + tileSize + 1 >= WINDOW_WIDTH) {
                ++level_pos.first;
                coords.x = 0;
            }
            break;
    }
    char filename = level.level_map[level_pos.first][level_pos.second];
    room.RoomMaker(filename);
}

