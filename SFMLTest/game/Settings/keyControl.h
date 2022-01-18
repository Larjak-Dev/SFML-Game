#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class keyControl {
public:
	keyControl(sf::Keyboard::Key key1 = (sf::Keyboard::Key)-2, sf::Keyboard::Key key2 = (sf::Keyboard::Key)-2);
	sf::Keyboard::Key First;
	sf::Keyboard::Key Second;
	bool isPressed();
};