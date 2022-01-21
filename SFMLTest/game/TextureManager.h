#pragma once
#include "Graphical/Quad.h"
#include "Graphical/TexCordArray.h"

#include <list>
#include <vector>

namespace TextureManager {

	extern std::list<TexCordArray> texCordArrays;

	extern


	void init();

	Quad getBlockTextureCords(int id);
}

