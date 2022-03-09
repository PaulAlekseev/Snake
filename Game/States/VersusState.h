#ifndef VERSUSSTATE_H
#define VERSUSSTATE_H

#pragma once

#include "GameState.cpp"

class VersusState : public State
{
private:

    Snake* snake1;
    Snake* snake2;
    Fruit* fruit;
    sf::Clock* clock;

    void initSnake();
    void initFruit();
    void initClock();

    int direction1;
    int direction2;

    void collision();

public:
    VersusState(sf::RenderWindow* window, std::stack<State*>* states);
    ~VersusState();

    void updateKeyBinds();
    void update();
    void render();



};

#endif