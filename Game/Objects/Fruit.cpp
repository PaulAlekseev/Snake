#include "Fruit.h"
#include <stdlib.h>
#include <time.h>

Fruit::Fruit(int posX, int posY)
{
    this -> posX = posY;
    this -> posY = posY;
    srand(time(NULL));
}

Fruit::~Fruit()
{

}

const bool Fruit::gotEatenBy(Snake snake)
    {
        if ((snake.getHeadX() == this->posX) && (snake.getHeadY() == this->posY))
        {
            return true;
        }
        return false;
    }

const int Fruit::gotEatenBy(Snake snake, Snake snake2)
{
        if ((snake.getHeadX() == this -> posX) && (snake.getHeadY() == this -> posY))
        {
            return 1;
        }
        if ((snake2.getHeadX() == this -> posX) && (snake2.getHeadY() == this -> posY))
        {
            return 2;
        }
        return 0;

}

void Fruit::changePosition()
{
    // srand(randomnumber % windowArea.amountY);
    // this -> posX = randomnumber % windowArea.amountX;
    // this -> posY = rand() % windowArea.amountY;
}

