#include "include.h"


int main(){

    Snake snake(10, 3, 12, 12);

    WindowArea area(1920, 1080);

    sf::RenderWindow window(sf::VideoMode(area.resolutionX, area.resolutionY), "Snake game");

    sf::Clock clock;

    
    while (window.isOpen())
    {

        sf::Time elapsed1 = clock.getElapsedTime();

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

        for (int i = 0; i < snake.length; i++)
        {
            sprite.setPosition(snake.bodyX[i]*area.gridScaleX, snake.bodyY[i]*area.gridScaleY);
            window.draw(sprite);
        }
        
        window.display();
        if(elapsed1.asSeconds() > 0.1)
        {
            snake.step();
            clock.restart();
        }
    }
}