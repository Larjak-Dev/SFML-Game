#include "Chunk.h"

Chunk::Chunk(int x, int y) : chunkX(x), chunkY(y)
{
	tilesPtr = (Tile*)operator new[](chunkAmount * sizeof(Tile));

	for (int i = 0; i < chunkAmount; i++) {
		tilesPtr[i] = Tile(0);
	}
}

Chunk::~Chunk()
{
	if(tilesPtr) operator delete[]((void*)tilesPtr);
}

void Chunk::Disable()
{
	tilesPtr = nullptr;
}

Tile* Chunk::getTile(int x, int y)
{
	return &tilesPtr[x + y * chunkSize];
}
