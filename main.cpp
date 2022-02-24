#include "include.h"


int main(){

    Snake snake(9, 3, 12, 12);

    Fruit fruit(15, 15);

    WindowArea area(40, 20);

    TextCounter textC ("Font/Font.ttf", 50);

    int direction = 3;

    srand(int (time(0)));

    sf::RenderWindow window(sf::VideoMode(area.resolutionX, area.resolutionY), "Snake game");

    sf::Clock clock;

    sf::Texture body, fruit1;
    body.loadFromFile("Textures/body1.png");
    fruit1.loadFromFile("Textures/fruit.png");

    sf::Sprite sprite(body);
    sf::Sprite fruitsprite(fruit1);

    sf::Font font;
    font.loadFromFile(textC.fontPath);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(textC.size);
    text.setStyle(sf::Text::Bold);

    
    while (window.isOpen())
    {

        sf::Time elapsed1 = clock.getElapsedTime();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            window.close();
        };

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction = 1; 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction = 2;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction = 3;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction = 4;

        }


        window.clear();
        fruitsprite.setPosition(fruit.posX*area.gridScaleX, fruit.posY*area.gridScaleY);
        window.draw(fruitsprite);

        sprite.setPosition(snake.headX*area.gridScaleX, snake.headY*area.gridScaleY);
        window.draw(sprite);
        window.draw(text);

        for (int i = 0; i < snake.length; i++)
        {
            sprite.setPosition(snake.bodyX[i]*area.gridScaleX, snake.bodyY[i]*area.gridScaleY);
            window.draw(sprite);
        }
        
        window.display();
        if(elapsed1.asSeconds() > 0.1)
        {

            if (fruit.gotEatenBy(snake))
            {
                snake.growth();
                fruit.changePosition(rand(), area);
                text.setString(to_string(snake.length));
            }
            snake.changedirection(direction);
            snake.step();
            clock.restart();
            textC.appearing(snake.headX, snake.headY, snake.direction);
            text.setPosition(snake.headX * area.gridScaleX + textC.posX, snake.headY * area.gridScaleY + textC.posY);
        }
    }
}