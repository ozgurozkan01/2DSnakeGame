//
// Created by ozgur on 10/16/2021.
//

#include "Snake.h"


void Snake::InitShape()
{
    shape.setSize(sf::Vector2f(25,25));
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color::White);
}



