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


void Game::initStates()
{
    this->states.push(new MenuState(this->window, &this->states));

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