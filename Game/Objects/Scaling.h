#ifndef SCALING_H
#define SCALING_H

#pragma once

#include <SFML/Graphics.hpp>

class Scaling
{
private:

    sf::RenderWindow* window;
    float gridSizeX;
    float gridSizeY;
    float gridScaleX;
    float gridScaleY;
    sf::Vector2f scaleVector;
    float centerX;
    float centerY;

public:
    Scaling(sf::RenderWindow* window);
    ~Scaling();

    const sf::Vector2f& getScaleVector();
    const float& getGridSizeX();
    const float& getGridSizeY();
    const float& getCenterX();
    const float& getCenterY();
};

#endif