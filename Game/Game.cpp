#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow (this->videoMode, "Snake game", sf::Style::Fullscreen);
        
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->states));

}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initStates();
}


Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    };
}

//Accessors
const bool Game::isRunning()
{
    return this->window->isOpen();
}

//Functions
void Game::poolEvent()
{
    while(this->window->pollEvent(this->event))
    {
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction = 1; 
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction = 2;
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction = 3;
        //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction = 4
        // }
    }
}

void Game::update()
{
    this->poolEvent();

    if (!this->states.empty())
    {
        this->states.top()->update();

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
        }
    }
    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}