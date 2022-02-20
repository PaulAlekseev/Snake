#include <iostream>
#include <SFML/Graphics.hpp>


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
        this->length = length;
        this->direction = direction;
        this->posX = posX;
        this->posY = posY;
    }
};
