#pragma once
#include "TexCordArray.h"
#include "Advanced/DynamicVertexArray.h"

void InsertQuadVAO(sf::VertexArray& va, Quad* vertexQuad, Quad* texQuad);
void InsertQuadVAOs(sf::VertexArray& va, Quad* vertexQuad, Quad* texQuad, int amountOfSprites);

void setCordVAO(sf::VertexArray& va, int x, int y);

void RenderVAO(sf::RenderTarget& window, sf::VertexArray& va, sf::Texture& texture);
void RenderDVAO(sf::RenderTarget& window, DynamicVertexArray& dva, sf::Texture& texture);