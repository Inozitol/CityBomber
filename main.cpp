#include "Plane.h"
#include "include.h"

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



    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.setFramerateLimit(30);

        plane.update();
        plane.movePlane();

        window.clear();
        window.draw(backgroundSprite);
        window.draw(plane.getSprite());
        window.display();
    }
}