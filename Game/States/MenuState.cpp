#include "MenuState.h"
#include <math.h>


void MenuState::initVariables()
{
    this->up = false;
    this->down = false;
    this->choice = 0;
}

void MenuState::initText()
{
    this->font.loadFromFile("Font/Font.ttf");
    this->text.setCharacterSize(50);
    this->text.setFont(font);

}

void MenuState::initClock()
{
    this->clock = new sf::Clock();
}

void MenuState::initScale()
{
    this->scale = new Scaling(this->window);
}

MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initText();
    this->initClock();
    this->initVariables();
    this->initScale();
}

int MenuState::getChoice()
{
    if (this->choice > 2)
    {
        this->choice = 0;
    }
    if (this->choice < 0)
    {
        this->choice = 2;
    }
    return this->choice;
}

MenuState::~MenuState()
{
    std::cout << "Ending Menustate" << std::endl;
}

void MenuState::placeText(std::string Text, sf::Color color, float posX, float posY)
{
    this->text.setString(Text);
    this->text.setFillColor(color);
    this->text.setPosition(posX - (this->text.getLocalBounds().width / 2), posY - (this->text.getLocalBounds().height / 2));
    this->window->draw(this->text);
}

void MenuState::drawText()
{
    if (this->getChoice() == 0) 
    {
        this->placeText("SinglePlayer", sf::Color::Red, this->scale->getCenterX(), this->window->getSize().y / 4);
    }
    else
    {
        this->placeText("SinglePlayer", sf::Color::White, this->scale->getCenterX(), this->window->getSize().y / 4);
    }
    if (this->getChoice() == 1) 
    {
        this->placeText("Hello1", sf::Color::Red, this->scale->getCenterX(), this->window->getSize().y / 4 * 2);
    }
    else
    {
        this->placeText("Hello1", sf::Color::White, this->scale->getCenterX(), this->window->getSize().y / 4 * 2);
    }
    if (this->getChoice() == 2) 
    {
        this->placeText("Quit", sf::Color::Red, this->scale->getCenterX(), this->window->getSize().y / 4 * 3);
    }
    else
    {
        this->placeText("Quit", sf::Color::White, this->scale->getCenterX(), this->window->getSize().y / 4 * 3);
    }
}

void MenuState::goUp()
{
    this->up = true;
}

void MenuState::goDown()
{
    this->down = true;
}

void MenuState::movingChoice()
{
    if (this->up)
    {
        choice--;
        this->up = false;
        this->down = false;
    }
    if (this->down)
    {
        choice++;
        this->down = false;
        this->up = false;
    }
}

void MenuState::checkChoice()
{
    switch (this->getChoice())
    {
        case 0:
            this->states->push(new GameState(this->window, this->states));
            break;
        case 1:
            //Settings
        case 2:
            this->QUIT();
    }
}

void MenuState::updateKeyBinds()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        this->goUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->goDown();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->checkChoice();
    }
}

void MenuState::update()
{
    sf::Time elapsed = this->clock->getElapsedTime();

    this->updateKeyBinds();
    if(elapsed.asSeconds() > 0.4)
    {
        this->movingChoice();
        this->clock->restart();
    }
}

void MenuState::render()
{
    this->drawText();
}