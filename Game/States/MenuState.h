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
    sf::Clock* clock;
    Scaling* scale;

    bool up;
    bool down;
    
    void initVariables();
    void initText();
    void initClock();
    void initScale();

    int choice;
    
public:
    MenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    ~MenuState();

    int getChoice();

    void placeText(std::string Text, sf::Color color, float posX, float posY);
    void drawText();

    void goUp();
    void goDown();
    void movingChoice();
    void checkChoice();

    void updateKeyBinds();
    void update();
    void render();

};

#endif