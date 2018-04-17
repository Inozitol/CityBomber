//
// Created by Gandalf on 16/Jan/18.
//

#ifndef CITYBOMBER_PLANE_H
#define CITYBOMBER_PLANE_H

#include "include.h"


class Plane {
public:
    Plane();
    sf::Vector2f getPosition();
    void movePlane();
    sf::Sprite getSprite();
    void update();
    void setSpriteTexture(sf::Texture&);
    void textureAnimation();
    bool planeDirec=false;
    int getAmmo();
    void decreAmmo();
    sf::FloatRect getRect();
    void textInit();
    sf::Text getText();

private:
    void _lowerHeight();
    sf::Vector2f _position;
    sf::RectangleShape _rectangle;
    sf::Sprite _sprite;
    int _ammo;
    sf::Clock _clock;
    sf::Time _time;
    int _animationCounter;
    bool _direction;
    sf::Text _textAmmo;
    sf::Font _font;
};


#endif //CITYBOMBER_PLANE_H
