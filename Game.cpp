
#include "Game.h"
#include "iostream"

void Game::InitWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(900, 450), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}


void Game::CreateSnake()
{
    snake = new Snake();
}

void Game::CreateGameBlock()
{
    gameBlock = new Game_Block();
}

void Game::CreateBait()
{
    bait = new Bait();
}


Game::Game()
{
    this->InitWindow();
    this->CreateGameBlock();
    this->CreateBait();
    this->bait->AssingRandomPosition();
    this->CreateSnake();
    this->snake->InitPosition();
}

Game::~Game()
{
    delete this->window;
    delete this->gameBlock;
    delete this->bait;
    for(int i = 0; i<snake->init_size+1; i++)
    {
        delete this->snake->snakePart[i];
    }
}

bool const Game::IsOpen()
{
    return this->window->isOpen();
}

void Game::PoolEvent()
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

void Game::DrawBlocks()
{
    for(int i = 0; i < gameBlock->verticalline; i++)
    {
        for(int j = 0; j < gameBlock->horizonaline; j++)
        {
            gameBlock->shape.setPosition(sf::Vector2f( j * 25, i * 25));
            window->draw(gameBlock->shape);
        }
    }
}

void Game::DrawSnake()
{
    for(int i = 0; i< snake->init_size+1; i++)
    {
        this->window->draw(snake->snakePart[i]->shape);
    }
}

void Game::DrawBait()
{
    this->window->draw(bait->shape);
}


void Game::Update()
{
    this->PoolEvent();
    this->snake->Delay();

    this->bait->BaitPosition();

    this->snake->SnakePartPosition();
    this->snake->SnakeMovement();
    this->snake->UpdateBorderPosition();
    this->snake->EatBait(bait);
}

void Game::Render()
{
    this->window->clear();
    this->DrawBlocks();
    this->DrawBait();
    this->DrawSnake();
    this->window->display();

}



