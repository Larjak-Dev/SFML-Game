#include "StateManager.h"

void StateManager::setState(State* state)
{
	states.push_back(state);
	states.back()->init();
}

void StateManager::updateStates()
{
	if (states.size() < 1) return;
	if (states.back()->isClosing()) {
		delete states.back();
		states.remove(states.back());
	}
}

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
	for (auto iterator = states.begin(); iterator != states.end(); ++iterator) {
		delete *iterator;
		states.remove(*iterator);
	}
}

void StateManager::tick()
{
	if (states.size() < 1) return;
	states.back()->tick();
}

void StateManager::render(sf::RenderTarget& render)
{
	if (states.size() < 1) return;
	states.back()->render(render);
}
