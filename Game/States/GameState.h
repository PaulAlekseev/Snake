#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.cpp"


class GameState : public State
{
private:

public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //Functions
    void endState();

    void updateKeyBinds();
    void update();
    void render();
};

#endif