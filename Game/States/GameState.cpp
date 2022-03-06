#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    
    std::cout << "GameState opened" << std::endl;
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
}   

void GameState::update()
{
    this->updateKeyBinds();
}

void GameState::render()
{

}

