#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.cpp"

class MenuState : public State
{
private:
    sf::Font font;
    sf::Text text;
    
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