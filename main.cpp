#include "include.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake game");
    
    while (window.isOpen())
    {

        while (window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
            }
        }

        window.clear();
        window.display();
    }
}