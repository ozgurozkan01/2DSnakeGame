//
// Created by ozgur on 10/16/2021.
//

#include "Bait.h"

void Bait::InitShape()
{
    this->shape.setSize(sf::Vector2f(25,25));
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(sf::Color::Red);
}


