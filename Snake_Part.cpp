//
// Created by ozgur on 11/26/2021.
//

#include "Snake_Part.h"

void Snake_Part::InitShape()
{
    shape.setSize(sf::Vector2f(25, 25));
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color::White);
}