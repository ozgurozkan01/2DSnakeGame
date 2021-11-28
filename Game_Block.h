//
// Created by ozgur on 11/26/2021.
//

#ifndef INC_2DSNAKEGAME_GAME_BLOCK_H
#define INC_2DSNAKEGAME_GAME_BLOCK_H
#include "SFML/Graphics.hpp"

class Game_Block {
public:

    sf::RectangleShape* shape;

    int verticalline = 18, horizonaline = 36;

    void InitBlock();

    Game_Block()
    {
        InitBlock();
    };

};


#endif //INC_2DSNAKEGAME_GAME_BLOCK_H
