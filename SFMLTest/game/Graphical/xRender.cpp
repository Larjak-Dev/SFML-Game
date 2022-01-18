#include "xRender.h"

void SpriteUpdate()
{
}



void InsertQuadVAO(sf::VertexArray& va, Quad* vertexQuad, Quad* texQuad)
{
	va[0] = sf::Vertex(vertexQuad->first, texQuad->first);
	va[1] = sf::Vertex(vertexQuad->second, texQuad->second);
	va[2] = sf::Vertex(vertexQuad->third, texQuad->third);
	va[3] = sf::Vertex(vertexQuad->fourth, texQuad->fourth);
}

void InsertQuadVAOs(sf::VertexArray& va, Quad* vertexQuad, Quad* texQuad, int amountOfSprites)
{
	for (int i = 0; i < amountOfSprites; i++) {
		va[4 * i + 0] = sf::Vertex(vertexQuad[i].first, texQuad[i].first);
		va[4 * i + 1] = sf::Vertex(vertexQuad[i].second, texQuad[i].second);
		va[4 * i + 2] = sf::Vertex(vertexQuad[i].third, texQuad[i].third);
		va[4 * i + 3] = sf::Vertex(vertexQuad[i].fourth, texQuad[i].fourth);
	}
}

void setCordVAO(sf::VertexArray& va, int x, int y)
{
	
}

void RenderVAO(sf::RenderTarget& window, sf::VertexArray& va, sf::Texture& texture)
{
	window.draw (va, &texture);
}

void RenderDVAO(sf::RenderTarget& window, DynamicVertexArray& dva, sf::Texture& texture)
{
	sf::VertexArray va(sf::PrimitiveType::Quads, dva.getSize() * 4);
	dva.initVA(va);
	RenderVAO(window, va, texture);
}
