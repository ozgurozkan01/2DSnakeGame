
#include "Bait.h"

void Bait::InitShape()
{
    shape.setSize(sf::Vector2f(25.f, 25.f));
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::White);
}

void Bait::AssingRandomPosition()
{
    random_x_bait = (rand() % 35) * 25;
    random_y_bait = (rand() % 17) * 25;
}

void Bait::BaitPosition()
{
    shape.setPosition(sf::Vector2f(random_x_bait, random_y_bait));
}





