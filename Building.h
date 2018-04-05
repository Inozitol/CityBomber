//
// Created by Gandalf on 20/Mar/18.
//

#ifndef CITYBOMBER_BUILDING_H
#define CITYBOMBER_BUILDING_H


#include "include.h"

class Building {
public:
    Building();
    sf::Sprite getSprite();
    void setSpriteTexture(sf::Texture&);
    void setPosition(sf::Vector2f);
    static void builder(Building,std::vector<Building>&,sf::Texture&);

private:
    sf::Sprite _sprite;
    sf::RectangleShape _rectangle;
    static constexpr float _SCALE = 4.0125391849529780564263322884013;
};


#endif //CITYBOMBER_BUILDING_H
