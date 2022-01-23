#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {

	int flags = 0;
	if (fullScreen == true) {

		flags = SDL_WINDOW_FULLSCREEN;

	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "Subsystems initialised..." << endl;
		// Ustveri in preveri ce sta window in renderer ustvarjeni

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window > 0) {
			cout << "Window se je ustvaril" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer > 0) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer se je ustvaril" << endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();
	// ECS implementacija

	player.addComponent<PositionComponent>(100, 500);
	player.addComponent<SpriteComponents>("assets/supremeMan.png");
}

void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

	manager.update();
	manager.refresh();

	if (player.getComponent<PositionComponent>().x() > 100) {

		player.getComponent<SpriteComponents>().setTex("assets/enemy.png");

	}
}

void Game::render() {

	SDL_RenderClear(renderer);
	map->drawMap();
	manager.draw();
	//Tuki damo stvari za render
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}