#include "GameState.h"

void GameState::initSnake()
{
    this->snake = new Snake(30, 3, 3, 3, this->window);
}

void GameState::initFruit()
{
    this->fruit = new Fruit(3, 3, this->window);
}

void GameState::initClock()
{
    this->clock = new sf::Clock();
}


GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initSnake();
    this->initFruit();
    this->initClock();
    this->direction = this->snake->getDirection();
    this->window->setFramerateLimit(60);
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
        this->snake->bitHimself();
        if (fruit->gotEaten(this->snake->getHeadX(), this->snake->getHeadY()))
        {
            fruit->changePosition();
            this->snake->growth();
        }
        this->snake->changeDirection(direction);
        this->snake->step();
        this->clock->restart();
    }
}

void GameState::render()
{
    this->fruit->drawFruit("Textures/fruit.png");
    this->snake->drawSnake("Textures/body1.png");
}

