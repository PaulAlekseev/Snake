#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>


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
