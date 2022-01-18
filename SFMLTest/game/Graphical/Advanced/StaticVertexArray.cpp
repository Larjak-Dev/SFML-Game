#include "StaticVertexArray.h"

StaticVertexArray::StaticVertexArray(int SpriteAmountArg) : SpriteAmount(SpriteAmountArg), sf::VertexArray(sf::PrimitiveType::Quads, SpriteAmountArg * 4), index(0)
{
}

void StaticVertexArray::add(Quad& vertexQuad, Quad& textureQuad)
{
	if (index > SpriteAmount) throw std::exception("Reached the limited amount of quads assigned by the Static Vertex Array object");
	(*this)[index * 4 + 0] = { vertexQuad.first, textureQuad.first};
	(*this)[index * 4 + 1] = { vertexQuad.second, textureQuad.second };
	(*this)[index * 4 + 2] = { vertexQuad.third, textureQuad.third };
	(*this)[index * 4 + 3] = { vertexQuad.fourth, textureQuad.fourth };
	index++;
}

void StaticVertexArray::clearVerticies()
{
	memset(&((*this)[0]), 0, SpriteAmount * 4 * sizeof(sf::Vertex));
	index = 0;
}
