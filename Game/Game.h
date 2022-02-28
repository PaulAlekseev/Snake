#include <SFML/Graphics.hpp>


class Game
{
    private:

        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;

        void initWindow()
        {
            this->videoMode.width = 800;
            this->videoMode.height = 600;
            this->window = new sf::RenderWindow (this->videoMode, "Snake game", sf::Style::Fullscreen);
        }
    public:
        Game()
        {
            this->initWindow();
        }
        
        const bool isRunning()
        {
            return this->window->isOpen();
        }   

        void pollEvent()
        {
        while(this->window->pollEvent(this->event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                this->window->close();
            }

            //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction = 1; 
            //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction = 2;
            //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction = 3;
            //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction = 4;

            // }
        }
        }
        
        void update()
        {
            this->pollEvent();
        }

        void render()
        {
            this->window->clear();



            this->window->display();
        }        

};