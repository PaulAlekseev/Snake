#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    
}

GameState::~GameState()
{
    std::cout << "Ending Gamestate!";
}

void GameState::endState()
{
    
}

void GameState::updateKeyBinds()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->QUIT();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        std::cout << "Hello from GameState" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->states->push(new MenuState(this->window, this->states));
    }
}   

void GameState::update()
{
    this->updateKeyBinds();
}

void GameState::render()
{

}

