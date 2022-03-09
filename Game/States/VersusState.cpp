#include "VersusState.h"


void VersusState::initSnake()
{
    this->snake1 = new Snake (3, 3, 3, 3, this->window);
    this->snake2 = new Snake (3, 1 , 33, 23, this->window);
}

void VersusState::collision()
{
    if (this->snake1->getHeadX() == this->snake2->getHeadX() && this->snake1->getHeadY() == this->snake2->getHeadY())
    {
        this->QUIT();
    }
}

void VersusState::initFruit()
{
    this->fruit = new Fruit(3, 3, this->window);
}

void VersusState::initClock()
{
    this->clock = new sf::Clock();
}

VersusState::VersusState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initSnake();
    this->initFruit();
    this->initClock();
    this->direction1 = this->snake1->getDirection();
    this->direction2 = this->snake2->getDirection();
    this->window->setFramerateLimit(60);
}

VersusState::~VersusState()
{

}

void VersusState::updateKeyBinds()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->QUIT();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->direction1 = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->direction1 = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->direction1 = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->direction1 = 4;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->direction2 = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) this->direction2 = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->direction2 = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) this->direction2 = 4;
}

void VersusState::update()
{
    sf::Time elapsed = this->clock->getElapsedTime();
    this->updateKeyBinds();


    if(elapsed.asSeconds() > 0.1)
    {
        this->collision();
        this->snake1->bitHimself();
        this->snake2->bitHimself();
        if (fruit->gotEaten(this->snake1->getHeadX(), this->snake1->getHeadY()))
        {
            fruit->changePosition();
            this->snake1->growth();
        }
        if (fruit->gotEaten(this->snake2->getHeadX(), this->snake2->getHeadY()))
        {
            fruit->changePosition();
            this->snake2->growth();
        }
        this->snake1->changeDirection(direction1);
        this->snake2->changeDirection(direction2);
        this->snake1->step();
        this->snake2->step();
        this->clock->restart();
    }
}

void VersusState::render()
{
    this->fruit->drawFruit("Textures/fruit.png");
    this->snake1->drawSnake("Textures/body1.png");
    this->snake2->drawSnake("Textures/body2.png");
}