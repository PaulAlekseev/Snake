#ifndef STATE_H
#define STATE_H

#include <stack>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma once

class State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    bool quit;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit();

    //Functions
    virtual void QUIT();
    virtual void endState();
    virtual void updateKeyBinds() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif