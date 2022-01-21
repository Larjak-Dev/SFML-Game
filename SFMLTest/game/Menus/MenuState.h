#pragma once
#include "../State.h"
#include "../TextureManager.h"

class MenuState : public State {
public:
	MenuState();
	void init();
	void tick();
	void render(sf::RenderTarget& render);
};