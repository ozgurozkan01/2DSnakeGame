//
// Created by ozgur on 11/26/2021.
//

#ifndef INC_2DSNAKEGAME_SNAKE_PART_H
#define INC_2DSNAKEGAME_SNAKE_PART_H
#include "SFML/Graphics.hpp"

class Snake_Part {
public:
    sf::RectangleShape shape;

    Snake_Part()
    {
        InitShape();
    }

    void InitShape();
};


#endif //INC_2DSNAKEGAME_SNAKE_PART_H
