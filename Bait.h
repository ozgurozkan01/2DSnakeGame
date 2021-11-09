//
// Created by ozgur on 10/16/2021.
//

#ifndef INC_2DSNAKEGAME_BAIT_H
#define INC_2DSNAKEGAME_BAIT_H
#include "SFML/Graphics.hpp"

class Bait {
public:
    sf::RectangleShape shape;

public:

    void InitShape();

    Bait()
    {
        InitShape();
    }
};


#endif //INC_2DSNAKEGAME_BAIT_H
