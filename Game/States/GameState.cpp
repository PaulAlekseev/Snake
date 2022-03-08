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

void GameState::initKeyBinds()
{
    this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initKeyBinds();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP")))) direction = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT")))) direction = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN")))) direction = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT")))) direction = 4;
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

