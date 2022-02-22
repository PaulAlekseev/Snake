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
                break;
            case 2:
                this -> headX++;
                bodyX[0] = this -> headX - 1;
                bodyY[0] = this -> headY;
                break;
            case 3:
                this -> headY++;
                bodyY[0] = this -> headY - 1;
                bodyX[0] = this -> headX;
                break;
            case 4:
                this -> headX--;
                bodyX[0] = this -> headX + 1;
                bodyY[0] = this -> headY;
                break;
        }

        for (int i = 0; i < length;i++)
        {
            cout << i+1 << "  ";
            cout << "Y: " << bodyY[i];
            cout << "| X: " << bodyX[i];
            cout << endl;
        }
        cout << "------" << endl;

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
