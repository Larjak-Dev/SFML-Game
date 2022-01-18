#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Quad {
public:
	sf::Vector2f first;
	sf::Vector2f second;
	sf::Vector2f third;
	sf::Vector2f fourth;


	Quad(int X = 0, int Y = 0, int Width = 0, int Height = 0);
	~Quad();
	void set(int x, int y, int width, int height);
};