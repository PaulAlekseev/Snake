#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>


using namespace std;

class Snake 
{
public:
    int length;
    int direction;
    int posX;
    int posY;
    
    Snake(int length, int direction, int posX, int posY)
    {
        this -> length = length;
        this -> direction = direction;
        this -> posX = posX;
        this -> posY = posY;
    }

    void changedirection(int required)
    {
        if (int (abs(this -> direction-required)) != 2)
        {
            this -> direction = required;
        }
    }
    
    void moving()
    {
        switch (this -> direction)
        {
            case 1:
                this -> posY++;
                break;
            case 2:
                this -> posX++;
                break;
            case 3:
                this -> posY--;
                break;
            case 4:
                this -> posX--;
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
