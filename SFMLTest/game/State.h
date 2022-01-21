#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class State {
	bool closing = false;
public:
	State();
	virtual ~State();

	void close();
	bool isClosing();
	virtual void init() = 0;
	virtual void tick() = 0;
	virtual void tickGame();
	virtual void render(sf::RenderTarget& render) = 0;
};