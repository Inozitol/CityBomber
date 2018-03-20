//
// Created by Gandalf on 16/Jan/18.
//

#include "Plane.h"

Plane::Plane(){

    _position.x = -125;
    _position.y = 25;
    _heightCounter = 0;
    _rectangle.setScale(4,4);
    _sprite.setScale(4,4);
    _rectangle.setSize(sf::Vector2f(29,12));
    _animationCounter = 0;
    _direction = true;
}

sf::Vector2f Plane::getPosition() {
    return _rectangle.getPosition();
}

void Plane::_lowerHeight() {
    _position.y += 35;
}

void Plane::movePlane() {
    if(_direction == true){
        _position.x += 3;
    }
    else{
        _position.x -= 3;
    }
}

sf::Sprite Plane::getSprite() {
    return _sprite;
}

void Plane::update() {
    _rectangle.setPosition(_position);
    _sprite.setPosition(_position);
}

void Plane::setSpriteTexture(sf::Texture &texture) {
    //Plane texture
    _sprite.setTexture(texture);
    _sprite.setTextureRect(sf::IntRect(0, 1, 29, 12));
    //
}

void Plane::textureAnimation() {
    _time = _clock.getElapsedTime();

    if(_direction) {
        _sprite.setTextureRect(sf::IntRect((_animationCounter * 29), 1, 29, 12));
    }
    else{
        _sprite.setTextureRect(sf::IntRect((_animationCounter * 29), 14, 29, 12));
    }

    if(_time.asMilliseconds() >= 100){
        _animationCounter++;
        if(_animationCounter >= 4){
            _animationCounter = 0;
        }
        _clock.restart();
    }
    if(_position.x > 1340){
        Plane::_lowerHeight();
        _position.x = 1300;
        _direction = false;
        planeDirec=true;
    }
    if(_position.x < -150){
        Plane::_lowerHeight();
        _position.x = -100;
        _direction = true;
        planeDirec=false;
    }
}