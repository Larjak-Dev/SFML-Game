#include "State.h"

State::State()
{
}

State::~State()
{
}

void State::close()
{
	closing = true;
}

bool State::isClosing()
{
	return closing;
}

void State::tickGame()
{
}
