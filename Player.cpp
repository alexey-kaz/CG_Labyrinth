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
        if ((coords.y + tileSize + 1 >= WINDOW_HEIGHT) ||
            (room.checkWall(coords.x / tileSize, (coords.y + tileSize + 1) / tileSize)))
            break;
      old_coords.y = coords.y;
      coords.y += move_dist;
      break;
      case MovementDir::DOWN:
          if ((coords.y - 1 <= 0) || (room.checkWall(coords.x / tileSize, (coords.y - 1) / tileSize))) break;
          old_coords.y = coords.y;
          coords.y -= move_dist;
          break;
      case MovementDir::LEFT:
          if ((coords.x - 1 <= 0) || (room.checkWall((coords.x - 1) / tileSize, coords.y / tileSize))) break;
          old_coords.x = coords.x;
          coords.x -= move_dist;
          break;
      case MovementDir::RIGHT:
          if ((coords.x + tileSize + 1 >= WINDOW_WIDTH) ||
              (room.checkWall((coords.x + tileSize - 1) / tileSize, coords.y / tileSize)))
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
    Image player("../resources/Rogue_R.png");
    if (coords.x > old_coords.x)
        direction_lr = true;
    else if (coords.x < old_coords.x)
        direction_lr = false;
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

//    drawImage(player, coords, back, tileSize);
}

