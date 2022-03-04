#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <math.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>

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
public:
    Snake(int length, int direction, int headX, int headY);
    ~Snake();

    void changeDirection(int required);
    void step();
    void growth();
    const int getHeadX();
    const int getHeadY();
    

};

#endif