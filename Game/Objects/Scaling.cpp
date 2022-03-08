#include "Scaling.h"

Scaling::Scaling(sf::RenderWindow* window)
{
    this->window = window;
    this->gridSizeX = (this->window->getSize().x + .0) / 60;
    this->gridSizeY = (this->window->getSize().y + .0) / 34;
    this->gridScaleX = (this->gridSizeX + .0) / 32;
    this->gridScaleY = (this->gridSizeY + .0) / 32;
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

const double& Scaling::getGridSizeX()
{
    return this->gridSizeX;
}

const double& Scaling::getGridSizeY()
{
    return this->gridSizeY;
}

const double& Scaling::getCenterX()
{
    return centerX;
}

const double& Scaling::getCenterY()
{
    return centerY;
}