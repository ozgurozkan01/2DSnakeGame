//
// Created by ozgur on 11/26/2021.
//

#include "Game_Block.h"


void Game_Block::InitBlock()
{
    shape.setSize(sf::Vector2f(25.f, 25.f));
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Cyan);
}


