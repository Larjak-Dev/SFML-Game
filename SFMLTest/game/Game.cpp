#include <thread>
#include <iostream>
#include <algorithm>
#include <string>

#include "Graphical/xRender.h"
#include "Graphical/Advanced/DynamicAtlas.h"
#include "Graphical/Advanced/DynamicVertexArray.h"
#include "Graphical/Advanced/StaticVertexArray.h"

#include "Settings/Settings.h"

#include "StateManager.h"
#include "State.h"
#include "Menus/MenuState.h"

bool running = true;

sf::RenderWindow* window;
StateManager stateManager;

//Info
float fps = 0;
float timeRunning = 0;

//Thread
std::unique_ptr<std::thread> gameThread(new std::thread);


float zoom = 1;

void gameRender() {
	while (window->isOpen()) {
		auto fpsClockStart = std::chrono::high_resolution_clock::now();

		if (window) {
			//Event Polling
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();

				}
				if (event.type == sf::Event::KeyPressed) {

				}
				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::F11) {
						if (!Settings::fullscreen) {
							window->create(sf::VideoMode::getFullscreenModes()[1], "Game", sf::Style::Fullscreen);
							Settings::fullscreen = true;
						} else if(Settings::fullscreen) {
							window->create(sf::VideoMode(600,600), "Game", sf::Style::Default);
							Settings::fullscreen = false;
						}
					}
				}
				if (event.type == sf::Event::Resized) {
					auto size = window->getSize();
					window->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
				}
			}

			//Render
			window->clear(sf::Color(255, 255, 255));
			stateManager.render(*window);
			window->display();
		}

		//Calculate the fps
		auto fpsClockNow = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> ms = fpsClockNow - fpsClockStart;
		fps = 1000.0f/ms.count();
	}
}

void tick() {
	stateManager.tick();
}

void tickGame() {
	
}

void startGame()
{
	window = new sf::RenderWindow(sf::VideoMode(600, 600, 32), "SFML works!");
	stateManager.setState(new MenuState());

	//Create seperate Game Thread
	std::thread* ptrTick = gameThread.get();
	*ptrTick = std::thread(tick);

	//Start Rendering Loop
	gameRender();

	//Stop seperate Game Thread
	ptrTick->join();

	delete window;
}

