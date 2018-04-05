//Gandalf made...only god and I understand this, but not for long. Soon only god will understand this piece of sh*t
//I know..."Sooo easy piece of code, I could write this in my sleep". To those people I say only one thing: Please, stay in your evil lair full of disappointment

#include "Plane.h"
#include "Bomb.h"
#include "Building.h"
#include <cstdlib>

sf::Clock globClock;
sf::Time globTime;

class const_iterator;

int bombArrCounter;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 800), "CityBomber");
    Plane plane;

    //Sprite and Texture for background
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("pixel-landscape.jpg")){
        std::cout << "Error while loading texture file.";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    //

    //Plane texture
    sf::Texture planeTexture;
    if(!planeTexture.loadFromFile("plane_spritesheet.png")){
        std::cout << "Error while loading texture file.";
    }
    plane.setSpriteTexture(planeTexture);
    //

    //Bomb vector array
    std::vector<Bomb>::const_iterator iterBomb;
    std::vector<Bomb> bombArray;

    class Bomb bomb;
    //

    //Bomb Texture
    sf::Texture bombTexture;
    if(!bombTexture.loadFromFile("pixel_bomb.png")){
        std::cout << "Error while loading texture file.";
    }
    bomb.setSpriteTexture(bombTexture);
    //

    //Building vector array
    std::vector<Building>::const_iterator iterBuilding;
    std::vector<Building> buildingArray;

    class Building building;
    //

    sf::Texture buildingTexture;
    if(!buildingTexture.loadFromFile("building.png")){
        std::cout << "Error while loading texture file.";
    }

    building.builder(building, buildingArray, buildingTexture);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.setFramerateLimit(30);

        globTime = globClock.getElapsedTime();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && globTime.asSeconds() >= 1){
            bomb.startPosition(plane.getPosition().x + 40,plane.getPosition().y + 16);
            bomb.setTextureRect(plane.planeDirec);
            bombArray.push_back(bomb);
            globClock.restart();
        }
        plane.update();
        plane.movePlane();
        plane.textureAnimation();

        window.clear();
        window.draw(backgroundSprite);
        bombArrCounter = 0;
        for(iterBomb = bombArray.begin(); iterBomb != bombArray.end(); iterBomb++) {
            window.draw(bombArray[bombArrCounter].getSprite());
            bombArray[bombArrCounter].decreaseHight();
            if(bombArray[bombArrCounter].getPosition().y > 700){
                bombArray.erase(bombArray.begin()+(bombArrCounter-1));
            }
            bombArray[bombArrCounter].update();
            bombArrCounter++;
        }
        int buildingArrCounter = 0;
        for(iterBuilding = buildingArray.begin(); iterBuilding != buildingArray.end(); iterBuilding++) {
            window.draw(buildingArray[buildingArrCounter].getSprite());
            buildingArrCounter++;
        }
        window.draw(plane.getSprite());
        window.display();
    }
}