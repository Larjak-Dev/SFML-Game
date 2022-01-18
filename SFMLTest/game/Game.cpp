#include <thread>
#include <iostream>
#include <algorithm>
#include <string>

#include "Window.h"
#include "Graphical/xRender.h"
#include "Graphical/Advanced/DynamicAtlas.h"
#include "Graphical/Advanced/DynamicVertexArray.h"
#include "Graphical/Advanced/StaticVertexArray.h"

#include "Menus/MenuState.h"
#include "State.h"

bool running = true;

sf::RenderWindow* window;
State* state = new MenuState();

//Info
float fps = 0;
float timeRunning = 0;

//Thread
std::unique_ptr<std::thread> gameThread(new std::thread);

//Settings
Settings settings;


float zoom = 1;

void gameRender() {
	while (window->isOpen()) {
		auto fpsClockStart = std::chrono::high_resolution_clock::now();

		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();

			}
			if (event.type == sf::Event::KeyPressed) {

			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::F11) {
					if (!fullscreen) {
						window->create(sf::VideoMode::getFullscreenModes()[1], "Game", sf::Style::Fullscreen);
						fullscreen = true;
					} else if(fullscreen) {
						window->create(sf::VideoMode(600,600), "Game", sf::Style::Default);
						fullscreen = false;
					}
				}
			}
			if (event.type == sf::Event::Resized) {
				auto size = window->getSize();
				window->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
			}
		}

		if(window) {
			window->clear(sf::Color(255, 255, 255));

			sf::VertexArray vaStone(sf::PrimitiveType::Quads, 4);
			InsertQuadVAO(vaStone, &playerQuad, (*stoneTextureCords)[0]);
			RenderVAO(*window, vaStone, blockAtlas);

			sf::Sprite sp(blockAtlas);
			sp.setScale(4, 4);
			window->draw(sp);


			//Block drawing
			int size = 16;

			for (int i = 0; i < chunkManager.chunkPtrs.size(); i++) {
				for (int x = 0; x < Chunk::chunkSize; x++) {
					for (int y = 0; y < Chunk::chunkSize; y++) {
						if (chunkManager.chunkPtrs[i]) {
							Quad vertecies(chunkManager.chunkPtrs[i]->chunkX * Chunk::chunkSize * size + x * size, chunkManager.chunkPtrs[i]->chunkY * Chunk::chunkSize * size + y * size, size, size);
							blockva.add(vertecies, *(*stoneTextureCords)[0]);
						}
					}
				}
				RenderVAO(*window, blockva, blockAtlas);
				blockva.clearVerticies();
			}
			/*
			StaticVertexArray blockva(chunkManager.chunks.size() * 8);
			for (int x = 0; x < 10; x++) {
				for (int y = 0; y < 10; y++) {
					auto texture = blockAtlas.getCords("Textures/Blocks/grass.png");

					Quad positionQuad(x * 60, y * 60, 60, 60);
					Quad* textureCord = (*texture)[0];
					blockva.add(positionQuad, *textureCord);
				}
			}
			*/

			//Player drawing
			DynamicVertexArray playerDva;
			playerDva.add(playerQuad, *playerSprite[0]);
			playerDva.add(playerQuad, *playerRingSprite[0]);
			RenderDVAO(*window, playerDva, playerAtlas);

			window->display();
		}

		//Calculate the fps
		auto fpsClockNow = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> ms = fpsClockNow - fpsClockStart;
		fps = 1000.0f/ms.count();
	}
}

void chunkTick() {
	chunkManager.Update(0, 0);
}

void gameTick() {
	 auto start = std::chrono::high_resolution_clock::now();
	 auto lastTick = std::chrono::high_resolution_clock::now();
	while (window->isOpen()) {
		while (running && window->isOpen()) {
			auto now = std::chrono::high_resolution_clock::now();

			//Game running time
			std::chrono::duration<double, std::milli> ms = now - start;
			timeRunning = ms.count() / 1000.0f;
			window->setTitle("FPS: " + std::to_string(fps) + " Time Running: " + std::to_string(timeRunning));

			//Tick (Checks if lastTick was 200 mls ago)
			if (((std::chrono::duration<double, std::milli>)(now - lastTick)).count() >= 200) {
				//Tick

				if (settings.zoomIn.isPressed()) {

				}

				if (settings.zoomOut.isPressed()) {

				}

				//Player Movement
				float XNormalizedMovement = 0.0f;
				float YNormalizedMovement = 0.0f;
				if (settings.left.isPressed()) {
					XNormalizedMovement += -1;
				}
				if (settings.right.isPressed()) {
					XNormalizedMovement += 1;
				}
				if (settings.up.isPressed()) {
					YNormalizedMovement += -1;
				}
				if (settings.down.isPressed()) {
					YNormalizedMovement += 1;
				}
				
				XNormalizedMovement = std::clamp(XNormalizedMovement, -1.0f, 1.0f);
				YNormalizedMovement = std::clamp(YNormalizedMovement, -1.0f, 1.0f);

				
				
				///
				lastTick = std::chrono::high_resolution_clock::now();
			}
		}
	}
}



void menuTick() {


}

void startGame()
{

	//Load Textures and atlases
	blockAtlas.addFile("Textures/Blocks/grass.png");
	blockAtlas.addFile("Textures/Blocks/water.png");
	blockAtlas.addFile("Textures/Blocks/stone.png");
	blockAtlas.addFile("Textures/Blocks/andesite.png");
	blockAtlas.addFile("Textures/Blocks/moon_stone.png");
	blockAtlas.addFile("Textures/Blocks/jungle_plank.png");
	blockAtlas.init();

	window = new sf::RenderWindow(sf::VideoMode(600, 600, 32), "SFML works!");

	//Create seperate Game Thread
	std::thread* ptrGame = gameThread.get();
	*ptrGame = std::thread(gameTick);

	std::thread* ptrChunk = chunkThread.get();
	*ptrChunk = std::thread(chunkTick);

	//Start Rendering Loop
	gameRender();

	//Stop seperate Game Thread
	ptrGame->join();
	ptrChunk->join();

	delete window;
}

