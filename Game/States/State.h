#ifndef STATE_H
#define STATE_H

#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <map>

#pragma once

class State
{
protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keyBinds;
    std::stack<State*>* states;
    bool quit;

public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
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