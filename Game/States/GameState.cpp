#include "GameState.h"

void GameState::initSnake()
{
    Snake snake(3, 3, 12, 12);
}

void GameState::initFruit()
{
    Fruit fruit(300, 300);
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{

}

GameState::~GameState()
{
    
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

