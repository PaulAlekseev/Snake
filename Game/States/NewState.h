#ifndef NEWSTATE_H
#define NEWSTATE_H


#include "State.cpp"


class NewState : public State
{
private:

public:
    NewState(sf::RenderWindow* window);
    virtual ~NewState();

    //Functions
    void endState();

    void updateKeyBinds();
    void update();
    void render();
};

#endif