#include "MenuState.h"


void MenuState::initText()
{
    this->font.loadFromFile("../../Font/Font.ttf");
    this->text.setFont(font);
    this->text.setCharacterSize(50);
    this->text.setStyle(sf::Text::Bold);
    this->text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
}

MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initText();
    std::cout << "MenuState opened" << std::endl;
}

MenuState::~MenuState()
{
    std::cout << "Ending Menustate" << std::endl;
}

void MenuState::placeText(std::string Text, float posX, float posY)
{
    this->text.setPosition(posX, posY);
    this->text.setString(Text);
    this->window->draw(text);
}

void MenuState::updateKeyBinds()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->QUIT();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Hello from MenuState" << std::endl;
    }
}

void MenuState::update()
{
    this->updateKeyBinds();
}

void MenuState::render()
{

}