#include "settings.h"

Settings::Settings() : up(sf::Keyboard::Key::W, sf::Keyboard::Key::Up), down(sf::Keyboard::Key::S, sf::Keyboard::Key::Down), 
left(sf::Keyboard::Key::A, sf::Keyboard::Key::Left) , right(sf::Keyboard::Key::D, sf::Keyboard::Key::Right), 
zoomIn(sf::Keyboard::Key::Add), zoomOut(sf::Keyboard::Key::Subtract)
{

}
