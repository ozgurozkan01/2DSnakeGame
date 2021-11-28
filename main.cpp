#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"


int main()
{
    srand(time(NULL));
    Game game;

    while(game.IsOpen())
    {
        game.Update();

        game.Render();
    }

    return 0;
}
