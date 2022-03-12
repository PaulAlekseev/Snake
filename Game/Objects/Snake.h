#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <math.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Scaling.cpp"


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
    Scaling* scale;
    
    void initScale();
    void initBody();

public:
    Snake(int length, int direction, int headX, int headY, sf::RenderWindow* window);
    ~Snake();

    const int& getDirection();
    void changeDirection(int required);
    void outOfView();
    void step();
    void drawSnake(std::string pathToTextures);
    void growth();
    const int getHeadX();
    const int getHeadY();
    void bitHimself();
    bool wasBittenBy(Snake* snake);
    bool collision(Snake* othersnake);
};

#endif