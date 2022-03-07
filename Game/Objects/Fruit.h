#ifndef FRUIT_H
#define FRUIT_H

#pragma once

#include "Snake.cpp"

class Fruit
{
private:

    sf::RenderWindow* window;
    Scaling* scale;
    sf::Texture fruitTexture;

    void initScale();

public:
    int posX;
    int posY;
    Fruit(int posX, int posY, sf::RenderWindow* window);
    ~Fruit();

    const bool gotEaten(int snakePosX, int snakePosY);
    void changePosition();

    void drawFruit(std::string pathToTextures);
};

#endif