#ifndef STATE_H
#define STATE_H

#include <stack>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#pragma once

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void endState() = 0;

    //Functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif