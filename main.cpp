#include "include.h"


int main(){

    Snake snake(10, 3, 12, 12);
    WindowArea area(1920, 1080);

    sf::RenderWindow window(sf::VideoMode(area.resX, area.resY), "Snake game");

    
    while (window.isOpen())
    {

        sf::Texture body;
        body.loadFromFile("Textures/body1.png");

        sf::Sprite sprite(body);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            window.close();
        };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))snake.changedirection(1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))snake.changedirection(2);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))snake.changedirection(3);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))snake.changedirection(4);
        }

        window.clear();

        snake.step();

        for (int i = 0; i < snake.length; i++)
        {
            sprite.setPosition(snake.bodyX[i], snake.bodyY[i]);
            window.draw(sprite);
        }

        
        window.display();
    }
}