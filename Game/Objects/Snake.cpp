#include "Snake.h"


void Snake::initScale()
{
    this->scale = new Scaling(this->window);
}
void Snake::initBody()
{
    for (int index = this->length; index > -1; index--)
    {
        this->bodyX[index] = -1;
        this->bodyY[index] = -1;
    }
}

Snake::Snake(int length, int direction, int headX, int headY, sf::RenderWindow* window)
{
    this -> length = length;
    this -> direction = direction;
    this -> headX = headX;
    this -> headY = headY;
    this -> window = window;
    
    this -> initScale();
    this->initBody();

}

Snake::~Snake()
{
    delete this->scale;
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
    if (this->headX > 59)
    {
        this->headX = 0;
    }
    else if (this->headX < 0)
    {
        this->headX = 59;
    }
    else if (this->headY > 33)
    {
        this->headY = 0;
    }
    else if (this->headY < 0)
    {
        this->headY = 33;
    }
}

void Snake::step()
{
    for (int index = this->length; index > -1; index--)
    {
        this->bodyX[index] = this->bodyX[index - 1];
        this->bodyY[index] = this->bodyY[index - 1];
    }
    
    switch (this -> direction)
    {
        case 1:
            this -> headY--;
            this->bodyY[0] = this -> headY + 1;
            this->bodyX[0] = this -> headX;
            this -> rotation = 0;
            break;
        case 2:
            this -> headX++;
            this->bodyX[0] = this -> headX - 1;
            this->bodyY[0] = this -> headY;
            this -> rotation = 90;
            break;
        case 3:
            this -> headY++;
            this->bodyY[0] = this -> headY - 1;
            this->bodyX[0] = this -> headX;
            this -> rotation = 180;
            break;
        case 4:
            this -> headX--;
            this->bodyX[0] = this -> headX + 1;
            this->bodyY[0] = this -> headY;
            this -> rotation = 270;
            break;
    }
    this->outOfView();
}



void Snake::drawSnake(std::string pathToTextures)
{
    this->snakeTexture.loadFromFile(pathToTextures);
    sf::Sprite snakeSprite(this->snakeTexture);
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
            this->length = i;
        }
    }
}

bool Snake::wasBittenBy(Snake* otherSnake)
{
    for (int i = 1; i < this->length; i++)
    {
        if (otherSnake->getHeadX() == this->bodyX[i] && otherSnake->getHeadY() == this->bodyY[i])
        {
            return true;
            break;
        }
    }
    return false;
}
