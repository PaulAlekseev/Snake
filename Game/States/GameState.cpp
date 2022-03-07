#include "GameState.h"

void GameState::initSnake()
{
    snake = new Snake(3, 3, 3, 3, this->window);
}

void GameState::initFruit()
{
    fruit = new Fruit(3, 3);
}

void GameState::initClock()
{
    clock = new sf::Clock();
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initSnake();
    this->initClock();
    this->direction = this->snake->getDirection();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction = 4;
}   

void GameState::update()
{
    sf::Time elapsed = this->clock->getElapsedTime();
    this->updateKeyBinds();
    if(elapsed.asSeconds() > 0.1)
    {
        this->snake->changeDirection(direction);
        this->snake->step();
        this->clock->restart();
    }
}

void GameState::render()
{
    this->snake->drawSnake("Textures/body1.png");
}

