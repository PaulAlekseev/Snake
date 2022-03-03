#ifndef STATE_H
#define STATE_H

#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma once

class State
{
private:
    sf::RenderWindow* window;
    bool quit;

public:
    State(sf::RenderWindow* window);
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