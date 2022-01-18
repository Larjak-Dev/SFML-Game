#pragma once
#include "Chunk.h"

#include <list>
#include <vector>
#include <array>


class ChunkManager {

	int renderDistance;
	bool multiplayer;

	int renderDistanceWidth;

	std::vector<int> spirilizedIndexes;

public:
	std::list<Chunk> chunkObjects;
	std::vector<Chunk*> chunkPtrs;
	std::vector<Chunk*> chunks;

	

	ChunkManager(int renderDistance, bool multiplayer = false);
	void Update(int x,int y);
};



template<class Class>
inline std::vector<Class> getSpirialized(Class* ArraySquareMatrix, int ArraySize) {
	float MatrixWidthF = std::sqrt(ArraySize);
	int MatrixWidth = MatrixWidthF;
	if (MatrixWidthF - MatrixWidth > 0) throw "Incorrect Array size. Must be a valid square of a number";

	int index = 0;

	int top = 0;
	int bottom = 0;
	int left = 0;
	int right = 0;



	std::vector<Class> Array(ArraySize);
	while (index < ArraySize) {
		for (int i = 0; i < MatrixWidth - left - right; i++) {
			Array[left + i + (MatrixWidth * (top))] = ArraySquareMatrix[index];
			index++;
		}
		top++;
		for (int i = 0; i < MatrixWidth - top - bottom; i++) {
			Array[MatrixWidth - 1 - right + (MatrixWidth * (i + top))] = ArraySquareMatrix[index];
			index++;
		}
		right++;
		for (int i = 0; i < MatrixWidth - right - left; i++) {
			Array[MatrixWidth - 1 - i - right + (MatrixWidth * (MatrixWidth - 1 - bottom))] = ArraySquareMatrix[index];
			index++;
		}
		bottom++;
		for (int i = 0; i < MatrixWidth - bottom - top; i++) {
			Array[left + (MatrixWidth * (MatrixWidth - 1 - i - bottom))] = ArraySquareMatrix[index];
			index++;
		}
		left++;
	}
	return Array;
}


std::vector<int> getSpirializedIndexes(int ArraySize);