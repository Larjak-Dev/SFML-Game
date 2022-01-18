#include "Quad.h"

Quad::Quad(int X, int Y, int Width, int Hight) : first(X, Y + Hight), second(X, Y), third(X + Width, Y), fourth(X + Width, Y + Hight)
{
}

Quad::~Quad()
{
}

void Quad::set(int x, int y, int width, int height)
{
	first.x = x; first.y = y + height;
	second.x = x; second.y = y;
	third.x = x + width; third.y = y;
	fourth.x = x + width; fourth.y = y + height;
}
