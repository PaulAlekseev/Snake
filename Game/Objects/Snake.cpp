#include "Snake.h"

Snake::Snake(int length, int direction, int headX, int headY)
{
    {
        this -> length = length;
        this -> direction = direction;
        this -> headX = headX;
        this -> headY = headY;
    }
}

Snake::~Snake()
{

}

void Snake::changeDirection(int required)
{
    if (int (abs(this -> direction - required)) != 2)
    {
        this -> direction = required;
    }
}

void Snake::step()
{
    for (int index = length; index > -1; index--)
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
    return this->headX;
}