

#ifndef INC_2DSNAKEGAME_BAIT_H
#define INC_2DSNAKEGAME_BAIT_H
#include "SFML/Graphics.hpp"

class Bait {
public:
    sf::RectangleShape shape;

    int random_x_bait, random_y_bait;

    Bait()
    {
        InitShape();
    }


    void InitShape();
    void AssingRandomPosition();
    void BaitPosition();
};


#endif //INC_2DSNAKEGAME_BAIT_H
