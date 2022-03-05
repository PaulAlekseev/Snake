#include "NewState.h"

NewState::NewState(sf::RenderWindow* window)
    : State(window)
{

}

NewState::~NewState()
{

}

void NewState::endState()
{
    
}

void NewState::updateKeyBinds()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->QUIT();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Hello it's NewState" << std::endl;
    }
}   

void NewState::update()
{
    this->updateKeyBinds();
}

void NewState::render()
{

}

