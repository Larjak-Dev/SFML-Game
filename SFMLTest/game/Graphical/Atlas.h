#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Atlas : public sf::Texture {
public:
	Atlas(const char* path);
};