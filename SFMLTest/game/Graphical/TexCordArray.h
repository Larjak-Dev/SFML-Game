#pragma once
#include "Atlas.h"
#include "Quad.h"
#include "Advanced/SmartPointer.h"

#include <array>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

class TexCordArray {
public:
	SmartPtr<Quad> quadArray;
	TexCordArray();
	TexCordArray(std::vector<Quad>& TexCords);
	~TexCordArray();

	void set(std::vector<Quad>& TexCords);
	Quad* operator[](int index) {
		return &quadArray.getPtr()[index];
	}
};

