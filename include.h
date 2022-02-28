#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>


using namespace std;

class Snake 
{
    public:
    int length;
    int direction;
    int headX;
    int headY;
    int bodyX[100];
    int bodyY[100];  
    int rotation;

    Snake(int length, int direction, int headX, int headY)
    {
        this -> length = length;
        this -> direction = direction;
        this -> headX = headX;
        this -> headY = headY;
    }
   


    void changedirection(int required)
    {
        if (int (abs(this -> direction - required)) != 2)
        {
            this -> direction = required;
        }
    }


    void step()
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

    void growth()
    {
        this -> length = this -> length + 1;
    }
};


class WindowArea
{
    public:
    int resolutionX;
    int resolutionY;
    int gridScaleX;
    int gridScaleY;
    int amountX;
    int amountY;

    WindowArea(int amountX,int amountY)
    {
        this -> resolutionX = amountX * 32;
        this -> resolutionY = amountY * 32;
        this -> gridScaleX = 32;
        this -> gridScaleY = 32;
        this -> amountX = amountX;
        this -> amountY = amountY;
    }

};


class Fruit
{
    public:
    int posX;
    int posY;

    Fruit(int posX, int posY)
    {
        this -> posX = posY;
        this -> posY = posY;
    }

    bool gotEatenBy(Snake snake)
    {
        if ((snake.headX == this->posX) && (snake.headY == this->posY))
        {
            return true;
        }
        return false;
    }

    int gotEatenBy(Snake snake1, Snake snake2)
    {
        if ((snake1.headX == this -> posX) && (snake1.headY == this -> posY))
        {
            return 1;
        }
        if ((snake2.headX == this -> posX) && (snake2.headY == this -> posY))
        {
            return 2;
        }
        return 0;
    }

    void changePosition(int randomnumber, WindowArea windowArea)
    {
        srand(randomnumber % windowArea.amountY);
        this -> posX = randomnumber % windowArea.amountX;
        this -> posY = rand() % windowArea.amountY;
    }
};


class TextCounter
{
    public:
    string fontPath;
    int size;
    int visibility;
    int posX;
    int posY;

    TextCounter(string fontPath, int size)
    {
        this -> fontPath = fontPath;
        this -> size = size;
        this -> visibility = 5;
    }

    void appearing(int snakeHeadX, int snakeHeadY, int snakeDirection)
    {
        int visibility = 6;
        switch (snakeDirection)
        {
            case 1:
                this -> posX = snakeHeadX - 43;
                this -> posY = snakeHeadY - 3;
                break;
            case 2:
                this -> posX = snakeHeadX - 10;
                this -> posY = snakeHeadY - this -> size - 25;
                break;
            case 3:
                this -> posX = snakeHeadX - 43;
                this -> posY = snakeHeadY - 3;
                break;
            case 4:
                this -> posX = snakeHeadX - 3;
                this -> posY = snakeHeadY - 43;
                break;

        }
    }
};
