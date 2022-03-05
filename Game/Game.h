#ifndef GAME_H
#define GAME_H

#pragma once

#include "States/GameState.cpp"

class Game
{

private:

    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    
    std::stack<State*> states;

    //Private functions
    void initVariables();
    void initWindow();
    void initStates();    

public:
    //Constuctos / Destructors
    Game();
    virtual ~Game();

    const bool isRunning();

    void poolEvent();
    void update();
    void render();

};

#endif