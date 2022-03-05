#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "../Game.h"
#include "MenuState.cpp"


class GameState : public State
{
private:

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