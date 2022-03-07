#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "../Game.h"
#include "State.cpp"
#include "../Objects/Fruit.cpp"


class GameState : public State
{
private:
    
    Snake* snake;
    Fruit* fruit;
    sf::Clock* clock;


    void initSnake();
    void initFruit();
    void initClock();

    int direction;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void endState();

    const sf::Time& getElapsed();

    void updateKeyBinds();
    void update();
    void render();
};

#endif