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
    static bool collision(sf::FloatRect, std::vector<Building>&, std::vector<Building>::iterator&);
    sf::FloatRect getRect();

private:
    sf::Sprite _sprite;
    sf::RectangleShape _rectangle;
    static constexpr float _SCALE = 4.0125391849;
};


#endif //CITYBOMBER_BUILDING_H
