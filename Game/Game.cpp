#include "Game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow (this->videoMode, "Snake game", sf::Style::Fullscreen);
        
}

void Game::initKeys()
{
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);

    
}

void Game::initStates()
{
    this->states.push(new MenuState(this->window, &this->supportedKeys, &this->states));

}

//Constructors / Destructors
Game::Game()
{
    this->initVariables();
    this->initKeys();
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

void Game::update()
{

    if (!this->states.empty())
    {
        this->states.top()->update();

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
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