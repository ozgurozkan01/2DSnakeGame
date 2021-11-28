

#ifndef INC_2DSNAKEGAME_BAIT_H
#define INC_2DSNAKEGAME_BAIT_H
#include "SFML/Graphics.hpp"

class Bait {
public:
    sf::RectangleShape shape;

    int x_bait, y_bait;

    Bait()
    {
        InitShape();
    }


    void InitShape();
    void BaitPosition();

};


#endif //INC_2DSNAKEGAME_BAIT_H
