#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.cpp"

class MenuState : public State
{
private:
    sf::Text text;
    sf::Font font;
    
    void initText();
public:
    MenuState(sf::RenderWindow* window, std::stack<State*>* states);
    ~MenuState();

    void placeText(std::string Text, float posX, float posY);

    void updateKeyBinds();
    void update();
    void render();

};

#endif