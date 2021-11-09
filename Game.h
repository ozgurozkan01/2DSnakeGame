//
// Created by ozgur on 10/16/2021.
//

#ifndef INC_2DSNAKEGAME_GAME_H
#define INC_2DSNAKEGAME_GAME_H
#include "SFML/Graphics.hpp"

class Bait;
class Snake;
class Tail;

#include "Bait.h"
#include "Snake.h"

class Game {
public:
    sf::RenderWindow * window;
    sf::Event evnt;

    sf::Clock c;
    sf::Time t;

    //SNAKE

    Snake* snake[100];
    bool movement = true;

    int max_bait = 1;

    int XS=250, YS=250;
    int XB, YB;

    int SX[100];
    int SY[100];


    //BAIT
    Bait* bait[1];

public:

    Game();
    virtual ~Game();

    void InitWindow();
    void InitPositions();
    void poolEvent();
    bool const IsOpen();
    void Update();
    void Render();
    void Delay();

    //SNAKE
    void CreateSnake();
    void SnakePosition();
    void DrawSnake();
    void SnakeMovement();
    void UpdatePosition();
    void EatBait();

    // BAIT
    void CreateBait();
    void DrawBait();
    void BaitPosition();
};


#endif //INC_2DSNAKEGAME_GAME_H
