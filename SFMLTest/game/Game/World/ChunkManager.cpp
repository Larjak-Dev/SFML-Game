#include "ChunkManager.h"
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>



ChunkManager::ChunkManager(int renderDistanceArg, bool multiplayerArg) : renderDistance(renderDistanceArg), renderDistanceWidth(renderDistanceArg * 2 + 1), multiplayer(multiplayerArg), chunkPtrs(renderDistanceWidth*renderDistanceWidth), chunks(renderDistanceWidth* renderDistanceWidth), spirilizedIndexes(getSpirializedIndexes(renderDistanceWidth* renderDistanceWidth))
{
	std::reverse(spirilizedIndexes.begin(), spirilizedIndexes.end());
}

void ChunkManager::Update(int chunkX, int chunkY)
{

	for (auto it = chunkObjects.begin(); it != chunkObjects.end(); ++it) {
		if ( std::abs((*it).chunkX - chunkX) > renderDistance) {
			chunkObjects.erase(it);
			--it;
		}
	}
	for (auto it = chunkObjects.begin(); it != chunkObjects.end(); ++it) {
		chunkPtrs[(*it).chunkX + (*it).chunkY * renderDistanceWidth] = &*it;
	}

	for (int i = 0; i < chunkPtrs.size(); i++) {
		if (chunkPtrs[spirilizedIndexes[i]] == nullptr) {
			int y = std::floor(spirilizedIndexes[i] / renderDistanceWidth);
			int x = spirilizedIndexes[i] - (renderDistanceWidth * y);
			Chunk chunk(x, y);
			chunkObjects.push_back(chunk);
			chunk.Disable();

			chunkPtrs[spirilizedIndexes[i]] = &chunkObjects.back();
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}

	chunks = chunkPtrs;
}

std::vector<int> getSpirializedIndexes(int ArraySize)
{
	float MatrixWidthF = std::sqrt(ArraySize);
	int MatrixWidth = MatrixWidthF;
	if (MatrixWidthF - MatrixWidth > 0) throw "Incorrect Array size. Must be a valid square of a number";

	int index = 0;

	int top = 0;
	int bottom = 0;
	int left = 0;
	int right = 0;



	std::vector<int> Array(ArraySize);
	while (index < ArraySize) {
		for (int i = 0; i < MatrixWidth - left - right; i++) {
			Array[index] = left + i + (MatrixWidth * (top));
			index++;
		}
		top++;
		for (int i = 0; i < MatrixWidth - top - bottom; i++) {
			Array[index] = MatrixWidth - 1 - right + (MatrixWidth * (i + top));
			index++;
		}
		right++;
		for (int i = 0; i < MatrixWidth - right - left; i++) {
			Array[index] = MatrixWidth - 1 - i - right + (MatrixWidth * (MatrixWidth - 1 - bottom));
			index++;
		}
		bottom++;
		for (int i = 0; i < MatrixWidth - bottom - top; i++) {
			Array[index] = left + (MatrixWidth * (MatrixWidth - 1 - i - bottom));
			index++;
		}
		left++;
	}
	return Array;
}
