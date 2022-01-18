#include "DynamicVertexArray.h"

DynamicVertexArray::DynamicVertexArray()
{
}

void DynamicVertexArray::add(Quad& vertexQuad, Quad& TextureQuad)
{
	vertexQuads.push_back(vertexQuad);
	textureQuads.push_back(TextureQuad);
}

int DynamicVertexArray::getSize()
{
	return vertexQuads.size();
}

void DynamicVertexArray::initVA(sf::VertexArray& va)
{
	int size = vertexQuads.size();
	std::vector<Quad> vQ(size);
	std::vector<Quad> tQ(size);

	auto vQit = vertexQuads.begin();
	auto tQit = textureQuads.begin();

	for (int i = 0; i < size; i++) {
		vQ[i] = *vQit;
		tQ[i] = *tQit;

		std::advance(vQit, 1);
		std::advance(tQit, 1);
	}
	
	for (int i = 0; i < size; i++) {
		va[4 * i + 0] = sf::Vertex(vQ[i].first, tQ[i].first);
		va[4 * i + 1] = sf::Vertex(vQ[i].second, tQ[i].second);
		va[4 * i + 2] = sf::Vertex(vQ[i].third, tQ[i].third);
		va[4 * i + 3] = sf::Vertex(vQ[i].fourth, tQ[i].fourth);
	}
}
