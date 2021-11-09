//
// Created by ozgur on 10/16/2021.
//

#include "Game.h"
#include "iostream"

void Game::InitWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(900, 450), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

}

void Game::InitPositions()
{
    for(int i = 0; i<3; i++)
    {
        if(i==0)
        {
            SX[0]= XS;
            SY[0]= YS;
        }
        else if(i==1)
        {
            SX[1]= XS;
            SY[1]= YS;
        }

        else if(i==2)
        {
            SX[2]= SX[1]-25;
            SY[2]= YS;
        }
    }
}


Game::Game()
{
    this->InitWindow();
    this->InitPositions();
    this->CreateSnake();
}

Game::~Game()
{
    delete this->window;
}

bool const Game::IsOpen()
{
    return this->window->isOpen();
}

void Game::poolEvent()
{
    while(window->pollEvent(evnt)){
        switch (evnt.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(evnt.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                    break;
                }
        }
    }
}

void Game::CreateSnake()
{
    for(int i=0; i<100; i++)
    {
        snake[i] = new Snake;
    }
}

void Game::SnakePosition()
{
    for(int i = 0; i<3; i++)
    {
        snake[i]->shape.setPosition(SX[i],SY[i]);
    }
}
void Game::DrawSnake()
{
    for(int i = 0; i<3; i++)
    {
        this->window->draw(snake[i]->shape);
    }
}

void Game::SnakeMovement()
{
    if(movement)
    {
        c.restart();
        UpdatePosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            YS += 25;
            SY[0] = YS;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            XS -= 25;
            SX[0] = XS;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            XS += 25;
            SX[0] = XS;
            movement = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            YS -= 25;
            SY[0] = YS;
            movement = false;
        }
        movement = false;
    }

}

void Game::Delay()
{
    t = c.getElapsedTime();
    if(!movement)
    {
        if(operator>(t,sf::seconds(0.1)))
            movement = true;
    }
}

void Game::UpdatePosition()
{
    if(movement)
    {
        for(int i = 2; i>0; i--)
        {
            SX[i] = SX[i-1];
            SY[i] = SY[i-1];
        }
    }
}

void Game::CreateBait()
{
    bait[0] = new Bait;
}

void Game::BaitPosition()
{

    XB = (rand() % 30) * 25;
    YB = (rand() % 15) * 25;

    if(sizeof(bait))
    bait[0]->shape.setPosition(XB, YB);
}

void Game::DrawBait()
{
    this->window->draw(bait[0]->shape);
}

void Game::EatBait()
{
    if(SX[0] == XB && SY[0] == YB)
    {
        XB = (rand() % 30) * 25;
        YB = (rand() % 15) * 25;
    }
}


void Game::Update()
{
    this->poolEvent();
    this->SnakePosition();
    this->SnakeMovement();
    this->Delay();

    this->EatBait();

    this->CreateBait();
    this->BaitPosition();
}


void Game::Render()
{
    this->window->clear();
    this->DrawSnake();
    this->DrawBait();
    this->window->display();
}



