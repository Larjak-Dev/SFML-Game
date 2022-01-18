#pragma once
#include "Tile.h"

class Chunk {
public:
	static const int chunkSize = 8; 
	static const int chunkAmount = chunkSize*chunkSize;

	//Chunk Cordinates
	int chunkX, chunkY;

	//Block Array
	Tile* tilesPtr;

	Chunk(int x, int y);
	~Chunk();

	//Used after the chunk has been copied to prevent a double deallocation heap error.
	void Disable();

	//Gets a tile from the chunk using chunk-cordinates.
	Tile* getTile(int x, int y);
};