#include "MenuState.h"

MenuState::MenuState()
{
}

void MenuState::init() 
{

}

void MenuState::tick()
{
}

void MenuState::render(sf::RenderTarget& render)
{
	sf::RectangleShape rect(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Black);
	rect.setPosition(sf::Vector2f(0, 0));
	render.draw(rect);
}
