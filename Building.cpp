//
// Created by Gandalf on 20/Mar/18.
//

#include "Building.h"

Building::Building(){
    _sprite.setScale(_SCALE,_SCALE);
    _rectangle.setScale(_SCALE,_SCALE);
}

sf::Sprite Building::getSprite() {
    return _sprite;
}

void Building::setSpriteTexture(sf::Texture &texture) {
    _sprite.setTexture(texture);
}

void Building::setPosition(sf::Vector2f position){
    _sprite.setPosition(position);
    _rectangle.setPosition(position);
}

void Building::builder(Building build, std::vector<Building> &buildArr, sf::Texture &buildingTexture) {
    //build.setPosition();
    srand(time(NULL));
    int buildNum;
    sf::Vector2f startPos;
    startPos.y = 780;
    for(int x=0;x<11;x++){
        if(x!=1 || x!=10) {
            startPos.x = (29 * _SCALE) * x;
            buildNum = rand() % 4 + 3;
            for (int y = 0; y < buildNum; y++) {
                startPos.y -= 20 * _SCALE;
                build.setPosition(startPos);
                build.setSpriteTexture(buildingTexture);
                buildArr.push_back(build);
            }
            startPos.y = 780;
        }
    }
}

sf::FloatRect Building::getRect() {
    return _sprite.getGlobalBounds();
}

bool Building::collision(sf::FloatRect bombRect, std::vector<Building> &buildArr, std::vector<Building>::iterator &iterBuilding) {
    int buildingArrCounter = 0;

    for(iterBuilding = buildArr.begin(); iterBuilding != buildArr.end();) {
        if (bombRect.intersects(buildArr[buildingArrCounter].getRect())){
            iterBuilding = buildArr.erase(iterBuilding);
            return true;
        }
        else {
            buildingArrCounter++;
            iterBuilding++;
        }
    }
}