#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
    this->supportedKeys = supportedKeys;
    this->states = states;
    this->window = window;
    this->quit = false;
}

State::~State()
{
    
}

void State::QUIT()
{
    this->quit = true;
}

void State::endState()
{

}

const bool& State::getQuit()
{
    return this->quit;
}
