
#include "Snake.h"

void Snake::InitPosition()
{
    x_snake_part[0] = 250;
    y_snake_part[0] = 250;

   for(int i = init_size; i>0; i--)
    {
        x_snake_part[i] = x_snake_part[i - 1] - 25;
        y_snake_part[i] = y_snake_part[i - 1];
    }
}

void Snake::CreateSnakeParts()
{
    for(int i = 0; i < 647; i++)
    {
        snakePart[i] = new Snake_Part();
    }
}

void Snake::SnakePartPosition()
{
    for(int i = 0; i<init_size+1; i++)
    {
        snakePart[i]->shape.setPosition(sf::Vector2f(x_snake_part[i], y_snake_part[i]));
    }
}

void Snake::SnakeMovement()
{
    if(movement)
    {
        c.restart();
        UpdatePosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            y_snake_part[0] += 25;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            x_snake_part[0] -= 25;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            x_snake_part[0] += 25;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            y_snake_part[0] -= 25;
            movement = false;
        }
    }
}

void Snake::Delay()
{
    t = c.getElapsedTime();

    if(!movement)
    {
        if(operator>(t,sf::seconds(0.01)))
        {
            movement = true;
        }
    }
}

void Snake::UpdatePosition()
{
    if(movement)
    {
        for(int i = init_size; i > 0; i--)
        {
            x_snake_part[i] = x_snake_part[i - 1];
            y_snake_part[i] = y_snake_part[i - 1];
        }
    }
}

void Snake::UpdateBorderPosition()
{
    if (x_snake_part[0] < 0) {
        x_snake_part[0] = 875;
    }

    if (x_snake_part[0] > 900) {
        x_snake_part[0] = 0;
    }

    if (y_snake_part[0] > 425) {
        y_snake_part[0] = 0;
    }

    if (y_snake_part[0] < 0) {
        y_snake_part[0] = 425;
    }
}

void Snake::EatBait(Bait* bait)
{
    if(bait->x_bait == x_snake_part[0] && bait->y_bait == y_snake_part[0])
    {
        init_size++;
        bait->x_bait = (rand() % 15) * 25;
        bait->y_bait = (rand() % 30) * 25;

        for(int i = 0; i < init_size+1; i++)
        {
            if(bait->x_bait == x_snake_part[i] && bait->y_bait == y_snake_part[i])
            {
                bait->x_bait = (rand() % 15) * 25;
                bait->y_bait = (rand() % 30) * 25;
            }
        }
    }
}