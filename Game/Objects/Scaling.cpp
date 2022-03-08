#include "Scaling.h"

Scaling::Scaling(sf::RenderWindow* window)
{
    this->window = window;
    this->gridSizeX = this->window->getSize().x / 60;
    this->gridSizeY = this->window->getSize().y / 34;
    this->gridScaleX = this->gridSizeX / 32;
    this->gridScaleY = this->gridSizeY / 32;
    this->scaleVector = sf::Vector2f(this->gridScaleX, this->gridScaleY);
    this->centerX = this->window->getSize().x / 2;
    this->centerY = this->window->getSize().y / 2;
}

Scaling::~Scaling()
{

}

const sf::Vector2f& Scaling::getScaleVector()
{
    return this->scaleVector;
}

const float& Scaling::getGridSizeX()
{
    return this->gridSizeX;
}

const float& Scaling::getGridSizeY()
{
    return this->gridSizeY;
}

const float& Scaling::getCenterX()
{
    return centerX;
}

const float& Scaling::getCenterY()
{
    return centerY;
}