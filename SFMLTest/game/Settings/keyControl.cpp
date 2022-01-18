#include "keyControl.h"

keyControl::keyControl(sf::Keyboard::Key key1, sf::Keyboard::Key key2) : First(key1), Second(key2) {
	
}

bool keyControl::isPressed()
{
	return (sf::Keyboard::isKeyPressed(First) || sf::Keyboard::isKeyPressed(Second));
}
