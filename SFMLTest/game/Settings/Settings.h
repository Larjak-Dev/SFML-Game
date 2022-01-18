#pragma once
#include "keyControl.h"

class Settings {
public:
	Settings();
	keyControl up;
	keyControl down;
	keyControl left;
	keyControl right;

	keyControl zoomIn;
	keyControl zoomOut;
};

