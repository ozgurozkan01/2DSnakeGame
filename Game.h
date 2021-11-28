
#ifndef INC_2DSNAKEGAME_GAME_H
#define INC_2DSNAKEGAME_GAME_H
#include "SFML/Graphics.hpp"

class Bait;
class Snake;
class Game_Block;


#include "Bait.h"
#include "Snake.h"
#include "Game_Block.h"

class Game {
public:
    sf::RenderWindow * window;
    sf::Event evnt;

    Game_Block* gameBlock;

    //SNAKE
    Snake* snake;

    //BAIT
    Bait* bait;

public:

    Game();
    virtual ~Game();

    void InitWindow();
    void PoolEvent();
    bool const IsOpen();
    void DrawBlocks();
    void Update();
    void Render();
    void CreateGameBlock();


    //SNAKE
    void CreateSnake();
    void DrawSnake();

    // BAIT
    void CreateBait();
    void DrawBait();
};


#endif //INC_2DSNAKEGAME_GAME_H
