#pragma once
#include "State.h"
#include <list>

class StateManager {
public:
	std::list<State*> states;
	void setState(State* state);
	void updateStates();

	StateManager();
	~StateManager();

	void tick();
	void render(sf::RenderTarget& render);
};