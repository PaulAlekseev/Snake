#ifndef SCALING_H
#define SCALING_H

#pragma once

#include <SFML/Graphics.hpp>

class Scaling
{
private:

    sf::RenderWindow* window;
    double gridSizeX;
    double gridSizeY;
    double gridScaleX;
    double gridScaleY;
    sf::Vector2f scaleVector;
    double centerX;
    double centerY;

public:
    Scaling(sf::RenderWindow* window);
    ~Scaling();

    const sf::Vector2f& getScaleVector();
    const double& getGridSizeX();
    const double& getGridSizeY();
    const double& getCenterX();
    const double& getCenterY();
};

#endif