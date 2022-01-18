#include "DynamicAtlas.h"

DynamicAtlas::DynamicAtlas(int SpriteWidth, int SpriteHeight) : spriteWidth(SpriteWidth), spriteHeight(SpriteHeight)
{
	
}

void DynamicAtlas::addFile(std::string path)
{
	files.push_back(path);
}

void DynamicAtlas::init()
{
	int widthCanvas = spriteWidth, heightCanvas = 0;

	std::list<sf::Image> images;
	texCordArrays.resize(files.size());

	//Load Textures and calulates the canvas height.
	auto iterator = files.begin();
	for (int i = 0; i < files.size(); i++) {
		std::cout << "Loading Texture \"" << *iterator << "\": ";
		auto start = std::chrono::high_resolution_clock::now();
		///

		//Loads the texture, If it fails to load it will replace it with a pink texture
		images.push_back(sf::Image());
		if (!images.back().loadFromFile(*iterator)) {
			images.back().create(this->spriteWidth, this->spriteHeight, { 255,20,147 });
		}
		auto size = images.back().getSize();
		heightCanvas += size.y;
		std::advance(iterator, 1);

		///
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << "Took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1000000.0f << "ms." << std::endl;

	}

	//Canvas for drawing the textures on
	sf::RenderTexture canvas; 
	canvas.create(widthCanvas, heightCanvas);

	//Pre variables for less unessessary variable initializion
	sf::Texture texture;
	texture.create(this->spriteWidth, this->spriteHeight);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	auto iterator2 = images.begin();
	int ySprite = 0;
	for (int i = 0; i < images.size(); i++) {
		std::cout << "Drawing texture " << i << " to atlas: ";
		auto start = std::chrono::high_resolution_clock::now();
		

		int imageHeight = (*iterator2).getSize().y;
		int imageAmount = imageHeight / this->spriteHeight;
		std::vector<Quad> textureCords(imageAmount);
		for (int ii = 0; ii < imageAmount; ii++) {
			textureCords[ii] = Quad(0,ySprite,this->spriteWidth, this->spriteHeight);
			if (imageHeight == this->spriteHeight) {
				texture.update(*iterator2, 0, 0);
			}
			else {
				sf::Image image;
				image.create(this->spriteWidth, this->spriteHeight);
				image.copy(*iterator2, 0, 0, sf::IntRect(sf::Vector2i(0, this->spriteHeight * ii), sf::Vector2i(this->spriteWidth, this->spriteHeight)));
				texture.update(image, 0, 0);
			}

			sprite.setPosition(0, ySprite);
			canvas.draw(sprite);

			ySprite += this->spriteHeight;
		}

		texCordArrays[i].set(textureCords);

		std::advance(iterator2, 1);
		auto end = std::chrono::high_resolution_clock::now();
		std::cout << "Took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000000.0f << "ms." << std::endl;
	}
	canvas.display();
	this->create(widthCanvas, heightCanvas);
	this->update(canvas.getTexture());
}

TexCordArray* DynamicAtlas::getCords(std::string texturePath)
{
	auto iterator = files.begin();
	for (int i = 0; i < files.size(); i++) {
		if (*iterator == texturePath) {
			return &texCordArrays[i];
		}
		std::advance(iterator, 1);
	}
}
