//
// Created by Gandalf on 27/Jan/18.
//

#include "Bomb.h"

void Bomb::startPosition(float startPosX, float startPosY) {
    _position.x = startPosX;
    _position.y = startPosY;
    _rectangle.setPosition(_position);
    _sprite.setPosition(_position);
}

sf::Sprite Bomb::getSprite() {
    return _sprite;
}

Bomb::Bomb(){
    _sprite.setScale(1.5,1.5);
    _rectangle.setScale(1.5,1.5);
    _fallSpeed=1;
}

void Bomb::setSpriteTexture(sf::Texture &texture) {
    //Plane texture
    _sprite.setTexture(texture);
    //
}

void Bomb::setTextureRect(bool direc) {
    if(direc==true){
        _sprite.setTextureRect(sf::IntRect(30, 0, -30, 15));
    }
    else{
        _sprite.setTextureRect(sf::IntRect(0, 0, 30, 15));
    }
}

void Bomb::decreaseHight() {
    _position.y += _fallSpeed;
    _fallSpeed += 0.25;
}

void Bomb::update() {
    _rectangle.setPosition(_position);
    _sprite.setPosition(_position);
}

sf::Vector2f Bomb::getPosition() {
    return _position;
}

sf::FloatRect Bomb::getRect() {
    return _sprite.getGlobalBounds();
}