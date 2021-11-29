

#ifndef INC_2DSNAKEGAME_SNAKE_H
#define INC_2DSNAKEGAME_SNAKE_H
#include "SFML/Graphics.hpp"

class Snake_Part;
class Bait;

#include "Snake_Part.h"
#include "Bait.h"

class Snake {
public:

    Snake_Part* snakePart[647];// 647 = (horizontalline * verticalline) - 1

    int x_snake_part[647];
    int y_snake_part[647];

    int init_size = 2;

    sf::Time t;
    sf::Clock c;
    bool movement;

    Snake()
    {
        CreateSnakeParts();
    }

  void CreateSnakeParts();
  void InitPosition();
  void SnakePartPosition();
  void SnakeMovement();
  void Delay();
  void UpdatePosition();
  void UpdateBorderPosition();
  void EatBait(Bait* bait);

};


#endif //INC_2DSNAKEGAME_SNAKE_H
