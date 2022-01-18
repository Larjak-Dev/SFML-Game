#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../Quad.h"


class StaticVertexArray : public sf::VertexArray {
	int index;
	int SpriteAmount;
public:
	StaticVertexArray(int SpriteAmountArg);
	void add(Quad& vertexQuad, Quad& textureQuad);
	void clearVerticies();
};
