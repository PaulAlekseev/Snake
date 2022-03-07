#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "../Game.h"
#include "State.cpp"
#include "../Objects/Fruit.cpp"


class GameState : public State
{
private:
    
    void initSnake();
    void initFruit();

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void endState();

    void updateKeyBinds();
    void update();
    void render();
};

#endif