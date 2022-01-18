#pragma once
#include "Graphical/Quad.h"
#include "Graphical/TexCordArray.h"

#include <list>
#include <vector>

std::list<TexCordArray> texCordArrays;


void init();

Quad getBlockTextureCords(int id);


