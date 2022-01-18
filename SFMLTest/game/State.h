#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class State {
public:
	virtual void init() = 0;
	virtual void tick() = 0;
	virtual void render(sf::RenderTarget& render) = 0;

	static void setState(State& state);
};