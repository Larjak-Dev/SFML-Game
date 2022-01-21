#include "Settings.h"


namespace Settings {
	keyControl up = keyControl(sf::Keyboard::Key::W, sf::Keyboard::Key::Up);
	keyControl down = keyControl(sf::Keyboard::Key::S, sf::Keyboard::Key::Down);
	keyControl left = keyControl(sf::Keyboard::Key::A, sf::Keyboard::Key::Left);
	keyControl right = keyControl(sf::Keyboard::Key::D, sf::Keyboard::Key::Right);

	keyControl zoomIn = keyControl(sf::Keyboard::Key::Add);
	keyControl zoomOut = keyControl(sf::Keyboard::Key::Subtract);

	bool fullscreen = false;
}
