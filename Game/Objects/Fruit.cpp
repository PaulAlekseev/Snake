#include "Fruit.h"
#include <stdlib.h>
#include <time.h>


void Fruit::initScale()
{
    this->scale = new Scaling(this->window);
}

Fruit::Fruit(int posX, int posY, sf::RenderWindow* window)
{
    this -> window = window;

    srand(time(NULL));

    this -> posX = rand() % 60;
    this -> posY = rand() % 34;
    
    this->initScale();
}

Fruit::~Fruit()
{

}

const bool Fruit::gotEaten(int snakePosX, int snakePosY)
    {
        if ((snakePosX == this->posX) && (snakePosY == this->posY))
        {
            return true;
        }
        return false;
    }

void Fruit::changePosition()
{
    this -> posX = rand() % 60;
    this -> posY = rand() % 34;
}

void Fruit::drawFruit(std::string pathToTextures)
{
    fruitTexture.loadFromFile(pathToTextures);
    sf::Sprite fruitSprite(fruitTexture);
    fruitSprite.setScale(this->scale->getScaleVector());
    fruitSprite.setPosition(this->posX * this->scale->getGridSizeX(), this->posY * this->scale->getGridSizeY());
    this->window->draw(fruitSprite);
}

