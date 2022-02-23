#include <iostream>
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

    bool gotEaten(int SnakepositionX , int SnakepositionY)
    {
        if ((SnakepositionX == this->posX) && (SnakepositionY == this->posY))
        {
            return true;
        }
        return false;
    }

    int gotEaten(int SnakepositionX , int SnakepositionY, int SnakepositionX2, int SnakepositionY2)
    {
        if ((SnakepositionX == this -> posX) && (SnakepositionY == this -> posY))
        {
            return 1;
        }
        if ((SnakepositionX2 == this -> posX) && (SnakepositionY2 == this -> posY))
        {
            return 2;
        }
        return 0;
    }
};


class WindowArea
{
    public:
    float resolutionX;
    float resolutionY;
    float gridScaleX;
    float gridScaleY;

    WindowArea(float resolutionX,float resolutionY)
    {
        this -> resolutionX = resolutionX;
        this -> resolutionY = resolutionY;
        // spacing between each element of a grid
        this -> gridScaleX = resolutionX / 60;
        this -> gridScaleY = resolutionY / 34;
    }

};
