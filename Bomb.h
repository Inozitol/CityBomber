//
// Created by Gandalf on 27/Jan/18.
//

#ifndef CITYBOMBER_BOMB_H
#define CITYBOMBER_BOMB_H


#include "include.h"

class Bomb {
public:
    Bomb();
    void startPosition(float, float);
    sf::Sprite getSprite();
    void setSpriteTexture(sf::Texture&);
    void setTextureRect(bool);
    void decreaseHight();
    void update();

private:
    float _fallSpeed;
    sf::Vector2f _position;
    sf::RectangleShape _rectangle;
    sf::Sprite _sprite;
    bool _direcSpritePos=false;
};


#endif //CITYBOMBER_BOMB_H
