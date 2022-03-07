#include "Snake.h"


void Snake::initScale()
{
    this->scale = new Scaling(this->window);
}

Snake::Snake(int length, int direction, int headX, int headY, sf::RenderWindow* window)
{
    this -> length = length;
    this -> direction = direction;
    this -> headX = headX;
    this -> headY = headY;
    this -> window = window;
    
    this -> initScale();
}

Snake::~Snake()
{
    
}

const int& Snake::getDirection()
{
    return this->direction;
}

void Snake::changeDirection(int required)
{
    if (int (abs(this -> direction - required)) != 2)
    {
        this -> direction = required;
    }
}

void Snake::outOfView()
{
    if (this->headX > 60)
    {
        this->headX = 0;
    }
    else if (this->headX < 0)
    {
        this->headX = 60;
    }
    else if (this->headY > 34)
    {
        this->headY = 0;
    }
    else if (this->headY < 0)
    {
        this->headY = 34;
    }
}

void Snake::step()
{
    for (int index = this->length; index > -1; index--)
    {
        bodyX[index] = bodyX[index - 1];
        bodyY[index] = bodyY[index - 1];
    }
    
    switch (this -> direction)
    {
        case 1:
            this -> headY--;
            bodyY[0] = this -> headY + 1;
            bodyX[0] = this -> headX;
            this -> rotation = 0;
            break;
        case 2:
            this -> headX++;
            bodyX[0] = this -> headX - 1;
            bodyY[0] = this -> headY;
            this -> rotation = 90;
            break;
        case 3:
            this -> headY++;
            bodyY[0] = this -> headY - 1;
            bodyX[0] = this -> headX;
            this -> rotation = 180;
            break;
        case 4:
            this -> headX--;
            bodyX[0] = this -> headX + 1;
            bodyY[0] = this -> headY;
            this -> rotation = 270;
            break;
    }
    this->outOfView();
}



void Snake::drawSnake(std::string pathToTextures)
{
    snakeTexture.loadFromFile(pathToTextures);
    sf::Sprite snakeSprite(snakeTexture);
    snakeSprite.setScale(this->scale->getScaleVector());
    snakeSprite.setPosition(this->headX * this->scale->getGridSizeX(), this->headY * this->scale->getGridSizeY());
    this->window->draw(snakeSprite);

    for (int i = 0; i < this->length; i++)
    {
        snakeSprite.setPosition(this->bodyX[i]*this->scale->getGridSizeX(), this->bodyY[i]*this->scale->getGridSizeY());
        this->window->draw(snakeSprite);
    }
}

void Snake::growth()
{
    this->length++;
}

const int Snake::getHeadX()
{
    return this->headX;
}

const int Snake::getHeadY()
{
    return this->headY;
}

void Snake::bitHimself()
{
    for (int i = 1; i < this->length; i++)
    {
        if (this->headX == this->bodyX[i] && this->headY == this->bodyY[i])
        {
            this->length = i+1;
        }
    }
}