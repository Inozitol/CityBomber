//
// Created by Gandalf on 16/Jan/18.
//

#ifndef CITYBOMBER_PLANE_H
#define CITYBOMBER_PLANE_H

#include "include.h"


class Plane {
public:
    Plane();
    sf::FloatRect getPosition();
    void lowerHeight();
    void dropBomb(){};
    void movePlane();
    sf::Sprite getSprite();
    void update();

private:
    sf::Vector2f _position;
    sf::RectangleShape _rectangle;
    sf::Sprite _sprite;
    int _ammo;
    sf::Clock _clock;
    sf::Time _time;
    int _heightCounter;
};


#endif //CITYBOMBER_PLANE_H
