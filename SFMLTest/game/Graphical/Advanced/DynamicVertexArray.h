#pragma once
#include <list>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../Quad.h"
#include "../TexCordArray.h"

class DynamicVertexArray {
	std::list<Quad> vertexQuads;
	std::list<Quad> textureQuads;
public:
	DynamicVertexArray();
	void add(Quad& vertexQuad, Quad& TextureQuad);

	int getSize();
	void initVA(sf::VertexArray& va);
};