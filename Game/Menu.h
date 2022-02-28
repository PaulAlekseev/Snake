#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Game.h"

class Menu
{

    private:

        sf::Text text;
        sf::Texture texture;
        sf::Font font;
        sf::RenderWindow window;
        int decision;

        void initMenu()
        {
            font.loadFromFile("../Font/Font.ttf");
            text.setFont(font);
            text.setCharacterSize(50);
            text.setStyle(sf::Text::Bold);
            text.setColor(sf::Color::White);
            text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);

            this->decision = 0;
        }
    
    public:

        Menu()
        {
            this->initMenu();
        }

        void update(sf::RenderWindow window, sf::Event event)
        {
            while(window.pollEvent(event))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if (this->decision == 0)
                    {
                        this->decision = 2;
                    }
                    else
                    {
                        this->decision--;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    if (this->decision == 2)
                    {
                        this->decision = 0;
                    }
                    else
                    {
                        this->decision++;
                    } 
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    switch(abs(this->decision%3))
                    {
                        case 0:
                            //Start a game
                            std::cout << "Start a game";
                        case 1:
                            //Start a Multiplayer game
                            std::cout << "Start a Multiplayer game";
                        case 2:
                            //Settings
                            std::cout << "Settings";
                    }
                } 
            }
        }
            
};