
#include "Bait.h"

void Bait::InitShape()
{
    shape.setSize(sf::Vector2f(25,25));
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::White);
}

void Bait::BaitPosition()
{
    x_bait= (rand() % 15) * 25;
    y_bait= (rand() % 30) * 25;

    shape.setPosition(sf::Vector2f(x_bait, y_bait));
}