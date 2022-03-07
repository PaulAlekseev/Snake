#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <math.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "WindowSettings.cpp"

class Snake
{
private:
    int length;
    int direction;
    int headX;
    int headY;
    int bodyX[100];
    int bodyY[100];  
    int rotation;

    sf::RenderWindow* window;
    sf::Texture snakeTexture;
    WindowSettings sets(this->window);

public:
    Snake(int length, int direction, int headX, int headY, sf::RenderWindow* window);
    ~Snake();

    void changeDirection(int required);
    void step();
    void draw(std::string pathToTextures);
    void growth();
    const int getHeadX();
    const int getHeadY();
    

};

#endif