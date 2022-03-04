#ifndef FRUIT_H
#define FRUIT_H

#pragma once

#include "Snake.cpp"

class Fruit
{
private:
    int posX;
    int posY;

public:
    Fruit(int posX, int posY);
    ~Fruit();

    const bool gotEatenBy(Snake snake);
    const int gotEatenBy (Snake snake, Snake snake2);
    void changePosition();
};

#endif