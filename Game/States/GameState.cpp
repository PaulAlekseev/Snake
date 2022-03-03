#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
    : State(window)
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
}   

void GameState::update()
{
    this->updateKeyBinds();
}

void GameState::render()
{

}

