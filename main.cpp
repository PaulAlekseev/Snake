#include "include.h"


int main(){
    
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Snake game");
    
    while (window.isOpen())
    {

        sf::Texture texture;
        texture.loadFromFile("Textures/Facebook_icon.png");

        sf::Sprite sprite(texture);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            window.close();
        }
        }

        window.clear();

        sprite.setPosition(400,300);

        window.draw(sprite);
        
        window.display();
    }
}