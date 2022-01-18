#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

#include "../TexCordArray.h"

class DynamicAtlas : public sf::Texture {
public:
	//Stores the filepaths for each texture
	std::list<std::string> files;
	std::vector<TexCordArray> texCordArrays;

	//Maximum and minimum sizes for each texture
	int spriteWidth;
	int spriteHeight;


	//Creates an atlas framework that creates an atlas texture using mulitple texture filepaths.
	DynamicAtlas(int SpriteWidth, int SpriteHeight);

	//Adds a path to the one of the textures you want to available using this atlas after initializing.
	void addFile(std::string path);

	//Initializes the atlas texture using all the texture's filepaths
	void init();

	//Returns the cords for a texture in the atlas
	TexCordArray* getCords(std::string textureName);
};