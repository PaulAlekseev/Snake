#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>


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
};



class Fruit
{
    public:
    int posX;
    int posY;
    int SnakepositionX;
    int SnakepositionY;
    int SnakepositionX2;
    int SnakepositionY2;

    Fruit(int posX, int posY, int SnakepositionX, int SnakepositionY)
    {
        this -> posX = posX;
        this -> posY = posY;
        this -> SnakepositionX = SnakepositionX;
        this -> SnakepositionY = SnakepositionY;
    }

    Fruit(int posX, int posY, int SnakepositionX, int SnakepositionY, int SnakepositionX2, int SnakepositionY2)
    {
        this -> posX = posX;
        this -> posY = posY;
        this -> SnakepositionX = SnakepositionX;
        this -> SnakepositionY = SnakepositionY;
        this -> SnakepositionX2 = SnakepositionX2;
        this -> SnakepositionY2 = SnakepositionY2;
    }

    void gotEaten()
    {
            if ((this -> SnakepositionX == this -> posX) && (this -> SnakepositionY == this -> posY))
        {
            cout << "goteaten";
        }
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
