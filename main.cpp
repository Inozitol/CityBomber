#include "Plane.h"
#include "Bomb.h"

sf::Clock globClock;
sf::Time globTime;

class const_iterator;

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
    std::vector<Bomb>::const_iterator iter;
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
        int bombArrCounter = 0;
        for(iter = bombArray.begin(); iter != bombArray.end(); iter++){
            window.draw(bombArray[bombArrCounter].getSprite());
            bombArray[bombArrCounter].decreaseHight();
            bombArray[bombArrCounter].update();
            bombArrCounter++;
        }
        window.draw(plane.getSprite());
        window.display();
    }
}