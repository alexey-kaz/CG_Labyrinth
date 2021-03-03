#include "Player.h"


bool Player::Moved() const
{
  if(coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}

void Player::ProcessInput(MovementDir dir)
{
  int move_dist = move_speed * 1;
  switch(dir)
  {
    case MovementDir::UP:
        if ((coords.y + tileSize + 1 > WINDOW_HEIGHT) ||
            (map[coords.x / tileSize][(coords.y + tileSize) / tileSize] == '#'))
            break;
      old_coords.y = coords.y;
      coords.y += move_dist;
      break;
      case MovementDir::DOWN:
          if ((coords.y - 1 < 0) || (map[coords.x / tileSize][(coords.y - 1) / tileSize] == '#')) break;
          old_coords.y = coords.y;
          coords.y -= move_dist;
          break;
      case MovementDir::LEFT:
          if ((coords.x - 1 < 0) || (map[(coords.x - 1) / tileSize][coords.y / tileSize] == '#')) break;
          old_coords.x = coords.x;
          coords.x -= move_dist;
          break;
      case MovementDir::RIGHT:
          if ((coords.x + tileSize + 1 > WINDOW_WIDTH) ||
              (map[(coords.x + tileSize) / tileSize + 1][coords.y / tileSize] == '#'))
              break;
          old_coords.x = coords.x;
          coords.x += move_dist;
          break;
      default:
          break;
  }
}

void Player::Draw(Image &screen) {
    Image back("../resources/tex.png");
    Image player("../resources/Rogue.png");
    if (Moved()) {
        for (int y = old_coords.y; y < old_coords.y - 1 + tileSize; ++y) {
            for (int x = old_coords.x; x < old_coords.x - 1 + tileSize; ++x) {
                screen.PutPixel(x, WINDOW_HEIGHT - y, back.GetPixel(x, WINDOW_HEIGHT - y));
            }
        }
        old_coords = coords;
    }
    for (int y = coords.y; y < coords.y - 1 + tileSize; ++y) {
        for (int x = coords.x; x < coords.x - 1 + tileSize; ++x) {
//      screen.PutPixel(x, WINDOW_HEIGHT-y, player.GetPixel(x-coords.x,tileSize-y+coords.y-1));
            screen.PutPixel(x, WINDOW_HEIGHT - y, BlendPixel(screen.GetPixel(x, WINDOW_HEIGHT - y),
                                                             player.GetPixel(x - coords.x,
                                                                             tileSize - y + coords.y - 1)));
        }
    }

//    drawImage(player, coords, back, tileSize);
}

void Player::MapMaker(Image &dest) {
    char currentChar = 0;
    std::fstream fileToRead;

    fileToRead.open("../resources/Level.txt", std::ios::in);
    fileToRead.get(currentChar);
    for (int currentCharString = 0; currentCharString < WINDOW_HEIGHT / tileSize; currentCharString++) {
        int currentCharNumber = 0;
        while (currentChar != '\n') {
            map[currentCharNumber++][currentCharString] = currentChar;
            fileToRead.get(currentChar);
        }
        fileToRead.get(currentChar);
    }
    fileToRead.close();
    for (int i = 0; i < WINDOW_HEIGHT / tileSize; ++i)
        for (int j = 0; j < WINDOW_WIDTH / tileSize; ++j) {
            if (map[i][j] == '#') {
                Image A("../resources/Wall.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (map[i][j] == ' ') {
                Image A("../resources/Space.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (map[i][j] == 'x') {
                Image A("../resources/X.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (map[i][j] == 'Q') {
                Image A("../resources/Q.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            } else if (map[i][j] == 'T') {
                Image A("../resources/Trap.png");
                drawImage(A, {i * tileSize, j * tileSize}, dest, tileSize);
            }
        }
}

