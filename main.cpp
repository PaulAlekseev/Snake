#include "Game/Game.cpp"
#include <iostream>


int main()
{
    Game game;
    while (game.isRunning())
    {
        game.update();

        game.render();
    };
}
