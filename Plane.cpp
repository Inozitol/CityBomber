//
// Created by Gandalf on 16/Jan/18.
//

#include "Plane.h"

Plane::Plane(){

    _position.x = 0;
    _position.y = 25;
    _heightCounter = 0;
    _rectangle.setScale(3.5,3.5);
    _sprite.setScale(3.5,3.5);
    _rectangle.setSize(sf::Vector2f(28,12));

    //Plane texture
    sf::Texture planeTexture;
    if(!planeTexture.loadFromFile("plane_spritesheet.png")){
        std::cout << "Error while loading texture file.";
    }
    _sprite.setTextureRect(sf::IntRect(0, 0, 28, 12));
    _sprite.setTexture(planeTexture);
    //
}

sf::FloatRect Plane::getPosition() {
    return _rectangle.getGlobalBounds();
}

void Plane::lowerHeight() {
    _position.y -= 10;
}

void Plane::movePlane() {
    if(_heightCounter % 2 == 0){
        _position.x += 1.8;
    }
    else{
        _position.x -= 1.8;
    }
}

sf::Sprite Plane::getSprite() {
    return _sprite;
}

void Plane::update() {
    _rectangle.setPosition(_position);
    _sprite.setPosition(_position);
}