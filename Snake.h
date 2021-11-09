//
// Created by ozgur on 10/16/2021.
//

#ifndef INC_2DSNAKEGAME_SNAKE_H
#define INC_2DSNAKEGAME_SNAKE_H
#include "SFML/Graphics.hpp"


class Snake {
public:
    sf::RectangleShape shape;

    void InitShape();

    Snake()
    {
        InitShape();
    }

};


#endif //INC_2DSNAKEGAME_SNAKE_H
