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

    
    Snake(int length, int direction, int headX, int headY)
    {
        this -> length = length;
        this -> direction = direction;
        this -> headX = headX;
        this -> headY = headY;
    }

    void changedirection(int required)
    {
        if (int (abs(this -> direction-required)) != 2)
        {
            this -> direction = required;
        }
    }
    
    void step()
    {
        int bodyX[length];
        int bodyY[length];

        for (int index = length; index > 0; --index)
        {
            bodyX[index] = bodyX[index - 1];
            bodyY[index] = bodyY[index - 1];
        }

        switch (this -> direction)
        {
            case 1:
                this -> headY++;
                break;
            case 2:
                this -> headX++;
                break;
            case 3:
                this -> headY--;
                break;
            case 4:
                this -> headX--;
                break;
        }
    }
};

class WindowArea
{
    public:
        int resX;
        int resY;
        double scaleX;
        double scaleY;        

        WindowArea(int resX, int resY)
        {
            this -> resX = resX;
            this -> resY = resY;
            this -> scaleX = resX / 40;
            this -> scaleY = resY / 23;
        };
        
};
