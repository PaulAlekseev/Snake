#include "MenuState.h"


void MenuState::initText()
{
    this->font.loadFromFile("Font/Font.ttf");
    this->text.setCharacterSize(50);
    this->text.setFont(font);
    this->text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
}


MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    this->initText();

}

MenuState::~MenuState()
{
    std::cout << "Ending Menustate" << std::endl;
}

void MenuState::placeText(std::string Text, float posX, float posY)
{
    this->text.setString(Text);
    this->text.setPosition(posX, posY);
    this->window->draw(this->text);
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->states->push(new GameState(this->window, this->states));
    }
}

void MenuState::update()
{
    this->updateKeyBinds();
}

void MenuState::render()
{
    this->placeText("hello guys", 100, 100);
    this->placeText("hello noguys", 500, 500);
}