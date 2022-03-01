#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "State.cpp"


class GameState : public State
{
private:



public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    //Functions
    void endState();

    void update();
    void render(sf::RenderTarget* target = nullptr);
};

#endif